#include "o04_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_0029AA08(void);

extern O04S4EF0 *D_800E4EF0;
void func_0029A73C(void);
s32 func_0043C4E8(void *p);
s32 func_0029AA08(void);
void func_004296A4(void);
void func_00429834(s32 a);
void func_0041E668(void);
void func_0042EB68(s32 a);
void func_0029A8A8(void);
void func_002A338C(void);
s32 func_002A2B18(s32 a);
s32 func_004299D8(void) {
    fprintf(__acrt_iob_func(2), "func_004299D8: page=%p unk18=%d focus=%d\n", (void *)D_800E4EF0, D_800E4EF0 ? (int)func_0043C4E8(D_800E4EF0) : -99, (int)func_0029AA08());
    func_0029A73C();
    if (func_0043C4E8(D_800E4EF0) == 1) {
        return 0;
    }
    switch (func_0029AA08()) {
    case 0x36B:
        func_004296A4();
        func_0042EB68(-1);
        func_0029A8A8();
        break;
    case 0x369:
        if (func_002A2B18(D_800E4EF0->unk34) > 0) {
            func_004296A4();
            func_00429834(0);
            func_0042EB68(0x17);
            func_0029A8A8();
        }
        break;
    case 0x36A:
        func_004296A4();
        func_00429834(0);
        func_0041E668();
        func_0042EB68(0x19);
        func_0029A8A8();
        func_002A338C();
        break;
    }
    return 0;
}
