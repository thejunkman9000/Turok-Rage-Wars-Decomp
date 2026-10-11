#include "s1009_types.h"
extern S10State D_801462C8[];
extern S10Ctrl D_8010F328[];
extern S10Row D_80146302[];
extern u8 D_80146381;
extern u8 D_8011FAC0[];
extern s32 D_80154048;
extern s32 func_0026439C(void *p);
extern void func_0025E3A4(void);
extern void func_0044EACC(void *a, s32 b);
s32 func_0043EC10(void *a, S10Menu *m) {
    s32 i;
    D_801462C8->b1D = 0;
    D_801462C8->b1E = 1;
    for (i = 0; i < 8; i++) {
        D_801462C8->rec[i].b0 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (func_0026439C(&D_8010F328[i]) != 0) {
            D_80146302->b78 = 1;
            D_80146381 = i;
            m->ctrl = &D_8010F328[i];
            break;
        }
    }
    func_0025E3A4();
    func_0044EACC(D_8011FAC0, -1);
    D_80154048 = 1;
    return 1;
}
