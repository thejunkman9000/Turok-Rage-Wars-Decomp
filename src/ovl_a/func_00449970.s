.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B7970-0x1B7B44 (VRAM 0x00449970) */
glabel func_00449970
    /* 1B7970 00449970 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* 1B7974 00449974 AFB20018 */  sw         $s2, 0x18($sp)
    /* 1B7978 00449978 00809021 */  addu       $s2, $a0, $zero
    /* 1B797C 0044997C AFB10014 */  sw         $s1, 0x14($sp)
    /* 1B7980 00449980 00A08821 */  addu       $s1, $a1, $zero
    /* 1B7984 00449984 AFB50024 */  sw         $s5, 0x24($sp)
    /* 1B7988 00449988 00C0A821 */  addu       $s5, $a2, $zero
    /* 1B798C 0044998C 00003821 */  addu       $a3, $zero, $zero
    /* 1B7990 00449990 AFBF0028 */  sw         $ra, 0x28($sp)
    /* 1B7994 00449994 AFB40020 */  sw         $s4, 0x20($sp)
    /* 1B7998 00449998 AFB3001C */  sw         $s3, 0x1C($sp)
    /* 1B799C 0044999C AFB00010 */  sw         $s0, 0x10($sp)
    /* 1B79A0 004499A0 0C092CE6 */  jal        func_0024B398
    /* 1B79A4 004499A4 AE5201D8 */   sw        $s2, 0x1D8($s2)
    /* 1B79A8 004499A8 3C030010 */  lui        $v1, (0x100000 >> 16)
    /* 1B79AC 004499AC 8E420100 */  lw         $v0, 0x100($s2)
    /* 1B79B0 004499B0 3C048014 */  lui        $a0, %hi(D_801462E5)
    /* 1B79B4 004499B4 248462E5 */  addiu      $a0, $a0, %lo(D_801462E5)
    /* 1B79B8 004499B8 AE5201D8 */  sw         $s2, 0x1D8($s2)
    /* 1B79BC 004499BC 00431025 */  or         $v0, $v0, $v1
    /* 1B79C0 004499C0 3C030001 */  lui        $v1, (0x10000 >> 16)
    /* 1B79C4 004499C4 00431025 */  or         $v0, $v0, $v1
    /* 1B79C8 004499C8 3C030100 */  lui        $v1, (0x1000000 >> 16)
    /* 1B79CC 004499CC 00431025 */  or         $v0, $v0, $v1
    /* 1B79D0 004499D0 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* 1B79D4 004499D4 00431825 */  or         $v1, $v0, $v1
    /* 1B79D8 004499D8 AE430100 */  sw         $v1, 0x100($s2)
    /* 1B79DC 004499DC 90820000 */  lbu        $v0, 0x0($a0)
    /* 1B79E0 004499E0 14400003 */  bnez       $v0, .L004499F0
    /* 1B79E4 004499E4 3C021000 */   lui       $v0, (0x10000000 >> 16)
    /* 1B79E8 004499E8 00621025 */  or         $v0, $v1, $v0
    /* 1B79EC 004499EC AE420100 */  sw         $v0, 0x100($s2)
  .L004499F0:
    /* 1B79F0 004499F0 3C020025 */  lui        $v0, %hi(func_0024B52C)
    /* 1B79F4 004499F4 2442B52C */  addiu      $v0, $v0, %lo(func_0024B52C)
    /* 1B79F8 004499F8 AE42028C */  sw         $v0, 0x28C($s2)
    /* 1B79FC 004499FC 3C020023 */  lui        $v0, %hi(func_0022E0A0)
    /* 1B7A00 00449A00 2442E0A0 */  addiu      $v0, $v0, %lo(func_0022E0A0)
    /* 1B7A04 00449A04 3C140022 */  lui        $s4, %hi(func_00219A40)
    /* 1B7A08 00449A08 26949A40 */  addiu      $s4, $s4, %lo(func_00219A40)
    /* 1B7A0C 00449A0C 3C130023 */  lui        $s3, %hi(func_0022E250)
    /* 1B7A10 00449A10 2673E250 */  addiu      $s3, $s3, %lo(func_0022E250)
    /* 1B7A14 00449A14 AE420290 */  sw         $v0, 0x290($s2)
    /* 1B7A18 00449A18 AE540280 */  sw         $s4, 0x280($s2)
    /* 1B7A1C 00449A1C AE530288 */  sw         $s3, 0x288($s2)
    /* 1B7A20 00449A20 90820000 */  lbu        $v0, 0x0($a0)
    /* 1B7A24 00449A24 10400004 */  beqz       $v0, .L00449A38
    /* 1B7A28 00449A28 265002E8 */   addiu     $s0, $s2, 0x2E8
    /* 1B7A2C 00449A2C 3C020022 */  lui        $v0, %hi(func_0021A2D4)
    /* 1B7A30 00449A30 2442A2D4 */  addiu      $v0, $v0, %lo(func_0021A2D4)
    /* 1B7A34 00449A34 AE42027C */  sw         $v0, 0x27C($s2)
  .L00449A38:
    /* 1B7A38 00449A38 02002021 */  addu       $a0, $s0, $zero
    /* 1B7A3C 00449A3C 02202821 */  addu       $a1, $s1, $zero
    /* 1B7A40 00449A40 02A03021 */  addu       $a2, $s5, $zero
    /* 1B7A44 00449A44 00003821 */  addu       $a3, $zero, $zero
    /* 1B7A48 00449A48 0C092CE6 */  jal        func_0024B398
    /* 1B7A4C 00449A4C AE5204C0 */   sw        $s2, 0x4C0($s2)
    /* 1B7A50 00449A50 3C07FFFE */  lui        $a3, (0xFFFEFFFF >> 16)
    /* 1B7A54 00449A54 34E7FFFF */  ori        $a3, $a3, (0xFFFEFFFF & 0xFFFF)
    /* 1B7A58 00449A58 02002021 */  addu       $a0, $s0, $zero
    /* 1B7A5C 00449A5C 26510458 */  addiu      $s1, $s2, 0x458
    /* 1B7A60 00449A60 02202821 */  addu       $a1, $s1, $zero
    /* 1B7A64 00449A64 00003021 */  addu       $a2, $zero, $zero
    /* 1B7A68 00449A68 3C020023 */  lui        $v0, %hi(func_0022F5D0)
    /* 1B7A6C 00449A6C 2442F5D0 */  addiu      $v0, $v0, %lo(func_0022F5D0)
    /* 1B7A70 00449A70 AE420574 */  sw         $v0, 0x574($s2)
    /* 1B7A74 00449A74 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B7A78 00449A78 A242048C */  sb         $v0, 0x48C($s2)
    /* 1B7A7C 00449A7C 8E4203E8 */  lw         $v0, 0x3E8($s2)
    /* 1B7A80 00449A80 3C01800C */  lui        $at, %hi(D_800C73E4)
    /* 1B7A84 00449A84 C42073E4 */  lwc1       $fv0, %lo(D_800C73E4)($at)
    /* 1B7A88 00449A88 3C030020 */  lui        $v1, (0x200000 >> 16)
    /* 1B7A8C 00449A8C AE5204C0 */  sw         $s2, 0x4C0($s2)
    /* 1B7A90 00449A90 AE540568 */  sw         $s4, 0x568($s2)
    /* 1B7A94 00449A94 AE530570 */  sw         $s3, 0x570($s2)
    /* 1B7A98 00449A98 00431025 */  or         $v0, $v0, $v1
    /* 1B7A9C 00449A9C AE4203E8 */  sw         $v0, 0x3E8($s2)
    /* 1B7AA0 00449AA0 00401821 */  addu       $v1, $v0, $zero
    /* 1B7AA4 00449AA4 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B7AA8 00449AA8 00671824 */  and        $v1, $v1, $a3
    /* 1B7AAC 00449AAC A642062E */  sh         $v0, 0x62E($s2)
    /* 1B7AB0 00449AB0 E6400338 */  swc1       $fv0, 0x338($s2)
    /* 1B7AB4 00449AB4 E640033C */  swc1       $fv0, 0x33C($s2)
    /* 1B7AB8 00449AB8 E6400340 */  swc1       $fv0, 0x340($s2)
    /* 1B7ABC 00449ABC 0C08505E */  jal        func_00214178
    /* 1B7AC0 00449AC0 AE4303E8 */   sw        $v1, 0x3E8($s2)
    /* 1B7AC4 00449AC4 02002021 */  addu       $a0, $s0, $zero
    /* 1B7AC8 00449AC8 0C08C97B */  jal        func_002325EC
    /* 1B7ACC 00449ACC 02202821 */   addu      $a1, $s1, $zero
    /* 1B7AD0 00449AD0 02402021 */  addu       $a0, $s2, $zero
    /* 1B7AD4 00449AD4 0C088297 */  jal        func_00220A5C
    /* 1B7AD8 00449AD8 02402821 */   addu      $a1, $s2, $zero
    /* 1B7ADC 00449ADC 8E4405DC */  lw         $a0, 0x5DC($s2)
    /* 1B7AE0 00449AE0 10800003 */  beqz       $a0, .L00449AF0
    /* 1B7AE4 00449AE4 00000000 */   nop
    /* 1B7AE8 00449AE8 0C091615 */  jal        func_00245854
    /* 1B7AEC 00449AEC 00000000 */   nop
  .L00449AF0:
    /* 1B7AF0 00449AF0 8E420018 */  lw         $v0, 0x18($s2)
    /* 1B7AF4 00449AF4 C44000FC */  lwc1       $fv0, 0xFC($v0)
    /* 1B7AF8 00449AF8 E6400050 */  swc1       $fv0, 0x50($s2)
    /* 1B7AFC 00449AFC C4400100 */  lwc1       $fv0, 0x100($v0)
    /* 1B7B00 00449B00 E6400054 */  swc1       $fv0, 0x54($s2)
    /* 1B7B04 00449B04 C4400104 */  lwc1       $fv0, 0x104($v0)
    /* 1B7B08 00449B08 00402021 */  addu       $a0, $v0, $zero
    /* 1B7B0C 00449B0C E6400058 */  swc1       $fv0, 0x58($s2)
    /* 1B7B10 00449B10 8C820004 */  lw         $v0, 0x4($a0)
    /* 1B7B14 00449B14 2403FFFB */  addiu      $v1, $zero, -0x5
    /* 1B7B18 00449B18 00431024 */  and        $v0, $v0, $v1
    /* 1B7B1C 00449B1C AC820004 */  sw         $v0, 0x4($a0)
    /* 1B7B20 00449B20 8FBF0028 */  lw         $ra, 0x28($sp)
    /* 1B7B24 00449B24 8FB50024 */  lw         $s5, 0x24($sp)
    /* 1B7B28 00449B28 8FB40020 */  lw         $s4, 0x20($sp)
    /* 1B7B2C 00449B2C 8FB3001C */  lw         $s3, 0x1C($sp)
    /* 1B7B30 00449B30 8FB20018 */  lw         $s2, 0x18($sp)
    /* 1B7B34 00449B34 8FB10014 */  lw         $s1, 0x14($sp)
    /* 1B7B38 00449B38 8FB00010 */  lw         $s0, 0x10($sp)
    /* 1B7B3C 00449B3C 03E00008 */  jr         $ra
    /* 1B7B40 00449B40 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_00449970
