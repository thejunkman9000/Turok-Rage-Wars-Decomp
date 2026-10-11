.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x50534 */
glabel pad_050534
    /* 50534 */  .word      0x248400E8
    /* 50538 */  .word      0x02001021
    /* 5053C */  .word      0x8FBF0018
endlabel pad_050534
