#include "p3_types.h"

typedef struct P3Node {
    struct P3Node *next;   /* 0x00 */
    struct P3Node *prev;   /* 0x04 */
} P3Node;

typedef struct {
    P3Node *head;          /* 0x00 */
    P3Node *tail;          /* 0x04 */
    s32 count;             /* 0x08 */
} P3List2;

void func_00279530(P3List2 *l, P3Node *n) {
    if (l->count == 0) {
        l->head = n;
        l->tail = n;
        n->next = NULL;
        n->prev = NULL;
    } else {
        n->prev = l->head;
        n->next = NULL;
        l->head->next = n;
        l->head = n;
    }
    l->count++;
}
