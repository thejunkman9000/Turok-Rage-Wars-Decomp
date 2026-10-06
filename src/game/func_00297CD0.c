#include "common.h"

typedef struct B21Node B21Node;
struct B21Node {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s16 id;
    /* 0x0E */ u8 padE[4];
    /* 0x12 */ u16 flags;
    /* 0x14 */ u8 pad14[0x18];
    /* 0x2C */ B21Node *link[4];
};

typedef struct B21Ent {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ B21Node *node;
    /* 0x0C */ u8 padC[0x10];
} B21Ent;

typedef struct B21Menu {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 cur;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ B21Ent *ents;
} B21Menu;

extern B21Menu *D_8014D080;
void func_0029A1D4(s32 id, B21Node **l, s32 dir);

void func_00297CD0(s32 dir) {
    B21Node *n;
    B21Node **l;
    B21Node *c;
    s32 id;
    n = D_8014D080->ents[D_8014D080->cur].node;
    id = -1;
    l = n->link;
    if (n != NULL && (n->flags & 0x10)) {
        switch (dir) {
        case 5:
            while (l[0] != NULL) {
                c = l[0];
                if (!(c->flags & 0x100)) {
                    id = c->id;
                    break;
                }
                l = c->link;
            }
            break;
        case 6:
            while (l[1] != NULL) {
                c = l[1];
                l = c->link;
                if (!(c->flags & 0x100)) {
                    id = c->id;
                    break;
                }
            }
            break;
        case 7:
            while (l[2] != NULL) {
                c = l[2];
                l = c->link;
                if (!(c->flags & 0x100)) {
                    id = c->id;
                    break;
                }
            }
            break;
        case 8:
            while (l[3] != NULL) {
                c = l[3];
                l = c->link;
                if (!(c->flags & 0x100)) {
                    id = c->id;
                    break;
                }
            }
            break;
        }
        if (id >= 0) {
            func_0029A1D4(id, l, dir);
        }
    }
}
