.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17AB24 */
glabel pad_17AB24
    /* 17AB24 */  .word      0x0C0A838E
    /* 17AB28 */  .word      0x24060018
    /* 17AB2C */  .word      0x3C028015
endlabel pad_17AB24
