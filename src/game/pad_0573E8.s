.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x573E8 */
glabel pad_0573E8
    /* 573E8 */  .word      0x24050001
    /* 573EC */  .word      0x0C0A3F65
endlabel pad_0573E8
