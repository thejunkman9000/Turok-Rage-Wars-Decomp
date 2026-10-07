.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18BFB4 */
glabel pad_18BFB4
    /* 18BFB4 */  .word      0x14610004
    /* 18BFB8 */  .word      0x3C018000
    /* 18BFBC */  .word      0x14410002
endlabel pad_18BFB4
