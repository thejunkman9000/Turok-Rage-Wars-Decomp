.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xDF64 */
glabel pad_00DF64
    /* DF64 */  .word      0x46800860
    /* DF68 */  .word      0x46030842
    /* DF6C */  .word      0x3C01800C
endlabel pad_00DF64
