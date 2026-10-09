/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b23_types.h"

typedef struct Part6ED0 Part6ED0;
struct Part6ED0 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ Part6ED0 *next;
    /* 0x08 */ f32 time;
    /* 0x0C */ f32 period;
    /* 0x10 */ s32 count;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ void (*cb)(Part6ED0 *);
};

typedef struct Owner6ED0 {
    u8 pad0[0x7588];
    u8 list[0xC];
    Part6ED0 *head;
} Owner6ED0;

extern f32 D_800D2988;

void func_00279764(void *list, Part6ED0 *p);

void func_002A6ED0(Owner6ED0 *o, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    Part6ED0 *p, *next;

    p = o->head;
    if (p != 0) {
        do {
            p->time = p->time - D_800D2988;
            next = p->next;
            if (p->time <= 0.0f) {
                p->time = p->time + p->period;
                if (p->time < 0.0f) {
                    p->time = 0.0f;
                }
                ((void (*)(Part6ED0 *, u32, u32, u32))p->cb)(p, pt_a1, pt_a2, pt_a3);
                p->count = p->count - 1;
                if (p->count <= 0) {
                    func_00279764(o->list, p);
                }
            }
            p = next;
        } while (p != 0);
    }
}
