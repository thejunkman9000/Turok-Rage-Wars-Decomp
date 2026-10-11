.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xE804 */
glabel pad_00E804
    /* E804 */  .word      0x8FB10014
    /* E808 */  .word      0x8FB00010
    /* E80C */  .word      0x03E00008
endlabel pad_00E804
