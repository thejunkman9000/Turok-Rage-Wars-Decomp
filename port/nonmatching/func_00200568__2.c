/* EXACT only with gcc 2.7.2 -O2 (tools/gcc/2.7.2, no -mcpu); gcc 2.8.1 fills the first beqz slot. */
#include "common.h"
void func_00200568(u32 *arg0, u32 arg1) {
    register u32 stat;
    stat = IO_READ(PI_STATUS_REG);
    while (stat & 3) {
        stat = IO_READ(PI_STATUS_REG);
    }
    *arg0 = arg1;
}
