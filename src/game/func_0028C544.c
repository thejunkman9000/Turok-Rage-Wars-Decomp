#include "b20_types.h"

typedef struct { u8 pad0[0xC]; u16 unkC; u8 unkE; } SndDesc;

void func_00255E78(Obj2 **list, Obj2 *n);
void func_00255C58(s32 *list, Obj2 *n);
void func_00278C80(void *p);
f32 Trunc16ToF32(u16 v);

void func_0028C544(Level *lv, SndDesc *s) {
    Obj2 *n = lv->unk11EC;
    f32 f;
    if (n != 0) {
        func_00255E78(&lv->unk11EC, n);
        func_00255C58(&lv->unk11D8, n);
        n->unk8 = s;
    } else {
        n = lv->unk11DC;
        func_00278C80(n->unk8);
        n->unk8 = s;
    }
    f = Trunc16ToF32(s->unkC);
    n->unkC = f;
    if (s->unkE & 2) {
        n->unkC = f * 15.0f;
    }
}
