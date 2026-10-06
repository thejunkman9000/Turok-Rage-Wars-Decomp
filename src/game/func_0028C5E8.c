#include "p4_types.h"
extern f32 D_800D2988;
typedef struct { u8 pad0[0xE]; u8 flags; } P4Obj5;
typedef struct P4LNode { s32 pad0; struct P4LNode *next; P4Obj5 *obj; f32 timer; } P4LNode;
typedef struct { u8 pad0[0x11D8]; P4LNode *head; } P4Mgr5;
void func_00278C80(P4Obj5 *o);
void func_00255E78(void *list, P4LNode *n);
void func_00255C58(void *list, P4LNode *n);


void func_0028C5E8(P4Mgr5 *m) {
    P4LNode *n = m->head;
s32 expired = 0;
while (n != NULL) {
    P4Obj5 *o = n->obj;
    P4LNode *next = n->next;
    s32 done = expired;
    if (o->flags & 2) {
        n->timer -= D_800D2988;
        if (n->timer <= 0.0f) {
            done = 1;
            expired = done;
        }
    }
    if (done) func_00278C80(o);
    if (expired) {
        func_00255E78((u8 *)m + 0x11D8, n);
        func_00255C58((u8 *)m + 0x11EC, n);
    }
    n = next;
    expired = 0;
}
}
