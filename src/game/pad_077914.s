.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x77914 */
glabel pad_077914
    /* 77914 */  .word      0x18400025
    /* 77918 */  .word      0x0200A021
    /* 7791C */  .word      0x24051508
endlabel pad_077914
