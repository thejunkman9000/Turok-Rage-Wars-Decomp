#include "common.h"

extern void *D_8014AECC[4];
void func_002536F4(s32 a, void *b);

void func_00295890(void) {
    void *p = D_8014AECC[0];
    if (p != NULL) {
        func_002536F4(0, p);
    }
    D_8014AECC[0] = NULL;
    D_8014AECC[2] = NULL;
    D_8014AECC[3] = NULL;
    D_8014AECC[1] = NULL;
}
