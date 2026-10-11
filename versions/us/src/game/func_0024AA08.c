
#include "b11_types.h"
#include "m03_types.h"

extern f32 D_800D15F0;
extern s32 D_800D15E0;
extern s32 D_800D297C;
extern u8 D_8011FFB0[];
extern u8 D_8013B1A8[];
f32 sqrtf(f32);
s32 func_0024E148();
f32 func_0024E640(Obj *a, s32 b);
void func_0024ADC0(Obj *a, M03V3 *off, s32 flag);
void func_0024BA6C(Obj *a, void *b, s32 m, s32 flag);
void func_00268A40(void *a, f32 x, f32 y, f32 z, M03V3 *dir, f32 *r);
void func_0026F690(s32 a, void *b, void *c);
void func_002720EC(M03V3 *v);
void func_0027317C(void *m, M03V3 *dir, f32 ty);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_00273618(void *m, f32 x, f32 y, f32 z);
void func_002742B4(void *q, void *m);
s32 func_00279A30(void *a, s32 b);

typedef struct M03Sh { u8 pad0[0x14]; M03V3 *off; } M03Sh;
typedef struct M03ShSeg { u8 pad0[8]; u8 b8; u8 b9; u8 pad_a[6]; s8 d[3]; } M03ShSeg;

void func_0024AA08(Obj *a, s32 unused, M03Sh *s) {
    M03V3 dir;
    f32 r;
    u8 m[0x40];
    u8 q[0x40];
    f32 dy;
    f32 h;
    f32 ty;
    f32 t;
    f32 u2;
    s32 v;
    M03ShSeg *seg;
    register f32 py __asm__("$f1");

    if (a->unk14 != 0 && func_0024E148() != 0 && !(a->flags & 0x200000)) {
        if (a->flags & 0x10000000) {
            if (*(s32 *)((u8 *)a + 0xBC) == 0) {
                h = func_0024E640(a, 0);
                py = a->pos.y;
                if (py < h) {
                    goto end;
                }
                t = py - h;
                dy = t;
                if (512.0f < t) {
                    dy = 512.0f;
                }
                *(s32 *)((u8 *)a + 0xBC) = func_00279A30(D_8011FFB0, 1);
                if (*(s32 *)((u8 *)a + 0xBC) == 0) {
                    goto end;
                }
                seg = (M03ShSeg *)((u8 *)a + (D_800D297C * 0x18 + 0x140));
                dir.x = seg->d[0] * 0.007874016f;
                dir.y = seg->d[1] * 0.007874016f;
                dir.z = seg->d[2] * 0.007874016f;
                t = (f32)seg->b8 * (f32)seg->b8;
                u2 = (f32)seg->b9 * (f32)seg->b9;
                t = t + u2;
                r = sqrtf(t + u2) * -0.00090497744f;
                func_00268A40(D_8013B1A8, a->pos.x, a->pos.y, a->pos.z, &dir, &r);
                if (r < -1.0f) {
                    r = -1.0f;
                }
                v = (s32)(r * 56.0f + 128.0f);
                if (D_800D15E0 == 1) {
                    v = (s32)((f32)v * D_800D15F0 * 0.003921569f);
                }
                *((u8 *)a + 0x13A) = v;
                dir.y = 1.0f;
                func_002720EC(&dir);
                if (dir.y < 0.0f) {
                    if (-dir.y < 0.15f) {
                        goto clampy;
                    }
                } else if (dir.y < 0.15f) {
clampy:
                    if (0.0f <= dir.y) {
                        dir.y = 0.15f;
                    } else {
                        dir.y = -0.15f;
                    }
                    func_002720EC(&dir);
                }
                ty = h + dy * 0.9f;
                func_0027317C(m, &dir, ty);
                func_002734B8(m, -a->pos.x, -ty, -a->pos.z);
                t = dy * 0.003f + 1.0f;
                func_00273618(m, t, t, t);
                func_002742B4(&a->q5C, q);
                func_0026F690(*(s32 *)((u8 *)a + 0xBC), m, q);
                func_002734B8((void *)*(s32 *)((u8 *)a + 0xBC), a->pos.x, h, a->pos.z);
                if (*(s32 *)((u8 *)a + 0xBC) == 0) {
                    goto end;
                }
            }
            func_0024BA6C(a, s, *(s32 *)((u8 *)a + 0xBC), *((u8 *)a + 0x13A));
        } else {
            func_0024ADC0(a, s->off, 0);
        }
    }
end:
    return;
}
