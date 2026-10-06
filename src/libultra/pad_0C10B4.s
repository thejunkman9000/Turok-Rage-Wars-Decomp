.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC10B4 */
glabel pad_0C10B4
    /* C10B4 */  .word      0x00000000
    /* C10B8 */  .word      0x445BF800
    /* C10BC */  .word      0x00000000
endlabel pad_0C10B4
