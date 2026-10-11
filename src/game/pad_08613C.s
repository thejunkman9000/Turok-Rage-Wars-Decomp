.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8613C */
glabel pad_08613C
    /* 8613C */  .word      0x46140542
endlabel pad_08613C
