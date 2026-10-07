#include "b16_types.h"



extern u8 D_801105E0[];

void func_0026D8F8(void);
void func_00272D20(B16Mtx *m, f32 x, f32 y, f32 z);
void func_0026FD0C(B16Mtx *m, void *p);

void func_0026D844(void) {
    B16Mtx m;
    func_0026D8F8();
    func_00272D20(&m, 2.0f, 2.0f, 2.0f);
    func_0026FD0C(&m, D_801105E0);
}
