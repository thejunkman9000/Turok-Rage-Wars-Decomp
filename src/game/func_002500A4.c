#include "b12_types.h"

extern f32 D_800C8F40;
void func_00271FD8(f32 *out, void *a, void *b);

s32 func_002500A4(B12Obj *o, s32 a1) {
    f32 v[3];
    f32 d;
    u32 dist;
    s32 e;
    B12Def *def;
    func_00271FD8(v, (void *)(a1 + 0x128), o->pos);
    d = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    dist = (u32)d;
    o->unkDC = dist;
    def = o->def;
    if (dist >= def->unk24 * 2) {
        e = def->unkF;
    } else {
        e = def->unkE;
    }
    if (e == -1) {
        if (o->unkE0 <= 0) {
            o->unkE0 = 0;
            o->unkD8 |= 4;
            return 0;
        }
        if (o->unkD8 & 0x200) {
            o->unkD8 |= 4;
            o->unkE0 = 0;
            return 0;
        }
        o->unkE0 = (u8)o->unkE0 - 1;
        if (o->unkE0 < 0) {
            o->unkE0 = 0;
        }
        o->unkD8 |= 4;
    } else if (o->unkE0 < 8) {
        if (o->unkD8 & 0x200) {
            o->unkE0 = 8;
            o->unkD8 &= ~4;
        } else {
            o->unkE0 = (u8)o->unkE0 + 1;
            o->unkD8 |= 4;
        }
    } else {
        o->unkE0 = 8;
    }
    return 1;
}
