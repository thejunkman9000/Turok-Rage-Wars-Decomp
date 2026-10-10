#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"





extern s32 D_80100570;
extern Queue_func_802517B4_de D_80101140;

extern s32 D_80105180;
extern s32 D_80101190;
extern s32 D_80101194;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);
extern void func_80255FB8_de(void *, s32);




void func_80253F8C_de(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    HashNode *node;
    void *value;
    void **out;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de((s32)&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }

    out = &value;
    node = (HashNode *)((s32)D_80101194 +
        ((((arg1 << 5) ^ ((u32)arg1 >> 1) ^ ((u32)arg1 >> 9) ^
           ((u32)arg1 >> 17)) & D_80101190) * 0x10));
    if (node->key != arg1) {
        goto not_initial;
    }
    value = node->value;
    goto found;
loop_found:
    *out = node->value;
    goto found;
not_initial:
    value = 0;
    if (node == 0) {
        goto found;
    }
loop:
    if (node->key == arg1) {
        goto loop_found;
    }
    node = node->next;
    if (node != 0) {
        goto loop;
    }
found:

    if (value != 0) {
        void *object = *(void **)value;
        ((func_8022BC04_S3 *)(object))->unk10 = D_80105180;
        func_80255FB8_de(&D_80100570, object);
    }

    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}
