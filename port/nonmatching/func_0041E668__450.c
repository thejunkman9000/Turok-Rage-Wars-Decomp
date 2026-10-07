#include "o03_types.h"
typedef struct Q2Pl { u8 pad0[0x78]; u8 f78; u8 pad79[6]; u8 f7F; u8 f80; u8 f81; u8 pad82[2]; u8 name[0xD]; u8 f91; u8 f92; u8 f93; u8 pad94[2]; } Q2Pl;
typedef struct Q2Cfg { u8 pad0[0xD0]; Q2Pl pl[8]; } Q2Cfg;
typedef struct Q2Rc { s32 w0; u8 b4[0xC]; u8 name[0xC]; } Q2Rc;
extern Q2Cfg D_801462C8[];
extern u8 D_80153F80[];
void func_002A125C(void *d, void *s);
void func_0041E668(void) {
    s32 idx, j, off;
    Q2Cfg *c;
    Q2Pl *e;
    idx = 7;
    c = D_801462C8;
    e = &c->pl[7];
    j = 0;
    off = 0;
    for (j = 0; j < 3; j++, off += 0x1C) {
        if (idx <= 0) break;
        if (*(s32 *)(D_80153F80 + off) >= 0) {
            while (c->pl[idx].f78 == 1) {
                idx--;
                e--;
                if (idx <= 0) break;
            }
            if (idx >= 0) {
                e->f91 = 1;
                e->f78 = 1;
                e->f7F = idx;
                idx--;
                e->f80 = D_80153F80[off + 3];
                e->f93 = D_80153F80[off + 7];
                e->f92 = D_80153F80[off + 0xB];
                e->f81 = D_80153F80[off + 0xF];
                func_002A125C(e->name, D_80153F80 + off + 0x10);
                e--;
            }
        }
    }
}
