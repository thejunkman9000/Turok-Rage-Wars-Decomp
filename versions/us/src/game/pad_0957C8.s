.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x957C8 */
glabel pad_0957C8
    /* 957C8 */  .word      0x0000003C
    /* 957CC */  .word      0x010000AC
endlabel pad_0957C8
