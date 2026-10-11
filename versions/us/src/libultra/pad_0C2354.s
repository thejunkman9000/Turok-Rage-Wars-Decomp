.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC2354 */
glabel pad_0C2354
    /* C2354 */  .word      0x656E755F
    /* C2358 */  .word      0x74042E65
    /* C235C */  .word      0x6F735400
endlabel pad_0C2354
