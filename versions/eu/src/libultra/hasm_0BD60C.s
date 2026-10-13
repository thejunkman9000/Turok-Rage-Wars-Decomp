.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBD60C-0xBD620 (VRAM 0x002BCA0C) */
.globl __osCleanupThread
__osCleanupThread:
    /* BD60C 002BCA0C 0C0AF430 */  jal        osDestroyThread
    /* BD610 002BCA10 00002021 */  addu      $a0, $zero, $zero
    /* BD614 002BCA14 241200FF */  addiu      $s2, $zero, 0xFF
    /* BD618 002BCA18 1052001D */  .word 0x1052001D
    /* BD61C 002BCA1C 00000000 */  nop
