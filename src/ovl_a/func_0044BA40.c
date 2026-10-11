/* their2 */
/* Port of func_8044ADF0_de.c of the other decompilation (CC0): func_0044BA40, symbols renamed to US v1.1 names. */
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80255BEC.h"

extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
extern s32 func_00255CB4(IntrusiveList *list, void *node);

void func_0044BA40(func_80262ABC_S1 *arg0) {
    Effect_func_80262A9C_de *var_s0;
    s32 var_s1;

    func_00255C40(&arg0->unk5F00, 0x2E8, 0x2EC);
    func_00255C40(&arg0->unk5F14, 0x2E8, 0x2EC);
    var_s1 = 0;
    var_s0 = arg0->effects;
    do {
        func_00255CB4(&arg0->unk5F00, var_s0);
        var_s1 += 1;
        var_s0 += 1;
    } while (var_s1 < 0x20);
}
