.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDA30-0xBDA4C (VRAM 0x002BCE30) */
.globl osGetCount
osGetCount:
    /* BDA30 002BCE30 40024800 */  mfc0       $v0, $9 /* handwritten instruction */
    /* BDA34 002BCE34 03E00008 */  jr         $ra
    /* BDA38 002BCE38 00000000 */  nop
.globl D_auto_002BCE3C
D_auto_002BCE3C:
    /* BDA3C 002BCE3C 4D61785A */  .word 0x4D61785A
.globl __osGetFpcCsr
__osGetFpcCsr:
    /* BDA40 002BCE40 4442F800 */  cfc1       $v0, $31
    /* BDA44 002BCE44 03E00008 */  jr         $ra
    /* BDA48 002BCE48 00000000 */  nop
