#include "s1005_types.h"

extern u8 D_8011EE70[];
extern S5Vtx D_8011F038[];
extern u8 D_8011EFF8[];

extern void func_00255C40(S5List *l, s32 prevOff, s32 nextOff);
extern void func_00255CB4(S5List *l, void *node);
extern void func_00219460(void *p);
extern void func_002736B8(void *m, f32 a);

void func_0044C050(S5QuadPool *p, s32 arg) {
    s32 i;
    s32 j;
    S5Vtx *v;

    for (i = 0; i < 0x80; i++) {
        p->obj[i].info = D_8011EE70;
        p->obj[i].type = 2;
        p->obj[i].f5C = 0;
        p->obj[i].f1DC = 0;
        p->obj[i].f1E4 = 0;
    }
    func_00255C40(&p->used, 0x1E8, 0x1EC);
    for (i = 0; i < 0x80; i++) {
        func_00255CB4(&p->used, &p->obj[i]);
    }
    func_00255C40(&p->listB, 0x1F0, 0x1F4);
    for (i = 0; i < 3; i++) {
        func_00255C40(&p->listC[i], 0x1E8, 0x1EC);
    }
    func_00219460(D_8011EE70);
    for (j = 0; j < 4; j++) {
        v = &D_8011F038[j];
        switch (j) {
        case 0:
            v->x = -1;
            v->y = 1;
            v->s = -0x8000;
            v->t = -0x8000;
            break;
        case 1:
            v->x = 1;
            v->y = 1;
            v->s = 0;
            v->t = -0x8000;
            break;
        case 2:
            v->x = 1;
            v->y = -1;
            v->s = 0;
            v->t = 0;
            break;
        case 3:
            v->x = -1;
            v->y = -1;
            v->s = -0x8000;
            v->t = 0;
            break;
        }
        v->z = 0;
        v->flag = 0;
        v->c[0] = 0xFF;
        v->c[1] = 0xFF;
        v->c[2] = 0xFF;
        v->c[3] = 0xFF;
    }
    func_002736B8(D_8011EFF8, 1.5707964f);
    p->fFC64 = arg;
    p->fFC68 = 0;
}
