.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE9B8 */
glabel pad_0BE9B8
    /* BE9B8 */  .word      0x10400007
    /* BE9BC */  .word      0xAFBF0018
endlabel pad_0BE9B8
