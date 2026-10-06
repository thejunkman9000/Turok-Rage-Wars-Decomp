#include "common.h"

extern u8 D_8010EC90[];
extern u8 D_80145040[];
void func_00285D00(void *a);
void func_0022A870(void *a);

void func_00294C64(void) {
    func_00285D00(D_8010EC90);
    func_0022A870(D_80145040);
}
