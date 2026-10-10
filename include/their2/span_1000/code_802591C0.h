#ifndef UNBAKE_SPAN_1000_CODE_802591C0_H
#define UNBAKE_SPAN_1000_CODE_802591C0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
union func_802598D4_S1_UD8;
/* unbake published declaration: published_001a4f692a4c78f5e298ebc4 */
typedef union func_802598D4_S1_UD8 func_802598D4_S1_UD8;

struct ListNode;
/* unbake published declaration: published_502cc8bcd0258769daff0423 */
struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    unsigned char pad08[0xB4];
    s32 valueBC;
};

struct ListNode;
/* unbake published declaration: published_d19b8dffe404a651048d2075 */
typedef struct ListNode ListNode;

struct ListNode;
union func_80259A0C_S1_UD8;
/* unbake published declaration: published_097ebf7323f0238152f0771a */
union func_80259A0C_S1_UD8 {
    ListNode v0;
    struct ListNode * v1;
};

struct Node_func_80259A50_de;
/* unbake published declaration: published_5fda9b5b781a2dde5de7d69a */
typedef struct Node_func_80259A50_de Node_func_80259A50_de;

struct Node_func_80259A50_de;
/* unbake published declaration: published_748022fcc59e7ae54f9036ac */
struct Node_func_80259A50_de {
    struct Node_func_80259A50_de *prev;
    struct Node_func_80259A50_de *next;
    char pad8[0xA4];
    s32 flags;
};

struct Lists;
/* unbake published declaration: published_115cda89196590cb47896dea */
struct Lists {
    char pad0[4];
    Node_func_80259A50_de first;
    char padB4[0x24];
    Node_func_80259A50_de second;
};

struct func_80259AD8_S1;
/* unbake published declaration: published_1257edcaa0e018bc94ac1346 */
typedef struct func_80259AD8_S1 func_80259AD8_S1;

struct Voice_func_802596B4_de;
/* unbake published declaration: published_142777172804316eae0f6c38 */
typedef struct Voice_func_802596B4_de Voice_func_802596B4_de;

/* unbake published declaration: published_1672b4a77b361e7c718f490e */
extern void func_802591D0_de(void *arg0, s16 arg1);

struct Manager_func_80259784_de;
/* unbake published declaration: published_1721620996602a218a793055 */
typedef struct Manager_func_80259784_de Manager_func_80259784_de;

struct func_802598D4_S1;
/* unbake published declaration: published_20cd90f7d3d8a06b6237e329 */
typedef struct func_802598D4_S1 func_802598D4_S1;

struct ObjectLinks8;
/* unbake published declaration: published_266766ed3bbe488dd0c115fb */
typedef struct ObjectLinks8 ObjectLinks8;

struct Lists;
/* unbake published declaration: published_2987c8e82d106bdbffe21370 */
typedef struct Lists Lists;

struct Link_func_80259784_de;
/* unbake published declaration: published_2b0609e06ae7a514e3b3ae6d */
typedef struct Link_func_80259784_de Link_func_80259784_de;

struct Node_func_80259784_de;
/* unbake published declaration: published_aeb762cfb3bd5853e4d98e92 */
struct Node_func_80259784_de {
    struct Node_func_80259784_de *prev;
    struct Node_func_80259784_de *next;
    char pad8[0x14];
    s32 timer;
    char pad20[0x20];
    s16 priority;
    char pad42[6];
    s32 owner;
    Vec3 position;
};

struct Link_func_80259784_de;
struct Node_func_80259784_de;
/* unbake published declaration: published_48a8dcb7abeff79a7f5e39e4 */
struct Link_func_80259784_de {
    struct Node_func_80259784_de *prev;
    struct Node_func_80259784_de *next;
};

struct Entry_func_80259784_de;
/* unbake published declaration: published_605cf6be127283657f98cab0 */
typedef struct Entry_func_80259784_de Entry_func_80259784_de;

struct Entry_func_80259784_de;
/* unbake published declaration: published_c7a3638dd50fd5fd97869a15 */
struct Entry_func_80259784_de {
    char pad0[0xAC];
    s32 busy;
    char padB0[0x1C];
};

struct Scene_func_80259784_de;
struct Scene_func_80259784_de {
    char pad0[0x1DBC];
    Entry_func_80259784_de entries[1];
};
struct Manager_func_80259784_de;
struct Scene_func_80259784_de;
/* unbake published declaration: published_2e290abdee8fb68cd6991931 */
struct Manager_func_80259784_de {
    struct Scene_func_80259784_de *scene;
    Link_func_80259784_de active;
    char padC[0xCC];
    Link_func_80259784_de free;
};

struct func_802597A4_S2;
/* unbake published declaration: published_2e563408af85e79b56cb3cd3 */
struct func_802597A4_S2 {
    char pad0[0x2A84];
    s32 unk2A84;
    char pad2A84[0x2A88 - 0x2A84 - sizeof(s32)];
    s32 unk2A88;
    char pad2A88[0x2AB4 - 0x2A88 - sizeof(s32)];
    s16 unk2AB4;
    char pad2AB4[0x2AB6 - 0x2AB4 - sizeof(s16)];
    s16 unk2AB6;
};

struct ObjectLinks8;
/* unbake published declaration: published_300b1a37f6001d6499c33953 */
struct ObjectLinks8 {
    void *unk_0;
    void *unk_4;
};

union func_80259A0C_S1_UD8;
/* unbake published declaration: published_3d84059681212c3395eea816 */
typedef union func_80259A0C_S1_UD8 func_80259A0C_S1_UD8;

/* unbake published declaration: published_3e1e343800b6c8fe55e6f2c4 */
extern float D_800C8FF8;

struct Node_func_80259918_de;
/* unbake published declaration: published_62db4dc3a5e8f969523b2f96 */
struct Node_func_80259918_de {
    struct Node_func_80259918_de *prev;
    struct Node_func_80259918_de *next;
    char pad08[0xB0 - 0x8];
    s32 key;
};

struct Node_func_80259918_de;
struct Owner_func_80259918_de;
/* unbake published declaration: published_417e20a9cf7369c203cae13b */
struct Owner_func_80259918_de {
    s32 unk00;
    struct Node_func_80259918_de *activePrev;
    struct Node_func_80259918_de *activeNext;
    char pad0C[0xD8 - 0xC];
    struct Node_func_80259918_de *otherPrev;
};

struct Glyphs;
/* unbake published declaration: published_495c5734e7d80c4f47d9c79d */
struct Glyphs {
    char pad0[0x10];
    s32 bitmaps[1];
};

struct Font;
struct Glyphs;
struct Font {
    char pad0[0xC];
    struct Glyphs *glyphs;
};
struct Context_func_80259440_de;
struct Font;
/* unbake published declaration: published_487d690c0f388fdbf6f39a50 */
struct Context_func_80259440_de {
    char pad0[0x7C];
    struct Font *font;
    char pad80[4];
    char textures[0xDC - 0x84];
    s16 slots[16];
    char padFC[0x104 - 0xFC];
    s32 frame;
    s32 sequence;
    char pad10C[0x1DB8 - 0x10C];
    char cells[1];
};

struct Slot_func_80259200_de;
/* unbake published declaration: published_49ea0bbdb74980456f2b8980 */
struct Slot_func_80259200_de {
    int id;
    char pad[0xC8];
};

struct Cache;
/* unbake published declaration: published_567b9a1a2c21f5a9602c41a5 */
typedef struct Cache Cache;

/* unbake published declaration: published_57d578f98e8ba0be55057e3e */
extern float D_800C3F00_de;

struct Node_func_802598B4_de;
/* unbake published declaration: published_5e67d03a9f57c8e5f6d5c407 */
struct Node_func_802598B4_de {
    struct Node_func_802598B4_de *prev;
    struct Node_func_802598B4_de *next;
    s32 unused;
    s32 value;
};

/* unbake published declaration: published_5f332b03d709ca04b7fdae7b */
extern void func_80259AF0_de(void **arg0, void *arg1);

struct Slot_func_80259200_de;
/* unbake published declaration: published_bf6cf7eaae75178b154b9f0e */
typedef struct Slot_func_80259200_de Slot_func_80259200_de;

struct Obj_func_80259200_de;
/* unbake published declaration: published_696849ca0742b871478fdd3d */
struct Obj_func_80259200_de {
    char pad[0x102];
    short owner;
    char pad104[0x1E64 - 0x104];
    Slot_func_80259200_de slots[17];
};

struct func_80259B30_S1;
/* unbake published declaration: published_6a6a423b97c7f96333471b0c */
typedef struct func_80259B30_S1 func_80259B30_S1;

struct ObjectLinks2B50;
/* unbake published declaration: published_742f7ea1aa34733c00ec3658 */
typedef struct ObjectLinks2B50 ObjectLinks2B50;

struct Cell_func_80259440_de;
/* unbake published declaration: published_7563390e5cf5548c41bfb4c4 */
struct Cell_func_80259440_de {
    s32 index;
    s32 pad4;
    s32 texture;
    s32 sequence;
    s32 frame;
    char pad14[0x44 - 0x14];
    char data[1];
};

struct Node_func_802598B4_de;
/* unbake published declaration: published_ce5e18296db8e68e91faaedc */
typedef struct Node_func_802598B4_de Node_func_802598B4_de;

struct Node_func_802598B4_de;
union func_802598D4_S1_UD8;
/* unbake published declaration: published_9d2214782f6118274ad3bb19 */
union func_802598D4_S1_UD8 {
    Node_func_802598B4_de v0;
    struct Node_func_802598B4_de * v1;
};

struct func_802598D4_S1;
/* unbake published declaration: published_7841c9b11c13695f3a9aef88 */
struct func_802598D4_S1 {
    char pad0[0x4];
    union { Node_func_802598B4_de node; struct { void *first; Node_func_802598B4_de *second; } links; } at4;
    char pad14[0xD8 - 0x4 - sizeof(Node_func_802598B4_de)];
    func_802598D4_S1_UD8 unkD8;
};

struct Entry_func_80259440_de;
/* unbake published declaration: published_7b37d0fd4bcd29747068efa5 */
struct Entry_func_80259440_de {
    struct Entry_func_80259440_de *prev;
    struct Entry_func_80259440_de *next;
    char body[0x10];
    s32 frame;
    s32 delay;
    char pad20[0x40 - 0x20];
    s16 glyph;
    s16 font;
    s16 style;
    s16 pad46;
    s32 sequence;
    char pad4C[0xA8 - 0x4C];
    s32 fieldA8;
};

struct Node_func_80259260_de;
/* unbake published declaration: published_8eb1b4b264b47b0ffd8bfbe7 */
struct Node_func_80259260_de {
    struct Node_func_80259260_de *prev;
    struct Node_func_80259260_de *next;
    char channel[4];
    s32 volume;
    char pad10[4];
    s32 handle;
    s32 frame;
    s32 sample;
    s32 gainA;
    s32 gainB;
    s16 pitch;
    char pad2A[2];
    s32 time;
    char pad30[0x10];
    s16 priority;
    s16 group;
    s16 volume16;
    char pad46[2];
    s32 voice;
    Vec3Words position;
    s32 pad58;
    u8 pan;
    char pad5D[0x4F];
    s32 flags;
    char padB0[4];
    s32 padB4;
    char padB8[0x10];
    s32 mix;
};

struct Link_func_80259260_de;
struct Node_func_80259260_de;
/* unbake published declaration: published_818a2c8ae5432ac7e1c6b8d3 */
struct Link_func_80259260_de {
    struct Node_func_80259260_de *prev;
    struct Node_func_80259260_de *next;
};

struct func_80259280_S1;
/* unbake published declaration: published_84344fc8602f36399d1c33d9 */
typedef struct func_80259280_S1 func_80259280_S1;

struct func_80259AD8_S2;
/* unbake published declaration: published_883a824d31f670c07901b652 */
typedef struct func_80259AD8_S2 func_80259AD8_S2;

struct Cell_func_80259440_de;
/* unbake published declaration: published_88d936c1e1c189ac2d3767c2 */
typedef struct Cell_func_80259440_de Cell_func_80259440_de;

struct Obj_func_80259200_de;
/* unbake published declaration: published_efbf652372ec88824953d56a */
typedef struct Obj_func_80259200_de Obj_func_80259200_de;

/* unbake published declaration: published_8ff8c7d543c818a9caa0ec15 */
extern int func_80259200_de(Obj_func_80259200_de *obj, int id);

struct func_80259AD8_S1;
/* unbake published declaration: published_927fce82b7f95d7c71fc3d21 */
struct func_80259AD8_S1 {
    char pad0[0x4];
    char unk4;
    char pad4[0x8 - 0x4 - sizeof(char)];
    void * unk8;
};

struct Link_func_80259260_de;
/* unbake published declaration: published_978986e41efd3d9d8d37a939 */
typedef struct Link_func_80259260_de Link_func_80259260_de;

struct Manager_func_80259260_de;
/* unbake published declaration: published_939627cc527fc8b35cdcb4fb */
struct Manager_func_80259260_de {
    s32 *scene;
    Link_func_80259260_de active;
    char padC[0xCC];
    Link_func_80259260_de free;
};

struct Node_func_80259918_de;
/* unbake published declaration: published_9717294d9aec3a5026dbec18 */
typedef struct Node_func_80259918_de Node_func_80259918_de;

struct Manager_func_80259260_de;
/* unbake published declaration: published_97df711adabcca87b7e47a5d */
typedef struct Manager_func_80259260_de Manager_func_80259260_de;

struct Voice_func_802596B4_de;
/* unbake published declaration: published_9e9f0a56901be0aab99056e3 */
struct Voice_func_802596B4_de {
    Link_func_802596B4_de link;
    Header header;
};

struct ChannelSet;
/* unbake published declaration: published_a1cbc6482ba3376a38d067c3 */
struct ChannelSet {
    s32 owner;
    Link_func_802596B4_de free;
    Header freeHeader;
    Link_func_802596B4_de active;
    Header activeHeader;
    Voice_func_802596B4_de voices[32];
};

struct func_80259280_S1;
/* unbake published declaration: published_a34171ce4686d207806f67e0 */
struct func_80259280_S1 {
    char pad0[0x2B8C];
    s16 unk2B8C;
};

/* unbake published declaration: published_a4f8ff6ffd32a7c8ff382bf6 */
extern void func_802598B4_de(void *arg0, s32 arg1);

struct Node_func_80259260_de;
/* unbake published declaration: published_ad3c4827d2728bfb4d728778 */
typedef struct Node_func_80259260_de Node_func_80259260_de;

struct Entry_func_80259440_de;
struct ListHead;
/* unbake published declaration: published_cdefd1552e1e80053692a005 */
struct ListHead {
    struct Entry_func_80259440_de *prev;
    struct Entry_func_80259440_de *next;
};

struct ListHead;
/* unbake published declaration: published_fac4ffb6555a22d3dba001fb */
typedef struct ListHead ListHead;

struct Cache;
struct Context_func_80259440_de;
/* unbake published declaration: published_af5efcf873a2c3ae91171a00 */
struct Cache {
    struct Context_func_80259440_de *context;
    ListHead pending;
    char padC[0xD8 - 0xC];
    ListHead done;
};

struct func_80259AD8_S2;
/* unbake published declaration: published_b4673de93cfe73fac556c999 */
struct func_80259AD8_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xB0 - 0x4 - sizeof(void*)];
    int unkB0;
};

struct func_80259B30_S1;
/* unbake published declaration: published_c386f089c6fd15210923cc95 */
struct func_80259B30_S1 {
    char pad0[0x128];
    Vec3 unk128;
    char pad128[0x160 - 0x128 - sizeof(Vec3)];
    char unk160;
};

struct Owner_func_80259918_de;
/* unbake published declaration: published_c543b3833ab44cb0e90310a1 */
typedef struct Owner_func_80259918_de Owner_func_80259918_de;

struct func_802597A4_S2;
/* unbake published declaration: published_c612121a34f32b306062d321 */
typedef struct func_802597A4_S2 func_802597A4_S2;

struct Entry_func_80259440_de;
/* unbake published declaration: published_cfd14f875a12311f77d05407 */
typedef struct Entry_func_80259440_de Entry_func_80259440_de;

struct func_80259A0C_S1;
/* unbake published declaration: published_d3c6831c1957902c1e5ef977 */
typedef struct func_80259A0C_S1 func_80259A0C_S1;

struct Node_func_80259784_de;
/* unbake published declaration: published_d896509e22e4fbc1ca56b7a4 */
typedef struct Node_func_80259784_de Node_func_80259784_de;

struct func_80259A0C_S1;
/* unbake published declaration: published_dbfc6b3ded26a79ee8f48e9d */
struct func_80259A0C_S1 {
    char pad0[0x4];
    union { ListNode node; struct { void *first; ListNode *second; } links; } at4;
    char padC4[0xD8 - 0x4 - sizeof(ListNode)];
    func_80259A0C_S1_UD8 unkD8;
};

struct LinkPair;
/* unbake published declaration: published_e14ae69502fe9b62a04fd233 */
typedef struct LinkPair LinkPair;

struct Glyphs;
/* unbake published declaration: published_e6fe388277061de560e671c2 */
typedef struct Glyphs Glyphs;

struct Context_func_80259440_de;
/* unbake published declaration: published_e86369f549d03b8aae25e86a */
typedef struct Context_func_80259440_de Context_func_80259440_de;

/* unbake published declaration: published_ec0a70a6c9fb633999dcebbb */
extern void func_802591A0_de(void *arg0, s16 arg1);

struct LinkPair;
/* unbake published declaration: published_ee139ce2d8a5e57026bd59e7 */
struct LinkPair {
    void **first;
    void **second;
};

struct ObjectLinks2B50;
/* unbake published declaration: published_fe7c20cdd97ddea70c088c7e */
struct ObjectLinks2B50 {
    unsigned char padding_0[11084];
    void *unk_2B4C;
};

struct ChannelSet;
/* unbake published declaration: published_ff26fe59283d4eb69c5b5298 */
typedef struct ChannelSet ChannelSet;

#endif
