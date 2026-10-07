#include "b01_types.h"

void func_002737D0(f32 *m, f32 a);
void func_00273930(f32 *m, f32 a);
void func_00273B08(f32 *m, f32 a);
void func_0027302C(void *dst, f32 *m);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_002725BC(Vec3f *v, f32 s);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_00273DDC(void *m);

void func_00207910(B01Actor *actor, B01State *state) {
    f32 rot[16];
    func_002737D0(rot, state->vec130.z);
    func_00273930(rot, state->vec130.y);
    func_00273B08(rot, actor->unk6C);
    func_0027302C(actor->mtx74, rot);
    func_002734EC(actor->mtx74, actor->unk50, actor->unk54, actor->unk58);
    func_002725BC(&actor->pos, 20000.0f);
    func_002734B8(actor->mtx74, actor->pos.x, actor->pos.y, actor->pos.z);
    func_00273DDC(actor->mtx74);
}
