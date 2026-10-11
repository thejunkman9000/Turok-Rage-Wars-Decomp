.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBBEF4 */
glabel pad_0BBEF4
    /* BBEF4 */  .word      0x0800F200
    /* BBEF8 */  .word      0x69000000
    /* BBEFC */  .word      0x02000500
endlabel pad_0BBEF4
