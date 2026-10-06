.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC848 */
glabel pad_0BC848
    /* BC848 */  .word      0x1440FFE4
    /* BC84C */  .word      0x25080004
endlabel pad_0BC848
