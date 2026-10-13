.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18EF98 */
glabel pad_18EF98
    /* 18EF98 */  .word      0x0C0A6682
    /* 18EF9C */  .word      0x00000000
endlabel pad_18EF98
