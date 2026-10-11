.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19BB08 */
glabel pad_19BB08
    /* 19BB08 */  .word      0x24040014
    /* 19BB0C */  .word      0x2404FFFF
endlabel pad_19BB08
