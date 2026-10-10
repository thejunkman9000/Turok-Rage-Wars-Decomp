#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "stddef.h"
/* Picks an actor's target (the tracked enemy when the aim point is chosen, else the nearest permitted target from func_802149C0_de), classifies it into one of eight kinds, and fills the target record with the kind, target, height difference, position, direction and distance, both in full and flattened to the horizontal plane. */
extern s32 D_8011CD20,D_8013B290;
extern void *func_802149C0_de(void *,void *,s32,s32), *func_80219408_de(void *);
extern f32 func_80216F44_de(void *,f32,f32,f32),func_802B72B0_de(f32);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
static inline s32 func_80215410_kind(void *self, void *ctx, void *target) {
    if (((func_80203E78_S1 *)(ctx))->unk4 == 0) {
        return 6;
    }
    if (target == NULL) {
        if (((Field_s8_94 *)(ctx))->value != 0) {
            return 4;
        }
        return 3;
    }
    if (target == ((Field_void_68 *)(ctx))->value) {
        return 2;
    }
    if (((struct Shape_func_8021A2D4_de_2 *)(((func_80205314_S1 *)(target))->unk18))->field_0 == 5) {
        return 5;
    }
    if (((struct Owner_func_8020388C_de *)(target))->id == 0x64F) {
        return 7;
    }
    if (D_8013B290 == 0) {
        if ((((func_80203C40_S1 *)(target))->unk100 & 0x300000) && ((Field_void_794 *)(((func_8020A028_S3 *)(target))->unk1D8))->value == self
            && ((Field_s32_788 *)(((func_8020A028_S3 *)(target))->unk1D8))->value == 2) {
            return 1;
        }
        if ((((Field_s32_2E0 *)(self))->value & 2) && ((struct Owner_func_8020388C_de *)(self))->id != 0xCA) {
            return 1;
        }
    }
    return 0;
}
void func_80215410_de(void *arg0, void *arg1, s32 unused, void *arg3) {
    Vec3 pos;
    Vec3 delta;
    f32 height;
    s32 kind;
    void *target;
    void *point;
    if ((((Field_s8_CE *)(arg1))->value == D_8011CD20) && !(((func_80203E78_S1 *)(((func_80205314_S1 *)(arg0))->unk18))->unk4 & 0x400) && (!(((struct Shape_func_8021A2D4_de_2 *)(arg1))->field_0 & 0x80000) || (((func_8020EA10_S1 *)(arg1))->unk78 != 0))) {
        ((Field_void_80 *)(arg1))->value = func_802149C0_de(arg0, arg1, 1, 0);
    }
    if ((((struct Shape_func_8021A2D4_de_2 *)(((func_80205314_S1 *)(arg0))->unk18))->field_0 == 1) && (((func_80203C84_S1 *)(arg1))->unk34 == 0xB)
        && func_80215410_kind(arg0, arg1, ((Field_void_88 *)(arg1))->value) == 4) {
        target = ((Field_void_88 *)(arg1))->value;
        kind = 4;
    } else {
        target = ((Field_void_80 *)(arg1))->value;
        kind = func_80215410_kind(arg0, arg1, target);
    }
    if (target != NULL) {
        pos = ((Player *)(target))->pos;
        height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
    } else {
        switch (kind) {
            case 4:
                point = func_80219408_de((char *)arg1 + 0x94);
                pos = ((Field_Vec_0 *)(point))->value;
                if (((Field_u16_14 *)(point))->value & 1) {
                    height = ((Field_f32_10 *)(point))->value * 0.0174532942f - ((func_80203908_S4 *)(arg0))->unk6C;
                } else {
                    height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
                }
                break;
            case 3:
                pos = ((Field_Vec_B0 *)(arg1))->value;
                height = ((Field_f32_9C *)(arg1))->value - ((func_80203908_S4 *)(arg0))->unk6C;
                break;
            case 6:
                pos = ((Player *)(arg0))->pos;
                height = 0.0f;
                break;
        }
    }
    func_80274020_de(&height);
    func_80271F68_de(&delta, &pos, &((Player *)(arg0))->pos);
    ((func_80212828_S7 *)(arg3))->unk8 = height;
    ((struct Shape_func_8021A2D4_de_2 *)(arg3))->field_0 = kind;
    ((Field_void_4 *)(arg3))->value = target;
    ((Field_Vec_C *)(arg3))->value = pos;
    ((Field_Vec_18 *)(arg3))->value = delta;
    ((Field_f32_24 *)(arg3))->value = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
    delta.y = 0.0f;
    pos.y = 0;
    ((Field_Vec_28 *)(arg3))->value = pos;
    ((Field_Vec_34 *)(arg3))->value = delta;
    ((func_802077F4_S4 *)(arg3))->unk40 = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}
