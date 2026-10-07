#include "b08_types.h"

typedef struct Row44 {
    u8 pad0[0x44];
    u32 unk44;
} Row44;

typedef struct ObjF4 {
    u8 pad0[0x58];
    s32 unk58;
    u8 pad5C[0x98];
    f32 unkF4;
    f32 unkF8;
} ObjF4;

Row44 *func_0028B2D4(void *tbl, s32 key);
f32 func_00274B00(f32 a, f32 b);

extern u8 D_8011FE88[];
extern f32 D_800C8668;
extern f32 D_800C866C;
extern f32 D_800C8670;
extern f32 D_800C8674;
extern f32 D_800C8678;
extern f32 D_800C867C;

void func_00239E94(ObjF4 *o, Vec3f *out) {
    Row44 *r;
    f32 tx, ty;
    f32 k;

    tx = ty = 0.0f;
    r = func_0028B2D4(D_8011FE88, o->unk58);
    if (r == NULL) {
        out->x = ty;
        out->y = ty;
        out->z = ty;
        return;
    }
    if (r->unk44 & 0x10000) {
        tx = D_800C8668;
        ty = D_800C866C;
    }
    o->unkF4 = o->unkF4 + (tx - o->unkF4) * D_800C8670;
    k = D_800C8674;
    o->unkF8 = o->unkF8 + (ty - o->unkF8) * D_800C8678;
    out->x = func_00274B00(-o->unkF4 * k, o->unkF4 * k);
    out->y = func_00274B00(0.0f, o->unkF8 * D_800C867C);
    out->z = func_00274B00(-o->unkF4 * k, o->unkF4 * k);
}
