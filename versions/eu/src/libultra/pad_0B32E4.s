.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB32E4 */
glabel pad_0B32E4
    /* B32E4 */  .word      0x42000001
    /* B32E8 */  .word      0x00000000
    /* B32EC */  .word      0x00000000
endlabel pad_0B32E4
