.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB81DC */
glabel pad_0B81DC
    /* B81DC */  .word      0x8C820008
endlabel pad_0B81DC
