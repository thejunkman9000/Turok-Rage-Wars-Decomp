#include "b23_types.h"

typedef struct Blk2C {
    s32 w[11];
} Blk2C;

typedef struct Blk14 {
    s32 w[5];
} Blk14;

typedef struct Tmpl2990 {
    /* 0x00 */ Blk2C head;
    /* 0x2C */ Blk14 tail;
} Tmpl2990;

typedef struct Sub2990 {
    u8 pad0[0x38];
    void *unk38;
} Sub2990;

typedef struct Obj2990 {
    /* 0x00 */ Blk2C head;
    /* 0x2C */ Blk14 tail;
    /* 0x40 */ u8 pad40[4];
    /* 0x44 */ Sub2990 *sub;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ u8 pad60[0xC];
} Obj2990;

s32 func_0029A958();
s32 func_00411E4C(s32 a);
Tmpl2990 *func_0040ECB0(s32 a, s32 b);
s32 func_00252FFC(s32 n);
void func_002A1748(void *p, s32 v, s32 n);
void func_002A2B24(Obj2990 *o, s32 n);
void func_0040EF24(Tmpl2990 *t, Obj2990 *o);
void func_0040F004(s32 a, Tmpl2990 *t, Obj2990 *o);

Obj2990 *func_002A2990(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    Tmpl2990 *t;
    Obj2990 *o;
    s32 s2;

    t = func_0040ECB0(func_00411E4C(func_0029A958()), a0 & 0xFFFF);
    s2 = func_00411E4C(func_0029A958());
    o = (Obj2990 *)func_00252FFC(0x6C);
    func_002A1748(o, 0, 0x6C);
    o->head = t->head;
    *(u16 *)((u8 *)o + 0xE) = 0xB65;
    o->tail = t->tail;
    o->sub = (Sub2990 *)func_0040ECB0(s2, a1 & 0xFFFF);
    o->sub->unk38 = (u8 *)o + 0x60;
    o->unk4C = a3;
    o->unk50 = a2;
    o->unk58 = 0;
    o->unk48 = 0;
    o->unk54 = a4;
    func_002A2B24(o, a2);
    o->unk5C = 2;
    func_0040EF24(t, o);
    *(s16 *)((u8 *)t + 0xC) = -1;
    func_0040F004(s2, t, o);
    return o;
}
