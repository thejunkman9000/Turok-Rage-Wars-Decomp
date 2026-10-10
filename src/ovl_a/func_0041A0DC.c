#include "o03_types.h"
s32 func_0041A0DC(O3B60 *o) {
    f32 t;
    O3B60G *g;
    O3B60 *p = o;
    if (o->flag == 1) {
        if (o->state != 2) {
            if (o->state < 3 && o->state == o->flag) {
                g = o->g;
                if (g->fx != 1.0f) {
                    if (g->fx < 1.0f) {
                        t = g->fx + o->sp1;
                        if (t < 0.0f) {
                            t = 0.0f;
                        } else if (1.0f < t) {
                            t = 1.0f;
                        }
                        g->fx = t;
                    } else {
                        g->fx = g->fx - 0.01f;
                    }
                } else {
                    if (g->fy != 1.0f) {
                        if (g->fy < 1.0f) {
                            g->fy = g->fy + o->sp2;
                            if (1.0f < o->g->fy) {
                                o->g->fy = 1.2f;
                            }
                        } else {
                            g->fy = 1.0f;
                            o->state = 3;
                        }
                    }
                }
            }
        } else {
            g = o->g;
            if (0.05f < g->fy - 0.05f) {
                if (0.05f < g->fy) {
                    t = g->fy - o->sp2;
                    if (t < 0.05f) {
                        t = 0.05f;
                    } else if (1.0f < t) {
                        t = 1.0f;
                    }
                    g->fy = t;
                } else {
                    g->fy = g->fy + 0.01f;
                }
            } else {
                if (g->fx == 0.0f) {
                    goto set4;
                } else if (g->fx > 0.0f) {
                    t = g->fx - o->sp1;
                    if (t < 0.0f) {
                        t = 0.0f;
                    } else if (1.0f < t) {
                        t = 1.0f;
                    }
                    g->fx = t;
                } else {
                    g->fx = g->fx + 0.01f;
                }
            }
        }
        goto done;
    set4:
        p->state = 4;
    }
done:
    return 0;
}
