#include "q04_types.h"
typedef struct { u8 pad[0x14]; void (*f14)(void *, void *, void *, void *); } Q04DefB;
typedef struct { s16 cur; s16 w2; s16 w4; u8 pad6[6]; Q04Item *items; s32 n; u8 pad14[0x30 - 0x14]; f32 f30; f32 f34; } Q04Pn;
typedef struct { u8 pad[0x29C]; f32 f29C; f32 f2A0; f32 f2A4; f32 f2A8; } Q04Cm;
extern void func_002AB9E4(void *it);
extern void func_002A8DD4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_0043F69C(Q04Item *it, Q04Info *info);
extern Q04Cm *func_00442BC8();
extern f32 sinf(f32 x);
extern u32 D_800D2980;
extern s32 D_800E5E70;
void func_00441764(Q04Pn *p, void *a1) {
    struct { s32 f, w, h, g; } sz;
    struct { s32 f, x0, x1, y0, y1; } r;
    Q04Info info;
    Q04Info cp;
    Q04Cm *cam;
    Q04Item *it;
    s32 i, v, v2, v3, v4;
    f32 cx, cy, hw, hh, fa, fb, sv, tt;
    u32 al;
    i = 0;
    cam = func_00442BC8(a1);
    r.x0 = 0x400; r.x1 = -0x400; r.y0 = 0x400; r.y1 = -0x400;
    info.f4 = 0; info.f8 = 0; info.x0 = 0; info.x1 = 0; info.y0 = 0; info.y1 = 0;
    for (; i < p->n; i++) {
        it = &p->items[i];
        if (it->flags & 0x800000) {
            if (it->flags & 0x20000000) {
                info.x0 = 0x400; info.x1 = -0x400; info.y0 = 0x400; info.y1 = -0x400;
                info.f4 = 0; info.f8 = 0;
            } else {
                func_0043F69C(it, &info);
            }
            v = info.x0; if (r.x0 < v) v = r.x0; r.x0 = v;
            v2 = info.x1; if (v2 < r.x1) v2 = r.x1; r.x1 = v2;
            v3 = info.y0; if (r.y0 < v3) v3 = r.y0; r.y0 = v3;
            v4 = info.y1; if (v4 < r.y1) v4 = r.y1; r.y1 = v4;
        }
    }
    sz.w = r.x1 - r.x0;
    sz.h = r.y1 - r.y0;
    if (sz.w >= 0 && sz.h >= 0) {
        cx = cam->f2A4 + cam->f29C * 0.5f + (f32)p->w2;
        cy = cam->f2A8 + cam->f2A0 * 0.5f + (f32)p->w4;
        info.f4 = 0; info.f8 = 0; info.x0 = 0; info.x1 = 0;
        hw = (f32)(sz.w / 2);
        hh = (f32)(sz.h / 2);
        info.y0 = 0; info.y1 = 0;
        r.x0 = (s32)(cx - hw);
        r.x1 = (s32)(cx + hw);
        r.y0 = (s32)(cy - hh);
        r.y1 = (s32)(cy + hh);
        D_800E5E70 = -1;
        for (i = 0; i < p->n; i++) {
            it = &p->items[i];
            if (it->flags & 0x800000) {
                info.f0 = i;
                if (it->flags & 0x20000000) {
                    func_0043F69C(it, &info);
                    info.f4 = 0; info.f8 = 0;
                    info.x0 = (s32)cam->f2A4;
                    info.x1 = 0;
                    info.y0 = (s32)cam->f2A8;
                    info.y1 = 0;
                } else {
                    func_0043F69C(it, &info);
                }
                cp = info;
                if (!(it->flags & 0x20000000)) {
                    cp.x0 += r.x0;
                    cp.x1 += r.x0;
                    cp.y0 += r.y0;
                    cp.y1 += r.y0;
                }
                if (it->flags & 1) {
                    cp.x0 = (s32)(cx - (f32)(info.f4 / 2));
                    cp.x1 = cp.x0 + info.f4;
                }
                if (it->flags & 2) {
                    cp.x0 = r.x0;
                    cp.x1 = r.x0 + info.f4;
                }
                if (it->flags & 4) {
                    cp.x1 = r.x1;
                    cp.x0 = r.x1 - info.f4;
                }
                if (it->flags & 0x800000) {
                    if (p->cur == i && it->w4 != 3) {
                        if (!(it->flags & 8)) {
                            fb = (f32)cp.y0;
                            fa = (f32)cp.y1;
                            fa = fb + (fa - fb);
                            func_002AB9E4(it);
                            tt = sinf((f32)(D_800D2980 * 10) * 0.017453294f);
                            sv = p->f30 * p->f34 * ((tt + 1.0f) * 50.0f + 50.0f);
                            if (it->flags & 0x10) {
                                func_002A8DD4(cp.x0 - 4, (s32)fb, cp.x1 + 4, (s32)fa, 0, 0, 0xFF, 0, 10, (u32)sv & 0xFF);
                            } else {
                                func_002A8DD4(cp.x0 - 4, (s32)fb, cp.x1 + 4, (s32)fa, 0, 0, 0xFF, 0, 10, (u32)sv & 0xFF);
                            }
                            D_800E5E70 = -1;
                        }
                    }
                    ((Q04DefB *)it->def)->f14(it, &cp, &sz, p);
                }
            }
        }
    }
}
