.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE1B8 */
glabel pad_0BE1B8
    /* BE1B8 */  .word      0xB8C90007
    /* BE1BC */  .word      0xA2420028
endlabel pad_0BE1B8
