.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC6A90-0xC7010 (VRAM 0x002C5E90) */
glabel func_002C5E90
    /* C6A90 002C5E90 00E04821 */  addu       $t1, $a3, $zero
    /* C6A94 002C5E94 00C04021 */  addu       $t0, $a2, $zero
    /* C6A98 002C5E98 150000E8 */  bnez       $t0, .L002C623C
    /* C6A9C 002C5E9C 00A05821 */   addu      $t3, $a1, $zero
    /* C6AA0 002C5EA0 0089102B */  sltu       $v0, $a0, $t1
    /* C6AA4 002C5EA4 10400051 */  beqz       $v0, .L002C5FEC
    /* C6AA8 002C5EA8 3402FFFF */   ori       $v0, $zero, 0xFFFF
    /* C6AAC 002C5EAC 0049102B */  sltu       $v0, $v0, $t1
    /* C6AB0 002C5EB0 14400005 */  bnez       $v0, .L002C5EC8
    /* C6AB4 002C5EB4 00E01821 */   addu      $v1, $a3, $zero
    /* C6AB8 002C5EB8 2D220100 */  sltiu      $v0, $t1, 0x100
    /* C6ABC 002C5EBC 38420001 */  xori       $v0, $v0, 0x1
    /* C6AC0 002C5EC0 080B17B8 */  j          .L002C5EE0
    /* C6AC4 002C5EC4 000240C0 */   sll       $t0, $v0, 3
  .L002C5EC8:
    /* C6AC8 002C5EC8 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C6ACC 002C5ECC 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C6AD0 002C5ED0 0049102B */  sltu       $v0, $v0, $t1
    /* C6AD4 002C5ED4 14400002 */  bnez       $v0, .L002C5EE0
    /* C6AD8 002C5ED8 24080018 */   addiu     $t0, $zero, 0x18
    /* C6ADC 002C5EDC 24080010 */  addiu      $t0, $zero, 0x10
  .L002C5EE0:
    /* C6AE0 002C5EE0 3C02800D */  lui        $v0, %hi(D_800CD150)
    /* C6AE4 002C5EE4 2442D150 */  addiu      $v0, $v0, %lo(D_800CD150)
    /* C6AE8 002C5EE8 01031806 */  srlv       $v1, $v1, $t0
    /* C6AEC 002C5EEC 00621821 */  addu       $v1, $v1, $v0
    /* C6AF0 002C5EF0 90620000 */  lbu        $v0, 0x0($v1)
    /* C6AF4 002C5EF4 24050020 */  addiu      $a1, $zero, 0x20
    /* C6AF8 002C5EF8 00481021 */  addu       $v0, $v0, $t0
    /* C6AFC 002C5EFC 00A23023 */  subu       $a2, $a1, $v0
    /* C6B00 002C5F00 10C00006 */  beqz       $a2, .L002C5F1C
    /* C6B04 002C5F04 00C41804 */   sllv      $v1, $a0, $a2
    /* C6B08 002C5F08 00C94804 */  sllv       $t1, $t1, $a2
    /* C6B0C 002C5F0C 00A61023 */  subu       $v0, $a1, $a2
    /* C6B10 002C5F10 004B1006 */  srlv       $v0, $t3, $v0
    /* C6B14 002C5F14 00622025 */  or         $a0, $v1, $v0
    /* C6B18 002C5F18 00CB5804 */  sllv       $t3, $t3, $a2
  .L002C5F1C:
    /* C6B1C 002C5F1C 00093402 */  srl        $a2, $t1, 16
    /* C6B20 002C5F20 0086001B */  divu       $zero, $a0, $a2
    /* C6B24 002C5F24 14C00002 */  bnez       $a2, .L002C5F30
    /* C6B28 002C5F28 00000000 */   nop
    /* C6B2C 002C5F2C 0007000D */  break      7
  .L002C5F30:
    /* C6B30 002C5F30 00003812 */  mflo       $a3
    /* C6B34 002C5F34 00001810 */  mfhi       $v1
    /* C6B38 002C5F38 3128FFFF */  andi       $t0, $t1, 0xFFFF
    /* C6B3C 002C5F3C 00000000 */  nop
    /* C6B40 002C5F40 00E80018 */  mult       $a3, $t0
    /* C6B44 002C5F44 000B1402 */  srl        $v0, $t3, 16
    /* C6B48 002C5F48 00031C00 */  sll        $v1, $v1, 16
    /* C6B4C 002C5F4C 00621825 */  or         $v1, $v1, $v0
    /* C6B50 002C5F50 00002812 */  mflo       $a1
    /* C6B54 002C5F54 0065102B */  sltu       $v0, $v1, $a1
    /* C6B58 002C5F58 5040000B */  beql       $v0, $zero, .L002C5F88
    /* C6B5C 002C5F5C 00651823 */   subu      $v1, $v1, $a1
    /* C6B60 002C5F60 00691821 */  addu       $v1, $v1, $t1
    /* C6B64 002C5F64 0069102B */  sltu       $v0, $v1, $t1
    /* C6B68 002C5F68 14400006 */  bnez       $v0, .L002C5F84
    /* C6B6C 002C5F6C 24E7FFFF */   addiu     $a3, $a3, -0x1
    /* C6B70 002C5F70 0065102B */  sltu       $v0, $v1, $a1
    /* C6B74 002C5F74 50400004 */  beql       $v0, $zero, .L002C5F88
    /* C6B78 002C5F78 00651823 */   subu      $v1, $v1, $a1
    /* C6B7C 002C5F7C 24E7FFFF */  addiu      $a3, $a3, -0x1
    /* C6B80 002C5F80 00691821 */  addu       $v1, $v1, $t1
  .L002C5F84:
    /* C6B84 002C5F84 00651823 */  subu       $v1, $v1, $a1
  .L002C5F88:
    /* C6B88 002C5F88 0066001B */  divu       $zero, $v1, $a2
    /* C6B8C 002C5F8C 14C00002 */  bnez       $a2, .L002C5F98
    /* C6B90 002C5F90 00000000 */   nop
    /* C6B94 002C5F94 0007000D */  break      7
  .L002C5F98:
    /* C6B98 002C5F98 00002012 */  mflo       $a0
    /* C6B9C 002C5F9C 00001810 */  mfhi       $v1
    /* C6BA0 002C5FA0 00000000 */  nop
    /* C6BA4 002C5FA4 00000000 */  nop
    /* C6BA8 002C5FA8 00880018 */  mult       $a0, $t0
    /* C6BAC 002C5FAC 3162FFFF */  andi       $v0, $t3, 0xFFFF
    /* C6BB0 002C5FB0 00031C00 */  sll        $v1, $v1, 16
    /* C6BB4 002C5FB4 00621825 */  or         $v1, $v1, $v0
    /* C6BB8 002C5FB8 00002812 */  mflo       $a1
    /* C6BBC 002C5FBC 0065102B */  sltu       $v0, $v1, $a1
    /* C6BC0 002C5FC0 10400007 */  beqz       $v0, .L002C5FE0
    /* C6BC4 002C5FC4 00691821 */   addu      $v1, $v1, $t1
    /* C6BC8 002C5FC8 0069102B */  sltu       $v0, $v1, $t1
    /* C6BCC 002C5FCC 14400004 */  bnez       $v0, .L002C5FE0
    /* C6BD0 002C5FD0 2484FFFF */   addiu     $a0, $a0, -0x1
    /* C6BD4 002C5FD4 0065102B */  sltu       $v0, $v1, $a1
    /* C6BD8 002C5FD8 54400001 */  bnel       $v0, $zero, .L002C5FE0
    /* C6BDC 002C5FDC 2484FFFF */   addiu     $a0, $a0, -0x1
  .L002C5FE0:
    /* C6BE0 002C5FE0 00071400 */  sll        $v0, $a3, 16
    /* C6BE4 002C5FE4 080B18FF */  j          .L002C63FC
    /* C6BE8 002C5FE8 00443025 */   or        $a2, $v0, $a0
  .L002C5FEC:
    /* C6BEC 002C5FEC 15200009 */  bnez       $t1, .L002C6014
    /* C6BF0 002C5FF0 0049102B */   sltu      $v0, $v0, $t1
    /* C6BF4 002C5FF4 24020001 */  addiu      $v0, $zero, 0x1
    /* C6BF8 002C5FF8 0048001B */  divu       $zero, $v0, $t0
    /* C6BFC 002C5FFC 15000002 */  bnez       $t0, .L002C6008
    /* C6C00 002C6000 00000000 */   nop
    /* C6C04 002C6004 0007000D */  break      7
  .L002C6008:
    /* C6C08 002C6008 00004812 */  mflo       $t1
    /* C6C0C 002C600C 3402FFFF */  ori        $v0, $zero, 0xFFFF
    /* C6C10 002C6010 0049102B */  sltu       $v0, $v0, $t1
  .L002C6014:
    /* C6C14 002C6014 14400005 */  bnez       $v0, .L002C602C
    /* C6C18 002C6018 01201821 */   addu      $v1, $t1, $zero
    /* C6C1C 002C601C 2D220100 */  sltiu      $v0, $t1, 0x100
    /* C6C20 002C6020 38420001 */  xori       $v0, $v0, 0x1
    /* C6C24 002C6024 080B1811 */  j          .L002C6044
    /* C6C28 002C6028 000230C0 */   sll       $a2, $v0, 3
  .L002C602C:
    /* C6C2C 002C602C 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C6C30 002C6030 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C6C34 002C6034 0049102B */  sltu       $v0, $v0, $t1
    /* C6C38 002C6038 14400002 */  bnez       $v0, .L002C6044
    /* C6C3C 002C603C 24060018 */   addiu     $a2, $zero, 0x18
    /* C6C40 002C6040 24060010 */  addiu      $a2, $zero, 0x10
  .L002C6044:
    /* C6C44 002C6044 3C02800D */  lui        $v0, %hi(D_800CD150)
    /* C6C48 002C6048 2442D150 */  addiu      $v0, $v0, %lo(D_800CD150)
    /* C6C4C 002C604C 00C31806 */  srlv       $v1, $v1, $a2
    /* C6C50 002C6050 00621821 */  addu       $v1, $v1, $v0
    /* C6C54 002C6054 90620000 */  lbu        $v0, 0x0($v1)
    /* C6C58 002C6058 24030020 */  addiu      $v1, $zero, 0x20
    /* C6C5C 002C605C 00461021 */  addu       $v0, $v0, $a2
    /* C6C60 002C6060 00623023 */  subu       $a2, $v1, $v0
    /* C6C64 002C6064 14C00004 */  bnez       $a2, .L002C6078
    /* C6C68 002C6068 00662823 */   subu      $a1, $v1, $a2
    /* C6C6C 002C606C 00892023 */  subu       $a0, $a0, $t1
    /* C6C70 002C6070 080B185B */  j          .L002C616C
    /* C6C74 002C6074 240A0001 */   addiu     $t2, $zero, 0x1
  .L002C6078:
    /* C6C78 002C6078 00C94804 */  sllv       $t1, $t1, $a2
    /* C6C7C 002C607C 00A43806 */  srlv       $a3, $a0, $a1
    /* C6C80 002C6080 00C41804 */  sllv       $v1, $a0, $a2
    /* C6C84 002C6084 00AB1006 */  srlv       $v0, $t3, $a1
    /* C6C88 002C6088 00622025 */  or         $a0, $v1, $v0
    /* C6C8C 002C608C 00CB5804 */  sllv       $t3, $t3, $a2
    /* C6C90 002C6090 00093402 */  srl        $a2, $t1, 16
    /* C6C94 002C6094 00E6001B */  divu       $zero, $a3, $a2
    /* C6C98 002C6098 14C00002 */  bnez       $a2, .L002C60A4
    /* C6C9C 002C609C 00000000 */   nop
    /* C6CA0 002C60A0 0007000D */  break      7
  .L002C60A4:
    /* C6CA4 002C60A4 00004012 */  mflo       $t0
    /* C6CA8 002C60A8 00001810 */  mfhi       $v1
    /* C6CAC 002C60AC 3125FFFF */  andi       $a1, $t1, 0xFFFF
    /* C6CB0 002C60B0 00000000 */  nop
    /* C6CB4 002C60B4 01050018 */  mult       $t0, $a1
    /* C6CB8 002C60B8 00041402 */  srl        $v0, $a0, 16
    /* C6CBC 002C60BC 00031C00 */  sll        $v1, $v1, 16
    /* C6CC0 002C60C0 00621825 */  or         $v1, $v1, $v0
    /* C6CC4 002C60C4 00003812 */  mflo       $a3
    /* C6CC8 002C60C8 0067102B */  sltu       $v0, $v1, $a3
    /* C6CCC 002C60CC 5040000B */  beql       $v0, $zero, .L002C60FC
    /* C6CD0 002C60D0 00671823 */   subu      $v1, $v1, $a3
    /* C6CD4 002C60D4 00691821 */  addu       $v1, $v1, $t1
    /* C6CD8 002C60D8 0069102B */  sltu       $v0, $v1, $t1
    /* C6CDC 002C60DC 14400006 */  bnez       $v0, .L002C60F8
    /* C6CE0 002C60E0 2508FFFF */   addiu     $t0, $t0, -0x1
    /* C6CE4 002C60E4 0067102B */  sltu       $v0, $v1, $a3
    /* C6CE8 002C60E8 50400004 */  beql       $v0, $zero, .L002C60FC
    /* C6CEC 002C60EC 00671823 */   subu      $v1, $v1, $a3
    /* C6CF0 002C60F0 2508FFFF */  addiu      $t0, $t0, -0x1
    /* C6CF4 002C60F4 00691821 */  addu       $v1, $v1, $t1
  .L002C60F8:
    /* C6CF8 002C60F8 00671823 */  subu       $v1, $v1, $a3
  .L002C60FC:
    /* C6CFC 002C60FC 0066001B */  divu       $zero, $v1, $a2
    /* C6D00 002C6100 14C00002 */  bnez       $a2, .L002C610C
    /* C6D04 002C6104 00000000 */   nop
    /* C6D08 002C6108 0007000D */  break      7
  .L002C610C:
    /* C6D0C 002C610C 00003012 */  mflo       $a2
    /* C6D10 002C6110 00001810 */  mfhi       $v1
    /* C6D14 002C6114 00000000 */  nop
    /* C6D18 002C6118 00000000 */  nop
    /* C6D1C 002C611C 00C50018 */  mult       $a2, $a1
    /* C6D20 002C6120 3082FFFF */  andi       $v0, $a0, 0xFFFF
    /* C6D24 002C6124 00031C00 */  sll        $v1, $v1, 16
    /* C6D28 002C6128 00621825 */  or         $v1, $v1, $v0
    /* C6D2C 002C612C 00003812 */  mflo       $a3
    /* C6D30 002C6130 0067102B */  sltu       $v0, $v1, $a3
    /* C6D34 002C6134 1040000B */  beqz       $v0, .L002C6164
    /* C6D38 002C6138 00081400 */   sll       $v0, $t0, 16
    /* C6D3C 002C613C 00691821 */  addu       $v1, $v1, $t1
    /* C6D40 002C6140 0069102B */  sltu       $v0, $v1, $t1
    /* C6D44 002C6144 14400006 */  bnez       $v0, .L002C6160
    /* C6D48 002C6148 24C6FFFF */   addiu     $a2, $a2, -0x1
    /* C6D4C 002C614C 0067102B */  sltu       $v0, $v1, $a3
    /* C6D50 002C6150 10400004 */  beqz       $v0, .L002C6164
    /* C6D54 002C6154 00081400 */   sll       $v0, $t0, 16
    /* C6D58 002C6158 24C6FFFF */  addiu      $a2, $a2, -0x1
    /* C6D5C 002C615C 00691821 */  addu       $v1, $v1, $t1
  .L002C6160:
    /* C6D60 002C6160 00081400 */  sll        $v0, $t0, 16
  .L002C6164:
    /* C6D64 002C6164 00465025 */  or         $t2, $v0, $a2
    /* C6D68 002C6168 00672023 */  subu       $a0, $v1, $a3
  .L002C616C:
    /* C6D6C 002C616C 00093402 */  srl        $a2, $t1, 16
    /* C6D70 002C6170 0086001B */  divu       $zero, $a0, $a2
    /* C6D74 002C6174 14C00002 */  bnez       $a2, .L002C6180
    /* C6D78 002C6178 00000000 */   nop
    /* C6D7C 002C617C 0007000D */  break      7
  .L002C6180:
    /* C6D80 002C6180 00003812 */  mflo       $a3
    /* C6D84 002C6184 00001810 */  mfhi       $v1
    /* C6D88 002C6188 3128FFFF */  andi       $t0, $t1, 0xFFFF
    /* C6D8C 002C618C 00000000 */  nop
    /* C6D90 002C6190 00E80018 */  mult       $a3, $t0
    /* C6D94 002C6194 000B1402 */  srl        $v0, $t3, 16
    /* C6D98 002C6198 00031C00 */  sll        $v1, $v1, 16
    /* C6D9C 002C619C 00621825 */  or         $v1, $v1, $v0
    /* C6DA0 002C61A0 00002812 */  mflo       $a1
    /* C6DA4 002C61A4 0065102B */  sltu       $v0, $v1, $a1
    /* C6DA8 002C61A8 5040000B */  beql       $v0, $zero, .L002C61D8
    /* C6DAC 002C61AC 00651823 */   subu      $v1, $v1, $a1
    /* C6DB0 002C61B0 00691821 */  addu       $v1, $v1, $t1
    /* C6DB4 002C61B4 0069102B */  sltu       $v0, $v1, $t1
    /* C6DB8 002C61B8 14400006 */  bnez       $v0, .L002C61D4
    /* C6DBC 002C61BC 24E7FFFF */   addiu     $a3, $a3, -0x1
    /* C6DC0 002C61C0 0065102B */  sltu       $v0, $v1, $a1
    /* C6DC4 002C61C4 50400004 */  beql       $v0, $zero, .L002C61D8
    /* C6DC8 002C61C8 00651823 */   subu      $v1, $v1, $a1
    /* C6DCC 002C61CC 24E7FFFF */  addiu      $a3, $a3, -0x1
    /* C6DD0 002C61D0 00691821 */  addu       $v1, $v1, $t1
  .L002C61D4:
    /* C6DD4 002C61D4 00651823 */  subu       $v1, $v1, $a1
  .L002C61D8:
    /* C6DD8 002C61D8 0066001B */  divu       $zero, $v1, $a2
    /* C6DDC 002C61DC 14C00002 */  bnez       $a2, .L002C61E8
    /* C6DE0 002C61E0 00000000 */   nop
    /* C6DE4 002C61E4 0007000D */  break      7
  .L002C61E8:
    /* C6DE8 002C61E8 00002012 */  mflo       $a0
    /* C6DEC 002C61EC 00001810 */  mfhi       $v1
    /* C6DF0 002C61F0 00000000 */  nop
    /* C6DF4 002C61F4 00000000 */  nop
    /* C6DF8 002C61F8 00880018 */  mult       $a0, $t0
    /* C6DFC 002C61FC 3162FFFF */  andi       $v0, $t3, 0xFFFF
    /* C6E00 002C6200 00031C00 */  sll        $v1, $v1, 16
    /* C6E04 002C6204 00621825 */  or         $v1, $v1, $v0
    /* C6E08 002C6208 00002812 */  mflo       $a1
    /* C6E0C 002C620C 0065102B */  sltu       $v0, $v1, $a1
    /* C6E10 002C6210 10400007 */  beqz       $v0, .L002C6230
    /* C6E14 002C6214 00691821 */   addu      $v1, $v1, $t1
    /* C6E18 002C6218 0069102B */  sltu       $v0, $v1, $t1
    /* C6E1C 002C621C 14400004 */  bnez       $v0, .L002C6230
    /* C6E20 002C6220 2484FFFF */   addiu     $a0, $a0, -0x1
    /* C6E24 002C6224 0065102B */  sltu       $v0, $v1, $a1
    /* C6E28 002C6228 54400001 */  bnel       $v0, $zero, .L002C6230
    /* C6E2C 002C622C 2484FFFF */   addiu     $a0, $a0, -0x1
  .L002C6230:
    /* C6E30 002C6230 00071400 */  sll        $v0, $a3, 16
    /* C6E34 002C6234 080B1900 */  j          .L002C6400
    /* C6E38 002C6238 00443025 */   or        $a2, $v0, $a0
  .L002C623C:
    /* C6E3C 002C623C 0088102B */  sltu       $v0, $a0, $t0
    /* C6E40 002C6240 10400003 */  beqz       $v0, .L002C6250
    /* C6E44 002C6244 3402FFFF */   ori       $v0, $zero, 0xFFFF
    /* C6E48 002C6248 080B18FF */  j          .L002C63FC
    /* C6E4C 002C624C 00003021 */   addu      $a2, $zero, $zero
  .L002C6250:
    /* C6E50 002C6250 0048102B */  sltu       $v0, $v0, $t0
    /* C6E54 002C6254 14400005 */  bnez       $v0, .L002C626C
    /* C6E58 002C6258 01001821 */   addu      $v1, $t0, $zero
    /* C6E5C 002C625C 2D020100 */  sltiu      $v0, $t0, 0x100
    /* C6E60 002C6260 38420001 */  xori       $v0, $v0, 0x1
    /* C6E64 002C6264 080B18A1 */  j          .L002C6284
    /* C6E68 002C6268 000230C0 */   sll       $a2, $v0, 3
  .L002C626C:
    /* C6E6C 002C626C 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C6E70 002C6270 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C6E74 002C6274 0048102B */  sltu       $v0, $v0, $t0
    /* C6E78 002C6278 14400002 */  bnez       $v0, .L002C6284
    /* C6E7C 002C627C 24060018 */   addiu     $a2, $zero, 0x18
    /* C6E80 002C6280 24060010 */  addiu      $a2, $zero, 0x10
  .L002C6284:
    /* C6E84 002C6284 3C02800D */  lui        $v0, %hi(D_800CD150)
    /* C6E88 002C6288 2442D150 */  addiu      $v0, $v0, %lo(D_800CD150)
    /* C6E8C 002C628C 00C31806 */  srlv       $v1, $v1, $a2
    /* C6E90 002C6290 00621821 */  addu       $v1, $v1, $v0
    /* C6E94 002C6294 90620000 */  lbu        $v0, 0x0($v1)
    /* C6E98 002C6298 24030020 */  addiu      $v1, $zero, 0x20
    /* C6E9C 002C629C 00461021 */  addu       $v0, $v0, $a2
    /* C6EA0 002C62A0 00623023 */  subu       $a2, $v1, $v0
    /* C6EA4 002C62A4 14C00009 */  bnez       $a2, .L002C62CC
    /* C6EA8 002C62A8 00662823 */   subu      $a1, $v1, $a2
    /* C6EAC 002C62AC 0104102B */  sltu       $v0, $t0, $a0
    /* C6EB0 002C62B0 14400052 */  bnez       $v0, .L002C63FC
    /* C6EB4 002C62B4 24060001 */   addiu     $a2, $zero, 0x1
    /* C6EB8 002C62B8 0169102B */  sltu       $v0, $t3, $t1
    /* C6EBC 002C62BC 1440004F */  bnez       $v0, .L002C63FC
    /* C6EC0 002C62C0 00003021 */   addu      $a2, $zero, $zero
    /* C6EC4 002C62C4 080B18FF */  j          .L002C63FC
    /* C6EC8 002C62C8 24060001 */   addiu     $a2, $zero, 0x1
  .L002C62CC:
    /* C6ECC 002C62CC 00C81804 */  sllv       $v1, $t0, $a2
    /* C6ED0 002C62D0 00A91006 */  srlv       $v0, $t1, $a1
    /* C6ED4 002C62D4 00624025 */  or         $t0, $v1, $v0
    /* C6ED8 002C62D8 00C94804 */  sllv       $t1, $t1, $a2
    /* C6EDC 002C62DC 00A43806 */  srlv       $a3, $a0, $a1
    /* C6EE0 002C62E0 00C41804 */  sllv       $v1, $a0, $a2
    /* C6EE4 002C62E4 00AB1006 */  srlv       $v0, $t3, $a1
    /* C6EE8 002C62E8 00622025 */  or         $a0, $v1, $v0
    /* C6EEC 002C62EC 00CB5804 */  sllv       $t3, $t3, $a2
    /* C6EF0 002C62F0 00083402 */  srl        $a2, $t0, 16
    /* C6EF4 002C62F4 00E6001B */  divu       $zero, $a3, $a2
    /* C6EF8 002C62F8 14C00002 */  bnez       $a2, .L002C6304
    /* C6EFC 002C62FC 00000000 */   nop
    /* C6F00 002C6300 0007000D */  break      7
  .L002C6304:
    /* C6F04 002C6304 00005012 */  mflo       $t2
    /* C6F08 002C6308 00001810 */  mfhi       $v1
    /* C6F0C 002C630C 3105FFFF */  andi       $a1, $t0, 0xFFFF
    /* C6F10 002C6310 00000000 */  nop
    /* C6F14 002C6314 01450018 */  mult       $t2, $a1
    /* C6F18 002C6318 00041402 */  srl        $v0, $a0, 16
    /* C6F1C 002C631C 00031C00 */  sll        $v1, $v1, 16
    /* C6F20 002C6320 00621825 */  or         $v1, $v1, $v0
    /* C6F24 002C6324 00003812 */  mflo       $a3
    /* C6F28 002C6328 0067102B */  sltu       $v0, $v1, $a3
    /* C6F2C 002C632C 5040000B */  beql       $v0, $zero, .L002C635C
    /* C6F30 002C6330 00671823 */   subu      $v1, $v1, $a3
    /* C6F34 002C6334 00681821 */  addu       $v1, $v1, $t0
    /* C6F38 002C6338 0068102B */  sltu       $v0, $v1, $t0
    /* C6F3C 002C633C 14400006 */  bnez       $v0, .L002C6358
    /* C6F40 002C6340 254AFFFF */   addiu     $t2, $t2, -0x1
    /* C6F44 002C6344 0067102B */  sltu       $v0, $v1, $a3
    /* C6F48 002C6348 50400004 */  beql       $v0, $zero, .L002C635C
    /* C6F4C 002C634C 00671823 */   subu      $v1, $v1, $a3
    /* C6F50 002C6350 254AFFFF */  addiu      $t2, $t2, -0x1
    /* C6F54 002C6354 00681821 */  addu       $v1, $v1, $t0
  .L002C6358:
    /* C6F58 002C6358 00671823 */  subu       $v1, $v1, $a3
  .L002C635C:
    /* C6F5C 002C635C 0066001B */  divu       $zero, $v1, $a2
    /* C6F60 002C6360 14C00002 */  bnez       $a2, .L002C636C
    /* C6F64 002C6364 00000000 */   nop
    /* C6F68 002C6368 0007000D */  break      7
  .L002C636C:
    /* C6F6C 002C636C 00003012 */  mflo       $a2
    /* C6F70 002C6370 00001810 */  mfhi       $v1
    /* C6F74 002C6374 00000000 */  nop
    /* C6F78 002C6378 00000000 */  nop
    /* C6F7C 002C637C 00C50018 */  mult       $a2, $a1
    /* C6F80 002C6380 3082FFFF */  andi       $v0, $a0, 0xFFFF
    /* C6F84 002C6384 00031C00 */  sll        $v1, $v1, 16
    /* C6F88 002C6388 00621825 */  or         $v1, $v1, $v0
    /* C6F8C 002C638C 00003812 */  mflo       $a3
    /* C6F90 002C6390 0067102B */  sltu       $v0, $v1, $a3
    /* C6F94 002C6394 1040000B */  beqz       $v0, .L002C63C4
    /* C6F98 002C6398 000A1400 */   sll       $v0, $t2, 16
    /* C6F9C 002C639C 00681821 */  addu       $v1, $v1, $t0
    /* C6FA0 002C63A0 0068102B */  sltu       $v0, $v1, $t0
    /* C6FA4 002C63A4 14400006 */  bnez       $v0, .L002C63C0
    /* C6FA8 002C63A8 24C6FFFF */   addiu     $a2, $a2, -0x1
    /* C6FAC 002C63AC 0067102B */  sltu       $v0, $v1, $a3
    /* C6FB0 002C63B0 10400004 */  beqz       $v0, .L002C63C4
    /* C6FB4 002C63B4 000A1400 */   sll       $v0, $t2, 16
    /* C6FB8 002C63B8 24C6FFFF */  addiu      $a2, $a2, -0x1
    /* C6FBC 002C63BC 00681821 */  addu       $v1, $v1, $t0
  .L002C63C0:
    /* C6FC0 002C63C0 000A1400 */  sll        $v0, $t2, 16
  .L002C63C4:
    /* C6FC4 002C63C4 00463025 */  or         $a2, $v0, $a2
    /* C6FC8 002C63C8 00672023 */  subu       $a0, $v1, $a3
    /* C6FCC 002C63CC 00C90019 */  multu      $a2, $t1
    /* C6FD0 002C63D0 00001810 */  mfhi       $v1
    /* C6FD4 002C63D4 0083102B */  sltu       $v0, $a0, $v1
    /* C6FD8 002C63D8 00004012 */  mflo       $t0
    /* C6FDC 002C63DC 54400007 */  bnel       $v0, $zero, .L002C63FC
    /* C6FE0 002C63E0 24C6FFFF */   addiu     $a2, $a2, -0x1
    /* C6FE4 002C63E4 14640006 */  bne        $v1, $a0, .L002C6400
    /* C6FE8 002C63E8 00005021 */   addu      $t2, $zero, $zero
    /* C6FEC 002C63EC 0168102B */  sltu       $v0, $t3, $t0
    /* C6FF0 002C63F0 10400004 */  beqz       $v0, .L002C6404
    /* C6FF4 002C63F4 00C06821 */   addu      $t5, $a2, $zero
    /* C6FF8 002C63F8 24C6FFFF */  addiu      $a2, $a2, -0x1
  .L002C63FC:
    /* C6FFC 002C63FC 00005021 */  addu       $t2, $zero, $zero
  .L002C6400:
    /* C7000 002C6400 00C06821 */  addu       $t5, $a2, $zero
  .L002C6404:
    /* C7004 002C6404 01406021 */  addu       $t4, $t2, $zero
    /* C7008 002C6408 01801021 */  addu       $v0, $t4, $zero
    /* C700C 002C640C 03E00008 */  jr         $ra
endlabel func_002C5E90
