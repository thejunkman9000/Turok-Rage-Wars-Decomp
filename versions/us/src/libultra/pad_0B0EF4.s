.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB0EF4 */
glabel pad_0B0EF4
    /* B0EF4 */  .word      0x6D5F6E46
    /* B0EF8 */  .word      0x72616D65
    /* B0EFC */  .word      0x73526E64
endlabel pad_0B0EF4
