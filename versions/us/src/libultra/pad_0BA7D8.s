.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA7D8 */
glabel pad_0BA7D8
    /* BA7D8 */  .word      0x00001043
    /* BA7DC */  .word      0x506C6179
endlabel pad_0BA7D8
