/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80445EF4_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "span_16E000/code_804453C4.h"
#include "types.h"
/* Returns 1 when any of the words at 0x28, 0x1C or 0x20 of D_801468A0 is nonzero, else 0. */



extern State_func_80445EF4_de D_801468A0;

s32 func_auto_00446064(void) {
    State_func_80445EF4_de *s = &D_801468A0;
    s32 ret;

    ret = 0;
    if (s->unk28 != 0 || s->unk1C != 0 || s->unk20 != 0) {
        ret = 1;
    }
    return ret;
}
