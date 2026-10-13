.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC7B4 */
glabel pad_0BC7B4
    /* BC7B4 */  .word      0x0481000A
    /* BC7B8 */  .word      0xAFBF0010
    /* BC7BC */  .word      0x3C029FFF
endlabel pad_0BC7B4
