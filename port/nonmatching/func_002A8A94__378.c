#include "b24_types.h"

typedef struct Script24 {
    /* 0x00 */ s32 active;
    /* 0x04 */ s32 *pc;
    /* 0x08 */ s32 state;
    /* 0x0C */ s32 wait;
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 tx;
    /* 0x1C */ f32 ty;
    /* 0x20 */ f32 vx;
    /* 0x24 */ f32 vy;
    /* 0x28 */ f32 ax;
    /* 0x2C */ f32 ay;
    /* 0x30 */ f32 k;
} Script24;

extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_002A8A94(Script24 *s) {
    s32 again;
    s32 *p;
    s32 op;
    f32 dx, dy, nx, ny;
    s32 limy, limx;
    limy = D_800E28D4 + 0x60;
    limx = D_800E28D0 + 0x60;
    for (;;) {
        again = 0;
        switch (s->state) {
        case 0:
        case 1:
            break;
        case 2:
            p = s->pc;
            if (p != NULL) {
                op = *p;
                p++;
                s->pc = p;
                switch (op) {
                case 6:
                    s->state = 0;
                    s->pc = NULL;
                    break;
                case 1: {
                    s32 *q = s->pc;
                    again = 1;
                    s->x = *q;
                    q++;
                    s->pc = q;
                    s->y = *q;
                    q++;
                    s->pc = q;
                    break;
                }
                case 2: {
                    s32 *q = s->pc;
                    s->state = 3;
                    s->wait = *q;
                    q++;
                    s->pc = q;
                    break;
                }
                case 3: {
                    s32 *q = s->pc;
                    s->active = 1;
                    s->state = 4;
                    s->tx = *q;
                    q++;
                    s->pc = q;
                    s->ty = *q;
                    s->pc = q + 1;
                    s->k = 1.0f / q[1];
                    s->pc = q + 2;
                    break;
                }
                case 4: {
                    s32 *q = s->pc;
                    s->active = 1;
                    s->state = 5;
                    s->vy = 0;
                    s->ay = *q * 1.52587890625e-05f;
                    q++;
                    s->pc = q;
                    break;
                }
                case 5: {
                    s32 *q = s->pc;
                    s->active = 1;
                    s->state = 6;
                    s->vx = 0;
                    s->ax = *q * 1.52587890625e-05f;
                    q++;
                    s->pc = q;
                    break;
                }
                default:
                    s->state = 1;
                    s->pc = NULL;
                    break;
                }
            } else {
                s->state = 1;
            }
            break;
        case 3:
            if (s->wait-- <= 0) {
                again = 1;
            }
            break;
        case 4:
            dx = (s->tx - s->x) * s->k;
            dy = (s->ty - s->y) * s->k;
            s->x = s->x + dx;
            s->y = s->y + dy;
            if ((dx < 0.0f ? -dx : dx) < 0.25f && (dy < 0.0f ? -dy : dy) < 0.25f) {
                s->x = s->tx;
                s->y = s->ty;
                again = 1;
            }
            break;
        case 5:
            s->y += s->vy;
            s->vy += s->ay;
            if ((f32)limy < s->y) {
                s->active = 0;
                again = 1;
            } else if (s->y < -90.0f) {
                s->active = 0;
                again = 1;
            }
            break;
        case 6:
            s->x += s->vx;
            s->vx += s->ax;
            if ((f32)limx < s->x) {
                s->active = 0;
                again = 1;
            } else if (s->x < -90.0f) {
                s->active = 0;
                again = 1;
            }
            break;
        }
        if (again == 0) {
            return;
        }
        s->state = 2;
    }
}
