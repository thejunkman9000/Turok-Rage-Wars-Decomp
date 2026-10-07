#include "o01_types.h"

extern u8 *D_8011FECC;

s32 func_004098B0(s32 a) {
    if (a == 0) {
        return (s32)D_8011FECC + 0x610;
    }
    return a << 8;
}
