.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BFF78 */
glabel pad_1BFF78
    /* 1BFF78 */  .word      0x00451021
    /* 1BFF7C */  .word      0x90420000
endlabel pad_1BFF78
