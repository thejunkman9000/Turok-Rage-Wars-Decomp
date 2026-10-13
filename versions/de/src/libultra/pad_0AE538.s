.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE538 */
glabel pad_0AE538
    /* AE538 */  .word      0xAFA50004
    /* AE53C */  .word      0xAFA60008
endlabel pad_0AE538
