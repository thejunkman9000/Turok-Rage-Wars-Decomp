.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AE9B8 */
glabel pad_1AE9B8
    /* 1AE9B8 */  .word      0x00086D5F
    /* 1AE9BC */  .word      0x41637469
endlabel pad_1AE9B8
