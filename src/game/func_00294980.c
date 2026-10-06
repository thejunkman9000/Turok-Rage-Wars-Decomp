#include "b21_types.h"
#include "b21_world.h"

extern s32 D_80146958;
extern s32 D_800D29D0;
extern s32 D_8011FAB0;
extern s32 D_800E28D4;
extern f32 D_8014AD78;
extern s32 D_800D29D4;
void func_0022A404(void *a);
void func_0028D8E8();
void func_0029397C(B21Game *g, s32 a);

void func_00294980(B21Game *g) {
    B21Sub1288 *s = &D_80145040.sub1288;
    s->unk1D = 0;
    D_800D29D0 = 0;
    D_8011FAB0 = 0;
    D_8014AD78 = (f32)D_800E28D4;
    D_80146958 = 0;
    func_0022A404(&D_80145040);
    D_800D29D4 = 0;
    func_0028D8E8();
    func_0029397C(g, 130);
    D_800D29D0 = 1;
    D_800D29D4 = 0;
}
