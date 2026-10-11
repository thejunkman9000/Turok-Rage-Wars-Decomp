.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA30FC */
glabel pad_0A30FC
    /* A30FC */  .word      0x41445F52
endlabel pad_0A30FC
