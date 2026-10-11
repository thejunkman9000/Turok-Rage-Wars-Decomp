.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC3D4 */
glabel pad_0BC3D4
    /* BC3D4 */  .word      0x6F72335F
    /* BC3D8 */  .word      0x740F6D5F
    /* BC3DC */  .word      0x76477261
endlabel pad_0BC3D4
