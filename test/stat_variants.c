#include "common.h"
extern int cond;
void f_nv(void) {   /* non-volatile constant address store inside a loop */
    int i;
    for (i = 0; i < 4; i++) {
        if (cond) { *(u32 *)PHYS_TO_K1(PI_STATUS_REG) = 2; }
    }
}
void f_v(void) {    /* volatile */
    int i;
    for (i = 0; i < 4; i++) {
        if (cond) { *(volatile u32 *)PHYS_TO_K1(PI_STATUS_REG) = 2; }
    }
}
void f_vk(u32 v) {  /* volatile with runtime value */
    int i;
    for (i = 0; i < 4; i++) {
        if (cond) { *(volatile u32 *)PHYS_TO_K1(PI_STATUS_REG) = v; }
    }
}
