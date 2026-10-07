#include "b12_types.h"

extern u32 D_80105180;
extern u8 D_80104570[];
extern u8 D_80104584[];
extern B12Node *D_80104568;
extern s32 D_8010513C;
extern B12Node **D_80104564;
extern u8 D_801051A0[];
void func_00254D70(s32 a, B12Node *n);
s32 func_00255ACC(void *list, s32 key);
void func_00255E78(void *list, B12Node *n);


inline B12Node *func_00254FE8(s32 unused, B12List *l, B12Node **out) {
    B12Node *n = (B12Node *)l->tail;
    if (*out == 0) {
        for (; n; n = n->link18) {
            if (!(n->flags & 0x702)) {
                if ((D_80105180 - n->unk10) >= 5) {
                    return n;
                }
                *out = n;
                break;
            }
        }
    }
    for (; n; n = n->link18) {
        if (!(n->flags & 0x702) && !((D_80105180 - n->unk10) < 5)) {
            return n;
        }
    }
    return 0;
}

s32 func_002512C8(s32 a0, s32 a1, s32 flag) {
    B12Node *fb = 0;
    B12Node *n;
    s32 r;
    n = func_00254FE8(0, (B12List *)D_80104570, &fb);
    if (!n) {
        if (flag == 0) {
            n = fb;
        }
    }
    if (n) {
        func_00254D70(0, n);
        r = func_00255ACC(D_801051A0, n->key);
        func_00255E78(D_80104570, n);
        if (n->flags & 0x1000) {
            func_00255E78(D_80104584, n);
        }
        if (D_80104568 == n) {
            D_80104568 = 0;
        }
        *(u32 *)((u8 *)n + 0xC) = 0;
        {
            B12Node **tab = D_80104564;
            *(B12Node **)((u8 *)tab + D_8010513C * 4) = n;
        }
        D_8010513C++;
        return r;
    }
    return 0;
}
