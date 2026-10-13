.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDDAC */
glabel pad_0BDDAC
    /* BDDAC */  .word      0xB8680007
endlabel pad_0BDDAC
