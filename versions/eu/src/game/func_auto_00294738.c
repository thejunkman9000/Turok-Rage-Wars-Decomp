#include "b21_types.h"

extern s32 D_80146928;
extern s32 D_800D2980;
extern f32 D_800D2994;
extern f32 D_800D298C;
extern f32 D_800D2990;
extern f32 D_800CA5C0;
extern s32 D_80154048;
extern u8 D_8011FE88[];
void func_0029324C();
void func_0023EDF0();
void func_44E178(void *a, s32 b, s32 c);

void func_auto_00294738(B21Game *g) {
    f32 v;
    D_80146928 = 0;
    D_800D2980 = 0;
    func_0029324C();
    func_0023EDF0();
    v = D_800CA5C0;
    D_800D2994 = v;
    D_800D298C = v;
    D_800D2990 = v;
    func_44E178(D_8011FE88, g->unk26DD8, 0);
    g->unk26DB8 = 13;
    D_80154048 = 0;
}
