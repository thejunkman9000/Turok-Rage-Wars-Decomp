#include "b10_types.h"

typedef struct B10Tab { u32 f0, f4; } B10Tab;
extern B10Tab D_800D1384[];
extern s32 D_800D06BC;
B10Le *func_002625B8(s32 list);
s32 func_002625E4(s32 list);
s32 **func_0024BFC4(B10Obj *o, s32 b);
u8 *func_0028FD94(s32 n, s32 i);
void func_002536F4(s32 a, s32 **p);
void func_00272908(void *m, Vec3f *a, Vec3f *b);
void func_00270980(B10Mt *dst, B10Mt *src);
void func_00265E30(B10Obj *a, B10Obj *b, s32 id, s32 c, Vec3f v, B10Pair pr);

void func_002476B8(B10Obj *o, s32 list, f32 lo, f32 hi) {
    Vec3f v28;
    Vec3f v38;
    B10Mt m48;
    B10Le *p;
    B10Le *e;
    s32 **s2;
    u8 *s5;
    s32 n;
    s32 i;
    s32 fp;
    s32 s1;
    f32 f;
    if ((o->flags100 & 0x4000000) || list == (s32)&o->f104) {
        switch (o->hE4) {
        case 0x44E:
        case 0x451:
        case 0x453:
            fp = 1;
            break;
        default:
            fp = 0;
            break;
        }
        s5 = 0;
        p = func_002625B8(list);
        n = func_002625E4(list);
        s2 = 0;
        for (i = 0; i < n; i++) {
            e = &p[i];
            f = (f32)e->hu0;
            if (lo <= f && f < hi) {
                s1 = 1;
                if (e->h4 == -1) {
                    v38.x = e->f8;
                    v38.y = e->f10;
                    v38.z = e->fC;
                    func_00272908(&o->b74, &v38, &v28);
                } else {
                    if (fp && (D_800D1384[e->h2].f0 & 4)) {
                        if (s2 == 0) {
                            s2 = func_0024BFC4(o, o->b1);
                            if (s2 == 0) goto skip;
                            s5 = func_0028FD94((s32)*s2, 5);
                        }
                        s1 = *(s32 *)(e->h4 * *(s32 *)s5 + (s32)s5 + 0x74) & o->f17C;
                    }
skip:
                    if (s1) {
                        if (o->pB8) {
                            func_00270980(&m48, &o->pB8[e->h4]);
                            func_00272908(m48.m, (Vec3f *)&e->f8, &v28);
                        } else {
                            v28 = *(Vec3f *)&o->u8;
                        }
                    }
                }
                if (s1) {
                    func_00265E30(o, o, e->h2, -1, v28, e->pr);
                    D_800D06BC++;
                }
            }
        }
        if (s2) {
            func_002536F4(0, s2);
        }
    }
}
