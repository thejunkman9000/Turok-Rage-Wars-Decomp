.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x9C798 */
glabel pad_09C798
    /* 9C798 */  .word      0x46000007
    /* 9C79C */  .word      0x8FBF0014
endlabel pad_09C798
