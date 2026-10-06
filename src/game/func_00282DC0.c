
#include "b19_types.h"
extern B19Row *D_800D052C[22];
s32 func_00282DC0(B19Obj *o) {
    s32 i, j;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            B19Ent *e = D_800D052C[i]->a[j];
            if (e != 0 && e->id == o->id && e->kind == 2) return 1;
            e = D_800D052C[i]->b[j];
            if (e != 0 && e->id == o->id && e->kind == 2) return 1;
        }
    }
    return 0;
}
