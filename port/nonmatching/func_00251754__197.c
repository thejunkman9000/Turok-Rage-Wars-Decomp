#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u32 D_80105190;
extern B12Bucket *D_80105194;
extern u32 D_80105180[];
extern u8 D_80104570[];
void func_00255F58(void *list, B12Node *n);

static inline void hashFind(u32 key, B12Node ***out) {
    B12Bucket *b = &D_80105194[((key << 5) ^ (key >> 1) ^ (key >> 9) ^ (key >> 17)) & D_80105190];
    if (b->unk0 == key) {
        *out = (B12Node **)b->unk4;
        return;
    }
    *out = 0;
    for (; b; b = b->next) {
        if (b->unk0 == key) {
            *out = (B12Node **)b->unk4;
            break;
        }
    }
}

B12Node *func_00251754(s32 unused, u32 key) {
    u32 mask;
    u32 m2;
    B12Node **res;
    B12Node *n;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    hashFind(key, &res);
    n = 0;
    if (res) {
        n = *res;
        n->refs++;
        n->flags |= 0x100;
        n->unk10 = D_80105180[0];
        func_00255F58(D_80104570, n);
    }
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    return n;
}
