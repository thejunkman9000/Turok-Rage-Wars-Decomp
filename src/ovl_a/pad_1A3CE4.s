.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A3CE4 */
glabel pad_1A3CE4
    /* 1A3CE4 */  .word      0x00300821
    /* 1A3CE8 */  .word      0x90222C8C
    /* 1A3CEC */  .word      0xA222007A
endlabel pad_1A3CE4
