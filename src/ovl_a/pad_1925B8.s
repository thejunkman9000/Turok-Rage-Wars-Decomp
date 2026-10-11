.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1925B8 */
glabel pad_1925B8
    /* 1925B8 */  .word      0x048000A2
    /* 1925BC */  .word      0x00001821
endlabel pad_1925B8
