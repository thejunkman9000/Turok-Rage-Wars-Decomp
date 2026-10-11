.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA7E4 */
glabel pad_0BA7E4
    /* BA7E4 */  .word      0x27A50018
    /* BA7E8 */  .word      0x27A6001A
    /* BA7EC */  .word      0x8FA80054
endlabel pad_0BA7E4
