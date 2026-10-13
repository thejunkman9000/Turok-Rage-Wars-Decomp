.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA968 */
glabel pad_0BA968
    /* BA968 */  .word      0x8C420000
    /* BA96C */  .word      0x30420003
endlabel pad_0BA968
