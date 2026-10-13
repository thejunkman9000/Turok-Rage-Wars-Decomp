.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1C5224 */
glabel pad_1C5224
    /* 1C5224 */  .word      0xA223060B
    /* 1C5228 */  .word      0xA2230608
    /* 1C522C */  .word      0xA2230616
endlabel pad_1C5224
