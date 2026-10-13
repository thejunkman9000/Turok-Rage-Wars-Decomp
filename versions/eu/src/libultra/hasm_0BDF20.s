.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDF20-0xBDFE8 (VRAM 0x002BD320) */
.globl __osProbeTLB
__osProbeTLB:
    /* BDF20 002BD320 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BDF24 002BD324 00000000 */  nop
    /* BDF28 002BD328 310900FF */  andi       $t1, $t0, 0xFF
    /* BDF2C 002BD32C 2401E000 */  addiu      $at, $zero, -0x2000
    /* BDF30 002BD330 00815024 */  and        $t2, $a0, $at
    /* BDF34 002BD334 012A4825 */  or         $t1, $t1, $t2
    /* BDF38 002BD338 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* BDF3C 002BD33C 00000000 */  nop
    /* BDF40 002BD340 00000000 */  nop
    /* BDF44 002BD344 00000000 */  nop
    /* BDF48 002BD348 42000008 */  tlbp /* handwritten instruction */
    /* BDF4C 002BD34C 00000000 */  nop
    /* BDF50 002BD350 00000000 */  nop
    /* BDF54 002BD354 400B0000 */  mfc0       $t3, $0 /* handwritten instruction */
    /* BDF58 002BD358 00000000 */  nop
    /* BDF5C 002BD35C 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* BDF60 002BD360 01615824 */  and        $t3, $t3, $at
    /* BDF64 002BD364 1560001C */  .word 0x1560001C
    /* BDF68 002BD368 00000000 */  nop
    /* BDF6C 002BD36C 42000001 */  tlbr /* handwritten instruction */
    /* BDF70 002BD370 00000000 */  nop
    /* BDF74 002BD374 00000000 */  nop
    /* BDF78 002BD378 00000000 */  nop
    /* BDF7C 002BD37C 400B2800 */  mfc0       $t3, $5 /* handwritten instruction */
    /* BDF80 002BD380 00000000 */  nop
    /* BDF84 002BD384 216B2000 */  addi       $t3, $t3, 0x2000 /* handwritten instruction */
    /* BDF88 002BD388 000B5842 */  srl        $t3, $t3, 1
    /* BDF8C 002BD38C 01646024 */  and        $t4, $t3, $a0
    /* BDF90 002BD390 15800004 */  .word 0x15800004
    /* BDF94 002BD394 216BFFFF */  addi      $t3, $t3, -0x1 /* handwritten instruction */
    /* BDF98 002BD398 40021000 */  mfc0       $v0, $2 /* handwritten instruction */
    /* BDF9C 002BD39C 04010002 */  .word 0x04010002
    /* BDFA0 002BD3A0 00000000 */  nop
.Lauto_002BD3A4:
    /* BDFA4 002BD3A4 40021800 */  mfc0       $v0, $3 /* handwritten instruction */
.Lauto_002BD3A8:
    /* BDFA8 002BD3A8 00000000 */  nop
    /* BDFAC 002BD3AC 304D0002 */  andi       $t5, $v0, 0x2
    /* BDFB0 002BD3B0 11A00009 */  .word 0x11A00009
    /* BDFB4 002BD3B4 00000000 */  nop
    /* BDFB8 002BD3B8 3C013FFF */  lui        $at, (0x3FFFFFC0 >> 16)
    /* BDFBC 002BD3BC 3421FFC0 */  ori        $at, $at, (0x3FFFFFC0 & 0xFFFF)
    /* BDFC0 002BD3C0 00411024 */  and        $v0, $v0, $at
    /* BDFC4 002BD3C4 00021180 */  sll        $v0, $v0, 6
    /* BDFC8 002BD3C8 008B6824 */  and        $t5, $a0, $t3
    /* BDFCC 002BD3CC 004D1020 */  add        $v0, $v0, $t5 /* handwritten instruction */
    /* BDFD0 002BD3D0 04010002 */  .word 0x04010002
    /* BDFD4 002BD3D4 00000000 */  nop
.Lauto_002BD3D8:
    /* BDFD8 002BD3D8 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BD3DC:
    /* BDFDC 002BD3DC 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BDFE0 002BD3E0 03E00008 */  jr         $ra
    /* BDFE4 002BD3E4 00000000 */  nop
