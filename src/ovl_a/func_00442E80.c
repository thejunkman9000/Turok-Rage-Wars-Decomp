/* GROUP file: func_00442E48, func_00442E64, func_00442E80 (contiguous ROM span 0x1B0E48..); the first two are inlined into the third */
#include "o06_types.h"
typedef struct { u8 b[4]; } O06C4;
typedef struct { u8 pad[0x478]; s32 unk478; } O06A;
typedef struct { s32 unk0; s16 unk4; s16 pad6; u32 unk8; s16 unkC; s16 unkE; u8 unk10; u8 unk11; u8 unk12; u8 unk13; s32 unk14; s32 unk18; s32 unk1C; O06A *unk20; s32 unk24; } O06E;
typedef struct { s16 unk0; s16 pad2; s32 unk4; s16 unk8; s16 unkA; u8 unkC; u8 unkD; u8 unkE; u8 unkF; s32 unk10; } O06S;
inline s32 func_00442E48(s16 *a) { if (*a == 3) return 0x480; return 0; }
inline void func_00442E64(s16 *a, O06A *b) { if (*a == 3) b->unk478 = 1; }
void func_00442E80(O06E *a, O06S *b, O06A **c, s32 d, s32 e) {
    s32 sz;
    a->unk0 = d;
    a->unk4 = b->unk0;
    a->unk8 = b->unk4 | 0x1800000;
    a->unkC = b->unk8;
    a->unkE = b->unkA;
    a->unk10 = b->unkC;
    a->unk11 = b->unkD;
    a->unk12 = b->unkE;
    a->unk13 = b->unkF;
    a->unk14 = b->unk10;
    a->unk18 = (s32)b;
    a->unk1C = -1;
    a->unk24 = e;
    sz = func_00442E48((s16 *)b);
    if (sz) {
        a->unk20 = *c;
        func_00442E64((s16 *)b, *c);
        *c = (O06A *)((u8 *)*c + func_00442E48((s16 *)b));
    }
}
