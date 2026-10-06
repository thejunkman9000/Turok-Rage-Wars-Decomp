.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B5140-0x1B51D0 (VRAM 0x00447140) */
glabel func_00447140
    /* 1B5140 00447140 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* 1B5144 00447144 AFB1001C */  sw         $s1, 0x1C($sp)
    /* 1B5148 00447148 00808821 */  addu       $s1, $a0, $zero
    /* 1B514C 0044714C AFB20020 */  sw         $s2, 0x20($sp)
    /* 1B5150 00447150 00A09021 */  addu       $s2, $a1, $zero
    /* 1B5154 00447154 AFB30024 */  sw         $s3, 0x24($sp)
    /* 1B5158 00447158 00C09821 */  addu       $s3, $a2, $zero
    /* 1B515C 0044715C AFBF0028 */  sw         $ra, 0x28($sp)
    /* 1B5160 00447160 AFB00018 */  sw         $s0, 0x18($sp)
    /* 1B5164 00447164 0C112645 */  jal        __osPfsSelectBank
    /* 1B5168 00447168 A2270065 */   sb        $a3, 0x65($s1)
    /* 1B516C 0044716C 14400011 */  bnez       $v0, .L004471B4
    /* 1B5170 00447170 00008021 */   addu      $s0, $zero, $zero
    /* 1B5174 00447174 001290C0 */  sll        $s2, $s2, 3
    /* 1B5178 00447178 02503021 */  addu       $a2, $s2, $s0
  .L0044717C:
    /* 1B517C 0044717C 30C6FFFF */  andi       $a2, $a2, 0xFFFF
    /* 1B5180 00447180 AFA00010 */  sw         $zero, 0x10($sp)
    /* 1B5184 00447184 8E240004 */  lw         $a0, 0x4($s1)
    /* 1B5188 00447188 8E250008 */  lw         $a1, 0x8($s1)
    /* 1B518C 0044718C 0C0AF654 */  jal        __osContRamWrite
    /* 1B5190 00447190 02603821 */   addu      $a3, $s3, $zero
    /* 1B5194 00447194 14400004 */  bnez       $v0, .L004471A8
    /* 1B5198 00447198 26100001 */   addiu     $s0, $s0, 0x1
    /* 1B519C 0044719C 2A020008 */  slti       $v0, $s0, 0x8
    /* 1B51A0 004471A0 1440FFF6 */  bnez       $v0, .L0044717C
    /* 1B51A4 004471A4 02503021 */   addu      $a2, $s2, $s0
  .L004471A8:
    /* 1B51A8 004471A8 A2200065 */  sb         $zero, 0x65($s1)
    /* 1B51AC 004471AC 0C112645 */  jal        __osPfsSelectBank
    /* 1B51B0 004471B0 02202021 */   addu      $a0, $s1, $zero
  .L004471B4:
    /* 1B51B4 004471B4 8FBF0028 */  lw         $ra, 0x28($sp)
    /* 1B51B8 004471B8 8FB30024 */  lw         $s3, 0x24($sp)
    /* 1B51BC 004471BC 8FB20020 */  lw         $s2, 0x20($sp)
    /* 1B51C0 004471C0 8FB1001C */  lw         $s1, 0x1C($sp)
    /* 1B51C4 004471C4 8FB00018 */  lw         $s0, 0x18($sp)
    /* 1B51C8 004471C8 03E00008 */  jr         $ra
    /* 1B51CC 004471CC 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_00447140
