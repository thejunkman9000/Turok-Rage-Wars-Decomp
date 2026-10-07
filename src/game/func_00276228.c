#include "b17_types.h"

void func_00276308(Hnd *h, s32 id);

void func_00276228(Hnd *h) {
    if (h != 0 && (h->fl & 2)) {
        func_00276308(h, h->id);
    }
}
