.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x77894 */
glabel pad_077894
    /* 77894 */  .word      0x0000960D
    /* 77898 */  .word      0x00080018
    /* 7789C */  .word      0x00000000
endlabel pad_077894
