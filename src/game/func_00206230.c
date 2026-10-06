#include "b01_types.h"

extern u8 D_8011FE88[];
void func_00285D80(void *mgr, void *arg, s32 flag);

void func_00206230(void *arg) {
    func_00285D80(D_8011FE88, arg, 1);
}
