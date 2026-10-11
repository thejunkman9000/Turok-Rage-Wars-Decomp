.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3898 */
glabel pad_003898
    /* 3898 */  .word      0x794F626A
    /* 389C */  .word      0x65637454
endlabel pad_003898
