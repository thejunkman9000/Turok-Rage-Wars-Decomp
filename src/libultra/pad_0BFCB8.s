.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFCB8 */
glabel pad_0BFCB8
    /* BFCB8 */  .word      0x00053FC2
    /* BFCBC */  .word      0x00471025
endlabel pad_0BFCB8
