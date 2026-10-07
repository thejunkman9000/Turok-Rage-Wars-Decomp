#include "b11_types.h"

extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
extern u8 *D_80145044;
extern s32 D_80145048;
extern u8 D_800CFB04[];
extern B11Desc *D_800D0680[];

void func_0024B2C0(Obj *a) {
    if (a->def == 0) { u32 *w = (u32 *)a; int k; fprintf(__acrt_iob_func(2), "24B2C0: obj %p def NULL, words:", a); for (k = 0; k < 24; k++) fprintf(__acrt_iob_func(2), " %08x", w[k]); fprintf(__acrt_iob_func(2), "\n"); { extern void port_bt(void); port_bt(); } return; }
    u32 t = a->def->type;
    B11Desc *d;
    u8 *p;
    s32 i;
    if (t >= 15) {
        d = 0;
    } else {
        if (t == 11) {
            for (i = 0; i < D_80145048; i++) {
                p = D_80145044 + i * 0x16E8;
                if (p == (u8 *)a) {
                    d = 0;
                    goto have;
                }
                if (p + 0x2E8 == (u8 *)a) {
                    d = (B11Desc *)D_800CFB04;
                    goto have;
                }
            }
        }
        d = D_800D0680[t];
    }
have:
    if (d != 0 && d->cb != 0) {
        d->cb(a, a->unk170);
    }
    if (a->flags & 0x8000000) {
        a->unk23B++;
    }
}
