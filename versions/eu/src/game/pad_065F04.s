.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x65F04 */
glabel pad_065F04
    /* 65F04 */  .word      0xAFA5001C
    /* 65F08 */  .word      0xAFA60020
    /* 65F0C */  .word      0xAFA70024
endlabel pad_065F04
