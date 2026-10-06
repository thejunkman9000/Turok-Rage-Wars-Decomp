.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9AC4 */
glabel pad_0B9AC4
    /* B9AC4 */  .word      0x00021040
    /* B9AC8 */  .word      0x8623001A
    /* B9ACC */  .word      0x3C01800E
endlabel pad_0B9AC4
