#include "b24_types.h"

typedef struct Sprt {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x20];
    /* 0x38 */ s32 unk38;
} Sprt;

void func_002AB6C0(Sprt *s, s16 a, s16 b) {
    s->unk38 = -1;
    s->unk10 = a;
    s->unk0 = 0;
    s->unk8 = 0;
    s->unk14 = b;
}
