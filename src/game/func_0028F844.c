#include "common.h"

u32 osSetIntMask(u32 mask);

typedef struct Qn Qn;
struct Qn { Qn *next; s32 unk4; };
typedef struct { u8 pad0[0x2E0]; Qn *head2E0; } QOwner;

void func_0028F844(QOwner *o, Qn *n, s32 v) {
    u32 m = osSetIntMask(1);
    n->unk4 = v;
    n->next = o->head2E0;
    o->head2E0 = n;
    osSetIntMask(m);
}
