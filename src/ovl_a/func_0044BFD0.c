#include "s1005_types.h"

extern void func_00279A00(S5MtxStack *s);

void func_0044BFD0(S5MtxStack *s, Mtx *m, s32 count) {
    s32 i;

    s->base = m;
    s->n = count / 2;
    for (i = 0; i < count; i++) {
        guMtxIdent(&m[i]);
    }
    func_00279A00(s);
}
