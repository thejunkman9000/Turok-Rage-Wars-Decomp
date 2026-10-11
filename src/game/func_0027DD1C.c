#include "b18_types.h"

typedef struct B18Rg {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s8 unk18;
} B18Rg;

typedef struct B18Lr {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
} B18Lr;

typedef struct B18CfgD {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9;
    /* 0x0A */ s8 unkA;
    /* 0x0B */ u8 padB[9];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0xC];
    /* 0x24 */ B18Lr *unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ B18Rg *unk2C;
} B18CfgD;

typedef struct B18Od B18Od;
struct B18Od {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x48];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18CfgD *cfg;
    /* 0x11C */ u8 pad11C[0x24];
    /* 0x140 */ f32 unk140;
    /* 0x144 */ u8 pad144[0xC];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15C */ u8 pad15C[0x18];
    /* 0x174 */ Vec3f unk174;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18C */ u8 pad18C[0x10];
    /* 0x19C */ f32 unk19C;
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ u8 pad1A4[8];
    /* 0x1AC */ f32 unk1AC;
    /* 0x1B0 */ f32 unk1B0;
    /* 0x1B4 */ u8 pad1B4[0x1C];
    /* 0x1D0 */ s8 unk1D0;
    /* 0x1D1 */ s8 unk1D1;
    /* 0x1D2 */ u8 pad1D2[6];
    /* 0x1D8 */ u8 unk1D8;
};

typedef struct B18Cm {
    /* 0x00 */ u8 pad0[0x6C];
    /* 0x6C */ f32 unk6C;
} B18Cm;

#define MAXF(a, b) (((a) < (b)) ? (b) : (a))

extern u8 D_8011FE88[];
extern s32 D_800D297C;

f32 sinf(f32);
void func_002702EC(void *m, void *a);
void func_00271FA4(Vec3f *o, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *o, Vec3f *a, f32 s);
void func_00272088(Vec3f *o, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_002725BC(Vec3f *v, f32 s);
void func_00272848(void *m);
void func_00272898(void *m);
void func_00272CD0(void *m, f32 a, f32 b, f32 c);
void func_00272EAC(void *m, f32 a, f32 b, f32 c);
void func_0027302C(void *o, void *a);
void func_00273424(void *m, f32 a, f32 b, f32 c);
void func_002734B8(void *m, f32 a, f32 b, f32 c);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
void func_002737D0(void *m, f32 a);
void func_00273930(void *m, f32 a);
void func_00273B08(void *m, f32 a);
void func_00273DDC(void *m);
f32 func_00275E44(s32 a, f32 x, f32 z);
f32 func_002752CC(s32 a, f32 x, f32 z);
void func_0026F690(void *o, void *a, void *b);
void func_0028C6B0(void *a, Vec3f *b, void *c);
void *func_0027D950(B18Od *o, void *c);
void func_0027DAA4(B18Od *o, Vec3f *a, Vec3f *b);

extern f32 D_800C9D58;
extern f32 D_800C9D5C;
extern f32 D_800C9D60;
extern f32 D_800C9D64;
extern f32 D_800C9D68;
extern f32 D_800C9D6C;
extern f32 D_800C9D70;
extern f32 D_800C9D74;

static inline f32 Ramp2(B18CfgD *par, f32 xin) {
    register f32 x asm("$f4") = xin;
    f32 d;
    f32 k;
    d = x - D_800C9D58;
    k = !(d < 0.0f) ? (!(D_800C9D60 < d * D_800C9D5C) ? (!(d < 0.0f) ? d * D_800C9D64 : 0.0f) : D_800C9D60) : 0.0f;
    {
        register f32 fb asm("$f2") = par->unk24->unk20;
        register f32 fa asm("$f3") = par->unk24->unk1C;
        x = x * (fa + (fb - fa) * k) * D_800C9D68;
    }
    return x;
}

void func_0027DD1C(B18Od *o, void *m, B18Cm *c, f32 px) {
    u8 mtx10[0x40];
    u8 mtx50[0x40];
    u8 mtx90[0x40];
    u8 mtxD0[0x40];
    u8 mtx110[0x40];
    Vec3f v150;
    Vec3f v160;
    Vec3f v170;
    Vec3f v180;
    Vec3f v190;
    Vec3f v1A0;
    Vec3f v1B0;
    Vec3f v1C0;
    Vec3f v1D0;
    Vec3f v1E0;
    B18CfgD *cfg;
    B18CfgD *cp;
    f32 t, d, r, s, s2, e;
    void *mm;
    void *mp;
    void *p;

    register f32 x asm("$f5") = px;
    cfg = o->cfg;
    if (c != NULL) {
        cp = o->cfg;
        if (cfg->flags & 4) {
            t = Ramp2(cp, x);
        } else {
            t = D_800C9D6C;
        }
        {
            f32 m = c->unk6C;
            s = t * 0.021052632f * (m + (D_800C9D70 - m) * D_800C9D74);
        }
    } else {
        s = 1.0f;
    }
    if (cfg->flags & 8) {
        s2 = o->unk154 * o->unk158 * s;
    } else {
        s2 = 0.0f;
    }
    func_0027DAA4(o, &v150, &v170);
    if (!(o->flags & 0x30000)) {
        if (0.0f < o->unk140) {
            f32 k = 1.0f;
            s32 b = cfg->unk2C->unk18;
            if (b != 0) {
                f32 fb = (f32)b;
                if (o->unk140 < fb) k = o->unk140 / fb;
            }
            v1D0 = o->unk174;
            if (o->unk1AC < 0.0f) {
                v160.x = 0.0f;
                v160.z = 0.0f;
                v160.y = 1.0f;
                func_00272088(&v1C0, &v160, &v1D0);
                func_0027200C(&v1E0, &v1C0, sinf(o->unk19C) * -o->unk1AC * k);
                func_00271FA4(&v150, &v150, &v1E0);
            }
            if (o->unk1B0 < 0.0f) {
                v160.x = 0.0f;
                v160.z = 0.0f;
                v160.y = 1.0f;
                func_00272088(&v1B0, &v160, &v1D0);
                func_00272088(&v1C0, &v1B0, &v1D0);
                func_0027200C(&v1E0, &v1C0, sinf(o->unk1A0) * -o->unk1B0 * k);
                func_00271FA4(&v150, &v150, &v1E0);
            }
        }
    }
    if (o->cfg->unk14 != 0) {
        if (o->unk1D0 == -7) {
            func_00272EAC(&mtx10, o->unk180 + 1.5707965f, o->unk184, o->unk188);
            if (v170.x == 0.0f && v170.y == 0.0f && v170.z == 0.0f) {
                v1A0 = o->unk174;
            } else {
                v1A0 = v170;
            }
            func_002720EC(&v1A0);
            v160.x = 0.0f;
            v160.y = 1.0f;
            v160.z = 0.0f;
            func_00272088(&v180, &v160, &v1A0);
            func_00272088(&v190, &v180, &v1A0);
            func_00272848(mtx50);
            func_002720EC(&v180);
            func_002720EC(&v190);
            func_002720EC(&v1A0);
            ((f32 *)mtx50)[0] = v180.x;
            ((f32 *)mtx50)[1] = v180.y;
            ((f32 *)mtx50)[2] = v180.z;
            ((f32 *)mtx50)[4] = v190.x;
            ((f32 *)mtx50)[5] = v190.y;
            ((f32 *)mtx50)[6] = v190.z;
            ((f32 *)mtx50)[8] = v1A0.x;
            ((f32 *)mtx50)[9] = v1A0.y;
            ((f32 *)mtx50)[10] = v1A0.z;
            func_0026F690(mtx90, mtx10, mtx50);
        } else {
            func_00272EAC(mtx90, o->unk180, o->unk184 + 3.141593f, o->unk188);
        }
        func_0028C6B0(D_8011FE88, &o->pos, (u8 *)o + (D_800D297C * 0x18 + 0xE0));
    } else {
        if (o->unk180 == 0.0f && o->unk184 == 0.0f) {
            func_002737D0(mtx90, o->unk188);
        } else {
            f32 a, b, na;
            func_002737D0(mtx90, o->unk188);
            a = 0.0f;
            if (o->cfg->unk14 == 0) a = o->unk180;
            na = -a;
            b = 0.0f;
            if (o->cfg->unk14 == 0) b = o->unk184;
            func_00273424(mtx90, na, -b, 0.0f);
        }
    }
    {
        f32 z0 = 0.0f;
        if (s2 != z0) {
            func_00273424(mtx90, z0, s2, z0);
            func_002734B8(mtx90, z0, -s2, z0);
        }
    }
    o->flags &= 0xFF7FFFFF;
    switch (o->unk1D0) {
    case 2:
    case 1:
    case 0:
        break;
    case -8:
        v150.x += o->unk174.x * 5.12f;
        v150.y += o->unk174.y * 5.12f;
        v150.z += o->unk174.z * 5.12f;
        break;
    case -5:
        if (cfg->unkA != 0) {
            e = 5.12f;
            v150.y = MAXF(func_00275E44(0, v150.x, v150.z) + e, v150.y);
        }
        break;
    case -3:
        d = func_00275E44(0, v150.x, v150.z);
        if (cfg->flags & 0x400) {
            if (v150.y < d + 1.024f) {
                v150.y = d;
                o->flags |= 0x800000;
            }
        } else {
            v150.y = !(v150.y <= d + 5.12f) ? v150.y : d + 5.12f;
        }
        break;
    case -2:
        if (cfg->unkA != 0) {
            e = 5.12f;
            v150.y = (v150.y < func_002752CC(0, v150.x, v150.z) - e) ? v150.y : func_002752CC(0, v150.x, v150.z) - e;
        }
        break;
    case -6:
    case -4:
    case -1:
        v150.y += s2;
        break;
    }
    func_002725BC(&v150, 20000.0f);
    if (cfg->flags & 0x80000) {
        if (cfg->unk8 == 1) {
            s = s * 0.003921569f * (f32)o->unk1D8;
        }
    }
    if (o->cfg->unk14 != 0) {
        e = s * o->unk158 * 0.034179688f;
        if (o->type == 0x40B || o->type == 0x40F || o->type == 0x41E || o->type == 0x40B || o->type == 0x436) {
            func_002734EC(mtx90, -1.0f, -1.0f, -1.0f);
        }
        func_002734EC(mtx90, o->unk150 * e, o->unk154 * e, e * 10.24f);
        func_00273DDC(mtx90);
    } else {
        e = s * o->unk158;
        func_002734EC(mtx90, o->unk150 * e, o->unk154 * e, e * 10.24f);
    }
    mm = func_0027D950(o, c);
    if (mm != NULL) {
        func_0026F690(mtxD0, mtx90, mm);
    } else {
        func_0027302C(mtxD0, mtx90);
    }
    p = mtxD0;
    asm("" : "+r"(p));
    func_002734B8(p, v150.x, v150.y, v150.z);
    if (o->flags & 0x20000) {
        s32 a0 = o->unk1D1;
        if (a0 != 0) {
            f32 q, q2, z1;
            register s32 cb asm("$7");
            mp = mtx110;
            q = (f32)a0 * 0.007874016f;
            asm volatile("li %0,0xC2851EB8" : "=r"(cb));
            q = q * q;
            z1 = 0.0f;
            q2 = q * 0.087266475f;
            ((void (*)(void *, f32, f32, s32))func_00272CD0)(mp, z1, z1, cb);
            func_00273B08(mp, q2 * (sinf(q * 18.849558f) * 0.25f));
            q2 = q2 * sinf(q * 43.9823f);
            func_00273930(mp, q2);
            func_002734B8(mp, z1, z1, 66.56f);
            func_0026F690(mtx10, mp, p);
            func_00272898(mtx10);
            func_002702EC(mtx10, m);
        } else {
            mp = mtxD0;
            func_00272898(mp);
            func_002702EC(mp, m);
        }
    } else {
        mp = mtxD0;
        func_00272898(mp);
        func_002702EC(mp, m);
    }
}