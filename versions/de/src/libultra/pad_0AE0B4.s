.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE0B4 */
glabel pad_0AE0B4
    /* AE0B4 */  .word      0xAFB00000
    /* AE0B8 */  .word      0xAFB10004
    /* AE0BC */  .word      0xAFB20008
endlabel pad_0AE0B4
