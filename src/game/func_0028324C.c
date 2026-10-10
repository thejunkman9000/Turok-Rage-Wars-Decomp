#include "span_1000/code_8028308C.h"
#include "types.h"
#include "common/draft_fields_func_80283278_de.h"


extern char D_801379C0;
extern char D_8013B1A8;

extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);




void func_80283278_de(void *arg0, s32 arg1) {
    s32 *temp_v1_3;
    s32 temp_a1;
    s32 temp_v1_2;
    u16 temp_v1;
    void *temp_s1;
    void *var_s0;

    var_s0 = ((struct Measured_func_80283278_de_0de4a5b91c75 *)(arg0))->value;
    if (var_s0 != 0) {
        do {
            temp_v1 = ((struct Measured_func_80283278_de_8375b44410ce *)(var_s0))->value;
            temp_s1 = ((struct Measured_func_80283278_de_94049340fefb *)(var_s0))->value;
            if (((temp_v1 == 0x414) || (temp_v1 == 0x42D)) &&
                (((struct Measured_func_80283278_de_b7d933e7eca3 *)(var_s0))->value == arg1)) {
                temp_v1_2 = ((struct Measured_func_80283278_de_06feaed90d80 *)(var_s0))->value;
                if (temp_v1_2 & 0x100) {
                  if (!(temp_v1_2 & 0x800)) {
                    func_80279A00_de(var_s0);
                    if (((struct Measured_func_80283278_de_cf5124ebb7ff *)(var_s0))->value != 0) {
                        func_80284178_de(var_s0);
                        func_802A42F4_de(&D_801379C0, var_s0);
                    }
                    temp_a1 = ((struct Measured_func_80283278_de_7a14ca935931 *)(var_s0))->value;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
                        ((struct Measured_func_80283278_de_7a14ca935931 *)(var_s0))->value = 0;
                    }
                    temp_v1_3 = ((struct Measured_func_80283278_de_e5800f736d95 *)(var_s0))->value;
                    if (temp_v1_3 != 0) {
                        *temp_v1_3 -= 1;
                    }
                    ((struct Measured_func_80283278_de_06feaed90d80 *)(var_s0))->value =
                        ((struct Measured_func_80283278_de_06feaed90d80 *)(var_s0))->value & 0xFDFFFEFF;
                    func_80255ED8_de(((struct Measured_func_80283278_de_d95970a8d560 *)(var_s0))->value, (s32)var_s0);
                    ((struct Measured_func_80283278_de_d95970a8d560 *)(var_s0))->value = 0;
                    func_80255CB8_de(&((func_8028324C_S1 *)(arg0))->unkFC00, (s32)var_s0);
                    if (((struct Measured_func_80283278_de_06feaed90d80 *)(var_s0))->value & 0x01000000) {
                        func_80255ED8_de(&((func_8028324C_S1 *)(arg0))->unkFC14, (s32)var_s0);
                    }
                  }
                }
            }
            var_s0 = temp_s1;
        } while (var_s0 != 0);
    }
}
