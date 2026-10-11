.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3F9E8 */
glabel pad_03F9E8
    /* 3F9E8 */  .word      0x24050005
    /* 3F9EC */  .word      0x0040B821
endlabel pad_03F9E8
