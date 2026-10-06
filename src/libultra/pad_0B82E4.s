.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB82E4 */
glabel pad_0B82E4
    /* B82E4 */  .word      0xAFB7002C
    /* B82E8 */  .word      0x00C0B821
    /* B82EC */  .word      0xAFBF0030
endlabel pad_0B82E4
