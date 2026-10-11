.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB0A4 */
glabel pad_0BB0A4
    /* BB0A4 */  .word      0x02202021
    /* BB0A8 */  .word      0x02602821
    /* BB0AC */  .word      0x02403021
endlabel pad_0BB0A4
