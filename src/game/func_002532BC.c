#include "b12_types.h"

void func_002532BC(B12Node *n) {
    if (--n->refs == 0) {
        n->flags &= ~0x100;
    }
}
