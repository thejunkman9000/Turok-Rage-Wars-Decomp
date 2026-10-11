.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x198728 */
glabel pad_198728
    /* 198728 */  .word      0xAC6200DC
    /* 19872C */  .word      0x3C02800F
endlabel pad_198728
