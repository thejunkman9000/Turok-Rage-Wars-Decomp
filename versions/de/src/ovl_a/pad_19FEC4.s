.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19FEC4 */
glabel pad_19FEC4
    /* 19FEC4 */  .word      0xAFB00048
    /* 19FEC8 */  .word      0x8FA40070
    /* 19FECC */  .word      0x24050004
endlabel pad_19FEC4
