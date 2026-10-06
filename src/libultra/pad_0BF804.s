.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF804 */
glabel pad_0BF804
    /* BF804 */  .word      0x36730020
    /* BF808 */  .word      0x3C12A440
    /* BF80C */  .word      0x36520024
endlabel pad_0BF804
