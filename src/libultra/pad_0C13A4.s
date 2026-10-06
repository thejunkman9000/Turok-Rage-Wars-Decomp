.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC13A4 */
glabel pad_0C13A4
    /* C13A4 */  .word      0xD7580190
    /* C13A8 */  .word      0xD75A0198
    /* C13AC */  .word      0xD75C01A0
endlabel pad_0C13A4
