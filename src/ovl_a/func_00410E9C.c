#include "o02_types.h"
/* NOTE: D_80153C18 is declared volatile only to reproduce the ROM's pointer reloads (found with the permuter) */
typedef struct { s32 id; s16 cnt; s16 pad; } S_e;
typedef struct { s32 p; s32 flags; u8 pad2[0x1C-8]; } S_o;
extern S_e * volatile D_80153C18;
extern S_o *D_80153C10;
extern s16 D_80153C0C;
void func_004196A4(s32 a);
void func_00410E9C(s32 mode) {
    s32 i;
    for (i = 0; i < D_80153C0C; i++) {
        S_e *e;
        if (mode == 1) {
            D_80153C18[i].cnt = 0;
            do { D_80153C18[i].id = 0; } while (0);
        }
        e = (S_e *)(i * 8 + (s32)D_80153C18);
        if (e->id != -1) {
            if (e->cnt > 0) {
                e->cnt = e->cnt - 1;
            } else {
                if (D_80153C10[i].flags & 1) {
                    func_004196A4(D_80153C10[i].p);
                    D_80153C10[i].flags &= ~1;
                }
                D_80153C18[i].id = 0;
            }
        }
    }
}
