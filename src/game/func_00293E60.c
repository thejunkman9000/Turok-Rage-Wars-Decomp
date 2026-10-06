#include "p4_types.h"
extern s32 D_8014ADA0;
void func_00293808(s32 a, s32 b);
void func_002647E4(void);
void func_00293E60(s32 a) {
    if (D_8014ADA0 != 0) {
        func_00293808(a, 1);
        func_002647E4();
    }
}
