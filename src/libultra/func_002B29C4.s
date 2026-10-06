.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB35C4-0xB3610 (VRAM 0x002B29C4) */
glabel func_002B29C4
    /* B35C4 002B29C4 00042100 */  sll        $a0, $a0, 4
    /* B35C8 002B29C8 00042102 */  srl        $a0, $a0, 4
    /* B35CC 002B29CC 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* B35D0 002B29D0 00442024 */  and        $a0, $v0, $a0
    /* B35D4 002B29D4 30A50003 */  andi       $a1, $a1, 0x3
    /* B35D8 002B29D8 00A42025 */  or         $a0, $a1, $a0
    /* B35DC 002B29DC 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* B35E0 002B29E0 00000000 */  nop
    /* B35E4 002B29E4 00000000 */  nop
    /* B35E8 002B29E8 00000000 */  nop
    /* B35EC 002B29EC 00000000 */  nop
    /* B35F0 002B29F0 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* B35F4 002B29F4 00000000 */  nop
    /* B35F8 002B29F8 00000000 */  nop
    /* B35FC 002B29FC 00000000 */  nop
    /* B3600 002B2A00 03E00008 */  jr         $ra
    /* B3604 002B2A04 00000000 */   nop
    /* B3608 002B2A08 00000000 */  .word      0x00000000 /* linker padding */


    /* B360C 002B2A0C 00804821 */  .word      0x00804821 /* linker padding */
endlabel func_002B29C4
