#include "o04_types.h"
#include "q03_types.h"
typedef struct { s32 f0; u8 pad4[0x6C]; } Q03Row70;
extern Q03S53 *D_800E53C0;
extern Q03Slot D_800E5322[];
extern Q03Ent D_80146398[];
extern Q03Row70 D_800E3A58[];
extern s32 *D_800E39B4[];
extern s32 D_800E4200[];
extern s32 D_80103140[];
extern s32 D_80102AE0[];
extern u8 D_80102B00[];
extern s32 D_80154028[];
extern char D_800E1B20[];
extern char D_800E1B24[];
Q03Wid *func_0040ECB0(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void func_0042CE54(void);
s32 func_0041F1B0(s32 a);
char *func_002A1494(char *s);
void func_002A125C(char *dst, char *src);
void func_002A1C08(char *buf, char *fmt, s32 a);
s32 func_00424FC8(s32 a);
void func_0042D4E4(s32 a, s32 b, s32 c);
void func_0042C1F8(void) {
    s32 i;
    s32 sel;
    s32 cnt;
    s32 v;
    Q03Wid *w;
    Q03Wid *p;
    Q03Ent *e;
    func_0042CE54();
    for (i = 0; i < 4; i++) {
        if (!(i < D_800E53C0->unkEC)) {
            break;
        }
        sel = D_800E53C0->unkF0[D_800E53C0->unkE8 + i];
        e = &D_80146398[sel];
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id0);
        func_0040E958(w, 1);
        w->unk10 = 0x96;
        p = w;
        p->unk2C = D_800E3A58[func_0041F1B0(e->f80)].f0;
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id4);
        func_0040E958(w, 1);
        w->unk10 = 0x19;
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id8);
        w->unk10 = 0xAF;
        func_0040E958(w, 1);
        if (e->f91 == 0) {
            w->unk38 = &D_80102B00[sel * 0x190];
        } else {
            func_002A125C(e->name, func_002A1494(e->name));
            w->unk38 = e->name;
        }
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].idC);
        w->unk10 = 0x73;
        func_0040E958(w, 1);
        if (e->f91 == 0) {
            w->unk38 = (void *)func_00424FC8(sel);
        } else {
            w->unk38 = (void *)*D_800E39B4[e->f93];
        }
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id10);
        w->unk10 = 0xAF;
        func_0040E958(w, 1);
        func_002A1C08(D_800E53C0->strA[i], D_800E1B20, e->f4);
        w->unk38 = D_800E53C0->strA[i];
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id14);
        w->unk10 = 0xAF;
        func_0040E958(w, 1);
        func_002A1C08(D_800E53C0->strB[i], D_800E1B20, e->f2 + e->f0);
        w->unk38 = D_800E53C0->strB[i];
        if (D_80154028[0] == 0) {
            func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id18), 0);
            func_0042D4E4(sel, i, 0x269);
        } else {
            w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id18);
            w->unk10 = 0xAF;
            func_0040E958(w, 1);
            cnt = D_80103140[sel];
            v = 0;
            if (cnt > 0) {
                v = D_80102AE0[sel] * 100 / cnt;
            }
            func_002A1C08(D_800E53C0->strC[i], D_800E1B24, v);
            w->unk38 = D_800E53C0->strC[i];
        }
        if (D_80154028[0] == 3) {
            func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id1C), 0);
            func_0042D4E4(sel, i, 0x26E);
        } else {
            w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id1C);
            w->unk10 = 0xAF;
            func_0040E958(w, 1);
            p = w;
            switch (D_80154028[0]) {
            case 0:
                func_002A1C08(D_800E53C0->strD[i], D_800E1B20, e->f8);
                break;
            case 1:
                func_002A1C08(D_800E53C0->strD[i], D_800E1B20, e->f6);
                break;
            default:
                func_002A1C08(D_800E53C0->strD[i], D_800E1B20, 0);
                break;
            }
            p->unk38 = D_800E53C0->strD[i];
        }
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id20);
        func_0040E958(w, 0);
        w->unk10 = 0x96;
        w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id24);
        func_0040E958(w, 0);
        w->unk10 = 0x96;
        if (e->f91 == 0) {
            if (D_800E53C0->unk110[sel].a != -1) {
                w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id20);
                func_0040E958(w, 1);
                w->unk2C = D_800E4200[D_800E53C0->unk110[sel].a];
            }
            if (D_800E53C0->unk110[sel].b != -1) {
                w = func_0040ECB0(D_800E53C0->unkE0, D_800E5322[i].id24);
                func_0040E958(w, 1);
                w->unk2C = D_800E4200[D_800E53C0->unk110[sel].b];
            }
        }
    }
}
