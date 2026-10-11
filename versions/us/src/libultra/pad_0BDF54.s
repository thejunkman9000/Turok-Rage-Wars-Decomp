.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDF54 */
glabel pad_0BDF54
    /* BDF54 */  .word      0x0C000000
    /* BDF58 */  .word      0x0000086D
    /* BDF5C */  .word      0x5F546578
endlabel pad_0BDF54
