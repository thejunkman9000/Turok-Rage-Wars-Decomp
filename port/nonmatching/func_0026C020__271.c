#include "r06_types.h"

extern R06Dl *D_80110634;
extern R06Node *D_8011062C;
extern R06Node *D_80110644;

s32 func_00269A80();
void func_0026AC38();
void func_0026B504();

#define PUSH(a, b) { R06Dl *g = D_80110634++; g->w0 = (a); g->w1 = (b); }

void func_0026C020(void) {
    R06Node *n, *nx, *defer;
    R06Sub *s;
    u16 p10, p12;
    u32 w;

    n = D_8011062C;
    defer = 0;
    if (n != 0) {
                do {
            s = n->head;
            if (s != 0 && func_00269A80(n->rec, (s8)n->key) != 0) {
                p12 = 0;
                p10 = 0;
                do {
                    func_0026B504(s->a, s->b, n->rec);
                    if (s->w14 != 0) { PUSH(0xDB060004, s->a); } else { PUSH(0xDA380003, s->a); }
                    PUSH(0xDB060008, s->c);
                    if (s->h10 != 0) {
                        if (p10 != s->h10 || p12 != s->h12) {
                            if (((R06Rec *)n->rec)->flags & 0x2000) { PUSH(0xD7002802, (s->h10 << 16) | s->h12); } else { PUSH(0xD7000002, (s->h10 << 16) | s->h12); }
                        }
                        p10 = s->h10;
                        p12 = s->h12;
                    }
                    PUSH(0xDE000000, (u32)s->data);
                    s = s->next;
                } while (s != 0);
                if (((R06Rec *)n->rec)->flags & 0x2000) {
                    PUSH(0xE3000F00, 0);
                }
                if (((R06Rec *)n->rec)->flags & 0x4000) {
                    nx = n->prv;
                    n->prv = defer;
                    defer = n;
                    n = nx;
                } else {
                    n = n->prv;
                }
            } else {
                n = n->prv;
            }
        } while (n != 0);
    }
    if (defer != 0) {
                n = defer;
        func_0026AC38();
        do {
            s = n->head;
            if (s != 0) {
                PUSH(0xFA000000, ((R06Rec *)n->rec)->b17);
                do {
                    func_0026B504(s->a, s->b, n->rec);
                    if (s->w14 != 0) { PUSH(0xDB060004, s->a); } else { PUSH(0xDA380003, s->a); }
                    PUSH(0xDB060008, s->c);
                    PUSH(0xDE000000, (u32)s->data);
                    s = s->next;
                } while (s != 0);
            }
            n = n->prv;
        } while (n != 0);
    }
    n = D_80110644;
    if (n != 0) {
                do {
            s = n->head;
            if (s != 0 && func_00269A80(n->rec, (s8)n->key) != 0) {
                p12 = 0;
                p10 = 0;
                do {
                    func_0026B504(s->a, s->b, n->rec);
                    if (s->w14 != 0) { PUSH(0xDB060004, s->a); } else { PUSH(0xDA380003, s->a); }
                    PUSH(0xDB060008, s->c);
                    if (s->h10 != 0) {
                        if (p10 != s->h10 || p12 != s->h12) {
                            if (((R06Rec *)n->rec)->flags & 0x2000) { PUSH(0xD7002802, (s->h10 << 16) | s->h12); } else { PUSH(0xD7000002, (s->h10 << 16) | s->h12); }
                        }
                        p10 = s->h10;
                        p12 = s->h12;
                    }
                    PUSH(0xDE000000, (u32)s->data);
                    s = s->next;
                } while (s != 0);
                if (((R06Rec *)n->rec)->flags & 0x2000) {
                    PUSH(0xE3000F00, 0);
                }
            }
            n = n->prv;
        } while (n != 0);
    }
}