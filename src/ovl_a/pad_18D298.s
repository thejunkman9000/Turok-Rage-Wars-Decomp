.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18D298 */
glabel pad_18D298
    /* 18D298 */  .word      0x8C4242D0
    /* 18D29C */  .word      0x00531021
endlabel pad_18D298
