#ifndef UNBAKE_SPAN_1000_CODE_80279208_H
#define UNBAKE_SPAN_1000_CODE_80279208_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_00dd0fccf654b74d3115bddd */
extern int D_8011BF00;

struct List802795C0;
/* unbake published declaration: published_087d5300d4ad2534446d8273 */
struct List802795C0 {
    Link_func_802596B4_de *head;
    Link_func_802596B4_de *tail;
    int count;
};

struct ListHeader;
/* unbake published declaration: published_092805d34c088ce55d5e8807 */
typedef struct ListHeader ListHeader;

struct ListHeader;
/* unbake published declaration: published_122bd086ba5cb45423d3cbe9 */
struct ListHeader {
    void *head;
    void *tail;
    s32 count;
};

/* unbake published declaration: published_1abadd4b2e588410c3508585 */
extern s16 func_80279798_de(s16 *arg0);

struct Lists18;
/* unbake published declaration: published_1b8083c1178c41b45ad007d1 */
typedef struct Lists18 Lists18;

struct IntegerState5AC;
/* unbake published declaration: published_328fc093242eb778f1782254 */
typedef struct IntegerState5AC IntegerState5AC;

struct func_80279490_S1;
/* unbake published declaration: published_3bb9ec5bc2ac0d23930926d5 */
struct func_80279490_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0xA - 0x4 - sizeof(u16)];
    u16 unkA;
    char padA[0x11 - 0xA - sizeof(u16)];
    u8 unk11;
    char pad11[0x12 - 0x11 - sizeof(u8)];
    u8 unk12;
};

/* unbake published declaration: published_50c3643b6939049ddab56405 */
extern void func_802791F0_de(void *object);

struct Trigger;
/* unbake published declaration: published_53bd8e86579f683e50cd2ba6 */
typedef struct Trigger Trigger;

/* unbake published declaration: published_56114eb18ef1ea3684f46a88 */
extern void func_802794B0_de(ListHeader *list);

struct List802795C0;
/* unbake published declaration: published_d22ac26dc200c77fee80bbd0 */
typedef struct List802795C0 List802795C0;

struct Lists18;
/* unbake published declaration: published_5be44533bf335b2789e4bd79 */
struct Lists18 {
    List802795C0 active;
    List802795C0 inactive;
};

/* unbake published declaration: published_80164303a93f9dd2ff3475d5 */
extern void func_80279198_de(int arg0, int arg1, void *arg2);

/* unbake published declaration: published_84eff980f5cc975c41473d97 */
extern void func_802791D8_de(void *arg0);

struct WeightedTable;
/* unbake published declaration: published_88b18199528ea8fc83ba39f6 */
struct WeightedTable {
    s16 count;
    s16 entries[1][2];
};

struct ObjectLinks1BC;
/* unbake published declaration: published_90df49d039eb9e1e772e8620 */
typedef struct ObjectLinks1BC ObjectLinks1BC;

struct ObjectLinks1BC;
/* unbake published declaration: published_9c3814dd53268c8b329df5d0 */
struct ObjectLinks1BC {
    char pad0[0x4];
    u16 unk_4;
    char pad4[0x118 - 0x4 - sizeof(u16)];
    char * unk_118;
    char pad118[0x12C - 0x118 - sizeof(char*)];
    char * unk_12C;
    char pad12C[0x1B8 - 0x12C - sizeof(char*)];
    s8 unk_1B8;
    char pad1B8[0x1B9 - 0x1B8 - sizeof(s8)];
    s8 unk_1B9;
    char pad1B9[0x1BA - 0x1B9 - sizeof(s8)];
    s8 unk_1BA;
};

struct ObjectStateC4;
/* unbake published declaration: published_ad51a0d688494a66a1ef54e3 */
typedef struct ObjectStateC4 ObjectStateC4;

struct Actor_func_80279B40_de;
/* unbake published declaration: published_b67545914a800e877cb6f24c */
struct Actor_func_80279B40_de {
    char pad0[8];
    Vec3 position;
    char pad14[8];
    Vec3 facing;
    char pad28[0x34];
    s32 flags;
    char pad60[0xB8];
    func_8021CD70_S3 *def;
    char pad11C[0x10];
    void *owner;
    s32 unk130;
    s32 unk134;
    char pad138[0x48];
    f32 offsetX;
    f32 offsetY;
    s32 angle;
};

/* unbake published declaration: published_c0a7fe0e5ce3ee521fd3c42c */
extern void func_802795B0_de(ListHeader *lists, void *pool, s32 stride, s32 count);

struct ObjectStateC4;
/* unbake published declaration: published_c530d6098a18bff6c07412c2 */
struct ObjectStateC4 {
    unsigned char padding_0[190];
    u16 unk_BE;
    unsigned char padding_C0[2];
    u16 unk_C2;
};

/* unbake published declaration: published_d227a9003d7a139cf7bf59f8 */


/* unbake published declaration: published_d4132126e601549167ec27d1 */
extern void func_802791B8_de(void *arg0);

struct func_80279490_S1;
/* unbake published declaration: published_e0ad98f17f9e3fb2fde6d703 */
typedef struct func_80279490_S1 func_80279490_S1;

struct Actor_func_80279B40_de;
/* unbake published declaration: published_e23130f14d507b4bd10b5378 */
typedef struct Actor_func_80279B40_de Actor_func_80279B40_de;

struct Trigger;
/* unbake published declaration: published_e36632acc63bb9ae76bf56e5 */
struct Trigger {
    s32 mask;
    s32 unk4;
    s32 unk8;
    union {
        s32 word;
        struct {
            u16 unkC;
            u8 state;
            u8 id;
        } bytes;
    } flags;
    s32 unk10;
};

struct WeightedTable;
/* unbake published declaration: published_e66627ffbf35581ea8a5527e */
typedef struct WeightedTable WeightedTable;

struct IntegerState5AC;
/* unbake published declaration: published_f8aad96d8c9239c9c64a73cc */
struct IntegerState5AC {
    char pad0[0x59C];
    s32 unk_59C;
    char pad59C[0x5A4 - 0x59C - sizeof(s32)];
    s32 unk_5A4;
    char pad5A4[0x5A8 - 0x5A4 - sizeof(s32)];
    s32 unk_5A8;
};

extern void func_802794A4_de(void * arg0);
#endif
