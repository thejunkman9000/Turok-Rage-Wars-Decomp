#include "r04_types.h"

u32 *func_0028FD94(void *list, s32 i);
void func_002433CC(R4Cx *cx, R4Vt **tri);

#define TRI(P) \
    tri[0] = (R4Vt *)((u8 *)vt + ((*(u32 *)(P) & 0xFE0000) >> 12)); \
    tri[1] = (R4Vt *)((u8 *)vt + ((*(u32 *)(P) & 0xFE00) >> 4)); \
    tri[2] = (R4Vt *)((u8 *)vt + ((((u8 *)(P))[3] >> 1) << 5)); \
    if (!(tri[0]->flags & tri[1]->flags & tri[2]->flags)) { \
        func_002433CC(cx, tri); \
        if (fp) { \
            t = tri[0]; \
            tri[0] = tri[2]; \
            tri[2] = t; \
            func_002433CC(cx, tri); \
        } \
    }

void func_00242FD8(R4Cx *cx, void *list) {
    R4Vt vt[32];
    R4Vt *tri[3];
    f32 s[3];
    R4Vt *t;
    R4Obj *obj;
    u32 *w;
    u32 *p1;
    u32 *p3;
    R4Vt *vp;
    s16 *sp;
    s32 fp;
    s32 n;
    s32 m;
    u8 op;
    u32 bx;
    u32 bits;

    w = func_0028FD94(list, 0);
    obj = cx->obj;
    cx->flags = *w;
    fp = *w & 4;
    m = cx->mode;
    if (m != 1) {
        if (m <= 0) goto nofp;
        if (m >= 9) goto nofp;
        if (m < 7) goto nofp;
    }
    fp = 1;
nofp:
    p1 = func_0028FD94(list, 1);
    p3 = p1 + 1;
    do {
        op = *(u8 *)p1;
        switch (op) {
        default:
            break;
        case 6:
            TRI(p3);
        case 5:
            TRI(p1);
            break;
        case 1:
            sp = (s16 *)((*p3 & 0xFFFFFF) + cx->segbase);
            n = (*p1 >> 12) & 0xFF;
            vp = (R4Vt *)((u8 *)vt + ((((*p1 & 0xFE) >> 1) - n) << 5));
            do {
                vp->src = sp;
                s[0] = sp[0];
                s[1] = sp[1];
                s[2] = sp[2];
                vp->x = cx->m[0][0] * s[0] + cx->m[1][0] * s[1] + cx->m[2][0] * s[2] + cx->m[3][0];
                bits = *(u32 *)&vp->x;
                vp->flags = ((u32)(obj->w18 - (bits & 0x7FFFFFFF)) >> 31) << (bits >> 31);
                vp->y = cx->m[0][1] * s[0] + cx->m[1][1] * s[1] + cx->m[2][1] * s[2] + cx->m[3][1];
                bits = *(u32 *)&vp->y;
                vp->flags = vp->flags | (((u32)(obj->w18 - (bits & 0x7FFFFFFF)) >> 31) << ((bits >> 31) + 2));
                vp->z = cx->m[0][2] * s[0] + cx->m[1][2] * s[1] + cx->m[2][2] * s[2] + cx->m[3][2];
                bits = *(u32 *)&vp->z;
                vp->flags = vp->flags | ((~(bits >> 31) & ((u32)(obj->w18 - bits) >> 31)) * 16);
                vp->flags = vp->flags | (((bits >> 31) & ((u32)(*(u32 *)&cx->lim2 - (bits & 0x7FFFFFFF)) >> 31)) << 5);
                sp += 8;
                n--;
                vp++;
            } while (n != 0);
            break;
        }
        p3 += 2;
        p1 += 2;
    } while (op != 0xDF);
}
