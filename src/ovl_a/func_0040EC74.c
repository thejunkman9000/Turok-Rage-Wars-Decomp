#include "o02_types.h"
typedef struct O02Node { struct O02Node *next; u8 pad[0x14-4]; s16 x; s16 y; } O02Node;
void func_0040EC74(O02Node *n, s32 *px, s32 *py) {
    s32 x = n->x;
    s32 y = n->y;
    while (n->next) {
        n = n->next;
        x += n->x;
        y += n->y;
    }
    *px = x;
    *py = y;
}
