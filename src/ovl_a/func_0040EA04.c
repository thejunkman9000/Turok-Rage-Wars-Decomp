#include "o02_types.h"
typedef struct { s32 x, y; s32 w[8]; } S_st;
typedef struct S_n { u8 pad0[4]; struct S_n *a; struct S_n *b; s16 id; u16 type; u8 pad10[4]; s16 x; s16 y; s16 w; s16 h; } S_n;
typedef struct { S_n *hit; } S_hit;
s32 func_0029A7E4(s32 t);
void func_0040EA04(S_hit *hit, S_n *n, S_st s, s32 px, s32 py) {
    if (hit->hit == 0) {
        if (n->a) {
            func_0040EA04(hit, n->a, s, px, py);
        }
        if (hit->hit == 0) {
            s.x += n->x;
            s.y += n->y;
            if (n->b) {
                func_0040EA04(hit, n->b, s, px, py);
            }
            if (hit->hit == 0) {
                if (n->id != -1) {
                    if (!(px < s.x)) {
                        if (!(s.x + n->w < px)) {
                            if (!(py < s.y)) {
                                if (!(s.y + n->h < py)) {
                                    if (func_0029A7E4(n->type) != 0) {
                                        hit->hit = n;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
