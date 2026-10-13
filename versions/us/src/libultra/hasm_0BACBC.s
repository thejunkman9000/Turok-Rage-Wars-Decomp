.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBACBC-0xBACC0 (VRAM 0x002BA0BC) */
.globl D_auto_002BA0BC
D_auto_002BA0BC:
    /* BACBC 002BA0BC 5F624475 */  .word 0x5F624475
