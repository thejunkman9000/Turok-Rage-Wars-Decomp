.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC334 */
glabel pad_0BC334
    /* BC334 */  .word      0xA0820000
    /* BC338 */  .word      0x24630001
    /* BC33C */  .word      0x24C60008
endlabel pad_0BC334
