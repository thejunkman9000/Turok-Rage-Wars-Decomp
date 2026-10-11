.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x97C18 */
glabel pad_097C18
    /* 97C18 */  .word      0x8E04003C
    /* 97C1C */  .word      0x0C0A64DA
endlabel pad_097C18
