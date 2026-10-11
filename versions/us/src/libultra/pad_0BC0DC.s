.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC0DC */
glabel pad_0BC0DC
    /* BC0DC */  .word      0x001C0000
endlabel pad_0BC0DC
