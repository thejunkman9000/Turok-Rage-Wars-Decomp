#include "b16_types.h"

extern s32 D_801153D0;
extern s32 D_801153D8[];

void func_0026BC60(void);
void func_0026C020(void);
void func_00253B5C(s32 a, s32 b);
void func_002536F4(s32 a, s32 b);

void func_0026D9D0(void) {
    s32 i;
    s32 v;
    func_0026BC60();
    func_0026C020();
    for (i = 0; i < D_801153D0; i++) {
        v = D_801153D8[i];
        func_00253B5C(0, v);
        func_002536F4(0, v);
    }
}
