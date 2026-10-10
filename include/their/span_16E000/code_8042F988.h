#ifndef UNBAKE_SPAN_16E000_CODE_8042F988_H
#define UNBAKE_SPAN_16E000_CODE_8042F988_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_08c282c47e39cff43d22f22a */
extern int func_80434750_de(void);

struct Name;
/* unbake published declaration: published_26edcae6190e2382fc68861a */
struct Name {
    u8 flags[2];
    u8 code[0x14];
    u8 text[0x46 - 0x16];
};

struct PakDisplayName;
/* unbake published declaration: published_776a336b01860b78beb1faae */
typedef struct PakDisplayName PakDisplayName;

struct PakDisplayName;
/* unbake published declaration: published_a72761cdc5d97a4720122974 */
struct PakDisplayName {
    char text[0x3C];
    char code[70 - 0x3C];
};

struct Name;
/* unbake published declaration: published_e55f3ba67da026f15d8970cd */
typedef struct Name Name;

struct Shared_Player_func_80433F14;
/* unbake published declaration: published_3cbe4762130bbe68b1a0dcf3 */
struct Shared_Player_func_80433F14 {
    s32 state;
    s32 sub;
    s32 next;
    union { s32 menu; MenuWidget *menuWidget; };
    char pad10[0x14 - 0x10];
    s32 back;
    union {
        char slots[4][400];
        Record_func_80433914_de records[4];
    };
    union {
        struct { char pad658[0x67E - 0x658]; Name names[15]; };
        PakDisplayName displayNames[15];
    };
    char padA98[0xAD8 - 0xA98];
    s32 slot;
    union {
        char padADC[0xAEC - 0xADC];
        struct { s32 scroll; MenuWidget *labels[3]; };
    };
    union {
        s32 chosen;
        s32 choice;
    };
    s32 used[4];
    union { s32 notes[4]; MenuWidget *nodes[4]; };
    char padB10[0xB28 - 0xB10];
    s32 port;
    s32 record;
    s32 host;
    char padB34[0xB64 - 0xB34];
    s32 profile;
};

struct Shared_Player_func_80433F14;
/* unbake published declaration: published_938a7734fc1938e8e130b05a */
typedef struct Shared_Player_func_80433F14 Shared_Player_func_80433F14;

struct PakMenuController;
/* unbake published declaration: published_0912bfd6b2d718dc0d995c44 */
struct PakMenuController {
    s32 field0;
    s32 root;
    char pad8[0x54 - 8];
    s32 phase;
    Shared_Player_func_80433F14 players[4];
};

struct Char;
/* unbake published declaration: published_1bec77b4622757b9cd129b7c */
struct Char {
    char c;
    char pad;
};

struct Char;
struct Player_func_80432158_de;
/* unbake published declaration: published_514ecef1b4117c8435ba9e97 */
struct Player_func_80432158_de {
    s32 state;
    char pad4[0xB34 - 0x4];
    struct Char name[8];
    s32 cursor;
    char padB48[0xB68 - 0xB48];
};

struct Block_func_80432158_de;
struct Player_func_80432158_de;
/* unbake published declaration: published_0e3b344786ade134ad8d6c71 */
struct Block_func_80432158_de {
    char pad0[0x54];
    s32 phase;
    struct Player_func_80432158_de players[4];
};

struct Record_func_804347CC_de;
/* unbake published declaration: published_24dbad8e9a602e8be686e939 */
struct Record_func_804347CC_de {
    char pad0[0xD];
    s8 owner;
    char padE[400 - 0xE];
};

struct Player_func_804347CC_de;
/* unbake published declaration: published_67ed07c39a25e654a129357d */
struct Player_func_804347CC_de {
    char pad0[0xB28];
    s32 chosen;
    char padB2C[0xB68 - 0xB2C];
};

struct Block_func_804347CC_de;
struct Player_func_804347CC_de;
struct Record_func_804347CC_de;
/* unbake published declaration: published_0e6278708d44f02f1f594607 */
struct Block_func_804347CC_de {
    char pad0[0x58];
    struct Player_func_804347CC_de players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Record_func_804347CC_de saved[4];
};

/* unbake published declaration: published_168b7662f1f383690c0017f8 */
extern s32 D_800E25A4[];

struct Shared_Item;
struct func_8028469C_S2;
/* unbake published declaration: published_1f6462984d5239635e05b893 */
struct Shared_Item {
    char pad0[0x8];
    struct func_8028469C_S2 * label;
    char padC[0x6];
    u16 flags;
    char pad14[0x24];
    struct Shared_Item *next;
};

/* unbake published declaration: published_232df907e210e7ae13912bce */
extern void func_80434B08_de(s32 player);

struct Player_func_8043497C_de;
/* unbake published declaration: published_26515b210391c42661113c3d */
struct Player_func_8043497C_de {
    char pad0[0x4];
    s32 word4;
    char pad8[0x18 - 0x8];
    char slots[4][400];
    char pad658[0xAEC - 0x658];
    s32 chosen;
    s32 flags[4];
    char padB00[0xB68 - 0xB00];
};

struct Player_func_80434C2C_de;
/* unbake published declaration: published_286deeea4fe988e5645cc956 */
struct Player_func_80434C2C_de {
    char pad0[0xC];
    void *window;
    char pad10[0xB68 - 0x10];
};

/* unbake published declaration: published_2c0b6fd5ee79980cfeff2caa */
extern void func_80434C2C_de(s32 player);

struct MatchSetupGlobals;
/* unbake published declaration: published_2e3d13cd46fdf516490b4b4a */
struct MatchSetupGlobals {
    char pad0[0xD0];
    ListScreenRecord status[8];
};

struct Item_func_80434C2C_de;
/* unbake published declaration: published_2edca9ed46f9db7273bbbc87 */
struct Item_func_80434C2C_de {
    char pad[0x38];
    u8 *text;
};

struct Block_func_80434B08_de;
struct Player_func_804356BC_de;
/* unbake published declaration: published_45cc4a62b85166ca17540a3e */
struct Block_func_80434B08_de {
    char pad0[0x58];
    struct Player_func_804356BC_de players[4];
};

struct Player_func_8042F7A8_de;
/* unbake published declaration: published_48c73e4e6ab45256bb4182cf */
struct Player_func_8042F7A8_de {
    char pad0[0x14];
    s32 timer;
    char pad18[0xB68 - 0x18];
};

/* unbake published declaration: published_4c3b7e35e8f4634d07471ff2 */
extern u8 D_80152789;

struct PakMenuController;
/* unbake published declaration: published_4db0231b0e4126691f89e038 */
typedef struct PakMenuController PakMenuController;

struct Block_func_8042F7A8_de;
struct Player_func_8042F7A8_de;
/* unbake published declaration: published_5746ffd082b0b56a649d0db7 */
struct Block_func_8042F7A8_de {
    char pad0[0x8];
    char menu[0x4C - 0x8];
    s32 phase4C;
    char pad50[0x54 - 0x50];
    s32 phase54;
    struct Player_func_8042F7A8_de players[4];
};

struct MatchSetupGlobals;
/* unbake published declaration: published_71c37f8a254cc0b55818f7de */
typedef struct MatchSetupGlobals MatchSetupGlobals;

/* unbake published declaration: published_78a5df614b0a81b47218c2f5 */
extern void func_804347CC_de(void);

struct Block_func_80434C2C_de;
struct Player_func_80434C2C_de;
/* unbake published declaration: published_78f7327ea4b68950019cd54a */
struct Block_func_80434C2C_de {
    char pad0[0x58];
    struct Player_func_80434C2C_de players[4];
};

struct Blk;
/* unbake published declaration: published_79c312a5c054aa375ebddd0e */
typedef struct Blk Blk;

struct Row_func_80430028_de;
/* unbake published declaration: published_819d60627a785c8e8bca4978 */
struct Row_func_80430028_de {
    char pad0[0x58];
    s32 state;
    char pad5C[0xB9C - 0x5C];
    s32 count;
    s32 phase;
    s32 timer;
};

struct Shared_Block;
/* unbake published declaration: published_b56b2a27de07acb3208c5fcb */
typedef struct Shared_Block Shared_Block;

struct Shared_Item;
/* unbake published declaration: published_b5dd927ef1cb2ede7edd86ad */
typedef struct Shared_Item Shared_Item;

struct Block_func_80430028_de;
struct Slots_func_8041B7FC_de;
/* unbake published declaration: published_b5eec2481654d6e87fbb02f8 */
struct Block_func_80430028_de {
    char pad0[4];
    struct Slots_func_8041B7FC_de *slots;
};

struct Shared_Block;
/* unbake published declaration: published_bb245bd6a2636e6d807cb8c2 */
struct Shared_Block {
    void *window;
    union {
        void *list;
        s32 menu;
    };
    char pad8[0x54 - 0x8];
    s32 mode;
    Shared_Player_func_80433F14 players[4];
    s32 source;
    s32 sourceRecord;
    Triple ports[4];
};

struct Item_func_80433BCC_de;
struct func_8028469C_S2;
/* unbake published declaration: published_bea9b9b6dbc1264f3125898b */
struct Item_func_80433BCC_de {
    char pad[0x8];
    struct func_8028469C_S2 *label;
};

struct Player_func_80433BCC_de;
/* unbake published declaration: published_befc5a615ed4fb2dcfc226a8 */
struct Player_func_80433BCC_de {
    char pad0[0x18];
    char slots[4][400];
    char pad658[0xAEC - 0x658];
    s32 chosen;
    char padAF0[0xB68 - 0xAF0];
};

/* unbake published declaration: published_c3ff99bbf118e9007d184346 */
extern s32 func_8043497C_de(s32 player);

struct Packet;
/* unbake published declaration: published_cc26a6d9ede7c6896e4bd52b */
struct Packet {
    char data[0x640];
    s32 tail;
    s32 checksum;
    char pad648[0x648 - 0x648];
};

struct Blk;
/* unbake published declaration: published_cd9f9218cb406f4d153f06a5 */
struct Blk {
    char p0[4];
    s32 unk4;
    char p1[0x24];
    s32 unk2C;
    char p2[0x28];
    s32 unk58;
    char p3[0xAD4];
    s32 unkB30;
    s32 unkB34;
    Resource_func_80419E54_de *unkB38;
    char p4[0x64];
    s32 unkBA0;
    s32 unkBA4;
};

struct Player_func_80434638_de;
/* unbake published declaration: published_d01123c727ed10f04669a631 */
struct Player_func_80434638_de {
    s32 first;
    char pad4[0x14 - 0x4];
    s32 second;
    char data[0x640];
    char pad658[0xB64 - 0x658];
    s32 tail;
};

/* unbake published declaration: published_d3e38c8282cc2d501b91b5d1 */
extern void func_80433398_de(s32 arg0);

struct Block_func_80434638_de;
struct Packet;
struct Player_func_80434638_de;
/* unbake published declaration: published_dd01800db4d5c5805812c2dd */
struct Block_func_80434638_de {
    char pad0[0x58];
    struct Player_func_80434638_de players[4];
    char pad2DF8[0x2E28 - 0x2DF8];
    struct Packet packet;
};

struct Block_func_80433BCC_de;
struct Player_func_80433BCC_de;
/* unbake published declaration: published_f048dd35dce1a256a4e6f38b */
struct Block_func_80433BCC_de {
    void *window;
    void *list;
    char pad8[0x58 - 0x8];
    struct Player_func_80433BCC_de players[4];
};

struct Block_func_8043497C_de;
struct Player_func_8043497C_de;
struct Triple;
/* unbake published declaration: published_f95e723164c134a4e51801fc */
struct Block_func_8043497C_de {
    char pad0[0x58];
    struct Player_func_8043497C_de players[4];
    struct Triple places[4];
};

struct PakMenuTail;
struct Triple;
/* unbake published declaration: published_fecdf1231fb17be6b1cdb9ff */
struct PakMenuTail {
    s32 source;
    s32 sourceRecord;
    struct Triple ports[4];
};

#endif
