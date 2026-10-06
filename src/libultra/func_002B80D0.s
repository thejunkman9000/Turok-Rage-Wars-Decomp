.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8CD0-0xB8E00 (VRAM 0x002B80D0) */
glabel func_002B80D0
    /* B8CD0 002B80D0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8CD4 002B80D4 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B8CD8 002B80D8 AFB20020 */  sw         $s2, 0x20($sp)
    /* B8CDC 002B80DC AFB1001C */  sw         $s1, 0x1C($sp)
    /* B8CE0 002B80E0 AFB00018 */  sw         $s0, 0x18($sp)
    /* B8CE4 002B80E4 94C20000 */  lhu        $v0, 0x0($a2)
    /* B8CE8 002B80E8 00A08821 */  addu       $s1, $a1, $zero
    /* B8CEC 002B80EC AFA00010 */  sw         $zero, 0x10($sp)
    /* B8CF0 002B80F0 A6220016 */  sh         $v0, 0x16($s1)
    /* B8CF4 002B80F4 90C20004 */  lbu        $v0, 0x4($a2)
    /* B8CF8 002B80F8 00809021 */  addu       $s2, $a0, $zero
    /* B8CFC 002B80FC AE20000C */  sw         $zero, 0xC($s1)
    /* B8D00 002B8100 A622001A */  sh         $v0, 0x1A($s1)
    /* B8D04 002B8104 94C20002 */  lhu        $v0, 0x2($a2)
    /* B8D08 002B8108 A6200014 */  sh         $zero, 0x14($s1)
    /* B8D0C 002B810C AE200008 */  sw         $zero, 0x8($s1)
    /* B8D10 002B8110 A6220018 */  sh         $v0, 0x18($s1)
    /* B8D14 002B8114 84C60000 */  lh         $a2, 0x0($a2)
    /* B8D18 002B8118 0C0AE080 */  jal        func_002B8200
    /* B8D1C 002B811C 27A50010 */   addiu     $a1, $sp, 0x10
    /* B8D20 002B8120 8FA40010 */  lw         $a0, 0x10($sp)
    /* B8D24 002B8124 1080002E */  beqz       $a0, .L002B81E0
    /* B8D28 002B8128 00000000 */   nop
    /* B8D2C 002B812C 8C90000C */  lw         $s0, 0xC($a0)
    /* B8D30 002B8130 10400027 */  beqz       $v0, .L002B81D0
    /* B8D34 002B8134 24020200 */   addiu     $v0, $zero, 0x200
    /* B8D38 002B8138 8C830008 */  lw         $v1, 0x8($a0)
    /* B8D3C 002B813C AC8200D8 */  sw         $v0, 0xD8($a0)
    /* B8D40 002B8140 0C0AE332 */  jal        func_002B8CC8
    /* B8D44 002B8144 AC600008 */   sw        $zero, 0x8($v1)
    /* B8D48 002B8148 00403821 */  addu       $a3, $v0, $zero
    /* B8D4C 002B814C 02002021 */  addu       $a0, $s0, $zero
    /* B8D50 002B8150 8E43001C */  lw         $v1, 0x1C($s2)
    /* B8D54 002B8154 8FA50010 */  lw         $a1, 0x10($sp)
    /* B8D58 002B8158 2402000B */  addiu      $v0, $zero, 0xB
    /* B8D5C 002B815C A4E20008 */  sh         $v0, 0x8($a3)
    /* B8D60 002B8160 ACE0000C */  sw         $zero, 0xC($a3)
    /* B8D64 002B8164 ACE30004 */  sw         $v1, 0x4($a3)
    /* B8D68 002B8168 8CA200D8 */  lw         $v0, 0xD8($a1)
    /* B8D6C 002B816C 00E03021 */  addu       $a2, $a3, $zero
    /* B8D70 002B8170 2442FFC0 */  addiu      $v0, $v0, -0x40
    /* B8D74 002B8174 ACE20010 */  sw         $v0, 0x10($a3)
    /* B8D78 002B8178 8E020008 */  lw         $v0, 0x8($s0)
    /* B8D7C 002B817C 0040F809 */  jalr       $v0
    /* B8D80 002B8180 24050003 */   addiu     $a1, $zero, 0x3
    /* B8D84 002B8184 0C0AE332 */  jal        func_002B8CC8
    /* B8D88 002B8188 00000000 */   nop
    /* B8D8C 002B818C 00403821 */  addu       $a3, $v0, $zero
    /* B8D90 002B8190 10E00010 */  beqz       $a3, .L002B81D4
    /* B8D94 002B8194 02002021 */   addu      $a0, $s0, $zero
    /* B8D98 002B8198 24050003 */  addiu      $a1, $zero, 0x3
    /* B8D9C 002B819C 8FA20010 */  lw         $v0, 0x10($sp)
    /* B8DA0 002B81A0 8E43001C */  lw         $v1, 0x1C($s2)
    /* B8DA4 002B81A4 8C4600D8 */  lw         $a2, 0xD8($v0)
    /* B8DA8 002B81A8 2402000F */  addiu      $v0, $zero, 0xF
    /* B8DAC 002B81AC A4E20008 */  sh         $v0, 0x8($a3)
    /* B8DB0 002B81B0 ACE00000 */  sw         $zero, 0x0($a3)
    /* B8DB4 002B81B4 00661821 */  addu       $v1, $v1, $a2
    /* B8DB8 002B81B8 ACE30004 */  sw         $v1, 0x4($a3)
    /* B8DBC 002B81BC 8C820008 */  lw         $v0, 0x8($a0)
    /* B8DC0 002B81C0 0040F809 */  jalr       $v0
    /* B8DC4 002B81C4 00E03021 */   addu      $a2, $a3, $zero
    /* B8DC8 002B81C8 080AE075 */  j          .L002B81D4
    /* B8DCC 002B81CC 00000000 */   nop
  .L002B81D0:
    /* B8DD0 002B81D0 AC8000D8 */  sw         $zero, 0xD8($a0)
  .L002B81D4:
    /* B8DD4 002B81D4 8FA20010 */  lw         $v0, 0x10($sp)
    /* B8DD8 002B81D8 AC510008 */  sw         $s1, 0x8($v0)
    /* B8DDC 002B81DC AE220008 */  sw         $v0, 0x8($s1)
  .L002B81E0:
    /* B8DE0 002B81E0 8FA20010 */  lw         $v0, 0x10($sp)
    /* B8DE4 002B81E4 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B8DE8 002B81E8 8FB20020 */  lw         $s2, 0x20($sp)
    /* B8DEC 002B81EC 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B8DF0 002B81F0 8FB00018 */  lw         $s0, 0x18($sp)
    /* B8DF4 002B81F4 0002102B */  sltu       $v0, $zero, $v0
    /* B8DF8 002B81F8 03E00008 */  jr         $ra
    /* B8DFC 002B81FC 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B80D0
