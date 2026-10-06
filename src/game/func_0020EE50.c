#include "b02_types.h"

extern B2Node *D_8013B388;
extern f32 D_800C6FD0;

void func_0020EE50(void) {
    B2Node *n;

    for (n = D_8013B388; n != NULL; n = n->next) {
        n->unk18 = n->unk18 + (f32)(n->unk38 * 30) * D_800C6FD0;
    }
}
