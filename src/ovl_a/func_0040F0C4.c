#include "o02_types.h"
typedef struct S_func_0040F0C4 { struct S_func_0040F0C4 *parent; struct S_func_0040F0C4 *next; struct S_func_0040F0C4 *child; u8 padC[2]; u16 type; u8 pad10[0x2C-0x10]; } S_func_0040F0C4;
void func_0040F0C4(S_func_0040F0C4 *a, S_func_0040F0C4 *b) {
    S_func_0040F0C4 *pa, *pb, *c;
    S_func_0040F0C4 tmp;
    pa = a;
L1:
    if (pa->type == 2) goto L2;
    pa = pa->parent;
    goto L1;
L2:
    pa = a->parent;
    c = pa->child;
    pa = 0;
    goto L3;
L4:
    c = pa->next;
L3:
    if (c == a) goto L5;
    pa = c;
    if (pa != 0) goto L4;
L5:
    pb = b->parent;
    c = pb->child;
    pb = 0;
    goto L6;
L7:
    c = pb->next;
L6:
    if (c == b) goto L8;
    pb = c;
    if (pb != 0) goto L7;
L8:
    if (pa) pa->next = b; else a->parent->child = b;
    if (pb) pb->next = a; else b->parent->child = a;
    tmp = *a;
    a->next = b->next;
    a->parent = b->parent;
    b->next = tmp.next;
    b->parent = tmp.parent;
}
