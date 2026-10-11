.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13264 */
glabel pad_013264
    /* 13264 */  .word      0xACA206B0
    /* 13268 */  .word      0x8E220320
    /* 1326C */  .word      0x04410012
endlabel pad_013264
