#include "b20_types.h"

void func_00278EEC(Rec14 *r);

void func_0028C34C(Level *lv, s32 key) {
    Rec14 *r;
    s32 n;
    n = lv->cnt11C0;
    r = lv->recA;
    while (--n != -1) {
        if (r->key == key) {
            func_00278EEC(r);
        }
        r++;
    }
    n = lv->cnt11C4;
    r = lv->recB;
    while (--n != -1) {
        if (r->key == key) {
            func_00278EEC(r);
        }
        r++;
    }
}
