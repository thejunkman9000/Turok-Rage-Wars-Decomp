.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB93B4 */
glabel pad_0B93B4
    /* B93B4 */  .word      0x3C01800D
    /* B93B8 */  .word      0xD423C840
    /* B93BC */  .word      0x24830012
endlabel pad_0B93B4
