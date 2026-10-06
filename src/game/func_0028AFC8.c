#include "common.h"

typedef struct { u8 pad0[0x70]; s32 *unk70; } Obj;
void *func_0028FD94();

void func_0028AFC8(Obj *o) {
    func_0028FD94(o->unk70);
}
