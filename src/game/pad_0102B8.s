.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x102B8 */
glabel pad_0102B8
    /* 102B8 */  .word      0x8FB60028
    /* 102BC */  .word      0x8FB50024
endlabel pad_0102B8
