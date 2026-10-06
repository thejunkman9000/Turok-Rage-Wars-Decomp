.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8BC8 */
glabel pad_0B8BC8
    /* B8BC8 */  .word      0x00471021
    /* B8BCC */  .word      0xAC460000
endlabel pad_0B8BC8
