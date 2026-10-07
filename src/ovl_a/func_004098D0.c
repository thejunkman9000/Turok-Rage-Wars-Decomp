#include "o01_types.h"

extern u8 *D_8011FECC;

void func_004098D0(s32 off, s32 v) {
    *(s32 *)(D_8011FECC + off + 0x60C) = v;
}
