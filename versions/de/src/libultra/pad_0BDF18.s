.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDF18 */
glabel pad_0BDF18
    /* BDF18 */  .word      0xAFA7000C
    /* BDF1C */  .word      0x27BDFFE8
endlabel pad_0BDF18
