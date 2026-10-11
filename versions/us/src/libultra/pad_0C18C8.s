.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC18C8 */
glabel pad_0C18C8
    /* C18C8 */  .word      0x0000000E
    /* C18CC */  .word      0x434D656E
endlabel pad_0C18C8
