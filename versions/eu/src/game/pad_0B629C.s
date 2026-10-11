.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB629C */
glabel pad_0B629C
    /* B629C */  .word      0xA6020030
endlabel pad_0B629C
