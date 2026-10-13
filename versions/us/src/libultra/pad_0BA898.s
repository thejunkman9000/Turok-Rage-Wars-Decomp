.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBA898 */
glabel pad_0BA898
    /* BA898 */  .word      0x6D655200
    /* BA89C */  .word      0x00580600
endlabel pad_0BA898
