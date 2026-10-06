.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB73B0-0xB74E4 (VRAM 0x002B67B0) */
glabel func_002B67B0
    /* B73B0 002B67B0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B73B4 002B67B4 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B73B8 002B67B8 00A09821 */  addu       $s3, $a1, $zero
    /* B73BC 002B67BC AFB40020 */  sw         $s4, 0x20($sp)
    /* B73C0 002B67C0 00C0A021 */  addu       $s4, $a2, $zero
    /* B73C4 002B67C4 30E700FF */  andi       $a3, $a3, 0xFF
    /* B73C8 002B67C8 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B73CC 002B67CC AFB20018 */  sw         $s2, 0x18($sp)
    /* B73D0 002B67D0 AFB10014 */  sw         $s1, 0x14($sp)
    /* B73D4 002B67D4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B73D8 002B67D8 8C820060 */  lw         $v0, 0x60($a0)
    /* B73DC 002B67DC 00073900 */  sll        $a3, $a3, 4
    /* B73E0 002B67E0 00E23821 */  addu       $a3, $a3, $v0
    /* B73E4 002B67E4 8CF20000 */  lw         $s2, 0x0($a3)
    /* B73E8 002B67E8 8650000E */  lh         $s0, 0xE($s2)
    /* B73EC 002B67EC 16400007 */  bnez       $s2, .L002B680C
    /* B73F0 002B67F0 24110001 */   addiu     $s1, $zero, 0x1
    /* B73F4 002B67F4 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B73F8 002B67F8 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B73FC 002B67FC 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B7400 002B6800 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B7404 002B6804 0C0AFF50 */  jal        __assert
    /* B7408 002B6808 24060376 */   addiu     $a2, $zero, 0x376
  .L002B680C:
    /* B740C 002B680C 1A00002D */  blez       $s0, .L002B68C4
    /* B7410 002B6810 00001021 */   addu      $v0, $zero, $zero
    /* B7414 002B6814 326500FF */  andi       $a1, $s3, 0xFF
    /* B7418 002B6818 328600FF */  andi       $a2, $s4, 0xFF
    /* B741C 002B681C 02301021 */  addu       $v0, $s1, $s0
  .L002B6820:
    /* B7420 002B6820 00021FC2 */  srl        $v1, $v0, 31
    /* B7424 002B6824 00431021 */  addu       $v0, $v0, $v1
    /* B7428 002B6828 00022043 */  sra        $a0, $v0, 1
    /* B742C 002B682C 2482FFFF */  addiu      $v0, $a0, -0x1
    /* B7430 002B6830 00021080 */  sll        $v0, $v0, 2
    /* B7434 002B6834 02421021 */  addu       $v0, $s2, $v0
    /* B7438 002B6838 8C470010 */  lw         $a3, 0x10($v0)
    /* B743C 002B683C 8CE30004 */  lw         $v1, 0x4($a3)
    /* B7440 002B6840 90620002 */  lbu        $v0, 0x2($v1)
    /* B7444 002B6844 00A2102B */  sltu       $v0, $a1, $v0
    /* B7448 002B6848 5440001A */  bnel       $v0, $zero, .L002B68B4
    /* B744C 002B684C 2490FFFF */   addiu     $s0, $a0, -0x1
    /* B7450 002B6850 90620003 */  lbu        $v0, 0x3($v1)
    /* B7454 002B6854 0045102B */  sltu       $v0, $v0, $a1
    /* B7458 002B6858 14400009 */  bnez       $v0, .L002B6880
    /* B745C 002B685C 00000000 */   nop
    /* B7460 002B6860 90620000 */  lbu        $v0, 0x0($v1)
    /* B7464 002B6864 00C2102B */  sltu       $v0, $a2, $v0
    /* B7468 002B6868 14400005 */  bnez       $v0, .L002B6880
    /* B746C 002B686C 00000000 */   nop
    /* B7470 002B6870 90620001 */  lbu        $v0, 0x1($v1)
    /* B7474 002B6874 0046102B */  sltu       $v0, $v0, $a2
    /* B7478 002B6878 10400012 */  beqz       $v0, .L002B68C4
    /* B747C 002B687C 00E01021 */   addu      $v0, $a3, $zero
  .L002B6880:
    /* B7480 002B6880 90620002 */  lbu        $v0, 0x2($v1)
    /* B7484 002B6884 00A2102B */  sltu       $v0, $a1, $v0
    /* B7488 002B6888 5440000A */  bnel       $v0, $zero, .L002B68B4
    /* B748C 002B688C 2490FFFF */   addiu     $s0, $a0, -0x1
    /* B7490 002B6890 90620000 */  lbu        $v0, 0x0($v1)
    /* B7494 002B6894 00C2102B */  sltu       $v0, $a2, $v0
    /* B7498 002B6898 50400006 */  beql       $v0, $zero, .L002B68B4
    /* B749C 002B689C 24910001 */   addiu     $s1, $a0, 0x1
    /* B74A0 002B68A0 90620003 */  lbu        $v0, 0x3($v1)
    /* B74A4 002B68A4 0045102B */  sltu       $v0, $v0, $a1
    /* B74A8 002B68A8 54400002 */  bnel       $v0, $zero, .L002B68B4
    /* B74AC 002B68AC 24910001 */   addiu     $s1, $a0, 0x1
    /* B74B0 002B68B0 2490FFFF */  addiu      $s0, $a0, -0x1
  .L002B68B4:
    /* B74B4 002B68B4 0211102A */  slt        $v0, $s0, $s1
    /* B74B8 002B68B8 1040FFD9 */  beqz       $v0, .L002B6820
    /* B74BC 002B68BC 02301021 */   addu      $v0, $s1, $s0
    /* B74C0 002B68C0 00001021 */  addu       $v0, $zero, $zero
  .L002B68C4:
    /* B74C4 002B68C4 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B74C8 002B68C8 8FB40020 */  lw         $s4, 0x20($sp)
    /* B74CC 002B68CC 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B74D0 002B68D0 8FB20018 */  lw         $s2, 0x18($sp)
    /* B74D4 002B68D4 8FB10014 */  lw         $s1, 0x14($sp)
    /* B74D8 002B68D8 8FB00010 */  lw         $s0, 0x10($sp)
    /* B74DC 002B68DC 03E00008 */  jr         $ra
    /* B74E0 002B68E0 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B67B0
