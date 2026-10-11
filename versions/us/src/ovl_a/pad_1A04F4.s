.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A04F4 */
glabel pad_1A04F4
    /* 1A04F4 */  .word      0x2E313133
    /* 1A04F8 */  .word      0x66616B65
    /* 1A04FC */  .word      0x042E656F
endlabel pad_1A04F4
