.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x182428 */
glabel pad_182428
    /* 182428 */  .word      0x0810562E
    /* 18242C */  .word      0x02403821
endlabel pad_182428
