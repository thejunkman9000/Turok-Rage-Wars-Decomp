#include "o06_types.h"
struct O06A;
typedef struct { char *unk0; s32 unk4; u8 pad8[0xC]; f32 unk14; void *(*unk18)(struct O06A *); } O06D;
typedef struct O06A { u8 pad[0x14]; O06D *unk14; } O06A;
extern s32 sprintf(char *buf, const char *fmt, ...);
extern char D_801540A0[];
extern char D_80154060[];
extern char D_800E23B0[];
extern char D_800E23B8[];
extern char D_800E23C0[];
char *func_0043F290(O06A *a) {
    O06D *d = a->unk14;
    void *p = d->unk18(a);
    f32 r;
    switch (d->unk4) {
    default: r = 0.0f; break;
    case 0: r = *(f32 *)p; break;
    case 3: r = (f32)*(s8 *)p; break;
    case 4: r = (f32)*(s16 *)p; break;
    case 1: case 2: case 5: r = (f32)*(s32 *)p; break;
    case 6: r = (f32)*(u8 *)p; break;
    case 7: r = (f32)*(u16 *)p; break;
    case 8: r = (f32)*(u32 *)p; break;
    }
    sprintf(D_801540A0, D_800E23B0, (f64)(r / d->unk14));
    if (d->unk0) sprintf(D_80154060, D_800E23B8, d->unk0, D_801540A0);
    else sprintf(D_80154060, D_800E23C0, D_801540A0);
    return D_80154060;
}
