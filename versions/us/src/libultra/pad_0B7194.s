.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7194 */
glabel pad_0B7194
    /* B7194 */  .word      0x106D5F50
    /* B7198 */  .word      0x69636B75
    /* B719C */  .word      0x70496E66
endlabel pad_0B7194
