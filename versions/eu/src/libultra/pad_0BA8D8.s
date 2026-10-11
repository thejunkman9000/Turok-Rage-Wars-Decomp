.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA8D8 */
glabel pad_0BA8D8
    /* BA8D8 */  .word      0xA617001C
    /* BA8DC */  .word      0x8602001E
endlabel pad_0BA8D8
