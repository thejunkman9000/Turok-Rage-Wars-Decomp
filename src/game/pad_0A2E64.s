.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA2E64 */
glabel pad_0A2E64
    /* A2E64 */  .word      0x3C04800D
    /* A2E68 */  .word      0x2484AF30
    /* A2E6C */  .word      0x0C103F05
endlabel pad_0A2E64
