.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0398 */
glabel pad_0C0398
    /* C0398 */  .word      0x8FB00010
    /* C039C */  .word      0x03E00008
endlabel pad_0C0398
