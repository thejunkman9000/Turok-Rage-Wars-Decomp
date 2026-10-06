.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2A54-0xC2B10 (VRAM 0x002C1E54) */
glabel __osLeoResume
    /* C2A54 002C1E54 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C2A58 002C1E58 3C068015 */  lui        $a2, %hi(__osPiEventState)
    /* C2A5C 002C1E5C 24C6FDE0 */  addiu      $a2, $a2, %lo(__osPiEventState)
    /* C2A60 002C1E60 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C2A64 002C1E64 8CC50000 */  lw         $a1, 0x0($a2)
    /* C2A68 002C1E68 10A00025 */  beqz       $a1, .L002C1F00
    /* C2A6C 002C1E6C 00000000 */   nop
    /* C2A70 002C1E70 8CA40008 */  lw         $a0, 0x8($a1)
    /* C2A74 002C1E74 8CA30010 */  lw         $v1, 0x10($a1)
    /* C2A78 002C1E78 0083102A */  slt        $v0, $a0, $v1
    /* C2A7C 002C1E7C 10400020 */  beqz       $v0, .L002C1F00
    /* C2A80 002C1E80 00000000 */   nop
    /* C2A84 002C1E84 8CA2000C */  lw         $v0, 0xC($a1)
    /* C2A88 002C1E88 00441021 */  addu       $v0, $v0, $a0
    /* C2A8C 002C1E8C 0043001A */  div        $zero, $v0, $v1
    /* C2A90 002C1E90 14600002 */  bnez       $v1, .L002C1E9C
    /* C2A94 002C1E94 00000000 */   nop
    /* C2A98 002C1E98 0007000D */  break      7
  .L002C1E9C:
    /* C2A9C 002C1E9C 2401FFFF */  addiu      $at, $zero, -0x1
    /* C2AA0 002C1EA0 14610004 */  bne        $v1, $at, .L002C1EB4
    /* C2AA4 002C1EA4 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* C2AA8 002C1EA8 14410002 */  bne        $v0, $at, .L002C1EB4
    /* C2AAC 002C1EAC 00000000 */   nop
    /* C2AB0 002C1EB0 0006000D */  break      6
  .L002C1EB4:
    /* C2AB4 002C1EB4 00001810 */  mfhi       $v1
    /* C2AB8 002C1EB8 8CA20014 */  lw         $v0, 0x14($a1)
    /* C2ABC 002C1EBC 8CC40004 */  lw         $a0, 0x4($a2)
    /* C2AC0 002C1EC0 00031880 */  sll        $v1, $v1, 2
    /* C2AC4 002C1EC4 00621821 */  addu       $v1, $v1, $v0
    /* C2AC8 002C1EC8 AC640000 */  sw         $a0, 0x0($v1)
    /* C2ACC 002C1ECC 8CA20008 */  lw         $v0, 0x8($a1)
    /* C2AD0 002C1ED0 8CA30000 */  lw         $v1, 0x0($a1)
    /* C2AD4 002C1ED4 24420001 */  addiu      $v0, $v0, 0x1
    /* C2AD8 002C1ED8 ACA20008 */  sw         $v0, 0x8($a1)
    /* C2ADC 002C1EDC 8C620000 */  lw         $v0, 0x0($v1)
    /* C2AE0 002C1EE0 10400007 */  beqz       $v0, .L002C1F00
    /* C2AE4 002C1EE4 00000000 */   nop
    /* C2AE8 002C1EE8 0C0B0592 */  jal        __osPopThread
    /* C2AEC 002C1EEC 00A02021 */   addu      $a0, $a1, $zero
    /* C2AF0 002C1EF0 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* C2AF4 002C1EF4 24849298 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* C2AF8 002C1EF8 0C0B057E */  jal        __osEnqueueThread
    /* C2AFC 002C1EFC 00402821 */   addu      $a1, $v0, $zero
  .L002C1F00:
    /* C2B00 002C1F00 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C2B04 002C1F04 03E00008 */  jr         $ra
    /* C2B08 002C1F08 27BD0018 */   addiu     $sp, $sp, 0x18


    /* C2B0C 002C1F0C AFB00038 */  .word      0xAFB00038 /* linker padding */
endlabel __osLeoResume
