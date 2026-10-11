.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x144E8 */
glabel pad_0144E8
    /* 144E8 */  .word      0x02602021
    /* 144EC */  .word      0x1040001D
endlabel pad_0144E8
