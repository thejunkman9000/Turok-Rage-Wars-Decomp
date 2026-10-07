#include "b17_types.h"

void func_00217388(ActorX *a);
void func_00262CA8(ActorX *a);

void func_00279130(ActorX *a, u32 *p) {
    func_00217388(a);
    *p |= 0x20;
    a->flags &= ~0x10000;
    a->flags &= ~0x2000;
    a->flags &= ~0x100;
    if (a->flags & 0x80000) {
        func_00262CA8(a);
    }
}
