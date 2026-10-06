.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB99E0-0xB9A88 (VRAM 0x002B8DE0) */
glabel func_002B8DE0
    /* B99E0 002B8DE0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B99E4 002B8DE4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B99E8 002B8DE8 00808821 */  addu       $s1, $a0, $zero
    /* B99EC 002B8DEC AFB20018 */  sw         $s2, 0x18($sp)
    /* B99F0 002B8DF0 00A09021 */  addu       $s2, $a1, $zero
    /* B99F4 002B8DF4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B99F8 002B8DF8 3C107FFF */  lui        $s0, (0x7FFFFFFF >> 16)
    /* B99FC 002B8DFC AFBF001C */  sw         $ra, 0x1C($sp)
    /* B9A00 002B8E00 8E220000 */  lw         $v0, 0x0($s1)
    /* B9A04 002B8E04 14400007 */  bnez       $v0, .L002B8E24
    /* B9A08 002B8E08 3610FFFF */   ori       $s0, $s0, (0x7FFFFFFF & 0xFFFF)
    /* B9A0C 002B8E0C 3C04800D */  lui        $a0, %hi(D_800CC7C0)
    /* B9A10 002B8E10 2484C7C0 */  addiu      $a0, $a0, %lo(D_800CC7C0)
    /* B9A14 002B8E14 3C05800D */  lui        $a1, %hi(D_800CC7C4)
    /* B9A18 002B8E18 24A5C7C4 */  addiu      $a1, $a1, %lo(D_800CC7C4)
    /* B9A1C 002B8E1C 0C0AFF50 */  jal        __assert
    /* B9A20 002B8E20 24060133 */   addiu     $a2, $zero, 0x133
  .L002B8E24:
    /* B9A24 002B8E24 AE400000 */  sw         $zero, 0x0($s2)
    /* B9A28 002B8E28 8E240000 */  lw         $a0, 0x0($s1)
    /* B9A2C 002B8E2C 1080000E */  beqz       $a0, .L002B8E68
    /* B9A30 002B8E30 00000000 */   nop
  .L002B8E34:
    /* B9A34 002B8E34 8C820010 */  lw         $v0, 0x10($a0)
    /* B9A38 002B8E38 8E230020 */  lw         $v1, 0x20($s1)
    /* B9A3C 002B8E3C 00431023 */  subu       $v0, $v0, $v1
    /* B9A40 002B8E40 0050102A */  slt        $v0, $v0, $s0
    /* B9A44 002B8E44 10400005 */  beqz       $v0, .L002B8E5C
    /* B9A48 002B8E48 00000000 */   nop
    /* B9A4C 002B8E4C AE440000 */  sw         $a0, 0x0($s2)
    /* B9A50 002B8E50 8C830010 */  lw         $v1, 0x10($a0)
    /* B9A54 002B8E54 8E220020 */  lw         $v0, 0x20($s1)
    /* B9A58 002B8E58 00628023 */  subu       $s0, $v1, $v0
  .L002B8E5C:
    /* B9A5C 002B8E5C 8C840000 */  lw         $a0, 0x0($a0)
    /* B9A60 002B8E60 1480FFF4 */  bnez       $a0, .L002B8E34
    /* B9A64 002B8E64 00000000 */   nop
  .L002B8E68:
    /* B9A68 002B8E68 8E420000 */  lw         $v0, 0x0($s2)
    /* B9A6C 002B8E6C 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B9A70 002B8E70 8FB20018 */  lw         $s2, 0x18($sp)
    /* B9A74 002B8E74 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9A78 002B8E78 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9A7C 002B8E7C 8C420010 */  lw         $v0, 0x10($v0)
    /* B9A80 002B8E80 03E00008 */  jr         $ra
    /* B9A84 002B8E84 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B8DE0
