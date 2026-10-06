.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAFCE4-0xAFDF0 (VRAM 0x002AF0E4) */
glabel dbgLinkCmdWriteHalf
    /* AFCE4 002AF0E4 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AFCE8 002AF0E8 AFB10024 */  sw         $s1, 0x24($sp)
    /* AFCEC 002AF0EC 27B10014 */  addiu      $s1, $sp, 0x14
    /* AFCF0 002AF0F0 02202021 */  addu       $a0, $s1, $zero
    /* AFCF4 002AF0F4 AFBF002C */  sw         $ra, 0x2C($sp)
    /* AFCF8 002AF0F8 AFB20028 */  sw         $s2, 0x28($sp)
    /* AFCFC 002AF0FC 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFD00 002AF100 AFB00020 */   sw        $s0, 0x20($sp)
    /* AFD04 002AF104 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFD08 002AF108 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFD0C 002AF10C 14400031 */  bnez       $v0, .L002AF1D4
    /* AFD10 002AF110 00009021 */   addu      $s2, $zero, $zero
    /* AFD14 002AF114 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFD18 002AF118 02202021 */  addu       $a0, $s1, $zero
    /* AFD1C 002AF11C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFD20 002AF120 00028200 */   sll       $s0, $v0, 8
    /* AFD24 002AF124 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFD28 002AF128 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFD2C 002AF12C 1440002A */  bnez       $v0, .L002AF1D8
    /* AFD30 002AF130 02401021 */   addu      $v0, $s2, $zero
    /* AFD34 002AF134 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFD38 002AF138 02202021 */  addu       $a0, $s1, $zero
    /* AFD3C 002AF13C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFD40 002AF140 02028025 */   or        $s0, $s0, $v0
    /* AFD44 002AF144 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFD48 002AF148 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFD4C 002AF14C 14400021 */  bnez       $v0, .L002AF1D4
    /* AFD50 002AF150 00108200 */   sll       $s0, $s0, 8
    /* AFD54 002AF154 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFD58 002AF158 02202021 */  addu       $a0, $s1, $zero
    /* AFD5C 002AF15C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFD60 002AF160 02028025 */   or        $s0, $s0, $v0
    /* AFD64 002AF164 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFD68 002AF168 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFD6C 002AF16C 14400019 */  bnez       $v0, .L002AF1D4
    /* AFD70 002AF170 00108200 */   sll       $s0, $s0, 8
    /* AFD74 002AF174 27B10018 */  addiu      $s1, $sp, 0x18
    /* AFD78 002AF178 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFD7C 002AF17C 02202021 */  addu       $a0, $s1, $zero
    /* AFD80 002AF180 02028025 */  or         $s0, $s0, $v0
    /* AFD84 002AF184 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFD88 002AF188 AFB00010 */   sw        $s0, 0x10($sp)
    /* AFD8C 002AF18C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFD90 002AF190 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFD94 002AF194 14400010 */  bnez       $v0, .L002AF1D8
    /* AFD98 002AF198 02401021 */   addu      $v0, $s2, $zero
    /* AFD9C 002AF19C 93A20018 */  lbu        $v0, 0x18($sp)
    /* AFDA0 002AF1A0 02202021 */  addu       $a0, $s1, $zero
    /* AFDA4 002AF1A4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFDA8 002AF1A8 00028200 */   sll       $s0, $v0, 8
    /* AFDAC 002AF1AC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFDB0 002AF1B0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFDB4 002AF1B4 14400008 */  bnez       $v0, .L002AF1D8
    /* AFDB8 002AF1B8 02401021 */   addu      $v0, $s2, $zero
    /* AFDBC 002AF1BC 24120001 */  addiu      $s2, $zero, 0x1
    /* AFDC0 002AF1C0 93A20018 */  lbu        $v0, 0x18($sp)
    /* AFDC4 002AF1C4 8FA30010 */  lw         $v1, 0x10($sp)
    /* AFDC8 002AF1C8 02021025 */  or         $v0, $s0, $v0
    /* AFDCC 002AF1CC A7A20016 */  sh         $v0, 0x16($sp)
    /* AFDD0 002AF1D0 A4620000 */  sh         $v0, 0x0($v1)
  .L002AF1D4:
    /* AFDD4 002AF1D4 02401021 */  addu       $v0, $s2, $zero
  .L002AF1D8:
    /* AFDD8 002AF1D8 8FBF002C */  lw         $ra, 0x2C($sp)
    /* AFDDC 002AF1DC 8FB20028 */  lw         $s2, 0x28($sp)
    /* AFDE0 002AF1E0 8FB10024 */  lw         $s1, 0x24($sp)
    /* AFDE4 002AF1E4 8FB00020 */  lw         $s0, 0x20($sp)
    /* AFDE8 002AF1E8 03E00008 */  jr         $ra
    /* AFDEC 002AF1EC 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel dbgLinkCmdWriteHalf
