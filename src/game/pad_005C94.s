.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5C94 */
glabel pad_005C94
    /* 5C94 */  .word      0xC44C000C
    /* 5C98 */  .word      0xC44E0010
    /* 5C9C */  .word      0x0C09D2C0
endlabel pad_005C94
