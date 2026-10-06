.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAFB84-0xAFCE4 (VRAM 0x002AEF84) */
glabel func_002AEF84
    /* AFB84 002AEF84 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AFB88 002AEF88 AFB30024 */  sw         $s3, 0x24($sp)
    /* AFB8C 002AEF8C 00009821 */  addu       $s3, $zero, $zero
    /* AFB90 002AEF90 AFB1001C */  sw         $s1, 0x1C($sp)
    /* AFB94 002AEF94 27B10014 */  addiu      $s1, $sp, 0x14
    /* AFB98 002AEF98 02202021 */  addu       $a0, $s1, $zero
    /* AFB9C 002AEF9C AFBF0028 */  sw         $ra, 0x28($sp)
    /* AFBA0 002AEFA0 AFB20020 */  sw         $s2, 0x20($sp)
    /* AFBA4 002AEFA4 0C0AB8E0 */  jal        func_002AE380
    /* AFBA8 002AEFA8 AFB00018 */   sw        $s0, 0x18($sp)
    /* AFBAC 002AEFAC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFBB0 002AEFB0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFBB4 002AEFB4 3C12800D */  lui        $s2, %hi(D_800CB480)
    /* AFBB8 002AEFB8 2652B480 */  addiu      $s2, $s2, %lo(D_800CB480)
    /* AFBBC 002AEFBC 14400042 */  bnez       $v0, .L002AF0C8
    /* AFBC0 002AEFC0 02601021 */   addu      $v0, $s3, $zero
    /* AFBC4 002AEFC4 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFBC8 002AEFC8 02202021 */  addu       $a0, $s1, $zero
    /* AFBCC 002AEFCC 0C0AB8E0 */  jal        func_002AE380
    /* AFBD0 002AEFD0 00028200 */   sll       $s0, $v0, 8
    /* AFBD4 002AEFD4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFBD8 002AEFD8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFBDC 002AEFDC 1440003A */  bnez       $v0, .L002AF0C8
    /* AFBE0 002AEFE0 02601021 */   addu      $v0, $s3, $zero
    /* AFBE4 002AEFE4 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFBE8 002AEFE8 02202021 */  addu       $a0, $s1, $zero
    /* AFBEC 002AEFEC 0C0AB8E0 */  jal        func_002AE380
    /* AFBF0 002AEFF0 02028025 */   or        $s0, $s0, $v0
    /* AFBF4 002AEFF4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFBF8 002AEFF8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFBFC 002AEFFC 14400031 */  bnez       $v0, .L002AF0C4
    /* AFC00 002AF000 00108200 */   sll       $s0, $s0, 8
    /* AFC04 002AF004 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFC08 002AF008 02202021 */  addu       $a0, $s1, $zero
    /* AFC0C 002AF00C 0C0AB8E0 */  jal        func_002AE380
    /* AFC10 002AF010 02028025 */   or        $s0, $s0, $v0
    /* AFC14 002AF014 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFC18 002AF018 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFC1C 002AF01C 14400029 */  bnez       $v0, .L002AF0C4
    /* AFC20 002AF020 00108200 */   sll       $s0, $s0, 8
    /* AFC24 002AF024 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFC28 002AF028 02402021 */  addu       $a0, $s2, $zero
    /* AFC2C 002AF02C 02028025 */  or         $s0, $s0, $v0
    /* AFC30 002AF030 0C0B093C */  jal        strlen
    /* AFC34 002AF034 AFB00010 */   sw        $s0, 0x10($sp)
    /* AFC38 002AF038 8FA40010 */  lw         $a0, 0x10($sp)
    /* AFC3C 002AF03C 0082102B */  sltu       $v0, $a0, $v0
    /* AFC40 002AF040 14400004 */  bnez       $v0, .L002AF054
    /* AFC44 002AF044 00808021 */   addu      $s0, $a0, $zero
    /* AFC48 002AF048 0C0B093C */  jal        strlen
    /* AFC4C 002AF04C 02402021 */   addu      $a0, $s2, $zero
    /* AFC50 002AF050 00408021 */  addu       $s0, $v0, $zero
  .L002AF054:
    /* AFC54 002AF054 00102602 */  srl        $a0, $s0, 24
    /* AFC58 002AF058 0C0AB96B */  jal        func_002AE5AC
    /* AFC5C 002AF05C AFB00010 */   sw        $s0, 0x10($sp)
    /* AFC60 002AF060 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFC64 002AF064 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFC68 002AF068 1440000F */  bnez       $v0, .L002AF0A8
    /* AFC6C 002AF06C 00102402 */   srl       $a0, $s0, 16
    /* AFC70 002AF070 0C0AB96B */  jal        func_002AE5AC
    /* AFC74 002AF074 308400FF */   andi      $a0, $a0, 0xFF
    /* AFC78 002AF078 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFC7C 002AF07C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFC80 002AF080 14400009 */  bnez       $v0, .L002AF0A8
    /* AFC84 002AF084 00102202 */   srl       $a0, $s0, 8
    /* AFC88 002AF088 0C0AB96B */  jal        func_002AE5AC
    /* AFC8C 002AF08C 308400FF */   andi      $a0, $a0, 0xFF
    /* AFC90 002AF090 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFC94 002AF094 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFC98 002AF098 14400003 */  bnez       $v0, .L002AF0A8
    /* AFC9C 002AF09C 00000000 */   nop
    /* AFCA0 002AF0A0 0C0AB96B */  jal        func_002AE5AC
    /* AFCA4 002AF0A4 320400FF */   andi      $a0, $s0, 0xFF
  .L002AF0A8:
    /* AFCA8 002AF0A8 8FA50010 */  lw         $a1, 0x10($sp)
    /* AFCAC 002AF0AC 0C0ABAAD */  jal        func_002AEAB4
    /* AFCB0 002AF0B0 02402021 */   addu      $a0, $s2, $zero
    /* AFCB4 002AF0B4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFCB8 002AF0B8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFCBC 002AF0BC 50400001 */  beql       $v0, $zero, .L002AF0C4
    /* AFCC0 002AF0C0 24130001 */   addiu     $s3, $zero, 0x1
  .L002AF0C4:
    /* AFCC4 002AF0C4 02601021 */  addu       $v0, $s3, $zero
  .L002AF0C8:
    /* AFCC8 002AF0C8 8FBF0028 */  lw         $ra, 0x28($sp)
    /* AFCCC 002AF0CC 8FB30024 */  lw         $s3, 0x24($sp)
    /* AFCD0 002AF0D0 8FB20020 */  lw         $s2, 0x20($sp)
    /* AFCD4 002AF0D4 8FB1001C */  lw         $s1, 0x1C($sp)
    /* AFCD8 002AF0D8 8FB00018 */  lw         $s0, 0x18($sp)
    /* AFCDC 002AF0DC 03E00008 */  jr         $ra
    /* AFCE0 002AF0E0 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002AEF84
