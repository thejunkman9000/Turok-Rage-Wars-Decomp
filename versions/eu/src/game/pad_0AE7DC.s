.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE7DC */
glabel pad_0AE7DC
    /* AE7DC */  .word      0x080AA301
endlabel pad_0AE7DC
