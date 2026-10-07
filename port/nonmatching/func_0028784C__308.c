#include "b19_types.h"
extern s32 D_8011FF08;
s32 func_0028FD94(s32, s32);
void func_0028FDD8(s32, s32);
void func_00278C80(void *);
typedef struct { u8 pad0[0xF]; u8 bF; u8 pad10[3]; u8 b13; } B19It2;
inline s32 tbl_test(s32 idx) {
    s32 t = func_0028FD94(D_8011FF08, 1);
    func_0028FD94(t, 0);
    return ((u8 *)func_0028FD94(t, 1))[idx];
}
void func_0028784C(u8 *owner, B19It2 *it) {
    s32 bit = it->b13;
    s32 key = *(s32 *)(owner + 0x1B40C);
    s32 n, m;
    u8 *bits;
    n = func_0028FD94(func_0028FD94(func_0028FD94(*(s32 *)(owner + 0x80), 0), key), 2);
    func_0028FD94(n, 0);
    func_0028FDD8(n, 1);
    bits = (u8 *)func_0028FD94(n, 1);
    m = 1 << (bit & 7);
    if ((bits[bit / 8] & m) && (it->bF == 0 || tbl_test(it->bF) == 0)) {
        func_00278C80(it);
    }
}
