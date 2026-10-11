.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC1E4 */
glabel pad_0BC1E4
    /* BC1E4 */  .word      0x7374426F
    /* BC1E8 */  .word      0x745F7405
    /* BC1EC */  .word      0x6D5F426F
endlabel pad_0BC1E4
