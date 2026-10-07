

#include "b13_types.h"
#include "m04_types.h"

typedef struct M04Node2 {
    s32 stride;
    u32 cnt;
} M04Node2;

extern f32 D_800C8FCC;
s32 func_00257BD4(SndMgr *m, void *info, M04Vec3 *pos, s32 a3, s32 a4, s32 a5, s32 a6);
s32 func_00265570(void *a, s32 b, s16 id, s32 *lo, s32 *hi);
s32 func_00274544();
f32 func_002745D4(f32 x);
void *func_0028FD94(void *n, s32 i);

s32 func_00257DF4(SndMgr *m, s32 id, M04Vec3 pos, s32 a5, s32 a6) {
    s32 i;
    s32 cnt;
    s32 busy;
    s32 idx;
    s32 sum;
    s32 r;
    s32 lo;
    s32 hi;
    s32 ok;
    s32 w;
    s32 n;
    s32 s0;
    s32 ret;
    s32 sh;
    u16 last;
    u8 *vp;
    M04Node2 *nd;
    if (m->unk102 != -1) {
        busy = 1;
        goto chk;
    }
    cnt = 0;
    if (id < 0x100) {
        for (i = 0; i < 17; i++) {
            if (*(s32 *)((u8 *)m + i * 0xCC + 0x1E64) == id) {
                cnt++;
            }
        }
        busy = 1;
        if (cnt >= 6) {
            goto chk;
        }
    }
    busy = 0;
chk:
    if (busy != 0) {
        return -1;
    }
    if (id < 0x100) {
        last = *(u16 *)((u8 *)m + 0x132);
        sum = 0;
        if (m->unk2B54 != 0 && func_00265570(m->unk2B58, m->unk2B54, id, &lo, &hi) != 0) {
            if (lo != hi) {
                for (i = lo; i <= hi; i++) {
                    sum += m->unk2B5C[i] * 10;
                }
                r = func_00274544() % sum;
                sum = 0;
                for (i = lo; i < hi; i++) {
                    sum += m->unk2B5C[i] * 10;
                    if (sum >= r) {
                        break;
                    }
                }
                idx = i;
                if ((s16)last != 0 && i == m->unk130) {
                    if (i != hi) {
                        i = i + 1;
                    } else {
                        i = i - 1;
                    }
                    idx = i;
                }
            } else {
                idx = lo;
            }
        } else {
            idx = -1;
        }
        m->unk2B94 = (s32)func_002745D4(D_800C8FCC);
    } else {
        sum = 0;
        if (m->unk2B54 != 0) {
            idx = -1;
            if (func_00265570(m->unk2B58, m->unk2B54, id, &lo, &hi) != 0) {
                if (lo != hi) {
                    for (i = lo; i <= hi; i++) {
                        sum += m->unk2B5C[i] * 10;
                    }
                    r = func_00274544() % sum;
                    sum = 0;
                    idx = lo;
                    for (i = lo; i < hi; i++) {
                        sum += m->unk2B5C[i] * 10;
                        idx = i;
                        if (sum >= r) {
                            break;
                        }
                    }
                } else {
                    idx = lo;
                }
            }
        } else {
            idx = -1;
        }
    }
    if (idx == -1) {
        return -1;
    }
    sh = (s16)idx;
    m->unk2B88 = func_0028FD94(func_0028FD94(m->tree2B4C, sh), 0);
    m->unk2B8C = id;
    m->unk2B90 = a6;
    nd = (M04Node2 *)func_0028FD94(func_0028FD94(m->tree2B4C, sh), 1);
    cnt = nd->cnt;
    ret = -1;
    if (cnt != 0) {
        SndMgr_Lock(m);
        ret = m->unk10C + 1;
        m->unk10C = ret;
        SndMgr_Unlock(m);
        if (id < 0x100) {
            m->unk130 = idx;
        }
    }
    s0 = 0;
    if (cnt != 0) {
        do {
            func_00257BD4(m, (u8 *)nd + s0 * nd->stride + 8, &pos, idx, ret, 0, a5);
            s0++;
        } while ((u32)s0 < (u32)cnt);
    }
    m->unk2B90 = -1;
    return ret;
}



