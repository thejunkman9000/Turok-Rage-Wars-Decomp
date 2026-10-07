/* PARTIAL: identical code, callee-saved register numbering differs (ROM: act=s1 src=s0 s=s2 G=s3) */
#include "b15_types.h"

void func_0025DEE0(s16 id, Vec3f pos, s32 a, void *src, f32 vol);
s32 func_0024E958();
extern B15Globals D_801462C8;
extern f32 D_800C9568;
extern f32 D_800C956C;
extern f32 D_800C9570;

void func_00268768(B15Src *act, B15Src *src, s32 c, Vec3f pos, B15Blk8 k) {
    f32 vol = D_800C9568;
    void *s = (void *)-1;
    if (D_801462C8.unk5CC == 0 && func_0024E958() == k.c) {
        switch (src->type) {
        case 0:
            s = src->unkD0;
            break;
        case 1:
            if (act->def->type == 1) {
                if (D_801462C8.flags0 & 0x40) {
                    vol = D_800C956C;
                }
                if (D_801462C8.flags0 & 0x20) {
                    vol = D_800C9570;
                }
            }
            break;
        }
        func_0025DEE0(k.b, pos, 0, s, vol);
    }
}
