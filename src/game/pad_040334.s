.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x40334 */
glabel pad_040334
    /* 40334 */  .word      0x2C420002
    /* 40338 */  .word      0x10400059
    /* 4033C */  .word      0x00609021
endlabel pad_040334
