.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAEC28 */
glabel pad_0AEC28
    /* AEC28 */  .word      0x00808821
    /* AEC2C */  .word      0xAFB3001C
endlabel pad_0AEC28
