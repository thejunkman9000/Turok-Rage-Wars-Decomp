#include "span_1000/code_80233920.h"

#include "shared/gameplay_camera.h"

void func_80234DE0_de(char *);
int func_80245798_de(void);
void func_80245864_de(void *);
f32 func_802459A0_de(void *);
float func_80245AD8_de(void);
void func_8026EF58_de(f32 *, f32 *);
void func_8026F620_de(f32 *, f32 *, f32 *);
void func_8026F898_de(f32 *, f32 *, f32 *);
void func_8026FC9C_de(f32 *, void *);
void func_802727D8_de(void *);
void func_80272828_de(f32 *);
void func_80272CB0_de(void *, f32, f32, f32);
void func_8027302C(float *, float *);
void func_802732D0_de(char *, float *);
void func_802736D4_de(void *, f32);
void func_802738C0_de(void *, f32);
void func_80273A98_de(void *, f32);
void func_80274244_de(f32 *, f32 *);

void func_80274870_de(f32 *, f32, f32);
f32 func_80275DD4_de(void *, f32, f32);
int func_802A23B4_de(void);
int func_802A23F0_de(void);

void func_802B6F9C_de(float *, u16 *, float, float, float, float, float);

f32 func_802B72B0_de(f32);
void func_804428F8_de(void *);
s32 func_802343C8_de();                        /* extern */
void func_802349C0_de(void *);                        /* extern */
s32 func_8023AFF0_de();                  /* extern */
               /* extern */
s32 func_802B6900_de(f32 *, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern s32 D_8011FE88;
extern void *D_80145060;
extern s32 D_80141008;
extern s32 D_800D297C;
extern f32 D_800D2988;
extern s32 D_800CD8D0; 
extern s32 D_800E28D0;
extern s32 D_800E28D4;                          /* unable to generate initializer: unknown type */
typedef struct Shared_func_80234FDC_S1 func_80234FDC_S1;
typedef struct Shared_func_80234FDC_S2 func_80234FDC_S2;
typedef struct Shared_func_80234FDC_S3 func_80234FDC_S3;
typedef struct Shared_func_80234FDC_S4 func_80234FDC_S4;
typedef struct Shared_func_80234FDC_S5 func_80234FDC_S5;
typedef struct Shared_func_80234FDC_S6 func_80234FDC_S6;
typedef struct Shared_func_80234FDC_S7 func_80234FDC_S7;
typedef struct Shared_func_80234FDC_S8 func_80234FDC_S8;







typedef struct Shared_Func_80234FDC_Callback Func_80234FDC_Callback;
extern Func_80234FDC_Callback D_800CB384_de[];
extern func_80234FDC_S4 D_80140FF8;


/* unable to generate initializer: unknown type; const */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x268, 0x26c, 0x270, 0x274, 0x278, 0x27c, 0x280, 0x284, 0x288, 0x298, 0x29c, 0x2a8, 0x2ac, 0x2b0, 0x2b4], gap at: 0x28c. */
/* Updates the actor view and projection matrices and applies camera effects. */
void func_80234FEC_de(func_80234FDC_S2 *arg0) {
    f32 ground_x;
    func_80234FDC_S8 *temp_s0_2;
    f32 sp28[16];
    f32 sp68[16];
    f32 spA8[16];
    f32 spE8[16];
    f32 sp128[16];
    f32 sp168[16];
    f32 sp1A8[16];
    f32 sp1E8[16];
    f32 sp228[16];
    s32 (*temp_v0)(s8 *);
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20_2;
    f32 div_stage; 
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f21_3;
    f32 var_f22_2;
    f32 temp_f22_3;
    f32 temp_f23;
    f32 initial_zoom; 
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f0_6;
    f32 var_f0_7;
    f32 var_f1;
    f32 var_f22;
    f32 var_f4;
    s32 temp_f5;
    s32 temp_v0_4;
    s32 captured_state; 
    s32 var_v1_2;
    s8 *temp_s0;
    s8 *var_s1;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 var_v1_3;

    func_80234FDC_S6 *temp_s4;
    func_80234FDC_S1 *var_s5;
    func_80234FDC_S1 *var_v1;
    func_80234FDC_S5 *state; 

    var_v1 = D_80145060;
    while (var_v1 != 0) {
        if (var_v1->unk5DC == arg0) {
            var_s5 = var_v1;
            goto actor_found;
        }
        var_v1 = var_v1->unk16E0;
    }
    var_s5 = 0;
actor_found:
    arg0->unk18 = (f32) (arg0->unk18 + D_800D2988);
    func_802343C8_de(arg0);
    arg0->unk7C = 1;
    if (func_80245798_de() == 0) {
        temp_v0 = D_800CB384_de[arg0->unk14].fn;
        if (temp_v0 != 0) {
            temp_v0(arg0);
        }
    }
    temp_s4 = &((func_80234FDC_S3 *) arg0)->unk400[D_800D297C];
    func_802B6900_de(sp28, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    if ((func_80245798_de() != 0) && (arg0 != &D_80141008)) {
        func_80245864_de(arg0);
    }
    temp_f24 = arg0->unk5C;
    initial_zoom = arg0->unk60;
    func_802349C0_de(arg0);
    if (func_80245798_de() == 0) {
        func_802337D0_de(arg0->unkB8);
        func_802337D0_de(arg0->unkCC);
        func_802337D0_de(arg0->unkE0);
    }
    var_s1 = &arg0->unk160;
    func_802732D0_de(var_s1, &arg0->unk128);
    func_8026EF58_de(&arg0->unk1A0, (f32 *) var_s1);
    func_802736D4_de(spA8, 3.1415927f);
    func_8026F620_de(sp68, spA8, (f32 *) var_s1);
    func_8026EF58_de(spE8, sp68);
    func_8026F620_de(sp128, spE8, sp28);
    func_8027302C(&arg0->unk220, sp128);
    if ((var_s5 != 0) && (var_s5->unk664 & 0x40) && (arg0->unk24 == 0) && (func_80245798_de() == 0)) {
        f32 temp_f20; 
        var_f1 = (((arg0->unk88 * 0.5f * (func_802B7130_de(arg0->unk90) + 1.0f)) + 0.8f) > 1.0f) ? 1.0f : ((arg0->unk88 * 0.5f * (func_802B7130_de(arg0->unk90) + 1.0f)) + 0.8f);
        arg0->unk80 = var_f1;
        var_f4 = (((arg0->unk8C * 0.5f * (func_802B7130_de(arg0->unk94) + 1.0f)) + 0.9f) > 1.0f) ? 1.0f : ((arg0->unk8C * 0.5f * (func_802B7130_de(arg0->unk94) + 1.0f)) + 0.9f);
        arg0->unk84 = var_f4;
        arg0->unk90 = (f32) (arg0->unk90 + (D_800D2988 * arg0->unk98));
        arg0->unk94 = (f32) (arg0->unk94 + (D_800D2988 * arg0->unk9C));
        var_f22 = var_s5->unk6C8 * 2.5f;
        var_f0 = 0.0f;
        if ((var_f22 < 0.0f) || (var_f0 = 1.0f, (var_f22 > 1.0f))) {
            var_f22 = var_f0;
        }
        func_80274870_de(&arg0->unk88, 0.1f, 0.5f);
        func_80274870_de(&arg0->unk8C, 0.05f, 0.5f);
        temp_f20 = 1.0f - var_f22;
        func_80274870_de(&arg0->unk98, (var_f22 * 0.104719765f) + (temp_f20 * 0.06981318f), 0.16666667f);
        func_80274870_de(&arg0->unk9C, (var_f22 * 0.087266475f) + (temp_f20 * 0.03490659f), 0.16666667f);
    } else {
        arg0->unk84 = 1.0f;
        arg0->unk80 = 1.0f;
    }
    temp_v0_2 = arg0->unk124;
    var_v1_2 = 0x32; 
    if (temp_v0_2 != var_v1_2) {
        arg0->unk84 = (f32) (((f32) (var_v1_2 - temp_v0_2) * 0.08f) + 1.0f);
        temp_f2 = D_800D2988 * 10.0f;
        if (!(temp_f2 >= 2.1474836e9f)) {
            var_v1_2 = (s32) temp_f2;
        } else {
            var_v1_2 = (s32) (temp_f2 - 2.1474836e9f) | 0x80000000;
        }
        temp_v0_3 = arg0->unk124 + var_v1_2;
        var_v1_3 = temp_v0_3;
        arg0->unk124 = temp_v0_3;
        if ((u32) (var_v1_3 & 0xFFFF) >= 0x33U) {
            var_v1_3 = 0x32;
        }
        arg0->unk124 = var_v1_3;
    }
    if (func_80245798_de() != 0) {
        var_f22_2 = func_802459A0_de(arg0);
    } else {
        temp_v0_4 = func_802A23B4_de();
        if ((temp_v0_4 == 1) && (func_802A23F0_de() == temp_v0_4)) {
            var_f22_2 = 45.0f;
        } else if (temp_f24 != 0.0f) {
            var_f22_2 = (temp_f24 * (initial_zoom - 75.0f)) + 75.0f;
        } else {
            var_f22_2 = 75.0f;
        }
    }
    if ((func_80245798_de() != 0) && (arg0 != &D_80141008)) {
        temp_f23 = arg0->unk29C / arg0->unk2A0;
    } else if (D_80140FF8.unk0 == 2) {
        temp_f23 = 0.6666667f;
        if (D_80140FF8.unk122F == 0) {
            temp_f23 = 2.666666f;
        }
    } else {
        temp_f23 = 1.333333f;
    }
    var_f22_2 = var_f22_2 * 0.017453294f;
    temp_f21 = func_802B7130_de(var_f22_2);
    temp_f21_3 = temp_f21 / func_802B6560_de(var_f22_2);
    temp_f20_2 = temp_f21_3 * 1.2792794f;
    temp_f21_3 = temp_f20_2 / temp_f23;
    temp_f21_3 = temp_f21_3 / arg0->unk84;
    temp_f20_3 = temp_f20_2 / arg0->unk80;
    temp_f1 = 1.0f; 
    var_f22_2 = func_802745D0_de(func_802B72B0_de(temp_f1 / ((temp_f21_3 * temp_f21_3) + 1.0f)));
    var_f22_2 = var_f22_2 * 57.295776f; 
    temp_f0 = arg0->unk528;
    temp_f23 = temp_f20_3 / temp_f21_3;
    arg0->unk70 = temp_f23;
    arg0->unk6C = var_f22_2;
    arg0->unk74 = (f32) (temp_f0 * temp_f20_3);
    arg0->unk78 = (f32) (temp_f0 * temp_f21_3);
    if (func_80245798_de() != 0) {
        temp_f5 = (s32) func_80245AD8_de();
        if (temp_f5 > 0) {
            arg0->unk528 = (f32) temp_f5;
        }
    }
    func_802B6F9C_de(sp168, &arg0->unk68, var_f22_2, temp_f23, 16.0f, arg0->unk528, 1.0f - (temp_f24 * 0.95f));
    func_80272CB0_de(sp1A8, -1.0f, 1.0f, 1.0f);
    func_8026F898_de(sp68, sp128, (f32 *) sp168);
    temp_s0 = &arg0->unk1E0;
    func_8026F898_de((f32 *) temp_s0, sp68, sp1A8);
    func_80272828_de((f32 *) temp_s0);
    func_8026FC9C_de((f32 *) temp_s0, arg0->unk380[D_800D297C]);
    func_8027302C(sp1E8, sp128);
    state = &D_80140FF8.state;
    if (state->unk0 == 4) {
        func_802738C0_de(sp1E8, arg0->unk18 * 0.010908309f);
        func_80273A98_de(sp1E8, arg0->unk18 * 0.008726647f);
    }
    func_80272828_de(sp1E8);
    var_f0_2 = sp1E8[0] * 128.0f;
    if (!(var_f0_2 <= 127.0f)) {
        var_f0_2 = 127.0f;
    }
    temp_s4->unk8 = (s8) (s32) var_f0_2;
    var_f0_3 = sp1E8[4] * 128.0f;
    if (!(var_f0_3 <= 127.0f)) {
        var_f0_3 = 127.0f;
    }
    temp_s4->unk9 = (s8) (s32) var_f0_3;
    var_f0_4 = sp1E8[8] * 128.0f;
    if (!(var_f0_4 <= 127.0f)) {
        var_f0_4 = 127.0f;
    }
    temp_s4->unkA = (s8) (s32) var_f0_4;
    var_f0_5 = sp1E8[1] * 128.0f;
    if (!(var_f0_5 <= 127.0f)) {
        var_f0_5 = 127.0f;
    }
    temp_s4->unk18 = (s8) (s32) var_f0_5;
    var_f0_6 = sp1E8[5] * 128.0f;
    if (!(var_f0_6 <= 127.0f)) {
        var_f0_6 = 127.0f;
    }
    temp_s4->unk19 = (s8) (s32) var_f0_6;
    var_f0_7 = sp1E8[9] * 128.0f;
    if (!(var_f0_7 <= 127.0f)) {
        var_f0_7 = 127.0f;
    }
    temp_s4->unk1A = (s8) (s32) var_f0_7;
    temp_s4->unk0 = 0;
    temp_s4->unk1 = 0;
    temp_s4->unk2 = 0;
    temp_s4->unk3 = 0;
    temp_s4->unk4 = 0;
    temp_s4->unk5 = 0;
    temp_s4->unk6 = 0;
    temp_s4->unk7 = 0;
    temp_s4->unk10 = 0;
    temp_s4->unk11 = 0x80;
    temp_s4->unk12 = 0;
    temp_s4->unk13 = 0;
    temp_s4->unk14 = 0;
    temp_s4->unk15 = 0x80;
    temp_s4->unk16 = 0;
    temp_s4->unk17 = 0;
    func_80234DE0_de(arg0);
    func_80274244_de(&arg0->unk150, &arg0->unkE54);
    func_802736D4_de(&arg0->unkE94, arg0->unk138);
    if (D_80140FF8.unk8 != 0) {
        func_802B6F9C_de(sp168, &arg0->unk440, 47.5f, (f32) ((s32) D_800E28D0 / D_800E28D4), 16.0f, 7168.0f, 1.0f);
        func_802727D8_de(sp128);
        func_8026F898_de(sp68, sp128, (f32 *) sp168);
        func_80272CB0_de(sp1A8, -1.0f, 1.0f, 1.0f);
        func_8026F898_de(sp228, sp68, sp1A8);
        func_80272828_de(sp228);
        func_8026FC9C_de(sp228, arg0->unk448[D_800D297C]);
    }
    func_8023AFF0_de(&arg0->unk570, arg0);
    func_804428F8_de(arg0->unk554);
    if (func_80245798_de() != 0) {
        arg0->unk58 = ((void *(*)())func_80286728_de)(&D_8011FE88, &arg0->unk38);
    }
    captured_state = D_800CD8D0;
    arg0->unk64 = captured_state;
    temp_s0_2 = arg0->unk58;
    ground_x = arg0->unk38;
    temp_f23_3 = arg0->unk3C;
    temp_f20_4 = arg0->unk40;
    temp_f22_3 = arg0->unk44;
    if ((temp_s0_2 != 0) && (func_80245798_de() == 0)) {
        temp_f1 = ((temp_f23_3 + temp_f22_3) - func_80275DD4_de(temp_s0_2, ground_x, temp_f20_4)) * 0.09765625f;
        if ((temp_f1 < 11.0f) && (temp_f1 > 5.0f)) {
            arg0->unk64 = (s32) temp_s0_2->unk1C;
        }
    }
    if (func_80245798_de() != 0) {
        arg0->unk64 = (s32) D_800CD8D0;
    }
    if (arg0->unk5C > 0.0f) {
        arg0->unk64 = (s32) D_800CD8D0;
    }
}
