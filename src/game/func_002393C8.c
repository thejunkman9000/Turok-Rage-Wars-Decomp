#include "b08_types.h"

typedef struct ModeBlk2 {
    u8 padFC[0xFC];
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    f32 unk110;
    f32 unk114;
    s32 unk118;
} ModeBlk2;

extern f32 D_800C8630;

void func_002393C8(ModeBlk2 *p) {
    p->unkFC = 0;
    p->unk100 = 0;
    p->unk104 = 0;
    p->unk108 = 0;
    p->unk10C = 0;
    p->unk118 = 0;
    p->unk110 = D_800C8630;
    p->unk114 = D_800C8630;
}
