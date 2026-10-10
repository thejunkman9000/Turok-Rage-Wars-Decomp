/* GROUP: func_0043F404 inlines the typed getter func_00443030 and setter func_00443120 */
#include "o06_types.h"
struct O06A;
typedef struct { char *unk0; s32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; void *(*unk18)(struct O06A *); } O06D;
typedef struct O06A { u8 pad[0x14]; O06D *unk14; } O06A;
typedef struct { u8 pad[0x20]; void *unk20; } O06B;
extern s32 func_002643A8(void *a);
extern s32 func_002643C0(void *a);
static inline f32 func_00443030(O06A *a) {
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
static inline void func_00443120(O06A *a, f32 v) {
    O06D *d = a->unk14;
    void *p = d->unk18(a);
    switch (d->unk4) {
    case 0: *(f32 *)p = v; return;
    case 3: *(s8 *)p = (s32)v; return;
    case 4: *(s16 *)p = (s32)v; return;
    case 1: case 2: case 5: *(s32 *)p = (s32)v; return;
    case 6: *(u8 *)p = (u32)v; return;
    case 7: *(u16 *)p = (u32)v; return;
    case 8: *(u32 *)p = (u32)v; return;
    }
}
s32 func_0043F404(O06A *a, O06B *b) {
    O06D *d = a->unk14;
    f32 v;
    v = func_00443030(a);
    if (func_002643A8(b->unk20)) {
        v -= d->unk10;
        if (v < d->unk8) v = d->unk8;
    } else if (func_002643C0(b->unk20)) {
        v += d->unk10;
        if (d->unkC < v) v = d->unkC;
    }
    func_00443120(a, v);
    return 0;
}
