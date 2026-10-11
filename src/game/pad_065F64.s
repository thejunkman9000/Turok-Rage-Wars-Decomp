.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x65F64 */
glabel pad_065F64
    /* 65F64 */  .word      0x240200CA
    /* 65F68 */  .word      0x1462002F
    /* 65F6C */  .word      0x24020001
endlabel pad_065F64
