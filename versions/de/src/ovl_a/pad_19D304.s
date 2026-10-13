.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19D304 */
glabel pad_19D304
    /* 19D304 */  .word      0x3C03800E
    /* 19D308 */  .word      0x8C631720
    /* 19D30C */  .word      0x00002821
endlabel pad_19D304
