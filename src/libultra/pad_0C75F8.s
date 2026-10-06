.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC75F8 */
glabel pad_0C75F8
    /* C75F8 */  .word      0x41800000
    /* C75FC */  .word      0x3C8EFA36
endlabel pad_0C75F8
