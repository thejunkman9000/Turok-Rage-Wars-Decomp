.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC093C */
glabel pad_0C093C
    /* C093C */  .word      0xA4650010
    /* C0940 */  .word      0x03E00008
    /* C0944 */  .word      0x00000000
    /* C0948 */  .word      0x8FBF0014
    /* C094C */  .word      0x8FB00010
endlabel pad_0C093C
