#include "common.h"

typedef struct Qn Qn;
struct Qn { Qn *next; s32 unk4; u32 flags8; u8 padC[4]; s32 kind; };
typedef struct {
    u8 pad0[0x2E4];
    Qn *head2E4;
    Qn *head2E8;
    Qn *tail2EC;
    Qn *tail2F0;
    u8 pad2F4[0xC];
    s32 unk300;
} QOwner;

void func_0028F934(QOwner *o, Qn *n) {
    if (n->kind == 2) {
        if (o->tail2EC != 0) {
            o->tail2EC->next = n;
        } else {
            o->head2E4 = n;
        }
        o->tail2EC = n;
        o->unk300 = 1;
    } else {
        if (o->tail2F0 != 0) {
            o->tail2F0->next = n;
        } else {
            o->head2E8 = n;
        }
        o->tail2F0 = n;
    }
    n->next = 0;
    n->unk4 = n->flags8 & 3;
}
