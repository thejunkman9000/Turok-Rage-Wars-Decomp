.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5F1C8 */
glabel pad_05F1C8
    /* 5F1C8 */  .word      0x104001E6
    /* 5F1CC */  .word      0x00002821
endlabel pad_05F1C8
