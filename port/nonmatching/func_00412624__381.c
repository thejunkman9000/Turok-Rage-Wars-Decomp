#include "o02_types.h"
typedef struct { s32 key; s32 id; s32 (*fn)(); } S_k;
typedef struct { s32 (*fn)(); s32 a, b; } S_h;
extern S_k D_800E2AD0[];
typedef struct { u8 pad[0xC]; s16 id; } S_o;
s32 func_00412624(S_o *o, s32 key, s32 x, s32 y, s32 arg) {
    s32 i = 0;
    s32 (**f)();
    f = (s32 (**)())((u8 *)D_800E2AD0 + 8);
    if (D_800E2AD0[0].fn) {
    while (*f) {
        if (D_800E2AD0[i].key == key) {
            if (D_800E2AD0[i].id == o->id || D_800E2AD0[i].id == 30000) {
                return (*f)(o, key, x, y, arg);
            }
        }
        f = (s32 (**)())((u8 *)f + 12);
        i++;
    }
    }
    return 0;
}
