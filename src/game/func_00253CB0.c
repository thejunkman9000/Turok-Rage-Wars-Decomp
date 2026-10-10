#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "types.h"



extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 arg0);
extern void func_802BB2A0_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
extern void func_80254DD0_de(void *arg0, void *arg1);
extern void func_80255B2C_de(void *arg0, s32 arg1);
extern void func_80254AD0_de(s32 arg0, void *arg1);

extern s32 D_80101140;

extern char D_801051A0;

void func_80253D10_de(s32 unused, struct Shape_typemap_165 **arg1, struct Shape_typemap_165 *arg2) {
    s32 counter;
    s32 counter2;
    s32 count;
    struct Shape_typemap_165 *node;
    u32 token;
    u32 token2;

    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de((s32)&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token);
    }

    node = *arg1;
    node->field_C &= ~2;
    if (node->field_8 != 0) {
    loop_1:
        do {
            count = node->field_8 - 1;
            node->field_8 = count;
            if (count != 0) {
                goto loop_1;
            }
            node->field_C &= ~0x100;
        } while (node->field_8 != 0);
    }
    if (!(node->field_C & 0x702)) {
        func_80254DD0_de(0, node);
        func_80255B2C_de(&D_801051A0, node->field_0);
        func_80254AD0_de(0, node);
    }
    *arg1 = arg2;

    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(token2);
}
