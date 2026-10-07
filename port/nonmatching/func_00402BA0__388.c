#include "q01_types.h"
typedef struct Q01Out { u8 pad0[0x29C]; f32 f29C, f2A0, f2A4, f2A8; } Q01Out;
typedef struct Q01Anim {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x18];
    s32 unk38;
    u8 pad3C[0x24];
    s32 unk60;
    f32 f64;
} Q01Anim;
typedef struct Q01F3 { f32 x, y, z; } Q01F3;
extern Q01Anim *D_800E2830;
extern s32 D_800E2844;
extern u8 D_8011FAC0[];
void func_00293100(void *a, s8 *b, u32 c, u32 d, u32 e, u32 f);
void func_00401564(Q01F3 *v, f32 f);
f32 func_0040170C(f32 f);
void func_0040293C();

void func_00402BA0(Q01Out *arg0) {
    Q01F3 v18;
    Q01F3 v28;
    s8 b[4];
    u32 s0, s1, s2, s3;
    f32 ft, t, v;
    if (D_800E2830->unk38 != 0) {
        s1 = (u32)arg0->f2A4;
        s0 = (u32)arg0->f2A8;
        s3 = (u32)((f32)s1 + arg0->f29C);
        s2 = (u32)((f32)s0 + arg0->f2A0);
        func_00401564(&v28, D_800E2830->f1C);
        ft = func_0040170C(D_800E2830->f1C);
        v18 = v28;
        if (D_800E2830->unk60 != 0) {
            t = D_800E2830->f64;
            if (t < 0.0f) t = 0.0f;
            v18.x = v28.x * t;
            v18.y = v28.y * t;
            v18.z = v28.z * t;
            ft += 1.0f - t;
        }
        v = v18.x * 255.0f;
        if (!(v <= 255.0f)) v = 255.0f;
        if (!(v >= 0.0f)) v = 0.0f;
        b[0] = (u32)v;
        v = v18.y * 255.0f;
        if (!(v <= 255.0f)) v = 255.0f;
        if (!(v >= 0.0f)) v = 0.0f;
        b[1] = (u32)v;
        v = v18.z * 255.0f;
        if (!(v <= 255.0f)) v = 255.0f;
        if (!(v >= 0.0f)) v = 0.0f;
        b[2] = (u32)v;
        v = ft * 255.0f;
        if (!(v <= 255.0f)) v = 255.0f;
        if (!(v >= 0.0f)) v = 0.0f;
        b[3] = (u32)v;
        func_00293100(D_8011FAC0, b, s1, s0, s3, s2);
    }
    if (D_800E2844 != 0) func_0040293C();
}
