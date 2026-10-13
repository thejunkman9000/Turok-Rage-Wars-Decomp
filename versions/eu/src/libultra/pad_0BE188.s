.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE188 */
glabel pad_0BE188
    /* BE188 */  .word      0x00628821
    /* BE18C */  .word      0x02203821
endlabel pad_0BE188
