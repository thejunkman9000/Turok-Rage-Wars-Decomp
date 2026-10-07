#include "b09_types.h"

extern B09Region D_80103F88;

B09Region *func_0023CBB0(u32 addr) {
    B09Region *r;
    for (r = &D_80103F88; r != NULL; r = r->next) {
        if (addr >= r->base && addr < r->base + r->size) {
            break;
        }
    }
    return r;
}
