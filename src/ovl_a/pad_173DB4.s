.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x173DB4 */
glabel pad_173DB4
    /* 173DB4 */  .word      0x8E3128C8
    /* 173DB8 */  .word      0x02202021
    /* 173DBC */  .word      0x02002821
endlabel pad_173DB4
