.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B4A54-0x1B4B44 (VRAM 0x00446A54) */
glabel func_00446A54
    /* 1B4A54 00446A54 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* 1B4A58 00446A58 AFB3001C */  sw         $s3, 0x1C($sp)
    /* 1B4A5C 00446A5C 00809821 */  addu       $s3, $a0, $zero
    /* 1B4A60 00446A60 AFB20018 */  sw         $s2, 0x18($sp)
    /* 1B4A64 00446A64 00A09021 */  addu       $s2, $a1, $zero
    /* 1B4A68 00446A68 AFB40020 */  sw         $s4, 0x20($sp)
    /* 1B4A6C 00446A6C 00C0A021 */  addu       $s4, $a2, $zero
    /* 1B4A70 00446A70 AFB00010 */  sw         $s0, 0x10($sp)
    /* 1B4A74 00446A74 3C108014 */  lui        $s0, %hi(D_80145040)
    /* 1B4A78 00446A78 26105040 */  addiu      $s0, $s0, %lo(D_80145040)
    /* 1B4A7C 00446A7C AFBF0024 */  sw         $ra, 0x24($sp)
    /* 1B4A80 00446A80 AFB10014 */  sw         $s1, 0x14($sp)
    /* 1B4A84 00446A84 8E51001C */  lw         $s1, 0x1C($s2)
    /* 1B4A88 00446A88 02002021 */  addu       $a0, $s0, $zero
    /* 1B4A8C 00446A8C 0C08A964 */  jal        func_0022A590
    /* 1B4A90 00446A90 02202821 */   addu      $a1, $s1, $zero
    /* 1B4A94 00446A94 00021840 */  sll        $v1, $v0, 1
    /* 1B4A98 00446A98 00621821 */  addu       $v1, $v1, $v0
    /* 1B4A9C 00446A9C 000318C0 */  sll        $v1, $v1, 3
    /* 1B4AA0 00446AA0 3C04800E */  lui        $a0, %hi(D_800E63CC)
    /* 1B4AA4 00446AA4 248463CC */  addiu      $a0, $a0, %lo(D_800E63CC)
    /* 1B4AA8 00446AA8 00643021 */  addu       $a2, $v1, $a0
    /* 1B4AAC 00446AAC 00021880 */  sll        $v1, $v0, 2
    /* 1B4AB0 00446AB0 00621821 */  addu       $v1, $v1, $v0
    /* 1B4AB4 00446AB4 00031100 */  sll        $v0, $v1, 4
    /* 1B4AB8 00446AB8 00431023 */  subu       $v0, $v0, $v1
    /* 1B4ABC 00446ABC 00021040 */  sll        $v0, $v0, 1
    /* 1B4AC0 00446AC0 261013DC */  addiu      $s0, $s0, 0x13DC
    /* 1B4AC4 00446AC4 00501821 */  addu       $v1, $v0, $s0
    /* 1B4AC8 00446AC8 00002821 */  addu       $a1, $zero, $zero
    /* 1B4ACC 00446ACC 00A02021 */  addu       $a0, $a1, $zero
  .L00446AD0:
    /* 1B4AD0 00446AD0 90C20000 */  lbu        $v0, 0x0($a2)
    /* 1B4AD4 00446AD4 14400003 */  bnez       $v0, .L00446AE4
    /* 1B4AD8 00446AD8 24C60001 */   addiu     $a2, $a2, 0x1
    /* 1B4ADC 00446ADC 08111ABA */  j          .L00446AE8
    /* 1B4AE0 00446AE0 24020020 */   addiu     $v0, $zero, 0x20
  .L00446AE4:
    /* 1B4AE4 00446AE4 24A50001 */  addiu      $a1, $a1, 0x1
  .L00446AE8:
    /* 1B4AE8 00446AE8 A0620000 */  sb         $v0, 0x0($v1)
    /* 1B4AEC 00446AEC 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B4AF0 00446AF0 28820008 */  slti       $v0, $a0, 0x8
    /* 1B4AF4 00446AF4 1440FFF6 */  bnez       $v0, .L00446AD0
    /* 1B4AF8 00446AF8 24630001 */   addiu     $v1, $v1, 0x1
    /* 1B4AFC 00446AFC 14A00004 */  bnez       $a1, .L00446B10
    /* 1B4B00 00446B00 A0600000 */   sb        $zero, 0x0($v1)
    /* 1B4B04 00446B04 8E2405D8 */  lw         $a0, 0x5D8($s1)
    /* 1B4B08 00446B08 0C111098 */  jal        func_00444260
    /* 1B4B0C 00446B0C 00000000 */   nop
  .L00446B10:
    /* 1B4B10 00446B10 02602021 */  addu       $a0, $s3, $zero
    /* 1B4B14 00446B14 02402821 */  addu       $a1, $s2, $zero
    /* 1B4B18 00446B18 0C11093D */  jal        func_004424F4
    /* 1B4B1C 00446B1C 02803021 */   addu      $a2, $s4, $zero
    /* 1B4B20 00446B20 8FBF0024 */  lw         $ra, 0x24($sp)
    /* 1B4B24 00446B24 8FB40020 */  lw         $s4, 0x20($sp)
    /* 1B4B28 00446B28 8FB3001C */  lw         $s3, 0x1C($sp)
    /* 1B4B2C 00446B2C 8FB20018 */  lw         $s2, 0x18($sp)
    /* 1B4B30 00446B30 8FB10014 */  lw         $s1, 0x14($sp)
    /* 1B4B34 00446B34 8FB00010 */  lw         $s0, 0x10($sp)
    /* 1B4B38 00446B38 24020001 */  addiu      $v0, $zero, 0x1
    /* 1B4B3C 00446B3C 03E00008 */  jr         $ra
    /* 1B4B40 00446B40 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_00446A54
