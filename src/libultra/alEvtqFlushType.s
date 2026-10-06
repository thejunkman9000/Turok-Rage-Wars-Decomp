.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5F28-0xB5FE0 (VRAM 0x002B5328) */
glabel alEvtqFlushType
    /* B5F28 002B5328 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5F2C 002B532C AFB3001C */  sw         $s3, 0x1C($sp)
    /* B5F30 002B5330 00809821 */  addu       $s3, $a0, $zero
    /* B5F34 002B5334 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5F38 002B5338 00A08821 */  addu       $s1, $a1, $zero
    /* B5F3C 002B533C 24040001 */  addiu      $a0, $zero, 0x1
    /* B5F40 002B5340 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B5F44 002B5344 AFB40020 */  sw         $s4, 0x20($sp)
    /* B5F48 002B5348 AFB20018 */  sw         $s2, 0x18($sp)
    /* B5F4C 002B534C 0C0B0898 */  jal        osSetIntMask
    /* B5F50 002B5350 AFB00010 */   sw        $s0, 0x10($sp)
    /* B5F54 002B5354 8E700008 */  lw         $s0, 0x8($s3)
    /* B5F58 002B5358 12000015 */  beqz       $s0, .L002B53B0
    /* B5F5C 002B535C 0040A021 */   addu      $s4, $v0, $zero
    /* B5F60 002B5360 00111400 */  sll        $v0, $s1, 16
    /* B5F64 002B5364 00029403 */  sra        $s2, $v0, 16
  .L002B5368:
    /* B5F68 002B5368 8602000C */  lh         $v0, 0xC($s0)
    /* B5F6C 002B536C 8E110000 */  lw         $s1, 0x0($s0)
    /* B5F70 002B5370 5452000D */  bnel       $v0, $s2, .L002B53A8
    /* B5F74 002B5374 02208021 */   addu      $s0, $s1, $zero
    /* B5F78 002B5378 12200005 */  beqz       $s1, .L002B5390
    /* B5F7C 002B537C 00000000 */   nop
    /* B5F80 002B5380 8E220008 */  lw         $v0, 0x8($s1)
    /* B5F84 002B5384 8E030008 */  lw         $v1, 0x8($s0)
    /* B5F88 002B5388 00431021 */  addu       $v0, $v0, $v1
    /* B5F8C 002B538C AE220008 */  sw         $v0, 0x8($s1)
  .L002B5390:
    /* B5F90 002B5390 0C0ADD48 */  jal        alUnlink
    /* B5F94 002B5394 02002021 */   addu      $a0, $s0, $zero
    /* B5F98 002B5398 02002021 */  addu       $a0, $s0, $zero
    /* B5F9C 002B539C 0C0ADD54 */  jal        alLink
    /* B5FA0 002B53A0 02602821 */   addu      $a1, $s3, $zero
    /* B5FA4 002B53A4 02208021 */  addu       $s0, $s1, $zero
  .L002B53A8:
    /* B5FA8 002B53A8 1600FFEF */  bnez       $s0, .L002B5368
    /* B5FAC 002B53AC 00000000 */   nop
  .L002B53B0:
    /* B5FB0 002B53B0 0C0B0898 */  jal        osSetIntMask
    /* B5FB4 002B53B4 02802021 */   addu      $a0, $s4, $zero
    /* B5FB8 002B53B8 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B5FBC 002B53BC 8FB40020 */  lw         $s4, 0x20($sp)
    /* B5FC0 002B53C0 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B5FC4 002B53C4 8FB20018 */  lw         $s2, 0x18($sp)
    /* B5FC8 002B53C8 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5FCC 002B53CC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5FD0 002B53D0 03E00008 */  jr         $ra
    /* B5FD4 002B53D4 27BD0028 */   addiu     $sp, $sp, 0x28


glabel func_002B53D8
    /* B5FD8 002B53D8 080AD96F */  .word      0x080AD96F /* was: j          .L002B65BC */
    /* B5FDC 002B53DC A0500008 */   sb        $s0, 0x8($v0)
endlabel alEvtqFlushType
