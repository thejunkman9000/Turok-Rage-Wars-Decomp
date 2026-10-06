#include "b15_types.h"
void func_0025DEE0(s16 id, Vec3f pos, s32 a, void *src, f32 vol);
extern B15Globals D_801462C8;
extern f32 D_800C9514;
extern f32 D_800C9518;
extern f32 D_800C951C;

void func_00267324(s32 a, B15Src *src, s32 c, Vec3f pos, B15Blk8 k) {
    f32 vol;
    void *s;

    vol = D_800C9514;
    s = (void *)-1;
    if (D_801462C8.unk5CC == 0) {
        if (src != NULL) {
            switch (src->type) {
            case 1:
                if (src->def->type == 1) {
                    if (D_801462C8.flags0 & 0x40) {
                        vol = D_800C9518;
                    } else if (D_801462C8.flags0 & 0x20) {
                            vol = D_800C951C;
                    }
                }
                s = src;
                break;
            case 2:
                s = src;
                break;
            case 0:
                s = src->unkD0;
                break;
            }
        }
        func_0025DEE0(k.b, pos, 0, s, vol);
    }
}
