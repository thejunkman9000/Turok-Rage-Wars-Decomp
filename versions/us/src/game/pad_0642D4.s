.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x642D4 */
glabel pad_0642D4
    /* 642D4 */  .word      0x4C455F49
    /* 642D8 */  .word      0x4D504143
    /* 642DC */  .word      0x54535F41
endlabel pad_0642D4
