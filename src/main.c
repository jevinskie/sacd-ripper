/**
 * SACD Ripper - https://github.com/sacd-ripper/
 *
 * Copyright (c) 2010-2015 by respective authors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <io/pad.h>

#include <sysutil/msg.h>
#include <sysutil/sysutil.h>
#include <sysutil/disc.h>

#include <sysmodule/sysmodule.h>

#include <sys/file.h>
#include <sys/stat.h>
#include <sys/thread.h>
#include <sys/spu.h>

#include <net/net.h>
#include <net/netctl.h>

#include <sys/storage.h>
#include <ioctl.h>
#include <patch-utils.h>
#include <utils.h>

#include <scarletbook_read.h>
#include <scarletbook_helpers.h>
#include <sacd_reader.h>
#include <version.h>

#include "rsxutil.h"
#include "exit_handler.h"
#include "install.h"
#include "output_device.h"
#include "server.h"
#include "ripping.h"

#include <logging.h>
#include <version.h>

#define MAX_PHYSICAL_SPU               6
#define MAX_RAW_SPU                    1

static int dialog_action = 0;
static int bd_contains_sacd_disc = -1;      // information about the current disc
static int bd_disc_changed = -1;            // when a disc has changed this is set to zero
static int loaded_modules = 0;
static int output_format = 6;               // default to ISO
static int output_format_changed = 0;
static int current_ripping_flags = 0;
static char message_output[150];
static char message_info[450];
float c_firmware=0.00f;
uint8_t dex_mode=0;
uint64_t SYSCALL_TABLE = 0;

static const int output_format_options[7] =
{
    RIP_2CH | RIP_DSDIFF,                   // 2ch DSD/DSDIFF
    RIP_2CH | RIP_DSDIFF | RIP_2CH_DST ,    // 2ch DST/DSDIFF
    RIP_2CH | RIP_DSF,                      // 2ch DSD/DSF

    RIP_MCH | RIP_DSDIFF,                   // mch DSD/DSDIFF
    RIP_MCH | RIP_DSDIFF | RIP_MCH_DST,     // mch DST/DSDIFF
    RIP_MCH | RIP_DSF,                      // mch DSD/DSF

    RIP_ISO                                 // ISO
};

static void validate_output_format(void)
{
    // skip over to MCH format?
    if (output_format == 0 && !(current_ripping_flags & RIP_2CH))
        output_format += 3;

    // skip over DST/DSDIFF format?
    if (output_format == 1 && !(current_ripping_flags & RIP_2CH_DST))
        output_format++;

    // skip over to ISO format?
    if (output_format == 3 && !(current_ripping_flags & RIP_MCH))
        output_format += 3;
}

static int load_modules(void)
{
    int ret;

    ret = sysModuleLoad(SYSMODULE_FS);
    if (ret != 0)
        return ret;
    else
        loaded_modules |= 1;

    ret = sysModuleLoad(SYSMODULE_IO);
    if (ret != 0)
        return ret;
    else
        loaded_modules |= 2;

    ret = sysModuleLoad(SYSMODULE_GCM_SYS);
    if (ret != 0)
        return ret;
    else
        loaded_modules |= 4;

    return ret;
}

static int unload_modules(void)
{
    if (loaded_modules & 4)
        sysModuleUnload(SYSMODULE_GCM_SYS);

    if (loaded_modules & 2)
        sysModuleUnload(SYSMODULE_IO);

    if (loaded_modules & 1)
        sysModuleUnload(SYSMODULE_FS);

    return 0;
}

int file_simple_save(const char *filePath, void *buf, unsigned int fileSize)
{
    int      ret;
    int      fd;
    uint64_t writelen;

    if (buf == NULL)
    {
        LOG(lm_main, LOG_ERROR, ("buffer is null\n"));
    }

    ret = sysFsOpen(filePath, SYS_O_WRONLY | SYS_O_CREAT | SYS_O_TRUNC, &fd, NULL, 0);
    if ((ret != 0))        // && (ret != EPERM) ){
    {
        LOG(lm_main, LOG_ERROR, ("file %s open error : 0x%x\n", filePath, ret));
        return -1;
    }

    ret = sysFsWrite(fd, buf, fileSize, &writelen);
    if (ret != 0 || fileSize != writelen)
    {
        LOG(lm_main, LOG_ERROR, ("file %s read error : 0x%x\n", filePath, ret));
        sysFsClose(fd);
        return -1;
    }

    ret = sysFsClose(fd);
    if (ret != 0)
    {
        LOG(lm_main, LOG_ERROR, ("file %s close error : 0x%x\n", filePath, ret));
        return -1;
    }

    return 0;
}

static void dialog_handler(msgButton button, void *usrData)
{
    switch (button)
    {
    case MSG_DIALOG_BTN_OK:
        dialog_action = 1;
        break;
    case MSG_DIALOG_BTN_NO:
    case MSG_DIALOG_BTN_ESCAPE:
        dialog_action = 2;
        break;
    case MSG_DIALOG_BTN_NONE:
        dialog_action = -1;
        break;
    default:
        break;
    }
}

int patch_lv1_ss_services(void)
{
	if(c_firmware==3.55f)
	{
		install_new_poke();

		// Try to map lv1
		if (!map_lv1())
		{
			remove_new_poke();
			return -1;
		}

		lv1poke(0x0016f3b8, 0x7f83e37860000000ULL); // 0x7f83e378f8010098ULL
		lv1poke(0x0016f3dc, 0x7f85e37838600001ULL); // 0x7f85e3784bfff0e5ULL
		lv1poke(0x0016f454, 0x7f84e3783be00001ULL); // 0x7f84e37838a10070ULL
		lv1poke(0x0016f45c, 0x9be1007038600000ULL); // 0x9be1007048005fa5ULL

		remove_new_poke();

		// unmap lv1
		unmap_lv1();

		return 0;
	}
	else
	if(c_firmware==4.21f)
	{
		if(lv1peek2( 0x16f758) == 0x7f83e378f8010098ULL)
		{
			lv1poke2( 0x16f758, 0x7f83e37860000000ULL);
			lv1poke2( 0x16F77C, 0x7f85e37838600001ULL);
			lv1poke2( 0x16F7F4, 0x7f84e3783be00001ULL);
			lv1poke2( 0x16F7FC, 0x9be1007038600000ULL);
		}
		if(lv1peek2( 0x16F7FC) == 0x9be1007038600000ULL) return 0;
	}
	else
	if(c_firmware>=4.30f)
	{
		if(lv1peek2( 0x16fA60) == 0x7f83e378f8010098ULL)
		{
			lv1poke2( 0x16fA60, 0x7f83e37860000000ULL);
			lv1poke2( 0x16FA84, 0x7f85e37838600001ULL);
			lv1poke2( 0x16FAFC, 0x7f84e3783be00001ULL);
			lv1poke2( 0x16FB04, 0x9be1007038600000ULL);
		}
		if(lv1peek2( 0x16FB04) == 0x9be1007038600000ULL) return 0;
	}
	return -1;
}

int unpatch_lv1_ss_services(void)
{
	if(c_firmware==3.55f)
	{
		install_new_poke();

		// Try to map lv1
		if (!map_lv1())
		{
			remove_new_poke();
			return -1;
		}

		lv1poke(0x0016f3b8, 0x7f83e378f8010098ULL);
		lv1poke(0x0016f3dc, 0x7f85e3784bfff0e5ULL);
		lv1poke(0x0016f454, 0x7f84e37838a10070ULL);
		lv1poke(0x0016f45c, 0x9be1007048005fa5ULL);

		remove_new_poke();

		// unmap lv1
		unmap_lv1();
	}
	else
	if(c_firmware==4.21f)
	{
		if(lv1peek2( 0x16f758) == 0x7f83e37860000000ULL)
		{
			lv1poke2( 0x16f758, 0x7f83e378f8010098ULL);
			lv1poke2( 0x16F77C, 0x7f85e3784bfff0e5ULL);
			lv1poke2( 0x16F7F4, 0x7f84e37838a10070ULL);
			lv1poke2( 0x16F7FC, 0x9be1007048006065ULL);
		}
	}
	else
	if(c_firmware>=4.30f)
	{
		if(lv1peek2( 0x16FA60) == 0x7f83e37860000000ULL)
		{
			lv1poke2( 0x16FA60, 0x7f83e378f8010098ULL);
			lv1poke2( 0x16FA84, 0x7f85e3784bfff0e5ULL);
			lv1poke2( 0x16FAFC, 0x7f84e37838a10070ULL);
			lv1poke2( 0x16FB04, 0x9be1007048006065ULL);
		}
	}
	return 0;
}

int patch_syscall_864(void)
{
	if(c_firmware>4.81f) return -1;

	uint64_t addr;
	if(dex_mode)
	{
		if(c_firmware==3.55f)
			addr = 0x80000000002EF270ULL; // fw 3.55D
		else if(c_firmware==4.21f)
			addr = 0x8000000000302098ULL; // fw 4.21D
		else if(c_firmware==4.30f)
			addr = 0x8000000000303940ULL; // fw 4.30D
		else if(c_firmware==4.41f)
			addr = 0x8000000000304220ULL; // fw 4.41D
		else if(c_firmware==4.46f)
			addr = 0x8000000000304720ULL; // fw 4.46D
		else if(c_firmware==4.50f)
			addr = 0x80000000003089C8ULL; // fw 4.50D
		else if(c_firmware==4.65f)
			addr = 0x800000000030E480ULL; // fw 4.65D
		else if(c_firmware==4.80f)
			addr = 0x800000000030E658ULL; // fw 4.80D
		else if(c_firmware==4.81f)
			addr = 0x800000000030E668ULL; // fw 4.81D
		else return -1;
	}
	else
	{
		if(c_firmware==3.55f)
			addr = 0x80000000002D7820ULL; // fw 3.55
		else if(c_firmware==4.21f)
			addr = 0x80000000002E7920ULL;
		else if(c_firmware==4.30f)
			addr = 0x80000000002E9218ULL;
		else if(c_firmware==4.31f)
			addr = 0x80000000002E9228ULL;
		else if(c_firmware==4.40f)
			addr = 0x80000000002E9798ULL;
		else if(c_firmware==4.41f)
			addr = 0x80000000002E97A8ULL;
		else if(c_firmware==4.46f)
			addr = 0x80000000002E9CE8ULL;
		else if(c_firmware==4.50f)
			addr = 0x80000000002E8F10ULL;
		else if(c_firmware==4.53f)
			addr = 0x80000000002E90A0ULL;
		else if(c_firmware==4.55f)
			addr = 0x80000000002EB8B8ULL;
		else if(c_firmware==4.60f)
			addr = 0x80000000002ECB28ULL;
		else if(c_firmware==4.65f)
			addr = 0x80000000002ECB38ULL;
		else if(c_firmware==4.70f)
			addr = 0x80000000002ECA50ULL;
		else if(c_firmware==4.75f)
			addr = 0x80000000002ECAD0ULL;
		else if(c_firmware==4.80f)
			addr = 0x80000000002ECAC0ULL;
		else if(c_firmware==3.41f)
			addr = 0x80000000002CF880ULL; // fw 3.41
		else return -1;
	}
    uint64_t access_rights = lv2peek( addr);
    if (access_rights == 0x2000000000000000ULL)
	{
        lv2poke( addr, 0x4000000000000000ULL);
    }
    else if (access_rights != 0x4000000000000000ULL)
    {
        return -1;
    }
	return 0;
}

static void bd_eject_disc_callback(void)
{
    LOG(lm_main, LOG_NOTICE, ("disc ejected.."));
    bd_contains_sacd_disc = -1;
    bd_disc_changed       = -1;
}

static void bd_insert_disc_callback(uint32_t disc_type, char *title_id)
{
    LOG(lm_main, LOG_NOTICE, ("disc inserted.."));
    bd_disc_changed = 1;

    if (disc_type == SYS_DISCTYPE_PS3)
    {
        // cannot do anything with a PS3 disc..
        bd_contains_sacd_disc = 0;
    }
    else
    {
        // unknown disc
        bd_contains_sacd_disc = 1;
    }
}

void server_loop(void)
{
    int client_connected;
    msgType              dialog_type;
    char                 *message = (char *) malloc(512);

    // did the disc change?
    if (bd_contains_sacd_disc && bd_disc_changed)
    {
        bd_contains_sacd_disc = 0;
    }

    // by default we have no user controls
    dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_DISABLE_CANCEL_ON);

    if (!bd_contains_sacd_disc)
    {
    	union net_ctl_info info;

    	if(netCtlGetInfo(NET_CTL_INFO_IP_ADDRESS, &info) == 0)
    	{
       		sprintf(message, "              SACD Daemon %s\n\n"
       		                 "Status: Active\n"
       		                 "IP Address: %s (port 2002)\n"
       		                 "Client: %s\n"
       		                 "Disc: %s",
    			SACD_RIPPER_VERSION_STRING, info.ip_address,
    			(is_client_connected() ? "connected" : "none"),
    			(bd_disc_changed == -1 ? "empty" : "inserted"));
    	}
    	else
    	{
    		sprintf(message, "No active network connection was detected.\n\nPress OK to refresh.");
            dialog_type |= MSG_DIALOG_BTN_TYPE_OK;
    	}
    }

    msgDialogOpen2(dialog_type, message, dialog_handler, NULL, NULL);

    dialog_action         = 0;
    bd_disc_changed       = 0;
    client_connected      = is_client_connected();
    while (!dialog_action && !user_requested_exit() && bd_disc_changed == 0 && client_connected == is_client_connected())
    {
        sysUtilCheckCallback();
        flip();
    }
    msgDialogAbort();

    free(message);
}

void main_loop(void)
{
    msgType              dialog_type;
    char                 *message = (char *) malloc(512);
    sacd_reader_t        *sacd_reader;
    scarletbook_handle_t *sb_handle = 0;
    int idx = 0;

    if (output_device_changed && output_device)
    {
        char file_path[100];
        sprintf(file_path, "%s/sacd_log.txt", output_device);
        set_log_file(file_path);
        LOG(lm_main, LOG_NOTICE, ("SACD-Ripper Version " SACD_RIPPER_VERSION_STRING));
    }

    // did the disc change?
    if (bd_contains_sacd_disc && bd_disc_changed)
    {
        // open the BD device
        sacd_reader = sacd_open("/dev_bdvd");
        if (sacd_reader)
        {
            // read the scarletbook information
            sb_handle = scarletbook_open(sacd_reader, 0);
            if (sb_handle)
            {
                master_text_t *master_text = &sb_handle->master_text;
                master_toc_t *mtoc = sb_handle->master_toc;

                if (master_text->disc_title || master_text->disc_title_phonetic)
                {
                    idx += snprintf(message_info + idx, 60, "Title: %s\n", substr((master_text->disc_title ? master_text->disc_title : master_text->disc_title_phonetic), 0, 50));
                    LOG(lm_main, LOG_NOTICE, ("Album Title: %s", substr((master_text->disc_title ? master_text->disc_title : master_text->disc_title_phonetic), 0, 50)));
                }

                if (message_info[idx - 1] != '\n') { message_info[idx++] = '\n'; message_info[idx] = '\0'; }

                if (master_text->disc_artist || master_text->disc_artist_phonetic)
                {
                    idx += snprintf(message_info + idx, 60, "Artist: %s\n", substr((master_text->disc_artist ? master_text->disc_artist : master_text->disc_artist_phonetic), 0, 50));
                    LOG(lm_main, LOG_NOTICE, ("Album Artist: %s", substr((master_text->disc_artist ? master_text->disc_artist : master_text->disc_artist_phonetic), 0, 50)));
                }

                if (message_info[idx - 1] != '\n') { message_info[idx++] = '\n'; message_info[idx] = '\0'; }

                idx += snprintf(message_info + idx, 20, "Version: %02i.%02i\n", mtoc->version.major, mtoc->version.minor);
                LOG(lm_main, LOG_NOTICE, ("Disc Version: %02i.%02i\n", mtoc->version.major, mtoc->version.minor));
                idx += snprintf(message_info + idx, 25, "Created: %4i-%02i-%02i\n", mtoc->disc_date_year, mtoc->disc_date_month, mtoc->disc_date_day);

                idx += snprintf(message_info + idx, 15, "Area 0:\n");
                idx += snprintf(message_info + idx, 35, "   Speakers: %s\n", get_speaker_config_string(sb_handle->area[0].area_toc));
                idx += snprintf(message_info + idx, 35, "   Encoding: %s\n", get_frame_format_string(sb_handle->area[0].area_toc));
                idx += snprintf(message_info + idx, 25, "   Tracks: %d (%.2fGB)\n", sb_handle->area[0].area_toc->track_count, ((double) (sb_handle->area[0].area_toc->track_end - sb_handle->area[0].area_toc->track_start) * SACD_LSN_SIZE) / 1073741824.00);
                if (has_both_channels(sb_handle))
                {
                    idx += snprintf(message_info + idx, 2, "\n");
                    idx += snprintf(message_info + idx, 15, "Area 1:\n");
                    idx += snprintf(message_info + idx, 35, "   Speakers: %s\n", get_speaker_config_string(sb_handle->area[1].area_toc));
                    idx += snprintf(message_info + idx, 35, "   Encoding: %s\n", get_frame_format_string(sb_handle->area[1].area_toc));
                    idx += snprintf(message_info + idx, 25, "   Tracks: %d (%.2fGB)\n", sb_handle->area[1].area_toc->track_count, ((double) (sb_handle->area[1].area_toc->track_end - sb_handle->area[1].area_toc->track_start) * SACD_LSN_SIZE) / 1073741824.00);
                }

                idx += snprintf(message_info + idx, 50, "\nclick X to start ripping, O to change output");

                current_ripping_flags = 0;
                if (has_two_channel(sb_handle))
                {
                    current_ripping_flags |= RIP_2CH;
                    if (sb_handle->area[sb_handle->twoch_area_idx].area_toc->frame_format == FRAME_FORMAT_DST)
                    {
                        current_ripping_flags |= RIP_2CH_DST;
                    }
                }
                if (has_multi_channel(sb_handle))
                {
                    current_ripping_flags |= RIP_MCH;
                }

                // validate output format as the ripping flags have changed
                output_format_changed = 1;
                validate_output_format();

                scarletbook_close(sb_handle);
                sb_handle = 0;
            }
            else
            {
                bd_contains_sacd_disc = 0;
            }

            // close the input device asap
            sacd_close(sacd_reader);
            sacd_reader = 0;
        }
        else
        {
            bd_contains_sacd_disc = 0;
        }
    }

    if (output_device_changed || output_format_changed)
    {
        // output device
        if (output_device)
            idx = snprintf(message_output, 35, "Output: %s %.2fGB\n", output_device, output_device_space);
        else
            idx = snprintf(message_output, 35, "Output: NO DEVICE\n");

        // output format
        idx += snprintf(message_output + idx, 20, "Format: ");

        switch (output_format)
        {
        case 0:
            idx += snprintf(message_output + idx, 20, "2ch DSDIFF (DSD)\n");
            break;
        case 1:
            idx += snprintf(message_output + idx, 20, "2ch DSDIFF (DST)\n");
            break;
        case 2:
            idx += snprintf(message_output + idx, 20, "2ch DSF (DSD)\n");
            break;
        case 3:
            idx += snprintf(message_output + idx, 20, "mch DSDIFF (DSD)\n");
            break;
        case 4:
            idx += snprintf(message_output + idx, 20, "mch DSDIFF (DST)\n");
            break;
        case 5:
            idx += snprintf(message_output + idx, 20, "mch DSF (DSF)\n");
            break;
        case 6:
            idx += snprintf(message_output + idx, 20, "ISO\n");
            break;
        }
        idx += snprintf(message_output + idx, 2, "\n");
    }

    // by default we have no user controls
    dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_DISABLE_CANCEL_ON);

    if (bd_contains_sacd_disc)
    {
        snprintf(message, 512, "%s%s", message_output, message_info);
    }
    else
    {
        snprintf(message, 512, "The current disc is empty or not recognized as an SACD, please re-insert.\n\n%s"
                 , (output_device ? "" : "(Also make sure you connect an external fat32 formatted harddisk!)"));
    }

    // can we start ripping?
    if (bd_contains_sacd_disc)
    {
        dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_BTN_TYPE_OK);
    }

    msgDialogOpen2(dialog_type, message, dialog_handler, NULL, NULL);

    dialog_action         = 0;
    bd_disc_changed       = 0;
    output_device_changed = 0;
    output_format_changed = 0;
    while (!dialog_action && !user_requested_exit() && bd_disc_changed == 0 && output_device_changed == 0)
    {
        // poll for new output devices
        poll_output_devices();

        sysUtilCheckCallback();
        flip();
    }
    msgDialogAbort();

    // did user request to start the ripping process?
    if (dialog_action == 1 && bd_contains_sacd_disc)
    {
        start_ripping_gui(output_format_options[output_format]);

        reset_output_devices();

        // action is handled
        dialog_action = 0;
    }
    else if (dialog_action == 2)
    {
#if 0
        output_format++;

        // max of 7 output options
        if (output_format > 6)
        {
            output_format = 0;
        }
#endif

        // is the current selection valid?
        validate_output_format();

        // action is handled
        output_format_changed = 1;
        dialog_action = 0;
    }

    free(message);
}

void show_version(void)
{
    msgType dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_DISABLE_CANCEL_ON);
    msgDialogOpen2(dialog_type, "SACD-Ripper, Version " SACD_RIPPER_VERSION_STRING, dialog_handler, NULL, NULL);
    msgDialogClose(5000.0f);

    dialog_action = 0;
    while (!dialog_action && !user_requested_exit())
    {
        sysUtilCheckCallback();
        flip();
    }
    msgDialogAbort();
}

int user_select_server_mode(void)
{
	msgType dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_BTN_TYPE_YESNO | MSG_DIALOG_DISABLE_CANCEL_ON);
	msgDialogOpen2(dialog_type, "Would you like to run in server mode?", dialog_handler, NULL, NULL);
    msgDialogClose(5000.0f);

    dialog_action = 0;
    while (!dialog_action && !user_requested_exit())
    {
        sysUtilCheckCallback();
        flip();
    }
    msgDialogAbort();

    return dialog_action != 2;
}

int main(int argc, char *argv[])
{
    int     ret, server_mode;
    void    *host_addr = memalign(1024 * 1024, HOST_SIZE);
    msgType dialog_type;
	sys_ppu_thread_t id; // start server thread

    load_modules();

    init_logging();

	netInitialize();
	netCtlInit();

    // Initialize SPUs
    LOG(lm_main, LOG_DEBUG, ("Initializing SPUs\n"));
    ret = sysSpuInitialize(MAX_PHYSICAL_SPU, MAX_RAW_SPU);
    if (ret != 0)
    {
        LOG(lm_main, LOG_ERROR, ("sysSpuInitialize failed: %d\n", ret));
        goto quit;
    }

    init_screen(host_addr, HOST_SIZE);
    ioPadInit(7);

    ret = initialize_exit_handlers();
    if (ret != 0)
        goto quit;

    show_version();

    if (user_requested_exit())
        goto quit;

	u64 CEX=0x4345580000000000ULL;
	u64 DEX=0x4445580000000000ULL;

	if(lv2peek(0x80000000002E79C8ULL)==DEX) {dex_mode=2; c_firmware=3.41f;}
	else
	if(lv2peek(0x80000000002CFF98ULL)==CEX) {dex_mode=0; c_firmware=3.41f;}
	else
	if(lv2peek(0x80000000002EFE20ULL)==DEX) {dex_mode=2; c_firmware=3.55f;}
	else
	if(lv2peek(0x80000000002D83D0ULL)==CEX) {dex_mode=0; c_firmware=3.55f;}
	else
	if(lv2peek(0x8000000000302D88ULL)==DEX) {dex_mode=2; c_firmware=4.21f;}
	else
	if(lv2peek(0x80000000002E8610ULL)==CEX) {dex_mode=0; c_firmware=4.21f;}
	else
	if(lv2peek(0x80000000002E9F08ULL)==CEX) {dex_mode=0; c_firmware=4.30f;}
	else
	if(lv2peek(0x8000000000304630ULL)==DEX) {dex_mode=2; c_firmware=4.30f;}
	else
	if(lv2peek(0x80000000002E9F18ULL)==CEX) {dex_mode=0; c_firmware=4.31f;}
	else
	if(lv2peek(0x80000000002EA488ULL)==CEX) {dex_mode=0; c_firmware=4.40f;}
	else
	if(lv2peek(0x80000000002EA498ULL)==CEX) {dex_mode=0; c_firmware=4.41f;}
	else
	if(lv2peek(0x8000000000304EF0ULL)==DEX) {dex_mode=2; c_firmware=4.41f;}
	else
	if(lv2peek(0x80000000002EA9B8ULL)==CEX) {dex_mode=0; c_firmware=4.46f;}
	else
	if(lv2peek(0x8000000000305410ULL)==DEX) {dex_mode=2; c_firmware=4.46f;}
	else
	if(lv2peek(0x80000000002E9BE0ULL)==CEX) {dex_mode=0; c_firmware=4.50f;}
	else
	if(lv2peek(0x8000000000309698ULL)==DEX) {dex_mode=2; c_firmware=4.50f;}
	else
	if(lv2peek(0x80000000002E9D70ULL)==CEX) {dex_mode=0; c_firmware=4.53f;}
	else
	if(lv2peek(0x80000000002EC5E0ULL)==CEX) {dex_mode=0; c_firmware=4.55f;}
	else
	if(lv2peek(0x80000000002ED850ULL)==CEX) {dex_mode=0; c_firmware=4.60f;}
	else
	if(lv2peek(0x80000000002ED860ULL)==CEX) {dex_mode=0; c_firmware=4.65f;}
	else
	if(lv2peek(0x800000000030F1A8ULL)==DEX) {dex_mode=2; c_firmware=4.65f;}
	else
	if(lv2peek(0x80000000002ED778ULL)==CEX) {dex_mode=0; c_firmware=4.70f;}
	else
	if(lv2peek(0x800000000030F240ULL)==DEX) {dex_mode=2; c_firmware=4.70f;}
	else
	if(lv2peek(0x80000000002ED818ULL)==CEX) {dex_mode=0; c_firmware=4.75f;}
	else
	if(lv2peek(0x800000000030F2D0ULL)==DEX) {dex_mode=2; c_firmware=4.75f;}
	else
	if(lv2peek(0x80000000002ED808ULL)==CEX) {dex_mode=0; c_firmware=4.80f;}
	else
	if(lv2peek(0x800000000030F3A0ULL)==DEX) {dex_mode=2; c_firmware=4.80f;}
	else
	if(lv2peek(0x800000000030F3B0ULL)==DEX) {dex_mode=2; c_firmware=4.81f;}
	else
		c_firmware=0.00f;

	if(c_firmware==3.55f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_355D;
	}
	else
	if(c_firmware==3.55f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_355;
	}
	else
	if(c_firmware==4.21f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_421;
	}
	else
	if(c_firmware==4.30f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_430;
	}
	else
	if(c_firmware==4.30f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_430D;
	}
	else
	if(c_firmware==4.31f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_431;
	}
	else
	if(c_firmware==4.40f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_440;
	}
	else
	if(c_firmware==4.41f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_441;
	}
	else
	if(c_firmware==4.41f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_441D;
	}
	else
	if(c_firmware==4.46f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_446;
	}
	else
	if(c_firmware==4.50f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_450;
	}
	else
	if(c_firmware==4.53f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_453;
	}
	else
	if(c_firmware==4.55f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_455;
	}
	else
	if(c_firmware==4.60f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_460;
	}
	else
	if(c_firmware==4.65f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_465;
	}
	else
	if(c_firmware==4.65f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_465D;
	}
	else
	if(c_firmware==4.70f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_470;
	}
	else
	if(c_firmware==4.70f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_470D;
	}
	else
	if(c_firmware==4.75f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_475;
	}
	else
	if(c_firmware==4.80f && !dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_480;
	}
	else
	if(c_firmware==4.80f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_480D;
	}
	else
	if(c_firmware==4.75f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_475D;
	}
	else
	if(c_firmware==4.81f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_481D;
	}
	else
	if(c_firmware==4.46f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_446D;
	}
	else
	if(c_firmware==4.50f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_450D;
	}
	else
	if(c_firmware==4.21f && dex_mode)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_421D;
	}
	else
	if(c_firmware==3.41f)
	{
		SYSCALL_TABLE			= SYSCALL_TABLE_341;
	}
/*
	if(c_firmware>=4.20f && SYSCALL_TABLE)
	{
		// add and enable lv2 peek/poke + lv1 peek/poke
		lv2poke(0x800000000000171CULL,       0x7C0802A6F8010010ULL);
		lv2poke(0x800000000000171CULL +   8, 0x396000B644000022ULL);
		lv2poke(0x800000000000171CULL +  16, 0x7C832378E8010010ULL);
		lv2poke(0x800000000000171CULL +  24, 0x7C0803A64E800020ULL);
		lv2poke(0x800000000000171CULL +  32, 0x7C0802A6F8010010ULL);
		lv2poke(0x800000000000171CULL +  40, 0x396000B744000022ULL);
		lv2poke(0x800000000000171CULL +  48, 0x38600000E8010010ULL);
		lv2poke(0x800000000000171CULL +  56, 0x7C0803A64E800020ULL);
		lv2poke(0x800000000000171CULL +  64, 0x7C0802A6F8010010ULL);
		lv2poke(0x800000000000171CULL +  72, 0x7D4B537844000022ULL);
		lv2poke(0x800000000000171CULL +  80, 0xE80100107C0803A6ULL);
		lv2poke(0x800000000000171CULL +  88, 0x4E80002080000000ULL);
		lv2poke(0x800000000000171CULL +  96, 0x0000170C80000000ULL);
		lv2poke(0x800000000000171CULL + 104, 0x0000171480000000ULL);
		lv2poke(0x800000000000171CULL + 112, 0x0000171C80000000ULL);
		lv2poke(0x800000000000171CULL + 120, 0x0000173C80000000ULL);
		lv2poke(0x800000000000171CULL + 128, 0x0000175C00000000ULL);
		lv2poke(SYSCALL_PTR( 6), 0x8000000000001778ULL); //sc6
		lv2poke(SYSCALL_PTR( 7), 0x8000000000001780ULL); //sc7
		lv2poke(SYSCALL_PTR( 8), 0x8000000000001788ULL); //sc8
		lv2poke(SYSCALL_PTR( 9), 0x8000000000001790ULL); //sc9
		lv2poke(SYSCALL_PTR(10), 0x8000000000001798ULL); //sc10
	}*/
    // remove patch protection
	if(c_firmware==3.55f)
	    remove_protection();

	if(c_firmware==0.00f)
		ret = -1;
	else
	    ret = patch_lv1_ss_services();
    if (ret < 0)
    {
        dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_BTN_TYPE_OK | MSG_DIALOG_DISABLE_CANCEL_ON);
        msgDialogOpen2(dialog_type, "ERROR: Couldn't patch lv1 services, returning to the XMB.\nMake sure you are running a firmware which allows patching!", dialog_handler, NULL, NULL);

        dialog_action = 0;
        while (!dialog_action && !user_requested_exit())
        {
            sysUtilCheckCallback();
            flip();
        }
        msgDialogAbort();

        goto quit;
    }

    // patch syscall 864 to allow drive re-init
	if(c_firmware==0.0f)
		ret = -1;
	else
	    ret = patch_syscall_864();
    if (ret < 0)
    {
        dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_BTN_TYPE_OK | MSG_DIALOG_DISABLE_CANCEL_ON);
        msgDialogOpen2(dialog_type, "ERROR: Couldn't patch syscall 864, returning to the XMB.\nMake sure you are running a firmware which allows patching!", dialog_handler, NULL, NULL);

        dialog_action = 0;
        while (!dialog_action && !user_requested_exit())
        {
            sysUtilCheckCallback();
            flip();
        }
        msgDialogAbort();

        goto quit;
    }

    // install the necessary modules
    ret = install_modules();
    if (ret < 0)
    {
        dialog_type = (MSG_DIALOG_NORMAL | MSG_DIALOG_BTN_TYPE_OK | MSG_DIALOG_DISABLE_CANCEL_ON);
        msgDialogOpen2(dialog_type, "Installation was aborted, returning to the XMB.", dialog_handler, NULL, NULL);

        dialog_action = 0;
        while (!dialog_action && !user_requested_exit())
        {
            sysUtilCheckCallback();
            flip();
        }
        msgDialogAbort();

        goto quit;
    }

    if (user_requested_exit())
        goto quit;

    // reset & re-authenticate the BD drive
    sys_storage_reset_bd();
    sys_storage_authenticate_bd();

    // eject current disc
    {
        int fd;
        ret = sys_storage_open(BD_DEVICE, &fd);
        if (ret == 0)
        {
            ioctl_eject(fd);
            sys_storage_close(fd);
        }
    }

    ret = sysDiscRegisterDiscChangeCallback(&bd_eject_disc_callback, &bd_insert_disc_callback);

    // poll for an output_device
    poll_output_devices();

    server_mode = user_select_server_mode();

    if (user_requested_exit())
        goto quit;

    if (server_mode)
    {
#ifdef ENABLE_LOGGING
        if (output_device)
        {
            char file_path[100];
            sprintf(file_path, "%s/daemon_log.txt", output_device);
            set_log_file(file_path);
        }
#endif
    	sysThreadCreate(&id, listener_thread, NULL, 1500, 0x400, 0, "listener");

        while (1)
        {
            // server loop
            server_loop();

            // break out of the loop when requested
            if (user_requested_exit())
                break;
        }
    }
    else
    {
        while (1)
        {
            // main loop
            main_loop();

            // break out of the loop when requested
            if (user_requested_exit())
                break;
        }
    }

    ret = sysDiscUnregisterDiscChangeCallback();

 quit:

    unpatch_lv1_ss_services();

    destroy_logging();
	netDeinitialize();
    unload_modules();

    free(host_addr);

    return 0;
}
