#include "b20_types.h"

s32 func_0028B1F8(u8 *lv, s32 id);
void func_00235AD0(u8 *p);
void func_00272CD0(f32 *m, s32 a, f32 b, f32 c);
void func_00273A34(f32 *m, f32 a);
void func_00273DDC(f32 *m);
void func_002702EC(f32 *m, f32 *src);
s32 func_0028C174(u8 *lv, s32 idx);
void func_0026D980();
void func_0026D9D0(void);
void func_0026DF30(s32 a, f32 *m, void *p, s32 b, s32 c);
void func_00291FE8(Level *lv, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g);
extern s32 D_800D15D0;
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern u8 D_8011FE88[];
extern u8 D_801450C8[];
extern f32 D_8011F5D0[];
extern s32 D_800D297C;
extern u8 D_800D0EF8[];
extern u8 D_auto_80152789;
extern s32 D_auto_800E0B44[];
extern s32 D_800E28D0;

/* the release enters through a stub: `a0 = s0; jal func_0028FDD8` whose delay slot is the
 * first instruction (the frame allocation) of the body that follows */
__asm__(".text\n"
        ".align 2\n"
        ".globl func_auto_00290B98\n"
        ".type func_auto_00290B98,@function\n"
        ".set noreorder\n"
        "func_auto_00290B98:\n"
        "addu $4,$16,$0\n"
        "jal func_0028FDD8\n");

void func_auto_00290B98_body(Level *lv) {
    f32 m[16];
    s32 idx;
    s32 r;
    f32 *p;
    s32 hook;
    register u8 *tb __asm__("$19");
    __asm__(".set reorder" : "=r"(hook));
    __asm__("la %0,D_8011FE88" : "=r"(tb) : "r"(hook));
    D_800D15D0 = 0;
    idx = func_0028B1F8(tb, 0xE10);
    D_800D15E0 = 0;
    p = D_800D15E4;
    p[0] = 255.0f;
    p[1] = 255.0f;
    p[2] = 255.0f;
    p[3] = 255.0f;
    if (idx != -1) {
        func_00235AD0(D_801450C8);
        func_00272CD0(m, 0, -100.0f, -500.0f);
        func_00273A34(m, lv->unk26DB0 * 0.17453295f);
        func_00273DDC(m);
        func_002702EC(m, D_8011F5D0 + D_800D297C * 16);
        r = func_0028C174(tb, idx);
        func_0026D980();
        func_0026DF30(r, D_8011F5D0 + D_800D297C * 16, D_800D0EF8, 0, -1);
        func_0026D9D0();
        func_00291FE8(lv, 0, D_auto_800E0B44[D_auto_80152789], D_800E28D0 / 2, 0xBE, 0xA, 0.4f, 0.7f);
    }
}
