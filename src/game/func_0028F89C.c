#include "p4_types.h"
typedef struct P4SNode { struct P4SNode *next; } P4SNode;
typedef struct { u8 pad0[0x2E0]; P4SNode *head; } P4SList;
u32 osSetIntMask(u32 mask);
void func_0028F89C(P4SList *l, P4SNode *n) {
    P4SNode *prev = NULL;
    P4SNode *cur = l->head;
    u32 mask = osSetIntMask(1);
    while (cur != NULL) {
        if (cur == n) {
            if (prev != NULL) {
                prev->next = cur->next;
            } else {
                l->head = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    osSetIntMask(mask);
}
