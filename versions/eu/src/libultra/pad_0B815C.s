.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB815C */
glabel pad_0B815C
    /* B815C */  .word      0x8CA20000
endlabel pad_0B815C
