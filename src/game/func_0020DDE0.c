/* func_0020DDE0 (ROM 0xE9E0, 549 insns): AI aim / launch-angle search for a ballistic shot (upstream: func_8020DDF4_eu).
   Needs @SN -fno-builtin (sqrtf is a real call).  The three stray words in front of it (ROM 0xE9D4) are linker padding: unit pad_00E9D4.
   State machine on ctl->unk268: 0 = set up from the target distance (c->unk264) and the elevation angle (atan2(dy, hd) in degrees),
   1..10 / 11..20 = bisection over the launch pitch c->unk278 inside [c->unk280, c->unk27C] (45 degree sectors c->unk284 = 0..3),
   >= 21 = give up.  The predicted height at horizontal distance hd is hd*tan(a) + grav*hd*hd/(2*speed*speed*cos(a)^2);
   func_0020E674 simulates the arc and returns nonzero when it is blocked.  Returns 1 when the search is finished / reset. */
#include "s1001_types.h"

f32 func_0029D044(f32 a, f32 b);
f32 func_0029ED3C(f32 x);
f32 func_00285600(S1Pair p);
void *func_0028FD94(void *tbl, s32 idx);
s32 func_00265570(u32 *a, s32 n, u32 key, s32 *first, s32 *last);
s32 func_0020E674(S1Ctl *c, f32 speed, f32 grav);
extern void *D_801315F4;

s32 func_0020DDE0(S1Ctl *c) {
    Vec3f a;
    Vec3f b;
    s32 idx;
    s32 last;
    f32 dy;
    f32 hd;
    f32 speed;
    f32 grav;
    f32 h;
    f32 cs;
    f32 cs2;
    f32 tn;
    s32 id;
    s32 mode;
    s32 n;
    void *p;
    u32 *t;
    S1Elem *e;

    id = 0;
    mode = c->owner->unk62E;
    if (mode != c->unk26C) {
        c->unk268 = 0;
        c->unk26C = mode;
    }
    if (c == NULL) {
        return 1;
    }
    if (c->unk268 == 0) {
        a = c->owner->pos;
        b = c->v258;
        b.x = b.x - a.x;
        b.y = b.y - a.y;
        b.z = b.z - a.z;
        c->unk264 = sqrtf(b.x * b.x + b.y * b.y + b.z * b.z);
        dy = b.y;
        b.y = 0.0f;
        hd = sqrtf(b.x * b.x + b.z * b.z);
        switch (mode) {
        case 10:
        case 12:
            c->unk268 = 1;
            c->unk270 = 1;
            c->unk274 = 0;
            break;
        case 6:
        case 8:
            c->unk268 = 0xB;
            c->unk270 = 0;
            c->unk274 = 1;
            break;
        case 9:
            c->unk268 = 1;
            c->unk270 = 1;
            c->unk274 = 1;
            break;
        default:
            if (hd == 0.0f) {
                if (dy < 0.0f) {
                    c->unk248 = -90.0f;
                } else {
                    c->unk248 = 90.0f;
                }
            } else {
                c->unk248 = func_0029D044(dy, hd) * 57.2957764f;
            }
            c->unk24C = c->unk248;
            c->unk270 = 0;
            c->unk274 = 0;
            c->unk254 = c->unk250 = 0.0f;
            return 1;
        }
        if (hd == 0.0f) {
            if (dy < 0.0f) {
                c->unk278 = -90.0f;
            } else {
                c->unk278 = 90.0f;
            }
        } else {
            c->unk278 = func_0029D044(dy, hd) * 57.2957764f;
        }
        c->unk24C = c->unk278;
        if (c->unk278 > 45.0f) {
            c->unk284 = 0;
        } else if (c->unk278 > 0.0f) {
            c->unk284 = 1;
        } else if (c->unk278 > -45.0f) {
            c->unk284 = 2;
        } else {
            c->unk284 = 3;
        }
        c->unk27C = 90.0f - (f32)c->unk284 * 45.0f;
        c->unk280 = c->unk278;
        c->unk278 = (c->unk27C + c->unk280) * 0.5f;
        if (c->unk270 != 0) {
            c->unk24C = c->unk278;
        }
        return 0;
    }
    if (c->unk268 < 0xB) {
        switch (mode) {
        case 2:
            id = 0x12E;
            break;
        case 9:
            id = 0x12E;
            break;
        case 10:
            id = 0x12E;
            break;
        case 12:
            id = 0x12E;
            break;
        }
    } else if (c->unk268 < 0x15) {
        c->unk270 = 0;
        switch (mode) {
        case 6:
            id = 0x12E;
            break;
        case 8:
            id = 0x12E;
            break;
        case 9:
            id = 0x12E;
            break;
        }
    }
    if (c->unk268 < 0x15) {
        p = D_801315F4;
        t = func_0028FD94(p, 1);
        n = t[1];
        if (func_00265570(t + 2, n, id, &idx, &last) == 0) {
            c->unk270 = 0;
            c->unk274 = 0;
            c->unk268 = 0;
            return 1;
        }
        e = (S1Elem *)((u8 *)func_0028FD94(p, 2) + 8);
        e += idx;
        speed = func_00285600(e->rec->speed);
        grav = func_00285600(e->rec->grav);
        a = c->owner->pos;
        b = c->v258;
        b.x = b.x - a.x;
        b.y = b.y - a.y;
        b.z = b.z - a.z;
        c->unk264 = sqrtf(b.x * b.x + b.y * b.y + b.z * b.z);
        dy = b.y;
        b.y = 0.0f;
        hd = sqrtf(b.x * b.x + b.z * b.z);
        cs = cosf(c->unk278 * 0.0174532942f);
        cs2 = cs * cs;
        tn = func_0029ED3C(c->unk278 * 0.0174532942f);
        h = tn * hd + grav * (hd * hd) / (speed * speed * 2.0f * cs2);
        if (dy - 1.0f <= h && h <= dy + 1.0f) {
            if (func_0020E674(c, speed, grav) != 0 && c->unk284 > 0) {
                c->unk284 = c->unk284 - 1;
                c->unk27C = 90.0f - (f32)c->unk284 * 45.0f;
                c->unk280 = 45.0f - (f32)c->unk284 * 45.0f;
                if (c->unk270 != 0) {
                    c->unk268 = 1;
                } else {
                    c->unk268 = 0xB;
                }
                return 0;
            }
            if (c->unk270 != 0 && c->unk274 != 0) {
                c->unk250 = c->unk278 - c->unk248;
                c->unk268 = 0xB;
                c->unk270 = 0;
                if (c->unk24C > 45.0f) {
                    c->unk284 = 0;
                } else if (c->unk24C > 0.0f) {
                    c->unk284 = 1;
                } else if (c->unk24C > -45.0f) {
                    c->unk284 = 2;
                } else {
                    c->unk284 = 3;
                }
                c->unk27C = 90.0f - (f32)c->unk284 * 45.0f;
                c->unk280 = 45.0f - (f32)c->unk284 * 45.0f;
                return 0;
            }
            c->unk270 = 0;
            c->unk274 = 0;
            c->unk250 = c->unk278 - c->unk248;
            c->unk268 = c->unk268 + 1;
            return 1;
        }
        if (c->unk268 + 1 == 0xB) {
            c->unk270 = 0;
            c->unk250 = c->unk278 - c->unk248;
            c->unk268 = c->unk268 + 1;
            if (c->unk24C > 45.0f) {
                c->unk284 = 0;
            } else if (c->unk24C > 0.0f) {
                c->unk284 = 1;
            } else if (c->unk24C > -45.0f) {
                c->unk284 = 2;
            } else {
                c->unk284 = 3;
            }
            c->unk27C = 90.0f - (f32)c->unk284 * 45.0f;
            c->unk280 = 45.0f - (f32)c->unk284 * 45.0f;
            if (c->unk274 == 0) {
                c->unk268 = 0;
            }
            return c->unk274 == 0;
        }
        if (c->unk268 + 1 >= 0x15) {
            c->unk270 = 0;
            c->unk274 = 0;
            c->unk254 = c->unk278 - c->unk24C;
            c->unk268 = c->unk268 + 1;
            return 1;
        }
        if (h < dy - 1.0f) {
            switch (c->unk284) {
            case 0:
                c->unk27C = c->unk278;
                break;
            case 1:
            case 2:
            case 3:
                c->unk280 = c->unk278;
                break;
            }
        } else {
            switch (c->unk284) {
            case 0:
                c->unk280 = c->unk278;
                break;
            case 1:
            case 2:
            case 3:
                c->unk27C = c->unk278;
                break;
            }
        }
        c->unk278 = (c->unk27C + c->unk280) * 0.5f;
        c->unk268 = c->unk268 + 1;
        return 0;
    }
    c->unk268 = 0;
    c->unk270 = 0;
    c->unk274 = 0;
    return 1;
}
