.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AE878 */
glabel pad_1AE878
    /* 1AE878 */  .word      0x3C02800F
    /* 1AE87C */  .word      0x8C421AC4
endlabel pad_1AE878
