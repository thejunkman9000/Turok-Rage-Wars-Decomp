.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9140-0xB9150 (VRAM 0x002B8540) */
glabel alSynSetPriority
    /* B9140 002B8540 03E00008 */  jr         $ra
    /* B9144 002B8544 A4A60016 */   sh        $a2, 0x16($a1)


    /* B9148 002B8548 3C06002C */  .word      0x3C06002C /* linker padding */
    /* B914C 002B854C 24C6A610 */  .word      0x24C6A610 /* linker padding */
endlabel alSynSetPriority
