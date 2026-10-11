/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044A170_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
/* Initializes camera transforms, viewport state, clipping records, and resource lists. */

 
void func_00238EA8(void *);                               /* extern */
void func_002390E4(void *, s32);                         /* extern */
void func_002393C8(void *);                            /* extern */
void func_00239C10(void *);                            /* extern */
void func_00272848(void *);                            /* extern */
void func_004426B4(void *);                    /* extern */


extern s32 D_800E28D0, D_800E28D4;
extern struct Shape_func_802764D4_de_2 D_80103220;






/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x20, 0x24], gap at: 0x18. */
void func_0044ADC0(State_func_8044A170_de *arg0) {
    f32 temp_f21;
    f32 zero;
    s16 temp_a0;
    s32 var_a1;
    Floats *temp_v0;
    Floats *temp_v0_2;
    Floats *temp_v0_3;
    Floats *temp_v0_4;
    Floats *temp_v0_5;
    State_func_8044A170_de *var_v1;
    State_func_8044A170_de *record;
    typedef struct { u8 bytes[16]; } ClipStride;

    func_00238EA8(((void *)&((func_8044ADC0_S1 *)(arg0))->unk24));
    func_00272848(((void *)&((func_8044ADC0_S1 *)(arg0))->unk160));
    func_00272848(((void *)&((func_8044ADC0_S1 *)(arg0))->unk1E0));
    zero = 0.0f;
    temp_f21 = 1.0f;
    temp_v0 = ((void *)&((func_8044ADC0_S1 *)(arg0))->unk140);
    temp_v0->unk8 = zero;
    temp_v0->unk4 = zero;
    arg0->unk140 = zero;
    arg0->unk14C = temp_f21;
    func_00272848(((void *)&((func_8044ADC0_S1 *)(arg0))->unk1A0));
    arg0->unk29C = (f32) D_800E28D0;
    arg0->unk2A0 = (f32) D_800E28D4;
    arg0->unk518 = -1;
    arg0->unk2A4 = zero;
    arg0->unk2A8 = zero;
    arg0->unk520 = 0;
    arg0->unk524 = 0;
    arg0->unk521 = 0;
    arg0->unk525 = 0;
    arg0->unk522 = 0;
    arg0->unk526 = 0;
    arg0->unk523 = 0;
    arg0->unk527 = 0;
    arg0->unk51C = temp_f21;
    arg0->unk53C = 0x3E3;
    arg0->unk540 = 0x3E3;
    arg0->unk548 = 0;
    arg0->unk7C = 0;
    arg0->unkC = temp_f21;
    arg0->unk10 = temp_f21;
    arg0->unk528 = (f32) 1024.0f;
    arg0->unk52C = (f32) 1024.0f;
    arg0->unk530 = (f32) 47.5f;
    arg0->unk534 = (f32) 47.5f;
    func_002393C8(arg0);
    temp_v0_2 = ((void *)&((func_8044ADC0_S1 *)(arg0))->unkA0);
    arg0->unkF4 = zero;
    arg0->unkF8 = zero;
    temp_v0_2->unk8 = zero;
    temp_v0_2->unkC = zero;
    temp_v0_2->unk10 = zero;
    temp_v0_2->unk14 = temp_f21;
    temp_v0_3 = ((void *)&((func_8044ADC0_S1 *)(arg0))->unkB8);
    temp_v0_3->unk4 = zero;
    temp_v0_3->unk8 = zero;
    temp_v0_3->unkC = zero;
    temp_v0_3->unk10 = zero;
    temp_v0_4 = ((void *)&((func_8044ADC0_S1 *)(arg0))->unkCC);
    temp_v0_4->unk4 = zero;
    temp_v0_4->unk8 = zero;
    temp_v0_4->unkC = zero;
    temp_v0_4->unk10 = zero;
    temp_v0_5 = ((void *)&((func_8044ADC0_S1 *)(arg0))->unkE0);
    temp_v0_5->unk4 = zero;
    temp_v0_5->unk8 = zero;
    temp_v0_5->unkC = zero;
    temp_v0_5->unk10 = zero;
    func_002390E4(arg0, 0);
    var_a1 = 0;
    var_v1 = arg0;

    temp_a0 = D_800E28D0 * 2;
    do {
        record = (State_func_8044A170_de *)&((ClipStride *)arg0)[var_a1];
        record->unk2B0 = temp_a0;
        record->unk2B2 = temp_a0;
        record->unk2B4 = 0x3FF;
        record->unk2B6 = 0;
        record->unk2B8 = temp_a0;
        record->unk2BA = temp_a0;
        record->unk2BC = 0;
        record->unk2BE = 0;
        var_a1 += 1;
        var_v1 = &((func_8044ADC0_S2 *)(var_v1))->unk10;

    } while (var_a1 < 2);
    func_004426B4(((void *)&((func_8044ADC0_S1 *)(arg0))->unk554));
    func_00272848(((void *)&((func_8044ADC0_S1 *)(arg0))->unkE54));
    func_00272848(((void *)&((func_8044ADC0_S1 *)(arg0))->unkE94));
    arg0->unk544 = 0;
    arg0->unk120 = 0;
    arg0->unk124 = 0x32;
    arg0->unk126 = 0;
    D_80103220.field_4 = 0;
    func_00255C40(&((func_8044ADC0_S1 *)(arg0))->unkE40, 0, 4);
    func_00239C10(arg0);
}
