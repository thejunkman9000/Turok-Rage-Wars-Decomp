.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA3F8 */
glabel pad_0BA3F8
    /* BA3F8 */  .word      0x03E00008
    /* BA3FC */  .word      0x27BD0040
endlabel pad_0BA3F8
