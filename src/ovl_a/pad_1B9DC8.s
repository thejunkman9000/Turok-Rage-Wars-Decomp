.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B9DC8 */
glabel pad_1B9DC8
    /* 1B9DC8 */  .word      0x24050002
    /* 1B9DCC */  .word      0x0C0A3F65
endlabel pad_1B9DC8
