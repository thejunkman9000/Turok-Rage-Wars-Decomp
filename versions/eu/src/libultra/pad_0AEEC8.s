.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAEEC8 */
glabel pad_0AEEC8
    /* AEEC8 */  .word      0x4405A800
    /* AEECC */  .word      0x4406A000
endlabel pad_0AEEC8
