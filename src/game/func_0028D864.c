#include "b20_types.h"
void func_002536F4(s32 a, void *b);
void func_0028D864(Level *lv) {
    s32 i;
    s32 n;
    s32 t;
    Ent12 *arr;
    i = 0;
    n = lv->cnt1504;
    arr = lv->ents;
    for (; i < n; i++) {
        func_002536F4(0, arr[i].tblp);
    }
    t = lv->cnt1504;
    lv->cnt944 = 0;
    lv->cntC4C = 0;
    lv->cnt10BC = 0;
    lv->cnt1504 = 0;
    lv->cnt1500 = t;
}
