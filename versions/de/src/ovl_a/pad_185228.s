.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x185228 */
glabel pad_185228
    /* 185228 */  .word      0x00021600
    /* 18522C */  .word      0x00822025
endlabel pad_185228
