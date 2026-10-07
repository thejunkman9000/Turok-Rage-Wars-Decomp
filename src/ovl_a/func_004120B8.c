#include "o02_types.h"
typedef struct { s32 id; s16 cnt; s16 pad; } S_e;
typedef struct { u8 pad[4]; s32 flags; u8 pad2[0x1C-8]; } S_o;
extern S_e *D_80153C18;
extern S_o *D_80153C10;
extern s16 D_80153C0C;
void func_00411B70(s32 i);
void func_004120B8(void) {
    s32 i;
    for (i = 0; i < D_80153C0C; i++) {
        if (D_80153C10[i].flags & 1) {
            S_e *e = &D_80153C18[i];
            if (e->id != -1) {
                if (e->cnt == 0) {
                    func_00411B70(i);
                }
            }
        }
    }
}
