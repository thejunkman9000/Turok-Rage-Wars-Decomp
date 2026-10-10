#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"

extern char D_801051A0;

extern void func_80254DD0_de(void *arg0, void *arg1);
extern void func_80255B2C_de(void *arg0, s32 arg1);
extern void func_80254AD0_de(s32, s32);




void func_80254990_de(void *unused, void *arg1) {
    s32 temp_v0;

    ((func_80254930_S1 *)(arg1))->unkC = ((func_80254930_S1 *)(arg1))->unkC & ~2;
    if (((func_80254930_S1 *)(arg1))->unk8 != 0) {
    loop_1:
        do {
            temp_v0 = ((func_80254930_S1 *)(arg1))->unk8 - 1;
            ((func_80254930_S1 *)(arg1))->unk8 = temp_v0;
            if (temp_v0 != 0) {
                goto loop_1;
            }
            ((func_80254930_S1 *)(arg1))->unkC = ((func_80254930_S1 *)(arg1))->unkC & ~0x100;
        } while (((func_80254930_S1 *)(arg1))->unk8 != 0);
    }
    if (!(((func_80254930_S1 *)(arg1))->unkC & 0x702)) {
        func_80254DD0_de(0, arg1);
        func_80255B2C_de(&D_801051A0, *(s32 *) arg1);
        func_80254AD0_de(0, arg1);
    }
}
