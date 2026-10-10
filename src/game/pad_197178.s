.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x197178 */
glabel pad_197178
    /* 197178 */  .word      0x24840308
    /* 19717C */  .word      0x8FA50050
endlabel pad_197178
