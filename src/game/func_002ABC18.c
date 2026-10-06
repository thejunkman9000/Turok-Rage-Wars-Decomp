#include "b24_types.h"

typedef struct DlOwner {
    u8 pad0[0x114];
    u32 unk114;
} DlOwner;

extern DlOwner *D_8011FE80;
extern DlCmd *D_80110634;
extern s32 D_800E28A4;
extern s32 D_800D29B4;
extern u8 D_8011FE88[];
s32 func_0028BE88(u8 *, s32, s32, s32);
void func_002AB19C(s32, s32, s16, s16, f32, f32, s32);
void func_002536F4(s32, s32);

s32 func_002ABC18(s32 id, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g) {
    s32 h;
    if ((u32)(D_800E28A4 - (((u32)D_80110634 - D_8011FE80->unk114) >> 3)) < 0x3E8 ||
        D_800D29B4 == 0 ||
        (h = func_0028BE88(D_8011FE88, id, 0, 1)) == 0) {
        return 0;
    }
    func_002AB19C(h, b, c, d, e, f, g);
    func_002536F4(0, h);
    return 1;
}
