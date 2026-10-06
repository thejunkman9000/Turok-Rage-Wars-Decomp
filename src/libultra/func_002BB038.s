.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBC38-0xBBDA8 (VRAM 0x002BB038) */
glabel func_002BB038
    /* BBC38 002BB038 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* BBC3C 002BB03C AFBE0030 */  sw         $fp, 0x30($sp)
    /* BBC40 002BB040 0080F021 */  addu       $fp, $a0, $zero
    /* BBC44 002BB044 AFB50024 */  sw         $s5, 0x24($sp)
    /* BBC48 002BB048 8FB50048 */  lw         $s5, 0x48($sp)
    /* BBC4C 002BB04C 00A02021 */  addu       $a0, $a1, $zero
    /* BBC50 002BB050 AFB7002C */  sw         $s7, 0x2C($sp)
    /* BBC54 002BB054 00C0B821 */  addu       $s7, $a2, $zero
    /* BBC58 002BB058 AFBF0034 */  sw         $ra, 0x34($sp)
    /* BBC5C 002BB05C AFB60028 */  sw         $s6, 0x28($sp)
    /* BBC60 002BB060 AFB40020 */  sw         $s4, 0x20($sp)
    /* BBC64 002BB064 AFB3001C */  sw         $s3, 0x1C($sp)
    /* BBC68 002BB068 AFB20018 */  sw         $s2, 0x18($sp)
    /* BBC6C 002BB06C AFB10014 */  sw         $s1, 0x14($sp)
    /* BBC70 002BB070 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBC74 002BB074 8FC3001C */  lw         $v1, 0x1C($fp)
    /* BBC78 002BB078 8FC20014 */  lw         $v0, 0x14($fp)
    /* BBC7C 002BB07C 00031840 */  sll        $v1, $v1, 1
    /* BBC80 002BB080 00432821 */  addu       $a1, $v0, $v1
    /* BBC84 002BB084 0082102B */  sltu       $v0, $a0, $v0
    /* BBC88 002BB088 10400002 */  beqz       $v0, .L002BB094
    /* BBC8C 002BB08C 02A03021 */   addu      $a2, $s5, $zero
    /* BBC90 002BB090 00832021 */  addu       $a0, $a0, $v1
  .L002BB094:
    /* BBC94 002BB094 0007B040 */  sll        $s6, $a3, 1
    /* BBC98 002BB098 00968021 */  addu       $s0, $a0, $s6
    /* BBC9C 002BB09C 00B0102B */  sltu       $v0, $a1, $s0
    /* BBCA0 002BB0A0 10400027 */  beqz       $v0, .L002BB140
    /* BBCA4 002BB0A4 3C120800 */   lui       $s2, (0x8000000 >> 16)
    /* BBCA8 002BB0A8 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBCAC 002BB0AC 02A0A021 */  addu       $s4, $s5, $zero
    /* BBCB0 002BB0B0 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBCB4 002BB0B4 00A48823 */  subu       $s1, $a1, $a0
    /* BBCB8 002BB0B8 00118843 */  sra        $s1, $s1, 1
    /* BBCBC 002BB0BC 00171400 */  sll        $v0, $s7, 16
    /* BBCC0 002BB0C0 00118840 */  sll        $s1, $s1, 1
    /* BBCC4 002BB0C4 3223FFFF */  andi       $v1, $s1, 0xFFFF
    /* BBCC8 002BB0C8 00431025 */  or         $v0, $v0, $v1
    /* BBCCC 002BB0CC 3C130600 */  lui        $s3, (0x6000000 >> 16)
    /* BBCD0 002BB0D0 02058023 */  subu       $s0, $s0, $a1
    /* BBCD4 002BB0D4 00108043 */  sra        $s0, $s0, 1
    /* BBCD8 002BB0D8 ACD20000 */  sw         $s2, 0x0($a2)
    /* BBCDC 002BB0DC ACC20004 */  sw         $v0, 0x4($a2)
    /* BBCE0 002BB0E0 0C0B032C */  jal        osVirtualToPhysical
    /* BBCE4 002BB0E4 AE930000 */   sw        $s3, 0x0($s4)
    /* BBCE8 002BB0E8 02A01821 */  addu       $v1, $s5, $zero
    /* BBCEC 002BB0EC 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBCF0 002BB0F0 02F18821 */  addu       $s1, $s7, $s1
    /* BBCF4 002BB0F4 00118C00 */  sll        $s1, $s1, 16
    /* BBCF8 002BB0F8 00108040 */  sll        $s0, $s0, 1
    /* BBCFC 002BB0FC 3210FFFF */  andi       $s0, $s0, 0xFFFF
    /* BBD00 002BB100 02308825 */  or         $s1, $s1, $s0
    /* BBD04 002BB104 02A08021 */  addu       $s0, $s5, $zero
    /* BBD08 002BB108 AE820004 */  sw         $v0, 0x4($s4)
    /* BBD0C 002BB10C AC720000 */  sw         $s2, 0x0($v1)
    /* BBD10 002BB110 AC710004 */  sw         $s1, 0x4($v1)
    /* BBD14 002BB114 AE130000 */  sw         $s3, 0x0($s0)
    /* BBD18 002BB118 8FC40014 */  lw         $a0, 0x14($fp)
    /* BBD1C 002BB11C 0C0B032C */  jal        osVirtualToPhysical
    /* BBD20 002BB120 26B50008 */   addiu     $s5, $s5, 0x8
    /* BBD24 002BB124 02A01821 */  addu       $v1, $s5, $zero
    /* BBD28 002BB128 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBD2C 002BB12C AE020004 */  sw         $v0, 0x4($s0)
    /* BBD30 002BB130 32C2FFFF */  andi       $v0, $s6, 0xFFFF
    /* BBD34 002BB134 AC720000 */  sw         $s2, 0x0($v1)
    /* BBD38 002BB138 080AEC5D */  j          .L002BB174
    /* BBD3C 002BB13C AC620004 */   sw        $v0, 0x4($v1)
  .L002BB140:
    /* BBD40 002BB140 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBD44 002BB144 02A08021 */  addu       $s0, $s5, $zero
    /* BBD48 002BB148 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBD4C 002BB14C 3C020800 */  lui        $v0, (0x8000000 >> 16)
    /* BBD50 002BB150 ACC20000 */  sw         $v0, 0x0($a2)
    /* BBD54 002BB154 00171400 */  sll        $v0, $s7, 16
    /* BBD58 002BB158 32C3FFFF */  andi       $v1, $s6, 0xFFFF
    /* BBD5C 002BB15C 00431025 */  or         $v0, $v0, $v1
    /* BBD60 002BB160 ACC20004 */  sw         $v0, 0x4($a2)
    /* BBD64 002BB164 3C020600 */  lui        $v0, (0x6000000 >> 16)
    /* BBD68 002BB168 0C0B032C */  jal        osVirtualToPhysical
    /* BBD6C 002BB16C AE020000 */   sw        $v0, 0x0($s0)
    /* BBD70 002BB170 AE020004 */  sw         $v0, 0x4($s0)
  .L002BB174:
    /* BBD74 002BB174 02A01021 */  addu       $v0, $s5, $zero
    /* BBD78 002BB178 8FBF0034 */  lw         $ra, 0x34($sp)
    /* BBD7C 002BB17C 8FBE0030 */  lw         $fp, 0x30($sp)
    /* BBD80 002BB180 8FB7002C */  lw         $s7, 0x2C($sp)
    /* BBD84 002BB184 8FB60028 */  lw         $s6, 0x28($sp)
    /* BBD88 002BB188 8FB50024 */  lw         $s5, 0x24($sp)
    /* BBD8C 002BB18C 8FB40020 */  lw         $s4, 0x20($sp)
    /* BBD90 002BB190 8FB3001C */  lw         $s3, 0x1C($sp)
    /* BBD94 002BB194 8FB20018 */  lw         $s2, 0x18($sp)
    /* BBD98 002BB198 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBD9C 002BB19C 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBDA0 002BB1A0 03E00008 */  jr         $ra
    /* BBDA4 002BB1A4 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_002BB038
