#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, void *arg);

s32 func_00204E78(void *arg) {
    return func_00285F28(D_8011FE88, arg) == 1;
}
