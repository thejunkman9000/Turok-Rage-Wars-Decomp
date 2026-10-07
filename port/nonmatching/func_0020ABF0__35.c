#include "b02_types.h"

f32 func_00272768(void *a, void *b);
B2Pool *func_0028D1F4(void *g, u8 id);
Vec3f *func_0028D220(void *g, u8 id, s32 idx);
extern u8 D_8011FE88[];
extern B2Obj *D_8011FFC0;
extern s32 D_8011FFC8;
extern const f32 D_800C6E3C;
extern f32 D_800C6E40;

void func_0020ABF0(B2Mgr *m) {
    B2Obj *list[30];
    s32 nlist;
    B2Obj **lp;
    s32 i;
    s32 j;
    s32 k;
    B2Node *n;
    u8 *r;
    B2Obj *sel;
    B2Obj *a;
    B2Info *info;
    B2Sub *st;
    B2Pool *t;
    Vec3f *p;
    Vec3f found;
    Vec3f pos1;
    Vec3f pos2;
    f32 best;
    f32 d;

    for (i = 29; i >= 0; i--) {
        list[i] = NULL;
    }
    i = 0;
    nlist = 0;
    lp = list;
    for (; i < D_8011FFC8; i++) {
        a = &D_8011FFC0[i];
        if (a->unkE4 == 0x642) {
            *lp = a;
            lp++;
            nlist++;
        }
    }
    for (n = m->head; n != NULL; n = n->next) {
        r = (u8 *)m->pool0 + n->id * m->pool0->elemSize + 8;
        sel = NULL;
        if (*(u16 *)(r + 0xC) & 0x200) {
            best = D_800C6E40;
            for (k = 0; k < nlist; k++) {
                a = list[k];
                st = &a->sub;
                info = &a->def->info;
                if (st->unk34 == 4) {
                    t = func_0028D1F4(D_8011FE88, st->unk95);
                    if (t != NULL) {
                        for (j = 0; j < ((s16 *)t)[1]; j++) {
                            p = func_0028D220(D_8011FE88, st->unk95, j);
                            d = func_00272768(r, p);
                            if (d < best || best == D_800C6E3C) {
                                sel = list[k];
                                best = d;
                                found = *p;
                            }
                        }
                    }
                } else {
                    pos1 = a->pos210;
                    pos2 = a->pos210;
                    pos2.y += info->unk2C;
                    if (info->unk4 != 0) {
                        pos2.x += info->unk30 * sinf(info->unk34);
                        pos2.z += info->unk30 * cosf(info->unk34);
                    }
                    d = func_00272768(r, &pos1);
                    if (d < best || best == D_800C6E3C) {
                        sel = list[k];
                        best = d;
                        found = pos1;
                    }
                    d = func_00272768(r, &pos2);
                    if (d < best || best == D_800C6E3C) {
                        sel = list[k];
                        best = d;
                        found = pos2;
                    }
                }
            }
            if (sel == NULL) {
                n->unk40 = NULL;
                *(u16 *)(r + 0xC) &= 0xFDFF;
            } else {
                n->unk40 = sel;
                n->v44 = found;
            }
        }
    }
}
