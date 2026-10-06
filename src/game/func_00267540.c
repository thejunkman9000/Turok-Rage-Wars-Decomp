#include "p3_types.h"

typedef struct { s32 kind; } P3Kind;
typedef struct {
    u8 pad0[0x18];
    P3Kind *info;          /* 0x18 */
    u8 pad1C[0xE4 - 0x1C];
    u16 id;                /* 0xE4 */
    u8 padE6[0x100 - 0xE6];
    u32 flags;             /* 0x100 */
} P3Actor;

extern u8 D_801462E5;
extern s32 D_8013B290;

s32 func_00267540(P3Actor *a, P3Actor *b) {
    if (D_801462E5 != 0) {
        return 1;
    }
    if (a->id == b->id || !(b->flags & 0x310000)) {
        return 0;
    }
    if (D_8013B290 != 0 && !(a->flags & 0x300000) && !(b->flags & 0x300000)) {
        return 0;
    }
    switch (b->info->kind) {
    case 1:
    case 4:
    case 7:
    case 0xB:
        return 1;
    }
    return 0;
}
