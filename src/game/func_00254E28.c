#include "p2_types.h"

extern List D_8010510C;
void func_00255E78(List *l, PNode *n);
void func_00255C58(void *l, PNode *n);

void func_00254E28(void *unused, PNode *n) {
    func_00255E78(&D_8010510C, n);
    n->f10 = 0;
    func_00255C58((u8 *)&D_8010510C - 0x14, n);
}