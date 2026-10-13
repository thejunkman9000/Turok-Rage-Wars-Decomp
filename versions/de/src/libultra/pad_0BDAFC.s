.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDAFC */
glabel pad_0BDAFC
    /* BDAFC */  .word      0x26B20008
endlabel pad_0BDAFC
