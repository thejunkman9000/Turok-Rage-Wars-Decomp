.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4780-0xB48F0 (VRAM 0x002B3B80) */
glabel alCSPNew
    /* B4780 002B3B80 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B4784 002B3B84 AFB00018 */  sw         $s0, 0x18($sp)
    /* B4788 002B3B88 00808021 */  addu       $s0, $a0, $zero
    /* B478C 002B3B8C AFB1001C */  sw         $s1, 0x1C($sp)
    /* B4790 002B3B90 00A08821 */  addu       $s1, $a1, $zero
    /* B4794 002B3B94 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B4798 002B3B98 AFB20020 */  sw         $s2, 0x20($sp)
    /* B479C 002B3B9C 8E32000C */  lw         $s2, 0xC($s1)
    /* B47A0 002B3BA0 3C03800E */  lui        $v1, %hi(D_800D80A0)
    /* B47A4 002B3BA4 8C6380A0 */  lw         $v1, %lo(D_800D80A0)($v1)
    /* B47A8 002B3BA8 240200FF */  addiu      $v0, $zero, 0xFF
    /* B47AC 002B3BAC A6020030 */  sh         $v0, 0x30($s0)
    /* B47B0 002B3BB0 240201E8 */  addiu      $v0, $zero, 0x1E8
    /* B47B4 002B3BB4 AE020024 */  sw         $v0, 0x24($s0)
    /* B47B8 002B3BB8 24027FFF */  addiu      $v0, $zero, 0x7FFF
    /* B47BC 002B3BBC A6020032 */  sh         $v0, 0x32($s0)
    /* B47C0 002B3BC0 24023E80 */  addiu      $v0, $zero, 0x3E80
    /* B47C4 002B3BC4 AE000020 */  sw         $zero, 0x20($s0)
    /* B47C8 002B3BC8 AE000018 */  sw         $zero, 0x18($s0)
    /* B47CC 002B3BCC AE000028 */  sw         $zero, 0x28($s0)
    /* B47D0 002B3BD0 AE00002C */  sw         $zero, 0x2C($s0)
    /* B47D4 002B3BD4 AE02005C */  sw         $v0, 0x5C($s0)
    /* B47D8 002B3BD8 AE00001C */  sw         $zero, 0x1C($s0)
    /* B47DC 002B3BDC AE030014 */  sw         $v1, 0x14($s0)
    /* B47E0 002B3BE0 8E220010 */  lw         $v0, 0x10($s1)
    /* B47E4 002B3BE4 00002021 */  addu       $a0, $zero, $zero
    /* B47E8 002B3BE8 AE020070 */  sw         $v0, 0x70($s0)
    /* B47EC 002B3BEC 8E220014 */  lw         $v0, 0x14($s1)
    /* B47F0 002B3BF0 00802821 */  addu       $a1, $a0, $zero
    /* B47F4 002B3BF4 AE020074 */  sw         $v0, 0x74($s0)
    /* B47F8 002B3BF8 8E230018 */  lw         $v1, 0x18($s1)
    /* B47FC 002B3BFC 24020009 */  addiu      $v0, $zero, 0x9
    /* B4800 002B3C00 A6020038 */  sh         $v0, 0x38($s0)
    /* B4804 002B3C04 AE030078 */  sw         $v1, 0x78($s0)
    /* B4808 002B3C08 92220008 */  lbu        $v0, 0x8($s1)
    /* B480C 002B3C0C 02403021 */  addu       $a2, $s2, $zero
    /* B4810 002B3C10 A2020034 */  sb         $v0, 0x34($s0)
    /* B4814 002B3C14 92270008 */  lbu        $a3, 0x8($s1)
    /* B4818 002B3C18 24020010 */  addiu      $v0, $zero, 0x10
    /* B481C 002B3C1C 0C0AD504 */  jal        alHeapDBAlloc
    /* B4820 002B3C20 AFA20010 */   sw        $v0, 0x10($sp)
    /* B4824 002B3C24 02002021 */  addu       $a0, $s0, $zero
    /* B4828 002B3C28 0C0ADA98 */  jal        __initChanState
    /* B482C 002B3C2C AE020060 */   sw        $v0, 0x60($s0)
    /* B4830 002B3C30 00002021 */  addu       $a0, $zero, $zero
    /* B4834 002B3C34 00802821 */  addu       $a1, $a0, $zero
    /* B4838 002B3C38 24020038 */  addiu      $v0, $zero, 0x38
    /* B483C 002B3C3C AFA20010 */  sw         $v0, 0x10($sp)
    /* B4840 002B3C40 8E270000 */  lw         $a3, 0x0($s1)
    /* B4844 002B3C44 0C0AD504 */  jal        alHeapDBAlloc
    /* B4848 002B3C48 02403021 */   addu      $a2, $s2, $zero
    /* B484C 002B3C4C AE00006C */  sw         $zero, 0x6C($s0)
    /* B4850 002B3C50 8E230000 */  lw         $v1, 0x0($s1)
    /* B4854 002B3C54 1860000A */  blez       $v1, .L002B3C80
    /* B4858 002B3C58 00002021 */   addu      $a0, $zero, $zero
    /* B485C 002B3C5C 00401821 */  addu       $v1, $v0, $zero
  .L002B3C60:
    /* B4860 002B3C60 8E02006C */  lw         $v0, 0x6C($s0)
    /* B4864 002B3C64 24840001 */  addiu      $a0, $a0, 0x1
    /* B4868 002B3C68 AC620000 */  sw         $v0, 0x0($v1)
    /* B486C 002B3C6C AE03006C */  sw         $v1, 0x6C($s0)
    /* B4870 002B3C70 8E220000 */  lw         $v0, 0x0($s1)
    /* B4874 002B3C74 0082102A */  slt        $v0, $a0, $v0
    /* B4878 002B3C78 1440FFF9 */  bnez       $v0, .L002B3C60
    /* B487C 002B3C7C 24630038 */   addiu     $v1, $v1, 0x38
  .L002B3C80:
    /* B4880 002B3C80 00002021 */  addu       $a0, $zero, $zero
    /* B4884 002B3C84 00802821 */  addu       $a1, $a0, $zero
    /* B4888 002B3C88 2402001C */  addiu      $v0, $zero, 0x1C
    /* B488C 002B3C8C AE000064 */  sw         $zero, 0x64($s0)
    /* B4890 002B3C90 AE000068 */  sw         $zero, 0x68($s0)
    /* B4894 002B3C94 AFA20010 */  sw         $v0, 0x10($sp)
    /* B4898 002B3C98 8E270004 */  lw         $a3, 0x4($s1)
    /* B489C 002B3C9C 0C0AD504 */  jal        alHeapDBAlloc
    /* B48A0 002B3CA0 02403021 */   addu      $a2, $s2, $zero
    /* B48A4 002B3CA4 26040048 */  addiu      $a0, $s0, 0x48
    /* B48A8 002B3CA8 8E260004 */  lw         $a2, 0x4($s1)
    /* B48AC 002B3CAC 0C0AD424 */  jal        alEvtqNew
    /* B48B0 002B3CB0 00402821 */   addu      $a1, $v0, $zero
    /* B48B4 002B3CB4 02002821 */  addu       $a1, $s0, $zero
    /* B48B8 002B3CB8 3C04800E */  lui        $a0, %hi(D_800D80A0)
    /* B48BC 002B3CBC 8C8480A0 */  lw         $a0, %lo(D_800D80A0)($a0)
    /* B48C0 002B3CC0 3C02002B */  lui        $v0, %hi(__CSPVoiceHandler)
    /* B48C4 002B3CC4 24423CF0 */  addiu      $v0, $v0, %lo(__CSPVoiceHandler)
    /* B48C8 002B3CC8 ACA00000 */  sw         $zero, 0x0($a1)
    /* B48CC 002B3CCC ACA20008 */  sw         $v0, 0x8($a1)
    /* B48D0 002B3CD0 0C0AE020 */  jal        alSynAddPlayer
    /* B48D4 002B3CD4 ACA50004 */   sw        $a1, 0x4($a1)
    /* B48D8 002B3CD8 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B48DC 002B3CDC 8FB20020 */  lw         $s2, 0x20($sp)
    /* B48E0 002B3CE0 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B48E4 002B3CE4 8FB00018 */  lw         $s0, 0x18($sp)
    /* B48E8 002B3CE8 03E00008 */  jr         $ra
    /* B48EC 002B3CEC 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alCSPNew
