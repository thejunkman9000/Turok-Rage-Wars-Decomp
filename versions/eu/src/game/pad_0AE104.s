.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAE104 */
glabel pad_0AE104
    /* AE104 */  .word      0x02301823
    /* AE108 */  .word      0x1075000B
    /* AE10C */  .word      0x28620002
endlabel pad_0AE104
