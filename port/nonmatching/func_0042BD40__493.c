#include "o04_types.h"
#include "q03_types.h"
typedef struct { u8 pad0[0xD]; s8 fD; s8 fE; u8 pad[0x190 - 0xF]; } Q03Row;
extern Q03S53 *D_800E53C0;
extern Q03Cfg D_801462C8[];
extern u8 D_801462D5;
extern s32 D_8015402C;
extern s32 D_80154028;
extern s32 D_80146894;
extern u8 D_8011FE88[];
extern Q03Row D_80102B00[];
extern char *D_800D75A8;
extern char *D_800D75B0;
extern char *D_800D75B4;
extern char *D_800D75B8;
extern char *D_800D75BC;
void *func_00252FFC(s32 a);
void func_0040E958(void *p, s32 a);
void func_0040E9D0(void *p, s32 a);
s32 func_0040EC50(void *p);
Q03H14 *func_0040ECB0(s32 a, s32 b);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0043C458(void *p);
void func_00424D70(void);
void func_00424E30(s32 a, s32 b);
void func_0042C8AC(void);
void func_0042D2F8(void);
void func_0042D3A8(void);
void func_00425EF4(s32 a);
void func_0042CE54(void);
void func_0042D054(void);
void func_0042C1F8(void);
void func_0041B190(s32 a);
s32 func_0042B108(void);
s32 func_0042B198(void);
void func_0028D35C(void *a, s32 b, char *buf, s32 c);
char *func_002A1494(char *s);
void func_002A125C(char *dst, char *src);
void func_002A338C(void);
s32 func_0042BD40(s32 a) {
    char buf[0x40];
    Q03H14 *w;
    Q03Cfg *g;
    Q03Ent *e;
    s32 i;
    D_800E53C0 = func_00252FFC(0x330);
    D_800E53C0->unkE0 = a;
    func_0040E958((void *)a, 0);
    func_0043C3F0(D_800E53C0, 0x67, 0, 0, 0);
    func_0043C458(D_800E53C0);
    i = 0;
    D_800E53C0->unk1C = 1;
    func_0040ECB0(a, 0x234)->unk10 = 0x6E;
    func_0040ECB0(a, 0x239)->unk10 = 0x14;
    func_0040ECB0(a, 0x236)->unk10 = 0x14;
    func_00424D70();
    for (; i < 8; i++) {
        D_800E53C0->unk110[i].a = -1;
        D_800E53C0->unk110[i].b = -1;
    }
    D_800E53C0->unk32C = -1;
    func_0042C8AC();
    g = D_801462C8;
    switch (g->unkD) {
    case 0:
        func_00424E30(D_800E53C0->unkF0[0], D_8015402C);
        func_0042D2F8();
        D_800E53C0->unk324 = 0;
        break;
    case 2:
        if (g->unk680 == 1) {
            i = 0;
            D_800E53C0->unk324 = 0;
            func_0042D3A8();
            for (e = &g->ent[0]; i < 4; i++, e++) {
                if (e->f78 == 1 && e->f91 == 0) {
                    func_00425EF4(i);
                }
            }
        } else {
            D_800E53C0->unk324 = 1;
        }
        break;
    }
    if (D_801462D5 == 0) {
        func_0042C1F8();
    } else if (D_801462D5 == 2) {
        if (D_800E53C0->unk324 == 1) {
            D_800E53C0->unkE8 = 0;
            D_800E53C0->unkEC = 0;
            func_0042CE54();
            w = func_0040ECB0(a, 0x266);
            func_0040E958(w, 1);
            w->unk10 = 0x73;
            *(char **)((u8 *)w + 0x38) = D_800D75A8;
            func_0040E958(func_0040ECB0(a, 0x267), 0);
        } else if (D_800E53C0->unk32C == -1) {
            func_0042C1F8();
        } else {
            D_800E53C0->unkE8 = 0;
            D_800E53C0->unkEC = 0;
            func_0042CE54();
            func_0040E958(func_0040ECB0(a, 0x267), 0);
            func_0042D054();
        }
    }
    func_0041B190(0x237);
    func_0041B190(0x238);
    func_0041B190(0x23C);
    func_0040E9D0(func_0040ECB0(a, 0x238), 1);
    i = 0;
    do {
        if (D_80102B00[i].fD >= 0 && D_80102B00[i].fE == 0) {
            func_0040E9D0(func_0040ECB0(a, 0x238), 0);
            break;
        }
        i++;
    } while (i < 4);
    if (func_0040EC50(func_0040ECB0(a, 0x238)) == 0) {
        if (func_0042B108() == 1) {
            if (func_0042B198() == 0) {
                func_0040E9D0(func_0040ECB0(a, 0x238), 1);
            }
        }
    }
    w = func_0040ECB0(D_800E53C0->unkE0, 0x23A);
    if (D_80154028 == 0) {
        *(char **)((u8 *)w + 0x38) = D_800D75B0;
    } else {
        *(char **)((u8 *)w + 0x38) = D_800D75B4;
    }
    w = func_0040ECB0(D_800E53C0->unkE0, 0x23B);
    switch (D_80154028) {
    case 3:
        *(char **)((u8 *)w + 0x38) = D_800D75B0;
        break;
    case 0:
        *(char **)((u8 *)w + 0x38) = D_800D75BC;
        break;
    case 1:
    default:
        *(char **)((u8 *)w + 0x38) = D_800D75B8;
        break;
    }
    w = func_0040ECB0(a, 0x235);
    func_0028D35C(D_8011FE88, D_8015402C, buf, 0x3F);
    func_002A125C(D_800E53C0->unk2E0, func_002A1494(buf));
    *(char **)((u8 *)w + 0x38) = D_800E53C0->unk2E0;
    D_800E53C0->unkE4 = func_0040ECB0(a, 0x23D);
    D_800E53C0->unk328 = 1;
    D_80146894 = 1;
    D_800E53C0->unk320 = 0;
    func_002A338C();
    return 0;
}
