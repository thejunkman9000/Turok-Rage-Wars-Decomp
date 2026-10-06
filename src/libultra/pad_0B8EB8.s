.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8EB8 */
glabel pad_0B8EB8
    /* B8EB8 */  .word      0xC420C824
    /* B8EBC */  .word      0x24020034
endlabel pad_0B8EB8
