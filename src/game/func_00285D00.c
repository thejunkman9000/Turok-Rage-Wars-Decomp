#include "b19_types.h"
u32 __osDisableInt(void);
void __osRestoreInt(u32);
void func_00255E78(void *, void *);
void func_00255CB4(void *, void *);
void func_00285D00(B19Pool *p) {
    u32 mask = __osDisableInt();
    B19PNode *n = p->head;
    B19PNode *next;
    while (n != 0) {
        next = n->next;
        func_00255E78(&p->head, n);
        func_00255CB4(p, n);
        n = next;
    }
    p->count = 0;
    __osRestoreInt(mask);
}
