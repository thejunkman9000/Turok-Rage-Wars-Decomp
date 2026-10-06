.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC03EC */
glabel pad_0C03EC
    /* C03EC */  .word      0xAE020010
endlabel pad_0C03EC
