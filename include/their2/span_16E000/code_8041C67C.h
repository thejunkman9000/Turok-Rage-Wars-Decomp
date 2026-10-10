#ifndef UNBAKE_SPAN_16E000_CODE_8041C67C_H
#define UNBAKE_SPAN_16E000_CODE_8041C67C_H
#include "../types.h"
struct OSPfsState;
/* unbake published declaration: published_ac268d47c80a22d0783f41ab */
struct OSPfsState {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    char ext_name[4];
    char game_name[16];
};

struct OSPfsState;
/* unbake published declaration: published_c589527dea30ddcee5f6fc8b */
typedef struct OSPfsState OSPfsState;

struct __OSContRequesFormatShort;
/* unbake published declaration: published_c9da4b3e3661f2cbc23127a6 */
typedef struct __OSContRequesFormatShort __OSContRequesFormatShort;

struct __OSContRequesFormatShort;
/* unbake published declaration: published_e19f204bcbc2c0c8934a6674 */
struct __OSContRequesFormatShort {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
};

#endif
