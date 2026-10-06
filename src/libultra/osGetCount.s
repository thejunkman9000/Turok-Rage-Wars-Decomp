.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2BF0-0xC2C00 (VRAM 0x002C1FF0) */
glabel osGetCount
    /* C2BF0 002C1FF0 40024800 */  mfc0       $v0, $9 /* handwritten instruction */
    /* C2BF4 002C1FF4 03E00008 */  jr         $ra
    /* C2BF8 002C1FF8 00000000 */   nop
    /* C2BFC 002C1FFC 8EB30004 */  .word      0x8EB30004 /* linker padding */
endlabel osGetCount
