.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD174 */
glabel pad_0BD174
    /* BD174 */  .word      0x8FB10064
    /* BD178 */  .word      0x8FB00060
    /* BD17C */  .word      0x03E00008
endlabel pad_0BD174
