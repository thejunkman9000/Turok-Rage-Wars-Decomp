#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Puts a new node in a tree node's place, taking over its parent and next links and becoming the parent's first child or the successor of the predecessor func_8040ECA8_de's search finds, then makes the old node the new node's only child with its next link and the halfwords at 0x14 and 0x16 cleared.
   Adapted from func_8040EDE4_de with the new node taking the old node's next link and child position and the old node's links reset afterwards changed. */



extern struct Tree_func_8040EEA4_de *func_8040ECA8_de(struct Tree_func_8040EEA4_de *node, s32 id);

static inline struct Tree_func_8040EEA4_de *findPredecessor(struct Tree_func_8040EEA4_de *node, s32 id) {
    s32 childId;
    struct Tree_func_8040EEA4_de *found = 0;

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

void func_8040EEA4_de(struct Tree_func_8040EEA4_de *node, struct Tree_func_8040EEA4_de *added) {
    struct Tree_func_8040EEA4_de *parent;

    added->child = node;
    added->parent = node->parent;
    added->next = node->next;
    parent = node->parent;
    if (parent->child == node) {
        parent->child = added;
    } else {
        findPredecessor(parent, (u16)node->id)->next = added;
    }
    node->next = 0;
    node->parent = added;
    node->field_14 = 0;
    node->field_16 = 0;
}
