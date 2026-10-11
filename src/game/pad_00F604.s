.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xF604 */
glabel pad_00F604
    /* F604 */  .word      0x24840004
    /* F608 */  .word      0x03E00008
    /* F60C */  .word      0x00A01021
endlabel pad_00F604
