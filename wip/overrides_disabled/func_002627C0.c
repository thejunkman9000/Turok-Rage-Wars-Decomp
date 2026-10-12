#include "m04_types.h"

extern u8 D_800C9350[];
extern u8 D_800C9364[];
extern s32 D_800D29B4;
extern s32 D_800D2B40;
extern u8 D_8011FE88[];
extern s32 D_8013B290;
f32 Trunc16ToF32(u16 x);

typedef struct M04Spawn {
    u8 pad0[0x5F00];
    u8 *list0;
    u8 *pad5F04[4];
    u8 *list1;
    u32 cnt5F14;
    u8 pad5F18[0xC];
    u32 cnt5F24;
} M04Spawn;

typedef struct M04SpInfo {
    u8 pad0[0x1C];
    u16 w1C;
    u16 w1E;
} M04SpInfo;

typedef struct M04SpObj {
    u8 pad0[0x2F0];
    s32 *cnt;
} M04SpObj;

void func_00246690(void *obj, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g, M04Vec3 p, s32 h, M04Vec3 r, M04Vec3 q, s32 i);
void func_0024B2C0(void *o);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
void func_002536F4(s32 a, void *p);
void func_00255C58(void *l, void *n);
void func_00255E78(void *l, void *n);
void func_0027200C(M04Vec3 *d, M04Vec3 *s, f32 f);
s32 func_0028B1F8(void *w, u32);
s32 func_0028B238(void *w, s32 a);
s32 func_0028CF48(void *w, u16 a);
void *func_0028FD94(s32 n, s32 i);
s32 func_0028FE08(s32 a, s32 b, s32 c);
s32 func_0028FE1C(s32 a, s32 b, s32 c, s32 *out);

void *func_002627C0(M04Spawn *w, s32 id, s32 a2, M04Vec3 p, f32 g, M04Vec3 q, M04Vec3 r, s32 *cnt) {
    s32 sp90;
    M04Vec3 lp;
    M04Vec3 lq;
    M04Vec3 lr;
    s32 m;
    s32 k;
    s32 *h1;
    s32 *h2;
    M04SpInfo *info;
    s32 s7;
    M04SpObj *obj;
    void *res;
    void *ret;
    res = 0;
    m = func_0028B1F8(D_8011FE88, id);   /* port: the MIPS code passed this function's own a1 (id) on; the decomp dropped it */
    ret = 0;
    if (m != -1) {
        k = func_0028FE08(*(s32 *)(D_8011FE88 + 0x54), *(s32 *)(D_8011FE88 + 0x24), m);
        h1 = func_002518DC(0, k, k, 0x18, 0, 0, 0, D_800C9350, 1);
        if (h1 != 0) {
            k = func_0028FE1C(*h1, k, 0, &sp90);
            h2 = func_002518DC(0, k, k, sp90, 0, 0, 0, D_800C9364, 1);
            if (h2 != 0) {
                info = (M04SpInfo *)func_0028FD94(*h2, 0);
                s7 = func_0028CF48(D_8011FE88, info->w1C);
                func_0027200C(&r, &r, Trunc16ToF32(info->w1E));
                lp = p;
                lq = q;
                lr = r;
                if (D_800D29B4 != 0 && s7 != 0) {
                    if ((u32)(id + 1) < 2U) {
                        id = func_0028B238(D_8011FE88, m);
                    }
                    if (D_8013B290 != 0 || (obj = 0, w->cnt5F24 < 3U)) {
                        obj = (M04SpObj *)w->list0;
                        if (obj != 0) {
                            func_00255E78(&w->list0, obj);
                            func_00255C58(&w->list1, obj);
                            obj->cnt = cnt;
                            if (cnt != 0) {
                                *cnt += 1;
                            }
                        }
                    }
                    if (obj == 0) {
                        res = 0;
                    } else {
                        res = obj;
                        func_00246690(obj, m, id, D_800D2B40, s7, -1, a2, g, lp, 0x80000, lr, lq, 0);
                        func_0024B2C0(res);
                    }
                }
                func_002536F4(0, h2);
            }
            func_002536F4(0, h1);
        }
        ret = res;
    }
    return ret;
}
