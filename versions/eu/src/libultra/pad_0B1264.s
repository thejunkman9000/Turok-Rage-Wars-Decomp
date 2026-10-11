.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB1264 */
glabel pad_0B1264
    /* B1264 */  .word      0x1486FFFC
    /* B1268 */  .word      0x24630014
    /* B126C */  .word      0x00008021
endlabel pad_0B1264
