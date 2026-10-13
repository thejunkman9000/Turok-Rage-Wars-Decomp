.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE208 */
glabel pad_0AE208
    /* AE208 */  .word      0x27BDFFD8
    /* AE20C */  .word      0xAFBF0024
endlabel pad_0AE208
