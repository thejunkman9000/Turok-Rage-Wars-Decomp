.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BBFC8 */
glabel pad_1BBFC8
    /* 1BBFC8 */  .word      0x00431024
    /* 1BBFCC */  .word      0x14400003
endlabel pad_1BBFC8
