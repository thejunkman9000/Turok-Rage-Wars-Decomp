#include "b18_types.h"

typedef struct B18Info {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
} B18Info;

typedef struct B18Actor {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0xFC];
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ B18Info *unk118;
} B18Actor;

extern s32 D_801450B8;
extern s32 D_800D297C;
extern u8 D_8011FFB0[];
extern u8 D_800C9E28[];
extern u8 D_800C9E40[];
extern u8 D_800C9E58[];

s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
void func_002536F4(s32 a, s32 *b);
void func_002537D8(s32 a, s32 *b);
s32 *func_00254094(s32 a, s32 **b, s32 c, void *d, s32 e);
void func_0026D7F4();
void func_0026DC24(s32 *a, s32 b, s32 c, void *d, s32 e, s32 f);
void func_00272908(void *a, void *b, Vec3f *c);
s32 func_00279A30(void *a, s32 b);
void func_0027DD1C(B18Actor *a, s32 b, void *c, f32 d);
s32 func_0028FE08(s32 a, s32 b, s32 c);
s32 func_0028FE1C(s32 *a, s32 b, s32 c, void *d);

void func_0027EB00(B18Actor *o, u8 *b) {
    Vec3f v;
    s32 *sp38;
    s32 *p;
    s32 *q;
    s32 s3;
    s32 s1;
    s32 zero;
    f32 f;

    zero = 0;
    if (D_801450B8 == 1) {
        s3 = (s32)((u8 *)o + ((D_800D297C << 6) + 0x60));
    } else {
        s3 = func_00279A30(D_8011FFB0, 1);
        if (s3 == 0) return;
        func_00272908(b + 0x220, &o->pos, &v);
        f = v.z;
        if (f < 0.0f) f = -f;
        func_0027DD1C(o, s3, b, f);
    }
    if (o->unk110 == 0) {
        p = func_002518DC(0, o->unk118->unk14, o->unk118->unk14, 0x18, 0, 0, 0, D_800C9E28, 1);
        if (p != NULL) {
            s1 = func_0028FE08(*p, o->unk118->unk14, 1);
            func_002537D8(0, p);
            q = func_00254094(0, &sp38, s1, D_800C9E40, 1);
            if (q != NULL) {
                o->unk110 = func_0028FE1C(sp38, s1, zero % *sp38, &o->unk114);
                func_002537D8(0, q);
            }
        }
        if (o->unk110 == 0) return;
    }
    p = func_002518DC(0, o->unk110, o->unk110, o->unk114, 0, 0, (void *)func_0026D7F4, D_800C9E58, 1);
    if (p != NULL) {
        func_0026DC24(p, s3, 0, (u8 *)o + (D_800D297C * 0x18 + 0xE0), 0, -1);
        func_002536F4(0, p);
    }
}
