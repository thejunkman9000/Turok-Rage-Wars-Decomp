#include "b08_types.h"

typedef struct LNode {
    struct LNode *next;
} LNode;

typedef struct LObj LObj;
struct LObj {
    s32 pad0;
    LObj *next4;
    u8 pad8[0xE38];
    s32 listE40;
    LNode *headE44;
    u8 padE48[0xDC];
    s32 listF24;
};

void func_00255E78(void *list, LNode *n);
void func_00255C58(void *list, LNode *n);
extern LObj *D_801450A8;

inline void func_00239AE4(LObj *a, LObj *b) {
    LNode *n;
    LNode *next;

    if (b != NULL) {
        n = b->headE44;
        while (n != NULL) {
            next = n->next;
            func_00255E78(&b->listE40, n);
            func_00255C58(&a->listF24, n);
            n = next;
        }
    }
}

void func_00239B54(LObj *a) {
    LObj *b;

    func_00239AE4(a, (LObj *)((u8 *)a + 0x40));
    for (b = D_801450A8; b != NULL; b = b->next4) {
        func_00239AE4(a, b);
    }
}
