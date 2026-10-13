#include "b07_types.h"
extern u8 D_801462C8[];
extern ActorRow400 D_80102B00[];
extern f32 D_800C8100;
extern s32 D_800E0D44[];
s32 func_0022F54C(void *row, s32 idx);
void func_0025DF54(s32 id);
s32 func_0022A590(void *a, Actor *actor);
void func_002398F8(void *a, void *b, s32 c, s32 d, f32 e);
s32 func_auto_00232788(Actor *actor)
{
    s32 r;
    s32 v;
    u8 *g;
    if (AT(f32, actor, 0x11D8) > 0) {
        return 0;
    }
    if (actor->unk1450 != 0) {
        return 1;
    }
    g = D_801462C8;
    if (g[0xD] != 1) {
        return 1;
    }
    r = func_0022F54C(&D_80102B00[actor->unk5D4], AT(s16, actor, 0x62E));
    if (r == 0) {
        func_0025DF54(0xD4D);
        if (AT(void *, actor, 0x5DC) != NULL) {
            v = func_0022A590(g - 0x1288, actor);
            func_002398F8(g - 0x1240, AT(void *, actor, 0x5DC), D_800E0D44[g[0x581]], v, D_800C8100);
        }
    }
    return r;
}
