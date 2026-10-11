
#include "b24_types.h"
typedef struct TabInfo {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
} TabInfo;
extern s32 D_800D29B4;
extern u8 D_8011FE88[];
s32 func_0028BE88(u8 *, s32, s32, s32);
void func_002AB8DC(s32, s32, void **, u8 *);
void func_002536F4(s32, s32);
void func_002AB940(s32 id, s32 idx, s32 *out1, s32 *out2) {
    TabInfo *info;
    u8 b;
    s32 h;
    TabInfo *q;
    if (D_800D29B4 != 0) {
        h = func_0028BE88(D_8011FE88, id, 0, 1);
        if (h != 0) {
            func_002AB8DC(h, idx, (void **)&info, &b);
            q = info;
            *out1 = q->unk4;
            *out2 = q->unk6;
            func_002536F4(0, h);
        }
    }
}