.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xE9D4 */
glabel pad_00E9D4
    /* E9D4 */  .word      0x3C128014
    /* E9D8 */  .word      0x2652B364
    /* E9DC */  .word      0xAFBF001C
endlabel pad_00E9D4
