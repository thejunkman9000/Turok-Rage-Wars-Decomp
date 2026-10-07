#include "b12_types.h"

extern B12Pool D_80103F70;
void func_00255F58(void *list, B12Node *n);

void func_00254D44(s32 unused, B12Node *n) {
    n->unk10 = D_80103F70.stamp;
    func_00255F58(&D_80103F70.list, n);
}
