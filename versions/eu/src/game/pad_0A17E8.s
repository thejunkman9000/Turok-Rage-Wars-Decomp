.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA17E8 */
glabel pad_0A17E8
    /* A17E8 */  .word      0x45000008
    /* A17EC */  .word      0x00000000
endlabel pad_0A17E8
