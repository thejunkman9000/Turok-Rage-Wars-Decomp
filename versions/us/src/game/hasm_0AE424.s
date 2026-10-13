.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE424-0xAE470 (VRAM 0x002AD824) */
.globl dbgSetWatchpoint
dbgSetWatchpoint:
    /* AE424 002AD824 00042100 */  sll        $a0, $a0, 4
    /* AE428 002AD828 00042102 */  srl        $a0, $a0, 4
    /* AE42C 002AD82C 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* AE430 002AD830 00442024 */  and        $a0, $v0, $a0
    /* AE434 002AD834 30A50003 */  andi       $a1, $a1, 0x3
    /* AE438 002AD838 00A42025 */  or         $a0, $a1, $a0
    /* AE43C 002AD83C 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* AE440 002AD840 00000000 */  nop
    /* AE444 002AD844 00000000 */  nop
    /* AE448 002AD848 00000000 */  nop
    /* AE44C 002AD84C 00000000 */  nop
    /* AE450 002AD850 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* AE454 002AD854 00000000 */  nop
    /* AE458 002AD858 00000000 */  nop
    /* AE45C 002AD85C 00000000 */  nop
    /* AE460 002AD860 03E00008 */  jr         $ra
    /* AE464 002AD864 00000000 */  nop
.globl D_auto_002AD868
D_auto_002AD868:
    /* AE468 002AD868 5F494D50 */  .word 0x5F494D50
    /* AE46C 002AD86C 41435453 */  .word 0x41435453
