.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xADE98-0xADEA8 (VRAM 0x002AD298) */
.globl padding_002B2368
padding_002B2368:
    /* ADE98 002AD298 240207CF */  addiu      $v0, $zero, 0x7CF
    /* ADE9C 002AD29C 1082000D */  .word 0x1082000D
    /* ADEA0 002AD2A0 03E00008 */  jr        $ra
    /* ADEA4 002AD2A4 00000000 */  nop
