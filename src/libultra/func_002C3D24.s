.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC4924-0xC4AA0 (VRAM 0x002C3D24) */
glabel func_002C3D24
    /* C4924 002C3D24 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* C4928 002C3D28 AFB20018 */  sw         $s2, 0x18($sp)
    /* C492C 002C3D2C 8FB2004C */  lw         $s2, 0x4C($sp)
    /* C4930 002C3D30 AFB60028 */  sw         $s6, 0x28($sp)
    /* C4934 002C3D34 8FB60050 */  lw         $s6, 0x50($sp)
    /* C4938 002C3D38 AFB50024 */  sw         $s5, 0x24($sp)
    /* C493C 002C3D3C 97B5004A */  lhu        $s5, 0x4A($sp)
    /* C4940 002C3D40 AFB00010 */  sw         $s0, 0x10($sp)
    /* C4944 002C3D44 00808021 */  addu       $s0, $a0, $zero
    /* C4948 002C3D48 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C494C 002C3D4C 00A09821 */  addu       $s3, $a1, $zero
    /* C4950 002C3D50 AFB7002C */  sw         $s7, 0x2C($sp)
    /* C4954 002C3D54 00C0B821 */  addu       $s7, $a2, $zero
    /* C4958 002C3D58 AFB10014 */  sw         $s1, 0x14($sp)
    /* C495C 002C3D5C 00E08821 */  addu       $s1, $a3, $zero
    /* C4960 002C3D60 AFBF0030 */  sw         $ra, 0x30($sp)
    /* C4964 002C3D64 AFB40020 */  sw         $s4, 0x20($sp)
    /* C4968 002C3D68 1A20001A */  blez       $s1, .L002C3DD4
    /* C496C 002C3D6C 0240A021 */   addu      $s4, $s2, $zero
    /* C4970 002C3D70 8E620030 */  lw         $v0, 0x30($s3)
    /* C4974 002C3D74 8E640044 */  lw         $a0, 0x44($s3)
    /* C4978 002C3D78 8E660034 */  lw         $a2, 0x34($s3)
    /* C497C 002C3D7C 0040F809 */  jalr       $v0
    /* C4980 002C3D80 02202821 */   addu      $a1, $s1, $zero
    /* C4984 002C3D84 30470007 */  andi       $a3, $v0, 0x7
    /* C4988 002C3D88 02278821 */  addu       $s1, $s1, $a3
    /* C498C 002C3D8C 02002821 */  addu       $a1, $s0, $zero
    /* C4990 002C3D90 26100008 */  addiu      $s0, $s0, 0x8
    /* C4994 002C3D94 02003021 */  addu       $a2, $s0, $zero
    /* C4998 002C3D98 26100008 */  addiu      $s0, $s0, 0x8
    /* C499C 002C3D9C 3243FFFF */  andi       $v1, $s2, 0xFFFF
    /* C49A0 002C3DA0 3C040800 */  lui        $a0, (0x8000000 >> 16)
    /* C49A4 002C3DA4 00641825 */  or         $v1, $v1, $a0
    /* C49A8 002C3DA8 ACA30000 */  sw         $v1, 0x0($a1)
    /* C49AC 002C3DAC 32230007 */  andi       $v1, $s1, 0x7
    /* C49B0 002C3DB0 2463FFF8 */  addiu      $v1, $v1, -0x8
    /* C49B4 002C3DB4 02231823 */  subu       $v1, $s1, $v1
    /* C49B8 002C3DB8 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* C49BC 002C3DBC ACA30004 */  sw         $v1, 0x4($a1)
    /* C49C0 002C3DC0 3C030400 */  lui        $v1, (0x4000000 >> 16)
    /* C49C4 002C3DC4 00471023 */  subu       $v0, $v0, $a3
    /* C49C8 002C3DC8 ACC30000 */  sw         $v1, 0x0($a2)
    /* C49CC 002C3DCC 080B0F76 */  j          .L002C3DD8
    /* C49D0 002C3DD0 ACC20004 */   sw        $v0, 0x4($a2)
  .L002C3DD4:
    /* C49D4 002C3DD4 00003821 */  addu       $a3, $zero, $zero
  .L002C3DD8:
    /* C49D8 002C3DD8 32C20002 */  andi       $v0, $s6, 0x2
    /* C49DC 002C3DDC 10400009 */  beqz       $v0, .L002C3E04
    /* C49E0 002C3DE0 02002021 */   addu      $a0, $s0, $zero
    /* C49E4 002C3DE4 26100008 */  addiu      $s0, $s0, 0x8
    /* C49E8 002C3DE8 3C031FFF */  lui        $v1, (0x1FFFFFFF >> 16)
    /* C49EC 002C3DEC 3C020F00 */  lui        $v0, (0xF000000 >> 16)
    /* C49F0 002C3DF0 AC820000 */  sw         $v0, 0x0($a0)
    /* C49F4 002C3DF4 8E620018 */  lw         $v0, 0x18($s3)
    /* C49F8 002C3DF8 3463FFFF */  ori        $v1, $v1, (0x1FFFFFFF & 0xFFFF)
    /* C49FC 002C3DFC 00431024 */  and        $v0, $v0, $v1
    /* C4A00 002C3E00 AC820004 */  sw         $v0, 0x4($a0)
  .L002C3E04:
    /* C4A04 002C3E04 02002021 */  addu       $a0, $s0, $zero
    /* C4A08 002C3E08 26100008 */  addiu      $s0, $s0, 0x8
    /* C4A0C 002C3E0C 3C051FFF */  lui        $a1, (0x1FFFFFFF >> 16)
    /* C4A10 002C3E10 00141400 */  sll        $v0, $s4, 16
    /* C4A14 002C3E14 00021403 */  sra        $v0, $v0, 16
    /* C4A18 002C3E18 00471021 */  addu       $v0, $v0, $a3
    /* C4A1C 002C3E1C 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C4A20 002C3E20 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* C4A24 002C3E24 00431025 */  or         $v0, $v0, $v1
    /* C4A28 002C3E28 00151C00 */  sll        $v1, $s5, 16
    /* C4A2C 002C3E2C AC820000 */  sw         $v0, 0x0($a0)
    /* C4A30 002C3E30 00171040 */  sll        $v0, $s7, 1
    /* C4A34 002C3E34 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C4A38 002C3E38 00621825 */  or         $v1, $v1, $v0
    /* C4A3C 002C3E3C AC830004 */  sw         $v1, 0x4($a0)
    /* C4A40 002C3E40 02002021 */  addu       $a0, $s0, $zero
    /* C4A44 002C3E44 32C200FF */  andi       $v0, $s6, 0xFF
    /* C4A48 002C3E48 00021400 */  sll        $v0, $v0, 16
    /* C4A4C 002C3E4C 3C030100 */  lui        $v1, (0x1000000 >> 16)
    /* C4A50 002C3E50 00431025 */  or         $v0, $v0, $v1
    /* C4A54 002C3E54 AC820000 */  sw         $v0, 0x0($a0)
    /* C4A58 002C3E58 8E630014 */  lw         $v1, 0x14($s3)
    /* C4A5C 002C3E5C 34A5FFFF */  ori        $a1, $a1, (0x1FFFFFFF & 0xFFFF)
    /* C4A60 002C3E60 00651824 */  and        $v1, $v1, $a1
    /* C4A64 002C3E64 AC830004 */  sw         $v1, 0x4($a0)
    /* C4A68 002C3E68 AE600040 */  sw         $zero, 0x40($s3)
    /* C4A6C 002C3E6C 8FBF0030 */  lw         $ra, 0x30($sp)
    /* C4A70 002C3E70 8FB7002C */  lw         $s7, 0x2C($sp)
    /* C4A74 002C3E74 8FB60028 */  lw         $s6, 0x28($sp)
    /* C4A78 002C3E78 8FB50024 */  lw         $s5, 0x24($sp)
    /* C4A7C 002C3E7C 8FB40020 */  lw         $s4, 0x20($sp)
    /* C4A80 002C3E80 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C4A84 002C3E84 8FB20018 */  lw         $s2, 0x18($sp)
    /* C4A88 002C3E88 8FB10014 */  lw         $s1, 0x14($sp)
    /* C4A8C 002C3E8C 8FB00010 */  lw         $s0, 0x10($sp)
    /* C4A90 002C3E90 24820008 */  addiu      $v0, $a0, 0x8
    /* C4A94 002C3E94 03E00008 */  jr         $ra
    /* C4A98 002C3E98 27BD0038 */   addiu     $sp, $sp, 0x38


    /* C4A9C 002C3E9C 45000008 */  .word      0x45000008 /* linker padding */
endlabel func_002C3D24
