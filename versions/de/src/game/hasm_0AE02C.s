.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE02C-0xAE0B4 (VRAM 0x002AD42C) */
.globl osReadAllTLBEntries
osReadAllTLBEntries:
    /* AE02C 002AD42C 00001020 */  add        $v0, $zero, $zero /* handwritten instruction */
    /* AE030 002AD430 2005001E */  addi       $a1, $zero, 0x1E /* handwritten instruction */
    /* AE034 002AD434 3C04800D */  lui        $a0, %hi(D_auto_800D3F70)
    /* AE038 002AD438 24843F70 */  addiu      $a0, $a0, %lo(D_auto_800D3F70)
    /* AE03C 002AD43C 2006014E */  addi       $a2, $zero, 0x14E /* handwritten instruction */
.Lauto_002AD440:
    /* AE040 002AD440 40820000 */  mtc0       $v0, $0 /* handwritten instruction */
    /* AE044 002AD444 42000001 */  tlbr /* handwritten instruction */
    /* AE048 002AD448 00000000 */  nop
    /* AE04C 002AD44C 00000000 */  nop
    /* AE050 002AD450 00000000 */  nop
    /* AE054 002AD454 00000000 */  nop
    /* AE058 002AD458 40032800 */  mfc0       $v1, $5 /* handwritten instruction */
    /* AE05C 002AD45C 00000000 */  nop
    /* AE060 002AD460 00031B42 */  srl        $v1, $v1, 13
    /* AE064 002AD464 A4830000 */  sh         $v1, 0x0($a0)
    /* AE068 002AD468 40035000 */  mfc0       $v1, $10 /* handwritten instruction */
    /* AE06C 002AD46C 00000000 */  nop
    /* AE070 002AD470 00031B02 */  srl        $v1, $v1, 12
    /* AE074 002AD474 A4830002 */  sh         $v1, 0x2($a0)
    /* AE078 002AD478 40031000 */  mfc0       $v1, $2 /* handwritten instruction */
    /* AE07C 002AD47C 00000000 */  nop
    /* AE080 002AD480 00031982 */  srl        $v1, $v1, 6
    /* AE084 002AD484 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* AE088 002AD488 A4830004 */  sh         $v1, 0x4($a0)
    /* AE08C 002AD48C 40031800 */  mfc0       $v1, $3 /* handwritten instruction */
    /* AE090 002AD490 00000000 */  nop
    /* AE094 002AD494 00031982 */  srl        $v1, $v1, 6
    /* AE098 002AD498 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* AE09C 002AD49C A4830006 */  sh         $v1, 0x6($a0)
    /* AE0A0 002AD4A0 20840008 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* AE0A4 002AD4A4 14A2FFE6 */  .word 0x14A2FFE6
    /* AE0A8 002AD4A8 20420001 */  addi      $v0, $v0, 0x1 /* handwritten instruction */
    /* AE0AC 002AD4AC 03E00008 */  jr         $ra
    /* AE0B0 002AD4B0 00000000 */  nop
