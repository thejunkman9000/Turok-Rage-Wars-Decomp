#ifndef UNBAKE_SPAN_16E000_CODE_804221A0_H
#define UNBAKE_SPAN_16E000_CODE_804221A0_H
#include "../types.h"
struct func_80422C20_S1;
/* unbake published declaration: published_133d5a2981ef72e48f273841 */
struct func_80422C20_S1 {
    char pad0[0x1240];
    u8 unk1240;
    char pad1240[0x180C - 0x1240 - sizeof(u8)];
    s32 unk180C;
};

struct func_80422C20_S1;
/* unbake published declaration: published_31885d3de6161ae1a18f0755 */
typedef struct func_80422C20_S1 func_80422C20_S1;

/* unbake published declaration: published_4c05e100b095c495b08fb548 */
extern s32 func_8042244C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_866f774c04dc615c5b2f4e5d */
extern void func_80422170_de();

/* unbake published declaration: published_8b8a30d10e6510b97d56c99f */
extern void func_80422F9C_de();

/* unbake published declaration: published_9e7619fca375d53e164ca51a */
extern void func_804221E8_de();

struct Screen_func_80422960_de;
/* unbake published declaration: published_a14285d432fe59ffa34fcd5d */
struct Screen_func_80422960_de {
    char pad0[0x1C];
    s32 choice;
    char pad20[0x60 - 0x20];
    s32 mode;
    s32 arena;
};

struct Game_func_80422960_de;
/* unbake published declaration: published_c32bce770bea3c5c69827ec5 */
struct Game_func_80422960_de {
    char pad0[0x3C];
    s32 next;
    char pad40[0xD8 - 0x40];
    s32 selection;
};

#endif
