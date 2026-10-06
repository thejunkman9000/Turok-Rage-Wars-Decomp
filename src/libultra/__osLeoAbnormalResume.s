.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2980-0xC2A54 (VRAM 0x002C1D80) */
glabel __osLeoAbnormalResume
    /* C2980 002C1D80 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C2984 002C1D84 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* C2988 002C1D88 3C028015 */  lui        $v0, %hi(__osDiskHandle)
    /* C298C 002C1D8C 8C42EA44 */  lw         $v0, %lo(__osDiskHandle)($v0)
    /* C2990 002C1D90 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
    /* C2994 002C1D94 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C2998 002C1D98 8C630000 */  lw         $v1, 0x0($v1)
    /* C299C 002C1D9C 24460014 */  addiu      $a2, $v0, 0x14
    /* C29A0 002C1DA0 30620003 */  andi       $v0, $v1, 0x3
    /* C29A4 002C1DA4 10400006 */  beqz       $v0, .L002C1DC0
    /* C29A8 002C1DA8 3C04A460 */   lui       $a0, %hi(PI_STATUS_REG)
    /* C29AC 002C1DAC 34840010 */  ori        $a0, $a0, %lo(PI_STATUS_REG)
  .L002C1DB0:
    /* C29B0 002C1DB0 8C830000 */  lw         $v1, 0x0($a0)
    /* C29B4 002C1DB4 30620003 */  andi       $v0, $v1, 0x3
    /* C29B8 002C1DB8 1440FFFD */  bnez       $v0, .L002C1DB0
    /* C29BC 002C1DBC 00000000 */   nop
  .L002C1DC0:
    /* C29C0 002C1DC0 3C05A500 */  lui        $a1, %hi(LEO_BM_CTL)
    /* C29C4 002C1DC4 34A50510 */  ori        $a1, $a1, %lo(LEO_BM_CTL)
    /* C29C8 002C1DC8 3C04A460 */  lui        $a0, %hi(PI_STATUS_REG)
    /* C29CC 002C1DCC 34840010 */  ori        $a0, $a0, %lo(PI_STATUS_REG)
    /* C29D0 002C1DD0 8CC20010 */  lw         $v0, 0x10($a2)
    /* C29D4 002C1DD4 3C031000 */  lui        $v1, (0x10000000 >> 16)
    /* C29D8 002C1DD8 00431025 */  or         $v0, $v0, $v1
    /* C29DC 002C1DDC ACA20000 */  sw         $v0, 0x0($a1)
    /* C29E0 002C1DE0 8C830000 */  lw         $v1, 0x0($a0)
    /* C29E4 002C1DE4 30620003 */  andi       $v0, $v1, 0x3
    /* C29E8 002C1DE8 10400006 */  beqz       $v0, .L002C1E04
    /* C29EC 002C1DEC 3C04A460 */   lui       $a0, %hi(PI_STATUS_REG)
    /* C29F0 002C1DF0 34840010 */  ori        $a0, $a0, %lo(PI_STATUS_REG)
  .L002C1DF4:
    /* C29F4 002C1DF4 8C830000 */  lw         $v1, 0x0($a0)
    /* C29F8 002C1DF8 30620003 */  andi       $v0, $v1, 0x3
    /* C29FC 002C1DFC 1440FFFD */  bnez       $v0, .L002C1DF4
    /* C2A00 002C1E00 00000000 */   nop
  .L002C1E04:
    /* C2A04 002C1E04 3C03A500 */  lui        $v1, %hi(LEO_BM_CTL)
    /* C2A08 002C1E08 8CC20010 */  lw         $v0, 0x10($a2)
    /* C2A0C 002C1E0C 34630510 */  ori        $v1, $v1, %lo(LEO_BM_CTL)
    /* C2A10 002C1E10 AC620000 */  sw         $v0, 0x0($v1)
    /* C2A14 002C1E14 0C0B0795 */  jal        __osLeoResume
    /* C2A18 002C1E18 00000000 */   nop
    /* C2A1C 002C1E1C 3C06A460 */  lui        $a2, %hi(PI_STATUS_REG)
    /* C2A20 002C1E20 34C60010 */  ori        $a2, $a2, %lo(PI_STATUS_REG)
    /* C2A24 002C1E24 3C050010 */  lui        $a1, (0x100401 >> 16)
    /* C2A28 002C1E28 34A50401 */  ori        $a1, $a1, (0x100401 & 0xFFFF)
    /* C2A2C 002C1E2C 3C04800E */  lui        $a0, %hi(__OSGlobalIntMask)
    /* C2A30 002C1E30 24849288 */  addiu      $a0, $a0, %lo(__OSGlobalIntMask)
    /* C2A34 002C1E34 8C820000 */  lw         $v0, 0x0($a0)
    /* C2A38 002C1E38 24030002 */  addiu      $v1, $zero, 0x2
    /* C2A3C 002C1E3C ACC30000 */  sw         $v1, 0x0($a2)
    /* C2A40 002C1E40 00451025 */  or         $v0, $v0, $a1
    /* C2A44 002C1E44 AC820000 */  sw         $v0, 0x0($a0)
    /* C2A48 002C1E48 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C2A4C 002C1E4C 03E00008 */  jr         $ra
    /* C2A50 002C1E50 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel __osLeoAbnormalResume
