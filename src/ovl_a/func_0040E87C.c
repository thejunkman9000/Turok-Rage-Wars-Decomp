#include "o02_types.h"
typedef struct { s32 w[10]; } O02Blob40;
typedef struct O02Node { struct O02Node *next0; struct O02Node *next; u8 pad[0x12-8]; u16 flags; } O02Node;
void func_0040DB84(O02Node *n, O02Blob40 b);
void func_0040E87C(O02Node *n, O02Blob40 b) {
    while (n) {
        if (n->flags & 8) {
            func_0040DB84(n, b);
        }
        n = n->next;
    }
}
