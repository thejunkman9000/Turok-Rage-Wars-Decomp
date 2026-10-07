#include "b13_types.h"

typedef struct Idpair { u8 pad0[8]; s32 a; s32 b; } Idpair;

void func_0025C8E0(Idpair *p) {
    p->b = -1;
    p->a = -1;
}
