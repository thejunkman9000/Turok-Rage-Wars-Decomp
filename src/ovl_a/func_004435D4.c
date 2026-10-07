#include "o06_types.h"
extern void func_0025E3A4(void);
extern s32 func_0025CC8C(void);
extern void func_0025CB2C(s32 a);
extern s32 func_004424F4(s32 a, s32 b, s32 c);
extern void func_0026497C(void);
extern s32 D_801540F0;
s32 func_004435D4(s32 a, s32 b, s32 c) {
    func_0025E3A4();
    func_0025CB2C(func_0025CC8C());
    if (D_801540F0 == 0) { func_0026497C(); return 1; }
    func_004424F4(a, b, c);
    return 1;
}
