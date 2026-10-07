.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ABCBC */
glabel pad_1ABCBC
    /* 1ABCBC */  .word      0x8FBF0024
endlabel pad_1ABCBC
