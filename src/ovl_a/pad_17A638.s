.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17A638 */
glabel pad_17A638
    /* 17A638 */  .word      0x28620002
    /* 17A63C */  .word      0x10400005
endlabel pad_17A638
