.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEAB4 */
glabel pad_0BEAB4
    /* BEAB4 */  .word      0x0C0B032C
    /* BEAB8 */  .word      0x00000000
    /* BEABC */  .word      0xAE020010
endlabel pad_0BEAB4
