.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x915C4 */
glabel pad_0915C4
    /* 915C4 */  .word      0x2442CD10
    /* 915C8 */  .word      0xACC20020
    /* 915CC */  .word      0x3C02800E
endlabel pad_0915C4
