.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19EB4 */
glabel pad_019EB4
    /* 19EB4 */  .word      0x8FB40028
    /* 19EB8 */  .word      0x8FB30024
    /* 19EBC */  .word      0x8FB20020
endlabel pad_019EB4
