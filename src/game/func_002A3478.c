#include "b23_types.h"

typedef struct Widget Widget;
struct Widget {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ Widget *child;
    /* 0x08 */ Widget *sibling;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 type;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ s16 w;
    /* 0x1A */ s16 h;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ f32 sx;
    /* 0x24 */ f32 sy;
    /* 0x28 */ s32 scaled;
    /* 0x2C */ Widget *sub2C;
    /* 0x30 */ Widget *sub30;
    /* 0x34 */ Widget *sub34;
};


extern f32 D_800CAF48;
extern f32 D_800CAF4C;
void func_002A3478(w, parent)
Widget *w;
Widget *parent;
{
    s32 new_var;
    if (w != 0) {
        if (w->child != 0) func_002A3478(w->child);
        if (w->sibling != 0) func_002A3478(w->sibling, w);
        if (w->type == 8) {
            if (w->sub2C != 0) func_002A3478(w->sub2C, w);
            if (w->sub34 != 0) func_002A3478(w->sub34, w);
            if (w->sub30 != 0) func_002A3478(w->sub30, w);
        }
        new_var = 4;
        if (w->scaled == 0) {
            f32 sx = D_800CAF48;
            f32 sy = D_800CAF4C;
            if (w->type == new_var) {
                w->sx = sx;
                w->sy = sy;
            } else {
                f32 t; t = w->x * sx; w->x = t; t = w->y * sy; w->y = t; t = w->w * sx; w->w = t; t = w->h * sy; w->h = t;
            }
            w->scaled = 1;
        }
    }
}
