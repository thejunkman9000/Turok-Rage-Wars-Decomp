.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBBF48 */
glabel pad_0BBF48
    /* BBF48 */  .word      0x00000000
    /* BBF4C */  .word      0x1143506C
endlabel pad_0BBF48
