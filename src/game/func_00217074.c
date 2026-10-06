#include "b04_types.h"
void func_00274090(f32 *);
typedef struct { u8 pad0[0x6C]; f32 unk6C; } B04Obj;
void func_00217074(B04Obj *o, f32 d) {
    o->unk6C = o->unk6C + d;
    func_00274090(&o->unk6C);
}
