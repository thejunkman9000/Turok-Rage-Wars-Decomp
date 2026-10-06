.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7558-0xB7574 (VRAM 0x002B6958) */
glabel func_002B6958
    /* B7558 002B6958 8C830024 */  lw         $v1, 0x24($a0)
    /* B755C 002B695C 00651823 */  subu       $v1, $v1, $a1
    /* B7560 002B6960 04610002 */  bgez       $v1, .L002B696C
    /* B7564 002B6964 00601021 */   addu      $v0, $v1, $zero
    /* B7568 002B6968 240203E8 */  addiu      $v0, $zero, 0x3E8
  .L002B696C:
    /* B756C 002B696C 03E00008 */  jr         $ra
    /* B7570 002B6970 00000000 */   nop
endlabel func_002B6958
