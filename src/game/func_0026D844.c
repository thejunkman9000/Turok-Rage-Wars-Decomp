#include "b16_types.h"

typedef struct Mtx4f { f32 m[4][4]; } Mtx4f;

extern f32 D_800C979C;
extern u8 D_801105E0[];

void func_0026D8F8(void);
void func_00272D20(Mtx4f *m, f32 x, f32 y, f32 z);
void func_0026FD0C(Mtx4f *m, void *p);

void func_0026D844(void) {
    Mtx4f m;
    func_0026D8F8();
    func_00272D20(&m, D_800C979C, D_800C979C, D_800C979C);
    func_0026FD0C(&m, D_801105E0);
}
