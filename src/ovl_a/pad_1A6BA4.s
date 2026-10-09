.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A6BA4 */
glabel pad_1A6BA4
    /* 1A6BA4 */  .word      0x27BDFFE8
    /* 1A6BA8 */  .word      0xAFBF0010
    /* 1A6BAC */  .word      0x0C0A8C89
    /* 1A6BB0 */  .word      0x00000000
    /* 1A6BB4 */  .word      0x0C0A8CE3
    /* 1A6BB8 */  .word      0x00000000
    /* 1A6BBC */  .word      0x0C0A64DA
    /* 1A6BC0 */  .word      0x24040012
    /* 1A6BC4 */  .word      0x8FBF0010
    /* 1A6BC8 */  .word      0x03E00008
    /* 1A6BCC */  .word      0x27BD0018
endlabel pad_1A6BA4
