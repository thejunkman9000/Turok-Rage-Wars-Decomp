.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18C304 */
glabel pad_18C304
    /* 18C304 */  .word      0x02202021
    /* 18C308 */  .word      0x00002821
    /* 18C30C */  .word      0x2406013C
endlabel pad_18C304
