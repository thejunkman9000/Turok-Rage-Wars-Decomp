#include "o04_types.h"
#include "q03_types.h"
typedef struct { f32 x; f32 y; f32 z; } O04V3;
typedef struct {
    u8 pad0[4]; f32 f4[4]; f32 f14[4]; O04V3 v24[4]; u8 pad54x[0x54 - 0x24 - 0x30]; s32 u54[4]; u8 pad64[0x70 - 0x64];
} O04Tbl70c;
extern O04ModeS4690 *D_800E4690;
extern Q03Ent D_80146398[];
extern O04Tbl70c D_800E3A58[];
void func_002A33BC(s32 a);
void func_002A338C(void);
s32 func_0041F1B0(s32 a);
void func_0041CB48(void *p, s32 a, s32 b, s32 c, s32 d, O04V3 v1, O04V3 v2, f32 f, s32 g);
s32 func_00426968(void) {
    s32 n;
    s32 slot;
    s32 i;
    s32 k;
    s32 off;
    O04V3 v;
    Q03Ent *e;
    func_002A33BC(1);
    func_002A338C();
    n = 0;
    slot = 0;
    off = 0x20;
    D_800E4690->unkA58 = 0;
    for (i = 0; i < 4; i++) {
        e = (Q03Ent *)((u8 *)D_80146398 + i * 0x96);
        if (e->f78 == 1) {
            k = func_0041F1B0(e->f80);
            n += k;
            v.x = D_800E3A58[k].f4[slot];
            v.y = D_800E3A58[k].f4[slot];
            v.z = D_800E3A58[k].f4[slot];
            func_0041CB48((u8 *)D_800E4690 + off, 9, e->f80 + 0x38F, 0x4B, 0x5DC0, v, D_800E3A58[k].v24[slot], D_800E3A58[k].f14[slot], D_800E3A58[k].u54[slot]);
            off += 0x4A8;
            slot = 2;
            if (n >= 2) {
                break;
            }
        }
    }
    return 0;
}
