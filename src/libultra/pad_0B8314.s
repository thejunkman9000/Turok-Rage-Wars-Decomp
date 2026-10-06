.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8314 */
glabel pad_0B8314
    /* B8314 */  .word      0x00111600
    /* B8318 */  .word      0x04420001
    /* B831C */  .word      0x00119823
endlabel pad_0B8314
