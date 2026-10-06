#include "b21_types.h"

void func_44AFC0(void *a);
void func_44A600(void *a, s32 b, s32 c);

void func_00293318(B21Game *g, s32 a, s32 b) {
    func_44AFC0(g->sub255C8);
    func_44A600(g->sub25580, a, b);
}
