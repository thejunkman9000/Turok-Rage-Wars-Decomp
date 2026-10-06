.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB438C-0xB4480 (VRAM 0x002B378C) */
glabel func_002B378C
    /* B438C 002B378C 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B4390 002B3790 AFB10014 */  sw         $s1, 0x14($sp)
    /* B4394 002B3794 00808821 */  addu       $s1, $a0, $zero
    /* B4398 002B3798 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B439C 002B379C 00A09821 */  addu       $s3, $a1, $zero
    /* B43A0 002B37A0 AFB00010 */  sw         $s0, 0x10($sp)
    /* B43A4 002B37A4 2410FFFF */  addiu      $s0, $zero, -0x1
    /* B43A8 002B37A8 00002821 */  addu       $a1, $zero, $zero
    /* B43AC 002B37AC AFBF0020 */  sw         $ra, 0x20($sp)
    /* B43B0 002B37B0 AFB20018 */  sw         $s2, 0x18($sp)
    /* B43B4 002B37B4 8E260010 */  lw         $a2, 0x10($s1)
  .L002B37B8:
    /* B43B8 002B37B8 8E220004 */  lw         $v0, 0x4($s1)
    /* B43BC 002B37BC 00A21006 */  srlv       $v0, $v0, $a1
    /* B43C0 002B37C0 30420001 */  andi       $v0, $v0, 0x1
    /* B43C4 002B37C4 5040000E */  beql       $v0, $zero, .L002B3800
    /* B43C8 002B37C8 24A50001 */   addiu     $a1, $a1, 0x1
    /* B43CC 002B37CC 8E220014 */  lw         $v0, 0x14($s1)
    /* B43D0 002B37D0 10400004 */  beqz       $v0, .L002B37E4
    /* B43D4 002B37D4 00000000 */   nop
    /* B43D8 002B37D8 8C8200B8 */  lw         $v0, 0xB8($a0)
    /* B43DC 002B37DC 00461023 */  subu       $v0, $v0, $a2
    /* B43E0 002B37E0 AC8200B8 */  sw         $v0, 0xB8($a0)
  .L002B37E4:
    /* B43E4 002B37E4 8C8300B8 */  lw         $v1, 0xB8($a0)
    /* B43E8 002B37E8 0070102B */  sltu       $v0, $v1, $s0
    /* B43EC 002B37EC 50400004 */  beql       $v0, $zero, .L002B3800
    /* B43F0 002B37F0 24A50001 */   addiu     $a1, $a1, 0x1
    /* B43F4 002B37F4 00608021 */  addu       $s0, $v1, $zero
    /* B43F8 002B37F8 00A09021 */  addu       $s2, $a1, $zero
    /* B43FC 002B37FC 24A50001 */  addiu      $a1, $a1, 0x1
  .L002B3800:
    /* B4400 002B3800 2CA20010 */  sltiu      $v0, $a1, 0x10
    /* B4404 002B3804 1440FFEC */  bnez       $v0, .L002B37B8
    /* B4408 002B3808 24840004 */   addiu     $a0, $a0, 0x4
    /* B440C 002B380C 02202021 */  addu       $a0, $s1, $zero
    /* B4410 002B3810 02402821 */  addu       $a1, $s2, $zero
    /* B4414 002B3814 0C0ACC40 */  jal        func_002B3100
    /* B4418 002B3818 02603021 */   addu      $a2, $s3, $zero
    /* B441C 002B381C AE700004 */  sw         $s0, 0x4($s3)
    /* B4420 002B3820 8E22000C */  lw         $v0, 0xC($s1)
    /* B4424 002B3824 AE300010 */  sw         $s0, 0x10($s1)
    /* B4428 002B3828 00501021 */  addu       $v0, $v0, $s0
    /* B442C 002B382C AE22000C */  sw         $v0, 0xC($s1)
    /* B4430 002B3830 86630000 */  lh         $v1, 0x0($s3)
    /* B4434 002B3834 24020012 */  addiu      $v0, $zero, 0x12
    /* B4438 002B3838 10620008 */  beq        $v1, $v0, .L002B385C
    /* B443C 002B383C 02202021 */   addu      $a0, $s1, $zero
    /* B4440 002B3840 0C0ACEBF */  jal        func_002B3AFC
    /* B4444 002B3844 02402821 */   addu      $a1, $s2, $zero
    /* B4448 002B3848 00122080 */  sll        $a0, $s2, 2
    /* B444C 002B384C 02242021 */  addu       $a0, $s1, $a0
    /* B4450 002B3850 8C8300B8 */  lw         $v1, 0xB8($a0)
    /* B4454 002B3854 00621821 */  addu       $v1, $v1, $v0
    /* B4458 002B3858 AC8300B8 */  sw         $v1, 0xB8($a0)
  .L002B385C:
    /* B445C 002B385C 24020001 */  addiu      $v0, $zero, 0x1
    /* B4460 002B3860 AE220014 */  sw         $v0, 0x14($s1)
    /* B4464 002B3864 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B4468 002B3868 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B446C 002B386C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B4470 002B3870 8FB10014 */  lw         $s1, 0x14($sp)
    /* B4474 002B3874 8FB00010 */  lw         $s0, 0x10($sp)
    /* B4478 002B3878 03E00008 */  jr         $ra
    /* B447C 002B387C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B378C
