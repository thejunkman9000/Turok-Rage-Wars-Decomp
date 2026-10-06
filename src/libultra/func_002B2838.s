.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3438-0xB3470 (VRAM 0x002B2838) */
glabel func_002B2838
    /* B3438 002B2838 01E97820 */  add        $t7, $t7, $t1 /* handwritten instruction */
    /* B343C 002B283C 01EE7006 */  srlv       $t6, $t6, $t7
    /* B3440 002B2840 22730004 */  addi       $s3, $s3, 0x4 /* handwritten instruction */
    /* B3444 002B2844 9261FFFE */  lbu        $at, -0x2($s3)
    /* B3448 002B2848 9262FFFF */  lbu        $v0, -0x1($s3)
    /* B344C 002B284C 2273FFFE */  addi       $s3, $s3, -0x2 /* handwritten instruction */
    /* B3450 002B2850 00010C00 */  sll        $at, $at, 16
    /* B3454 002B2854 00021600 */  sll        $v0, $v0, 24
    /* B3458 002B2858 01C27025 */  or         $t6, $t6, $v0
    /* B345C 002B285C 01C17025 */  or         $t6, $t6, $at
    /* B3460 002B2860 012F4822 */  sub        $t1, $t1, $t7 /* handwritten instruction */
    /* B3464 002B2864 200F0010 */  addi       $t7, $zero, 0x10 /* handwritten instruction */
    /* B3468 002B2868 03E00008 */  jr         $ra
    /* B346C 002B286C 01E97822 */   sub       $t7, $t7, $t1 /* handwritten instruction */
endlabel func_002B2838
