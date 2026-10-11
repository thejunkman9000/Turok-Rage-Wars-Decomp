.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x64354 */
glabel pad_064354
    /* 64354 */  .word      0x9022F308
    /* 64358 */  .word      0x10400003
    /* 6435C */  .word      0x24630001
endlabel pad_064354
