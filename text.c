#include "oslib.h"
#include "intraFont/intraFont.h"

unsigned int intra_options = 0;

OSL_FONT *osl_curFont=NULL;
OSL_FONT *osl_sceFont=NULL;
int osl_consolePosX=0, osl_consolePosY=0; //, osl_consoleOk=0;
OSL_COLOR osl_textBkColor = 0xff000000, osl_textColor = 0xffffffff;

const unsigned char osl_sceFont_data[]=		{
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x3c, 0x42, 0xa5, 0x81, 0xa5, 0x99, 0x42, 0x3c,
	0x3c, 0x7e, 0xdb, 0xff, 0xff, 0xdb, 0x66, 0x3c,
	0x36, 0x7f, 0x7f, 0x7f, 0x3e, 0x1c, 0x8, 0x0,
	0x8, 0x1c, 0x3e, 0x7f, 0x3e, 0x1c, 0x8, 0x0,
	0x8, 0x1c, 0x2a, 0x7f, 0x2a, 0x8, 0x1c, 0x0,
	0x8, 0x1c, 0x3e, 0x7f, 0x7f, 0x8, 0x1c, 0x0,
	0x0, 0x0, 0x0, 0xc, 0xc, 0x0, 0x0, 0x0,
	0xff, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xff,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0xf0, 0xc0, 0xa0, 0x9e, 0x11, 0x11, 0x11, 0xe,
	0x1c, 0x22, 0x22, 0x22, 0x1c, 0x8, 0x3e, 0x8,
	0xc, 0x14, 0x24, 0x24, 0x14, 0x4, 0x7, 0x3,
	0x3c, 0x24, 0x3c, 0x24, 0x24, 0x27, 0x3b, 0x18,
	0x8, 0x2a, 0x1c, 0x77, 0x1c, 0x2a, 0x8, 0x0,
	0x8, 0x8, 0x8, 0x3e, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0xff, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0xff, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0xf, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0xf8, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0xff, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
	0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0xf8, 0x8, 0x8, 0x8, 0x8,
	0x0, 0x0, 0x0, 0xf, 0x8, 0x8, 0x8, 0x8,
	0x8, 0x8, 0x8, 0xf8, 0x0, 0x0, 0x0, 0x0,
	0x8, 0x8, 0x8, 0xf, 0x0, 0x0, 0x0, 0x0,
	0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81,
	0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
	0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
	0x0, 0x8, 0x8, 0xff, 0x8, 0x8, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x4, 0x0,
	0xa, 0xa, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0,
	0xa, 0xa, 0x1f, 0xa, 0x1f, 0xa, 0xa, 0x0,
	0x4, 0x1e, 0x5, 0xe, 0x14, 0xf, 0x4, 0x0,
	0x3, 0x13, 0x8, 0x4, 0x2, 0x19, 0x18, 0x0,
	0x2, 0x5, 0x2, 0x15, 0x9, 0x19, 0x6, 0x0,
	0x8, 0x4, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x8, 0x4, 0x2, 0x2, 0x2, 0x4, 0x8, 0x0,
	0x2, 0x4, 0x8, 0x8, 0x8, 0x4, 0x2, 0x0,
	0x4, 0x15, 0xe, 0x4, 0xe, 0x15, 0x4, 0x0,
	0x0, 0x4, 0x4, 0x1f, 0x4, 0x4, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x2,
	0x0, 0x0, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x6, 0x0,
	0x0, 0x0, 0x10, 0x8, 0x4, 0x2, 0x1, 0x0,
	0xe, 0x11, 0x19, 0x15, 0x13, 0x11, 0xe, 0x0,
	0x4, 0x6, 0x5, 0x4, 0x4, 0x4, 0x1f, 0x0,
	0xe, 0x11, 0x10, 0x8, 0x6, 0x1, 0x1f, 0x0,
	0xe, 0x11, 0x10, 0xc, 0x10, 0x11, 0xe, 0x0,
	0x8, 0xc, 0xa, 0x9, 0x1f, 0x8, 0x8, 0x0,
	0x1f, 0x1, 0x7, 0x8, 0x10, 0x8, 0x7, 0x0,
	0xc, 0x2, 0x1, 0xf, 0x11, 0x11, 0xe, 0x0,
	0x1f, 0x11, 0x8, 0x4, 0x4, 0x4, 0x4, 0x0,
	0xe, 0x11, 0x11, 0xe, 0x11, 0x11, 0xe, 0x0,
	0xe, 0x11, 0x11, 0x1e, 0x10, 0x8, 0x6, 0x0,
	0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x0, 0x0,
	0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x4, 0x2,
	0x18, 0xc, 0x6, 0x3, 0x6, 0xc, 0x18, 0x0,
	0x0, 0x0, 0x1f, 0x0, 0x1f, 0x0, 0x0, 0x0,
	0x3, 0x6, 0xc, 0x18, 0xc, 0x6, 0x3, 0x0,
	0xe, 0x11, 0x10, 0x8, 0x4, 0x0, 0x4, 0x0,
	0xe, 0x11, 0x10, 0x16, 0x15, 0x15, 0xe, 0x0,
	0x4, 0xa, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x0,
	0xf, 0x12, 0x12, 0xe, 0x12, 0x12, 0xf, 0x0,
	0xc, 0x12, 0x1, 0x1, 0x1, 0x12, 0xc, 0x0,
	0x7, 0xa, 0x12, 0x12, 0x12, 0xa, 0x7, 0x0,
	0x1f, 0x1, 0x1, 0xf, 0x1, 0x1, 0x1f, 0x0,
	0x1f, 0x1, 0x1, 0xf, 0x1, 0x1, 0x1, 0x0,
	0xe, 0x11, 0x1, 0x1d, 0x11, 0x11, 0xe, 0x0,
	0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11, 0x0,
	0xe, 0x4, 0x4, 0x4, 0x4, 0x4, 0xe, 0x0,
	0x1c, 0x8, 0x8, 0x8, 0x9, 0x9, 0x6, 0x0,
	0x11, 0x9, 0x5, 0x3, 0x5, 0x9, 0x11, 0x0,
	0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1f, 0x0,
	0x11, 0x1b, 0x15, 0x15, 0x11, 0x11, 0x11, 0x0,
	0x11, 0x13, 0x13, 0x15, 0x19, 0x19, 0x11, 0x0,
	0xe, 0x11, 0x11, 0x11, 0x11, 0x11, 0xe, 0x0,
	0xf, 0x11, 0x11, 0xf, 0x1, 0x1, 0x1, 0x0,
	0xe, 0x11, 0x11, 0x11, 0x15, 0x9, 0x16, 0x0,
	0xf, 0x11, 0x11, 0xf, 0x5, 0x9, 0x11, 0x0,
	0xe, 0x11, 0x1, 0xe, 0x10, 0x11, 0xe, 0x0,
	0x1f, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0,
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xe, 0x0,
	0x11, 0x11, 0x11, 0x11, 0xa, 0xa, 0x4, 0x0,
	0x11, 0x11, 0x11, 0x15, 0x15, 0x1b, 0x11, 0x0,
	0x11, 0x11, 0xa, 0x4, 0xa, 0x11, 0x11, 0x0,
	0x11, 0x11, 0x11, 0xe, 0x4, 0x4, 0x4, 0x0,
	0x1f, 0x10, 0x8, 0x4, 0x2, 0x1, 0x1f, 0x0,
	0xe, 0x2, 0x2, 0x2, 0x2, 0x2, 0xe, 0x0,
	0x0, 0x0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x0,
	0xe, 0x8, 0x8, 0x8, 0x8, 0x8, 0xe, 0x0,
	0x4, 0xa, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x0,
	0x2, 0x4, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x1, 0x1, 0xd, 0x13, 0x11, 0x13, 0xd, 0x0,
	0x0, 0x0, 0xe, 0x11, 0x1, 0x11, 0xe, 0x0,
	0x10, 0x10, 0x16, 0x19, 0x11, 0x19, 0x16, 0x0,
	0x0, 0x0, 0xe, 0x11, 0x1f, 0x1, 0xe, 0x0,
	0x8, 0x14, 0x4, 0x1f, 0x4, 0x4, 0x4, 0x0,
	0x0, 0x0, 0x16, 0x19, 0x19, 0x16, 0x10, 0xe,
	0x1, 0x1, 0xf, 0x11, 0x11, 0x11, 0x11, 0x0,
	0x4, 0x0, 0x6, 0x4, 0x4, 0x4, 0xe, 0x0,
	0x8, 0x0, 0xc, 0x8, 0x8, 0x8, 0x9, 0x6,
	0x2, 0x2, 0x12, 0xa, 0x6, 0xa, 0x12, 0x0,
	0x6, 0x4, 0x4, 0x4, 0x4, 0x4, 0xe, 0x0,
	0x0, 0x0, 0xb, 0x15, 0x15, 0x15, 0x15, 0x0,
	0x0, 0x0, 0xd, 0x13, 0x11, 0x11, 0x11, 0x0,
	0x0, 0x0, 0xe, 0x11, 0x11, 0x11, 0xe, 0x0,
	0x0, 0x0, 0xd, 0x13, 0x13, 0xd, 0x1, 0x1,
	0x0, 0x0, 0x16, 0x19, 0x19, 0x16, 0x10, 0x10,
	0x0, 0x0, 0xd, 0x13, 0x1, 0x1, 0x1, 0x0,
	0x0, 0x0, 0x1e, 0x1, 0xf, 0x10, 0xf, 0x0,
	0x2, 0x2, 0xf, 0x2, 0x2, 0x12, 0xc, 0x0,
	0x0, 0x0, 0x9, 0x9, 0x9, 0x9, 0x16, 0x0,
	0x0, 0x0, 0x11, 0x11, 0x11, 0xa, 0x4, 0x0,
	0x0, 0x0, 0x11, 0x15, 0x15, 0x15, 0xa, 0x0,
	0x0, 0x0, 0x11, 0xa, 0x4, 0xa, 0x11, 0x0,
	0x0, 0x0, 0x11, 0x11, 0x19, 0x16, 0x10, 0xe,
	0x0, 0x0, 0x1f, 0x8, 0x4, 0x2, 0x1f, 0x0,
	0x18, 0x4, 0x4, 0x2, 0x4, 0x4, 0x18, 0x0,
	0x4, 0x4, 0x4, 0x0, 0x4, 0x4, 0x4, 0x0,
	0x3, 0x4, 0x4, 0x8, 0x4, 0x4, 0x3, 0x0,
	0x2, 0x15, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x4, 0xa, 0x1f, 0x0, 0x0, 0x0,
	0xe, 0x11, 0x1, 0x1, 0x11, 0xe, 0x4, 0x6,
	0x9, 0x0, 0x0, 0x9, 0x9, 0x9, 0x16, 0x0,
	0x8, 0x4, 0xe, 0x11, 0x1f, 0x1, 0xe, 0x0,
	0x4, 0xa, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x12, 0x0, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x4, 0x8, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x4, 0x0, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x0, 0xe, 0x1, 0x1, 0x1, 0xe, 0x8, 0x6,
	0x4, 0xa, 0xe, 0x11, 0x1f, 0x1, 0xe, 0x0,
	0xa, 0x0, 0xe, 0x11, 0x1f, 0x1, 0xe, 0x0,
	0x4, 0x8, 0xe, 0x11, 0x1f, 0x1, 0xe, 0x0,
	0xa, 0x0, 0x0, 0x6, 0x4, 0x4, 0xe, 0x0,
	0x4, 0xa, 0x0, 0x6, 0x4, 0x4, 0xe, 0x0,
	0x2, 0x4, 0x0, 0x6, 0x4, 0x4, 0xe, 0x0,
	0xa, 0x0, 0x4, 0xa, 0x11, 0x1f, 0x11, 0x0,
	0x4, 0x0, 0x4, 0xa, 0x11, 0x1f, 0x11, 0x0,
	0x8, 0x4, 0x1f, 0x1, 0xf, 0x1, 0x1f, 0x0,
	0x0, 0x0, 0x36, 0x48, 0x7e, 0x9, 0x76, 0x0,
	0x7c, 0xa, 0x9, 0x39, 0xf, 0x9, 0x79, 0x0,
	0x6, 0x9, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0,
	0x9, 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0,
	0x2, 0x4, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0,
	0x2, 0x5, 0x0, 0x5, 0x5, 0x5, 0xa, 0x0,
	0x2, 0x4, 0x0, 0x5, 0x5, 0x5, 0xa, 0x0,
	0x9, 0x0, 0x9, 0x9, 0xd, 0xa, 0x8, 0x7,
	0xa, 0x0, 0xe, 0x11, 0x11, 0x11, 0xe, 0x0,
	0xa, 0x0, 0x11, 0x11, 0x11, 0x11, 0xe, 0x0,
	0x4, 0x4, 0x1e, 0x1, 0x1, 0x1e, 0x4, 0x4,
	0x18, 0x24, 0x4, 0x1f, 0x4, 0x47, 0x3a, 0x0,
	0x11, 0xa, 0x4, 0x1f, 0x4, 0x1f, 0x4, 0x0,
	0x3, 0x5, 0x5, 0x13, 0x39, 0x11, 0x11, 0x31,
	0x18, 0x4, 0x4, 0x1f, 0x4, 0x4, 0x4, 0x2,
	0x8, 0x4, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x8, 0x4, 0x0, 0x6, 0x4, 0x4, 0xe, 0x0,
	0x4, 0x2, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0,
	0x4, 0x2, 0x0, 0x9, 0x9, 0x9, 0x16, 0x0,
	0xa, 0x5, 0x0, 0x5, 0xb, 0x9, 0x9, 0x0,
	0x14, 0xa, 0x0, 0x13, 0x15, 0x19, 0x11, 0x0,
	0x0, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0, 0x1f,
	0x0, 0x6, 0x9, 0x9, 0x9, 0x6, 0x0, 0xf,
	0x4, 0x0, 0x4, 0x2, 0x1, 0x11, 0xe, 0x0,
	0x0, 0x0, 0x0, 0x1f, 0x1, 0x1, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x1f, 0x10, 0x10, 0x0, 0x0,
	0x21, 0x11, 0x9, 0x15, 0x2a, 0x21, 0x10, 0x38,
	0x21, 0x11, 0x9, 0x15, 0x1a, 0x15, 0x3c, 0x10,
	0x4, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x0,
	0x0, 0x0, 0x24, 0x12, 0x9, 0x12, 0x24, 0x0,
	0x0, 0x0, 0x9, 0x12, 0x24, 0x12, 0x9, 0x0,
	0x14, 0xa, 0x4, 0xa, 0x11, 0x1f, 0x11, 0x0,
	0x14, 0xa, 0xe, 0x10, 0x1e, 0x11, 0x1e, 0x0,
	0x14, 0xa, 0x0, 0xe, 0x4, 0x4, 0xe, 0x0,
	0x14, 0xa, 0x0, 0x4, 0x4, 0x4, 0xe, 0x0,
	0x14, 0xa, 0x0, 0xe, 0x11, 0x11, 0xe, 0x0,
	0xa, 0x5, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0,
	0x14, 0xa, 0x0, 0x11, 0x11, 0x11, 0xe, 0x0,
	0xa, 0x5, 0x0, 0x5, 0x5, 0x5, 0xa, 0x0,
	0x3f, 0x12, 0x12, 0x12, 0x17, 0x10, 0xa, 0x4,
	0x0, 0xa, 0x0, 0xa, 0xa, 0xa, 0x8, 0x4,
	0x3, 0x22, 0x13, 0x2a, 0x37, 0x2a, 0x79, 0x20,
	0x8, 0x15, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x4, 0xa, 0x11, 0xa, 0x4, 0x0, 0x0,
	0x11, 0x8, 0x4, 0x2, 0x1, 0x14, 0x0, 0x0,
	0x3e, 0x15, 0x15, 0x16, 0x14, 0x14, 0x14, 0x0,
	0x1c, 0x2, 0xc, 0x12, 0x12, 0xc, 0x10, 0xe,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
	0xf, 0xf, 0xf, 0xf, 0xf0, 0xf0, 0xf0, 0xf0,
	0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x3c, 0x3c, 0x0, 0x0, 0x0,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0,
	0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf, 0xf, 0xf, 0xf,
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
	0x88, 0x44, 0x22, 0x11, 0x88, 0x44, 0x22, 0x11,
	0x11, 0x22, 0x44, 0x88, 0x11, 0x22, 0x44, 0x88,
	0x7f, 0x3e, 0x1c, 0x8, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x8, 0x1c, 0x3e, 0x7f,
	0x1, 0x3, 0x7, 0xf, 0x7, 0x3, 0x1, 0x0,
	0x80, 0xc0, 0xe0, 0xf0, 0xe0, 0xc0, 0x80, 0x0,
	0xff, 0x7e, 0x3c, 0x18, 0x18, 0x3c, 0x7e, 0xff,
	0x81, 0xc3, 0xe7, 0xff, 0xff, 0xe7, 0xc3, 0x81,
	0xf, 0xf, 0xf, 0xf, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xf0, 0xf0, 0xf0, 0xf0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0xf, 0xf, 0xf, 0xf,
	0xcc, 0xcc, 0x33, 0x33, 0xcc, 0xcc, 0x33, 0x33,
	0x0, 0x4, 0x4, 0xa, 0xa, 0x11, 0x1f, 0x0,
	0x4, 0x4, 0xe, 0x4, 0xe, 0x4, 0x4, 0x0,
	0x0, 0x0, 0x0, 0xa, 0x11, 0x15, 0xa, 0x0,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
	0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x16, 0x9, 0x9, 0x9, 0x16, 0x0,
	0xc, 0x12, 0x12, 0xe, 0x12, 0x12, 0xe, 0x3,
	0x1f, 0x11, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0,
	0x1f, 0xa, 0xa, 0xa, 0xa, 0xa, 0x19, 0x0,
	0x1f, 0x11, 0x2, 0x4, 0x2, 0x11, 0x1f, 0x0,
	0x0, 0x0, 0x1e, 0x9, 0x9, 0x9, 0x6, 0x0,
	0x0, 0xa, 0xa, 0xa, 0xa, 0x16, 0x1, 0x1,
	0x0, 0xa, 0x5, 0x4, 0x4, 0x4, 0x4, 0x0,
	0x1f, 0x4, 0xe, 0x15, 0x15, 0xe, 0x4, 0x1f,
	0x4, 0xa, 0x11, 0x1f, 0x11, 0xa, 0x4, 0x0,
	0xe, 0x11, 0x11, 0x11, 0xa, 0xa, 0x1b, 0x0,
	0xc, 0x2, 0x2, 0x4, 0xa, 0xa, 0xa, 0x4,
	0x0, 0x0, 0x0, 0xa, 0x15, 0x15, 0xa, 0x0,
	0x10, 0xe, 0x15, 0x15, 0x15, 0xe, 0x1, 0x0,
	0x1c, 0x2, 0x1, 0x1f, 0x1, 0x2, 0x1c, 0x0,
	0xe, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0,
	0x0, 0x1f, 0x0, 0x1f, 0x0, 0x1f, 0x0, 0x0,
	0x4, 0x4, 0x1f, 0x4, 0x4, 0x0, 0x1f, 0x0,
	0x3, 0xc, 0x10, 0xc, 0x3, 0x0, 0x1f, 0x0,
	0x18, 0x6, 0x1, 0x6, 0x18, 0x0, 0x1f, 0x0,
	0x8, 0x14, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4,
	0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x5, 0x2,
	0x0, 0x4, 0x0, 0x1f, 0x0, 0x4, 0x0, 0x0,
	0x0, 0xa, 0x5, 0x0, 0xa, 0x5, 0x0, 0x0,
	0x0, 0x18, 0x24, 0x24, 0x18, 0x0, 0x0, 0x0,
	0x0, 0xc, 0x1e, 0x1e, 0xc, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0xc, 0x0, 0x0, 0x0,
	0x7c, 0x4, 0x4, 0x4, 0x5, 0x6, 0x4, 0x0,
	0x5, 0xa, 0xa, 0xa, 0x0, 0x0, 0x0, 0x0,
	0x2, 0x5, 0x4, 0x2, 0x7, 0x0, 0x0, 0x0,
	0x0, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};

OSL_FONTINFO osl_sceFontInfo=		{
	(void*)osl_sceFont_data,				// Fonte Sony Computer Entertainment
	1,										// 1 bit par pixel
	NULL,									// Proportionnelle
	7, 8, 1,								// 7x8 (1 octet par ligne)
};

//bitplanes: format (bits par pixel) de la fonte, imagePlanes: format de la texture à remplir (puissance de deux)
void oslDrawChar1BitToImage(OSL_IMAGE *img, int x0, int y0, int w, int h, int width, int bitPlanes, int imagePlanes, const unsigned char *font)
{
	unsigned char v, t, *data;
	int x,xx,y;
	//Nombre de pixels par octet en fonction du format (seuls 1, 2, 4 et 8 supportés)
	const u8 pixelsPerByte[] = {0, 8, 4, 0, 2, 0, 0, 0, 1};

	for (y=0;y<h;y++)
	{
		data = (u8*)oslGetImagePixelAdr(img, x0, y+y0);
		for (xx=0;xx<width;)			{
			v = *font++;
			for (x=0;x<8;x+=bitPlanes)
			{
				if (xx < w)			{
					int offset = (xx + x0) & (pixelsPerByte[imagePlanes] - 1);
					t = v & ((1 << bitPlanes) - 1);
					if (t)
						*data |= t << (offset * imagePlanes);
					//Dernier pixel pour cet octet
					if (offset == pixelsPerByte[imagePlanes] - 1)
						data++;
				}
				v >>= bitPlanes;
				xx++;
			}
		}
	}
}

OSL_FONT *oslLoadFont(OSL_FONTINFO *fi)
{
	OSL_FONT *f;
	int i, x, y;
	int imageFormat;
	const int pixelplanewidth[4]={3, 2, 2, 1};

	f = (OSL_FONT*)malloc(sizeof(OSL_FONT));
	if (!f)
		return NULL;

    f->fontType = OSL_FONT_OFT;

	//Liste des tailles
	f->charWidths = (u8*)malloc(256*sizeof(char));
	if (!f->charWidths)		{
		free(f);
		return NULL;
	}
	if (fi->charWidths)		{
		//Réutilise les tailles fournies
		for (i=0;i<256;i++)
			f->charWidths[i] = fi->charWidths[i];
//		f->charWidths = fi->charWidths;
		f->isCharWidthConstant = 0;
	}
	else		{
		//Remplit la table avec les mêmes tailles
		for (i=0;i<256;i++)
			f->charWidths[i] = fi->charWidth;
		f->isCharWidthConstant = 1;
	}
	//Position des caractères (pour les fontes non proportionnelles)
	f->charPositions = (u16*)malloc(256*sizeof(short));
	if (!f->charPositions)		{
		free(f->charWidths);
		free(f);
		return NULL;
	}
	f->addedSpace = fi->addedSpace;
	x = y = 0;
	for (i=0;i<256;i++)
	{
		if (x + f->charWidths[i] + f->addedSpace >= OSL_TEXT_TEXWIDTH)			{
			//Prochaine ligne
			x = 0;
			y ++;
		}
		f->charPositions[i] = x + (y<<OSL_TEXT_TEXDECAL);
		x += f->charWidths[i] + f->addedSpace;
	}

	//16x16 caractères
	f->img = oslCreateImage(512, (y+1)*fi->charHeight, OSL_IN_RAM, OSL_PF_4BIT);
	//4 bit texture format
	imageFormat = 4;
	if (!f->img)		{
		free(f->charPositions);
		free(f->charWidths);
		free(f);
		return NULL;
	}
	//La palette
	f->img->palette = oslCreatePalette(16, OSL_PF_8888);
	if (!f->img->palette)		{
		free(f->charPositions);
		free(f->charWidths);
		free(f);
		oslDeleteImage(f->img);
		return NULL;
	}

	if (fi->paletteCount)		{
		for (i=0;i<fi->paletteCount;i++)
			((unsigned long*)f->img->palette->data)[i] = fi->paletteData[i];
	}
	else	{
		((unsigned long*)f->img->palette->data)[0] = RGBA(255,255,255, 0);
		((unsigned long*)f->img->palette->data)[1] = RGBA(255,255,255, 255);
	}

	//Vide directement le cache
	sceKernelDcacheWritebackInvalidateRange(f->img->palette->data, 16*4);

	f->charHeight = fi->charHeight;
	memset(f->img->data, 0, f->img->totalSize);
	//Dessine les caractères sur le buffer
	for (i=0;i<256;i++)		{
		oslDrawChar1BitToImage(f->img, OSL_TEXT_CHARPOSXY(f, i),
			f->charWidths[i] + f->addedSpace, f->charHeight, fi->lineWidth << pixelplanewidth[fi->pixelFormat - 1],
			fi->pixelFormat, imageFormat, (u8*)fi->fontdata+i*fi->lineWidth*fi->charHeight);
	}
	//Pareil, vide direct le cache
	sceKernelDcacheWritebackInvalidateRange(f->img->data, f->img->totalSize);
	return f;
}

OSL_FONT *oslLoadIntraFontFile(const char *filename, unsigned int options)		{
	OSL_FONT *font = NULL;

    font = (OSL_FONT*)malloc(sizeof(OSL_FONT));
    if (!font)
        return NULL;
    font->fontType = OSL_FONT_INTRA;
    font->intra = intraFontLoad(filename, options);
    if (!font->intra){
        free(font);
        font = NULL;
        oslHandleLoadNoFailError(filename);
    }else{
        intraFontSetStyle(font->intra, 1.0f, 0xFFFFFFFF, 0xFF000000, INTRAFONT_ALIGN_LEFT);
        font->charHeight = font->intra->texYSize;
    }
    return font;
}

void oslLoadAltIntraFontFile(OSL_FONT *font, const char *filename)		{
	if (!font || font->fontType != OSL_FONT_INTRA) return;

    intraFont* alt = intraFontLoad(filename, font->intra->options&~INTRAFONT_CACHE_ALL);
    if (!alt)
    {
        oslHandleLoadNoFailError(filename);
    }else{
        intraFontSetStyle(alt, 1.0f, 0xFFFFFFFF, 0xFF000000, INTRAFONT_ALIGN_LEFT);
		if ( font->charHeight < alt->texYSize )
			font->charHeight = alt->texYSize;
        intraFontSetAltFont(font->intra, alt);
    }
	return;
}

OSL_FONT *oslLoadFontFile(const char *filename)		{
	OSL_FONTINFO fi;
	OSL_FONT_FORMAT_HEADER fh;
	VIRTUAL_FILE *f;
	OSL_FONT *font = NULL;
	unsigned char tcTaillesCar[256], *tcCaracteres;

    char *start = (char *)filename + (strlen(filename) - 4);
    if (!strncmp(start, ".pgf", 4) || !strncmp(start, ".PGF", 4)){
        font = (OSL_FONT*)malloc(sizeof(OSL_FONT));
		if (!font)
			return NULL;
        font->fontType = OSL_FONT_INTRA;
        font->intra = intraFontLoad(filename, intra_options);
        if (!font->intra){
            free(font);
            font = NULL;
            oslHandleLoadNoFailError(filename);
        }else{
            intraFontSetStyle(font->intra, 1.0f, 0xFFFFFFFF, 0xFF000000, INTRAFONT_ALIGN_LEFT);
            font->charHeight = font->intra->texYSize;
        }
    }else{
        f = VirtualFileOpen((void*)filename, 0, VF_AUTO, VF_O_READ);
        if (f)			{
            //Lit l'en-tête de la fonte
            VirtualFileRead(&fh, sizeof(fh), 1, f);
            //Vérifie l'en-tête
            if (!strcmp(fh.strVersion, "OSLFont v01"))		{
                fi.pixelFormat = fh.pixelFormat;
                //VERIFIER 1 <= PIXELFORMAT <= 4
                if (fh.variableWidth)		{
                    VirtualFileRead(tcTaillesCar, 256 * sizeof(unsigned char), 1, f);
                    fi.charWidths = tcTaillesCar;
                }
                else
                    fi.charWidths = NULL;
                fi.charWidth = fh.charWidth;
                fi.charHeight = fh.charHeight;
                fi.lineWidth = fh.lineWidth;
                fi.addedSpace = fh.addedSpace;
                //Lit les données des caractères
                tcCaracteres = (u8*)malloc(fh.lineWidth*fi.charHeight*256);
				if (!tcCaracteres)
					return NULL;
                if (VirtualFileRead(tcCaracteres, fh.lineWidth*fi.charHeight*256, 1, f) > 0)			{
                    fi.fontdata = tcCaracteres;
                    fi.paletteCount = fh.paletteCount;
                    fi.paletteData = NULL;
                    //Est-ce qu'il reste encore des couleurs à charger?
                    if (fi.paletteCount > 0)			{
                        fi.paletteData = (unsigned long*)malloc(fi.paletteCount * sizeof(unsigned long));
                        if (fi.paletteData)			{
                            //Lit les entrées de palette
                            if (VirtualFileRead(fi.paletteData, fi.paletteCount * sizeof(unsigned long), 1, f) == 0)			{
                                //Do not use these entries as they were not read correctly
                                fi.paletteCount = 0;
                            }
                        }
                    }
                    //On peut finalement la charger
                    font = oslLoadFont(&fi);
                    if (fi.paletteData)
                        free(fi.paletteData);
                }
                free(tcCaracteres);
            }
            VirtualFileClose(f);
        }
        if (!font)
            oslHandleLoadNoFailError(filename);
        else
            font->fontType = OSL_FONT_OFT;
    }
	return font;
}

void oslDeleteFont(OSL_FONT *f)		{
    if (f->fontType == OSL_FONT_INTRA){
        if (f->intra->altFont)
            intraFontUnload(f->intra->altFont);
        intraFontUnload(f->intra);
    }else if (f->fontType == OSL_FONT_OFT){
        oslDeleteImage(f->img);
        free(f->charPositions);
        free(f->charWidths);
    }
    free(f);
	f = NULL;
}

void oslDrawTextTileBack(int x, int y, int tX, int tY)		{
	int color = oslBlendColor(osl_textBkColor);

	OSL_LINE_VERTEX_COLOR32 *vertices;
	vertices = (OSL_LINE_VERTEX_COLOR32*)sceGuGetMemory(2 * sizeof(OSL_LINE_VERTEX_COLOR32));

	x += osl_curFont->addedSpace;

	vertices[0].color = color;
	vertices[0].x = x;
	vertices[0].y = y;
	vertices[0].z = 0;

	vertices[1].color = color;
	vertices[1].x = x+tX;
	vertices[1].y = y+tY;
	vertices[1].z = 0;

    int wasEnable = osl_textureEnabled;
    oslDisableTexturing();

    sceGuDrawArray(GU_SPRITES,GU_COLOR_8888|GU_VERTEX_16BIT|GU_TRANSFORM_2D,2,0,vertices);
	sceKernelDcacheWritebackRange(vertices, 2 * sizeof(OSL_LINE_VERTEX_COLOR32)); //SAKYA
    if (wasEnable)
        oslEnableTexturing();
}

//Dessine une tile de la texture sélectionnée. Eviter d'utiliser à l'extérieur.
void oslDrawTextTile(int u, int v, int x, int y, int tX, int tY)
{
	int color = oslBlendColor(osl_textColor);

	//If enabled, draw the background
	if (osl_textBkColor & 0xff000000)
		oslDrawTextTileBack(x, y, tX, tY);

	tX += osl_curFont->addedSpace;

	OSL_FAST_VERTEX_COLOR32 *vertices;
	vertices = (OSL_FAST_VERTEX_COLOR32*)sceGuGetMemory(2 * sizeof(OSL_FAST_VERTEX_COLOR32));

	vertices[0].u = u;
	vertices[0].v = v;
	vertices[0].color = color;
	vertices[0].x = x;
	vertices[0].y = y;
	vertices[0].z = 0;

	vertices[1].u = u+tX;
	vertices[1].v = v+tY;
	vertices[1].color = color;
	vertices[1].x = x+tX;
	vertices[1].y = y+tY;
	vertices[1].z = 0;

    int wasEnable = osl_textureEnabled;
	oslEnableTexturing();

	sceGuDrawArray(GU_SPRITES,GU_TEXTURE_16BIT|GU_COLOR_8888|GU_VERTEX_16BIT|GU_TRANSFORM_2D,2,0,vertices);
	sceKernelDcacheWritebackRange(vertices, 2 * sizeof(OSL_FAST_VERTEX_COLOR32)); //SAKYA
    if (!wasEnable)
        oslDisableTexturing();
}

void oslDrawChar(int x, int y, unsigned char c)
{
	if (!osl_curFont)
		return;
    if (osl_curFont->fontType == OSL_FONT_OFT){
        oslSetTexture(osl_curFont->img);
        //Dessine le caractère
        oslDrawTextTile(OSL_TEXT_CHARPOSXY(osl_curFont, c), x, y, osl_curFont->charWidths[c], osl_curFont->charHeight);
    }else if (osl_curFont->fontType == OSL_FONT_INTRA){
        char temp[2];
        sprintf(temp, "%c", c);
        y += (int)((float)osl_curFont->charHeight / 2.0) + 1;
        intraFontPrint(osl_curFont->intra, x, y, temp);
    }
}

void oslDrawString(int x, int y, const char *str)
{
    if (osl_curFont->fontType == OSL_FONT_OFT){
        unsigned char c;
        if (!osl_curFont)
            return;
        oslSetTexture(osl_curFont->img);
        while(*str)			{
            c = *(unsigned char*)str++;
            oslDrawTextTile(OSL_TEXT_CHARPOSXY(osl_curFont, c), x, y, osl_curFont->charWidths[c], osl_curFont->charHeight);
            x += osl_curFont->charWidths[c];
        }
    }else if (osl_curFont->fontType == OSL_FONT_INTRA){
		//intraFontActivate(osl_curFont->intra);
        y += (int)((float)osl_curFont->charHeight / 2.0) + 1;
        intraFontPrint(osl_curFont->intra, x, y, str);
    }

}

void oslDrawTextBox(int x0, int y0, int x1, int y1, const char *text, int format)
{
	int x,y, x2;
	unsigned char c;
	const char *text2;
	x = x0;
	y = y0;
	while(*text)		{
		c = *text;
		if (c == ' ')
		{
			text2 = text;
			x2 = x;
			do		{
				x2 += osl_curFont->charWidths[(int)(*text2++)];
				if (x2 > x1)		{
					text++;
					goto newline;
				}
			} while(*text2 != '\n' && *text2 != ' ' && *text2);
		}
		if (x + osl_curFont->charWidths[c] > x1 || *text=='\n')			{
newline:
			//Prochaine ligne
			x = x0;
			y += osl_curFont->charHeight;
			//Trop bas -> terminé
			if (y + osl_curFont->charHeight > y1)
				break;
			//Retour -> saute
			if (*text == '\n')
				text++;
			continue;
		}
		oslDrawChar(x,y,c);
		x += osl_curFont->charWidths[c];
		text++;
	}
}

void oslInitConsole()
{
	//Charge et utilise la fonte système
	if (!osl_sceFont)
		osl_sceFont = oslLoadFont(&osl_sceFontInfo);
	oslSetFont(osl_sceFont);
	oslCls();
//	osl_consoleOk=1;
}

void oslMoveMem(void *dst, void *src, int size)
{
	unsigned long *fdst=(unsigned long*)dst, *fsrc=(unsigned long*)src;
	while(size > 0)			{
		*fdst++ = *fsrc++;
		size -= 4;
	}
}

void oslConsolePrint(const char *str)
{
	unsigned char c;
//	if (!osl_consoleOk)
//		return;
	OSL_FONT *oldFont = NULL;
	if (osl_curFont != osl_sceFont)
	{
		oldFont = osl_curFont;
		oslSetFont(osl_sceFont);
	}

	while(*str)
	{
		c = *(unsigned char*)str++;
		if (c!='\n')			{
			oslDrawChar(osl_consolePosX, osl_consolePosY, c);
			osl_consolePosX += osl_curFont->charWidths[c];
		}
		//A droite de l'écran
		if (osl_consolePosX+7 > osl_curBuf->sizeX || c=='\n')			{
			osl_consolePosY += osl_curFont->charHeight;
			//[MARCHE PAS, TESTER] Trop bas -> défile
			if (osl_consolePosY + osl_curFont->charHeight > osl_curBuf->sizeY)		{
				osl_consolePosY -= osl_curFont->charHeight;
				oslSyncDrawing();
				oslMoveMem(oslAddVramPrefixPtr(oslGetImageLine(osl_curBuf, 0)), oslAddVramPrefixPtr(oslGetImageLine(osl_curBuf, osl_curFont->charHeight)), osl_curBuf->totalSize-(int)oslGetImageLine(osl_curBuf, osl_curFont->charHeight));
				oslFlushDataCache();
				oslDrawFillRect(0, osl_consolePosY, osl_curBuf->sizeX, osl_curBuf->sizeY, 0);
			}
			osl_consolePosX = 0;
		}
	}

	if (oldFont != NULL)
		oslSetFont(oldFont);
}

void oslSetTextColor(OSL_COLOR color)			{
	osl_textColor = color;
}

void oslSetBkColor(OSL_COLOR color)			{
	osl_textBkColor = color;
}


int oslGetStringWidth(const char *str)
{
    if (!osl_curFont)
        return 0;

    u32 x = 0;
    if (osl_curFont->fontType == OSL_FONT_OFT){
        unsigned char c;

        //Parcourt tous les caractères
        while(*str)			{
            c = *(unsigned char*)str++;
            x += osl_curFont->charWidths[c];
        }
    }else if (osl_curFont->fontType == OSL_FONT_INTRA){
        x = (int)intraFontMeasureText(osl_curFont->intra, str);
    }
	return x;
}

int oslGetTextBoxHeight(int width, int maxHeight, const char *text, int format)
{
	int x,y, x2;
	unsigned char c, newLine = 1;
	const char *text2;

	x = y = 0;

	while (*text)		{
		c = *text;
		if (c == ' ')
		{
			text2 = text;
			x2 = x;
			do		{
				x2 += osl_curFont->charWidths[(int)(*text2++)];
				if (x2 > width)		{
					text++;
					goto newline;
				}
			} while(*text2 != '\n' && *text2 != ' ' && *text2);
		}
		if (x + osl_curFont->charWidths[c] > width || *text=='\n')			{
newline:
			//Prochaine ligne
			x = 0;
			if (newLine && *text=='\n')
				y += osl_curFont->charHeight;
			newLine = 1;
			//Retour -> saute
			if (*text == '\n')
				text++;
			continue;
		}
		//Trop bas -> terminé
		if (y + osl_curFont->charHeight > maxHeight && maxHeight > 0)
			break;
		if (newLine)
			newLine = 0, y += osl_curFont->charHeight;
		x += osl_curFont->charWidths[c];
		text++;
	}

	return y;
}


int oslIntraFontInit(unsigned int options){
    intra_options = options;
    osl_intraInit = 1;
    return intraFontInit();
}

void oslIntraFontShutdown(){
    osl_intraInit = 0;
    intra_options = 0;
    intraFontShutdown();
}

void oslIntraFontSetStyle(OSL_FONT *f, float size, unsigned int color, unsigned int shadowColor, unsigned int options){
    if (f->intra){
        intraFontSetStyle(f->intra, size, color, shadowColor, options);
        if(f->intra->altFont)
            intraFontSetStyle(f->intra->altFont, size, color, shadowColor, options);
    }
}

