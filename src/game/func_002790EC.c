#include "b17_types.h"

void func_0025E13C(s32 id);
void func_0025E2F4(s32 id);

void func_002790EC(s32 a0, s32 a1, Evt *e) {
    if (e->id >= 0x100) {
        func_0025E13C(e->id);
    } else {
        func_0025E2F4(e->id);
    }
}
