.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBBAF8 */
glabel pad_0BBAF8
    /* BBAF8 */  .word      0x080AD800
    /* BBAFC */  .word      0xA446000A
endlabel pad_0BBAF8
