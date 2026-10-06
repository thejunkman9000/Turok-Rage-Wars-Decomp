.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B59D0-0x1B5AA8 (VRAM 0x004479D0) */
glabel func_004479D0
    /* 1B59D0 004479D0 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* 1B59D4 004479D4 AFB20028 */  sw         $s2, 0x28($sp)
    /* 1B59D8 004479D8 00809021 */  addu       $s2, $a0, $zero
    /* 1B59DC 004479DC AFB3002C */  sw         $s3, 0x2C($sp)
    /* 1B59E0 004479E0 00A09821 */  addu       $s3, $a1, $zero
    /* 1B59E4 004479E4 02602021 */  addu       $a0, $s3, $zero
    /* 1B59E8 004479E8 AFBF0030 */  sw         $ra, 0x30($sp)
    /* 1B59EC 004479EC AFB10024 */  sw         $s1, 0x24($sp)
  .L004479F0:
    /* 1B59F0 004479F0 0C111EAA */  jal        func_00447AA8
    /* 1B59F4 004479F4 AFB00020 */   sw        $s0, 0x20($sp)
    /* 1B59F8 004479F8 24040001 */  addiu      $a0, $zero, 0x1
    /* 1B59FC 004479FC 3C118015 */  lui        $s1, %hi(__osPfsPifRam)
    /* 1B5A00 00447A00 26314110 */  addiu      $s1, $s1, %lo(__osPfsPifRam)
    /* 1B5A04 00447A04 0C0AFB68 */  jal        __osSiRawStartDma
    /* 1B5A08 00447A08 02202821 */   addu      $a1, $s1, $zero
    /* 1B5A0C 00447A0C 02402021 */  addu       $a0, $s2, $zero
    /* 1B5A10 00447A10 27B00018 */  addiu      $s0, $sp, 0x18
    /* 1B5A14 00447A14 02002821 */  addu       $a1, $s0, $zero
    /* 1B5A18 00447A18 0C0B00E4 */  jal        osRecvMesg
    /* 1B5A1C 00447A1C 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B5A20 00447A20 00002021 */  addu       $a0, $zero, $zero
    /* 1B5A24 00447A24 0C0AFB68 */  jal        __osSiRawStartDma
    /* 1B5A28 00447A28 02202821 */   addu      $a1, $s1, $zero
    /* 1B5A2C 00447A2C 02402021 */  addu       $a0, $s2, $zero
    /* 1B5A30 00447A30 02002821 */  addu       $a1, $s0, $zero
    /* 1B5A34 00447A34 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B5A38 00447A38 0C0B00E4 */  jal        osRecvMesg
    /* 1B5A3C 00447A3C 00408021 */   addu      $s0, $v0, $zero
    /* 1B5A40 00447A40 02602021 */  addu       $a0, $s3, $zero
    /* 1B5A44 00447A44 0C111ECD */  jal        func_00447B34
    /* 1B5A48 00447A48 27A50010 */   addiu     $a1, $sp, 0x10
    /* 1B5A4C 00447A4C 93A30012 */  lbu        $v1, 0x12($sp)
    /* 1B5A50 00447A50 30620001 */  andi       $v0, $v1, 0x1
    /* 1B5A54 00447A54 10400003 */  beqz       $v0, .L00447A64
    /* 1B5A58 00447A58 30620002 */   andi      $v0, $v1, 0x2
    /* 1B5A5C 00447A5C 1440000B */  bnez       $v0, .L00447A8C
    /* 1B5A60 00447A60 24020002 */   addiu     $v0, $zero, 0x2
  .L00447A64:
    /* 1B5A64 00447A64 97A20012 */  lhu        $v0, 0x12($sp)
    /* 1B5A68 00447A68 24030100 */  addiu      $v1, $zero, 0x100
    /* 1B5A6C 00447A6C 304201FF */  andi       $v0, $v0, 0x1FF
    /* 1B5A70 00447A70 14430006 */  bne        $v0, $v1, .L00447A8C
    /* 1B5A74 00447A74 24020001 */   addiu     $v0, $zero, 0x1
    /* 1B5A78 00447A78 93A30012 */  lbu        $v1, 0x12($sp)
    /* 1B5A7C 00447A7C 24020004 */  addiu      $v0, $zero, 0x4
    /* 1B5A80 00447A80 00621824 */  and        $v1, $v1, $v0
    /* 1B5A84 00447A84 50600001 */  beql       $v1, $zero, .L00447A8C
    /* 1B5A88 00447A88 02001021 */   addu      $v0, $s0, $zero
  .L00447A8C:
    /* 1B5A8C 00447A8C 8FBF0030 */  lw         $ra, 0x30($sp)
    /* 1B5A90 00447A90 8FB3002C */  lw         $s3, 0x2C($sp)
    /* 1B5A94 00447A94 8FB20028 */  lw         $s2, 0x28($sp)
    /* 1B5A98 00447A98 8FB10024 */  lw         $s1, 0x24($sp)
    /* 1B5A9C 00447A9C 8FB00020 */  lw         $s0, 0x20($sp)
    /* 1B5AA0 00447AA0 03E00008 */  jr         $ra
    /* 1B5AA4 00447AA4 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_004479D0
