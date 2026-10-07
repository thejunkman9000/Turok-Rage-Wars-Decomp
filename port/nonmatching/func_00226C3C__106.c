#include "b06_types.h"

f32 cosf(f32 x);
f32 sinf(f32 x);
void func_00274108(Vec4f *out, Vec4f *a, Vec4f *b);
extern f32 D_800C7C60;
extern f32 D_80115DEC;

void func_00226C3C(Plr *a, Vec4f *out) {
    Vec4f q1, q2, q3, q4, q5, q6;
    f32 yaw, pitch, roll, r, K;
    f32 yaw0, roll0, pitch0;
    yaw0 = a->unk724 + a->unk730 - a->unk708;
    K = D_800C7C60;
    pitch = (a->unk72C + a->unk738) * K;
    roll = a->unk728 + a->unk734;
    r = a->unk6C;
    q4 = a->unk5C;
    D_80115DEC = sinf(pitch);
    q3.x = 0.0f;
    q3.y = 0.0f;
    q3.z = D_80115DEC;
    yaw = yaw0 * K;
    q3.w = cosf(pitch);
    D_80115DEC = sinf(yaw);
    q1.x = D_80115DEC;
    q1.y = 0.0f;
    q1.z = 0.0f;
    q1.w = cosf(yaw);
    roll = (r + roll) * K;
    D_80115DEC = sinf(roll);
    q2.x = 0.0f;
    q2.y = D_80115DEC;
    q2.z = 0.0f;
    q2.w = cosf(roll);
    func_00274108(&q5, &q1, &q2);
    func_00274108(&q6, &q5, &q4);
    func_00274108(out, &q3, &q6);
}
