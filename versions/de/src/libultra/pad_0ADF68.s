.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xADF68 */
glabel pad_0ADF68
    /* ADF68 */  .word      0x8FB90014
    /* ADF6C */  .word      0x200FFFFF
endlabel pad_0ADF68
