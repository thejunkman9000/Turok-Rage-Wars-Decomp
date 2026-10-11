.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13DF8 */
glabel pad_013DF8
    /* 13DF8 */  .word      0x8E020030
    /* 13DFC */  .word      0x460005C6
endlabel pad_013DF8
