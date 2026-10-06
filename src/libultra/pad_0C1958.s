.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC1958 */
glabel pad_0C1958
    /* C1958 */  .word      0xAE020000
    /* C195C */  .word      0x0C0B0760
endlabel pad_0C1958
