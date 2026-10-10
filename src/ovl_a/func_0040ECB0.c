#include "span_16E000/code_8040C780.h"


struct Tree *func_8040EC30_de(struct Tree *node, unsigned short id) {
    struct Tree *found = 0;

    while (node != 0 && found == 0) {
        if (node->id == id) {
            found = node;
        }
        if (found == 0 && node->child != 0) {
            found = func_8040EC30_de(node->child, id);
        }
        node = node->next;
    }
    return found;
}
