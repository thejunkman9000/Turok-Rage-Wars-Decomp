.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC394 */
glabel pad_0BC394
    /* BC394 */  .word      0x65616D54
    /* BC398 */  .word      0x7269616E
    /* BC39C */  .word      0x676C654D
endlabel pad_0BC394
