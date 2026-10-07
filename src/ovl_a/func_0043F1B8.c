#include "o06_types.h"
typedef struct { u8 pad[0x20]; s16 unk20; s16 unk22; } O06X;
typedef struct { u8 pad[0x18]; O06X *unk18; } O06A;
typedef struct { u8 pad[0x644]; u8 unk644[9]; u8 unk64D; u8 unk64E; } O06Y;
typedef struct { u8 pad[0x1C]; O06Y *unk1C; } O06B;
s32 func_0043F1B8(O06A *a, O06B *b) {
    O06X *x = a->unk18; s32 id = x->unk20; s32 idx = x->unk22; O06Y *y = b->unk1C; s32 r = 0;
    switch (id) {
    case 0x10FE:
        if (idx >= 0) {
            if (idx < 3) goto A;
            if (idx < 6) goto B;
            break;
        A: r = idx < y->unk64D; break;
        B: r = (idx - 3) < y->unk64E; break;
        }
        break;
    case 0x1194: r = y->unk644[idx] != 0; break;
    }
    return r;
}
