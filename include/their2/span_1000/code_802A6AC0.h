#ifndef UNBAKE_SPAN_1000_CODE_802A6AC0_H
#define UNBAKE_SPAN_1000_CODE_802A6AC0_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Marker_func_802A71C0_de;
/* unbake published declaration: published_3fbc611bfd678af1fd532247 */
struct Marker_func_802A71C0_de {
    char text[15];
};

struct Marker_func_802A71C0_de;
/* unbake published declaration: published_d0252fa26d043c6969926f09 */
typedef struct Marker_func_802A71C0_de Marker_func_802A71C0_de;

/* unbake published declaration: published_065e11091c656476811fb8db */
extern void func_802A7654_de(void);

struct Node802A697C;
/* unbake published declaration: published_905e5234c19342094c46e354 */
typedef struct Node802A697C Node802A697C;

struct State802A6DF8;
/* unbake published declaration: published_bc33774d70f2721d4d864883 */
struct State802A6DF8 {
    struct State802A6DF8 *prev;
    struct State802A6DF8 *next;
    Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};

struct List802A6DF8;
struct State802A6DF8;
/* unbake published declaration: published_0c3368d03a6f5c71336fbb5e */
struct List802A6DF8 {
    struct State802A6DF8 *head;
    struct State802A6DF8 *tail;
    s32 count;
};

struct List802A6DF8;
/* unbake published declaration: published_eae5cf51f18ce712bf4b6a48 */
typedef struct List802A6DF8 List802A6DF8;

struct Lists802A6DF8;
/* unbake published declaration: published_0738b57f84c333d422c47128 */
struct Lists802A6DF8 {
    List802A6DF8 active;
    List802A6DF8 inactive;
};

struct func_802A7164_S4;
/* unbake published declaration: published_104ce63422660a4c9112e296 */
typedef struct func_802A7164_S4 func_802A7164_S4;

/* unbake published declaration: published_1aa30685fe665327a53891cc */
extern void func_802A6174_de(void *arg0, void *arg1);

struct func_802A72F4_S1;
/* unbake published declaration: published_1d69dd0193e9b0bb3cff2ca1 */
typedef struct func_802A72F4_S1 func_802A72F4_S1;

struct func_802A72AC_S2;
/* unbake published declaration: published_22b2491c3f3f4b7740dd277f */
typedef struct func_802A72AC_S2 func_802A72AC_S2;

struct func_802A6B74_S1;
/* unbake published declaration: published_237c956d23fd4f749f564f4b */
struct func_802A6B74_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};

struct Bar;
/* unbake published declaration: published_5686191f081389d1fd19c0ea */
struct Bar {
    s32 unk0;
    s32 *script;
    s32 state;
    s32 wait;
    f32 x;
    f32 y;
    char pad18[0x20];
    s32 fill;
    s32 label;
    char pad40[4];
    s32 target;
};

struct Bar;
/* unbake published declaration: published_f446efa5ab6b586f7d6d9704 */
typedef struct Bar Bar;

struct Hud;
/* unbake published declaration: published_276a1706fb3ee266c9a935c8 */
struct Hud {
    Bar bars[2];
};

struct Menu_func_802A65E0_de;
/* unbake published declaration: published_27e5dbef48a207c4a1d6b190 */
typedef struct Menu_func_802A65E0_de Menu_func_802A65E0_de;

/* unbake published declaration: published_2a46b5ee8e4bc60273d7a21c */
extern void func_802A7180_de(void *arg0, void *arg1);

struct Frame_func_802A7660_de;
/* unbake published declaration: published_2f355df3166d3352db29f3de */
struct Frame_func_802A7660_de {
    char pad0[0x2A0];
    f32 height;
};

/* unbake published declaration: published_3030fe4152821b26c77ab817 */
extern void func_802A7168_de(void *arg0);

struct Lists802A6DF8;
/* unbake published declaration: published_97d631f5649517e737c25be3 */
typedef struct Lists802A6DF8 Lists802A6DF8;

struct Owner802A6DF8;
/* unbake published declaration: published_31d68f3db1a4e7e588be3e9f */
struct Owner802A6DF8 {
    u8 pad0[0x751C];
    Lists802A6DF8 lists;
};

struct func_802A72AC_S2;
/* unbake published declaration: published_32e38d37ca6f29aee62ab866 */
struct func_802A72AC_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xA8 - 0x4 - sizeof(void*)];
    f32 unkA8;
    char padA8[0xAC - 0xA8 - sizeof(f32)];
    f32 unkAC;
};

/* unbake published declaration: published_37c20bf75568659acdbcabe0 */
extern void func_802A62BC_de(void *arg0);

struct func_802A6AC0_S2;
/* unbake published declaration: published_3a074ddcf2572e5e74b16c6f */
struct func_802A6AC0_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
};

struct Entry_func_802A6F68_de;
/* unbake published declaration: published_3f9e18cf9673cc9f1bb9c0c3 */
typedef struct Entry_func_802A6F68_de Entry_func_802A6F68_de;

struct State802A6DF8;
/* unbake published declaration: published_400575628304543f8fb4c602 */
typedef struct State802A6DF8 State802A6DF8;

struct Input_func_802A65E0_de;
/* unbake published declaration: published_40762d04fc59c94c61746dd2 */
struct Input_func_802A65E0_de {
    char pad0[0x6AC];
    s32 held;
    s32 pressed;
};

struct func_802A7FA8_S4;
/* unbake published declaration: published_41b8ef509a7d7d90d29e1d3c */
typedef struct func_802A7FA8_S4 func_802A7FA8_S4;

struct ObjectState30_2;
/* unbake published declaration: published_42d299de79c1605f722a6a68 */
typedef struct ObjectState30_2 ObjectState30_2;

struct func_802A7440_S2;
/* unbake published declaration: published_4743eff2577b6780c64f86f7 */
typedef struct func_802A7440_S2 func_802A7440_S2;

struct Sprite;
/* unbake published declaration: published_497ca9a75f2dde790d5579bb */
struct Sprite {
    s32 format;
    char *data;
    s32 field8;
    s32 fieldC;
    f32 width;
    f32 height;
    f32 extentX;
    f32 extentY;
    f32 step;
};

/* unbake published declaration: published_498af8e1f8d8ef302b0b390a */
extern float D_800C5EB0_de;

struct func_802A7164_S1;
/* unbake published declaration: published_4b4081ec7198f20ba4b758ea */
typedef struct func_802A7164_S1 func_802A7164_S1;

struct Owner802A6DF8;
/* unbake published declaration: published_527ec1ac82293ae4647d2185 */
typedef struct Owner802A6DF8 Owner802A6DF8;

struct Entry_func_802A6F68_de;
/* unbake published declaration: published_56b8cce5c4393b0003647bfe */
struct Entry_func_802A6F68_de {
    int unk0;
    int unk4;
    char pad8[5];
    unsigned char unkD;
    char padE[0x18 - 0xE];
    short unk18;
    int unk1C;
    char pad20[0x18];
};

struct func_802A7FA8_S4;
/* unbake published declaration: published_56d6d53cd63060e3315cdd88 */
struct func_802A7FA8_S4 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    u8 unkC;
    char padC[0xD - 0xC - sizeof(u8)];
    u8 unkD;
    char padD[0x10 - 0xD - sizeof(u8)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x28 - 0x14 - sizeof(s32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
    char pad30[0x34 - 0x30 - sizeof(s32)];
    s32 unk34;
};

struct func_802A7FA8_S3;
/* unbake published declaration: published_5ebc46e24ebedeefb5a8c34b */
typedef struct func_802A7FA8_S3 func_802A7FA8_S3;

struct func_802A8158_S1;
/* unbake published declaration: published_61e32c3436de64d91c4b6c53 */
typedef struct func_802A8158_S1 func_802A8158_S1;

struct func_802A8158_S1;
/* unbake published declaration: published_64c6d2090311f18fbc6dc7cc */
struct func_802A8158_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0xD - 0x4 - sizeof(int)];
    char unkD;
    char padD[0x18 - 0xD - sizeof(char)];
    short unk18;
    char pad18[0x1C - 0x18 - sizeof(short)];
    int unk1C;
};

struct CallbackState1C;
/* unbake published declaration: published_6fd86b7cbb7ac9acd3e3ef7b */
typedef struct CallbackState1C CallbackState1C;

struct func_802A7164_S4;
/* unbake published declaration: published_72a5daaae311d02affa7a76e */
struct func_802A7164_S4 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x3C - 0x8 - sizeof(void*)];
    u32 unk3C;
};

struct ObjectLinks14_2;
/* unbake published declaration: published_761cba6e1f2f3752d1f7ec1c */
typedef struct ObjectLinks14_2 ObjectLinks14_2;

struct func_802A6B74_S1;
/* unbake published declaration: published_77430e15f4401c5e21e3f977 */
typedef struct func_802A6B74_S1 func_802A6B74_S1;

struct func_802A7480_S2;
/* unbake published declaration: published_7798973d975a9989df8bcdcf */
struct func_802A7480_S2 {
    char pad0[0x4];
    char * unk4;
    char pad4[0x34 - 0x4 - sizeof(char*)];
    s32 unk34;
    char pad34[0x3C - 0x34 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x48 - 0x3C - sizeof(s32)];
    s32 unk48;
};

struct func_802A7FA8_S1;
/* unbake published declaration: published_786b58adc9be1761ffe26573 */
typedef struct func_802A7FA8_S1 func_802A7FA8_S1;

struct func_802A72AC_S1;
/* unbake published declaration: published_7a7965163ff4c6dfef50cb6f */
struct func_802A72AC_S1 {
    char pad0[0x40];
    void * unk40;
    char pad40[0x4C - 0x40 - sizeof(void*)];
    f32 unk4C;
};

struct func_802A72F4_S1;
/* unbake published declaration: published_7a981ccdefbefc4c71916aef */
struct func_802A72F4_S1 {
    char pad0[0x34];
    s32 unk34;
    char pad34[0x3C - 0x34 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x48 - 0x3C - sizeof(s32)];
    s32 unk48;
};

struct func_802A6D28_S2;
/* unbake published declaration: published_7d3e19a1497023f3c7ebb43b */
struct func_802A6D28_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x48 - 0x4 - sizeof(void*)];
    s32 unk48;
};

struct MenuItem;
/* unbake published declaration: published_8ea141e0ec08a74c2fdc04da */
typedef struct MenuItem MenuItem;

struct MenuItem;
/* unbake published declaration: published_b01f8e90bdac1675050ba477 */
struct MenuItem {
    s32 active;
    s32 on;
    char pad8[0x18 - 0x8];
    s16 bounce;
    s32 startFrame;
    f32 value;
    s32 extra;
    f32 restoreValue;
    s32 restoreExtra;
    s32 (*select)(void *input, struct MenuItem *item);
    s32 (*update)(void *input, struct MenuItem *item);
};

struct Menu_func_802A65E0_de;
/* unbake published declaration: published_7f19267e71cf7332a614d85d */
struct Menu_func_802A65E0_de {
    u8 state;
    u8 timer;
    MenuItem items[4];
    u16 selected;
    s16 blink;
    s32 frame;
};

struct ObjectLinks7598;
/* unbake published declaration: published_803177d6c84d7d7c60805199 */
typedef struct ObjectLinks7598 ObjectLinks7598;

/* unbake published declaration: published_80defdc1eda9602e391ae242 */
extern float D_800C5EA8_de;

struct ObjectLinks7598;
/* unbake published declaration: published_84c69ab53057ccb6adcac445 */
struct ObjectLinks7598 {
    char pad0[0x7588];
    char unk_7588;
    char pad7588[0x7594 - 0x7588 - sizeof(char)];
    void * unk_7594;
};

struct func_802A7FA8_S1;
/* unbake published declaration: published_85593d9d5f289cf471babb33 */
struct func_802A7FA8_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x10 - 0x4 - sizeof(s32)];
    u8 unk10;
};

struct ObjectState30_2;
/* unbake published declaration: published_874aaa14ec27a05dbb6c856a */
struct ObjectState30_2 {
    unsigned char padding_0[4];
    s32 unk_4;
    unsigned char padding_8[16];
    s16 unk_18;
    unsigned char padding_1A[2];
    s32 unk_1C;
    f32 unk_20;
    s32 unk_24;
    f32 unk_28;
    s32 unk_2C;
};

struct Hud;
/* unbake published declaration: published_8ebda8a29e511e8cfe7a88d6 */
typedef struct Hud Hud;

struct ObjectLinks14_2;
/* unbake published declaration: published_9015bfd5b7ba2a0f7a8b68fa */
struct ObjectLinks14_2 {
    char pad0[0x4];
    void * next;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    f32 unk_8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unk_C;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk_10;
};

struct Sprite;
/* unbake published declaration: published_9a7f6d0833a9da6f4e53a282 */
typedef struct Sprite Sprite;

struct Image;
/* unbake published declaration: published_9165df15b8894b3ae45627db */
extern void func_802A6068_de(struct Image * image, struct Image * texture, Sprite * sprite);

struct func_802A6D28_S1;
/* unbake published declaration: published_98085f978546ee1eeb6134e4 */
struct func_802A6D28_S1 {
    char pad0[0x94E0];
    IntrusiveList slots[10];
    IntrusiveList free;
};

struct func_802A6F8C_S1;
/* unbake published declaration: published_98ceeb8c2590b9b0f1c6ea94 */
struct func_802A6F8C_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x34 - 0x14 - sizeof(s32)];
    s32 unk34;
};

struct func_802A6D28_S1;
/* unbake published declaration: published_9e64b131ee5675d4071ba8f3 */
typedef struct func_802A6D28_S1 func_802A6D28_S1;

struct func_802A6F8C_S1;
/* unbake published declaration: published_a000c471d237a2001cf510bb */
typedef struct func_802A6F8C_S1 func_802A6F8C_S1;

struct Frame_func_802A7660_de;
/* unbake published declaration: published_a264a44ee9e5b3f1454fc18f */
typedef struct Frame_func_802A7660_de Frame_func_802A7660_de;

struct func_802A6AC0_S2;
/* unbake published declaration: published_a3e25e7b36adaeac21ef32b0 */
typedef struct func_802A6AC0_S2 func_802A6AC0_S2;

struct State802A6FE0;
/* unbake published declaration: published_a86847533c30834c42c1c2e5 */
typedef struct State802A6FE0 State802A6FE0;

struct func_802A7394_S1;
/* unbake published declaration: published_b573730d2cb69c0d1da68fb1 */
struct func_802A7394_S1 {
    char pad0[0x1C];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    f32 unk24;
};

struct func_802A7394_S1;
/* unbake published declaration: published_b615584791c38e583d6d62e5 */
typedef struct func_802A7394_S1 func_802A7394_S1;

struct Entry_func_802A70D4_de;
/* unbake published declaration: published_c6ca888af33151abd79bb9d0 */
struct Entry_func_802A70D4_de {
    char pad0[0x4];
    s32 active;
    char pad8[0x38 - 0x8];
};

struct Entry_func_802A70D4_de;
/* unbake published declaration: published_e36a550b56dca24be3740ffd */
typedef struct Entry_func_802A70D4_de Entry_func_802A70D4_de;

struct Menu_func_802A70D4_de;
/* unbake published declaration: published_becf9b09db06e5b363d756e4 */
struct Menu_func_802A70D4_de {
    Entry_func_802A70D4_de entries[4];
    char padE0[0xE4 - 0xE0];
    u16 cursor;
};

struct func_802A7440_S2;
/* unbake published declaration: published_bef61251a3c16df5be77c640 */
struct func_802A7440_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x1C - 0x4 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
};

/* unbake published declaration: published_c15e41cdc50be83247dcaaba */
extern float D_800C5EC4_de;

/* unbake published declaration: published_c51fdda09c2c61a8380942ba */
extern float D_800C5EBC_de;

struct Record_func_802A6F68_de;
/* unbake published declaration: published_c9657c835af1359a790be119 */
typedef struct Record_func_802A6F68_de Record_func_802A6F68_de;

struct State802A6FE0;
/* unbake published declaration: published_ce9f3bd587d1517aed31e908 */
struct State802A6FE0 {
    u8 pad0[8];
    Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};

/* unbake published declaration: published_cfadc7d4af2c5b2096043b60 */
extern void func_802A5AD0_de(void *arg0);

struct func_802A7480_S2;
/* unbake published declaration: published_d1a7589f141fd0cef11e7864 */
typedef struct func_802A7480_S2 func_802A7480_S2;

struct func_802A6D28_S2;
/* unbake published declaration: published_d9438c507df5ad6652b4ab22 */
typedef struct func_802A6D28_S2 func_802A6D28_S2;

/* unbake published declaration: published_dce90af4d866e246f5471608 */
extern void func_802A5B84_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

/* unbake published declaration: published_dde38349678b1e44ab7b8363 */
extern float D_800C5EB8_de;

struct func_802A72AC_S1;
/* unbake published declaration: published_de65e7e62b149c2897aad173 */
typedef struct func_802A72AC_S1 func_802A72AC_S1;

struct CallbackState1C;
/* unbake published declaration: published_e2902e896495a17cdf66f93f */
struct CallbackState1C {
    unsigned char padding_0[24];
    void (*callback)(void *);
};

/* unbake published declaration: published_e51b782ee5addc650ce81bc4 */
extern void func_802A5B4C_de(f32 *arg0);

struct Record_func_802A6F68_de;
/* unbake published declaration: published_e7a68b075731090482545f28 */
struct Record_func_802A6F68_de {
    unsigned char unk0;
    unsigned char unk1;
    char pad2[2];
    Entry_func_802A6F68_de entries[4];
    short unkE4;
    short unkE6;
    int unkE8;
};

struct func_802A7164_S1;
/* unbake published declaration: published_e8c11615472f55d7e4ef9b25 */
struct func_802A7164_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x1C - 0x10 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0xB0 - 0x1C - sizeof(f32)];
    void * unkB0;
};

/* unbake published declaration: published_eca532d11617d983ca9cb0b1 */
extern void func_802A754C_de(void);

/* unbake published declaration: published_ef0c4a07e4f42229d98e2195 */
extern float D_800C5EC0_de;

struct func_802A7480_S1;
/* unbake published declaration: published_ef0cc448422bcdc286d9a78d */
struct func_802A7480_S1 {
    char pad0[0x7528];
    char * unk7528;
};

struct Menu_func_802A70D4_de;
/* unbake published declaration: published_f2c2633fc8f382231acefcd5 */
typedef struct Menu_func_802A70D4_de Menu_func_802A70D4_de;

struct func_802A7480_S1;
/* unbake published declaration: published_f8c8daee91d211200caef06b */
typedef struct func_802A7480_S1 func_802A7480_S1;

struct func_802A7FA8_S3;
/* unbake published declaration: published_fb27a16d56bc3ddf35dc8e89 */
struct func_802A7FA8_S3 {
    char pad0[0xE4];
    s16 unkE4;
};

struct Input_func_802A65E0_de;
/* unbake published declaration: published_ffe5fe133465e828d692230e */
typedef struct Input_func_802A65E0_de Input_func_802A65E0_de;

#endif
