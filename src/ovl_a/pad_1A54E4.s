.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A54E4 */
glabel pad_1A54E4
    /* 1A54E4 */  .word      0x24020096
    /* 1A54E8 */  .word      0xA2220010
    /* 1A54EC */  .word      0x82440080
endlabel pad_1A54E4
