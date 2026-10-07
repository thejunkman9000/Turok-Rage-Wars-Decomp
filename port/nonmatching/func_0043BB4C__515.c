#include "o06_types.h"
typedef struct { u8 pad[0x4C]; u8 unk4C[0x2C]; u8 unk78; u8 pad2[7]; s8 unk80; u8 pad3[0x96 - 0x81]; } O06R;
extern O06R D_80146398[];
extern u8 D_8011FE88[];
extern s32 *func_0028CF7C();
extern void func_0043B8C8(s32 a);
void func_0043BB4C(void) {
    s32 i, j, k; s32 *v; O06R *row;
    for (i = 0; i < 4; i++) {
        row = &D_80146398[i];
        for (j = 0x15; j >= 0; j--) {
            if (row->unk78) { row->unk4C[j] = 0; } else { row->unk4C[j] = 0; }
        }
        if (row->unk78 == 1) {
            v = func_0028CF7C(D_8011FE88, 0xB, k = row->unk80);
            for (k = 0; k < 8; k++) { s32 t = v[0x13 + k]; if (t >= 0x4C3) row->unk4C[t - 0x4C3] = 1; }
            func_0043B8C8(i);
        }
    }
}
