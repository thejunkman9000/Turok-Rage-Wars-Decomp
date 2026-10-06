#include "b03_types.h"

extern f32 D_800C70F0;
extern f32 D_800C70F4;

void func_002110C4(BrainB *b) {
    u32 i;

    if (b != NULL) {
        if (b->actor != NULL) {
            for (i = 0; i < 8; i++) {
                b->fa[i] = D_800C70F0;
                b->fb[i] = D_800C70F0;
            }
            b->step = 0;
            b->unk288 = 1;
            b->unk210 = D_800C70F4;
        }
    }
}
