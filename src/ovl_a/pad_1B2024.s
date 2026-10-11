.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B2024 */
glabel pad_1B2024
    /* 1B2024 */  .word      0x8CA50058
    /* 1B2028 */  .word      0x10A0006A
    /* 1B202C */  .word      0x00000000
endlabel pad_1B2024
