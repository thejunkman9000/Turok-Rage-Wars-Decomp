#include "b20_types.h"

typedef struct {
    u8 pad0[0x2F0];
    u8 unk2F0[0x60];
    f32 box[6];
} Probe;

void func_0026D980();
void func_0026D9D0(void);
s32 func_00297B74(u8 *a, f32 *b);
void func_0024EB80(Entity *e);
extern s32 D_800D15E0;
extern f32 D_800D15F0;

void func_002905D4(NodeOwner *o, Probe *p) {
    Entity *e;
    f32 f;
    func_0026D980();
    e = (Entity *)o->head;
    while (e != 0) {
        if (p->box[3] > e->box[0]
            && p->box[0] < e->box[3]
            && p->box[5] > e->box[2]
            && p->box[2] < e->box[5]
            && p->box[4] > e->box[1]
            && p->box[1] < e->box[4]) {
            if (func_00297B74(p->unk2F0, &e->box[0]) != 0) {
                f = *(f32 *)((u8 *)e + 0x1C8);
                D_800D15E0 = 0;
                if (0.0f < f) {
                    if (f <= 7.5f) {
                        D_800D15F0 = f * 34.0f;
                        D_800D15E0 = 1;
                    }
                }
                func_0024EB80(e);
                D_800D15E0 = 0;
            }
        }
        e = (Entity *)((Node *)e)->next;
    }
    func_0026D9D0();
}
