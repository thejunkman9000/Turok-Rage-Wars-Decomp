.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE4F4-0xAE538 (VRAM 0x002AD8F4) */
.globl dbgSetWatchpoint
dbgSetWatchpoint:
    /* AE4F4 002AD8F4 00042100 */  sll        $a0, $a0, 4
    /* AE4F8 002AD8F8 00042102 */  srl        $a0, $a0, 4
    /* AE4FC 002AD8FC 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* AE500 002AD900 00442024 */  and        $a0, $v0, $a0
    /* AE504 002AD904 30A50003 */  andi       $a1, $a1, 0x3
    /* AE508 002AD908 00A42025 */  or         $a0, $a1, $a0
    /* AE50C 002AD90C 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* AE510 002AD910 00000000 */  nop
    /* AE514 002AD914 00000000 */  nop
    /* AE518 002AD918 00000000 */  nop
    /* AE51C 002AD91C 00000000 */  nop
    /* AE520 002AD920 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* AE524 002AD924 00000000 */  nop
    /* AE528 002AD928 00000000 */  nop
    /* AE52C 002AD92C 00000000 */  nop
    /* AE530 002AD930 03E00008 */  jr         $ra
    /* AE534 002AD934 00000000 */  nop
