.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B9498 */
glabel pad_1B9498
    /* 1B9498 */  .word      0x02610821
    /* 1B949C */  .word      0xAC20B61C
endlabel pad_1B9498
