#include "b20_types.h"

void func_00290404(Entity *e);
extern f32 D_801031F0[];
extern f32 D_800D2988;

void func_00290218(NodeOwner *o) {
    Entity *e;
    Entity *p;
    Node *h;
    Node *n;
    s32 flag;
    p = (Entity *)o->head;
    while (p != 0) {
        e = p;
        p = (Entity *)((Node *)p)->next;
        flag = 0;
        if (0.0f < e->unk1C8) {
            e->unk1C8 = e->unk1C8 - D_800D2988;
            if (e->unk1C8 <= 0.0f) {
                flag = 1;
            }
        }
        if (D_801031F0[3] > e->box[0]
            && D_801031F0[0] < e->box[3]
            && D_801031F0[5] > e->box[2]
            && D_801031F0[2] < e->box[5]
            && D_801031F0[4] > e->box[1]
            && D_801031F0[1] < e->box[4]) {
        } else {
            if (!(*(u16 *)&e->flags19C & 0x200)) {
                flag = 1;
            }
        }
        if (flag != 0) {
            n = (Node *)e;
            if (n->flags & 1) {
                n->flags = n->flags & ~1;
                if (n->counter != 0) {
                    *n->counter = *n->counter - 1;
                }
                if (n->prev != 0) {
                    n->prev->next = n->next;
                }
                if (n->next != 0) {
                    n->next->prev = n->prev;
                }
                if (o->head == n) {
                    o->head = n->next;
                }
                if (o->tail == n) {
                    o->tail = n->prev;
                }
                h = o->freeList;
                n->prev = 0;
                n->next = h;
                o->freeList = n;
            }
        } else {
            func_00290404(e);
        }
    }
}
