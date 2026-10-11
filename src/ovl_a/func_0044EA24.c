/* their2 */
/* Port of func_8044DDD4_de.c of the other decompilation (CC0): func_0044EA24, symbols renamed to US v1.1 names. */
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044E2B8.h"
#include "types.h"

/* Asks func_0044DE70 about D_8011FE88 with a minus-one selector, clears the words of D_801468A0 and puts the object at arg0 into state 0xC with byte 0x26DC1 set to two and the selector, or zero when the lookup failed, stored at 0x26DD8. Adapted from func_00293268 with the selector fixed at minus one, the word at 0x26DDC cleared before the last word of D_801468A0 instead of set after the selector, and the state 0xC instead of 0xD changed. */

extern s32 func_0044DE70(s8 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern s32 D_801468A0;

void func_0044EA24(void *arg0) {
    s32 sp18[6];
    s32 var_s0;

    var_s0 = -1;
    if (func_0044DE70((s8 *)&D_8011FE88, var_s0, var_s0, sp18, 1) == 0) {
        var_s0 = 0;
    }
    ((func_80293268_S1 *)(&D_801468A0))->unk0 = 0;
    ((func_80293268_S1 *)(&D_801468A0))->unk4 = 0;
    ((func_80293268_S1 *)(&D_801468A0))->unk8 = 0;
    ((func_80293268_S1 *)(&D_801468A0))->unkC = 0;
    ((func_80293268_S2 *)(arg0))->unk26DDC = 0;
    ((func_80293268_S1 *)(&D_801468A0))->unk88 = 0;
    ((func_80293268_S2 *)(arg0))->unk26DC1 = 2;
    ((func_80293268_S2 *)(arg0))->unk26DD8 = var_s0;
    ((func_80293268_S2 *)(arg0))->unk26DBC = 0xC;
}
