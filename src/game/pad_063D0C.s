.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63D0C */
glabel pad_063D0C
    /* 63D0C */  .word      0x27BDFFE8
    /* 63D10 */  .word      0xAFB00010
    /* 63D14 */  .word      0xAFBF0014
    /* 63D18 */  .word      0x0C098C5D
    /* 63D1C */  .word      0x00A08021
    /* 63D20 */  .word      0x00402021
    /* 63D24 */  .word      0x2603FFFF
    /* 63D28 */  .word      0x24020001
    /* 63D2C */  .word      0x00621004
    /* 63D30 */  .word      0x00821024
    /* 63D34 */  .word      0x1040000A
    /* 63D38 */  .word      0x2A020020
    /* 63D3C */  .word      0x10400008
    /* 63D40 */  .word      0x02002821
    /* 63D44 */  .word      0x24030001
    /* 63D48 */  .word      0x00A31004
    /* 63D4C */  .word      0x00822025
    /* 63D50 */  .word      0x24A50001
    /* 63D54 */  .word      0x28A20020
    /* 63D58 */  .word      0x1440FFFC
    /* 63D5C */  .word      0x00A31004
    /* 63D60 */  .word      0x8FBF0014
    /* 63D64 */  .word      0x8FB00010
    /* 63D68 */  .word      0x00801021
    /* 63D6C */  .word      0x03E00008
    /* 63D70 */  .word      0x27BD0018
endlabel pad_063D0C
