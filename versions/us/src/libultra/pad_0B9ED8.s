.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9ED8 */
glabel pad_0B9ED8
    /* B9ED8 */  .word      0x53535F48
    /* B9EDC */  .word      0x4149525F
endlabel pad_0B9ED8
