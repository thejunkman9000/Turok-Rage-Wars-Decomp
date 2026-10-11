.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4255C */
glabel pad_04255C
    /* 4255C */  .word      0xAFB10024
endlabel pad_04255C
