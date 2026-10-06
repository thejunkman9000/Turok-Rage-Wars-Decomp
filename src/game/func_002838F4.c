#include "b19_types.h"
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
void func_0027DAA4(B19Obj *, s32, s32);
void func_002A5588(void *, B19Obj *, s32);
s32 func_00268BE0(void *, s32);
void func_0028438C(B19Obj *, s32);
void func_0025DE74(s16, f32, f32, f32, s32, s32);
void func_002838F4(B19Obj *o, B19Def *def) {
    s32 t;
    func_0027DAA4(o, 0, 0);
    if (def->b6 != -1) func_002A5588(D_8013BA80, o, def->b6);
    if (def->b7 != -1) o->unk138 = func_00268BE0(D_8013B1A8, def->b7);
    else o->unk138 = 0;
    if (!(o->flags & 0x200000) && (t = def->sC) != 0) {
        switch (o->id) {
        case 0x22:
        case 0x5F:
        case 0x60:
            func_0028438C(o, t);
            break;
        default:
            func_0025DE74(t, o->pos.x, o->pos.y, o->pos.z, 0, -1);
            break;
        }
    }
}
