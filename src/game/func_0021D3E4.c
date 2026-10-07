#include "b04_types.h"
extern f32 D_800C7494, D_800C7498, D_800C749C, D_800C74A0, D_800CF1B4;
extern s32 D_800D297C;
typedef struct { f32 m[16]; } B04Mtx;
typedef struct { f32 x, y, z, w; } B04Q4;
typedef struct { u8 pad0[0x128]; Vec3f v128; f32 f12C_unused; } B04Cm;
typedef struct { u8 pad0[0x12C]; f32 f12C; } B04Cm2;
typedef struct {
    u8 pad0[0x260]; Vec3f v260; u8 pad26C[0x28]; /* placeholder to keep 0x264 inside v260 */
} B04Dummy;
typedef struct { u8 pad0[0x260]; f32 f260, f264, f268; u8 pad26C[0x1200 - 0x26C]; u8 pad1200[0x14]; s32 unk1214; } B04Unused;
typedef struct B04P8 B04P8;
struct B04P8 {
    u8 pad0[0x5DC]; B04Cm2 *cam;
};
void func_0022B134(void *, Vec3f *);
void func_002702EC(B04Mtx *, void *);
void func_00271888(B04Q4 *, Vec3f *);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_00271FD8(Vec3f *, Vec3f *, Vec3f *);
void func_0027200C(Vec3f *, Vec3f *, f32);
void func_002720EC(Vec3f *);
f32 func_00272768(Vec3f *, Vec3f *);
void func_00272848(B04Mtx *);
void func_00272EAC(B04Mtx *, f32, f32, f32);
void func_00273208(B04Mtx *, Vec3f *);
void func_00273424(B04Mtx *, f32, f32, f32);
void func_002734B8(B04Mtx *, f32, f32, f32);
void func_002734EC(B04Mtx *, f32, f32, f32);
void func_00273860(B04Mtx *, f32);
void func_002742B4(B04Q4 *, B04Mtx *);
#define PW(o, off) (*(u8 **)((u8 *)(o) + (off)))
#define PF(o, off) (*(f32 *)((u8 *)(o) + (off)))
#define PV(o, off) (*(Vec3f *)((u8 *)(o) + (off)))
void func_0021D3E4(void *p, Vec3f *v1, Vec3f *v2) {
    Vec3f a, b, c, d, e, f;
    B04Mtx m;
    B04Q4 q;
    f32 zero, t, u, y0, k;
    B04Cm2 *cm;
    void *cam = PW(p, 0x5DC);
    if (cam != NULL) {
        f = PV(cam, 0x128);
    } else {
        func_0022B134(p, &f);
    }
    b = f;
    a = *v1;
    func_00271FD8(&d, &a, &b);
    func_002720EC(&d);
    func_00272848(&m);
    if (d.y >= D_800C7494) {
        func_00272EAC(&m, -1.57079649f, PF(p, 0x6C), 0);
    } else if (d.y <= D_800C7498) {
        func_00272EAC(&m, 1.57079649f, PF(p, 0x6C), 0);
    } else {
        func_00273208(&m, &d);
    }
    func_002734B8(&m, b.x, b.y, b.z);
    zero = 0.0f;
    func_00273424(&m, zero, zero, D_800CF1B4);
    func_002734EC(&m, 0.05f, 1.0f, D_800CF1B4 - func_00272768(&b, &a));
    func_002702EC(&m, (u8 *)p + ((D_800D297C << 6) + 0x1480));
    e = PV(p, 0x1464);
    cm = (B04Cm2 *)PW(p, 0x5DC);
    if (cm != NULL) {
        t = cm->f12C - PF(p, 0x264);
        y0 = e.y;
        if (t < zero)
            u = y0 + t;
        else
            u = y0 - t;
        e.y = u;
    }
    func_00271FD8(&d, &e, (Vec3f *)((u8 *)p + 0x260));
    func_002720EC(&d);
    func_00272848(&m);
    func_00273208(&m, &d);
    func_002734B8(&m, PF(p, 0x260), PF(p, 0x264), PF(p, 0x268));
    t = -func_00272768(&f, (Vec3f *)((u8 *)p + 0x1464));
    k = D_800C749C;
    func_002734EC(&m, k, k, t);
    func_002702EC(&m, (u8 *)p + ((D_800D297C << 6) + 0x1500));
    if (v2 != NULL) {
        c = *v2;
        func_00271888(&q, &c);
        func_002742B4(&q, &m);
        func_00273860(&m, 1.57079649f);
        func_002720EC(&c);
        func_0027200C(&c, &c, 2.048f);
        func_00271FA4(&b, &b, &c);
        func_002734B8(&m, a.x, a.y, a.z);
        func_002734EC(&m, D_800C74A0, k, D_800C74A0);
        func_002702EC(&m, (u8 *)p + ((D_800D297C << 6) + 0x1580));
    }
    *(s32 *)((u8 *)p + 0x1214) = 1;
}
