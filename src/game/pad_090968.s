.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x90968 */
glabel pad_090968
    /* 90968 */  .word      0x3C020030
    /* 9096C */  .word      0xAD140008
endlabel pad_090968
