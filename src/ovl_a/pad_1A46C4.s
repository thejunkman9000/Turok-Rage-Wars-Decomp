.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A46C4 */
glabel pad_1A46C4
    /* 1A46C4 */  .word      0x8CA2000C
    /* 1A46C8 */  .word      0x2442FFFF
    /* 1A46CC */  .word      0x1C40001D
endlabel pad_1A46C4
