.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3DBC8 */
glabel pad_03DBC8
    /* 3DBC8 */  .word      0xAFA00030
    /* 3DBCC */  .word      0xAFA00034
endlabel pad_03DBC8
