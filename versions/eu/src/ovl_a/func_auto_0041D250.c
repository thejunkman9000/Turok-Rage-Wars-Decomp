#include "common.h"

typedef struct EuObj { u8 pad0[0x49C]; s32 unk49C; } EuObj;

void func_auto_0041D250(EuObj *o, s32 v) {
    o->unk49C = v;
}
