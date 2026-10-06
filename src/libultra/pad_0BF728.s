.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF728 */
glabel pad_0BF728
    /* BF728 */  .word      0x00571021
    /* BF72C */  .word      0x00021080
endlabel pad_0BF728
