.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B7B44-0x1B7E38 (VRAM 0x00449B44) */
glabel func_00449B44
    /* 1B7B44 00449B44 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* 1B7B48 00449B48 AFB1001C */  sw         $s1, 0x1C($sp)
    /* 1B7B4C 00449B4C 00808821 */  addu       $s1, $a0, $zero
    /* 1B7B50 00449B50 AFB00018 */  sw         $s0, 0x18($sp)
    /* 1B7B54 00449B54 00A08021 */  addu       $s0, $a1, $zero
    /* 1B7B58 00449B58 AFBF0028 */  sw         $ra, 0x28($sp)
    /* 1B7B5C 00449B5C AFB30024 */  sw         $s3, 0x24($sp)
    /* 1B7B60 00449B60 0C0992E3 */  jal        func_00264B8C
    /* 1B7B64 00449B64 AFB20020 */   sw        $s2, 0x20($sp)
    /* 1B7B68 00449B68 24120001 */  addiu      $s2, $zero, 0x1
    /* 1B7B6C 00449B6C 8E221450 */  lw         $v0, 0x1450($s1)
    /* 1B7B70 00449B70 00009821 */  addu       $s3, $zero, $zero
    /* 1B7B74 00449B74 AE3205D0 */  sw         $s2, 0x5D0($s1)
    /* 1B7B78 00449B78 1440000B */  bnez       $v0, .L00449BA8
    /* 1B7B7C 00449B7C AE3005E0 */   sw        $s0, 0x5E0($s1)
    /* 1B7B80 00449B80 3C108014 */  lui        $s0, %hi(D_80145088)
    /* 1B7B84 00449B84 26105088 */  addiu      $s0, $s0, %lo(D_80145088)
    /* 1B7B88 00449B88 0C112CE2 */  jal        func_0044B388
    /* 1B7B8C 00449B8C 02002021 */   addu      $a0, $s0, $zero
    /* 1B7B90 00449B90 AE2205DC */  sw         $v0, 0x5DC($s1)
    /* 1B7B94 00449B94 8E0218C4 */  lw         $v0, 0x18C4($s0)
    /* 1B7B98 00449B98 54400004 */  bnel       $v0, $zero, .L00449BAC
    /* 1B7B9C 00449B9C AE321450 */   sw        $s2, 0x1450($s1)
    /* 1B7BA0 00449BA0 081126EB */  j          .L00449BAC
    /* 1B7BA4 00449BA4 00000000 */   nop
  .L00449BA8:
    /* 1B7BA8 00449BA8 AE2005DC */  sw         $zero, 0x5DC($s1)
  .L00449BAC:
    /* 1B7BAC 00449BAC 0C0860DB */  jal        func_0021836C
    /* 1B7BB0 00449BB0 26240938 */   addiu     $a0, $s1, 0x938
    /* 1B7BB4 00449BB4 0C0863A6 */  jal        func_00218E98
    /* 1B7BB8 00449BB8 26240CCC */   addiu     $a0, $s1, 0xCCC
    /* 1B7BBC 00449BBC A62005E8 */  sh         $zero, 0x5E8($s1)
    /* 1B7BC0 00449BC0 24040005 */  addiu      $a0, $zero, 0x5
    /* 1B7BC4 00449BC4 02241021 */  addu       $v0, $s1, $a0
  .L00449BC8:
    /* 1B7BC8 00449BC8 A0400644 */  sb         $zero, 0x644($v0)
    /* 1B7BCC 00449BCC 2484FFFF */  addiu      $a0, $a0, -0x1
    /* 1B7BD0 00449BD0 0481FFFD */  bgez       $a0, .L00449BC8
    /* 1B7BD4 00449BD4 2442FFFF */   addiu     $v0, $v0, -0x1
    /* 1B7BD8 00449BD8 24040005 */  addiu      $a0, $zero, 0x5
    /* 1B7BDC 00449BDC 02241021 */  addu       $v0, $s1, $a0
  .L00449BE0:
    /* 1B7BE0 00449BE0 A040064A */  sb         $zero, 0x64A($v0)
    /* 1B7BE4 00449BE4 2484FFFF */  addiu      $a0, $a0, -0x1
    /* 1B7BE8 00449BE8 0481FFFD */  bgez       $a0, .L00449BE0
    /* 1B7BEC 00449BEC 2442FFFF */   addiu     $v0, $v0, -0x1
    /* 1B7BF0 00449BF0 3C028014 */  lui        $v0, %hi(D_801462E5)
    /* 1B7BF4 00449BF4 904262E5 */  lbu        $v0, %lo(D_801462E5)($v0)
    /* 1B7BF8 00449BF8 10400028 */  beqz       $v0, .L00449C9C
    /* 1B7BFC 00449BFC 24020001 */   addiu     $v0, $zero, 0x1
    /* 1B7C00 00449C00 3C038014 */  lui        $v1, %hi(D_801462D5)
    /* 1B7C04 00449C04 906362D5 */  lbu        $v1, %lo(D_801462D5)($v1)
    /* 1B7C08 00449C08 14620017 */  bne        $v1, $v0, .L00449C68
    /* 1B7C0C 00449C0C 24020004 */   addiu     $v0, $zero, 0x4
    /* 1B7C10 00449C10 8E221450 */  lw         $v0, 0x1450($s1)
    /* 1B7C14 00449C14 14400014 */  bnez       $v0, .L00449C68
    /* 1B7C18 00449C18 24020004 */   addiu     $v0, $zero, 0x4
    /* 1B7C1C 00449C1C 8E2205D4 */  lw         $v0, 0x5D4($s1)
    /* 1B7C20 00449C20 8E2305D8 */  lw         $v1, 0x5D8($s1)
    /* 1B7C24 00449C24 00022040 */  sll        $a0, $v0, 1
    /* 1B7C28 00449C28 00822021 */  addu       $a0, $a0, $v0
    /* 1B7C2C 00449C2C 000420C0 */  sll        $a0, $a0, 3
    /* 1B7C30 00449C30 00822021 */  addu       $a0, $a0, $v0
    /* 1B7C34 00449C34 00042100 */  sll        $a0, $a0, 4
    /* 1B7C38 00449C38 3C028010 */  lui        $v0, %hi(D_80102B00)
    /* 1B7C3C 00449C3C 24422B00 */  addiu      $v0, $v0, %lo(D_80102B00)
    /* 1B7C40 00449C40 80650080 */  lb         $a1, 0x80($v1)
    /* 1B7C44 00449C44 0C08BD11 */  jal        func_0022F444
    /* 1B7C48 00449C48 00822021 */   addu      $a0, $a0, $v0
    /* 1B7C4C 00449C4C 304200FF */  andi       $v0, $v0, 0xFF
    /* 1B7C50 00449C50 00021042 */  srl        $v0, $v0, 1
    /* 1B7C54 00449C54 24420001 */  addiu      $v0, $v0, 0x1
    /* 1B7C58 00449C58 AE22133C */  sw         $v0, 0x133C($s1)
    /* 1B7C5C 00449C5C 3C038014 */  lui        $v1, %hi(D_801462D5)
    /* 1B7C60 00449C60 906362D5 */  lbu        $v1, %lo(D_801462D5)($v1)
    /* 1B7C64 00449C64 24020004 */  addiu      $v0, $zero, 0x4
  .L00449C68:
    /* 1B7C68 00449C68 1462000D */  bne        $v1, $v0, .L00449CA0
    /* 1B7C6C 00449C6C 24020001 */   addiu     $v0, $zero, 0x1
    /* 1B7C70 00449C70 8E221450 */  lw         $v0, 0x1450($s1)
    /* 1B7C74 00449C74 1440000A */  bnez       $v0, .L00449CA0
    /* 1B7C78 00449C78 24020001 */   addiu     $v0, $zero, 0x1
    /* 1B7C7C 00449C7C 3C02800E */  lui        $v0, %hi(D_800E4680)
    /* 1B7C80 00449C80 8C424680 */  lw         $v0, %lo(D_800E4680)($v0)
    /* 1B7C84 00449C84 50400006 */  beql       $v0, $zero, .L00449CA0
    /* 1B7C88 00449C88 24020001 */   addiu     $v0, $zero, 0x1
    /* 1B7C8C 00449C8C 90420028 */  lbu        $v0, 0x28($v0)
    /* 1B7C90 00449C90 AE22133C */  sw         $v0, 0x133C($s1)
    /* 1B7C94 00449C94 08112728 */  j          .L00449CA0
    /* 1B7C98 00449C98 24020001 */   addiu     $v0, $zero, 0x1
  .L00449C9C:
    /* 1B7C9C 00449C9C 24020003 */  addiu      $v0, $zero, 0x3
  .L00449CA0:
    /* 1B7CA0 00449CA0 A62205EA */  sh         $v0, 0x5EA($s1)
    /* 1B7CA4 00449CA4 02202021 */  addu       $a0, $s1, $zero
    /* 1B7CA8 00449CA8 0C086BDB */  jal        func_0021AF6C
    /* 1B7CAC 00449CAC AE2013C8 */   sw        $zero, 0x13C8($s1)
    /* 1B7CB0 00449CB0 00002021 */  addu       $a0, $zero, $zero
    /* 1B7CB4 00449CB4 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B7CB8 00449CB8 AE200670 */  sw         $zero, 0x670($s1)
    /* 1B7CBC 00449CBC AE200674 */  sw         $zero, 0x674($s1)
    /* 1B7CC0 00449CC0 AE22086C */  sw         $v0, 0x86C($s1)
    /* 1B7CC4 00449CC4 AE220870 */  sw         $v0, 0x870($s1)
  .L00449CC8:
    /* 1B7CC8 00449CC8 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7CCC 00449CCC 00041840 */  sll        $v1, $a0, 1
    /* 1B7CD0 00449CD0 00431021 */  addu       $v0, $v0, $v1
    /* 1B7CD4 00449CD4 A440002C */  sh         $zero, 0x2C($v0)
    /* 1B7CD8 00449CD8 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7CDC 00449CDC 00431021 */  addu       $v0, $v0, $v1
    /* 1B7CE0 00449CE0 A440003C */  sh         $zero, 0x3C($v0)
    /* 1B7CE4 00449CE4 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7CE8 00449CE8 00431021 */  addu       $v0, $v0, $v1
    /* 1B7CEC 00449CEC A440000C */  sh         $zero, 0xC($v0)
    /* 1B7CF0 00449CF0 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7CF4 00449CF4 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B7CF8 00449CF8 00431021 */  addu       $v0, $v0, $v1
    /* 1B7CFC 00449CFC A440001C */  sh         $zero, 0x1C($v0)
    /* 1B7D00 00449D00 28820008 */  slti       $v0, $a0, 0x8
    /* 1B7D04 00449D04 1440FFF0 */  bnez       $v0, .L00449CC8
    /* 1B7D08 00449D08 24100001 */   addiu     $s0, $zero, 0x1
    /* 1B7D0C 00449D0C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D10 00449D10 A4400000 */  sh         $zero, 0x0($v0)
    /* 1B7D14 00449D14 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D18 00449D18 A4400002 */  sh         $zero, 0x2($v0)
    /* 1B7D1C 00449D1C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D20 00449D20 A4400004 */  sh         $zero, 0x4($v0)
    /* 1B7D24 00449D24 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D28 00449D28 A4400006 */  sh         $zero, 0x6($v0)
    /* 1B7D2C 00449D2C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D30 00449D30 A440000A */  sh         $zero, 0xA($v0)
    /* 1B7D34 00449D34 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D38 00449D38 A4400008 */  sh         $zero, 0x8($v0)
    /* 1B7D3C 00449D3C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D40 00449D40 A040008D */  sb         $zero, 0x8D($v0)
    /* 1B7D44 00449D44 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D48 00449D48 A040008E */  sb         $zero, 0x8E($v0)
    /* 1B7D4C 00449D4C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D50 00449D50 02202021 */  addu       $a0, $s1, $zero
    /* 1B7D54 00449D54 A040008F */  sb         $zero, 0x8F($v0)
    /* 1B7D58 00449D58 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7D5C 00449D5C A0400090 */  sb         $zero, 0x90($v0)
    /* 1B7D60 00449D60 AE200638 */  sw         $zero, 0x638($s1)
    /* 1B7D64 00449D64 AE30063C */  sw         $s0, 0x63C($s1)
    /* 1B7D68 00449D68 AE200640 */  sw         $zero, 0x640($s1)
    /* 1B7D6C 00449D6C 0C11285F */  jal        func_0044A17C
    /* 1B7D70 00449D70 AE300868 */   sw        $s0, 0x868($s1)
    /* 1B7D74 00449D74 3C038014 */  lui        $v1, %hi(D_801462C8)
    /* 1B7D78 00449D78 246362C8 */  addiu      $v1, $v1, %lo(D_801462C8)
    /* 1B7D7C 00449D7C 9062001D */  lbu        $v0, 0x1D($v1)
    /* 1B7D80 00449D80 54400001 */  bnel       $v0, $zero, .L00449D88
    /* 1B7D84 00449D84 AE2013E8 */   sw        $zero, 0x13E8($s1)
  .L00449D88:
    /* 1B7D88 00449D88 1260001A */  beqz       $s3, .L00449DF4
    /* 1B7D8C 00449D8C 00000000 */   nop
    /* 1B7D90 00449D90 9062001D */  lbu        $v0, 0x1D($v1)
    /* 1B7D94 00449D94 1040000E */  beqz       $v0, .L00449DD0
    /* 1B7D98 00449D98 00000000 */   nop
    /* 1B7D9C 00449D9C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7DA0 00449DA0 A0400080 */  sb         $zero, 0x80($v0)
    /* 1B7DA4 00449DA4 AE2005E0 */  sw         $zero, 0x5E0($s1)
    /* 1B7DA8 00449DA8 AE30085C */  sw         $s0, 0x85C($s1)
    /* 1B7DAC 00449DAC 8C6205FC */  lw         $v0, 0x5FC($v1)
    /* 1B7DB0 00449DB0 3C050045 */  lui        $a1, %hi(D_00450830)
    /* 1B7DB4 00449DB4 24A50830 */  addiu      $a1, $a1, %lo(D_00450830)
    /* 1B7DB8 00449DB8 14400007 */  bnez       $v0, .L00449DD8
    /* 1B7DBC 00449DBC 00000000 */   nop
    /* 1B7DC0 00449DC0 3C050045 */  lui        $a1, %hi(D_00450758)
    /* 1B7DC4 00449DC4 24A50758 */  addiu      $a1, $a1, %lo(D_00450758)
    /* 1B7DC8 00449DC8 08112776 */  j          .L00449DD8
    /* 1B7DCC 00449DCC 00000000 */   nop
  .L00449DD0:
    /* 1B7DD0 00449DD0 3C050045 */  lui        $a1, %hi(D_00450BAC)
    /* 1B7DD4 00449DD4 24A50BAC */  addiu      $a1, $a1, %lo(D_00450BAC)
  .L00449DD8:
    /* 1B7DD8 00449DD8 8E2405DC */  lw         $a0, 0x5DC($s1)
    /* 1B7DDC 00449DDC 8E2205D4 */  lw         $v0, 0x5D4($s1)
    /* 1B7DE0 00449DE0 02203021 */  addu       $a2, $s1, $zero
    /* 1B7DE4 00449DE4 AFA20010 */  sw         $v0, 0x10($sp)
    /* 1B7DE8 00449DE8 8E270698 */  lw         $a3, 0x698($s1)
    /* 1B7DEC 00449DEC 0C1109B9 */  jal        func_004426E4
    /* 1B7DF0 00449DF0 24840554 */   addiu     $a0, $a0, 0x554
  .L00449DF4:
    /* 1B7DF4 00449DF4 8E2205D4 */  lw         $v0, 0x5D4($s1)
    /* 1B7DF8 00449DF8 8FBF0028 */  lw         $ra, 0x28($sp)
    /* 1B7DFC 00449DFC 8FB30024 */  lw         $s3, 0x24($sp)
    /* 1B7E00 00449E00 8FB20020 */  lw         $s2, 0x20($sp)
    /* 1B7E04 00449E04 8FB00018 */  lw         $s0, 0x18($sp)
    /* 1B7E08 00449E08 00021080 */  sll        $v0, $v0, 2
    /* 1B7E0C 00449E0C 3C018010 */  lui        $at, %hi(D_80102AE0)
    /* 1B7E10 00449E10 00220821 */  addu       $at, $at, $v0
    /* 1B7E14 00449E14 AC202AE0 */  sw         $zero, %lo(D_80102AE0)($at)
    /* 1B7E18 00449E18 8E2205D4 */  lw         $v0, 0x5D4($s1)
    /* 1B7E1C 00449E1C 8FB1001C */  lw         $s1, 0x1C($sp)
    /* 1B7E20 00449E20 00021080 */  sll        $v0, $v0, 2
    /* 1B7E24 00449E24 3C018010 */  lui        $at, %hi(D_80103140)
    /* 1B7E28 00449E28 00220821 */  addu       $at, $at, $v0
    /* 1B7E2C 00449E2C AC203140 */  sw         $zero, %lo(D_80103140)($at)
    /* 1B7E30 00449E30 03E00008 */  jr         $ra
    /* 1B7E34 00449E34 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_00449B44
