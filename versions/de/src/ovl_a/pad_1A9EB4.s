.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A9EB4 */
glabel pad_1A9EB4
    /* 1A9EB4 */  .word      0xAFB20018
    /* 1A9EB8 */  .word      0xA2220018
    /* 1A9EBC */  .word      0x240200FA
endlabel pad_1A9EB4
