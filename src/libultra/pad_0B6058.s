.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB6058 */
glabel pad_0B6058
    /* B6058 */  .word      0x02402021
    /* B605C */  .word      0x8E220020
endlabel pad_0B6058
