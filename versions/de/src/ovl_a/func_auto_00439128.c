typedef int s32;
typedef struct { s32 f0; unsigned char pad[0x10]; s32 f14; } VS;
extern VS *D_auto_800E1850;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_auto_0041A430(s32 a, s32 b);

s32 func_auto_00439128(void) {
    VS *p;
    func_0029A73C();
    if (func_0029AA08() == 0x71) {
        p = D_auto_800E1850;
        p->f14 = -1;
        func_auto_0041A430(p->f0, 2);
    }
    return 0;
}
