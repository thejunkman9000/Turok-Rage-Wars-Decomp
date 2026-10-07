#include "b19a_types.h"
extern f32 D_800CA2C4;
extern s32 D_8014694C;
extern s32 D_800D2980;
extern s32 D_800D15D0;
extern s32 D_80146910;
extern u8 D_801462E5;
extern B19aGF D_801468A0[];
extern u8 D_8010A248[];
extern u8 D_8013B7B8[];
extern u8 D_8013BA80[];
extern u8 D_8011F260[];
extern u8 D_8011F080[];
extern u8 D_8011FE88[];
extern u8 D_80145040[];
extern B19aActor *D_80145060;
extern u8 D_800CA1F4[];
extern u8 D_800CA200[];
extern u8 D_800CA20C[];
extern u8 D_800CA218[];
extern u8 D_800CA224[];
extern u8 D_800CA238[];
extern u8 D_800CA244[];
extern u8 D_800CA250[];
extern u8 D_800CA258[];
extern u8 D_800CA264[];
extern u8 D_800CA270[];
extern u8 D_800CA280[];
extern u8 D_800CA290[];
extern u8 D_800CA2A4[];
extern u8 D_800CA2B0[];
extern void *D_800D7190;
extern void *D_800F7CD0[];
extern void *D_800F7CF8[];
extern void *D_800F7CFC;
extern void *D_800F7D00;
extern void *D_800F7D04;
extern void *D_800F7D08;
extern void *D_800F7D0C;
void D_44D024();
void D_44CD58();
void D_44E6A4();
void D_44D408();
void func_44E3E4();
s32 func_00245774();
void func_0028D8E8();
void func_4037E8(s32);
void func_0028A924();
void func_0028D864(B19aWorld *);
void func_002551C8(void *);
void func_0028DA50(B19aWorld *);
void func_002538A8(s32);
void func_44CBE0(B19aWorld *);
void func_0025470C(s32);
void func_0028D628(B19aWorld *);
void func_44C050(void *, s32);
void func_44E7C0(void *);
void func_44BA40(void *);
void func_44EBB0(void *);
void func_0023EDF0();
void func_44BD30(void *);
void func_0025C8F8(void *, void *, s32);
void func_44ED24(void *);
B19aActor *func_0022A5E4(void *, s32);
void func_00208000(void *);
void func_002AB720(void *, void *, void *);
void func_002AB750(void *, void *, void *);
void func_0028D35C(B19aWorld *, s32, void *, s32);
s32 *func_002533DC(s32, s32, s32, void *);
void func_44BFD0(void *, s32, s32);
s32 func_0028FE08(s32 *, s32, s32);
s32 func_00254224(s32, void *, s32, void *);
s32 **func_002543A8(s32, s32 *, s32, s32, void *, void (*)(), void *);
void func_002537D8(s32, s32 **);
void func_44CA54(B19aWorld *);
void func_00255C40(void *, s32, s32);
void *func_00252FFC(s32);
void func_0020CA10(void *, s32);
void func_00255CB4(void *, void *);
void func_00285130();
void func_00286920(B19aWorld *);
s32 func_0028B238(void *, s16);
s32 func_002A11E8();
void func_44E214(B19aWorld *);
void func_0024B2C0(void *);
s32 func_0020CB3C(void *, void *);
void func_44E2B8(B19aWorld *);
void func_0024BE2C(void *);
void func_00246E34(void *);
void func_0020AA40(void *);
void func_0020ABF0(void *);
void func_44AA68(void *);
void func_44B31C(void *);
void func_00236864(void *);
void func_00286A78(B19aWorld *w, s32 lvl, s32 flag) {
    s32 c1, k1, c2, k2, c3, k3, a4;
    B19aEnt2E8 *o1, *o2, *o3;
    B19aActor *a;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 *n4C;
    s32 tmp;
    s32 **h;
    s32 a3;
    B19aEnt2E8 *o;
    B19aActor *p;
    void *q;
    w->f1B2FC = D_800CA2C4;
    if (w->f1B40C != -1) func_44E3E4();
    w->f1B6AC = 0;
    if (func_00245774() == 0 && flag != 0 && w->f1B41C != 0 && D_8014694C == 0) {
        func_0028D8E8();
        x1 = w->level - 0xBC2;
        if ((u32)x1 < 0x15F) func_4037E8(x1 / 10 + 0x259);
        func_0028A924();
    }
    func_0028D864(w);
    w->state = 0;
    func_002551C8(D_8010A248);
    func_0028DA50(w);
    func_002538A8(0);
    if (w->f1B40C != -1) func_44CBE0(w);
    func_002538A8(0);
    D_800D2980 = 0;
    func_0025470C(8);
    func_0028D628(w);
    x2 = 0;
    func_44C050((u8 *)w + 0x1B08, *w->pB4);
    func_44E7C0((u8 *)w + 0x11778);
    func_44BA40((u8 *)w + 0x15388);
    func_44EBB0(D_8013BA80);
    func_0023EDF0();
    func_44BD30((u8 *)w + 0x1B320);
    func_0025C8F8(D_8011F260, D_8011F080, 0xF);
    func_44ED24(D_8013BA80 - 0x2C8);
    do {
        a = func_0022A5E4(D_80145040, x2);
        if (a != 0) {
            if (a->stats->b78 == 1 && a->stats->b91 == 1) func_00208000(a->brain);
            if (D_801468A0->f98 != 0) {
                B19aStats *st = a->stats;
                if (st->b94 != 0) {
                    if (st->b94 == 1) func_002AB720(D_8013B7B8, a, (u8 *)st + 0x84);
                    else if (st->b94 == 2) func_002AB750(D_8013B7B8, a, (u8 *)st + 0x84);
                    if (a->stats->b80 == 0xB) func_002AB720(D_8013B7B8, a, D_800D7190);
                }
            }
        }
        x2++;
    } while (x2 < 8);
    n4C = w->p4C;
    if (*n4C < lvl) {
        lvl = *n4C - 1;
        flag = 0;
    }
    w->f1B40C = lvl;
    if (flag == 0) w->f1B41C = 0;
    func_0028D35C(w, lvl, (u8 *)w + 0x1B2BC, 0x3F);
    switch (w->level) {
    case 0x123A: case 0x1BBC: case 0x1C20: case 0x1C84: case 0x1CE8: case 0x1CE9:
    case 0x1D4C: case 0x1D4D: case 0x1DB1: case 0x1DB2:
        w->f1B408 = 1;
        break;
    default:
        w->f1B408 = 0;
        break;
    }
    switch (w->level) {
    case 0x123A: case 0x1BBC: case 0x1C20: case 0x1C84: case 0x1CE8: case 0x1CE9:
    case 0x1D4C: case 0x1D4D: case 0x1DB2:
        x1 = 0xC80;
        break;
    case 0x1DB1:
        x1 = 0x4B0;
        break;
    default:
        x1 = 0x320;
        break;
    }
    if (D_801462E5 != 0) x1 += 0x200;
    func_002538A8(0);
    w->fE8 = func_002533DC(0, x1 << 6, 3, D_800CA1F4);
    func_44BFD0((u8 *)w + 0x128, *w->fE8, x1);
    tmp = func_0028FE08(w->p4C, w->f1C, lvl);
    w->fB8 = func_00254224(0, &w->p60, tmp, D_800CA200);
    w->fBC = func_002543A8(0, w->p60, 1, tmp, w, D_44D024, D_800CA20C);
    w->f6C = *w->fBC;
    w->fC0 = func_002543A8(0, w->p60, 4, tmp, w, func_00285130, D_800CA218);
    w->f68 = *w->fC0;
    w->f30 = func_0028FE08(w->p60, tmp, 5);
    w->fC4 = func_00254224(0, &w->f64, w->f30, D_800CA224);
    if (*w->p60 >= 0xD) {
        w->f40 = func_0028FE08(w->p60, tmp, 0xC);
        w->f100 = func_00254224(0, &w->p8C, w->f40, D_800CA238);
        h = func_002543A8(0, w->p8C, 0, w->f40, w, 0, D_800CA244);
        w->box = *(B19aBox6 *)*h;
        func_002537D8(0, h);
        if (w->box.w[4] != 0 || w->box.w[5] != 0) {
            w->f1B92C = 1;
        } else {
            w->f1B92C = 0;
        }
    } else {
        w->f1B92C = 0;
    }
    w->fD4 = func_002543A8(0, w->p60, 7, tmp, w, D_44CD58, D_800CA250);
    w->fEC = func_002543A8(0, w->p60, 2, tmp, w, D_44E6A4, D_800CA258);
    w->fC8 = func_002543A8(0, w->p60, 0, tmp, w, 0, D_800CA264);
    w->f1B2B0 = (B19aBrain *)*w->fC8;
    func_44CA54(w);
    D_800D15D0 = (w->f1B2B0->b10 >> 2) & 1;
    if (*w->p60 >= 9) {
        w->fF0 = func_002543A8(0, w->p60, 9, tmp, w, func_00285130, D_800CA270);
        w->f1B4DC = *w->fF0;
        w->f1B4E0 = ((s32 *)w->f1B4DC)[1];
        w->fF4 = func_002543A8(0, w->p60, 0xA, tmp, w, func_00285130, D_800CA280);
        w->f1B4E4 = *w->fF4;
        w->f1B4E8 = ((s32 *)w->f1B4E4)[1];
        func_00255C40((u8 *)w + 0x1B500, 0xC, 0x10);
        if (w->f1B4E0 > 0) {
            q = func_00252FFC(w->f1B4E0 * 0x50);
            x2 = 0;
            if (w->f1B4E0 > 0) {
                do {
                    func_0020CA10(q, x2);
                    func_00255CB4((u8 *)w + 0x1B500, q);
                    x2++;
                    q = (u8 *)q + 0x50;
                } while (x2 < w->f1B4E0);
            }
        }
    }
    if (*w->p60 >= 0xC) {
        w->fFC = func_002543A8(0, w->p60, 0xB, tmp, w, func_00285130, D_800CA290);
        w->f1B4EC = *w->fFC;
        w->f1B4F0 = ((s32 *)w->f1B4EC)[1];
    }
    w->fCC = func_002543A8(0, w->p60, 6, tmp, w, func_00285130, D_800CA2A4);
    w->f1B300 = (u8 *)*w->fCC + 8;
    w->state = 1;
    w->objs = 0;
    w->nobjs = 0;
    w->f1B304 = (*w->fCC)[1];
    w->fD0 = func_002543A8(0, w->p60, 3, tmp, w, D_44D408, D_800CA2B0);
    func_00286920(w);
    a3 = 0;
    o1 = w->objs;
    w->f1B6A4 = 0;
    for (c1 = 0; c1 < 16; c1++) w->arr1B664[c1] = 0;
    k1 = 0;
    if (w->nobjs > 0) {
        do {
            if (o1->info->type == 0xE) {
                w->arr1B664[a3] = o1;
                a3++;
            }
            if (!(a3 < 0x10)) break;
            k1++;
            o1++;
        } while (k1 < w->nobjs);
    }
    w->f1B6A4 = a3;
    D_800F7D08 = 0;
    for (c2 = 0; c2 < 4; c2++) D_800F7CF8[c2] = 0;
    k2 = 0;
    o2 = w->objs;
    if (w->nobjs > 0) {
        do {
            if (o2->info->type == 3) {
                if (func_0028B238(D_8011FE88, o2->info->f28) == 0xBD7) {
                    D_800F7D08 = o2;
                    break;
                }
            } else if (o2->info->type == 0xA) {
                switch (o2->id) {
                case 0x653: D_800F7CF8[0] = o2; break;
                case 0x654: D_800F7CFC = o2; break;
                case 0x655: D_800F7D00 = o2; break;
                case 0x656: D_800F7D04 = o2; break;
                }
            }
            k2++;
            o2++;
        } while (k2 < w->nobjs);
    }
    a3 = 0;
    D_800F7D0C = 0;
    for (c3 = 0; c3 < 10; c3++) D_800F7CD0[c3] = 0;
    k3 = 0;
    o3 = w->objs;
    if (w->nobjs > 0) {
        do {
            if (o3->info->type == 3) {
                if (o3->info->f28 == 0xBD6) D_800F7D0C = o3;
            } else if (o3->info->type == 0xA) {
                if (o3->id == 0x64E) {
                    D_800F7CD0[a3] = o3;
                    a3++;
                }
            }
            if (!(a3 < 10)) goto done;
            k3++;
            o3++;
        } while (k3 < w->nobjs);
    }
    D_80146910 = func_002A11E8() % 3;
done:
    w->state = 2;
    func_44E214(w);
    x0 = w->nobjs;
    x2 = w->f13C;
    w->state = 3;
    for (; x2 < x0; x2++) func_0024B2C0(w->objs + x2);
    p = D_80145060;
    if (p != 0) {
        do {
            func_0024B2C0(p);
            func_0024B2C0((u8 *)p + 0x2E8);
            p->brain->f4 = func_0020CB3C((u8 *)w + 0x1B4DC, (u8 *)p + 8);
            p = p->next;
        } while (p != 0);
    }
    func_44E2B8(w);
    x0 = w->nobjs;
    x3 = w->f13C;
    for (; x3 < x0; x3++) {
        o = w->objs + x3;
        func_0024BE2C(o);
        func_00246E34(o);
    }
    func_0020AA40((u8 *)w + 0x1B4DC);
    func_0020ABF0((u8 *)w + 0x1B4DC);
    w->state = 4;
    func_44AA68(D_80145040);
    func_44B31C(D_80145040 + 0x48);
    func_00236864(D_80145040 + 0x48);
}
