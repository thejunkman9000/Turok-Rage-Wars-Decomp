.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC05F4 */
glabel pad_0C05F4
    /* C05F4 */  .word      0x00000000
    /* C05F8 */  .word      0x0C0B07FC
    /* C05FC */  .word      0x00000000
endlabel pad_0C05F4
