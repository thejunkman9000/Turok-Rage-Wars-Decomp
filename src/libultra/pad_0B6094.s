.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB6094 */
glabel pad_0B6094
    /* B6094 */  .word      0x00431021
    /* B6098 */  .word      0xA050000A
    /* B609C */  .word      0x8E510064
endlabel pad_0B6094
