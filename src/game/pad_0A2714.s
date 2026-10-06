.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA2714 */
glabel pad_0A2714
    /* A2714 */  .word      0x8FB00010
    /* A2718 */  .word      0x03E00008
    /* A271C */  .word      0x27BD0018
endlabel pad_0A2714
