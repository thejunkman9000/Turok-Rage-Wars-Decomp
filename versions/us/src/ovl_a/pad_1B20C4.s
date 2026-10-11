.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B20C4 */
glabel pad_1B20C4
    /* 1B20C4 */  .word      0x4E444C49
    /* 1B20C8 */  .word      0x46456571
    /* 1B20CC */  .word      0x75520000
endlabel pad_1B20C4
