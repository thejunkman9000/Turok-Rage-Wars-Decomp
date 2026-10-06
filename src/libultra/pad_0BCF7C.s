.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCF7C */
glabel pad_0BCF7C
    /* BCF7C */  .word      0x8CAA0008
endlabel pad_0BCF7C
