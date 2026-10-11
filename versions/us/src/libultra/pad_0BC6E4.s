.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC6E4 */
glabel pad_0BC6E4
    /* BC6E4 */  .word      0x00005000
    /* BC6E8 */  .word      0x00000800
    /* BC6EC */  .word      0x08000C00
endlabel pad_0BC6E4
