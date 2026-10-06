.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0F84 */
glabel pad_0C0F84
    /* C0F84 */  .word      0x016C082A
    /* C0F88 */  .word      0x10200024
    /* C0F8C */  .word      0x00000000
endlabel pad_0C0F84
