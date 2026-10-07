.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63C18 */
glabel pad_063C18
    /* 63C18 */  .word      0x3C028014
    /* 63C1C */  .word      0x8C42B290
    /* 63C20 */  .word      0x27BDFFE0
    /* 63C24 */  .word      0xAFB10014
    /* 63C28 */  .word      0x00808821
    /* 63C2C */  .word      0xAFB20018
    /* 63C30 */  .word      0x00A09021
    /* 63C34 */  .word      0xAFBF001C
    /* 63C38 */  .word      0x14400005
    /* 63C3C */  .word      0xAFB00010
    /* 63C40 */  .word      0x8E225F24
    /* 63C44 */  .word      0x2C420003
    /* 63C48 */  .word      0x1040000F
    /* 63C4C */  .word      0x00001021
    /* 63C50 */  .word      0x8E305F00
    /* 63C54 */  .word      0x1200000B
    /* 63C58 */  .word      0x26245F00
    /* 63C5C */  .word      0x0C09579E
    /* 63C60 */  .word      0x02002821
    /* 63C64 */  .word      0x26245F14
    /* 63C68 */  .word      0x0C095716
    /* 63C6C */  .word      0x02002821
    /* 63C70 */  .word      0x12400004
    /* 63C74 */  .word      0xAE1202F0
    /* 63C78 */  .word      0x8E420000
    /* 63C7C */  .word      0x24420001
    /* 63C80 */  .word      0xAE420000
    /* 63C84 */  .word      0x02001021
    /* 63C88 */  .word      0x8FBF001C
    /* 63C8C */  .word      0x8FB20018
    /* 63C90 */  .word      0x8FB10014
    /* 63C94 */  .word      0x8FB00010
    /* 63C98 */  .word      0x03E00008
    /* 63C9C */  .word      0x27BD0020
    /* 63CA0 */  .word      0x27BDFFE0
    /* 63CA4 */  .word      0xAFB00010
    /* 63CA8 */  .word      0x00A08021
    /* 63CAC */  .word      0xAFBF0018
    /* 63CB0 */  .word      0xAFB10014
    /* 63CB4 */  .word      0x8E0302F0
    /* 63CB8 */  .word      0x00808821
    /* 63CBC */  .word      0x10600004
    /* 63CC0 */  .word      0xAE000174
    /* 63CC4 */  .word      0x8C620000
    /* 63CC8 */  .word      0x2442FFFF
    /* 63CCC */  .word      0xAC620000
    /* 63CD0 */  .word      0x26245F14
    /* 63CD4 */  .word      0x0C09579E
    /* 63CD8 */  .word      0x02002821
    /* 63CDC */  .word      0x26245F00
    /* 63CE0 */  .word      0x0C09572D
    /* 63CE4 */  .word      0x02002821
    /* 63CE8 */  .word      0x8FBF0018
    /* 63CEC */  .word      0x8FB10014
    /* 63CF0 */  .word      0x8FB00010
    /* 63CF4 */  .word      0x03E00008
    /* 63CF8 */  .word      0x27BD0020
    /* 63CFC */  .word      0xAC820028
endlabel pad_063C18
