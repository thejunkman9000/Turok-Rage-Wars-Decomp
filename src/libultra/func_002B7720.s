.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8320-0xB8450 (VRAM 0x002B7720) */
glabel func_002B7720
    /* B8320 002B7720 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B8324 002B7724 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B8328 002B7728 00808821 */  addu       $s1, $a0, $zero
    /* B832C 002B772C AFB20030 */  sw         $s2, 0x30($sp)
    /* B8330 002B7730 00A09021 */  addu       $s2, $a1, $zero
    /* B8334 002B7734 00002021 */  addu       $a0, $zero, $zero
    /* B8338 002B7738 AFBF0034 */  sw         $ra, 0x34($sp)
    /* B833C 002B773C AFB00028 */  sw         $s0, 0x28($sp)
    /* B8340 002B7740 8E430000 */  lw         $v1, 0x0($s2)
    /* B8344 002B7744 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B8348 002B7748 AE22003C */  sw         $v0, 0x3C($s1)
    /* B834C 002B774C 24023E80 */  addiu      $v0, $zero, 0x3E80
    /* B8350 002B7750 AE220048 */  sw         $v0, 0x48($s1)
    /* B8354 002B7754 AE230044 */  sw         $v1, 0x44($s1)
    /* B8358 002B7758 8E430000 */  lw         $v1, 0x0($s2)
    /* B835C 002B775C 00802821 */  addu       $a1, $a0, $zero
    /* B8360 002B7760 00031040 */  sll        $v0, $v1, 1
    /* B8364 002B7764 00431021 */  addu       $v0, $v0, $v1
    /* B8368 002B7768 00021100 */  sll        $v0, $v0, 4
    /* B836C 002B776C AFA20010 */  sw         $v0, 0x10($sp)
    /* B8370 002B7770 8E460008 */  lw         $a2, 0x8($s2)
    /* B8374 002B7774 0C0AD504 */  jal        func_002B5410
    /* B8378 002B7778 24070001 */   addiu     $a3, $zero, 0x1
    /* B837C 002B777C 00402021 */  addu       $a0, $v0, $zero
    /* B8380 002B7780 AE240040 */  sw         $a0, 0x40($s1)
    /* B8384 002B7784 8E420000 */  lw         $v0, 0x0($s2)
    /* B8388 002B7788 10400007 */  beqz       $v0, .L002B77A8
    /* B838C 002B778C 00001821 */   addu      $v1, $zero, $zero
  .L002B7790:
    /* B8390 002B7790 AC80001C */  sw         $zero, 0x1C($a0)
    /* B8394 002B7794 8E420000 */  lw         $v0, 0x0($s2)
    /* B8398 002B7798 24630001 */  addiu      $v1, $v1, 0x1
    /* B839C 002B779C 0062102B */  sltu       $v0, $v1, $v0
    /* B83A0 002B77A0 1440FFFB */  bnez       $v0, .L002B7790
    /* B83A4 002B77A4 24840030 */   addiu     $a0, $a0, 0x30
  .L002B77A8:
    /* B83A8 002B77A8 00002021 */  addu       $a0, $zero, $zero
    /* B83AC 002B77AC 8E430004 */  lw         $v1, 0x4($s2)
    /* B83B0 002B77B0 00802821 */  addu       $a1, $a0, $zero
    /* B83B4 002B77B4 000310C0 */  sll        $v0, $v1, 3
    /* B83B8 002B77B8 00431023 */  subu       $v0, $v0, $v1
    /* B83BC 002B77BC 00021080 */  sll        $v0, $v0, 2
    /* B83C0 002B77C0 AFA20010 */  sw         $v0, 0x10($sp)
    /* B83C4 002B77C4 8E460008 */  lw         $a2, 0x8($s2)
    /* B83C8 002B77C8 0C0AD504 */  jal        func_002B5410
    /* B83CC 002B77CC 24070001 */   addiu     $a3, $zero, 0x1
    /* B83D0 002B77D0 26300014 */  addiu      $s0, $s1, 0x14
    /* B83D4 002B77D4 02002021 */  addu       $a0, $s0, $zero
    /* B83D8 002B77D8 8E460004 */  lw         $a2, 0x4($s2)
    /* B83DC 002B77DC 0C0AD424 */  jal        func_002B5090
    /* B83E0 002B77E0 00402821 */   addu      $a1, $v0, $zero
    /* B83E4 002B77E4 3C02800E */  lui        $v0, %hi(D_800D80A0)
    /* B83E8 002B77E8 8C4280A0 */  lw         $v0, %lo(D_800D80A0)($v0)
    /* B83EC 002B77EC 02202821 */  addu       $a1, $s1, $zero
    /* B83F0 002B77F0 AE200000 */  sw         $zero, 0x0($s1)
    /* B83F4 002B77F4 AE310004 */  sw         $s1, 0x4($s1)
    /* B83F8 002B77F8 AE220038 */  sw         $v0, 0x38($s1)
    /* B83FC 002B77FC 00402021 */  addu       $a0, $v0, $zero
    /* B8400 002B7800 3C02002B */  lui        $v0, %hi(func_002B7C8C)
    /* B8404 002B7804 24427C8C */  addiu      $v0, $v0, %lo(func_002B7C8C)
    /* B8408 002B7808 0C0AE020 */  jal        func_002B8080
    /* B840C 002B780C AE220008 */   sw        $v0, 0x8($s1)
    /* B8410 002B7810 02002021 */  addu       $a0, $s0, $zero
    /* B8414 002B7814 24020005 */  addiu      $v0, $zero, 0x5
    /* B8418 002B7818 A7A20018 */  sh         $v0, 0x18($sp)
    /* B841C 002B781C 8E260048 */  lw         $a2, 0x48($s1)
    /* B8420 002B7820 0C0AD469 */  jal        func_002B51A4
    /* B8424 002B7824 27A50018 */   addiu     $a1, $sp, 0x18
    /* B8428 002B7828 02002021 */  addu       $a0, $s0, $zero
    /* B842C 002B782C 0C0AD443 */  jal        func_002B510C
    /* B8430 002B7830 26250028 */   addiu     $a1, $s1, 0x28
    /* B8434 002B7834 AE22004C */  sw         $v0, 0x4C($s1)
    /* B8438 002B7838 8FBF0034 */  lw         $ra, 0x34($sp)
    /* B843C 002B783C 8FB20030 */  lw         $s2, 0x30($sp)
    /* B8440 002B7840 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B8444 002B7844 8FB00028 */  lw         $s0, 0x28($sp)
    /* B8448 002B7848 03E00008 */  jr         $ra
    /* B844C 002B784C 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_002B7720
