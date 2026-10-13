#include "o05_types.h"

typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05Lobby *D_800E54A4;
extern void *D_800D7784;
extern void *D_800D727C;
s32 func_0040458C(s32 k, s32 i, s32 *a, char *name, u8 *b, s32 *c, s32 *d, s32 *e);
s32 func_004057BC(char *p, s32 n);
void func_002A125C(char *dst, void *src);
void func_002A1C08(char *dst, const char *fmt, ...);
O05Wd *func_0040ECB0(void *w, s32 id);
s32 func_00405160(s32 k, s32 *out);
s32 func_00435600(void);
s32 func_004057EC(s32 a);
void func_00432488(s32 k);
void func_0043442C(s32 k, s32 a);

#define ITEM(k, i) ((char *)&D_800E54A4->plr[k].items[i])

void func_auto_00433EA0(s32 k) {
    s32 found = 0;
    s32 i = 0;
    char name[24];
    u8 b38[8];
    s32 L40[2];
    s32 L48[2];
    s32 L50, L54;
    O05Wd *w;
    s32 r;
    s32 ok;

    for (i = 0; i < 16 && found == 0; i++) {
        r = func_0040458C(k, i, &L50, name, b38, &L54, L40, L48);
        if (r == 0 && (ok = L50) == 1) {
            if (func_004057BC(name, 16) == ok) {
                func_002A125C(name, D_800D7784);
            }
            func_002A125C(ITEM(k, i) + 0x28, name);
            func_002A1C08(ITEM(k, i) + 0x3C, "%d", L54);
            if (b38[0] != 0) {
                func_002A1C08(ITEM(k, i), "%d.%s.%s", i + 1, ITEM(k, i) + 0x28, b38);
                continue;
            }
        } else {
            if (r != 0) {
                found = 1;
            }
            func_002A125C(ITEM(k, i) + 0x28, D_800D727C);
            func_002A1C08(ITEM(k, i) + 0x3C, "%d", 0);
        }
        func_002A1C08(ITEM(k, i), "%d.%s", i + 1, ITEM(k, i) + 0x28);
    }
    if (found == 0) {
        w = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2ED);
        if (func_00405160(k, &L54) == 0) {
            func_002A1C08((char *)&D_800E54A4->plr[k] + 0xACC, "%d", L54);
            w->f38 = (char *)&D_800E54A4->plr[k] + 0xACC;
            w = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2EE);
            L54 = func_00435600();
            func_002A1C08((char *)&D_800E54A4->plr[k] + 0xAC2, "%d", func_004057EC(L54));
            w->f38 = (char *)&D_800E54A4->plr[k] + 0xAC2;
        } else {
            found = 1;
        }
    }
    if (found == 1) {
        D_800E54A4->plr[k].state = found;
        func_00432488(k);
    } else {
        D_800E54A4->plr[k].scroll = -1;
        i = k;
        D_800E54A4->plr[k].cur = 0;
        D_800E54A4->plr[k].wd[0] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2EA);
        D_800E54A4->plr[i].wd[1] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2E9);
        D_800E54A4->plr[k].wd[2] = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2EB);
        func_0043442C(k, 1);
    }
}
