.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC23A8 */
glabel pad_0C23A8
    /* C23A8 */  .word      0x0007434C
    /* C23AC */  .word      0x6973745F
endlabel pad_0C23A8
