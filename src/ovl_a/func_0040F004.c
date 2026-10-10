#include "span_16E000/code_8040C780.h"
#include "types.h"
/* Walks a node tree recursively, replacing every reference to one pointer with another in each node's link fields. */



void func_8040EF84_de(Node_func_8040EF84_de *node, void *from, void *to) {
    if (node != 0) {
        if (node->left != 0) {
            func_8040EF84_de(node->left, from, to);
        }
        if (node->right != 0) {
            func_8040EF84_de(node->right, from, to);
        }
        if (node->flags & 0x10) {
            if (node->ref30 == from) {
                node->ref30 = to;
            }
            if (node->ref34 == from) {
                node->ref34 = to;
            }
            if (node->ref38 == from) {
                node->ref38 = to;
            }
            if (node->ref2C == from) {
                node->ref2C = to;
            }
        }
        if (node->kind == 2) {
            if (node->ref44 == from) {
                node->ref44 = to;
            }
        }
    }
}
