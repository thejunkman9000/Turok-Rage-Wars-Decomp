#include "b14_types.h"
typedef struct B14Ent2 B14Ent2;
struct B14Ent2 {
    /* 0x000 */ u8 pad0[0xE8];
    /* 0x0E8 */ f32 minx;
    /* 0x0EC */ f32 miny;
    /* 0x0F0 */ f32 minz;
    /* 0x0F4 */ f32 maxx;
    /* 0x0F8 */ f32 maxy;
    /* 0x0FC */ f32 maxz;
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x70];
    /* 0x174 */ s32 f174;
    /* 0x178 */ u8 pad178[0x174];
    /* 0x2EC */ B14Ent2 *next;
    /* 0x2F0 */ s32 *counter;
};
typedef struct {
    /* 0x0000 */ u8 pad0[0x5F00];
    /* 0x5F00 */ u8 listA[0x14];
    /* 0x5F14 */ B14Ent2 *listB;
} B14World;
extern f32 D_801031F0[];
void func_00255CB4(void *list, B14Ent2 *e);
void func_00255E78(void *list, B14Ent2 *e);
void func_0028C910(void *a, B14Ent2 *e);
void func_00262EA8(B14World *w, void *arg) {
    B14Ent2 *e;
    B14Ent2 *next;
    s32 inside;
    e = w->listB;
    while (e != NULL) {
        next = e->next;
        inside = 0;
        if (D_801031F0[3] > e->minx && D_801031F0[0] < e->maxx && D_801031F0[5] > e->minz && D_801031F0[2] < e->maxz && D_801031F0[4] > e->miny && D_801031F0[1] < e->maxy) {
            inside = 1;
        }
        if (inside != 0) {
            func_0028C910(arg, e);
            if (e->counter != NULL && e->f174 == 0) {
                *e->counter -= 1;
                e->counter = NULL;
            }
        } else {
            e->f174 = 0;
            e->flags &= ~0x200;
            if (e->counter != NULL) {
                *e->counter -= 1;
            }
            func_00255E78(&w->listB, e);
            func_00255CB4(w->listA, e);
        }
        e = next;
    }
}
