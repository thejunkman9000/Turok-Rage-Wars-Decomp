#include "b08_types.h"

typedef struct LNode {
    struct LNode *next;
} LNode;

typedef struct LObj {
    u8 pad0[0xE40];
    s32 listE40;
    LNode *headE44;
    u8 padE48[0xDC];
    LNode *listF24;
} LObj;

void func_00239CD0(LNode *n);
void func_00255E78(void *list, LNode *n);
void func_00255CB4(void *list, LNode *n);

LNode *func_00239C2C(LObj *a, LObj *b) {
    LNode *n;

    n = a->listF24;
    if (n != NULL) {
        func_00239CD0(n);
        func_00255E78(&a->listF24, n);
        func_00255CB4(&b->listE40, n);
    }
    return n;
}
