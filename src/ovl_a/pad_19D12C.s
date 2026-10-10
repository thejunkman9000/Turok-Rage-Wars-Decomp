.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19D12C */
glabel pad_19D12C
    /* 19D12C */  .word      0x000510C0
endlabel pad_19D12C
