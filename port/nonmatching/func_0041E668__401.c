#include "o03_types.h"
extern O3Cfg D_801462C8[];
extern u8 D_80153F80[];
void func_002A125C(void *d, void *s);
void func_0041E668(void) {
    s32 idx, j, off;
    O3Pl4 *e;
    idx = 7;
    j = 0;
    off = 0;
    do {
        if (idx <= 0) break;
        if (*(s32 *)(D_80153F80 + off) >= 0) {
            while (D_801462C8->pl[idx].f78 == 1) {
                idx--;
                if (idx <= 0) break;
            }
            if (idx >= 0) {
                e = &D_801462C8->pl[idx];
                e->f91 = 1;
                e->f78 = 1;
                e->f7F = idx;
                idx--;
                e->f80 = D_80153F80[off + 3];
                e->f93 = D_80153F80[off + 7];
                e->f92 = D_80153F80[off + 0xB];
                e->f81 = D_80153F80[off + 0xF];
                func_002A125C(e->name, D_80153F80 + off + 0x10);
            }
        }
        j++;
        off += 0x1C;
    } while (j < 3);
}
