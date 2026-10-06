.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B6B80-0x1B6D30 (VRAM 0x00448B80) */
glabel __osGetId
    /* 1B6B80 00448B80 27BDFF98 */  addiu      $sp, $sp, -0x68
    /* 1B6B84 00448B84 AFB1005C */  sw         $s1, 0x5C($sp)
    /* 1B6B88 00448B88 00808821 */  addu       $s1, $a0, $zero
    /* 1B6B8C 00448B8C AFBF0060 */  sw         $ra, 0x60($sp)
    /* 1B6B90 00448B90 AFB00058 */  sw         $s0, 0x58($sp)
    /* 1B6B94 00448B94 92220065 */  lbu        $v0, 0x65($s1)
    /* 1B6B98 00448B98 10400006 */  beqz       $v0, .L00448BB4
    /* 1B6B9C 00448B9C 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B6BA0 00448BA0 0C112645 */  jal        __osPfsSelectBank
    /* 1B6BA4 00448BA4 A2200065 */   sb        $zero, 0x65($s1)
  .L00448BA8:
    /* 1B6BA8 00448BA8 00401821 */  addu       $v1, $v0, $zero
    /* 1B6BAC 00448BAC 1460005B */  bnez       $v1, .L00448D1C
    /* 1B6BB0 00448BB0 24060001 */   addiu     $a2, $zero, 0x1
  .L00448BB4:
    /* 1B6BB4 00448BB4 8E240004 */  lw         $a0, 0x4($s1)
    /* 1B6BB8 00448BB8 8E250008 */  lw         $a1, 0x8($s1)
    /* 1B6BBC 00448BBC 0C0AF564 */  jal        __osContRamRead
    /* 1B6BC0 00448BC0 27A70010 */   addiu     $a3, $sp, 0x10
    /* 1B6BC4 00448BC4 00401821 */  addu       $v1, $v0, $zero
    /* 1B6BC8 00448BC8 14600054 */  bnez       $v1, .L00448D1C
    /* 1B6BCC 00448BCC 27A40010 */   addiu     $a0, $sp, 0x10
    /* 1B6BD0 00448BD0 27A50050 */  addiu      $a1, $sp, 0x50
    /* 1B6BD4 00448BD4 0C112601 */  jal        __osIdCheckSum
    /* 1B6BD8 00448BD8 27A60052 */   addiu     $a2, $sp, 0x52
    /* 1B6BDC 00448BDC 97A3002C */  lhu        $v1, 0x2C($sp)
    /* 1B6BE0 00448BE0 97A20050 */  lhu        $v0, 0x50($sp)
    /* 1B6BE4 00448BE4 14620005 */  bne        $v1, $v0, .L00448BFC
    /* 1B6BE8 00448BE8 27B00010 */   addiu     $s0, $sp, 0x10
    /* 1B6BEC 00448BEC 97A3002E */  lhu        $v1, 0x2E($sp)
    /* 1B6BF0 00448BF0 97A20052 */  lhu        $v0, 0x52($sp)
    /* 1B6BF4 00448BF4 10620013 */  beq        $v1, $v0, .L00448C44
    /* 1B6BF8 00448BF8 00000000 */   nop
  .L00448BFC:
    /* 1B6BFC 00448BFC 02202021 */  addu       $a0, $s1, $zero
    /* 1B6C00 00448C00 0C112466 */  jal        __osCheckPackId
    /* 1B6C04 00448C04 02002821 */   addu      $a1, $s0, $zero
    /* 1B6C08 00448C08 00401821 */  addu       $v1, $v0, $zero
    /* 1B6C0C 00448C0C 2402000A */  addiu      $v0, $zero, 0xA
    /* 1B6C10 00448C10 1462000A */  bne        $v1, $v0, .L00448C3C
    /* 1B6C14 00448C14 02202021 */   addu      $a0, $s1, $zero
    /* 1B6C18 00448C18 02002821 */  addu       $a1, $s0, $zero
    /* 1B6C1C 00448C1C 27B00030 */  addiu      $s0, $sp, 0x30
    /* 1B6C20 00448C20 0C1123AC */  jal        __osRepairPackId
    /* 1B6C24 00448C24 02003021 */   addu      $a2, $s0, $zero
    /* 1B6C28 00448C28 00401821 */  addu       $v1, $v0, $zero
    /* 1B6C2C 00448C2C 10600005 */  beqz       $v1, .L00448C44
    /* 1B6C30 00448C30 00000000 */   nop
    /* 1B6C34 00448C34 08112347 */  j          .L00448D1C
    /* 1B6C38 00448C38 00000000 */   nop
  .L00448C3C:
    /* 1B6C3C 00448C3C 14600037 */  bnez       $v1, .L00448D1C
    /* 1B6C40 00448C40 00601021 */   addu      $v0, $v1, $zero
  .L00448C44:
    /* 1B6C44 00448C44 96020018 */  lhu        $v0, 0x18($s0)
    /* 1B6C48 00448C48 30420001 */  andi       $v0, $v0, 0x1
    /* 1B6C4C 00448C4C 1440000F */  bnez       $v0, .L00448C8C
    /* 1B6C50 00448C50 00002021 */   addu      $a0, $zero, $zero
    /* 1B6C54 00448C54 02202021 */  addu       $a0, $s1, $zero
    /* 1B6C58 00448C58 02002821 */  addu       $a1, $s0, $zero
    /* 1B6C5C 00448C5C 27B00030 */  addiu      $s0, $sp, 0x30
    /* 1B6C60 00448C60 0C1123AC */  jal        __osRepairPackId
    /* 1B6C64 00448C64 02003021 */   addu      $a2, $s0, $zero
    /* 1B6C68 00448C68 00401821 */  addu       $v1, $v0, $zero
    /* 1B6C6C 00448C6C 1460002B */  bnez       $v1, .L00448D1C
    /* 1B6C70 00448C70 00000000 */   nop
    /* 1B6C74 00448C74 97A20048 */  lhu        $v0, 0x48($sp)
    /* 1B6C78 00448C78 30420001 */  andi       $v0, $v0, 0x1
    /* 1B6C7C 00448C7C 14400003 */  bnez       $v0, .L00448C8C
    /* 1B6C80 00448C80 00002021 */   addu      $a0, $zero, $zero
    /* 1B6C84 00448C84 08112347 */  j          .L00448D1C
    /* 1B6C88 00448C88 2402000B */   addiu     $v0, $zero, 0xB
  .L00448C8C:
    /* 1B6C8C 00448C8C 02241821 */  addu       $v1, $s1, $a0
  .L00448C90:
    /* 1B6C90 00448C90 02041021 */  addu       $v0, $s0, $a0
    /* 1B6C94 00448C94 90420000 */  lbu        $v0, 0x0($v0)
    /* 1B6C98 00448C98 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B6C9C 00448C9C A062000C */  sb         $v0, 0xC($v1)
    /* 1B6CA0 00448CA0 28820020 */  slti       $v0, $a0, 0x20
    /* 1B6CA4 00448CA4 1440FFFA */  bnez       $v0, .L00448C90
    /* 1B6CA8 00448CA8 02241821 */   addu      $v1, $s1, $a0
    /* 1B6CAC 00448CAC 24060007 */  addiu      $a2, $zero, 0x7
    /* 1B6CB0 00448CB0 8E240004 */  lw         $a0, 0x4($s1)
    /* 1B6CB4 00448CB4 8E250008 */  lw         $a1, 0x8($s1)
    /* 1B6CB8 00448CB8 9202001B */  lbu        $v0, 0x1B($s0)
    /* 1B6CBC 00448CBC 2627002C */  addiu      $a3, $s1, 0x2C
    /* 1B6CC0 00448CC0 AE22004C */  sw         $v0, 0x4C($s1)
    /* 1B6CC4 00448CC4 9203001A */  lbu        $v1, 0x1A($s0)
    /* 1B6CC8 00448CC8 24020010 */  addiu      $v0, $zero, 0x10
    /* 1B6CCC 00448CCC AE220050 */  sw         $v0, 0x50($s1)
    /* 1B6CD0 00448CD0 24020008 */  addiu      $v0, $zero, 0x8
    /* 1B6CD4 00448CD4 AE220054 */  sw         $v0, 0x54($s1)
    /* 1B6CD8 00448CD8 A2230064 */  sb         $v1, 0x64($s1)
    /* 1B6CDC 00448CDC 306300FF */  andi       $v1, $v1, 0xFF
    /* 1B6CE0 00448CE0 00031840 */  sll        $v1, $v1, 1
    /* 1B6CE4 00448CE4 92220064 */  lbu        $v0, 0x64($s1)
    /* 1B6CE8 00448CE8 24630003 */  addiu      $v1, $v1, 0x3
    /* 1B6CEC 00448CEC AE230060 */  sw         $v1, 0x60($s1)
    /* 1B6CF0 00448CF0 92230064 */  lbu        $v1, 0x64($s1)
    /* 1B6CF4 00448CF4 24420001 */  addiu      $v0, $v0, 0x1
    /* 1B6CF8 00448CF8 000210C0 */  sll        $v0, $v0, 3
    /* 1B6CFC 00448CFC 000318C0 */  sll        $v1, $v1, 3
    /* 1B6D00 00448D00 AE220058 */  sw         $v0, 0x58($s1)
    /* 1B6D04 00448D04 00431021 */  addu       $v0, $v0, $v1
    /* 1B6D08 00448D08 0C0AF564 */  jal        __osContRamRead
    /* 1B6D0C 00448D0C AE22005C */   sw        $v0, 0x5C($s1)
    /* 1B6D10 00448D10 00401821 */  addu       $v1, $v0, $zero
    /* 1B6D14 00448D14 50600001 */  beql       $v1, $zero, .L00448D1C
    /* 1B6D18 00448D18 00001021 */   addu      $v0, $zero, $zero
  .L00448D1C:
    /* 1B6D1C 00448D1C 8FBF0060 */  lw         $ra, 0x60($sp)
    /* 1B6D20 00448D20 8FB1005C */  lw         $s1, 0x5C($sp)
    /* 1B6D24 00448D24 8FB00058 */  lw         $s0, 0x58($sp)
    /* 1B6D28 00448D28 03E00008 */  jr         $ra
    /* 1B6D2C 00448D2C 27BD0068 */   addiu     $sp, $sp, 0x68
endlabel __osGetId
