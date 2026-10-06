.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF634 */
glabel pad_0BF634
    /* BF634 */  .word      0xAFB10034
    /* BF638 */  .word      0xAFB00030
    /* BF63C */  .word      0x8C420000
endlabel pad_0BF634
