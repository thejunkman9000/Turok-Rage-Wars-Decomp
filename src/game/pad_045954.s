.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x45954 */
glabel pad_045954
    /* 45954 */  .word      0x14620010
    /* 45958 */  .word      0x00E09821
    /* 4595C */  .word      0x8E030038
endlabel pad_045954
