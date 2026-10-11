.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x46918 */
glabel pad_046918
    /* 46918 */  .word      0xAFA00010
    /* 4691C */  .word      0xAFA00014
endlabel pad_046918
