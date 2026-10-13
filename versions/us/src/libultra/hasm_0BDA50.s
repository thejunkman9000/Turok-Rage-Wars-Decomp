.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDA50-0xBDA60 (VRAM 0x002BCE50) */
.globl __osGetSR
__osGetSR:
    /* BDA50 002BCE50 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* BDA54 002BCE54 03E00008 */  jr         $ra
    /* BDA58 002BCE58 00000000 */  nop
.globl D_auto_002BCE5C
D_auto_002BCE5C:
    /* BDA5C 002BCE5C 002A0000 */  .word 0x002A0000
