.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3410-0xB3438 (VRAM 0x002B2810) */
glabel func_002B2810
    /* B3410 002B2810 01C84024 */  and        $t0, $t6, $t0
    /* B3414 002B2814 01E97822 */  sub        $t7, $t7, $t1 /* handwritten instruction */
    /* B3418 002B2818 05E10005 */  bgez       $t7, .L002B2830
    /* B341C 002B281C 00000000 */   nop
    /* B3420 002B2820 03E0C821 */  addu       $t9, $ra, $zero
    /* B3424 002B2824 0C0ACA0E */  jal        func_002B2838
    /* B3428 002B2828 00000000 */   nop
    /* B342C 002B282C 0320F821 */  addu       $ra, $t9, $zero
  .L002B2830:
    /* B3430 002B2830 03E00008 */  jr         $ra
    /* B3434 002B2834 012E7006 */   srlv      $t6, $t6, $t1
endlabel func_002B2810
