/* semantics right; not exact: ROM reloads g->unk26DC1 after the speed select (cse across the join not done), tests ==1 first with the state-1 block placed last, copies speed to a 2nd pseudo for the state-2 block */
#include "b21_types.h"

extern f32 D_800CA56C;
extern f32 D_800CA570;
extern f32 D_800D2988;
extern f32 D_800CA574;
extern f32 D_800CA578;
extern f32 D_800CA57C;
extern f32 D_800CA580;

void func_002935A4(B21Game *g) {
    f32 speed;
    f32 t;
    f32 a;
    f32 b;
    s32 old;
    if (g->unk26DC1 != 0) {
        speed = D_800CA56C;
        if (g->unk26DC0 != 0) {
            speed = D_800CA570;
        }
        if (g->unk26DC1 != 1) {
          if (g->unk26DC1 == 2) {
            t = g->unk26DC4;
            if (0.0f < t) {
                t = t - speed * D_800D2988;
                g->unk26DC4 = t;
                if (t < 0.0f) {
                    g->unk26DC4 = 0.0f;
                }
            } else {
                g->unk26DC4 = t - D_800CA574;
            }
            if (g->unk26DC4 < D_800CA578) {
                old = g->unk26DB8;
                g->unk26DB8 = 20;
                g->unk26DC4 = 0.0f;
                g->unk26DC1 = 1;
                g->unk26DB4 = old;
            }
          }
        } else {
            a = D_800D2988;
            b = D_800CA57C;
            if (a < b) {
                t = g->unk26DC4 + speed * b;
            } else {
                t = g->unk26DC4 + speed * a;
            }
            g->unk26DC4 = t;
            if (t >= D_800CA580) {
                g->unk26DC1 = 0;
                g->unk26DC4 = D_800CA580;
                g->unk26DC0 = 0;
            }
        }
    }
}
