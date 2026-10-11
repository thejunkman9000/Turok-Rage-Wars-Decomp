.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA1068 */
glabel pad_0A1068
    /* A1068 */  .word      0x10460004
    /* A106C */  .word      0x00801021
endlabel pad_0A1068
