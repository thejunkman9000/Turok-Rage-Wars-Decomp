/* their2 */
/* Port of func_8044B0E0_de.c of the other decompilation (CC0): func_0044BD30, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
extern s32 func_00255CB4(IntrusiveList *list, void *node);

/* Initializes a list and its eight records with default state. */
void func_0044BD30(struct Pool_func_8044B0E0_de *arg0) {
    f32 temp_f20;
    s32 var_s1;
    s32 var_s2;
    Record_func_8044B0E0_de *temp_s0;
    void *base;

    func_00255C40(&arg0->empty, 0, 4);
    func_00255C40(&arg0->records, 0, 4);
    var_s2 = 0;
    var_s1 = 0x28;
    temp_f20 = 1.0f;
    do {
        base = arg0;
        temp_s0 = base + var_s1;
        func_00255CB4(&arg0->records, temp_s0);
        var_s1 += 0x18;
        var_s2 += 1;
        temp_s0->unk8 = 0;
        temp_s0->unkC = temp_f20;
        temp_s0->unk16 = 0;
    } while (var_s2 < 8);
}
