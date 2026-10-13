.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xADD9C-0xADDA0 (VRAM 0x002AD19C) */
.globl D_auto_002AD19C
D_auto_002AD19C:
    /* ADD9C 002AD19C 5F437572 */  .word 0x5F437572
