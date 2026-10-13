.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1884DC */
glabel pad_1884DC
    /* 1884DC */  .word      0x0C0978B5
endlabel pad_1884DC
