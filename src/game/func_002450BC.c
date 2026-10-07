#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern s32 D_800D0660;
extern s32 D_800D2978;
extern f32 D_800D2988;
extern f32 D_800C88A4;
extern f32 D_800C88A8;
extern f32 D_800C88AC;
extern s32 D_80145074[];
s32 func_00244FA4(void);
s32 func_00245774(void);
s32 func_00245840(void);
void func_00244E48(void);
void func_403458(void);
void func_00245B64(s32 a);
void func_00245BB0(void);
void func_002537D8(s32 a, void *p);
void func_0025470C(s32 a);

void func_002450BC(void) {
    if (D_800D0660 != D_800D2978) {
        D_800D0660 = D_800D2978;
        if (func_00244FA4() == 0) {
            if (func_00245774()) {
                if (func_00245840()) {
                    D_800E2830->f20 = D_800E2830->f1C;
                } else {
                    D_800E2830->f20 = D_800E2830->f1C;
                    D_800E2830->f1C += D_800D2988 * D_800C88A4;
                    if (D_800E2830->f30 <= D_800E2830->f1C) {
                        func_00244E48();
                    }
                    if (D_800E2830->f1C >= D_800E2830->f2C) {
                        if (D_800E2830->f104 == 1) {
                            D_800E2830->f1C -= D_800E2830->f2C;
                        } else {
                            D_800E2830->f1C = D_800E2830->f2C;
                            if (D_800E2830->fB4) {
                                D_800E2830->f3C = 1;
                                D_800E2830->fB4 = 0;
                            }
                        }
                    }
                }
            }
            func_403458();
        }
        func_00244FA4();
        if (D_800E2830->f60) {
            D_800E2830->f64 -= D_800D2988 * D_800C88A8 * 2.0f;
            if (D_800E2830->f64 < D_800C88AC) {
                D_800E2830->f60 = 0;
                D_800E2830->f64 = 0;
                if (func_00245774()) {
                    func_00245B64(1);
                    func_00245BB0();
                    if (D_800E2830->p0) {
                        func_002537D8(0, D_800E2830->p0);
                    }
                    D_800E2830->p0 = 0;
                    D_800E2830->f4 = 0;
                    D_800E2830->f38 = 0;
                    D_800E2830->f3C = 0;
                    D_800E2830->f60 = 0;
                }
                return;
            }
        }
        func_00244FA4();
        if (func_00245774() && !func_00245840() && D_80145074[0] == 0 && D_80145074[0x62D] == 0 && D_800E2830->f104 == 0) {
            if (D_800E2830->f1C >= D_800E2830->f34 && D_800E2830->f44 == 0) {
                void (*fn)(void) = D_800E2830->fn10;
                if (fn) {
                    D_800E2830->fn10 = 0;
                    fn();
                }
                D_800E2830->f44 = 1;
            }
            if (D_800E2830->f1C >= D_800E2830->f2C && D_800E2830->f48 == 0) {
                void (*fn)(void);
                if (D_800E2830->p0) {
                    func_002537D8(0, D_800E2830->p0);
                }
                D_800E2830->p0 = 0;
                D_800E2830->f4 = 0;
                D_800E2830->f38 = 0;
                D_800E2830->f3C = 0;
                fn = D_800E2830->fn0C;
                D_800E2830->f60 = 0;
                if (fn) {
                    D_800E2830->fn0C = 0;
                    fn();
                }
                D_800E2830->f48 = 1;
            }
        }
        func_00244FA4();
        if (D_800E2830->f38) {
            func_0025470C(10);
        }
    }
}
