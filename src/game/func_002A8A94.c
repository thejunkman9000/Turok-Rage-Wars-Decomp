#include "span_1000/code_802A8A94.h"
/* Steps a scripted screen mover: in state 2 it reads opcodes from its script (1 sets the position, 2 waits a number of frames, 3 moves toward a target at a rate of one over a frame count until within a quarter pixel, 4 and 5 fall vertically or horizontally with a fixed-point acceleration until leaving the screen, 6 or a missing script stops), running each finished step straight into the next opcode. */
#include "types.h"



extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_802A7AA4_de(Mover *m) {
    s32 next;
    f32 dx;
    f32 dy;
    s32 bottom;
    s32 right;

    bottom = D_800E28D4 + 0x60;
    right = D_800E28D0 + 0x60;
    do {
        next = 0;
        switch (m->state) {
        case 0:
        case 1:
            break;
        case 2:
            if (m->script != 0) {
                switch (*m->script++) {
                case 6:
                    m->state = 0;
                    m->script = 0;
                    break;
                case 1:
                    next = 1;
                    m->x = *m->script++;
                    m->y = *m->script++;
                    break;
                case 2:
                    m->state = 3;
                    m->wait = *m->script++;
                    break;
                case 3:
                    m->active = 1;
                    m->state = 4;
                    m->targetX = *m->script++;
                    m->targetY = *m->script++;
                    m->rate = 1.0f / *m->script++;
                    break;
                case 4:
                    m->active = 1;
                    m->state = 5;
                    m->velY = 0.0f;
                    m->accelY = *m->script++ * (1.0f / 65536.0f);
                    break;
                case 5:
                    m->active = 1;
                    m->state = 6;
                    m->velX = 0.0f;
                    m->accelX = *m->script++ * (1.0f / 65536.0f);
                    break;
                default:
                    m->state = 1;
                    m->script = 0;
                    break;
                }
            } else {
                m->state = 1;
            }
            break;
        case 3:
            if (m->wait-- <= 0) {
                next = 1;
            }
            break;
        case 4:
            dx = (m->targetX - m->x) * m->rate;
            dy = (m->targetY - m->y) * m->rate;
            m->x += dx;
            m->y += dy;
            if ((dx < 0.0f ? -dx < 0.25f : dx < 0.25f) && (dy < 0.0f ? -dy < 0.25f : dy < 0.25f)) {
                m->x = m->targetX;
                m->y = m->targetY;
                next = 1;
            }
            break;
        case 5:
            m->y += m->velY;
            m->velY += m->accelY;
            if ((f32)bottom < m->y || m->y < -90.0f) {
                m->active = 0;
                next = 1;
            }
            break;
        case 6:
            m->x += m->velX;
            m->velX += m->accelX;
            if ((f32)right < m->x || m->x < -90.0f) {
                m->active = 0;
                next = 1;
            }
            break;
        }
        if (next) {
            m->state = 2;
        }
    } while (next);
}
