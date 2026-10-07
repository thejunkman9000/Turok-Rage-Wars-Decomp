#include "b17_types.h"

extern s32 D_800D297C;

void func_00279A00(MtxStack *s) {
    s->left = s->n;
    s->cur = s->base + s->n * D_800D297C;
}
