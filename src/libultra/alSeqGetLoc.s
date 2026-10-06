.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7FA8-0xB7FC4 (VRAM 0x002B73A8) */
glabel alSeqGetLoc
    /* B7FA8 002B73A8 8C820008 */  lw         $v0, 0x8($a0)
    /* B7FAC 002B73AC ACA20000 */  sw         $v0, 0x0($a1)
    /* B7FB0 002B73B0 9482001A */  lhu        $v0, 0x1A($a0)
    /* B7FB4 002B73B4 A4A2000C */  sh         $v0, 0xC($a1)
    /* B7FB8 002B73B8 8C82000C */  lw         $v0, 0xC($a0)
    /* B7FBC 002B73BC 03E00008 */  jr         $ra
    /* B7FC0 002B73C0 ACA20004 */   sw        $v0, 0x4($a1)
endlabel alSeqGetLoc
