.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB3038 */
glabel pad_0B3038
    /* B3038 */  .word      0x3C01800D
    /* B303C */  .word      0xD420C540
endlabel pad_0B3038
