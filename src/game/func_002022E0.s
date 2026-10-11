.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x2EE0-0x2F8C (VRAM 0x002022E0) */
glabel func_002022E0
    /* 2EE0 002022E0 23BDFFF8 */  addi       $sp, $sp, -0x8 /* handwritten instruction */
    /* 2EE4 002022E4 AFBF0000 */  sw         $ra, 0x0($sp)
    /* 2EE8 002022E8 3C080020 */  lui        $t0, %hi(func_00202268 + 0x8)
    /* 2EEC 002022EC 25082270 */  addiu      $t0, $t0, %lo(func_00202268 + 0x8)
    /* 2EF0 002022F0 3C090020 */  lui        $t1, %hi(func_00202268 + 0x1C)
    /* 2EF4 002022F4 25292284 */  addiu      $t1, $t1, %lo(func_00202268 + 0x1C)
    /* 2EF8 002022F8 3C0A8000 */  lui        $t2, (0x80000180 >> 16)
    /* 2EFC 002022FC 354A0180 */  ori        $t2, $t2, (0x80000180 & 0xFFFF)
    /* 2F00 00202300 3C0B0020 */  lui        $t3, %hi(func_00202268 + 0x1C)
    /* 2F04 00202304 256B2284 */  addiu      $t3, $t3, %lo(func_00202268 + 0x1C)
  .L00202308:
    /* 2F08 00202308 8D4C0000 */  lw         $t4, 0x0($t2)
    /* 2F0C 0020230C 8D0D0000 */  lw         $t5, 0x0($t0)
    /* 2F10 00202310 25080004 */  addiu      $t0, $t0, 0x4
    /* 2F14 00202314 AD2C0000 */  sw         $t4, 0x0($t1)
    /* 2F18 00202318 25290004 */  addiu      $t1, $t1, 0x4
    /* 2F1C 0020231C AD4D0000 */  sw         $t5, 0x0($t2)
    /* 2F20 00202320 150BFFF9 */  bne        $t0, $t3, .L00202308
    /* 2F24 00202324 254A0004 */   addiu     $t2, $t2, 0x4
    /* 2F28 00202328 3C080020 */  lui        $t0, %hi(func_00202268 + 0x40)
    /* 2F2C 0020232C 250822A8 */  addiu      $t0, $t0, %lo(func_00202268 + 0x40)
    /* 2F30 00202330 3C090020 */  lui        $t1, %hi(func_00202268 + 0x54)
    /* 2F34 00202334 252922BC */  addiu      $t1, $t1, %lo(func_00202268 + 0x54)
    /* 2F38 00202338 3C0A8000 */  lui        $t2, %hi(D_80000000)
    /* 2F3C 0020233C 3C0B0020 */  lui        $t3, %hi(func_00202268 + 0x54)
    /* 2F40 00202340 256B22BC */  addiu      $t3, $t3, %lo(func_00202268 + 0x54)
  .L00202344:
    /* 2F44 00202344 8D4C0000 */  lw         $t4, %lo(D_80000000)($t2)
    /* 2F48 00202348 8D0D0000 */  lw         $t5, 0x0($t0)
    /* 2F4C 0020234C 25080004 */  addiu      $t0, $t0, 0x4
    /* 2F50 00202350 AD2C0000 */  sw         $t4, 0x0($t1)
    /* 2F54 00202354 25290004 */  addiu      $t1, $t1, 0x4
    /* 2F58 00202358 AD4D0000 */  sw         $t5, %lo(D_80000000)($t2)
    /* 2F5C 0020235C 150BFFF9 */  bne        $t0, $t3, .L00202344
    /* 2F60 00202360 254A0004 */   addiu     $t2, $t2, %lo(D_80000004)
    /* 2F64 00202364 0C0808E3 */  jal        func_0020238C
    /* 2F68 00202368 00000000 */   nop
    /* 2F6C 0020236C 0C0808EA */  jal        func_002023A8
    /* 2F70 00202370 00000000 */   nop
    /* 2F74 00202374 2408F7FE */  addiu      $t0, $zero, -0x802
    /* 2F78 00202378 3C01800F */  lui        $at, %hi(D_800F7468)
    /* 2F7C 0020237C AC287468 */  sw         $t0, %lo(D_800F7468)($at)
    /* 2F80 00202380 8FBF0000 */  lw         $ra, 0x0($sp)
    /* 2F84 00202384 03E00008 */  jr         $ra
    /* 2F88 00202388 23BD0008 */   addi      $sp, $sp, 0x8 /* handwritten instruction */
endlabel func_002022E0
