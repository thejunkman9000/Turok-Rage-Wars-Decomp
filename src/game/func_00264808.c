#include "b14_types.h"
void func_00264268(void *p);
typedef struct { u8 pad[0xCC]; s32 unkCC; } T808;
void func_00264808(T808 *p, s32 v) {
    p->unkCC = v;
    if (v == 0) {
        func_00264268(p);
    }
}
