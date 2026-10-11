.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE2C4 */
glabel pad_0BE2C4
    /* BE2C4 */  .word      0x8C680000
    /* BE2C8 */  .word      0x8C690004
    /* BE2CC */  .word      0x8C6A0008
endlabel pad_0BE2C4
