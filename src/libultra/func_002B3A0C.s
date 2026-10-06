.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB460C-0xB4680 (VRAM 0x002B3A0C) */
glabel func_002B3A0C
    /* B460C 002B3A0C 00804821 */  addu       $t1, $a0, $zero
    /* B4610 002B3A10 8D220004 */  lw         $v0, 0x4($t1)
    /* B4614 002B3A14 00004021 */  addu       $t0, $zero, $zero
    /* B4618 002B3A18 ACA20000 */  sw         $v0, 0x0($a1)
    /* B461C 002B3A1C 8D22000C */  lw         $v0, 0xC($t1)
    /* B4620 002B3A20 01203821 */  addu       $a3, $t1, $zero
    /* B4624 002B3A24 ACA20004 */  sw         $v0, 0x4($a1)
    /* B4628 002B3A28 8D220010 */  lw         $v0, 0x10($t1)
    /* B462C 002B3A2C 00A03021 */  addu       $a2, $a1, $zero
    /* B4630 002B3A30 ACA20008 */  sw         $v0, 0x8($a1)
  .L002B3A34:
    /* B4634 002B3A34 8CE20018 */  lw         $v0, 0x18($a3)
    /* B4638 002B3A38 ACC2000C */  sw         $v0, 0xC($a2)
    /* B463C 002B3A3C 8CE20058 */  lw         $v0, 0x58($a3)
    /* B4640 002B3A40 01281821 */  addu       $v1, $t1, $t0
    /* B4644 002B3A44 ACC2004C */  sw         $v0, 0x4C($a2)
    /* B4648 002B3A48 90620098 */  lbu        $v0, 0x98($v1)
    /* B464C 002B3A4C 00A82021 */  addu       $a0, $a1, $t0
    /* B4650 002B3A50 A082008C */  sb         $v0, 0x8C($a0)
    /* B4654 002B3A54 906200A8 */  lbu        $v0, 0xA8($v1)
    /* B4658 002B3A58 25080001 */  addiu      $t0, $t0, 0x1
    /* B465C 002B3A5C A082009C */  sb         $v0, 0x9C($a0)
    /* B4660 002B3A60 8CE200B8 */  lw         $v0, 0xB8($a3)
    /* B4664 002B3A64 24E70004 */  addiu      $a3, $a3, 0x4
    /* B4668 002B3A68 ACC200AC */  sw         $v0, 0xAC($a2)
    /* B466C 002B3A6C 29020010 */  slti       $v0, $t0, 0x10
    /* B4670 002B3A70 1440FFF0 */  bnez       $v0, .L002B3A34
    /* B4674 002B3A74 24C60004 */   addiu     $a2, $a2, 0x4
    /* B4678 002B3A78 03E00008 */  jr         $ra
    /* B467C 002B3A7C 00000000 */   nop
endlabel func_002B3A0C
