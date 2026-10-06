.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC184 */
glabel pad_0BC184
    /* BC184 */  .word      0xAFB00010
    /* BC188 */  .word      0x00808021
    /* BC18C */  .word      0xAFBF0018
endlabel pad_0BC184
