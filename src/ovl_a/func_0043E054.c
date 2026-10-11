#include "s1009_types.h"
extern S10State D_801462C8[];
extern S10Ctrl D_8010F328[];
extern S10Row D_80146398[];
extern s32 func_0026439C(void *p);
void func_0043E054(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        D_801462C8->rec[i].b8 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (func_0026439C(&D_8010F328[i]) != 0) {
            S10Row *r = &D_80146398[i];
            r->b78 = 1;
            r->b7F = i;
            break;
        }
    }
}
