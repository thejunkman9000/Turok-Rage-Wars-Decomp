.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ABF74 */
glabel pad_1ABF74
    /* 1ABF74 */  .word      0x30B0FFFF
    /* 1ABF78 */  .word      0xAFBF0294
    /* 1ABF7C */  .word      0xAFB50284
endlabel pad_1ABF74
