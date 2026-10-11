.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x9BA74 */
glabel pad_09BA74
    /* 9BA74 */  .word      0xD420A8C0
    /* 9BA78 */  .word      0xC7A20000
    /* 9BA7C */  .word      0x468010A1
endlabel pad_09BA74
