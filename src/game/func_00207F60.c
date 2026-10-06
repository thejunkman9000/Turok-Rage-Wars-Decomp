#include "b02_types.h"

void func_0028B64C(void *p, u16 a, u16 b, s32 on);
extern u8 D_8011FE88[];

void func_00207F60(B2Evt *e) {
    func_0028B64C(D_8011FE88, e->unkA, e->unk4, 0);
}
