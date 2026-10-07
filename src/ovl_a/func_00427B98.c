#include "o04_types.h"
typedef struct { f32 x; f32 y; f32 z; } O04V3;
typedef struct { u8 pad0[4]; u8 unk4; } O04Rec4;
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96j;
typedef struct {
    u8 pad0[4]; f32 unk4; u8 pad8[0xC]; f32 unk14; u8 pad18[0xC]; O04V3 unk24; u8 pad30[0x24]; s32 unk54; u8 pad58[0x70 - 0x58];
} O04Tbl70;
extern O04ModeS4690 *D_800E4690;
extern O04Cfg D_801462C8[];
extern O04Tbl70 D_800E3A58[];
extern u8 D_8011FE88[];
void func_004286A0(s32 a);
O04Rec4 *func_0028D450(void *a, s32 b);
s32 func_0041F1B0(s32 a);
void func_0041CB48(void *p, s32 a, s32 b, s32 c, s32 d, O04V3 v1, O04V3 v2, f32 f, s32 g);
void func_00427B98(void) {
    s32 s1;
    s32 k;
    O04Ent96j *e;
    O04V3 v;
    if (D_801462C8->unkD != 4) {
        return;
    }
    s1 = D_800E4690->unkA44;
    e = (O04Ent96j *)((u8 *)D_801462C8 + 0xD0) + D_800E4690->unkA5C;
    func_004286A0(s1);
    e->unk80 = func_0028D450(D_8011FE88, s1)->unk4;
    k = func_0041F1B0(e->unk80);
    v.x = D_800E3A58[k].unk4;
    v.y = D_800E3A58[k].unk4;
    v.z = D_800E3A58[k].unk4;
    func_0041CB48(&D_800E4690->unk20, 9, e->unk80 + 0x38F, 0x4B, 0x5DC0, v, D_800E3A58[k].unk24, D_800E3A58[k].unk14, D_800E3A58[k].unk54);
}
