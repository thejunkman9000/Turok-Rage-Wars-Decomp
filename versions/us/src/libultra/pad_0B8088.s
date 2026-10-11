.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8088 */
glabel pad_0B8088
    /* B8088 */  .word      0x654C6F6F
    /* B808C */  .word      0x6B585200
endlabel pad_0B8088
