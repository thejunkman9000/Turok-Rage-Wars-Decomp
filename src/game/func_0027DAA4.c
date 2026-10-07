#include "b18_types.h"

typedef struct B18Owner {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
} B18Owner;

typedef struct B18Parent {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x60];
    /* 0x074 */ u8 unk74[0x8C];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0xD4];
    /* 0x1D8 */ B18Owner *owner;
} B18Parent;

typedef struct B18Src {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ u8 pad14[0xA0];
    /* 0xB4 */ u8 *unkB4;
} B18Src;

typedef struct B18Mover {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[4];
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x24];
    /* 0x04C */ u8 pad4C[4];
    /* 0x050 */ Vec3f unk50;
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xCC];
    /* 0x12C */ B18Parent *parent;
    /* 0x130 */ u8 pad130[4];
    /* 0x134 */ B18Src *src;
    /* 0x138 */ u8 pad138[0x39];
    /* 0x171 */ u8 pad171[3];
    /* 0x174 */ Vec3f unk174;
    /* 0x180 */ u8 pad180[0x51];
    /* 0x1D1 */ s8 unk1D1;
} B18Mover;

void func_00226DAC(B18Owner *a, void *out);
void func_00270980(void *out, void *m);
void func_00272908(void *m, Vec3f *in, Vec3f *out);
void func_00272BA8(void *m, Vec3f *in, Vec3f *out);

void func_0027DAA4(B18Mover *o, Vec3f *out1, Vec3f *out2) {
    u8 mtx10[0x40];
    Vec3f sp50;
    Vec3f sp60;
    u8 mtx70[0x40];
    B18Src *src;
    u8 *m;

    sp50 = o->pos;
    sp60 = o->unk1C;
    if (o->flags & 0x10000) {
        src = o->src;
        switch (o->type) {
        case 2:
        case 0xB:
        case 0xF:
        case 0x2D:
        case 0x4F:
        case 0x56:
        case 0x126:
        case 0x12A:
        case 0x132:
        case 0x41E:
            if (src->unkB4 != 0) {
                func_00270980(mtx10, src->unkB4 + (o->unk1D1 << 6));
                func_00272908(mtx10, &o->unk50, &sp50);
                func_00272BA8(mtx10, &o->unk1C, &sp60);
                o->pos = sp50;
                o->unk174 = sp60;
            } else {
                sp50 = src->pos;
                o->pos = sp50;
            }
            break;
        }
        o->unk14 = 0;
    }
    if (o->flags & 0x400000) {
        B18Parent *p = o->parent;
        void *mm;
        if (p->flags100 & 0x300000) {
            B18Owner *ow = p->owner;
            if (ow->unk5DC != 0) {
                mm = ow->unk5DC + 0x160;
            } else {
                func_00226DAC(ow, mtx70);
                mm = mtx70;
            }
        } else {
            mm = p->unk74;
        }
        func_00272908(mm, &o->unk50, &sp50);
        o->pos = sp50;
    }
    if (out1 != NULL) {
        *out1 = sp50;
    }
    if (out2 != NULL) {
        *out2 = sp60;
    }
}
