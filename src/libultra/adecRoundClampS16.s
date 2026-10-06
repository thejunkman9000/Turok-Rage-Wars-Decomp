.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5D34-0xC5DA0 (VRAM 0x002C5134) */
glabel adecRoundClampS16
    /* C5D34 002C5134 44800000 */  mtc1       $zero, $fv0
    /* C5D38 002C5138 460C003E */  c.le.s     $fv0, $fa0
    /* C5D3C 002C513C 00000000 */  nop
    /* C5D40 002C5140 45000009 */  bc1f       .L002C5168
    /* C5D44 002C5144 00000000 */   nop
    /* C5D48 002C5148 3C01800D */  lui        $at, %hi(D_800CCF38)
    /* C5D4C 002C514C C420CF38 */  lwc1       $fv0, %lo(D_800CCF38)($at)
    /* C5D50 002C5150 46006300 */  add.s      $fa0, $fa0, $fv0
    /* C5D54 002C5154 3C01800D */  lui        $at, %hi(D_800CCF3C)
    /* C5D58 002C5158 C420CF3C */  lwc1       $fv0, %lo(D_800CCF3C)($at)
    /* C5D5C 002C515C 460C003C */  c.lt.s     $fv0, $fa0
    /* C5D60 002C5160 080B1460 */  j          .L002C5180
    /* C5D64 002C5164 00000000 */   nop
  .L002C5168:
    /* C5D68 002C5168 3C01800D */  lui        $at, %hi(D_800CCF40)
    /* C5D6C 002C516C C420CF40 */  lwc1       $fv0, %lo(D_800CCF40)($at)
    /* C5D70 002C5170 46006301 */  sub.s      $fa0, $fa0, $fv0
    /* C5D74 002C5174 3C01800D */  lui        $at, %hi(D_800CCF44)
    /* C5D78 002C5178 C420CF44 */  lwc1       $fv0, %lo(D_800CCF44)($at)
    /* C5D7C 002C517C 4600603C */  c.lt.s     $fa0, $fv0
  .L002C5180:
    /* C5D80 002C5180 00000000 */  nop
    /* C5D84 002C5184 45030001 */  bc1tl      .L002C518C
    /* C5D88 002C5188 46000306 */   mov.s     $fa0, $fv0
  .L002C518C:
    /* C5D8C 002C518C 4600604D */  trunc.w.s  $fv0f, $fa0
    /* C5D90 002C5190 44020800 */  mfc1       $v0, $fv0f
    /* C5D94 002C5194 00021400 */  sll        $v0, $v0, 16
    /* C5D98 002C5198 03E00008 */  jr         $ra
    /* C5D9C 002C519C 00021403 */   sra       $v0, $v0, 16
endlabel adecRoundClampS16
