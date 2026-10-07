.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA26C4 */
glabel pad_0A26C4
    /* A26C4 */  .word      0x02202021
    /* A26C8 */  .word      0x02002821
    /* A26CC */  .word      0x24020002
endlabel pad_0A26C4
