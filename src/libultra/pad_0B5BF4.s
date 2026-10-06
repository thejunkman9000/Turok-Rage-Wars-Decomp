.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB5BF4 */
glabel pad_0B5BF4
    /* B5BF4 */  .word      0x34420001
    /* B5BF8 */  .word      0xA2220037
    /* B5BFC */  .word      0xC7A0003C
endlabel pad_0B5BF4
