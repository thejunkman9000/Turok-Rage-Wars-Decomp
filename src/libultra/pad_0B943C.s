.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB943C */
glabel pad_0B943C
    /* B943C */  .word      0x8E02003C
endlabel pad_0B943C
