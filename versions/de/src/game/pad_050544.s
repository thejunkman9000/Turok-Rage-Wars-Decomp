.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x50544 */
glabel pad_050544
    /* 50544 */  .word      0xAFB00060
    /* 50548 */  .word      0x00C08021
    /* 5054C */  .word      0xAFB3006C
endlabel pad_050544
