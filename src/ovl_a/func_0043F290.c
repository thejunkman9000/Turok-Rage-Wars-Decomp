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
inline f32 func_00443030(O06A *a) {
    O06D *d = a->unk14;
    void *p = d->unk18(a);
    switch (d->unk4) {
    default: return 0.0f;
    case 0: return *(f32 *)p;
    case 3: return (f32)*(s8 *)p;
    case 4: return (f32)*(s16 *)p;
    case 1: case 2: case 5: return (f32)*(s32 *)p;
    case 6: return (f32)*(u8 *)p;
    case 7: return (f32)*(u16 *)p;
    case 8: return (f32)*(u32 *)p;
    }
}
char *func_0043F290(O06A *a) {
    O06D *d = a->unk14;
    f32 r = func_00443030(a);
    r = r / d->unk14;
    sprintf(D_801540A0, D_800E23B0, (f64)r);
    if (d->unk0) sprintf(D_80154060, D_800E23B8, d->unk0, D_801540A0);
    else sprintf(D_80154060, D_800E23C0, D_801540A0);
    return D_80154060;
}
