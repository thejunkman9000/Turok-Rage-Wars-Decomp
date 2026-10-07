#include "o02_types.h"
typedef struct O02N { struct O02N *parent; struct O02N *next; struct O02N *child; s16 id; u16 pad0E; u8 pad10[2]; u16 flags; u16 h14; u16 h16; u8 pad18[0x2C-0x18]; struct O02N *f2C; struct O02N *f30; struct O02N *f34; struct O02N *f38; u8 pad3C[8]; struct O02N *f44; } O02N;

O02N *func_0040ECB0(O02N *n, u16 id) {
    O02N *r = 0;
    O02N *c;
    for (; n != 0 && r == 0; n = n->next) {
        if (n->id == id) r = n;
        if (r == 0) {
            c = n->child;
            if (c) r = func_0040ECB0(c, id);
        }
    }
    return r;
}

inline O02N *func_0040ED28(O02N *n, u16 id) {
    O02N *r = 0;
    O02N *c;
    for (; n != 0 && r == 0; n = n->next) {
        if (n->next && n->next->id == id) r = n;
        if (r == 0) {
            c = n->child;
            if (c) r = func_0040ED28(c, id);
        }
    }
    return r;
}

void func_0040EDB8(O02N *n, O02N *p, O02N *old, O02N *new) {
    if (n) {
        if (n->next) {
            func_0040EDB8(n->next, p, old, new);
        }
        if (n->child) {
            func_0040EDB8(n->child, n, old, new);
        }
        if (n->parent == old) n->parent = new;
        if (n->next == old) n->next = new;
        if (n->child == old) n->child = new;
        if (n == old) {
            new->parent = n->parent;
            new->next = n->next;
            new->child = n->child;
        }
    }
}

void func_0040EE64(O02N *n, O02N *new) {
    O02N *p;
    O02N *r;
    new->next = n;
    new->parent = n->parent;
    new->child = 0;
    p = n->parent;
    if (p->child == n) {
        p->child = new;
    } else {
        r = func_0040ED28(p, n->id);
        r->next = new;
    }
}

void func_0040EF24(O02N *n, O02N *new) {
    O02N *p;
    O02N *r;
    new->child = n;
    new->parent = n->parent;
    new->next = n->next;
    p = n->parent;
    if (p->child == n) {
        p->child = new;
    } else {
        r = func_0040ED28(p, n->id);
        r->next = new;
    }
    n->next = 0;
    n->parent = new;
    n->h14 = 0;
    n->h16 = 0;
}

void func_0040F004(O02N *n, O02N *old, O02N *new) {
    if (n) {
        if (n->next) {
            func_0040F004(n->next, old, new);
        }
        if (n->child) {
            func_0040F004(n->child, old, new);
        }
        if (n->flags & 0x10) {
            if (n->f30 == old) n->f30 = new;
            if (n->f34 == old) n->f34 = new;
            if (n->f38 == old) n->f38 = new;
            if (n->f2C == old) n->f2C = new;
        }
        if (n->pad0E == 2) {
            if (n->f44 == old) n->f44 = new;
        }
    }
}
