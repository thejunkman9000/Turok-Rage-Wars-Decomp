#include "common.h"

typedef struct EuObj { u8 pad0[0x498]; s32 unk498; } EuObj;

void func_auto_0041D248(EuObj *o, s32 v) {
    o->unk498 = v;
}
