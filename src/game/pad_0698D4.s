.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x698D4 */
glabel pad_0698D4
    /* 698D4 */  .word      0x8FA20028
    /* 698D8 */  .word      0x8FA5002C
    /* 698DC */  .word      0x0202001A
endlabel pad_0698D4
