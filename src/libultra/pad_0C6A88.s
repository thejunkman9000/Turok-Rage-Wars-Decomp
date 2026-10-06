.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC6A88 */
glabel pad_0C6A88
    /* C6A88 */  .word      0xBF800000
    /* C6A8C */  .word      0xBF800000
endlabel pad_0C6A88
