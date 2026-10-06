.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0A58 */
glabel pad_0C0A58
    /* C0A58 */  .word      0x3369FF00
    /* C0A5C */  .word      0x11200014
endlabel pad_0C0A58
