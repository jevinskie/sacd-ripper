#!/usr/bin/env python3

import sys

import lief

prx = lief.parse(sys.argv[1])
prx_bin = open(sys.argv[1], 'rb').read()

elf_magic = b'\x7F\x45\x4C\x46'

elf = None
for i in range(4, len(prx_bin), 4):
	if prx_bin[i:i+4] == elf_magic:
		elf = lief.parse(list(prx_bin[i:]))
		for n in elf.notes:
			if n.name != 'SPUNAME':
				continue
			name = n.description
			name_swap = list(name)
			for j in range(0, len(name), 4):
				name_swap[j+0] = name[j+3]
				name_swap[j+1] = name[j+2]
				name_swap[j+2] = name[j+1]
				name_swap[j+3] = name[j+0]
			name_swap = ''.join(map(chr, name_swap))
			print('note name swap: ' + name_swap)
			if 'decoder.spu' in name_swap:
				print('found it')
				sec_len = 0
				for sec in elf.sections:
					if sec.type == lief.ELF.SECTION_TYPES.NOBITS:
						continue
					sec_len = max(sec_len, sec.file_offset + sec.original_size)
				seg_len = 0
				for seg in elf.segments:
					seg_len = max(seg_len, seg.file_offset + seg.physical_size)
				shdr_len = elf.header.section_header_offset + elf.header.section_header_size
				print('sec_len: {} seg_len: {} virtual_size: {} shdr_len: {}'.format(sec_len, seg_len, elf.virtual_size, shdr_len))
				with open('decoder.spu.elf', 'wb') as f:
					f.write(prx_bin[i:i+elf.virtual_size])
