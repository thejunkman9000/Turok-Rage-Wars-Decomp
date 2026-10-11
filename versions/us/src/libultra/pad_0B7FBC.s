.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7FBC */
glabel pad_0B7FBC
    /* B7FBC */  .word      0x72616374
endlabel pad_0B7FBC
