#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Links a new node into a tree just before a given node, making it the parent's first child when the given node was, and otherwise attaching it after the predecessor that func_8040ECA8_de's search finds from the parent by the given node's id. Adapted from func_8040ECA8_de with the search body kept as a static inline helper and called after the new node's parent, next and child links are set. */



extern struct Tree_func_8040EDE4_de *func_8040ECA8_de(struct Tree_func_8040EDE4_de *node, s32 id);

static inline struct Tree_func_8040EDE4_de *findPredecessor(struct Tree_func_8040EDE4_de *node, s32 id) {
    s32 childId;
    struct Tree_func_8040EDE4_de *found = 0;

    childId = id;
    while (node != 0 && found == 0) {
        if (node->next != 0 && node->next->id == (u16)id) {
            found = node;
        }
        if (found == 0 && node->child != 0) {
            found = func_8040ECA8_de(node->child, (u16)childId);
        }
        node = node->next;
    }
    return found;
}

void func_8040EDE4_de(struct Tree_func_8040EDE4_de *node, struct Tree_func_8040EDE4_de *added) {
    struct Tree_func_8040EDE4_de *parent;

    added->next = node;
    added->parent = node->parent;
    added->child = 0;
    parent = node->parent;
    if (parent->child == node) {
        parent->child = added;
    } else {
        findPredecessor(parent, (u16)node->id)->next = added;
    }
}
