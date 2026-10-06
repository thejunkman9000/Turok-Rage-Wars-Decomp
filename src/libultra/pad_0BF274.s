.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF274 */
glabel pad_0BF274
    /* BF274 */  .word      0x1440000B
    /* BF278 */  .word      0x00000000
    /* BF27C */  .word      0x0C0AFDCC
endlabel pad_0BF274
