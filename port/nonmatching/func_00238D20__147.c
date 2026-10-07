#include "b08_types.h"

typedef struct ScreenObj {
    u8 pad0[8];
    s32 unk8;
    u8 pad0C[0x1D4];
    u8 unk1E0[1];
} ScreenObj;

typedef struct Emitter {
    u8 pad0[8];
    Vec3f pos;
    u8 pad14[0x48];
    u32 unk5C;
    u8 pad60[0xB8];
    u32 *unk118;
    u8 pad11C[0x7C];
    f32 unk198;
    u8 pad19C[0x58];
    struct Emitter *next1F4;
} Emitter;

typedef struct Vec2f {
    f32 x, y;
} Vec2f;

void func_002AA224(s32 a);
void func_0026925C(s32 a);
void func_00272A80(void *a, Vec3f *b, Vec3f *out);
void func_00238660(void *a, f32 sx, f32 sy, f32 sc, s32 c, s32 d);

extern DlCmd *D_80110634;
extern Emitter *D_801315A4;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern f32 D_800C8604;

static inline void worldToScreen(ScreenObj *a, Vec3f *pos, f32 *outx, f32 *outy) {
    Vec3f v;

    func_00272A80(a->unk1E0, pos, &v);
    *outx = v.x * (f32)(D_800E28D0 / 2) + (f32)(D_800E28D0 / 2);
    *outy = v.y * (f32)(-D_800E28D4 / 2) + (f32)(D_800E28D4 / 2);
}

void func_00238D20(ScreenObj *a) {
    Emitter *e;
    DlCmd *dl;
    f32 sx, sy;
    s32 mask;

    mask = 8 << a->unk8;
    func_002AA224(0x64);
    func_0026925C(0x1A);
    dl = D_80110634++;
    dl->w1 = 0x2000;
    dl->w0 = 0xE3001201;
    for (e = D_801315A4; e != NULL; e = e->next1F4) {
        if ((e->unk5C & mask) && (*e->unk118 & 0x80000)) {
            worldToScreen(a, &e->pos, &sx, &sy);
            func_00238660(a, sx, sy, e->unk198 * D_800C8604, 0, 0);
        }
    }
}

