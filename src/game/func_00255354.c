#include "b12_types.h"

extern u32 D_80105190;
extern u32 D_80105198;
extern B12Bucket *D_80105194;

void func_00255354(u32 key, s32 val) {
    B12Bucket *b;
    B12Bucket *prev;
    u32 idx;
    b = &D_80105194[((key << 5) ^ (key >> 1) ^ (key >> 9) ^ (key >> 17)) & D_80105190];
    if (b->unk4 == 0) {
        b->unk0 = key;
        b->unk4 = val;
        return;
    }
    do {
        if (b->unk0 == key) {
            b->unk4 = val;
            return;
        }
        prev = b;
        b = b->next;
    } while (b);
    idx = prev->id | 1;
    if (D_80105194[idx].unk4 != 0) {
        for (;;) {
            idx += 2;
            idx &= D_80105198;
            if (D_80105194[idx].unk4 == 0) {
                break;
            }
        }
    }
    D_80105194[idx].unk0 = key;
    D_80105194[idx].unk4 = val;
    prev->next = &D_80105194[idx];
}
