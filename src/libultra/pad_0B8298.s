.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8298 */
glabel pad_0B8298
    /* B8298 */  .word      0x8FB00010
    /* B829C */  .word      0x03E00008
endlabel pad_0B8298
