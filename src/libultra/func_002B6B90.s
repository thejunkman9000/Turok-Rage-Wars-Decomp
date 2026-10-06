.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7790-0xB77E4 (VRAM 0x002B6B90) */
glabel func_002B6B90
    /* B7790 002B6B90 8C820060 */  lw         $v0, 0x60($a0)
    /* B7794 002B6B94 00063100 */  sll        $a2, $a2, 4
    /* B7798 002B6B98 00C21021 */  addu       $v0, $a2, $v0
    /* B779C 002B6B9C AC450000 */  sw         $a1, 0x0($v0)
    /* B77A0 002B6BA0 8C820060 */  lw         $v0, 0x60($a0)
    /* B77A4 002B6BA4 90A30001 */  lbu        $v1, 0x1($a1)
    /* B77A8 002B6BA8 00C21021 */  addu       $v0, $a2, $v0
    /* B77AC 002B6BAC A0430007 */  sb         $v1, 0x7($v0)
    /* B77B0 002B6BB0 8C820060 */  lw         $v0, 0x60($a0)
    /* B77B4 002B6BB4 90A30000 */  lbu        $v1, 0x0($a1)
    /* B77B8 002B6BB8 00C21021 */  addu       $v0, $a2, $v0
    /* B77BC 002B6BBC A0430009 */  sb         $v1, 0x9($v0)
    /* B77C0 002B6BC0 8C820060 */  lw         $v0, 0x60($a0)
    /* B77C4 002B6BC4 90A30002 */  lbu        $v1, 0x2($a1)
    /* B77C8 002B6BC8 00C21021 */  addu       $v0, $a2, $v0
    /* B77CC 002B6BCC A0430008 */  sb         $v1, 0x8($v0)
    /* B77D0 002B6BD0 8C820060 */  lw         $v0, 0x60($a0)
    /* B77D4 002B6BD4 94A3000C */  lhu        $v1, 0xC($a1)
    /* B77D8 002B6BD8 00C23021 */  addu       $a2, $a2, $v0
    /* B77DC 002B6BDC 03E00008 */  jr         $ra
    /* B77E0 002B6BE0 A4C30004 */   sh        $v1, 0x4($a2)
endlabel func_002B6B90
