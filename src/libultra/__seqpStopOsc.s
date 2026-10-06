.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7904-0xB79F4 (VRAM 0x002B6D04) */
glabel __seqpStopOsc
    /* B7904 002B6D04 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B7908 002B6D08 AFB40020 */  sw         $s4, 0x20($sp)
    /* B790C 002B6D0C 0080A021 */  addu       $s4, $a0, $zero
    /* B7910 002B6D10 AFBF0028 */  sw         $ra, 0x28($sp)
    /* B7914 002B6D14 AFB50024 */  sw         $s5, 0x24($sp)
    /* B7918 002B6D18 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B791C 002B6D1C AFB20018 */  sw         $s2, 0x18($sp)
    /* B7920 002B6D20 AFB10014 */  sw         $s1, 0x14($sp)
    /* B7924 002B6D24 AFB00010 */  sw         $s0, 0x10($sp)
    /* B7928 002B6D28 8E900050 */  lw         $s0, 0x50($s4)
    /* B792C 002B6D2C 12000028 */  beqz       $s0, .L002B6DD0
    /* B7930 002B6D30 00A09821 */   addu      $s3, $a1, $zero
    /* B7934 002B6D34 24150016 */  addiu      $s5, $zero, 0x16
  .L002B6D38:
    /* B7938 002B6D38 9612000C */  lhu        $s2, 0xC($s0)
    /* B793C 002B6D3C 8E110000 */  lw         $s1, 0x0($s0)
    /* B7940 002B6D40 2642FFEA */  addiu      $v0, $s2, -0x16
    /* B7944 002B6D44 2C420002 */  sltiu      $v0, $v0, 0x2
    /* B7948 002B6D48 5040001F */  beql       $v0, $zero, .L002B6DC8
    /* B794C 002B6D4C 02208021 */   addu      $s0, $s1, $zero
    /* B7950 002B6D50 8E020010 */  lw         $v0, 0x10($s0)
    /* B7954 002B6D54 5453001C */  bnel       $v0, $s3, .L002B6DC8
    /* B7958 002B6D58 02208021 */   addu      $s0, $s1, $zero
    /* B795C 002B6D5C 8E040014 */  lw         $a0, 0x14($s0)
    /* B7960 002B6D60 8E820078 */  lw         $v0, 0x78($s4)
    /* B7964 002B6D64 0040F809 */  jalr       $v0
    /* B7968 002B6D68 00000000 */   nop
    /* B796C 002B6D6C 0C0ADD48 */  jal        alUnlink
    /* B7970 002B6D70 02002021 */   addu      $a0, $s0, $zero
    /* B7974 002B6D74 12200005 */  beqz       $s1, .L002B6D8C
    /* B7978 002B6D78 02002021 */   addu      $a0, $s0, $zero
    /* B797C 002B6D7C 8E220008 */  lw         $v0, 0x8($s1)
    /* B7980 002B6D80 8E030008 */  lw         $v1, 0x8($s0)
    /* B7984 002B6D84 00431021 */  addu       $v0, $v0, $v1
    /* B7988 002B6D88 AE220008 */  sw         $v0, 0x8($s1)
  .L002B6D8C:
    /* B798C 002B6D8C 0C0ADD54 */  jal        alLink
    /* B7990 002B6D90 26850048 */   addiu     $a1, $s4, 0x48
    /* B7994 002B6D94 00121400 */  sll        $v0, $s2, 16
    /* B7998 002B6D98 00021403 */  sra        $v0, $v0, 16
    /* B799C 002B6D9C 14550004 */  bne        $v0, $s5, .L002B6DB0
    /* B79A0 002B6DA0 00000000 */   nop
    /* B79A4 002B6DA4 92620037 */  lbu        $v0, 0x37($s3)
    /* B79A8 002B6DA8 080ADB6E */  j          .L002B6DB8
    /* B79AC 002B6DAC 304200FE */   andi      $v0, $v0, 0xFE
  .L002B6DB0:
    /* B79B0 002B6DB0 92620037 */  lbu        $v0, 0x37($s3)
    /* B79B4 002B6DB4 304200FD */  andi       $v0, $v0, 0xFD
  .L002B6DB8:
    /* B79B8 002B6DB8 A2620037 */  sb         $v0, 0x37($s3)
    /* B79BC 002B6DBC 92620037 */  lbu        $v0, 0x37($s3)
    /* B79C0 002B6DC0 10400003 */  beqz       $v0, .L002B6DD0
    /* B79C4 002B6DC4 02208021 */   addu      $s0, $s1, $zero
  .L002B6DC8:
    /* B79C8 002B6DC8 1600FFDB */  bnez       $s0, .L002B6D38
    /* B79CC 002B6DCC 00000000 */   nop
  .L002B6DD0:
    /* B79D0 002B6DD0 8FBF0028 */  lw         $ra, 0x28($sp)
    /* B79D4 002B6DD4 8FB50024 */  lw         $s5, 0x24($sp)
    /* B79D8 002B6DD8 8FB40020 */  lw         $s4, 0x20($sp)
    /* B79DC 002B6DDC 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B79E0 002B6DE0 8FB20018 */  lw         $s2, 0x18($sp)
    /* B79E4 002B6DE4 8FB10014 */  lw         $s1, 0x14($sp)
    /* B79E8 002B6DE8 8FB00010 */  lw         $s0, 0x10($sp)
    /* B79EC 002B6DEC 03E00008 */  jr         $ra
    /* B79F0 002B6DF0 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel __seqpStopOsc
