.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC1594 */
glabel pad_0C1594
    /* C1594 */  .word      0x080B075A
    /* C1598 */  .word      0x00001021
    /* C159C */  .word      0x8E230000
endlabel pad_0C1594
