.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB76A8 */
glabel pad_0B76A8
    /* B76A8 */  .word      0x4F444552
    /* B76AC */  .word      0x00000100
endlabel pad_0B76A8
