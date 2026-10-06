.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8EC8 */
glabel pad_0B8EC8
    /* B8EC8 */  .word      0xE601001C
    /* B8ECC */  .word      0x0C0AD504
endlabel pad_0B8EC8
