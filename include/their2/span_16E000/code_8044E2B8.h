#ifndef UNBAKE_SPAN_16E000_CODE_8044E2B8_H
#define UNBAKE_SPAN_16E000_CODE_8044E2B8_H
#include "../types.h"
struct Item_func_8044D668_de;
/* unbake published declaration: published_19af1571a60feb6037c82d8b */
typedef struct Item_func_8044D668_de Item_func_8044D668_de;

struct func_8044E9A0_S1;
/* unbake published declaration: published_4265a79e2b65078b53a8017a */
typedef struct func_8044E9A0_S1 func_8044E9A0_S1;

struct func_8044E9A0_S1;
/* unbake published declaration: published_7761baea0588a03a3b0cd650 */
struct func_8044E9A0_S1 {
    char pad0[0x26DBC];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    u8 unk26DC1;
};

struct Item_func_8044D668_de;
/* unbake published declaration: published_e7cdc26b93f854c05cccc322 */
struct Item_func_8044D668_de {
    char pad0[0x11];
    u8 kind;
    char pad12[2];
};

struct Level;
/* unbake published declaration: published_89074508878058526cf744c6 */
struct Level {
    char pad0[0x11C0];
    s32 counts[2];
    char pad11C8[8];
    Item_func_8044D668_de *items[2];
};

struct Level;
/* unbake published declaration: published_c6e4f47305289a6fd779c0f9 */
typedef struct Level Level;

struct State_func_8044DD50_de;
/* unbake published declaration: published_e9a427152c7db20fc3e31a4b */
struct State_func_8044DD50_de {
    char pad0[0x24];
    s32 a;
    char pad28[0x54 - 0x28];
    s32 b;
    char pad58[0x78 - 0x58];
    s32 c;
    char pad7C[0x88 - 0x7C];
    s32 d;
    char pad8C[0xAC - 0x8C];
    s32 e;
};

extern int func_8044DCC0_de();
#endif
