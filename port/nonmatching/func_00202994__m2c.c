#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_00202994(s64 arg0, f64 arg1, s64 arg2, f64 arg3) {
    s64 var_t0;

    *M2C_ERROR(/* Read from unset register $k0 */) = 0;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 8) = (s64) M2C_ERROR(/* Read from unset register $at */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x10) = (s64) M2C_ERROR(/* Read from unset register $v0 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x18) = (s64) M2C_ERROR(/* Read from unset register $v1 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x20) = arg0;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x28) = arg1;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x30) = arg2;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x38) = arg3;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x40) = (s64) M2C_ERROR(/* Read from unset register $t0 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x48) = (s64) M2C_ERROR(/* Read from unset register $t1 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x50) = (s64) M2C_ERROR(/* Read from unset register $t2 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x58) = (s64) M2C_ERROR(/* Read from unset register $t3 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x60) = (s64) M2C_ERROR(/* Read from unset register $t4 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x68) = (s64) M2C_ERROR(/* Read from unset register $t5 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x70) = (s64) M2C_ERROR(/* Read from unset register $t6 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x78) = (s64) M2C_ERROR(/* Read from unset register $t7 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x80) = (s64) saved_reg_s0;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x88) = (s64) saved_reg_s1;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x90) = (s64) saved_reg_s2;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x98) = (s64) saved_reg_s3;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xA0) = (s64) saved_reg_s4;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xA8) = (s64) saved_reg_s5;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xB0) = (s64) saved_reg_s6;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xB8) = (s64) saved_reg_s7;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xC0) = (s64) M2C_ERROR(/* Read from unset register $t8 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xC8) = (s64) M2C_ERROR(/* Read from unset register $t9 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xD8) = (s64) M2C_ERROR(/* Read from unset register $k1 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xE0) = (s64) saved_reg_gp;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xE8) = (s64) sp;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xF0) = (s64) saved_reg_fp;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0xD0) = (s64) M2C_ERROR(/* mfc0 $30 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x100) = (s64) M2C_ERROR(/* Read from unset register $lo */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x108) = (s64) M2C_ERROR(/* Read from unset register $hi */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x118) = (s64) M2C_ERROR(/* mfc0 $0 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x120) = (s64) M2C_ERROR(/* mfc0 $1 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x128) = (s64) M2C_ERROR(/* mfc0 $2 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x130) = (s64) M2C_ERROR(/* mfc0 $3 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x138) = (s64) M2C_ERROR(/* mfc0 $4 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x140) = (s64) M2C_ERROR(/* mfc0 $5 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x148) = (s64) M2C_ERROR(/* mfc0 $6 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x150) = (s64) M2C_ERROR(/* mfc0 $7 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x158) = (s64) M2C_ERROR(/* mfc0 $8 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x160) = (s64) M2C_ERROR(/* mfc0 $9 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x168) = (s64) M2C_ERROR(/* mfc0 $10 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x170) = (s64) M2C_ERROR(/* mfc0 $11 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x178) = (s64) M2C_ERROR(/* mfc0 $12 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x180) = (s64) M2C_ERROR(/* mfc0 $13 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x188) = (s64) M2C_ERROR(/* mfc0 $14 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x190) = (s64) M2C_ERROR(/* mfc0 $15 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x198) = (s64) M2C_ERROR(/* mfc0 $16 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1A0) = (s64) M2C_ERROR(/* mfc0 $17 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1A8) = (s64) M2C_ERROR(/* mfc0 $18 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1B0) = (s64) M2C_ERROR(/* mfc0 $19 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1B8) = (s64) M2C_ERROR(/* mfc0 $20 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1C0) = (s64) M2C_ERROR(/* mfc0 $21 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1C8) = (s64) M2C_ERROR(/* mfc0 $22 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1D0) = (s64) M2C_ERROR(/* mfc0 $23 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1D8) = (s64) M2C_ERROR(/* mfc0 $24 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1E0) = (s64) M2C_ERROR(/* mfc0 $25 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1E8) = (s64) M2C_ERROR(/* mfc0 $26 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1F0) = (s64) M2C_ERROR(/* mfc0 $27 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x1F8) = (s64) M2C_ERROR(/* mfc0 $28 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x200) = (s64) M2C_ERROR(/* mfc0 $29 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x208) = (s64) M2C_ERROR(/* mfc0 $30 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x210) = (s64) M2C_ERROR(/* mfc0 $31 */);
    if (0x20000000 & M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x178)) {
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s32 *, 0x318) = (s32) M2C_ERROR(/* cfc1 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s32 *, 0x31C) = (s32) M2C_ERROR(/* cfc1 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x218) = (f64) M2C_ERROR(/* Read from unset register $f0 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x228) = (f64) M2C_ERROR(/* Read from unset register $f2 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x238) = (f64) M2C_ERROR(/* Read from unset register $f4 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x248) = (f64) M2C_ERROR(/* Read from unset register $f6 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x258) = (f64) M2C_ERROR(/* Read from unset register $f8 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x268) = (f64) M2C_ERROR(/* Read from unset register $f10 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x278) = arg0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x288) = arg1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x298) = (f64) M2C_ERROR(/* Read from unset register $f16 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2A8) = (f64) M2C_ERROR(/* Read from unset register $f18 */);
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2B8) = (f64) saved_reg_f20;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2C8) = (f64) saved_reg_f22;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2D8) = (f64) saved_reg_f24;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2E8) = (f64) saved_reg_f26;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2F8) = (f64) saved_reg_f28;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x308) = (f64) saved_reg_f30;
        if (0x04000000 & M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x178)) {
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x220) = (f64) M2C_ERROR(/* Read from unset register $f1 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x230) = (f64) M2C_ERROR(/* Read from unset register $f3 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x240) = (f64) M2C_ERROR(/* Read from unset register $f5 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x250) = (f64) M2C_ERROR(/* Read from unset register $f7 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x260) = (f64) M2C_ERROR(/* Read from unset register $f9 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x270) = (f64) M2C_ERROR(/* Read from unset register $f11 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x280) = arg1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x290) = arg3;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2A0) = (f64) M2C_ERROR(/* Read from unset register $f17 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2B0) = (f64) M2C_ERROR(/* Read from unset register $f19 */);
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2C0) = (f64) saved_reg_f21;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2D0) = (f64) saved_reg_f23;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2E0) = (f64) saved_reg_f25;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x2F0) = (f64) saved_reg_f27;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x300) = (f64) saved_reg_f29;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), f64 *, 0x310) = (f64) saved_reg_f31;
        }
    }
    if (!(M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x178) & 4)) {
        var_t0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x188);
    } else {
        var_t0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x208);
    }
    M2C_FIELD(M2C_ERROR(/* Read from unset register $k0 */), s64 *, 0x110) = var_t0;
}
