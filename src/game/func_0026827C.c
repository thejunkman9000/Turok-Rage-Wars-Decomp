#include "b15_types.h"

void func_0025DEE0(s16 id, Vec3f pos, s32 a, void *src, f32 vol);
extern B15Globals D_801462C8;
extern f32 D_800C9554;
extern f32 D_800C9558;
extern f32 D_800C955C;

void func_0026827C(B15Src *act, B15Src *src, s32 c, Vec3f pos, B15Blk8 k) {
    f32 vol;
    void *s;

    vol = D_800C9554;
    s = (void *)-1;
    if (D_801462C8.unk5CC != 0) {
        return;
    }
    switch (src->type) {
    case 0:
        if (act->def->unkE != k.c) {
            return;
        }
        s = src->unkD0;
        break;
    case 1:
        if (src->def->type == 1) {
            if (D_801462C8.flags0 & 0x40) {
                vol = D_800C9558;
            } else if (D_801462C8.flags0 & 0x20) {
                vol = D_800C955C;
            }
        }
        if ((src->unk17C & (1 << k.c)) == 0) {
            return;
        }
        break;
    }
    func_0025DEE0(k.b, pos, 0, s, vol);
}
