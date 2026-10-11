.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x343B8 */
glabel pad_0343B8
    /* 343B8 */  .word      0x44820800
    /* 343BC */  .word      0x46800861
endlabel pad_0343B8
