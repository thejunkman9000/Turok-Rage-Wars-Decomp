/* func_00290A68 (ROM 0x91668, 103 insns) - draws the table entry 3600 of D_8011FE88 (matrix from the lv->unk26DB0 angle) and then calls func_00291FE8.
 *
 * Needs @SN.  Two source tricks are required for the ROM schedule (see wip/out/FINDINGS.txt):
 *  1. The ROM starts with a DEAD read of D_801536B8 (`lui v1; lw v1,...` hoisted above `addiu sp`).  D_801536B8 is declared
 *     volatile here so the read survives; the value is handed to an (otherwise empty) asm that also materialises `tb`
 *     (= &D_8011FE88): in sched2 the asm is the only consumer of the load and the writer of s3 at the same time, so the
 *     load is released right after the `la` pick and is starved by the prologue stores up to the top of the block.
 *     The plain `tb = D_8011FE88;` before the asm is what the PC build (TARGET_PC: no asm) uses; on the MIPS build flow
 *     deletes it (the asm output overwrites it).
 *  2. tb lives in s3 in the ROM (the -1 constant is s2): the register pin only fixes that allocation order.
 */
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
extern volatile s32 D_801536B8;
extern s32 D_800D15D0;
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern u8 D_8011FE88[];
extern u8 D_801450C8[];
extern f32 D_8011F5D0[];
extern s32 D_800D297C;
extern u8 D_800D0EF8[];
extern s32 D_800D7068;
extern s32 D_800E28D0;

void func_00290A68(Level *lv) {
    f32 m[16];
    s32 idx;
    s32 r;
    f32 *p;
    register u8 *tb __asm__("$19");
    tb = D_8011FE88;
    p = (f32 *)D_801536B8;
#ifndef TARGET_PC
    __asm__("la %0,D_8011FE88" : "=r"(tb) : "r"(p));
#endif
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
        func_00291FE8(lv, 0, D_800D7068, D_800E28D0 / 2, 0xBE, 0xA, 0.4f, 0.7f);
    }
}
