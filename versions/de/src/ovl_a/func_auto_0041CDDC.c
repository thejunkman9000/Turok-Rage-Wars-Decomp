#include "common.h"

typedef struct EuVec3 { s32 x, y, z; } EuVec3;
typedef struct EuObj { u8 pad0[0x48C]; EuVec3 unk48C; } EuObj;

void func_auto_0041CDDC(EuObj *o, EuVec3 v) {
    o->unk48C = v;
}
