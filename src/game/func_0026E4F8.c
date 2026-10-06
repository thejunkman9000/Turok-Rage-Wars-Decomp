#include "b16_types.h"

typedef struct B16Node B16Node;
struct B16Node {
    /* 0x00 */ u32 key;
    /* 0x04 */ u8 pad4[0x14];
    /* 0x18 */ B16Node *left;
    /* 0x1C */ B16Node *right;
};

B16Node *func_0026E4F8(B16Node **root, u32 key) {
    B16Node *n;
    B16Node *parent;

    n = *root;
    parent = NULL;
    while (n != NULL) {
        if (n->key == key) {
            return n;
        }
        parent = n;
        if (key < n->key) {
            n = parent->left;
        } else {
            n = parent->right;
        }
    }
    return parent;
}
