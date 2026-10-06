.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5C80-0xC5CFC (VRAM 0x002C5080) */
glabel func_002C5080
    /* C5C80 002C5080 00804021 */  addu       $t0, $a0, $zero
    /* C5C84 002C5084 00003821 */  addu       $a3, $zero, $zero
  .L002C5088:
    /* C5C88 002C5088 00071400 */  sll        $v0, $a3, 16
    /* C5C8C 002C508C 00021403 */  sra        $v0, $v0, 16
    /* C5C90 002C5090 000220C0 */  sll        $a0, $v0, 3
    /* C5C94 002C5094 00882021 */  addu       $a0, $a0, $t0
    /* C5C98 002C5098 00021080 */  sll        $v0, $v0, 2
    /* C5C9C 002C509C 00451821 */  addu       $v1, $v0, $a1
    /* C5CA0 002C50A0 C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C5CA4 002C50A4 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C5CA8 002C50A8 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C5CAC 002C50AC 00461021 */  addu       $v0, $v0, $a2
    /* C5CB0 002C50B0 C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C5CB4 002C50B4 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C5CB8 002C50B8 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C5CBC 002C50BC 00000000 */  nop
    /* C5CC0 002C50C0 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C5CC4 002C50C4 00000000 */  nop
    /* C5CC8 002C50C8 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C5CCC 002C50CC 24E20001 */  addiu      $v0, $a3, 0x1
    /* C5CD0 002C50D0 00403821 */  addu       $a3, $v0, $zero
    /* C5CD4 002C50D4 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C5CD8 002C50D8 00021400 */  sll        $v0, $v0, 16
    /* C5CDC 002C50DC 00021403 */  sra        $v0, $v0, 16
    /* C5CE0 002C50E0 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C5CE4 002C50E4 28420080 */  slti       $v0, $v0, 0x80
    /* C5CE8 002C50E8 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C5CEC 002C50EC 1440FFE6 */  bnez       $v0, .L002C5088
    /* C5CF0 002C50F0 E4820004 */   swc1      $fv1, 0x4($a0)
    /* C5CF4 002C50F4 03E00008 */  jr         $ra
    /* C5CF8 002C50F8 00000000 */   nop
endlabel func_002C5080
