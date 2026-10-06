.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBC048-0xBC150 (VRAM 0x002BB448) */
glabel alSavePull
    /* BC048 002BB448 30E200FF */  andi       $v0, $a3, 0xFF
    /* BC04C 002BB44C 2C420011 */  sltiu      $v0, $v0, 0x11
  alabel D_002BB450
    /* BC050 002BB450 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* BC054 002BB454 AFB5002C */  sw         $s5, 0x2C($sp)
    /* BC058 002BB458 0080A821 */  addu       $s5, $a0, $zero
    /* BC05C 002BB45C AFB30024 */  sw         $s3, 0x24($sp)
    /* BC060 002BB460 00A09821 */  addu       $s3, $a1, $zero
    /* BC064 002BB464 AFB20020 */  sw         $s2, 0x20($sp)
    /* BC068 002BB468 00C09021 */  addu       $s2, $a2, $zero
    /* BC06C 002BB46C AFB40028 */  sw         $s4, 0x28($sp)
    /* BC070 002BB470 AFBF0030 */  sw         $ra, 0x30($sp)
    /* BC074 002BB474 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BC078 002BB478 AFB00018 */  sw         $s0, 0x18($sp)
    /* BC07C 002BB47C 8EB10000 */  lw         $s1, 0x0($s5)
    /* BC080 002BB480 8FB00048 */  lw         $s0, 0x48($sp)
    /* BC084 002BB484 16200007 */  bnez       $s1, .L002BB4A4
    /* BC088 002BB488 00E0A021 */   addu      $s4, $a3, $zero
    /* BC08C 002BB48C 3C04800D */  lui        $a0, %hi(D_800CCA40)
    /* BC090 002BB490 2484CA40 */  addiu      $a0, $a0, %lo(D_800CCA40)
    /* BC094 002BB494 3C05800D */  lui        $a1, %hi(D_800CCA44)
    /* BC098 002BB498 24A5CA44 */  addiu      $a1, $a1, %lo(D_800CCA44)
    /* BC09C 002BB49C 0C0AFF50 */  jal        __assert
    /* BC0A0 002BB4A0 24060022 */   addiu     $a2, $zero, 0x22
  .L002BB4A4:
    /* BC0A4 002BB4A4 02202021 */  addu       $a0, $s1, $zero
    /* BC0A8 002BB4A8 02602821 */  addu       $a1, $s3, $zero
    /* BC0AC 002BB4AC 02403021 */  addu       $a2, $s2, $zero
    /* BC0B0 002BB4B0 AFB00010 */  sw         $s0, 0x10($sp)
    /* BC0B4 002BB4B4 8C820004 */  lw         $v0, 0x4($a0)
    /* BC0B8 002BB4B8 0040F809 */  jalr       $v0
    /* BC0BC 002BB4BC 02803821 */   addu      $a3, $s4, $zero
    /* BC0C0 002BB4C0 00408021 */  addu       $s0, $v0, $zero
    /* BC0C4 002BB4C4 02002021 */  addu       $a0, $s0, $zero
    /* BC0C8 002BB4C8 26100008 */  addiu      $s0, $s0, 0x8
    /* BC0CC 002BB4CC 02002821 */  addu       $a1, $s0, $zero
    /* BC0D0 002BB4D0 26100008 */  addiu      $s0, $s0, 0x8
    /* BC0D4 002BB4D4 3C070440 */  lui        $a3, (0x4400580 >> 16)
    /* BC0D8 002BB4D8 34E70580 */  ori        $a3, $a3, (0x4400580 & 0xFFFF)
    /* BC0DC 002BB4DC 02003021 */  addu       $a2, $s0, $zero
    /* BC0E0 002BB4E0 26100008 */  addiu      $s0, $s0, 0x8
    /* BC0E4 002BB4E4 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* BC0E8 002BB4E8 00121040 */  sll        $v0, $s2, 1
    /* BC0EC 002BB4EC 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BC0F0 002BB4F0 AC820004 */  sw         $v0, 0x4($a0)
    /* BC0F4 002BB4F4 3C020D00 */  lui        $v0, (0xD000000 >> 16)
    /* BC0F8 002BB4F8 AC830000 */  sw         $v1, 0x0($a0)
    /* BC0FC 002BB4FC ACA20000 */  sw         $v0, 0x0($a1)
    /* BC100 002BB500 00121080 */  sll        $v0, $s2, 2
    /* BC104 002BB504 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BC108 002BB508 ACA70004 */  sw         $a3, 0x4($a1)
    /* BC10C 002BB50C ACC30000 */  sw         $v1, 0x0($a2)
    /* BC110 002BB510 02001821 */  addu       $v1, $s0, $zero
    /* BC114 002BB514 ACC20004 */  sw         $v0, 0x4($a2)
    /* BC118 002BB518 3C020600 */  lui        $v0, (0x6000000 >> 16)
    /* BC11C 002BB51C AC620000 */  sw         $v0, 0x0($v1)
    /* BC120 002BB520 8EA40014 */  lw         $a0, 0x14($s5)
    /* BC124 002BB524 AC640004 */  sw         $a0, 0x4($v1)
    /* BC128 002BB528 8FBF0030 */  lw         $ra, 0x30($sp)
    /* BC12C 002BB52C 8FB5002C */  lw         $s5, 0x2C($sp)
    /* BC130 002BB530 8FB40028 */  lw         $s4, 0x28($sp)
    /* BC134 002BB534 8FB30024 */  lw         $s3, 0x24($sp)
    /* BC138 002BB538 8FB20020 */  lw         $s2, 0x20($sp)
    /* BC13C 002BB53C 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BC140 002BB540 8FB00018 */  lw         $s0, 0x18($sp)
    /* BC144 002BB544 24620008 */  addiu      $v0, $v1, 0x8
    /* BC148 002BB548 03E00008 */  jr         $ra
    /* BC14C 002BB54C 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel alSavePull
