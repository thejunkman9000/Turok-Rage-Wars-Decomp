#include "b17_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned); extern char *getenv(const char *);
static int g_ldbg = -1, g_ln;

extern f32 D_800C9BC8;
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
void func_002720EC(Vec3f *v);
void func_00272908(Mat4F *m, Vec3f *in, Vec3f *out);
void func_00272BA8(Mat4F *m, Vec3f *in, Vec3f *out);
s32 func_00277198(Probe *o, f32 x, f32 y, f32 z, Vec3f *hit, f32 *dist);

s32 func_00277444(Probe *o, Vec3f pos, Vec3f dir, Mat4F *m, Vec3f *out, f32 *outDist) {
    Vec3f wd, wp, hit;
    f32 d, t, f4;

    if (o->bB9 != 0) {
        wp.x = pos.x * m->m[0];
        wp.y = pos.y * m->m[5];
        wp.z = pos.z * m->m[10];
        wp.x = wp.x + m->m[12];
        wp.y = wp.y + m->m[13];
        wp.z = wp.z + m->m[14];
        wd.x = dir.x * m->m[0];
        wd.y = dir.y * m->m[5];
        wd.z = dir.z * m->m[10];
    } else {
        func_00272908(m, &pos, &wp);
        func_00272BA8(m, &dir, &wd);
    }
    func_002720EC(&wd);
    if (g_ldbg < 0) g_ldbg = getenv("TUROK_LIGHTDBG") ? 1 : 0;
    if (func_00277198(o, wp.x, wp.y, wp.z, &hit, &d) == 0) {
        if (g_ldbg && g_ln < 400) { g_ln++; fprintf(__acrt_iob_func(2), "ltest miss: pos (%.0f %.0f %.0f) -> light (%.2f %.2f %.2f) mode=%d f0=%.2f diag=%d m0=%.3f m5=%.3f m10=%.3f t=(%.0f %.0f %.0f)\n", pos.x, pos.y, pos.z, wp.x, wp.y, wp.z, ((u8 *)o)[0xBB], o->f0, o->bB9, m->m[0], m->m[5], m->m[10], m->m[12], m->m[13], m->m[14]); }
        return 0;
    } else {
        t = -(hit.x * wd.x + hit.y * wd.y + hit.z * wd.z);
        if (t < 0.0f) {
            t = 0.0f;
        }
        f4 = o->f4;
        d = d * (f4 + t * (D_800C9BC8 - f4));
        if (d <= 0.0f) {
            d = 0.0f;
        }
        if (o->bB8 != 0) {
            d = -d;
        }
        if (outDist != 0) {
            *outDist = d;
        }
        if (g_ldbg && g_ln < 400) { g_ln++; fprintf(__acrt_iob_func(2), "ltest HIT: pos (%.0f %.0f %.0f) -> light (%.2f %.2f %.2f) mode=%d d=%.2f col (%.0f %.0f %.0f)\n", pos.x, pos.y, pos.z, wp.x, wp.y, wp.z, ((u8 *)o)[0xBB], d, o->v8.x, o->v8.y, o->v8.z); }
        func_0027200C(out, &o->v8, d);
        return 1;
    }
}
