.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8EC0-0xB8ED0 (VRAM 0x002B82C0) */
glabel alSynDelete
    /* B8EC0 002B82C0 03E00008 */  jr         $ra
    /* B8EC4 002B82C4 AC800000 */   sw        $zero, 0x0($a0)


    /* B8EC8 002B82C8 E601001C */  .word      0xE601001C /* linker padding */
    /* B8ECC 002B82CC 0C0AD504 */  .word      0x0C0AD504 /* linker padding */
endlabel alSynDelete
