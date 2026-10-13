.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE138-0xAE148 (VRAM 0x002AD538) */
.globl padding_002B2368
padding_002B2368:
    /* AE138 002AD538 080AA151 */  .word 0x080AA151
    /* AE13C 002AD53C 02602821 */  addu      $a1, $s3, $zero
    /* AE140 002AD540 03E00008 */  jr         $ra
    /* AE144 002AD544 00000000 */  nop
