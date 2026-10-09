.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x10E28 */
glabel pad_010E28
    /* 10E28 */  .word      0x04620001
    /* 10E2C */  .word      0x24620003
endlabel pad_010E28
