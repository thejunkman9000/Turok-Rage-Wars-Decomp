#include "s504_types.h"

void *func_0028FD94(int *, int);
int func_00253294(void *);
typedef S504Anim func_80261EB8_S1;
typedef S504AnimOut func_80261EB8_S2;
typedef struct { char pad0[8]; signed char unk8; } func_80261EB8_S3;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x30, 0x34, 0x38, 0x3c], gap at: 0x28. */
/* FAKEMATCH: these existing scale identities also supply the two-word shared
 * ROM pool prefix. Their definitions preserve the resident data layout. */
const f32 D_800C41F8_de = 1.0f;
const f32 D_800C41FC_de = 1.0f;
void func_00261EB8(func_80261EB8_S1 *arg0, func_80261EB8_S2 *arg1) {
    extern const f32 D_800C41FC_de;
    f32 unit;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f0;
    s32 **temp_a0;
    s32 *temp_s0;
    s32 *temp_v0;
    s32 temp_a0_2;
    s32 temp_f3;
    s32 temp_f3_2;
    s32 temp_f3_3;
    s32 temp_f3_4;
    s32 temp_f3_5;
    s32 temp_f3_6;
    s32 temp_v1;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    func_80261EB8_S3 *temp_s1;

    temp_a0 = arg0->unk10;
    if (temp_a0 == 0) {
        var_v0 = 0;
    } else {
        var_v0 = func_00253294(temp_a0) != 0;
    }
    if (var_v0 != 0) {
        temp_s0 = *arg0->unk10;
        temp_s1 = func_0028FD94(temp_s0, 1);
        temp_v0 = func_0028FD94(temp_s0, 5);
        func_0028FD94(temp_v0, 0);
        var_s0 = arg0->unkC;
        temp_f20 = arg0->unk0;
        temp_f22 = (f32) arg0->unk8;
        arg1->unk0 = &temp_s1->unk8;
        arg1->unk4 = &((func_80261EB8_S3 *)func_0028FD94(temp_s0, 2))->unk8;
        arg1->unk8 = func_0028FD94(temp_v0, 1);
        
        {
            extern const f32 D_800C41F8_de;
            /* FAKEMATCH: SN64 const-call metadata lets the scheduler delay the
             * scale load past this lookup. The callee reads an offset table, so
             * the attribute is stronger than the actual C contract. */
            extern void *func_0028FD94(int *, int) __attribute__((const));
            unit = D_800C41F8_de;
            arg1->unkC = func_0028FD94(temp_v0, 2);
        }
        if (temp_f20 >= 0.0f) {
            var_v0_2 = (s32) temp_f20;
            goto block_8;
        }
        temp_f3 = (s32) temp_f20;
        var_f0 = (f32) temp_f3;
        if (var_f0 != temp_f20) {
            var_v0_2 = temp_f3 - 1;
block_8:
            var_f0 = (f32) var_v0_2;
        }
        arg1->unk20 = (f32) (temp_f20 - var_f0);
        if (var_s0 == 0xFFFF) {
            var_s0 = 0;
            if (temp_f20 >= 0.0f) {
                var_a1 = (s32) temp_f20;
            } else {
                temp_f3_2 = (s32) temp_f20;
                var_a1 = ((f32) temp_f3_2 == temp_f20) ? 0 : 1;
                var_a1 = temp_f3_2 - var_a1;
            }
            if (temp_f22 <= (f32) var_a1) {
                var_a1 = 0;
            }
            var_v1 = var_a1 + 1;
            if (temp_f22 <= (f32) var_v1) {
                var_v1 = 0;
            }
        } else {
            if (temp_f20 >= 0.0f) {
                var_a1 = (s32) temp_f20;
            } else {
                temp_f3_3 = (s32) temp_f20;
                var_a1 = ((f32) temp_f3_3 == temp_f20) ? 0 : 1;
                var_a1 = temp_f3_3 - var_a1;
            }
            if ((temp_f22 - D_800C41FC_de) <= (f32) var_a1) {
                temp_v1 = arg0->unkC;
                if (((f32) (u32) temp_v1 * unit) <= 0.0f) {
                    var_a1 = (s32) ((f32) (u32) temp_v1 * unit);
                } else {
                    var_a1 = ((f32) (s32) ((f32) (u32) temp_v1 * unit) == ((f32) (u32) temp_v1 * unit)) ? 0 : 1;
                    var_a1 = var_a1 + (s32) ((f32) (u32) temp_v1 * unit);
                }
            }
            var_v1 = var_a1 + 1;
            if ((temp_f22 - 1.0f) <= (f32) var_v1) {
                temp_a0_2 = arg0->unkC;
                if (((f32) (u32) temp_a0_2 * unit) <= 0.0f) {
                    var_v1 = (s32) ((f32) (u32) temp_a0_2 * unit);
                } else {
                    var_v1 = ((f32) (s32) ((f32) (u32) temp_a0_2 * unit) == ((f32) (u32) temp_a0_2 * unit)) ? 0 : 1;
                    var_v1 = var_v1 + (s32) ((f32) (u32) temp_a0_2 * unit);
                }
            }
        }
        arg1->unk10 = (s32) (var_a1 * 4);
        arg1->unk14 = (s32) (var_v1 * 4);
        if (temp_f20 >= 0.0f) {
            var_a1 = (s32) temp_f20;
        } else {
            temp_f3_4 = (s32) temp_f20;
            var_a1 = ((f32) temp_f3_4 == temp_f20) ? 0 : 1;
            var_a1 = temp_f3_4 - var_a1;
        }
        if (temp_f22 <= (f32) var_a1) {
            temp_f1 = (f32) var_s0 * unit;
            if (temp_f1 <= 0.0f) {
                var_a1 = (s32) temp_f1;
                var_v1 = var_a1 + 1;
            } else {
                temp_f3_5 = (s32) temp_f1;
                var_a1 = ((f32) temp_f3_5 == temp_f1) ? 0 : 1;
                var_a1 = var_a1 + temp_f3_5;
                var_v1 = var_a1 + 1;
            }
        } else {
            var_v1 = var_a1 + 1;
        }
        if (temp_f22 <= (f32) var_v1) {
            temp_f1_2 = (f32) var_s0 * unit;
            if (temp_f1_2 <= 0.0f) {
                var_v1 = (s32) temp_f1_2;
                arg1->unk18 = var_a1 * 4;
            } else {
                temp_f3_6 = (s32) temp_f1_2;
                var_v1 = ((f32) temp_f3_6 == temp_f1_2) ? 0 : 1;
                var_v1 = var_v1 + temp_f3_6;
                        goto block_75;
            }
        } else {
block_75:
            arg1->unk18 = var_a1 * 4;
        }
        arg1->unk1C = (s32) (var_v1 * 4);
    }
}
