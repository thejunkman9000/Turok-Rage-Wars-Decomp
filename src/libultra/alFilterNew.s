.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB0B0-0xBB0CC (VRAM 0x002BA4B0) */
glabel alFilterNew
    /* BB0B0 002BA4B0 AC800000 */  sw         $zero, 0x0($a0)
    /* BB0B4 002BA4B4 AC850004 */  sw         $a1, 0x4($a0)
    /* BB0B8 002BA4B8 AC860008 */  sw         $a2, 0x8($a0)
    /* BB0BC 002BA4BC A480000C */  sh         $zero, 0xC($a0)
    /* BB0C0 002BA4C0 A480000E */  sh         $zero, 0xE($a0)
    /* BB0C4 002BA4C4 03E00008 */  jr         $ra
    /* BB0C8 002BA4C8 AC870010 */   sw        $a3, 0x10($a0)
endlabel alFilterNew
