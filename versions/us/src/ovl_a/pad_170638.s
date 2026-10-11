.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x170638 */
glabel pad_170638
    /* 170638 */  .word      0x940F000A
    /* 17063C */  .word      0x00040000
endlabel pad_170638
