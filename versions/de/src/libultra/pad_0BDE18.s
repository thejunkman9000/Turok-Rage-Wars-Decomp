.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDE18 */
glabel pad_0BDE18
    /* BDE18 */  .word      0x03E00008
    /* BDE1C */  .word      0x00000000
endlabel pad_0BDE18
