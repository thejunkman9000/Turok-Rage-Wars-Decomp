#include "b20_types.h"

void func_0024F460(Entity *e);
s32 func_0024D150(Entity *e);
extern f32 D_801031F0[];

void func_0029074C(NodeOwner *o, Level *lv) {
    Entity *e = (Entity *)o->head;
    s32 c;
    while (e != 0) {
        func_0024F460(e);
        if ((e->flags19C & 0x30000) == 0x20000
            && func_0024D150(e) != 0
            && !(*(u16 *)&e->flags19C & 0x100)
            && D_801031F0[3] > e->box[0]
            && D_801031F0[0] < e->box[3]
            && D_801031F0[5] > e->box[2]
            && D_801031F0[2] < e->box[5]
            && D_801031F0[4] > e->box[1]
            && D_801031F0[1] < e->box[4]) {
            c = lv->cnt944;
            if (c != 0x200) {
                lv->arr144[c] = e;
                lv->cnt944 = c + 1;
            }
        }
        e = (Entity *)((Node *)e)->next;
    }
}
