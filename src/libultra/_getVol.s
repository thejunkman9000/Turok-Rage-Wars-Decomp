.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBAF58-0xBAFD0 (VRAM 0x002BA358) */
glabel _getVol
    /* BAF58 002BA358 000528C3 */  sra        $a1, $a1, 3
    /* BAF5C 002BA35C 14A00003 */  bnez       $a1, .L002BA36C
    /* BAF60 002BA360 00001821 */   addu      $v1, $zero, $zero
    /* BAF64 002BA364 03E00008 */  jr         $ra
    /* BAF68 002BA368 46006006 */   mov.s     $fv0, $fa0
  .L002BA36C:
    /* BAF6C 002BA36C 00061400 */  sll        $v0, $a2, 16
    /* BAF70 002BA370 44820800 */  mtc1       $v0, $fv0f
    /* BAF74 002BA374 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BAF78 002BA378 30E2FFFF */  andi       $v0, $a3, 0xFFFF
    /* BAF7C 002BA37C 44820000 */  mtc1       $v0, $fv0
    /* BAF80 002BA380 46800020 */  cvt.s.w    $fv0, $fv0
    /* BAF84 002BA384 46000840 */  add.s      $fv0f, $fv0f, $fv0
    /* BAF88 002BA388 3C01800D */  lui        $at, %hi(D_800CC958)
    /* BAF8C 002BA38C C420C958 */  lwc1       $fv0, %lo(D_800CC958)($at)
    /* BAF90 002BA390 3C01800D */  lui        $at, %hi(D_800CC95C)
    /* BAF94 002BA394 C422C95C */  lwc1       $fv1, %lo(D_800CC95C)($at)
    /* BAF98 002BA398 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* BAF9C 002BA39C 30A20001 */  andi       $v0, $a1, 0x1
  .L002BA3A0:
    /* BAFA0 002BA3A0 10400002 */  beqz       $v0, .L002BA3AC
    /* BAFA4 002BA3A4 00052843 */   sra       $a1, $a1, 1
    /* BAFA8 002BA3A8 46011082 */  mul.s      $fv1, $fv1, $fv0f
  .L002BA3AC:
    /* BAFAC 002BA3AC 10A00005 */  beqz       $a1, .L002BA3C4
    /* BAFB0 002BA3B0 24630001 */   addiu     $v1, $v1, 0x1
    /* BAFB4 002BA3B4 28620020 */  slti       $v0, $v1, 0x20
    /* BAFB8 002BA3B8 46010842 */  mul.s      $fv0f, $fv0f, $fv0f
    /* BAFBC 002BA3BC 1440FFF8 */  bnez       $v0, .L002BA3A0
    /* BAFC0 002BA3C0 30A20001 */   andi      $v0, $a1, 0x1
  .L002BA3C4:
    /* BAFC4 002BA3C4 46026002 */  mul.s      $fv0, $fa0, $fv1
    /* BAFC8 002BA3C8 03E00008 */  jr         $ra
    /* BAFCC 002BA3CC 00000000 */   nop
endlabel _getVol
