#include "o04_types.h"
extern O04Cfg D_801462C8[];
extern O04ModeS4680 *D_800E4680;
extern u8 D_8011FAC0[];
void func_0042EF50(f32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
s32 func_0042F014(void);
void func_0044EACC(void *a, s32 b);
void func_0042EE18(void) {
    if (D_801462C8->unkD) {
        func_0042EF50((f32)D_800E4680->u24, D_800E4680->u22, D_800E4680->u21, D_800E4680->u23, 0, 1, 0);
    } else {
        func_0042EF50((f32)D_801462C8->s24, D_801462C8->s25, D_801462C8->s27, D_801462C8->s26, 0, 1, 0);
    }
    func_0044EACC(D_8011FAC0, func_0042F014());
}
