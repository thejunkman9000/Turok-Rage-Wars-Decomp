.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE354 */
glabel pad_0AE354
    /* AE354 */  .word      0xAC620028
    /* AE358 */  .word      0x3C02F300
    /* AE35C */  .word      0xACE00004
endlabel pad_0AE354
