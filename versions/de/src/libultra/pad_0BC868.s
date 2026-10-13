.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC868 */
glabel pad_0BC868
    /* BC868 */  .word      0x03400008
    /* BC86C */  .word      0x00000000
endlabel pad_0BC868
