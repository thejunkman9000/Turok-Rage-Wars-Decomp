.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2D70-0xC2E40 (VRAM 0x002C2170) */
glabel __osProbeTLB
    /* C2D70 002C2170 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* C2D74 002C2174 00000000 */  nop
    /* C2D78 002C2178 310900FF */  andi       $t1, $t0, 0xFF
    /* C2D7C 002C217C 2401E000 */  addiu      $at, $zero, -0x2000
    /* C2D80 002C2180 00815024 */  and        $t2, $a0, $at
    /* C2D84 002C2184 012A4825 */  or         $t1, $t1, $t2
    /* C2D88 002C2188 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* C2D8C 002C218C 00000000 */  nop
    /* C2D90 002C2190 00000000 */  nop
    /* C2D94 002C2194 00000000 */  nop
    /* C2D98 002C2198 42000008 */  tlbp /* handwritten instruction */
    /* C2D9C 002C219C 00000000 */  nop
    /* C2DA0 002C21A0 00000000 */  nop
    /* C2DA4 002C21A4 400B0000 */  mfc0       $t3, $0 /* handwritten instruction */
    /* C2DA8 002C21A8 00000000 */  nop
    /* C2DAC 002C21AC 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* C2DB0 002C21B0 01615824 */  and        $t3, $t3, $at
    /* C2DB4 002C21B4 1560001C */  bnez       $t3, .L002C2228
    /* C2DB8 002C21B8 00000000 */   nop
    /* C2DBC 002C21BC 42000001 */  tlbr /* handwritten instruction */
    /* C2DC0 002C21C0 00000000 */  nop
    /* C2DC4 002C21C4 00000000 */  nop
    /* C2DC8 002C21C8 00000000 */  nop
    /* C2DCC 002C21CC 400B2800 */  mfc0       $t3, $5 /* handwritten instruction */
    /* C2DD0 002C21D0 00000000 */  nop
    /* C2DD4 002C21D4 216B2000 */  addi       $t3, $t3, 0x2000 /* handwritten instruction */
    /* C2DD8 002C21D8 000B5842 */  srl        $t3, $t3, 1
    /* C2DDC 002C21DC 01646024 */  and        $t4, $t3, $a0
    /* C2DE0 002C21E0 15800004 */  bnez       $t4, .L002C21F4
    /* C2DE4 002C21E4 216BFFFF */   addi      $t3, $t3, -0x1 /* handwritten instruction */
    /* C2DE8 002C21E8 40021000 */  mfc0       $v0, $2 /* handwritten instruction */
    /* C2DEC 002C21EC 04010002 */  bgez       $zero, .L002C21F8
    /* C2DF0 002C21F0 00000000 */   nop
  .L002C21F4:
    /* C2DF4 002C21F4 40021800 */  mfc0       $v0, $3 /* handwritten instruction */
  .L002C21F8:
    /* C2DF8 002C21F8 00000000 */  nop
    /* C2DFC 002C21FC 304D0002 */  andi       $t5, $v0, 0x2
    /* C2E00 002C2200 11A00009 */  beqz       $t5, .L002C2228
    /* C2E04 002C2204 00000000 */   nop
    /* C2E08 002C2208 3C013FFF */  lui        $at, (0x3FFFFFC0 >> 16)
    /* C2E0C 002C220C 3421FFC0 */  ori        $at, $at, (0x3FFFFFC0 & 0xFFFF)
    /* C2E10 002C2210 00411024 */  and        $v0, $v0, $at
    /* C2E14 002C2214 00021180 */  sll        $v0, $v0, 6
    /* C2E18 002C2218 008B6824 */  and        $t5, $a0, $t3
    /* C2E1C 002C221C 004D1020 */  add        $v0, $v0, $t5 /* handwritten instruction */
    /* C2E20 002C2220 04010002 */  bgez       $zero, .L002C222C
    /* C2E24 002C2224 00000000 */   nop
  .L002C2228:
    /* C2E28 002C2228 2402FFFF */  addiu      $v0, $zero, -0x1
  .L002C222C:
    /* C2E2C 002C222C 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* C2E30 002C2230 03E00008 */  jr         $ra
    /* C2E34 002C2234 00000000 */   nop


    /* C2E38 002C2238 24840008 */  .word      0x24840008 /* linker padding */
    /* C2E3C 002C223C 00002021 */  .word      0x00002021 /* linker padding */
endlabel __osProbeTLB
