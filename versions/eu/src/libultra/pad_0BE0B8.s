.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE0B8 */
glabel pad_0BE0B8
    /* BE0B8 */  .word      0x02403021
    /* BE0BC */  .word      0x1AA00007
endlabel pad_0BE0B8
