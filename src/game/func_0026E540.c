#include "b16_types.h"

typedef struct B16Node B16Node;
struct B16Node {
    /* 0x00 */ u32 key;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ B16Node *prev;
    /* 0x14 */ B16Node *next;
    /* 0x18 */ B16Node *left;
    /* 0x1C */ B16Node *right;
};

void func_0026E540(B16Node **first, B16Node **root, B16Node *n, B16Node *parent) {
    B16Node *t;

    if (parent != NULL) {
        if (n->key < parent->key) {
            parent->left = n;
            n->right = NULL;
            n->left = NULL;
            n->next = parent;
            n->prev = parent->prev;
            t = parent->prev;
            if (t != NULL) {
                t->next = n;
            }
            parent->prev = n;
            if (*first == parent) {
                *first = n;
            }
        } else {
            parent->right = n;
            n->right = NULL;
            n->left = NULL;
            n->next = parent->next;
            t = parent->next;
            if (t != NULL) {
                t->prev = n;
            }
            n->prev = parent;
            parent->next = n;
        }
    } else {
        *root = n;
        *first = n;
        n->right = NULL;
        n->left = NULL;
        n->next = NULL;
        n->prev = NULL;
    }
}
