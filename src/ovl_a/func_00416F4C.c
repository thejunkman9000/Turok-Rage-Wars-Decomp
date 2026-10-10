#include "o02_types.h"
typedef struct { u32 w0; u32 w1; } O02Gfx;
typedef struct { s16 x, y, z; s16 pad; s16 s, t; u8 r, g, b, a; } O02Vtx;
typedef struct { f32 x, y, z; } O02V3;
extern O02Gfx *D_80110634;
extern s32 D_800E32C8;
extern f32 D_800E142C;
extern u8 D_80145228[];
void func_0029FB14(void *m);
void func_004194B0(void *m);
void func_00272908(void *a, O02V3 *b, O02V3 *c);
O02Vtx *func_002A25E4(s32 n);
#define GFX(a, b) { O02Gfx *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
void func_00416F4C(s32 mode) {
    O02V3 a;
    O02V3 b;
    f32 m[16];
    f32 *mp;
    O02Vtx *v, *vt;
    s32 n, k;
    if (mode != D_800E32C8) {
        if (mode == 9) {
            mp = m;
            func_0029FB14(mp);
            func_004194B0(mp);
            a.x = 0;
            a.y = 0;
            a.z = D_800E142C;
            func_00272908(D_80145228, &a, &b);
            n = 4;
            v = func_002A25E4(0x40);
            for (k = 0; k < n; k++) {
                v[k].x = b.x;
                v[k].y = b.y;
                v[k].z = b.z;
                v[k].s = 0;
                v[k].t = 0;
                v[k].r = 0xFF;
 v[k].g = 0xFF;
 v[k].b = 0xFF;
 v[k].a = 0xFF;
            }
            GFX(0x01000000 | (n << 12) | (n << 1), (u32)v);
            for (k = 0; k < n; k++) {
                GFX(0x021C0000 | ((k * 2) & 0xFFFF), 0);
            }
        }
        D_800E32C8 = mode;
    }
}
