.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A70EC */
glabel pad_1A70EC
    /* 1A70EC */  .word      0x24050004
endlabel pad_1A70EC
