.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xADDC8-0xADDD8 (VRAM 0x002AD1C8) */
.globl padding_002B2368
padding_002B2368:
    /* ADDC8 002AD1C8 65520000 */  daddiu     $s2, $t2, 0x0
    /* ADDCC 002AD1CC 5F000000 */  .word 0x5F000000
.Lauto_002AD1D0:
    /* ADDD0 002AD1D0 03E00008 */  jr        $ra
    /* ADDD4 002AD1D4 00000000 */  nop
