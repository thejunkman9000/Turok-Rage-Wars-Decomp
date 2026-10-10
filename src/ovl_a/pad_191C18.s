.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x191C18 */
glabel pad_191C18
    /* 191C18 */  .word      0xAC430000
    /* 191C1C */  .word      0x26520001
endlabel pad_191C18
