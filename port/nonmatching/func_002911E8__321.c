#include "b20_types.h"

typedef struct Slot Slot;
struct Slot {
    u8 pad0[0xF0];
    s16 unkF0;
    u8 padF2[0x1E];
    s32 unk110;
    u8 pad114[0x18];
    Slot *prev;
    Slot *next;
    u8 pad134[0xC];
};

void *memset(void *p, s32 c, u32 n);
void func_0028F734(u8 *vid, void *sp, s32 pri, s32 unused, u8 retrace);
void func_0028F844(u8 *vid, u8 *node, s32 v);
void func_00293574(Level *lv);
void func_00264B64(void);
void func_00444030(u8 *p);
void func_00244D60(void);
void func_0044E910(void);
void func_0044E8B0(u8 *p);
void func_002909E0(Slot *o);
void func_00293038(Level *lv);
void func_0025DE50(void);
extern OSMesgQueue D_80146980;
extern OSMesg D_80146D78[];
extern u8 D_800F3C80[];
extern u8 D_801469E8[];
extern s32 D_800D2B38;
extern u8 D_8014AD80[];
extern s32 D_80110634;
extern f32 D_80146D20[];
extern s32 D_8014D330;
extern u8 D_801462C8[];
extern u32 D_800E28A0;
typedef struct { u8 pad[0x88]; s32 a88; s32 a8C; } R07Blk;
extern R07Blk D_801468A0[];
extern s32 D_801536F8[];

void func_002911E8(Level *lv) {
    u32 i;
    Slot *sl;
    u32 a;
    u32 b;
    u32 dm1, dp1;
    osCreateMesgQueue(&D_80146980, D_80146D78, 0x1000);
    memset(D_800F3C80, 7, 0x2000);
    func_0028F734(D_801469E8, D_800F3C80 + 0x2000, D_800D2B38, 0, 1);
    func_0028F844(D_801469E8, D_8014AD80, (s32)&D_80146980);
    lv->unk26DB4 = -1;
    func_00293574(lv);
    D_80110634 = 0;
    guMtxIdent(D_80146D20);
    if (D_8014D330 != 0) {
        func_00264B64();
        func_00444030(D_801462C8);
    }
    func_00244D60();
    i = 0;
    func_0044E910();
    func_0044E8B0(&lv->unk26D8C);
    lv->unk26DD0 = 0;
    lv->unk26DC8 = 1;
    lv->unk26DCC = 0;
    lv->unk26DD4 = 0;
    D_801468A0->a88 = 0;
    D_801468A0->a8C = 0;
    sl = (Slot *)lv;
    while (i < D_800E28A0) {
        dm1 = D_800E28A0 - 1;
        a = (i + dm1) % D_800E28A0;
        dp1 = D_800E28A0 + 1;
        b = (i + dp1) % D_800E28A0;
        sl[i].unkF0 = 2;
        sl[i].unk110 = D_801536F8[i];
        sl[i].prev = &((Slot *)lv)[a];
        sl[i].next = &((Slot *)lv)[b];
        func_002909E0(&sl[i]);
        i++;
    }
    func_00293038(lv);
    func_0025DE50();
}
