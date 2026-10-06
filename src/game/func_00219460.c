#include "b04_types.h"
typedef struct { s32 unk0; s32 unk4; u8 pad8[4]; s16 unkC; s8 unkE; u8 padF[3]; s8 unk12; } B04Rec;
void func_00219460(B04Rec *p) {
    p->unk4 = 1;
    p->unk0 = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk12 = -1;
}
