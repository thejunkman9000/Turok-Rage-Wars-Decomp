#include "o01_types.h"

typedef struct O01Rec36 { f32 f0; u8 pad[32]; } O01Rec36;
extern O01Ctx *D_800E2830;
void *func_0028FD94(void *tree, s32 idx);

f32 func_004039C4(void) {
    f32 sum = 0.0f;
    s32 i = 0;
    while (i < ((O01Node *)func_0028FD94(D_800E2830->tree, 0))->unk0) {
        O01Node *n = func_0028FD94(func_0028FD94(func_0028FD94(D_800E2830->tree, 0), i), 0);
        n = (O01Node *)((O01Rec36 *)n + n->unk4);
        sum += *(f32 *)n;
        i++;
    }
    return sum;
}
