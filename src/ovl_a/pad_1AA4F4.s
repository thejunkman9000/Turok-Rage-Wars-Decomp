.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AA4F4 */
glabel pad_1AA4F4
    /* 1AA4F4 */  .word      0x8C820008
    /* 1AA4F8 */  .word      0x0810F544
    /* 1AA4FC */  .word      0x00431025
endlabel pad_1AA4F4
