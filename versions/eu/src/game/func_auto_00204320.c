#include "b01_types.h"

typedef struct V3Slot {
    s32 *a;
    s32 b;
} V3Slot;

typedef struct V3Other {
    u8 kind;
    u8 pad1[0xFF];
    u32 flags;
    u8 pad104[0xD4];
    struct V3Owner *owner;
} V3Other;

typedef struct V3Owner {
    u8 pad0[0x5DC];
    void *pawn;
} V3Owner;

extern u8 D_80145088[];
extern u8 D_801450C8[];
extern V3Slot D_auto_800E45D4[];
void func_002398F8(void *a, void *b, s32 c, B01Actor *actor, f32 f);
void func_0025E13C(s32 a);

s32 func_auto_00204320(B01Actor *actor, B01State *state, V3Other *other) {
    B01Info *info = B01_INFO(actor->def);
    if (info->unk16 != 0) {
        if (state->unk34 == 0 && other->kind == 1) {
            if (other->flags & 0x300000) {
                s32 idx = info->unk18;
                V3Owner *ow = other->owner;
                if (idx != 0) {
                    void *p = ow->pawn;
                    void *who = D_801450C8;
                    if (p != NULL) {
                        who = p;
                    }
                    func_002398F8(D_80145088, who, D_auto_800E45D4[idx].a[D_80145088[0x17C1]], actor, 4.0f);
                    if (D_auto_800E45D4[info->unk18].b != 0) {
                        func_0025E13C(D_auto_800E45D4[info->unk18].b);
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
