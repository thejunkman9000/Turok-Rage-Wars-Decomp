#include "b06_types.h"

void func_0024ADC0(PlrObj *e, Vec3f *v, s32 a);
void func_0024B4E4(PlrObj *e, s32 n);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void func_002536F4(s32 a, s32 *r);
s32 func_0028FD94(s32 a, s32 b);
extern u8 D_800C7CB0[];

void func_00228774(PlrGroup *g, Pawn *p) {
    Plr *a;
    PlrObj *e;
    Pawn *pw;
    s32 *r;
    s32 *r2;
    Plr *other;
    Vec3f v;
    for (a = g->head; a != NULL; a = a->next) {
        pw = a->unk5DC;
        if (pw != NULL) {
            if (pw == p) {
                if (pw->unk24 == 0) {
                    e = (PlrObj *)((u8 *)a + 0x2E8);
                    if (e->flags100 & 0x40000) {
                        r = func_002518DC(0, e->unkC4, e->unkC4, e->unkD0, 4, 0, 0, D_800C7CB0, 1);
                        if (r != NULL) {
                            other = e->unk1D8;
                            func_0024B4E4(e, func_0028FD94(r[0], 0));
                            if (other->unk5DC != NULL) {
                                v.x = other->unk5DC->pos128.x - e->pos.x;
                                v.y = 0;
                                v.z = other->unk5DC->pos128.z - e->pos.z;
                                func_0024ADC0(e, &v, 1);
                            }
                            func_002536F4(0, r);
                        }
                    }
                } else {
                    goto blk;
                }
            } else if (pw != NULL) {
blk:
                if (a->flags100 & 0x40000) {
                    r2 = func_002518DC(0, a->unkC4, a->unkC4, a->unkD0, 4, 0, 0, D_800C7CB0, 1);
                    if (r2 != NULL) {
                        func_0024B4E4((PlrObj *)a, func_0028FD94(r2[0], 0));
                        func_002536F4(0, r2);
                    }
                }
            }
        }
    }
}
