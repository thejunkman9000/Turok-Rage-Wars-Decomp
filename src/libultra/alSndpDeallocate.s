.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB82A0-0xB82F0 (VRAM 0x002B76A0) */
glabel alSndpDeallocate
    /* B82A0 002B76A0 00052C00 */  sll        $a1, $a1, 16
    /* B82A4 002B76A4 00052C03 */  sra        $a1, $a1, 16
    /* B82A8 002B76A8 00051040 */  sll        $v0, $a1, 1
    /* B82AC 002B76AC 00451021 */  addu       $v0, $v0, $a1
    /* B82B0 002B76B0 8C830040 */  lw         $v1, 0x40($a0)
    /* B82B4 002B76B4 00021100 */  sll        $v0, $v0, 4
    /* B82B8 002B76B8 00431821 */  addu       $v1, $v0, $v1
    /* B82BC 002B76BC 8C620028 */  lw         $v0, 0x28($v1)
    /* B82C0 002B76C0 14400006 */  bnez       $v0, .L002B76DC
    /* B82C4 002B76C4 00000000 */   nop
    /* B82C8 002B76C8 AC60001C */  sw         $zero, 0x1C($v1)
    /* B82CC 002B76CC 8C82003C */  lw         $v0, 0x3C($a0)
    /* B82D0 002B76D0 14450002 */  bne        $v0, $a1, .L002B76DC
    /* B82D4 002B76D4 2402FFFF */   addiu     $v0, $zero, -0x1
    /* B82D8 002B76D8 AC82003C */  sw         $v0, 0x3C($a0)
  .L002B76DC:
    /* B82DC 002B76DC 03E00008 */  jr         $ra
    /* B82E0 002B76E0 00000000 */   nop


    /* B82E4 002B76E4 AFB7002C */  .word      0xAFB7002C /* linker padding */
    /* B82E8 002B76E8 00C0B821 */  .word      0x00C0B821 /* linker padding */
    /* B82EC 002B76EC AFBF0030 */  .word      0xAFBF0030 /* linker padding */
endlabel alSndpDeallocate
