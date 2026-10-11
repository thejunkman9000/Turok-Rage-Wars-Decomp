.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x187758 */
glabel pad_187758
    /* 187758 */  .word      0x03E00008
    /* 18775C */  .word      0x27BD0028
endlabel pad_187758
