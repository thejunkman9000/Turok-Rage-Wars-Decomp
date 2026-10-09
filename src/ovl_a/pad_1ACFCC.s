.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ACFCC */
glabel pad_1ACFCC
    /* 1ACFCC */  .word      0x00E0A021
endlabel pad_1ACFCC
