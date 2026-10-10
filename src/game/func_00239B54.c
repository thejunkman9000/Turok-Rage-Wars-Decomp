#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"
#include "types.h"



extern void *D_80140FE8_de;
extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);






void func_80239B64_de(s32 arg0) {
    Node_func_80239AF4_de *temp_s0;
    Node_func_80239AF4_de *temp_s0_2;
    Node_func_80239AF4_de *var_s1;
    Node_func_80239AF4_de *var_s1_2;
    void *temp_s2;
    void *var_s2;

    temp_s2 = (void *)(arg0 + 0x40);
    if (temp_s2 != 0) {
        var_s1 = ((func_80239AE4_S1 *)(temp_s2))->unkE44;
        if (var_s1 != 0) {
            do {
                temp_s0 = var_s1->next;
                func_80255ED8_de(&((func_80239AE4_S1 *)(temp_s2))->unkE40, var_s1);
                func_80255CB8_de((void *)(arg0 + 0xF24), (s32)var_s1);
                var_s1 = temp_s0;
            } while (var_s1 != 0);
        }
    }

    var_s2 = D_80140FE8_de;
    if (var_s2 != 0) {
        do {
            var_s1_2 = ((func_80239B54_S2 *)(var_s2))->unkE44;
            if (var_s1_2 != 0) {
                do {
                    temp_s0_2 = var_s1_2->next;
                    func_80255ED8_de(&((func_80239B54_S2 *)(var_s2))->unkE40, var_s1_2);
                    func_80255CB8_de((void *)(arg0 + 0xF24), (s32)var_s1_2);
                    var_s1_2 = temp_s0_2;
                } while (var_s1_2 != 0);
            }
            var_s2 = ((func_80239B54_S2 *)(var_s2))->unk4;
        } while (var_s2 != 0);
    }
}
