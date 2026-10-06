.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC3DB8 */
glabel pad_0C3DB8
    /* C3DB8 */  .word      0x0C0B0FA8
    /* C3DBC */  .word      0xAFAB0010
endlabel pad_0C3DB8
