.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x77218 */
glabel pad_077218
    /* 77218 */  .word      0x03E00008
    /* 7721C */  .word      0x27BD0060
endlabel pad_077218
