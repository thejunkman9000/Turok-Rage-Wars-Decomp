.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x188228 */
glabel pad_188228
    /* 188228 */  .word      0x8FBF0018
    /* 18822C */  .word      0x00001021
endlabel pad_188228
