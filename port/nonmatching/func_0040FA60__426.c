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
    s32 buf0;            /* 0x288 */
    s32 buf1;            /* 0x28C */
} S_G;
extern S_G D_801539B0;
extern S_ent *D_80153C30;
extern s32 *D_80153C3C;
void func_00254784(s32 p);
s32 func_00252FFC(s32 n);
void func_002A1F60(s32 a, s32 b);
void func_002A1ED4(s32 a, s32 b, s32 c, s32 d);
void func_002A1EB0(s32 a);
void func_0040FA60(s32 idx) {
    s32 cnt, size, end, i, j, p, flag;
    cnt = D_80153C30[idx].cnt;
    flag = 0;
    if (D_801539B0.buf0) func_00254784(D_801539B0.buf0);
    D_801539B0.buf0 = 0;
    if (D_801539B0.buf1) func_00254784(D_801539B0.buf1);
    D_801539B0.buf1 = 0;
    if (idx < D_801539B0.n - 1) {
        end = D_80153C30[idx + 1].off;
    } else {
        end = D_801539B0.f234;
    }
    size = end - D_80153C30[idx].off;
    D_801539B0.buf0 = func_00252FFC(size);
    func_002A1F60(D_801539B0.h, D_80153C30[idx].off + D_801539B0.f230);
    func_002A1ED4(D_801539B0.buf0, size, 1, D_801539B0.h);
    if (flag) {
        func_002A1EB0(D_801539B0.h);
        D_801539B0.h = 0;
    }
    D_801539B0.buf1 = func_00252FFC(cnt << 2);
    D_80153C3C[0] = D_801539B0.buf0;
    j = 1;
    for (p = D_801539B0.buf0 + 1; (u32)p < D_801539B0.buf0 + size && j < cnt; p++) {
        if (*(u8 *)p == 0) {
            D_80153C3C[j++] = p + 1;
        }
    }
}
