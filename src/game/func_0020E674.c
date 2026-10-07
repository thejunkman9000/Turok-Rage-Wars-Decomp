#include "b02_types.h"

s32 func_00244494(B2Actor *a, Vec3f from, Vec3f to, void *out);
extern B2Hit *D_80103FCC;
extern u8 D_80103FD0[];
extern f32 D_800C6F30;
extern f32 D_800C6F34;
extern f32 D_800C6F38;

s32 func_0020E674(B2Ctl *ctl, f32 speed, f32 grav) {
    Vec3f p0;
    Vec3f p1;
    Vec3f vel;
    Vec3f acc;
    f32 k;
    f32 h;
    f32 dt;
    f32 tt;
    f32 dd;
    f32 ax;
    f32 ay;
    f32 az;
    f32 a;
    s32 n;
    s32 i;

    if (ctl == NULL) {
        return 0;
    }
    if (ctl->unk264 == 0.0f) {
        return 0;
    }
    k = D_800C6F30 / ctl->unk264;
    vel.x = (ctl->v258.x - ctl->owner->pos.x) * k;
    vel.x *= speed * cosf(ctl->unk278);
    vel.z = (ctl->v258.z - ctl->owner->pos.z) * k;
    vel.z *= speed * cosf(ctl->unk278);
    vel.y = speed * sinf(ctl->unk278);
    acc.x = 0.0f;
    acc.y = grav;
    acc.z = 0.0f;
    h = speed * cosf(ctl->unk278) / ctl->unk264;
    if (h == 0.0f) {
        return 0;
    }
    n = (s32)(h * D_800C6F34);
    if (n == 0) {
        return 0;
    }
    dt = h / (f32)n;
    p0 = ctl->owner->pos;
    dd = dt * dt * D_800C6F38;
    ax = acc.x * dd;
    ay = acc.y * dd;
    az = acc.z * dd;
    p1.x = p0.x + vel.x * dt + ax;
    p1.y = p0.y + vel.y * dt + ay;
    p1.z = p0.z + vel.z * dt + az;
    tt = dt;
    if (func_00244494(ctl->owner, p0, p1, D_80103FD0) != 0) {
        if ((u32)(D_80103FCC->type - 7) >= 2) {
            return 1;
        }
    }
    vel.x += acc.x * tt;
    vel.y += acc.x * tt;
    vel.z += acc.x * tt;
    tt += dt;
    for (i = 0; i < n; i++) {
        p0 = p1;
        p1.x = p0.x + vel.x * tt + ax;
        p1.y = p0.y + vel.y * tt + ay;
        p1.z = p0.z + vel.z * tt + az;
        if (func_00244494(ctl->owner, p0, p1, D_80103FD0) != 0) {
            if ((u32)(D_80103FCC->type - 7) >= 2) {
                return 1;
            }
        }
        vel.x += acc.x * tt;
        vel.y += acc.x * tt;
        vel.z += acc.x * tt;
        tt += dt;
    }
    return 0;
}
