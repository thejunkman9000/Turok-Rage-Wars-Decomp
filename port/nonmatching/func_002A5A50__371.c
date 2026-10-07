#include "r08_types.h"

typedef struct R5Anim {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ s32 state;
    /* 0x08 */ f32 t;
    /* 0x0C */ f32 *restart;
    /* 0x10 */ f32 *pc;
    /* 0x14 */ f32 cur;
    /* 0x18 */ f32 from;
    /* 0x1C */ f32 to;
    /* 0x20 */ f32 dur;
    /* 0x24 */ f32 d24;
    /* 0x28 */ f32 d28;
    /* 0x2C */ f32 d2C;
    /* 0x30 */ f32 dur2;
    /* 0x34 */ f32 d34;
    /* 0x38 */ f32 d38;
    /* 0x3C */ f32 d3C;
    /* 0x40 */ f32 pad40;
    /* 0x44 */ f32 f44;
    /* 0x48 */ f32 f48;
    /* 0x4C */ f32 f4C;
    /* 0x50 */ f32 pad50;
    /* 0x54 */ f32 f54;
    /* 0x58 */ f32 f58;
    /* 0x5C */ f32 f5C;
} R5Anim;

extern f32 D_800D2988;
f32 func_00274B00(f32, f32);

void func_002A5A50(R5Anim *a) {
    s32 run = 0;
    f32 r, s, u0, u1, u2, u3;

    switch (a->state) {
    case 0:
        if (a->restart != 0) {
            run = 1;
        }
        break;
    case 1:
        a->t = a->t - D_800D2988;
        if (a->t < 0.0f) {
            run = 1;
        }
        break;
    case 4:
        a->t = a->t + D_800D2988;
        if (a->t >= a->dur) {
            a->t = a->dur;
            run = 1;
        }
        r = a->t / a->dur;
        u0 = r * a->to;
        a->cur = (1.0f - r) * a->from + u0;
        break;
    case 6:
        a->t = a->t + D_800D2988;
        if (a->t >= a->dur2) {
            a->t = a->dur2;
            run = 1;
        }
        r = a->t / a->dur2;
        u0 = r * a->f54;
        u1 = r * a->f58;
        u2 = r * a->f5C;
        u3 = r * a->d2C;
        s = 1.0f - r;
        a->d34 = s * a->f44 + u0;
        a->d38 = s * a->f48 + u1;
        a->d3C = s * a->f4C + u2;
        a->d24 = s * a->d28 + u3;
        break;
    }
    if (run != 0) {
again:
        {
            a->state = (s32)*a->pc;
            a->pc = a->pc + 1;
            run = 0;
            switch (a->state) {
            case 0:
                a->pc = 0;
                a->restart = 0;
                break;
            case 1:
                a->t = *a->pc++;
                break;
            case 2: {
                f32 p0 = *a->pc++;
                f32 p1 = *a->pc++;
                a->state = 1;
                a->t = func_00274B00(p0, p1);
                break;
            }
            case 3:
                run = 1;
                a->cur = *a->pc++;
                break;
            case 4: {
                f32 p0, p1;
                f32 c = a->cur;
                p0 = *a->pc++;
                p1 = *a->pc++;
                a->from = c;
                a->t = 0;
                a->to = p0;
                a->dur = p1;
                break;
            }
            case 5: {
                f32 p0 = *a->pc++;
                f32 p1 = *a->pc++;
                f32 p2 = *a->pc++;
                f32 p3 = *a->pc++;
                run = 1;
                a->d34 = p0;
                a->d38 = p1;
                a->d3C = p2;
                a->d24 = p3;
                break;
            }
            case 6: {
                f32 c0 = a->d34, c1 = a->d38, c2 = a->d3C, c3 = a->d24;
                f32 p0 = *a->pc++;
                f32 p1 = *a->pc++;
                f32 p2 = *a->pc++;
                f32 p3 = *a->pc++;
                f32 p4 = *a->pc++;
                a->f44 = c0;
                a->f48 = c1;
                a->f4C = c2;
                a->d28 = c3;
                a->t = 0;
                a->f54 = p0;
                a->f58 = p1;
                a->f5C = p2;
                a->d2C = p3;
                a->dur2 = p4;
                break;
            }
            case 7:
                run = 1;
                a->pc = a->pc + 1;
                break;
            case 8:
                run = 1;
                a->pc = a->restart;
                break;
            }
        }
        if (run != 0) goto again;
    }
}
