#include "b08_types.h"

typedef struct CamObj {
    u8 pad0[0x70];
    f32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
    u8 pad80[0x1E0];
    Vec3f unk260;
    u8 pad26C[0xFC];
    f32 unk368;
    f32 unk36C;
    f32 unk370;
    f32 unk374;
    f32 unk378;
    f32 unk37C;
    u8 pad380[0x1A8];
    f32 unk528;
    u8 pad52C[0x4];
    f32 unk530;
} CamObj;

void func_002729B4(void *a, Vec3f *v, void *b, s32 n);
void func_002975B0(void *a, void *b, void *c, void *d, void *e, void *f);
void func_002759C4(void *a, s32 n, void *b);

extern u8 D_801462E5;

void func_00234DD0(CamObj *o) {
    Vec3f v[5];
    f32 r;
    f32 a, b, c;
    f32 half;
    void *p;

    if (o->unk7C != 0) {
        if (D_801462E5 == 0) {
            r = o->unk528 / cosf(o->unk530 * o->unk70 * 0.008726647f);
            v[0].x = 0;
            v[0].y = 0;
            v[0].z = 0;
            v[1].x = r * sinf(o->unk530 * o->unk70 * 0.008726647f);
            v[1].y = v[1].x / o->unk70;
            v[2].x = -v[1].x;
            v[2].y = v[1].y;
            v[3].x = v[1].x;
            v[3].y = -v[1].y;
            v[4].x = -v[1].x;
            v[4].y = -v[1].y;
            c = -o->unk528;
            v[1].z = c;
            v[2].z = c;
            v[3].z = c;
            v[4].z = c;
        } else {
            v[0].x = 0;
            v[0].y = 0;
            v[0].z = 0;
            a = o->unk74 * 0.5f;
            v[1].x = a;
            b = o->unk78 * 0.5f;
            v[1].y = b;
            v[2].x = -a;
            v[2].y = b;
            c = -o->unk528;
            v[3].x = a;
            v[3].y = -b;
            v[4].x = -a;
            v[4].y = -b;
            v[1].z = c;
            v[2].z = c;
            v[3].z = c;
            v[4].z = c;
            r = b08_sqrtf(a * a + b * b + c * c);
        }
        p = &o->unk260;
        func_002729B4((u8 *)o + 0x160, v, p, 5);
        func_002975B0((u8 *)o + 0x2F0, p, (u8 *)o + 0x26C, (u8 *)o + 0x278, (u8 *)o + 0x284, (u8 *)o + 0x290);
        func_002759C4((u8 *)o + 0x350, 5, p);
        half = r * 1.5f;
        o->unk368 = o->unk260.x - r;
        o->unk374 = o->unk260.x + r;
        o->unk370 = o->unk260.z - r;
        o->unk37C = o->unk260.z + r;
        o->unk36C = o->unk260.y - half;
        o->unk378 = o->unk260.y + half;
    }
}
