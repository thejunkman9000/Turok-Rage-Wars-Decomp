#include "b02_types.h"

typedef struct G20Actor {
    u8 pad0[0x5F4];
    s16 h5F4;
    s16 h5F6;
    s16 h5F8;
} G20Actor;

extern f32 D_800C7010;
extern f32 D_800C7014;
extern f32 D_800C7018;
extern f32 D_800C701C;
extern f32 D_800C7020;
extern f32 D_800C7024;
extern u8 D_80145040[];
extern B2GameFlags D_801468A0[];
extern s32 D_80146938;

void func_00209874(B2Ctl *ctl, s32 state);
s32 func_00209A94(B2Ctl *ctl);
s32 func_00209AD8(B2Ctl *ctl);
f32 func_00209B64(B2Ctl *ctl);
s32 func_0020EA10(B2Ctl *ctl);
s32 func_0020F5A4(B2Ctl *ctl);
B2Actor *func_0022A82C(void *world);
s32 func_0022AAC4(B2Actor *a, s16 id);
s32 func_0022AB10(B2Actor *a, s16 id);
s32 func_0022ABF0(B2Actor *a);
s32 func_0022ACA8(B2Actor *a, s32 x, s32 n);

s32 func_0020FA10(B2Ctl *ctl) {
    s32 s0;
    s32 v;
    s32 d;
    f32 k;
    f32 fs0f;
    f32 fs0;
    s32 s2, s3, s4;
    B2Actor *p;
    s32 a1;
    s32 var_s0;
    s32 var_v0;
    s32 cur;
    B2Stats *st;

    s0 = ctl->owner->unk5E4;
    do {
    s0 >>= 8;
    d = func_0022ABF0(ctl->owner) >> 8;
    fs0f = ((f32)s0 / (f32)d) * (k = D_800C7010);
    s0 = func_0022AB10(ctl->owner, ctl->owner->unk62E);
    v = func_0022ACA8(ctl->owner, func_0022AAC4(ctl->owner, ctl->owner->unk62E), 1);
    if (v != 0 && s0 != -1) {
        fs0 = ((f32)s0 / (f32)v) * k;
    } else {
        fs0 = D_800C7014;
    }
    s2 = ((G20Actor *)ctl->owner)->h5F4;
    s3 = ((G20Actor *)ctl->owner)->h5F6;
    s4 = ((G20Actor *)ctl->owner)->h5F8;
    p = func_0022A82C(D_80145040);
    if (p != NULL && *(s32 *)(D_80145040 + 0x18D8) != 0) {
        if (p == ctl->owner) {
            func_00209874(ctl, 10);
            goto done;
        }
        if (ctl->target != NULL) {
            func_00209874(ctl, 1);
            goto done;
        }
    }
    if (D_801468A0->unk54 != 0 && ctl->owner->stats->unk8F != 0) {
        if (D_801468A0->unk68 > 0) {
            if (ctl->curId != 2) {
                func_00209874(ctl, 2);
                ctl->unk2F4 = 1;
                ctl->unk2F8 = 1;
                return 1;
            }
            goto done;
        }
        func_00209874(ctl, 11);
        goto done;
    }
    var_s0 = (s32)((D_800C7018 - func_00209B64(ctl)) * D_800C701C);
    if (D_80146938 != 0 && ctl->owner->stats->unk94 != 0) {
        var_s0 = 0;
    }
    if (func_00209AD8(ctl) == 0) {
        var_v0 = 1;
        if (fs0f < (f32)var_s0) {
b20:
            ctl->unkBC = var_v0;
b21:
            func_00209874(ctl, 8);
            goto done;
        }
    }
    if (func_00209AD8(ctl) == 0 && fs0 < D_800C7020) {
        ctl->unkBC = func_0020F5A4(ctl);
        goto b21;
    }
    cur = ctl->curId;
    if ((((u32)(cur - 3) >= 2U) && (cur != 0xD)) || !(s2 < 0xA) || (s3 >= 0xA) || (var_v0 = 4, (s4 > 0))) {
        if (func_00209A94(ctl) != 0 && ctl->target == NULL) {
b32:
            func_00209874(ctl, 2);
            goto done;
        }
        if (func_0020EA10(ctl) != 0 && (cur = ctl->curId, cur != 9)) {
            if ((u32)(cur - 1) < 2U) {
                func_00209874(ctl, 9);
                goto done;
            }
        } else if (func_00209AD8(ctl) == 0 || !((f32)var_s0 < fs0f) || !(D_800C7024 < fs0)) {
            if (func_00209A94(ctl) == 0 && func_00209AD8(ctl) == 0 && ctl->target != NULL) {
                st = ctl->owner->stats;
                if (st->unk94 != 0) {
                    if (st->unk80 == 0xC) {
                        func_00209874(ctl, 13);
                        goto done;
                    } else if (var_s0) {
                        goto b47;
                    } else {
                        goto b47;
                    }
                } else {
b47:
                    func_00209874(ctl, 1);
                }
                goto done;
            }
        } else {
            goto b32;
        }
    } else {
        goto b20;
    }
    } while (0);
done:
    return 1;
}
