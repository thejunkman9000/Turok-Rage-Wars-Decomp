.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x915D8 */
glabel pad_0915D8
    /* 915D8 */  .word      0x3C028014
    /* 915DC */  .word      0x24426980
endlabel pad_0915D8
