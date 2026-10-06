.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB084-0xBB0B0 (VRAM 0x002BA484) */
glabel libm_ldexp
    /* BB084 002BA484 10C00005 */  beqz       $a2, .L002BA49C
    /* BB088 002BA488 24020001 */   addiu     $v0, $zero, 0x1
    /* BB08C 002BA48C 00C21004 */  sllv       $v0, $v0, $a2
    /* BB090 002BA490 44820000 */  mtc1       $v0, $fv0
    /* BB094 002BA494 46800021 */  cvt.d.w    $fv0, $fv0
    /* BB098 002BA498 46206302 */  mul.d      $fa0, $fa0, $fv0
  .L002BA49C:
    /* BB09C 002BA49C 03E00008 */  jr         $ra
    /* BB0A0 002BA4A0 46206006 */   mov.d     $fv0, $fa0


    /* BB0A4 002BA4A4 02202021 */  .word      0x02202021 /* linker padding */
    /* BB0A8 002BA4A8 02602821 */  .word      0x02602821 /* linker padding */
    /* BB0AC 002BA4AC 02403021 */  .word      0x02403021 /* linker padding */
endlabel libm_ldexp
