/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80449E18_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern void func_00264B9C();
extern void func_00264BAC();
extern s32 func_002866F8(void *, void *);
/* Refreshes every instance owned by the holder and clears their pending flag. */



void func_00220A5C(Node_func_80449E18_de *, Node_func_80449E18_de *);                 /* extern */
void func_00245854(s32);                            /* extern */
s32 func_00264B8C(void);                            /* extern */
                           /* extern */
                           /* extern */
                    /* extern */
s32 func_002934DC(void);                            /* extern */
void func_00449E38(Node_func_80449E18_de *);                         /* extern */

void func_0044AA68(Node_func_80449E18_de *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    struct Shape_func_802764D4_de_2 *temp_v1;
    struct Shape_func_802764D4_de_2 *temp_v1_2;
    Node_func_80449E18_de *var_s0;

    if ((func_002934DC() != 0) && (func_00264B8C() != 0)) {
        func_00264BAC();
        func_00264B9C();
    }
    var_s0 = arg0->unk20;
    if (var_s0 != 0) {
        do {
            func_00449E38(var_s0);
            temp_v0 = ((s32 (*)(s32 *, s32 *))func_002866F8)(&D_8011FE88, &var_s0->unk8);
            var_s0->unk2FC = temp_v0;
            var_s0->unk14 = temp_v0;
            func_00220A5C(var_s0, var_s0);
            temp_a0 = var_s0->unk5DC;
            if (temp_a0 != 0) {
                func_00245854(temp_a0);
            }
            temp_v1 = var_s0->unk18;
            temp_v1->field_4 = temp_v1->field_4 & ~4;
            temp_v1_2 = var_s0->unk18;
            temp_v1_2->field_4 = temp_v1_2->field_4 & ~4;
            var_s0 = var_s0->unk16E0;
        } while (var_s0 != 0);
    }
}
