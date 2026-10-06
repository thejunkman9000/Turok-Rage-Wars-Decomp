.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8094-0xB80C4 (VRAM 0x002B7494) */
glabel __alSeqReadShort
    /* B8094 002B7494 8C830008 */  lw         $v1, 0x8($a0)
    /* B8098 002B7498 90620000 */  lbu        $v0, 0x0($v1)
    /* B809C 002B749C 24630001 */  addiu      $v1, $v1, 0x1
    /* B80A0 002B74A0 AC830008 */  sw         $v1, 0x8($a0)
    /* B80A4 002B74A4 90650000 */  lbu        $a1, 0x0($v1)
    /* B80A8 002B74A8 24630001 */  addiu      $v1, $v1, 0x1
    /* B80AC 002B74AC AC830008 */  sw         $v1, 0x8($a0)
    /* B80B0 002B74B0 00021200 */  sll        $v0, $v0, 8
    /* B80B4 002B74B4 00451025 */  or         $v0, $v0, $a1
    /* B80B8 002B74B8 00021400 */  sll        $v0, $v0, 16
    /* B80BC 002B74BC 03E00008 */  jr         $ra
    /* B80C0 002B74C0 00021403 */   sra       $v0, $v0, 16
endlabel __alSeqReadShort
