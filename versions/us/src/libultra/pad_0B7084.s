.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7084 */
glabel pad_0B7084
    /* B7084 */  .word      0x03000000
    /* B7088 */  .word      0x0000116D
    /* B708C */  .word      0x5F416D6D
endlabel pad_0B7084
