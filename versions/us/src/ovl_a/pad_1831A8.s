.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1831A8 */
glabel pad_1831A8
    /* 1831A8 */  .word      0x495F414E
    /* 1831AC */  .word      0x494D5F47
endlabel pad_1831A8
