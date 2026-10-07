#include "b08_types.h"

typedef struct ViewObj {
    u8 pad0[0x29C];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
} ViewObj;

void func_002909D0();
void func_00289054(void *w, ViewObj *a);
s32 func_00245788();
s32 func_002934DC();
void func_00228774(void *l, ViewObj *a);
void func_0022A274(void *l, ViewObj *a);
void func_0028B004(void *w, ViewObj *a);
void func_002A6170(void *l, ViewObj *a);
void func_002905D4(void *w, ViewObj *a);
void func_00286424(void *w, ViewObj *a);
void func_00228934(void *l, ViewObj *a);
void func_0023B3E8(void *p, ViewObj *a);
void func_0028B13C(void *w, ViewObj *a);
void func_002A577C(void *l, ViewObj *a);
void func_00238D20(ViewObj *a);
void func_0022A2FC(void *l, ViewObj *a);
void func_0026925C(s32 a);

extern u8 D_80145040[];
extern u8 D_8013BA80[];
extern DlCmd *D_80110634;
extern s32 D_801462C8;

void func_002362D8(ViewObj *a, u8 *w) {
    DlCmd *dl;
    DlCmd *dl6;
    u32 x2;

    func_002909D0();
    func_00289054(w, a);
    if (func_00245788() == 0) {
        func_00228774(D_80145040, a);
    }
    if (func_002934DC() != 0) {
        func_0022A274(D_80145040, a);
    }
    func_0028B004(w, a);
    func_002A6170(D_8013BA80, a);
    if (func_00245788() == 0) {
        func_002905D4(w + 0x11778, a);
    }
    func_00286424(w, a);
    func_00228934(D_80145040, a);
    func_0023B3E8((u8 *)a + 0x570, a);
    func_0028B13C(w, a);
    func_002A577C(D_8013BA80, a);
    func_00238D20(a);
    if (func_00245788() == 0 && func_002934DC() != 0) {
        func_0022A2FC(D_80145040, a);
    }
    if (D_801462C8 & 0x200) {
        dl = D_80110634++;
        dl->w0 = 0xE7000000;
        dl->w1 = 0;
        dl = D_80110634++;
        dl->w0 = 0xE3000A01;
        dl->w1 = 0;
        dl = D_80110634++;
        dl->w0 = 0xF9000000;
        dl->w1 = -1;
        dl = D_80110634++;
        dl->w0 = 0xEE000000;
        dl->w1 = -1;
        dl = D_80110634++;
        dl->w0 = 0xE2001D00;
        dl->w1 = 4;
        func_0026925C(0x16);
        dl6 = D_80110634++;
        dl6->w0 = 0xF6000000 | ((((u32)(a->unk2A4 + a->unk29C)) & 0x3FF) << 14) | ((((u32)(a->unk2A8 + a->unk2A0)) & 0x3FF) << 2);
        dl6->w1 = (((u32)a->unk2A4 & 0x3FF) << 14) | (((u32)a->unk2A8 & 0x3FF) << 2);
    }
}
