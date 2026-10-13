.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x183F44 */
glabel pad_183F44
    /* 183F44 */  .word      0x00162280
    /* 183F48 */  .word      0xAFAC0018
    /* 183F4C */  .word      0xA7A50012
endlabel pad_183F44
