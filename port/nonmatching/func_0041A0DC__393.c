#include "o03_types.h"
s32 func_0041A0DC(O3B60 *o) {
    f32 t;
    if (o->flag == 1) {
        switch (o->state) {
        case 1:
            if (o->g->fx != 1.0f) {
                if (o->g->fx < 1.0f) {
                    t = o->g->fx + o->sp1;
                    if (t < 0.0f) {
                        t = 0.0f;
                    } else if (1.0f < t) {
                        t = 1.0f;
                    }
                    o->g->fx = t;
                } else {
                    o->g->fx = o->g->fx - 0.01f;
                }
            } else {
                if (o->g->fy != 1.0f) {
                    if (o->g->fy < 1.0f) {
                        o->g->fy = o->g->fy + o->sp2;
                        if (1.0f < o->g->fy) {
                            o->g->fy = 1.2f;
                        }
                    } else {
                        o->g->fy = 1.0f;
                        o->state = 3;
                    }
                }
            }
            break;
        case 2:
            if (0.05f < o->g->fy - 0.05f) {
                if (0.05f < o->g->fy) {
                    t = o->g->fy - o->sp2;
                    if (t < 0.05f) {
                        t = 0.05f;
                    } else if (1.0f < t) {
                        t = 1.0f;
                    }
                    o->g->fy = t;
                } else {
                    o->g->fy = o->g->fy + 0.01f;
                }
            } else {
                if (o->g->fx == 0.0f) {
                    o->state = 4;
                } else if (o->g->fx > 0.0f) {
                    t = o->g->fx - o->sp1;
                    if (t < 0.0f) {
                        t = 0.0f;
                    } else if (1.0f < t) {
                        t = 1.0f;
                    }
                    o->g->fx = t;
                } else {
                    o->g->fx = o->g->fx + 0.01f;
                }
            }
            break;
        }
    }
    return 0;
}
