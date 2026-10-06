.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB30C0-0xB30FC (VRAM 0x002B24C0) */
glabel func_002B24C0
    /* B30C0 002B24C0 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* B30C4 002B24C4 40840000 */  mtc0       $a0, $0 /* handwritten instruction */
    /* B30C8 002B24C8 3C098000 */  lui        $t1, (0x80000000 >> 16)
    /* B30CC 002B24CC 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* B30D0 002B24D0 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* B30D4 002B24D4 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
    /* B30D8 002B24D8 00000000 */  nop
    /* B30DC 002B24DC 42000002 */  tlbwi /* handwritten instruction */
    /* B30E0 002B24E0 00000000 */  nop
    /* B30E4 002B24E4 00000000 */  nop
    /* B30E8 002B24E8 00000000 */  nop
    /* B30EC 002B24EC 00000000 */  nop
    /* B30F0 002B24F0 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* B30F4 002B24F4 03E00008 */  jr         $ra
    /* B30F8 002B24F8 00000000 */   nop
endlabel func_002B24C0
