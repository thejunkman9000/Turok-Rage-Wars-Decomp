.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x183298 */
glabel pad_183298
    /* 183298 */  .word      0x35657175
    /* 18329C */  .word      0xD0100000
endlabel pad_183298
