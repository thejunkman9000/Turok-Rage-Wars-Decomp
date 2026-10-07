#include "o02_types.h"
extern s32 D_80153800;
extern s32 D_800E2ABC;
extern s32 D_800E2AB8;
extern O02Ent D_80153820[];
extern s32 D_80153810, D_80153814, D_80153818, D_8015381C;
extern s32 D_801539A0, D_801539A4;
void func_004171B8(s32 a);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_00410FD4(s32 a, s32 b, s32 c);
void func_00417574(s32 a);
void func_00418E20(f32 a, f32 b, f32 c, f32 d, f32 e, s32 f);
void func_0040CB30(void) {
    O02Rect r;
    u16 lo, hi;
    s32 i, j, started;
    O02Item *it;
    O02Ent *e;
    O02Rect *p;
    if (D_80153800 != 0) {
        lo = 0x60;
        hi = 0;
        if (D_800E2ABC != 0x53333 || D_800E2AB8 == 0) {
            D_800E2ABC = 0x53333;
            func_004171B8(0x53333);
            D_800E2AB8 = 1;
        }
        func_002A2898(&r.w[0], &r.w[2], &r.w[1], &r.w[3]);
        func_002A2870(D_80153810, D_80153818, D_80153814, D_8015381C);
        for (i = 0; i < D_80153800; i++) {
            it = D_80153820[i].items;
            lo = lo < it->f14 ? lo : it->f14;
            hi = it[D_80153820[i].count - 1].f14 < hi ? hi : it[D_80153820[i].count - 1].f14;
        }
        for (i = lo; i <= hi; i++) {
            started = 0;
            for (j = 0; j < D_80153800; j++) {
                e = &D_80153820[j];
                while (i == e->items->f14 && e->count > 0) {
                    it = e->items;
                    if (!started) {
                        s32 r2 = func_00410FD4(i & 0xFF, D_801539A0, D_801539A4);
                        if (!r2) {
                            j = D_80153800;
                            break;
                        }
                        func_00417574(r2);
                        started = 1;
                    }
                    func_00418E20(it->f4, it->f8, 10.0f, it->fC, it->f10, it->w0);
                    e->items++;
                    e->count--;
                }
            }
        }
        p = &r;
        func_002A2870(r.w[0], p->w[2], p->w[1], p->w[3]);
        D_80153800 = 0;
    }
}
