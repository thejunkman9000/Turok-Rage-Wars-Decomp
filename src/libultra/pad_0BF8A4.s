.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF8A4 */
glabel pad_0BF8A4
    /* BF8A4 */  .word      0xAE670000
    /* BF8A8 */  .word      0x8FB90010
    /* BF8AC */  .word      0x35AD0034
endlabel pad_0BF8A4
