#include "common.h"

extern u8 D_8011FE88[];
void func_0028C138(void *o, s32 b, s32 *p, s32 *q);

void func_00296DDC(s32 *a, s32 b) {
    func_0028C138(D_8011FE88, b, a, a + 1);
}
