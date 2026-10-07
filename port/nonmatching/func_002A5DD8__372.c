
#include "b23_types.h"

extern s32 D_800D15E0;
extern f32 D_800D15E4;
extern f32 D_800D15E8;
extern f32 D_800D15EC;
extern f32 D_800D15F0;
typedef struct Pair { f32 a; f32 b; } Pair;
extern Pair D_800D15F0_p __asm__("D_800D15F0");
extern f32 D_800D15F4;

void func_002A5DD8(void) {
    f32 v, w;
    f32 a, b;
    Pair *pp;
    v = D_800D15E4; w = v; if (v < 0.0f) { D_800D15E4 = 0.0f; } else if (w > 255.0f) { D_800D15E4 = 255.0f; }
    v = D_800D15E8; w = v; if (v < 0.0f) { D_800D15E8 = 0.0f; } else if (w > 255.0f) { D_800D15E8 = 255.0f; }
    v = D_800D15EC; w = v; if (v < 0.0f) { D_800D15EC = 0.0f; } else if (w > 255.0f) { D_800D15EC = 255.0f; }
    v = D_800D15F0; w = v; if (v < 0.0f) { D_800D15F0 = 0.0f; } else if (w > 255.0f) { D_800D15F0 = 255.0f; }
    v = D_800D15F4; w = v; if (v < 0.0f) { D_800D15F4 = 0.0f; } else if (w > 255.0f) { D_800D15F4 = 255.0f; }
    pp = &D_800D15F0_p;
    b = pp->b;
    a = pp->a;
    if (a == 0.0f) {
        if (b == 255.0f) {
            D_800D15E0 = 0;
            return;
        }
    }
    if (b != 255.0f) {
        if (a == 0.0f) {
            D_800D15E0 = 1;
            D_800D15F0_p.a = D_800D15F0_p.b;
            return;
        }
    }
    if (b == 255.0f) {
        if (a != 0.0f) {
            D_800D15E0 = 3;
            return;
        }
    }
    if (b != 255.0f) {
        if (a != 0.0f) {
            D_800D15E0 = 6;
        }
    }
}

