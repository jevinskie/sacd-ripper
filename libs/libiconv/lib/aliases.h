/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode10.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf aliases.gperf  */
/* Computed positions: -k'1,3-11,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "aliases.gperf"
struct alias { int name; unsigned int encoding_index; };

#define TOTAL_KEYWORDS 324
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 45
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 1525
/* maximum key range = 1524, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
aliases_hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526,    5,   10, 1526,  100,    0,
         5,   90,  210,   20,   15,  130,   10,   25,  330, 1526,
      1526, 1526, 1526, 1526, 1526,  330,  290,    0,   10,   90,
        50,   20,  200,    0,  410,  290,    0,   95,   25,    0,
        10, 1526,  100,    0,   35,  160,  230,  100,  450,    0,
         0, 1526, 1526, 1526, 1526,  195, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526,
      1526, 1526, 1526, 1526, 1526, 1526, 1526, 1526
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

struct stringpool_t
  {
    char stringpool_str2[sizeof("L1")];
    char stringpool_str4[sizeof("SJIS")];
    char stringpool_str7[sizeof("L2")];
    char stringpool_str12[sizeof("L8")];
    char stringpool_str17[sizeof("L6")];
    char stringpool_str22[sizeof("L5")];
    char stringpool_str23[sizeof("862")];
    char stringpool_str27[sizeof("CN")];
    char stringpool_str31[sizeof("CP1251")];
    char stringpool_str40[sizeof("CP862")];
    char stringpool_str41[sizeof("CP1252")];
    char stringpool_str43[sizeof("866")];
    char stringpool_str51[sizeof("CP1258")];
    char stringpool_str53[sizeof("C99")];
    char stringpool_str60[sizeof("CP866")];
    char stringpool_str61[sizeof("CP1256")];
    char stringpool_str65[sizeof("CP819")];
    char stringpool_str66[sizeof("LATIN1")];
    char stringpool_str71[sizeof("CP1255")];
    char stringpool_str76[sizeof("LATIN2")];
    char stringpool_str79[sizeof("ISO8859-1")];
    char stringpool_str85[sizeof("ISO-8859-1")];
    char stringpool_str86[sizeof("LATIN8")];
    char stringpool_str89[sizeof("ISO8859-2")];
    char stringpool_str92[sizeof("L3")];
    char stringpool_str95[sizeof("ISO-8859-2")];
    char stringpool_str96[sizeof("LATIN6")];
    char stringpool_str98[sizeof("MAC")];
    char stringpool_str99[sizeof("ISO8859-8")];
    char stringpool_str105[sizeof("ISO-8859-8")];
    char stringpool_str106[sizeof("LATIN5")];
    char stringpool_str108[sizeof("CYRILLIC")];
    char stringpool_str109[sizeof("ISO8859-6")];
    char stringpool_str110[sizeof("ISO8859-16")];
    char stringpool_str111[sizeof("CP1361")];
    char stringpool_str112[sizeof("R8")];
    char stringpool_str115[sizeof("ISO-8859-6")];
    char stringpool_str116[sizeof("ISO-8859-16")];
    char stringpool_str119[sizeof("ISO8859-5")];
    char stringpool_str120[sizeof("ISO8859-15")];
    char stringpool_str125[sizeof("ISO-8859-5")];
    char stringpool_str126[sizeof("ISO-8859-15")];
    char stringpool_str129[sizeof("ISO8859-9")];
    char stringpool_str130[sizeof("CP932")];
    char stringpool_str131[sizeof("GB2312")];
    char stringpool_str132[sizeof("L7")];
    char stringpool_str135[sizeof("ISO-8859-9")];
    char stringpool_str136[sizeof("IBM862")];
    char stringpool_str140[sizeof("ISO-CELTIC")];
    char stringpool_str145[sizeof("EUCCN")];
    char stringpool_str148[sizeof("ISO-IR-6")];
    char stringpool_str150[sizeof("CP936")];
    char stringpool_str151[sizeof("EUC-CN")];
    char stringpool_str155[sizeof("ISO-IR-126")];
    char stringpool_str156[sizeof("IBM866")];
    char stringpool_str159[sizeof("ISO-IR-58")];
    char stringpool_str160[sizeof("ISO-IR-226")];
    char stringpool_str161[sizeof("IBM819")];
    char stringpool_str162[sizeof("US")];
    char stringpool_str163[sizeof("UHC")];
    char stringpool_str165[sizeof("ISO-IR-166")];
    char stringpool_str175[sizeof("ISO-IR-165")];
    char stringpool_str176[sizeof("CSISO2022CN")];
    char stringpool_str180[sizeof("UCS-2")];
    char stringpool_str186[sizeof("ISO-2022-CN")];
    char stringpool_str190[sizeof("ISO-IR-159")];
    char stringpool_str195[sizeof("ISO-IR-199")];
    char stringpool_str200[sizeof("ISO-2022-CN-EXT")];
    char stringpool_str202[sizeof("HZ")];
    char stringpool_str206[sizeof("MACCYRILLIC")];
    char stringpool_str207[sizeof("MS-CYRL")];
    char stringpool_str211[sizeof("CP1253")];
    char stringpool_str212[sizeof("L4")];
    char stringpool_str213[sizeof("850")];
    char stringpool_str220[sizeof("ISO-IR-101")];
    char stringpool_str230[sizeof("ISO-IR-138")];
    char stringpool_str231[sizeof("CP1250")];
    char stringpool_str233[sizeof("TIS620.2529-1")];
    char stringpool_str235[sizeof("CP850")];
    char stringpool_str236[sizeof("VISCII")];
    char stringpool_str238[sizeof("CSVISCII")];
    char stringpool_str240[sizeof("UTF-8")];
    char stringpool_str246[sizeof("LATIN3")];
    char stringpool_str250[sizeof("CP950")];
    char stringpool_str251[sizeof("UTF-16")];
    char stringpool_str256[sizeof("VISCII1.1-1")];
    char stringpool_str259[sizeof("ISO8859-3")];
    char stringpool_str260[sizeof("ISO8859-13")];
    char stringpool_str261[sizeof("TIS620")];
    char stringpool_str265[sizeof("ISO-8859-3")];
    char stringpool_str266[sizeof("ISO-8859-13")];
    char stringpool_str267[sizeof("TIS-620")];
    char stringpool_str270[sizeof("ISO-IR-109")];
    char stringpool_str275[sizeof("ISO_8859-1")];
    char stringpool_str276[sizeof("CP1133")];
    char stringpool_str277[sizeof("WINDOWS-1251")];
    char stringpool_str280[sizeof("ISO8859-10")];
    char stringpool_str281[sizeof("UNICODE-1-1")];
    char stringpool_str282[sizeof("WINDOWS-1252")];
    char stringpool_str285[sizeof("ISO_8859-2")];
    char stringpool_str286[sizeof("ISO-8859-10")];
    char stringpool_str287[sizeof("WINDOWS-1258")];
    char stringpool_str290[sizeof("CP949")];
    char stringpool_str291[sizeof("CP1257")];
    char stringpool_str292[sizeof("WINDOWS-1256")];
    char stringpool_str295[sizeof("ISO_8859-8")];
    char stringpool_str296[sizeof("CSUNICODE11")];
    char stringpool_str297[sizeof("WINDOWS-1255")];
    char stringpool_str300[sizeof("ISO-IR-179")];
    char stringpool_str302[sizeof("CHINESE")];
    char stringpool_str304[sizeof("ISO646-CN")];
    char stringpool_str305[sizeof("ISO_8859-6")];
    char stringpool_str306[sizeof("ISO_8859-16")];
    char stringpool_str311[sizeof("ISO_8859-15:1998")];
    char stringpool_str315[sizeof("ISO_8859-5")];
    char stringpool_str316[sizeof("ISO_8859-15")];
    char stringpool_str319[sizeof("TCVN")];
    char stringpool_str320[sizeof("ISO-IR-110")];
    char stringpool_str321[sizeof("UTF-32")];
    char stringpool_str325[sizeof("ISO_8859-9")];
    char stringpool_str326[sizeof("LATIN7")];
    char stringpool_str330[sizeof("EUCTW")];
    char stringpool_str331[sizeof("IBM850")];
    char stringpool_str335[sizeof("ASCII")];
    char stringpool_str336[sizeof("EUC-TW")];
    char stringpool_str337[sizeof("CSASCII")];
    char stringpool_str339[sizeof("ISO8859-7")];
    char stringpool_str345[sizeof("ISO-8859-7")];
    char stringpool_str350[sizeof("ISO-IR-148")];
    char stringpool_str354[sizeof("BIG5")];
    char stringpool_str356[sizeof("CSBIG5")];
    char stringpool_str357[sizeof("UCS-2LE")];
    char stringpool_str360[sizeof("BIG-5")];
    char stringpool_str362[sizeof("CN-BIG5")];
    char stringpool_str367[sizeof("WINDOWS-1253")];
    char stringpool_str368[sizeof("TIS620-0")];
    char stringpool_str370[sizeof("CP367")];
    char stringpool_str375[sizeof("MS-EE")];
    char stringpool_str377[sizeof("WINDOWS-1250")];
    char stringpool_str378[sizeof("ELOT_928")];
    char stringpool_str380[sizeof("ISO-IR-149")];
    char stringpool_str381[sizeof("KOI8-T")];
    char stringpool_str383[sizeof("TIS620.2533-1")];
    char stringpool_str384[sizeof("CSUNICODE")];
    char stringpool_str385[sizeof("ISO-IR-127")];
    char stringpool_str386[sizeof("ISO_8859-10:1992")];
    char stringpool_str389[sizeof("ISO-IR-87")];
    char stringpool_str390[sizeof("IBM-CP1133")];
    char stringpool_str396[sizeof("ISO_8859-16:2000")];
    char stringpool_str399[sizeof("ISO-IR-57")];
    char stringpool_str400[sizeof("ISO-IR-157")];
    char stringpool_str401[sizeof("CSISOLATIN1")];
    char stringpool_str405[sizeof("ISO-IR-203")];
    char stringpool_str407[sizeof("WINDOWS-1257")];
    char stringpool_str408[sizeof("CSISOLATINCYRILLIC")];
    char stringpool_str411[sizeof("CSISOLATIN2")];
    char stringpool_str414[sizeof("ISO646-US")];
    char stringpool_str417[sizeof("UNICODE-1-1-UTF-7")];
    char stringpool_str418[sizeof("UTF-16LE")];
    char stringpool_str420[sizeof("ISO-IR-100")];
    char stringpool_str422[sizeof("JP")];
    char stringpool_str423[sizeof("CSGB2312")];
    char stringpool_str427[sizeof("GB18030")];
    char stringpool_str430[sizeof("CSUNICODE11UTF7")];
    char stringpool_str431[sizeof("CSISOLATIN6")];
    char stringpool_str433[sizeof("UNICODELITTLE")];
    char stringpool_str439[sizeof("UCS-2-INTERNAL")];
    char stringpool_str441[sizeof("CSISOLATIN5")];
    char stringpool_str448[sizeof("CSIBM866")];
    char stringpool_str449[sizeof("CSPC850MULTILINGUAL")];
    char stringpool_str451[sizeof("CP1254")];
    char stringpool_str454[sizeof("CN-GB-ISOIR165")];
    char stringpool_str455[sizeof("ISO_8859-3")];
    char stringpool_str456[sizeof("ISO_8859-13")];
    char stringpool_str459[sizeof("ARMSCII-8")];
    char stringpool_str460[sizeof("TCVN5712-1")];
    char stringpool_str462[sizeof("MS-ANSI")];
    char stringpool_str464[sizeof("TCVN-5712")];
    char stringpool_str466[sizeof("IBM367")];
    char stringpool_str470[sizeof("X0212")];
    char stringpool_str476[sizeof("ISO_8859-10")];
    char stringpool_str480[sizeof("UTF-7")];
    char stringpool_str483[sizeof("TIS620.2533-0")];
    char stringpool_str485[sizeof("GB_1988-80")];
    char stringpool_str486[sizeof("LATIN4")];
    char stringpool_str487[sizeof("WINDOWS-1254")];
    char stringpool_str492[sizeof("CSEUCTW")];
    char stringpool_str498[sizeof("UTF-32LE")];
    char stringpool_str499[sizeof("ISO8859-4")];
    char stringpool_str500[sizeof("ISO8859-14")];
    char stringpool_str501[sizeof("ISO_8859-14:1998")];
    char stringpool_str503[sizeof("US-ASCII")];
    char stringpool_str505[sizeof("ISO-8859-4")];
    char stringpool_str506[sizeof("ISO-8859-14")];
    char stringpool_str507[sizeof("CSKOI8R")];
    char stringpool_str508[sizeof("CSISO57GB1988")];
    char stringpool_str509[sizeof("SHIFT-JIS")];
    char stringpool_str511[sizeof("KOI8-R")];
    char stringpool_str516[sizeof("GREEK8")];
    char stringpool_str521[sizeof("GEORGIAN-PS")];
    char stringpool_str523[sizeof("CSPC862LATINHEBREW")];
    char stringpool_str525[sizeof("EUCJP")];
    char stringpool_str529[sizeof("MULELAO-1")];
    char stringpool_str530[sizeof("ISO-10646-UCS-2")];
    char stringpool_str531[sizeof("EUC-JP")];
    char stringpool_str534[sizeof("CHAR")];
    char stringpool_str535[sizeof("ISO_8859-7")];
    char stringpool_str539[sizeof("ISO-IR-14")];
    char stringpool_str540[sizeof("GB_2312-80")];
    char stringpool_str548[sizeof("ECMA-118")];
    char stringpool_str550[sizeof("CSISO58GB231280")];
    char stringpool_str552[sizeof("CSISO2022JP2")];
    char stringpool_str556[sizeof("CSISO2022JP")];
    char stringpool_str558[sizeof("ISO-2022-JP-1")];
    char stringpool_str560[sizeof("X0201")];
    char stringpool_str562[sizeof("UCS-4LE")];
    char stringpool_str563[sizeof("ISO-2022-JP-2")];
    char stringpool_str564[sizeof("MACINTOSH")];
    char stringpool_str565[sizeof("CP874")];
    char stringpool_str566[sizeof("ISO-2022-JP")];
    char stringpool_str570[sizeof("MACICELAND")];
    char stringpool_str575[sizeof("CSISO159JISX02121990")];
    char stringpool_str576[sizeof("ROMAN8")];
    char stringpool_str580[sizeof("X0208")];
    char stringpool_str581[sizeof("CSISOLATIN3")];
    char stringpool_str585[sizeof("EUCKR")];
    char stringpool_str586[sizeof("CSUCS4")];
    char stringpool_str590[sizeof("UCS-4")];
    char stringpool_str591[sizeof("EUC-KR")];
    char stringpool_str593[sizeof("CSKSC56011987")];
    char stringpool_str600[sizeof("UNICODEBIG")];
    char stringpool_str603[sizeof("GBK")];
    char stringpool_str610[sizeof("CN-GB")];
    char stringpool_str616[sizeof("CSISO2022KR")];
    char stringpool_str626[sizeof("ISO-2022-KR")];
    char stringpool_str628[sizeof("KSC_5601")];
    char stringpool_str630[sizeof("ISO_8859-8:1988")];
    char stringpool_str631[sizeof("KOI8-U")];
    char stringpool_str635[sizeof("HZ-GB-2312")];
    char stringpool_str637[sizeof("CSISO14JISC6220RO")];
    char stringpool_str640[sizeof("ISO_8859-5:1988")];
    char stringpool_str642[sizeof("JIS0208")];
    char stringpool_str644[sizeof("UCS-4-INTERNAL")];
    char stringpool_str647[sizeof("UCS-2BE")];
    char stringpool_str648[sizeof("UCS-2-SWAPPED")];
    char stringpool_str660[sizeof("ISO_8859-9:1989")];
    char stringpool_str663[sizeof("NEXTSTEP")];
    char stringpool_str667[sizeof("MACTHAI")];
    char stringpool_str678[sizeof("MACROMAN")];
    char stringpool_str684[sizeof("ISO646-JP")];
    char stringpool_str688[sizeof("ASMO-708")];
    char stringpool_str695[sizeof("ISO_8859-4")];
    char stringpool_str696[sizeof("ISO_8859-14")];
    char stringpool_str699[sizeof("SHIFT_JIS")];
    char stringpool_str705[sizeof("CSSHIFTJIS")];
    char stringpool_str706[sizeof("CSISOLATINHEBREW")];
    char stringpool_str708[sizeof("UTF-16BE")];
    char stringpool_str710[sizeof("ISO_8859-3:1988")];
    char stringpool_str715[sizeof("CSISOLATINGREEK")];
    char stringpool_str732[sizeof("KOI8-RU")];
    char stringpool_str735[sizeof("ISO-10646-UCS-4")];
    char stringpool_str736[sizeof("CSISOLATINARABIC")];
    char stringpool_str740[sizeof("ISO_8859-1:1987")];
    char stringpool_str745[sizeof("ISO_8859-2:1987")];
    char stringpool_str747[sizeof("CSEUCKR")];
    char stringpool_str750[sizeof("ISO-IR-144")];
    char stringpool_str752[sizeof("JIS_C6220-1969-RO")];
    char stringpool_str754[sizeof("JIS_C6226-1983")];
    char stringpool_str755[sizeof("ISO_8859-6:1987")];
    char stringpool_str777[sizeof("BIGFIVE")];
    char stringpool_str783[sizeof("BIG-FIVE")];
    char stringpool_str784[sizeof("HP-ROMAN8")];
    char stringpool_str785[sizeof("GREEK")];
    char stringpool_str788[sizeof("UTF-32BE")];
    char stringpool_str790[sizeof("CSHPROMAN8")];
    char stringpool_str791[sizeof("ISO_646.IRV:1991")];
    char stringpool_str811[sizeof("WINDOWS-874")];
    char stringpool_str821[sizeof("CSISOLATIN4")];
    char stringpool_str829[sizeof("BIG5HKSCS")];
    char stringpool_str830[sizeof("ISO_8859-4:1988")];
    char stringpool_str835[sizeof("BIG5-HKSCS")];
    char stringpool_str846[sizeof("GEORGIAN-ACADEMY")];
    char stringpool_str849[sizeof("CSEUCPKDFMTJAPANESE")];
    char stringpool_str852[sizeof("UCS-4BE")];
    char stringpool_str853[sizeof("UCS-4-SWAPPED")];
    char stringpool_str859[sizeof("KS_C_5601-1989")];
    char stringpool_str865[sizeof("EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE")];
    char stringpool_str866[sizeof("KOREAN")];
    char stringpool_str870[sizeof("ISO_8859-7:1987")];
    char stringpool_str871[sizeof("MACCENTRALEUROPE")];
    char stringpool_str885[sizeof("TCVN5712-1:1993")];
    char stringpool_str886[sizeof("HEBREW")];
    char stringpool_str887[sizeof("MS-HEBR")];
    char stringpool_str896[sizeof("CSMACINTOSH")];
    char stringpool_str948[sizeof("ECMA-114")];
    char stringpool_str951[sizeof("MACCROATIAN")];
    char stringpool_str956[sizeof("ARABIC")];
    char stringpool_str964[sizeof("KS_C_5601-1987")];
    char stringpool_str982[sizeof("MS-TURK")];
    char stringpool_str983[sizeof("MACGREEK")];
    char stringpool_str988[sizeof("MS-GREEK")];
    char stringpool_str1002[sizeof("WCHAR_T")];
    char stringpool_str1025[sizeof("CSISO87JISX0208")];
    char stringpool_str1074[sizeof("MACHEBREW")];
    char stringpool_str1080[sizeof("WINBALTRIM")];
    char stringpool_str1090[sizeof("MACTURKISH")];
    char stringpool_str1123[sizeof("JISX0201-1976")];
    char stringpool_str1154[sizeof("MACARABIC")];
    char stringpool_str1179[sizeof("JIS_X0212")];
    char stringpool_str1190[sizeof("MACUKRAINE")];
    char stringpool_str1269[sizeof("JIS_X0201")];
    char stringpool_str1274[sizeof("CSHALFWIDTHKATAKANA")];
    char stringpool_str1284[sizeof("JIS_X0212-1990")];
    char stringpool_str1289[sizeof("JIS_X0208")];
    char stringpool_str1291[sizeof("JIS_X0212.1990-0")];
    char stringpool_str1304[sizeof("JAVA")];
    char stringpool_str1314[sizeof("ANSI_X3.4-1968")];
    char stringpool_str1315[sizeof("MACROMANIA")];
    char stringpool_str1319[sizeof("ANSI_X3.4-1986")];
    char stringpool_str1353[sizeof("MS_KANJI")];
    char stringpool_str1379[sizeof("JIS_X0208-1983")];
    char stringpool_str1389[sizeof("JIS_X0208-1990")];
    char stringpool_str1447[sizeof("MS-ARAB")];
    char stringpool_str1525[sizeof("JOHAB")];
  };
static const struct stringpool_t stringpool_contents =
  {
    "L1",
    "SJIS",
    "L2",
    "L8",
    "L6",
    "L5",
    "862",
    "CN",
    "CP1251",
    "CP862",
    "CP1252",
    "866",
    "CP1258",
    "C99",
    "CP866",
    "CP1256",
    "CP819",
    "LATIN1",
    "CP1255",
    "LATIN2",
    "ISO8859-1",
    "ISO-8859-1",
    "LATIN8",
    "ISO8859-2",
    "L3",
    "ISO-8859-2",
    "LATIN6",
    "MAC",
    "ISO8859-8",
    "ISO-8859-8",
    "LATIN5",
    "CYRILLIC",
    "ISO8859-6",
    "ISO8859-16",
    "CP1361",
    "R8",
    "ISO-8859-6",
    "ISO-8859-16",
    "ISO8859-5",
    "ISO8859-15",
    "ISO-8859-5",
    "ISO-8859-15",
    "ISO8859-9",
    "CP932",
    "GB2312",
    "L7",
    "ISO-8859-9",
    "IBM862",
    "ISO-CELTIC",
    "EUCCN",
    "ISO-IR-6",
    "CP936",
    "EUC-CN",
    "ISO-IR-126",
    "IBM866",
    "ISO-IR-58",
    "ISO-IR-226",
    "IBM819",
    "US",
    "UHC",
    "ISO-IR-166",
    "ISO-IR-165",
    "CSISO2022CN",
    "UCS-2",
    "ISO-2022-CN",
    "ISO-IR-159",
    "ISO-IR-199",
    "ISO-2022-CN-EXT",
    "HZ",
    "MACCYRILLIC",
    "MS-CYRL",
    "CP1253",
    "L4",
    "850",
    "ISO-IR-101",
    "ISO-IR-138",
    "CP1250",
    "TIS620.2529-1",
    "CP850",
    "VISCII",
    "CSVISCII",
    "UTF-8",
    "LATIN3",
    "CP950",
    "UTF-16",
    "VISCII1.1-1",
    "ISO8859-3",
    "ISO8859-13",
    "TIS620",
    "ISO-8859-3",
    "ISO-8859-13",
    "TIS-620",
    "ISO-IR-109",
    "ISO_8859-1",
    "CP1133",
    "WINDOWS-1251",
    "ISO8859-10",
    "UNICODE-1-1",
    "WINDOWS-1252",
    "ISO_8859-2",
    "ISO-8859-10",
    "WINDOWS-1258",
    "CP949",
    "CP1257",
    "WINDOWS-1256",
    "ISO_8859-8",
    "CSUNICODE11",
    "WINDOWS-1255",
    "ISO-IR-179",
    "CHINESE",
    "ISO646-CN",
    "ISO_8859-6",
    "ISO_8859-16",
    "ISO_8859-15:1998",
    "ISO_8859-5",
    "ISO_8859-15",
    "TCVN",
    "ISO-IR-110",
    "UTF-32",
    "ISO_8859-9",
    "LATIN7",
    "EUCTW",
    "IBM850",
    "ASCII",
    "EUC-TW",
    "CSASCII",
    "ISO8859-7",
    "ISO-8859-7",
    "ISO-IR-148",
    "BIG5",
    "CSBIG5",
    "UCS-2LE",
    "BIG-5",
    "CN-BIG5",
    "WINDOWS-1253",
    "TIS620-0",
    "CP367",
    "MS-EE",
    "WINDOWS-1250",
    "ELOT_928",
    "ISO-IR-149",
    "KOI8-T",
    "TIS620.2533-1",
    "CSUNICODE",
    "ISO-IR-127",
    "ISO_8859-10:1992",
    "ISO-IR-87",
    "IBM-CP1133",
    "ISO_8859-16:2000",
    "ISO-IR-57",
    "ISO-IR-157",
    "CSISOLATIN1",
    "ISO-IR-203",
    "WINDOWS-1257",
    "CSISOLATINCYRILLIC",
    "CSISOLATIN2",
    "ISO646-US",
    "UNICODE-1-1-UTF-7",
    "UTF-16LE",
    "ISO-IR-100",
    "JP",
    "CSGB2312",
    "GB18030",
    "CSUNICODE11UTF7",
    "CSISOLATIN6",
    "UNICODELITTLE",
    "UCS-2-INTERNAL",
    "CSISOLATIN5",
    "CSIBM866",
    "CSPC850MULTILINGUAL",
    "CP1254",
    "CN-GB-ISOIR165",
    "ISO_8859-3",
    "ISO_8859-13",
    "ARMSCII-8",
    "TCVN5712-1",
    "MS-ANSI",
    "TCVN-5712",
    "IBM367",
    "X0212",
    "ISO_8859-10",
    "UTF-7",
    "TIS620.2533-0",
    "GB_1988-80",
    "LATIN4",
    "WINDOWS-1254",
    "CSEUCTW",
    "UTF-32LE",
    "ISO8859-4",
    "ISO8859-14",
    "ISO_8859-14:1998",
    "US-ASCII",
    "ISO-8859-4",
    "ISO-8859-14",
    "CSKOI8R",
    "CSISO57GB1988",
    "SHIFT-JIS",
    "KOI8-R",
    "GREEK8",
    "GEORGIAN-PS",
    "CSPC862LATINHEBREW",
    "EUCJP",
    "MULELAO-1",
    "ISO-10646-UCS-2",
    "EUC-JP",
    "CHAR",
    "ISO_8859-7",
    "ISO-IR-14",
    "GB_2312-80",
    "ECMA-118",
    "CSISO58GB231280",
    "CSISO2022JP2",
    "CSISO2022JP",
    "ISO-2022-JP-1",
    "X0201",
    "UCS-4LE",
    "ISO-2022-JP-2",
    "MACINTOSH",
    "CP874",
    "ISO-2022-JP",
    "MACICELAND",
    "CSISO159JISX02121990",
    "ROMAN8",
    "X0208",
    "CSISOLATIN3",
    "EUCKR",
    "CSUCS4",
    "UCS-4",
    "EUC-KR",
    "CSKSC56011987",
    "UNICODEBIG",
    "GBK",
    "CN-GB",
    "CSISO2022KR",
    "ISO-2022-KR",
    "KSC_5601",
    "ISO_8859-8:1988",
    "KOI8-U",
    "HZ-GB-2312",
    "CSISO14JISC6220RO",
    "ISO_8859-5:1988",
    "JIS0208",
    "UCS-4-INTERNAL",
    "UCS-2BE",
    "UCS-2-SWAPPED",
    "ISO_8859-9:1989",
    "NEXTSTEP",
    "MACTHAI",
    "MACROMAN",
    "ISO646-JP",
    "ASMO-708",
    "ISO_8859-4",
    "ISO_8859-14",
    "SHIFT_JIS",
    "CSSHIFTJIS",
    "CSISOLATINHEBREW",
    "UTF-16BE",
    "ISO_8859-3:1988",
    "CSISOLATINGREEK",
    "KOI8-RU",
    "ISO-10646-UCS-4",
    "CSISOLATINARABIC",
    "ISO_8859-1:1987",
    "ISO_8859-2:1987",
    "CSEUCKR",
    "ISO-IR-144",
    "JIS_C6220-1969-RO",
    "JIS_C6226-1983",
    "ISO_8859-6:1987",
    "BIGFIVE",
    "BIG-FIVE",
    "HP-ROMAN8",
    "GREEK",
    "UTF-32BE",
    "CSHPROMAN8",
    "ISO_646.IRV:1991",
    "WINDOWS-874",
    "CSISOLATIN4",
    "BIG5HKSCS",
    "ISO_8859-4:1988",
    "BIG5-HKSCS",
    "GEORGIAN-ACADEMY",
    "CSEUCPKDFMTJAPANESE",
    "UCS-4BE",
    "UCS-4-SWAPPED",
    "KS_C_5601-1989",
    "EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE",
    "KOREAN",
    "ISO_8859-7:1987",
    "MACCENTRALEUROPE",
    "TCVN5712-1:1993",
    "HEBREW",
    "MS-HEBR",
    "CSMACINTOSH",
    "ECMA-114",
    "MACCROATIAN",
    "ARABIC",
    "KS_C_5601-1987",
    "MS-TURK",
    "MACGREEK",
    "MS-GREEK",
    "WCHAR_T",
    "CSISO87JISX0208",
    "MACHEBREW",
    "WINBALTRIM",
    "MACTURKISH",
    "JISX0201-1976",
    "MACARABIC",
    "JIS_X0212",
    "MACUKRAINE",
    "JIS_X0201",
    "CSHALFWIDTHKATAKANA",
    "JIS_X0212-1990",
    "JIS_X0208",
    "JIS_X0212.1990-0",
    "JAVA",
    "ANSI_X3.4-1968",
    "MACROMANIA",
    "ANSI_X3.4-1986",
    "MS_KANJI",
    "JIS_X0208-1983",
    "JIS_X0208-1990",
    "MS-ARAB",
    "JOHAB"
  };
#define stringpool ((const char *) &stringpool_contents)

static const struct alias aliases[] =
  {
    {-1}, {-1},
#line 60 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str2), ei_iso8859_1},
    {-1},
#line 291 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str4), ei_sjis},
    {-1}, {-1},
#line 68 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str7), ei_iso8859_2},
    {-1}, {-1}, {-1}, {-1},
#line 147 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str12), ei_iso8859_14},
    {-1}, {-1}, {-1}, {-1},
#line 133 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str17), ei_iso8859_10},
    {-1}, {-1}, {-1}, {-1},
#line 125 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str22), ei_iso8859_9},
#line 196 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str23), ei_cp862},
    {-1}, {-1}, {-1},
#line 271 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str27), ei_iso646_cn},
    {-1}, {-1}, {-1},
#line 167 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str31), ei_cp1251},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 194 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str40), ei_cp862},
#line 170 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str41), ei_cp1252},
    {-1},
#line 200 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str43), ei_cp866},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 188 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str51), ei_cp1258},
    {-1},
#line 51 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str53), ei_c99},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 198 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str60), ei_cp866},
#line 182 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str61), ei_cp1256},
    {-1}, {-1}, {-1},
#line 57 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str65), ei_iso8859_1},
#line 59 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str66), ei_iso8859_1},
    {-1}, {-1}, {-1}, {-1},
#line 179 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str71), ei_cp1255},
    {-1}, {-1}, {-1}, {-1},
#line 67 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str76), ei_iso8859_2},
    {-1}, {-1},
#line 62 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str79), ei_iso8859_1},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 53 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str85), ei_iso8859_1},
#line 146 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str86), ei_iso8859_14},
    {-1}, {-1},
#line 70 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str89), ei_iso8859_2},
    {-1}, {-1},
#line 76 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str92), ei_iso8859_3},
    {-1}, {-1},
#line 63 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str95), ei_iso8859_2},
#line 132 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str96), ei_iso8859_10},
    {-1},
#line 204 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str98), ei_mac_roman},
#line 119 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str99), ei_iso8859_8},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 113 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str105), ei_iso8859_8},
#line 124 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str106), ei_iso8859_9},
    {-1},
#line 91 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str108), ei_iso8859_5},
#line 102 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str109), ei_iso8859_6},
#line 159 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str110), ei_iso8859_16},
#line 331 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str111), ei_johab},
#line 219 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str112), ei_hp_roman8},
    {-1}, {-1},
#line 94 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str115), ei_iso8859_6},
#line 155 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str116), ei_iso8859_16},
    {-1}, {-1},
#line 93 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str119), ei_iso8859_5},
#line 154 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str120), ei_iso8859_15},
    {-1}, {-1}, {-1}, {-1},
#line 87 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str125), ei_iso8859_5},
#line 150 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str126), ei_iso8859_15},
    {-1}, {-1},
#line 127 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str129), ei_iso8859_9},
#line 294 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str130), ei_cp932},
#line 302 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str131), ei_euc_cn},
#line 140 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str132), ei_iso8859_13},
    {-1}, {-1},
#line 120 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str135), ei_iso8859_9},
#line 195 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str136), ei_cp862},
    {-1}, {-1}, {-1},
#line 148 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str140), ei_iso8859_14},
    {-1}, {-1}, {-1}, {-1},
#line 301 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str145), ei_euc_cn},
    {-1}, {-1},
#line 16 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str148), ei_ascii},
    {-1},
#line 306 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str150), ei_ces_gbk},
#line 300 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str151), ei_euc_cn},
    {-1}, {-1}, {-1},
#line 106 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str155), ei_iso8859_7},
#line 199 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str156), ei_cp866},
    {-1}, {-1},
#line 274 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str159), ei_gb2312},
#line 158 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str160), ei_iso8859_16},
#line 58 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str161), ei_iso8859_1},
#line 21 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str162), ei_ascii},
#line 329 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str163), ei_cp949},
    {-1},
#line 235 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str165), ei_tis620},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 277 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str175), ei_isoir165},
#line 309 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str176), ei_iso2022_cn},
    {-1}, {-1}, {-1},
#line 24 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str180), ei_ucs2},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 308 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str186), ei_iso2022_cn},
    {-1}, {-1}, {-1},
#line 266 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str190), ei_jisx0212},
    {-1}, {-1}, {-1}, {-1},
#line 145 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str195), ei_iso8859_14},
    {-1}, {-1}, {-1}, {-1},
#line 310 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str200), ei_iso2022_cn_ext},
    {-1},
#line 311 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str202), ei_hz},
    {-1}, {-1}, {-1},
#line 210 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str206), ei_mac_cyrillic},
#line 169 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str207), ei_cp1251},
    {-1}, {-1}, {-1},
#line 173 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str211), ei_cp1253},
#line 84 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str212), ei_iso8859_4},
#line 192 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str213), ei_cp850},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 66 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str220), ei_iso8859_2},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 116 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str230), ei_iso8859_8},
#line 164 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str231), ei_cp1250},
    {-1},
#line 232 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str233), ei_tis620},
    {-1},
#line 190 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str235), ei_cp850},
#line 238 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str236), ei_viscii},
    {-1},
#line 240 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str238), ei_viscii},
    {-1},
#line 23 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str240), ei_utf8},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 75 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str246), ei_iso8859_3},
    {-1}, {-1}, {-1},
#line 322 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str250), ei_cp950},
#line 38 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str251), ei_utf16},
    {-1}, {-1}, {-1}, {-1},
#line 239 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str256), ei_viscii},
    {-1}, {-1},
#line 78 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str259), ei_iso8859_3},
#line 141 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str260), ei_iso8859_13},
#line 230 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str261), ei_tis620},
    {-1}, {-1}, {-1},
#line 71 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str265), ei_iso8859_3},
#line 136 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str266), ei_iso8859_13},
#line 229 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str267), ei_tis620},
    {-1}, {-1},
#line 74 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str270), ei_iso8859_3},
    {-1}, {-1}, {-1}, {-1},
#line 54 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str275), ei_iso8859_1},
#line 227 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str276), ei_cp1133},
#line 168 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str277), ei_cp1251},
    {-1}, {-1},
#line 135 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str280), ei_iso8859_10},
#line 29 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str281), ei_ucs2be},
#line 171 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str282), ei_cp1252},
    {-1}, {-1},
#line 64 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str285), ei_iso8859_2},
#line 128 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str286), ei_iso8859_10},
#line 189 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str287), ei_cp1258},
    {-1}, {-1},
#line 328 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str290), ei_cp949},
#line 185 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str291), ei_cp1257},
#line 183 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str292), ei_cp1256},
    {-1}, {-1},
#line 114 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str295), ei_iso8859_8},
#line 30 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str296), ei_ucs2be},
#line 180 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str297), ei_cp1255},
    {-1}, {-1},
#line 138 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str300), ei_iso8859_13},
    {-1},
#line 276 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str302), ei_gb2312},
    {-1},
#line 269 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str304), ei_iso646_cn},
#line 95 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str305), ei_iso8859_6},
#line 156 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str306), ei_iso8859_16},
    {-1}, {-1}, {-1}, {-1},
#line 152 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str311), ei_iso8859_15},
    {-1}, {-1}, {-1},
#line 88 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str315), ei_iso8859_5},
#line 151 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str316), ei_iso8859_15},
    {-1}, {-1},
#line 241 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str319), ei_tcvn},
#line 82 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str320), ei_iso8859_4},
#line 41 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str321), ei_utf32},
    {-1}, {-1}, {-1},
#line 121 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str325), ei_iso8859_9},
#line 139 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str326), ei_iso8859_13},
    {-1}, {-1}, {-1},
#line 314 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str330), ei_euc_tw},
#line 191 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str331), ei_cp850},
    {-1}, {-1}, {-1},
#line 13 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str335), ei_ascii},
#line 313 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str336), ei_euc_tw},
#line 22 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str337), ei_ascii},
    {-1},
#line 112 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str339), ei_iso8859_7},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 103 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str345), ei_iso8859_7},
    {-1}, {-1}, {-1}, {-1},
#line 123 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str350), ei_iso8859_9},
    {-1}, {-1}, {-1},
#line 316 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str354), ei_ces_big5},
    {-1},
#line 321 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str356), ei_ces_big5},
#line 31 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str357), ei_ucs2le},
    {-1}, {-1},
#line 317 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str360), ei_ces_big5},
    {-1},
#line 320 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str362), ei_ces_big5},
    {-1}, {-1}, {-1}, {-1},
#line 174 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str367), ei_cp1253},
#line 231 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str368), ei_tis620},
    {-1},
#line 19 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str370), ei_ascii},
    {-1}, {-1}, {-1}, {-1},
#line 166 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str375), ei_cp1250},
    {-1},
#line 165 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str377), ei_cp1250},
#line 108 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str378), ei_iso8859_7},
    {-1},
#line 282 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str380), ei_ksc5601},
#line 225 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str381), ei_koi8_t},
    {-1},
#line 234 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str383), ei_tis620},
#line 26 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str384), ei_ucs2},
#line 97 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str385), ei_iso8859_6},
#line 130 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str386), ei_iso8859_10},
    {-1}, {-1},
#line 259 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str389), ei_jisx0208},
#line 228 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str390), ei_cp1133},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 157 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str396), ei_iso8859_16},
    {-1}, {-1},
#line 270 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str399), ei_iso646_cn},
#line 131 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str400), ei_iso8859_10},
#line 61 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str401), ei_iso8859_1},
    {-1}, {-1}, {-1},
#line 153 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str405), ei_iso8859_15},
    {-1},
#line 186 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str407), ei_cp1257},
#line 92 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str408), ei_iso8859_5},
    {-1}, {-1},
#line 69 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str411), ei_iso8859_2},
    {-1}, {-1},
#line 14 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str414), ei_ascii},
    {-1}, {-1},
#line 45 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str417), ei_utf7},
#line 40 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str418), ei_utf16le},
    {-1},
#line 56 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str420), ei_iso8859_1},
    {-1},
#line 248 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str422), ei_iso646_jp},
#line 304 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str423), ei_euc_cn},
    {-1}, {-1}, {-1},
#line 307 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str427), ei_gb18030},
    {-1}, {-1},
#line 46 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str430), ei_utf7},
#line 134 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str431), ei_iso8859_10},
    {-1},
#line 32 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str433), ei_ucs2le},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 47 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str439), ei_ucs2internal},
    {-1},
#line 126 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str441), ei_iso8859_9},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 201 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str448), ei_cp866},
#line 193 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str449), ei_cp850},
    {-1},
#line 176 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str451), ei_cp1254},
    {-1}, {-1},
#line 278 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str454), ei_isoir165},
#line 72 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str455), ei_iso8859_3},
#line 137 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str456), ei_iso8859_13},
    {-1}, {-1},
#line 222 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str459), ei_armscii_8},
#line 243 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str460), ei_tcvn},
    {-1},
#line 172 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str462), ei_cp1252},
    {-1},
#line 242 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str464), ei_tcvn},
    {-1},
#line 20 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str466), ei_ascii},
    {-1}, {-1}, {-1},
#line 265 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str470), ei_jisx0212},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 129 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str476), ei_iso8859_10},
    {-1}, {-1}, {-1},
#line 44 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str480), ei_utf7},
    {-1}, {-1},
#line 233 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str483), ei_tis620},
    {-1},
#line 268 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str485), ei_iso646_cn},
#line 83 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str486), ei_iso8859_4},
#line 177 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str487), ei_cp1254},
    {-1}, {-1}, {-1}, {-1},
#line 315 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str492), ei_euc_tw},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 43 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str498), ei_utf32le},
#line 86 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str499), ei_iso8859_4},
#line 149 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str500), ei_iso8859_14},
#line 144 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str501), ei_iso8859_14},
    {-1},
#line 12 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str503), ei_ascii},
    {-1},
#line 79 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str505), ei_iso8859_4},
#line 142 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str506), ei_iso8859_14},
#line 161 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str507), ei_koi8_r},
#line 272 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str508), ei_iso646_cn},
#line 290 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str509), ei_sjis},
    {-1},
#line 160 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str511), ei_koi8_r},
    {-1}, {-1}, {-1}, {-1},
#line 109 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str516), ei_iso8859_7},
    {-1}, {-1}, {-1}, {-1},
#line 224 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str521), ei_georgian_ps},
    {-1},
#line 197 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str523), ei_cp862},
    {-1},
#line 286 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str525), ei_euc_jp},
    {-1}, {-1}, {-1},
#line 226 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str529), ei_mulelao},
#line 25 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str530), ei_ucs2},
#line 285 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str531), ei_euc_jp},
    {-1}, {-1},
#line 334 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str534), ei_local_char},
#line 104 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str535), ei_iso8859_7},
    {-1}, {-1}, {-1},
#line 247 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str539), ei_iso646_jp},
#line 273 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str540), ei_gb2312},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 107 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str548), ei_iso8859_7},
    {-1},
#line 275 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str550), ei_gb2312},
    {-1},
#line 299 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str552), ei_iso2022_jp2},
    {-1}, {-1}, {-1},
#line 296 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str556), ei_iso2022_jp},
    {-1},
#line 297 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str558), ei_iso2022_jp1},
    {-1},
#line 252 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str560), ei_jisx0201},
    {-1},
#line 37 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str562), ei_ucs4le},
#line 298 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str563), ei_iso2022_jp2},
#line 203 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str564), ei_mac_roman},
#line 236 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str565), ei_cp874},
#line 295 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str566), ei_iso2022_jp},
    {-1}, {-1}, {-1},
#line 207 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str570), ei_mac_iceland},
    {-1}, {-1}, {-1}, {-1},
#line 267 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str575), ei_jisx0212},
#line 218 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str576), ei_hp_roman8},
    {-1}, {-1}, {-1},
#line 258 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str580), ei_jisx0208},
#line 77 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str581), ei_iso8859_3},
    {-1}, {-1}, {-1},
#line 326 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str585), ei_euc_kr},
#line 35 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str586), ei_ucs4},
    {-1}, {-1}, {-1},
#line 33 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str590), ei_ucs4},
#line 325 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str591), ei_euc_kr},
    {-1},
#line 283 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str593), ei_ksc5601},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 28 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str600), ei_ucs2be},
    {-1}, {-1},
#line 305 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str603), ei_ces_gbk},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 303 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str610), ei_euc_cn},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 333 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str616), ei_iso2022_kr},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 332 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str626), ei_iso2022_kr},
    {-1},
#line 279 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str628), ei_ksc5601},
    {-1},
#line 115 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str630), ei_iso8859_8},
#line 162 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str631), ei_koi8_u},
    {-1}, {-1}, {-1},
#line 312 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str635), ei_hz},
    {-1},
#line 249 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str637), ei_iso646_jp},
    {-1}, {-1},
#line 89 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str640), ei_iso8859_5},
    {-1},
#line 257 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str642), ei_jisx0208},
    {-1},
#line 49 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str644), ei_ucs4internal},
    {-1}, {-1},
#line 27 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str647), ei_ucs2be},
#line 48 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str648), ei_ucs2swapped},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1},
#line 122 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str660), ei_iso8859_9},
    {-1}, {-1},
#line 221 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str663), ei_nextstep},
    {-1}, {-1}, {-1},
#line 216 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str667), ei_mac_thai},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 202 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str678), ei_mac_roman},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 246 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str684), ei_iso646_jp},
    {-1}, {-1}, {-1},
#line 99 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str688), ei_iso8859_6},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 80 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str695), ei_iso8859_4},
#line 143 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str696), ei_iso8859_14},
    {-1}, {-1},
#line 289 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str699), ei_sjis},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 293 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str705), ei_sjis},
#line 118 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str706), ei_iso8859_8},
    {-1},
#line 39 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str708), ei_utf16be},
    {-1},
#line 73 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str710), ei_iso8859_3},
    {-1}, {-1}, {-1}, {-1},
#line 111 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str715), ei_iso8859_7},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 163 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str732), ei_koi8_ru},
    {-1}, {-1},
#line 34 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str735), ei_ucs4},
#line 101 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str736), ei_iso8859_6},
    {-1}, {-1}, {-1},
#line 55 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str740), ei_iso8859_1},
    {-1}, {-1}, {-1}, {-1},
#line 65 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str745), ei_iso8859_2},
    {-1},
#line 327 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str747), ei_euc_kr},
    {-1}, {-1},
#line 90 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str750), ei_iso8859_5},
    {-1},
#line 245 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str752), ei_iso646_jp},
    {-1},
#line 260 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str754), ei_jisx0208},
#line 96 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str755), ei_iso8859_6},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 319 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str777), ei_ces_big5},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 318 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str783), ei_ces_big5},
#line 217 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str784), ei_hp_roman8},
#line 110 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str785), ei_iso8859_7},
    {-1}, {-1},
#line 42 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str788), ei_utf32be},
    {-1},
#line 220 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str790), ei_hp_roman8},
#line 15 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str791), ei_ascii},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 237 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str811), ei_cp874},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 85 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str821), ei_iso8859_4},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 324 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str829), ei_big5hkscs},
#line 81 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str830), ei_iso8859_4},
    {-1}, {-1}, {-1}, {-1},
#line 323 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str835), ei_big5hkscs},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 223 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str846), ei_georgian_academy},
    {-1}, {-1},
#line 288 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str849), ei_euc_jp},
    {-1}, {-1},
#line 36 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str852), ei_ucs4be},
#line 50 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str853), ei_ucs4swapped},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 281 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str859), ei_ksc5601},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 287 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str865), ei_euc_jp},
#line 284 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str866), ei_ksc5601},
    {-1}, {-1}, {-1},
#line 105 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str870), ei_iso8859_7},
#line 206 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str871), ei_mac_centraleurope},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1},
#line 244 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str885), ei_tcvn},
#line 117 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str886), ei_iso8859_8},
#line 181 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str887), ei_cp1255},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 205 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str896), ei_mac_roman},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 98 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str948), ei_iso8859_6},
    {-1}, {-1},
#line 208 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str951), ei_mac_croatian},
    {-1}, {-1}, {-1}, {-1},
#line 100 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str956), ei_iso8859_6},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 280 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str964), ei_ksc5601},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 178 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str982), ei_cp1254},
#line 212 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str983), ei_mac_greek},
    {-1}, {-1}, {-1}, {-1},
#line 175 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str988), ei_cp1253},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1},
#line 335 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1002), ei_local_wchar_t},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1},
#line 261 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1025), ei_jisx0208},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 214 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1074), ei_mac_hebrew},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 187 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1080), ei_cp1257},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 213 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1090), ei_mac_turkish},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 251 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1123), ei_jisx0201},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 215 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1154), ei_mac_arabic},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 262 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1179), ei_jisx0212},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 211 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1190), ei_mac_ukraine},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 250 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1269), ei_jisx0201},
    {-1}, {-1}, {-1}, {-1},
#line 253 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1274), ei_jisx0201},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 264 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1284), ei_jisx0212},
    {-1}, {-1}, {-1}, {-1},
#line 254 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1289), ei_jisx0208},
    {-1},
#line 263 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1291), ei_jisx0212},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 52 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1304), ei_java},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 17 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1314), ei_ascii},
#line 209 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1315), ei_mac_romania},
    {-1}, {-1}, {-1},
#line 18 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1319), ei_ascii},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 292 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1353), ei_sjis},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 255 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1379), ei_jisx0208},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 256 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1389), ei_jisx0208},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 184 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1447), ei_cp1256},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 330 "aliases.gperf"
    {offsetof(struct stringpool_t, stringpool_str1525), ei_johab}
  };

const struct alias *
aliases_lookup (register const char *str, register unsigned int len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = aliases_hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register int o = aliases[key].name;
          if (o >= 0)
            {
              register const char *s = o + stringpool;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &aliases[key];
            }
        }
    }
  return 0;
}
