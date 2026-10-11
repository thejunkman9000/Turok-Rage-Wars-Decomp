.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC2438 */
glabel pad_0C2438
    /* C2438 */  .word      0x4F4D486F
    /* C243C */  .word      0x74506F69
endlabel pad_0C2438
