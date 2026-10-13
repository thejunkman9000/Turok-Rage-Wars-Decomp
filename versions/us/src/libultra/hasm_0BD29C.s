.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBD29C-0xBD2B0 (VRAM 0x002BC69C) */
.globl __osCleanupThread
__osCleanupThread:
    /* BD29C 002BC69C 0C0AF354 */  .word 0x0C0AF354
    /* BD2A0 002BC6A0 00002021 */  .word 0x00002021
    /* BD2A4 002BC6A4 00000000 */  .word 0x00000000
    /* BD2A8 002BC6A8 00134348 */  .word 0x00134348
    /* BD2AC 002BC6AC 65616C74 */  .word 0x65616C74
