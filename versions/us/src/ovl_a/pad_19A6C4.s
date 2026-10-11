.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19A6C4 */
glabel pad_19A6C4
    /* 19A6C4 */  .word      0x64655400
    /* 19A6C8 */  .word      0x000A0000
    /* 19A6CC */  .word      0x00080032
endlabel pad_19A6C4
