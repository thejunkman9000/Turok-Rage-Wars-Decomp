.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA8A8 */
glabel pad_0BA8A8
    /* BA8A8 */  .word      0x00808821
    /* BA8AC */  .word      0xAFB00010
endlabel pad_0BA8A8
