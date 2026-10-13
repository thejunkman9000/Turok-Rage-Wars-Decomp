.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19DA48 */
glabel pad_19DA48
    /* 19DA48 */  .word      0x24050067
    /* 19DA4C */  .word      0x00003021
endlabel pad_19DA48
