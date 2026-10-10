.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x197C04 */
glabel pad_197C04
    /* 197C04 */  .word      0x00651821
    /* 197C08 */  .word      0x94650002
    /* 197C0C */  .word      0x0C103B2C
endlabel pad_197C04
