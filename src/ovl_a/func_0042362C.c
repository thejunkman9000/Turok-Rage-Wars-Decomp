#include "o03_types.h"
extern O3Words *D_800E4514;
extern O3Cfg D_801462C8[];
extern char *D_800D749C[];
extern char *D_800D74A4[];
extern char *D_800D74A8[];
extern char *D_800D74B4[];
extern char *D_800D74B8[];
extern char *D_800D74BC[];
void *func_00252FFC(s32 size);
s32 func_00265370();
s32 func_0041A600(s32 a, s32 b, s32 c);
s32 func_0041AC40(s32 a, s32 b);
void func_0041A76C(s32 o, s32 v);
void func_0041AD90(s32 o, s32 i);
void func_0041ADB4(s32 o, char *s);
void func_0041B190(s32 id);
void func_002A338C();
s32 func_0042362C(void) {
    s32 t;
    D_800E4514 = func_00252FFC(0x10);
    func_0041B190(0x1BD);
    func_0041B190(0x1C2);
    D_800E4514->w[1] = func_0041AC40(0x1BB, 0x1BC);
    func_0041ADB4(D_800E4514->w[1], D_800D749C[0]);
    func_0041ADB4(D_800E4514->w[1], D_800D74A4[0]);
    func_0041ADB4(D_800E4514->w[1], D_800D74A8[0]);
    func_0041AD90(D_800E4514->w[1], D_801462C8->f1B);
    D_800E4514->w[2] = func_0041AC40(0x1BE, 0x1BF);
    func_0041ADB4(D_800E4514->w[2], D_800D74B4[0]);
    if (func_00265370() != 0x400000) {
        func_0041ADB4(D_800E4514->w[2], D_800D74B8[0]);
        func_0041ADB4(D_800E4514->w[2], D_800D74BC[0]);
    }
    func_0041AD90(D_800E4514->w[2], D_801462C8->f580);
    t = func_0041A600(0x1C0, 0x1C1, 0x80);
    D_800E4514->w[0] = t;
    func_0041A76C(t, D_801462C8->f10);
    func_0041B190(0x1C3);
    func_0041B190(0x1C4);
    D_800E4514->w[3] = 0;
    func_002A338C();
    return 0;
}
