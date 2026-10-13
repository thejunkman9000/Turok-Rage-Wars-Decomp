.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAFB4 */
glabel pad_0BAFB4
    /* BAFB4 */  .word      0x46800861
    /* BAFB8 */  .word      0x46210000
    /* BAFBC */  .word      0x3C01800D
endlabel pad_0BAFB4
