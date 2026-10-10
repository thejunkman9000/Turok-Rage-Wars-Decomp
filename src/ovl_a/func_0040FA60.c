#include "o02_types.h"
typedef struct { s32 off; s32 cnt; } S_ent;
typedef struct {
    s32 h;               /* 0x000 */
    u8 pad4[0x230 - 4];
    s32 f230;
    s32 f234;
    u8 pad238[0x27C - 0x238];
    s16 n;               /* 0x27C */
    u8 pad27E[2];
    S_ent *tbl;          /* 0x280 */
    u8 pad284[4];
    u8 *buf0;            /* 0x288 */
    u8 **buf1;           /* 0x28C */
} S_G;
extern S_G D_801539B0;
extern S_ent *D_80153C30;
void func_00254784(void *p);
u8 *func_00252FFC(s32 n);
void func_002A1F60(s32 a, s32 b, s32 c);
void func_002A1ED4(s32 a, s32 b, s32 c, s32 d);
void func_002A1EB0(s32 a);
void func_0040FA60(s32 idx) {
    s32 cnt, size, end, j, flag;
    u8 *p;
    flag = 0;
    cnt = D_80153C30[idx].cnt;
    if (D_801539B0.buf0) func_00254784(D_801539B0.buf0);
    D_801539B0.buf0 = 0;
    if (D_801539B0.buf1) func_00254784(D_801539B0.buf1);
    D_801539B0.buf1 = 0;
    if (idx < D_801539B0.n - 1) {
        size = D_80153C30[idx + 1].off - D_80153C30[idx].off;
    } else {
        size = D_801539B0.f234 - D_80153C30[idx].off;
    }
    D_801539B0.buf0 = func_00252FFC(size);
    func_002A1F60(D_801539B0.h, D_80153C30[idx].off + D_801539B0.f230, 0);
    func_002A1ED4((s32)D_801539B0.buf0, size, 1, D_801539B0.h);
    if (flag) {
        func_002A1EB0(D_801539B0.h);
        D_801539B0.h = 0;
    }
    D_801539B0.buf1 = (u8 **)func_00252FFC(cnt << 2);
    ((u8 **)D_801539B0.buf1)[0] = D_801539B0.buf0;
    j = 1;
    for (p = D_801539B0.buf0 + 1; (u32)p < (u32)D_801539B0.buf0 + size && j < cnt; p++) {
        if (*p == 0) {
            D_801539B0.buf1[j++] = p + 1;
        }
    }
}
