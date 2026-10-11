.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13DD8 */
glabel pad_013DD8
    /* 13DD8 */  .word      0x52000030
    /* 13DDC */  .word      0x07000010
endlabel pad_013DD8
