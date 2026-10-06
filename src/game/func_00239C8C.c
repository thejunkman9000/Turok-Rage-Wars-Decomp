#include "b08_types.h"

typedef struct LNode {
    struct LNode *next;
} LNode;

typedef struct LObj {
    u8 pad0[0xE40];
    s32 listE40;
    LNode *headE44;
    u8 padE48[0xDC];
    s32 listF24;
} LObj;

void func_00255E78(void *list, LNode *n);
void func_00255C58(void *list, LNode *n);

void func_00239C8C(LObj *a, LObj *b, LNode *n) {
    func_00255E78(&b->listE40, n);
    func_00255C58(&a->listF24, n);
}
