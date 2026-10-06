.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBC150-0xBC190 (VRAM 0x002BB550) */
glabel func_002BB550
    /* BC150 002BB550 24020001 */  addiu      $v0, $zero, 0x1
    /* BC154 002BB554 10A20005 */  beq        $a1, $v0, .L002BB56C
    /* BC158 002BB558 24020006 */   addiu     $v0, $zero, 0x6
    /* BC15C 002BB55C 10A20005 */  beq        $a1, $v0, .L002BB574
    /* BC160 002BB560 00001021 */   addu      $v0, $zero, $zero
    /* BC164 002BB564 080AED5F */  j          .L002BB57C
    /* BC168 002BB568 00000000 */   nop
  .L002BB56C:
    /* BC16C 002BB56C 080AED5E */  j          .L002BB578
    /* BC170 002BB570 AC860000 */   sw        $a2, 0x0($a0)
  .L002BB574:
    /* BC174 002BB574 AC860014 */  sw         $a2, 0x14($a0)
  .L002BB578:
    /* BC178 002BB578 00001021 */  addu       $v0, $zero, $zero
  .L002BB57C:
    /* BC17C 002BB57C 03E00008 */  jr         $ra
    /* BC180 002BB580 00000000 */   nop


    /* BC184 002BB584 AFB00010 */  .word      0xAFB00010 /* linker padding */
    /* BC188 002BB588 00808021 */  .word      0x00808021 /* linker padding */
    /* BC18C 002BB58C AFBF0018 */  .word      0xAFBF0018 /* linker padding */
endlabel func_002BB550
