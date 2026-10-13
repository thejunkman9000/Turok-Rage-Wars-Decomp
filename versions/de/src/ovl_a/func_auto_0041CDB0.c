#include "common.h"

typedef struct EuVec3 { s32 x, y, z; } EuVec3;
typedef struct EuObj { u8 pad0[0x480]; EuVec3 unk480; } EuObj;

void func_auto_0041CDB0(EuObj *o, EuVec3 v) {
    o->unk480 = v;
}
