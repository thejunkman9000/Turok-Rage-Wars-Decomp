#include "o02_types.h"
typedef struct { s32 id; s16 cnt; s16 pad; } S_e;
typedef struct { u8 pad[4]; s32 flags; u8 pad2[0x1C-8]; } S_o;
extern S_e *D_80153C18;
extern S_o *D_80153C10;
void func_004196A4(s32 a);
void func_00411B70(s32 i) {
    S_e *e = (S_e *)(i * 8 + (s32)D_80153C18);
    if (e->id != -1) {
        if (e->cnt > 0) {
            e->cnt = e->cnt - 1;
        } else {
            if (D_80153C10[i].flags & 1) {
                func_004196A4(*(s32 *)&D_80153C10[i]);
                D_80153C10[i].flags &= ~1;
            }
            D_80153C18[i].id = 0;
        }
    }
}
