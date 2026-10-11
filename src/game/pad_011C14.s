.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x11C14 */
glabel pad_011C14
    /* 11C14 */  .word      0x0C0827A0
    /* 11C18 */  .word      0x02202021
    /* 11C1C */  .word      0x0808480D
endlabel pad_011C14
