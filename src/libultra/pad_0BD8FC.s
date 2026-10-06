.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD8FC */
glabel pad_0BD8FC
    /* BD8FC */  .word      0x8FB00038
endlabel pad_0BD8FC
