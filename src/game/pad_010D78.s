.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x10D78 */
glabel pad_010D78
    /* 10D78 */  .word      0xAE020318
    /* 10D7C */  .word      0x8E020064
endlabel pad_010D78
