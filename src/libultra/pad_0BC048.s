.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC048 */
glabel pad_0BC048
    /* BC048 */  .word      0x30E200FF
    /* BC04C */  .word      0x2C420011
endlabel pad_0BC048
