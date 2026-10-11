/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028308C.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "types.h"

/** Return the word at offset 0xFC68. */
int func_802830B8_de(void *arg0) {
    return ((func_8028308C_S1 *)(arg0))->unkFC68;
}

extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);

void func_802830CC_de(void *arg0, s32 arg1) {
    s32 *temp_v1_3;
    s32 temp_a1;
    s32 temp_v1_2;
    u16 temp_v1;
    void *temp_s1;
    void *var_s0;

    var_s0 = ((func_802831FC_S1 *)arg0)->unkFC3C;
    if (var_s0 != 0) {
        do {
            temp_v1 = ((Effect_func_802800C0_de *)var_s0)->kind;
            temp_s1 = ((Effect_func_802800C0_de *)var_s0)->next;
            if ((temp_v1 == 0x41E) || (temp_v1 == 0x3EF)) {
                temp_v1_2 = ((Effect_func_802800C0_de *)var_s0)->flags;
                if ((temp_v1_2 & 0x100) && (((func_802831FC_S2 *)var_s0)->unk12C == arg1) && !(temp_v1_2 & 0x800)) {
                    func_80279A00_de(var_s0);
                    if (((Effect_func_802800C0_de *)var_s0)->unk1D9 != 0) {
                        func_80284178_de(var_s0);
                        func_802A42F4_de(&D_801379C0, var_s0);
                    }
                    temp_a1 = ((Effect_func_802800C0_de *)var_s0)->unk138;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
                        ((Effect_func_802800C0_de *)var_s0)->unk138 = 0;
                    }
                    temp_v1_3 = ((Effect_func_802800C0_de *)var_s0)->refCount;
                    if (temp_v1_3 != 0) {
                        *temp_v1_3 -= 1;
                    }
                    ((Effect_func_802800C0_de *)var_s0)->flags = ((Effect_func_802800C0_de *)var_s0)->flags & 0xFDFFFEFF;
                    func_80255ED8_de(((Effect_func_802800C0_de *)var_s0)->list, (s32)var_s0);
                    ((Effect_func_802800C0_de *)var_s0)->list = 0;
                    func_80255CB8_de(&((func_8028324C_S1 *)arg0)->unkFC00, (s32)var_s0);
                    if (((Effect_func_802800C0_de *)var_s0)->flags & 0x01000000) {
                        func_80255ED8_de(&((func_8028324C_S1 *)arg0)->unkFC14, (s32)var_s0);
                    }
                }
            }
            var_s0 = temp_s1;
        } while (var_s0 != 0);
    }
}

s32 func_80283228_de(void *arg0, s32 arg1) {
    s8 *record;
    s32 count;
    u16 v;

    record = ((func_802831FC_S1 *)(arg0))->unkFC3C;
    count = 0;
    if (record != 0) {
        do {
            v = ((func_802831FC_S2 *)(record))->unk4;
            if (((v == 0x3EF) || (v == 0x41E)) && (((func_802831FC_S2 *)(record))->unk12C == arg1)) {
                count += 1;
            }
            record = ((func_802831FC_S2 *)(record))->unk1EC;
        } while (record != 0);
    }
    return count;
}
