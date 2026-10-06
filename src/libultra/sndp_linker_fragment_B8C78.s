.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8C78-0xB8C80 (VRAM 0x002B8078) */
glabel sndp_linker_fragment_B8C78
    /* B8C78 002B8078 24110002 */  addiu      $s1, $zero, 0x2
    /* B8C7C 002B807C 3C12800E */  lui        $s2, (0x800E0000 >> 16)
endlabel sndp_linker_fragment_B8C78
