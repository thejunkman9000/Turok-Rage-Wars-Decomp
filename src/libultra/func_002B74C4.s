.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB80C4-0xB8120 (VRAM 0x002B74C4) */
glabel func_002B74C4
    /* B80C4 002B74C4 8C830008 */  lw         $v1, 0x8($a0)
    /* B80C8 002B74C8 90620000 */  lbu        $v0, 0x0($v1)
    /* B80CC 002B74CC 24630001 */  addiu      $v1, $v1, 0x1
    /* B80D0 002B74D0 AC830008 */  sw         $v1, 0x8($a0)
    /* B80D4 002B74D4 90670000 */  lbu        $a3, 0x0($v1)
    /* B80D8 002B74D8 24650001 */  addiu      $a1, $v1, 0x1
    /* B80DC 002B74DC AC850008 */  sw         $a1, 0x8($a0)
    /* B80E0 002B74E0 90660001 */  lbu        $a2, 0x1($v1)
    /* B80E4 002B74E4 24650002 */  addiu      $a1, $v1, 0x2
    /* B80E8 002B74E8 AC850008 */  sw         $a1, 0x8($a0)
    /* B80EC 002B74EC 90650002 */  lbu        $a1, 0x2($v1)
    /* B80F0 002B74F0 24630003 */  addiu      $v1, $v1, 0x3
    /* B80F4 002B74F4 AC830008 */  sw         $v1, 0x8($a0)
    /* B80F8 002B74F8 00021600 */  sll        $v0, $v0, 24
    /* B80FC 002B74FC 00073C00 */  sll        $a3, $a3, 16
    /* B8100 002B7500 00471025 */  or         $v0, $v0, $a3
    /* B8104 002B7504 00063200 */  sll        $a2, $a2, 8
    /* B8108 002B7508 00461025 */  or         $v0, $v0, $a2
    /* B810C 002B750C 03E00008 */  jr         $ra
    /* B8110 002B7510 00451025 */   or        $v0, $v0, $a1


    /* B8114 002B7514 8C44000C */  .word      0x8C44000C /* linker padding */
    /* B8118 002B7518 8C820008 */  .word      0x8C820008 /* linker padding */
    /* B811C 002B751C 0040F809 */  .word      0x0040F809 /* linker padding */
endlabel func_002B74C4
