.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF9AC */
glabel pad_0BF9AC
    /* BF9AC */  .word      0x3C04800D
endlabel pad_0BF9AC
