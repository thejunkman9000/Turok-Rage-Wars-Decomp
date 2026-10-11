.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x96784 */
glabel pad_096784
    /* 96784 */  .word      0x12000067
    /* 96788 */  .word      0x3C02E700
    /* 9678C */  .word      0x3C078011
endlabel pad_096784
