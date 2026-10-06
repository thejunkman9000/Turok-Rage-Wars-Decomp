.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC18A4 */
glabel pad_0C18A4
    /* C18A4 */  .word      0x34630001
    /* C18A8 */  .word      0x14430012
    /* C18AC */  .word      0x00000000
endlabel pad_0C18A4
