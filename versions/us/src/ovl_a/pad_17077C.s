.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17077C */
glabel pad_17077C
    /* 17077C */  .word      0x50726566
endlabel pad_17077C
