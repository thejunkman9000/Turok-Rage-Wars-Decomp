#include "b21_types.h"

extern s32 D_800D29C0;
extern f32 D_800CA5BC;
void func_0028D8E8(B21Game *g);
void func_002459F0(f32 a);
void func_0029397C(B21Game *g, s32 a);

void func_00294428(B21Game *g) {
    D_800D29C0++;
    func_0028D8E8(g);
    func_002459F0(D_800CA5BC);
    func_0029397C(g, 111);
}
