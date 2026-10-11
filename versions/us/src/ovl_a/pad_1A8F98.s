.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A8F98 */
glabel pad_1A8F98
    /* 1A8F98 */  .word      0x0000000F
    /* 1A8F9C */  .word      0x534D5F41
endlabel pad_1A8F98
