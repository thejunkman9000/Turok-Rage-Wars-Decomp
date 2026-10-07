.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17A638 */
glabel pad_17A638
    /* 17A638 */  .word      0x28620002
    /* 17A63C */  .word      0x10400005
    /* 17A640 */  .word      0x03E00008
    /* 17A644 */  .word      0x00001021
endlabel pad_17A638
