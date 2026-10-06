#include "b05_types.h"

typedef struct B05P6 {
    u8 pad0[0x5D0];
    /* 0x5D0 */ s32 mode;
    u8 pad5D4[0x8];
    /* 0x5DC */ void* handle;
    u8 pad5E0[0xCC];
    /* 0x6AC */ u32 flags;
    u8 pad6B0[0x58];
    /* 0x708 */ f32 f708;
    u8 pad70C[0xC];
    /* 0x718 */ f32 f718;
    u8 pad71C[0x4];
    /* 0x720 */ f32 f720;
    /* 0x724 */ f32 f724;
    /* 0x728 */ f32 f728;
    /* 0x72C */ f32 f72C;
    /* 0x730 */ f32 f730;
    /* 0x734 */ f32 f734;
    /* 0x738 */ f32 f738;
    /* 0x73C */ f32 f73C;
    /* 0x740 */ f32 f740;
    /* 0x744 */ f32 f744;
    u8 pad748[0x38];
    /* 0x780 */ f32 f780;
    u8 pad784[0x68];
    /* 0x7EC */ f32 f7EC;
} B05P6;

typedef struct B05S6 {
    u8 pad0[0x8];
    /* 0x008 */ f32 x;
    /* 0x00C */ f32 y;
    /* 0x010 */ f32 z;
    /* 0x014 */ s32 w14;
    u8 pad18[0x44];
    /* 0x05C */ s32 q0;
    /* 0x060 */ s32 q1;
    /* 0x064 */ s32 q2;
    /* 0x068 */ s32 q3;
    /* 0x06C */ f32 ang;
} B05S6;

typedef struct B05Q4 { s32 w[4]; } B05Q4;

extern f32 D_800C7894;
extern f32 D_800C7898;
extern f32 D_800C789C;
extern f32 D_800C78A0;
extern f32 D_800C78A4;
extern f32 D_800C78A8;
extern f32 D_800C78AC;
extern f32 D_800C78B0;
extern f32 D_800CF1E4;
extern f32 D_800CF1E8;

f32 sinf(f32);
f32 cosf(f32);
void func_0021D750(B05P6 *);
void func_00234FDC(void *);
void func_00238F14(void *, s32, f32, f32, f32, f32, f32, f32, f32, f32, B05Q4, s32, f32, f32);

void func_00220A5C(B05P6 *p, B05S6 *s) {
    void *h;
    f32 a;
    f32 x;
    f32 v;

    h = p->handle;
    if (h != NULL) {
        if (p->mode == 1) {
            func_00238F14(h, 0, s->ang, p->f724 + p->f730 - p->f708,
                          p->f728 + p->f734, p->f72C + p->f738, s->x + p->f73C,
                          s->y, s->z + p->f744,
                          (p->f740 + p->f780 - p->f718 - p->f720 < D_800C7894) ? D_800C7894 : p->f740 + p->f780 - p->f718 - p->f720,
                          *(B05Q4 *)&s->q0, s->w14, p->f7EC, D_800C7898);
        } else if (p->mode == 2) {
            if (p->flags & 0x200) {
                D_800CF1E4 += D_800C789C;
            } else if (p->flags & 0x100) {
                D_800CF1E4 -= D_800C78A0;
            } else if (p->flags & 0x800) {
                D_800CF1E8 -= D_800C78A4;
            } else if (p->flags & 0x400) {
                D_800CF1E8 += D_800C78A8;
            }
            a = s->ang + D_800CF1E4;
            x = s->x + D_800CF1E8 * sinf(a);
            func_00238F14(h, 1, a, 0.0f, 0.0f, 0.0f, x,
                          s->y + D_800C78AC, s->z + D_800CF1E8 * cosf(a), 0.0f,
                          *(B05Q4 *)&s->q0, s->w14, 0.0f, D_800C78B0);
        }
        func_00234FDC(h);
    }
    func_0021D750(p);
}
