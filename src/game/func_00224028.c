#include "b05_types.h"

extern f32 D_800C7A38;
extern f32 D_800C7A3C;

typedef struct B05Def { u8 pad0[0xF4]; f32 unkF4; } B05Def;
typedef struct B05Obj { u8 pad0[0x18]; B05Def *def; } B05Obj;

void func_002748E0(void *, f32, f32);

void func_00224028(B05Obj *obj) {
    f32 v;
    if (obj->def != NULL) {
        v = obj->def->unkF4 * D_800C7A38;
    } else {
        v = D_800C7A3C;
    }
    func_002748E0((u8 *)obj + 0x740, v, 0.5f);
}
