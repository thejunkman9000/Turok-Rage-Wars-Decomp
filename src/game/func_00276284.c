#include "b17_types.h"

void func_00276284(TNode *n, u16 id) {
    u16 myid = n->id;

    if (myid == id && !(n->fl & 4)) {
        n->fl |= 4;
        if (n->c0) {
            func_00276284(n->c0, myid);
        }
        if (n->c1) {
            func_00276284(n->c1, myid);
        }
        if (n->c2) {
            func_00276284(n->c2, myid);
        }
    }
}
