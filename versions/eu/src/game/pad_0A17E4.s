.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA17E4 */
glabel pad_0A17E4
    /* A17E4 */  .word      0x00000000
endlabel pad_0A17E4
