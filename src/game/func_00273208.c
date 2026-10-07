#include "b16_types.h"
extern f32 D_800C97B0[];
void func_00272088(Vec3f *dst, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_00273208(B16Mtx *m, Vec3f *dir) {
    Vec3f up;
    up = *(Vec3f *)&D_800C97B0[1];
    if (dir->y < 0.0f) {
        if (-dir->y >= 0.999999f) {
            goto parallel;
        }
    } else {
        if (dir->y >= 0.999999f) {
parallel:
            m->m[0][0] = 1.0f;
            m->m[0][1] = 0.0f;
            m->m[0][2] = 0.0f;
            goto next;
        }
    }
    func_00272088((Vec3f *)m->m[0], &up, dir);
next:
    func_00272088((Vec3f *)m->m[1], (Vec3f *)m->m[0], dir);
    *(Vec3f *)m->m[2] = *dir;
    func_002720EC((Vec3f *)m->m[0]);
    func_002720EC((Vec3f *)m->m[1]);
    func_002720EC((Vec3f *)m->m[2]);
    m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
}
