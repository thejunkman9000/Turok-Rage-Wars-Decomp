.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC3114 */
glabel pad_0C3114
    /* C3114 */  .word      0x00021040
    /* C3118 */  .word      0x00621821
    /* C311C */  .word      0x080B0D4C
endlabel pad_0C3114
