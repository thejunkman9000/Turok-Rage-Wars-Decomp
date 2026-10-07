#include "b17_types.h"

void func_00276284(Hnd *h, s32 id);

void func_002761F4(Hnd *h) {
    if (h != 0 && (h->fl & 2)) {
        func_00276284(h, h->id);
    }
}
