.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0974 */
glabel pad_0C0974
    /* C0974 */  .word      0x275A0E60
    /* C0978 */  .word      0xFF410020
    /* C097C */  .word      0x401B6000
endlabel pad_0C0974
