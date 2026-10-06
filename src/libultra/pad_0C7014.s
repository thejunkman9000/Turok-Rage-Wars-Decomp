.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC7014 */
glabel pad_0C7014
    /* C7014 */  .word      0x40400000
    /* C7018 */  .word      0x40400000
    /* C701C */  .word      0x41B80000
endlabel pad_0C7014
