#include "o04_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_0029AA08(void);

extern void *D_800E4EF0;
void func_0029A73C(void);
s32 func_0043C4E8(void *p);
void func_004296A4(void);
void func_0042EB68(s32 a);
void func_0029A8A8(void);
s32 func_00429AD8(void) {
    fprintf(__acrt_iob_func(2), "func_00429AD8: page=%p unk18=%d focus=%d\n", (void *)D_800E4EF0, D_800E4EF0 ? (int)func_0043C4E8(D_800E4EF0) : -99, (int)func_0029AA08());
    func_0029A73C();
    if (func_0043C4E8(D_800E4EF0) == 1) {
        return 0;
    }
    func_004296A4();
    func_0042EB68(-1);
    func_0029A8A8();
    return 0;
}
