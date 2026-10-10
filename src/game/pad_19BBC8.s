.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19BBC8 */
glabel pad_19BBC8
    /* 19BBC8 */  .word      0x00408021
    /* 19BBCC */  .word      0x0C0A848E
endlabel pad_19BBC8
