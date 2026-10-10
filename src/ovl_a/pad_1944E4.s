.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1944E4 */
glabel pad_1944E4
    /* 1944E4 */  .word      0x0C09959C
    /* 1944E8 */  .word      0x02002821
    /* 1944EC */  .word      0x50400022
endlabel pad_1944E4
