.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC4794-0xC4924 (VRAM 0x002C3B94) */
glabel func_002C3B94
    /* C4794 002C3B94 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C4798 002C3B98 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C479C 002C3B9C 24020004 */  addiu      $v0, $zero, 0x4
    /* C47A0 002C3BA0 10A2004A */  beq        $a1, $v0, .L002C3CCC
    /* C47A4 002C3BA4 00803821 */   addu      $a3, $a0, $zero
    /* C47A8 002C3BA8 24020005 */  addiu      $v0, $zero, 0x5
    /* C47AC 002C3BAC 14A2005A */  bne        $a1, $v0, .L002C3D18
    /* C47B0 002C3BB0 00C01821 */   addu      $v1, $a2, $zero
    /* C47B4 002C3BB4 ACE60028 */  sw         $a2, 0x28($a3)
    /* C47B8 002C3BB8 8CC20000 */  lw         $v0, 0x0($a2)
    /* C47BC 002C3BBC ACE00038 */  sw         $zero, 0x38($a3)
    /* C47C0 002C3BC0 ACE20044 */  sw         $v0, 0x44($a3)
    /* C47C4 002C3BC4 90630008 */  lbu        $v1, 0x8($v1)
    /* C47C8 002C3BC8 24020001 */  addiu      $v0, $zero, 0x1
    /* C47CC 002C3BCC 10620029 */  beq        $v1, $v0, .L002C3C74
    /* C47D0 002C3BD0 28620002 */   slti      $v0, $v1, 0x2
    /* C47D4 002C3BD4 50400005 */  beql       $v0, $zero, .L002C3BEC
    /* C47D8 002C3BD8 24020002 */   addiu     $v0, $zero, 0x2
    /* C47DC 002C3BDC 10600007 */  beqz       $v1, .L002C3BFC
    /* C47E0 002C3BE0 00000000 */   nop
    /* C47E4 002C3BE4 080B0F46 */  j          .L002C3D18
    /* C47E8 002C3BE8 00000000 */   nop
  .L002C3BEC:
    /* C47EC 002C3BEC 10620030 */  beq        $v1, $v0, .L002C3CB0
    /* C47F0 002C3BF0 00000000 */   nop
    /* C47F4 002C3BF4 080B0F46 */  j          .L002C3D18
    /* C47F8 002C3BF8 00000000 */   nop
  .L002C3BFC:
    /* C47FC 002C3BFC 8CE30028 */  lw         $v1, 0x28($a3)
    /* C4800 002C3C00 3C02002C */  lui        $v0, %hi(D_002C31C0)
    /* C4804 002C3C04 244231C0 */  addiu      $v0, $v0, %lo(D_002C31C0)
    /* C4808 002C3C08 ACE20004 */  sw         $v0, 0x4($a3)
    /* C480C 002C3C0C 8C630010 */  lw         $v1, 0x10($v1)
    /* C4810 002C3C10 8C620004 */  lw         $v0, 0x4($v1)
    /* C4814 002C3C14 8C630000 */  lw         $v1, 0x0($v1)
    /* C4818 002C3C18 00021040 */  sll        $v0, $v0, 1
    /* C481C 002C3C1C 00620018 */  mult       $v1, $v0
    /* C4820 002C3C20 8CE30028 */  lw         $v1, 0x28($a3)
    /* C4824 002C3C24 00004012 */  mflo       $t0
    /* C4828 002C3C28 000810C0 */  sll        $v0, $t0, 3
    /* C482C 002C3C2C ACE2002C */  sw         $v0, 0x2C($a3)
    /* C4830 002C3C30 8C62000C */  lw         $v0, 0xC($v1)
    /* C4834 002C3C34 10400021 */  beqz       $v0, .L002C3CBC
    /* C4838 002C3C38 24060020 */   addiu     $a2, $zero, 0x20
    /* C483C 002C3C3C 8C420000 */  lw         $v0, 0x0($v0)
    /* C4840 002C3C40 ACE2001C */  sw         $v0, 0x1C($a3)
    /* C4844 002C3C44 8C62000C */  lw         $v0, 0xC($v1)
    /* C4848 002C3C48 8C420004 */  lw         $v0, 0x4($v0)
    /* C484C 002C3C4C ACE20020 */  sw         $v0, 0x20($a3)
    /* C4850 002C3C50 8C62000C */  lw         $v0, 0xC($v1)
    /* C4854 002C3C54 8C420008 */  lw         $v0, 0x8($v0)
    /* C4858 002C3C58 ACE20024 */  sw         $v0, 0x24($a3)
    /* C485C 002C3C5C 8C64000C */  lw         $a0, 0xC($v1)
    /* C4860 002C3C60 8CE50018 */  lw         $a1, 0x18($a3)
    /* C4864 002C3C64 0C0AD4F8 */  jal        func_002B53E0
    /* C4868 002C3C68 2484000C */   addiu     $a0, $a0, 0xC
    /* C486C 002C3C6C 080B0F46 */  j          .L002C3D18
    /* C4870 002C3C70 00000000 */   nop
  .L002C3C74:
    /* C4874 002C3C74 8CE30028 */  lw         $v1, 0x28($a3)
    /* C4878 002C3C78 3C02002C */  lui        $v0, %hi(func_002C3604)
    /* C487C 002C3C7C 24423604 */  addiu      $v0, $v0, %lo(func_002C3604)
    /* C4880 002C3C80 ACE20004 */  sw         $v0, 0x4($a3)
    /* C4884 002C3C84 8C62000C */  lw         $v0, 0xC($v1)
    /* C4888 002C3C88 5040000D */  beql       $v0, $zero, .L002C3CC0
    /* C488C 002C3C8C ACE00024 */   sw        $zero, 0x24($a3)
    /* C4890 002C3C90 8C420000 */  lw         $v0, 0x0($v0)
    /* C4894 002C3C94 ACE2001C */  sw         $v0, 0x1C($a3)
    /* C4898 002C3C98 8C62000C */  lw         $v0, 0xC($v1)
    /* C489C 002C3C9C 8C420004 */  lw         $v0, 0x4($v0)
    /* C48A0 002C3CA0 ACE20020 */  sw         $v0, 0x20($a3)
    /* C48A4 002C3CA4 8C62000C */  lw         $v0, 0xC($v1)
    /* C48A8 002C3CA8 080B0F44 */  j          .L002C3D10
    /* C48AC 002C3CAC 00000000 */   nop
  .L002C3CB0:
    /* C48B0 002C3CB0 3C02002C */  lui        $v0, %hi(func_002C3988)
    /* C48B4 002C3CB4 24423988 */  addiu      $v0, $v0, %lo(func_002C3988)
    /* C48B8 002C3CB8 ACE20004 */  sw         $v0, 0x4($a3)
  .L002C3CBC:
    /* C48BC 002C3CBC ACE00024 */  sw         $zero, 0x24($a3)
  .L002C3CC0:
    /* C48C0 002C3CC0 ACE00020 */  sw         $zero, 0x20($a3)
    /* C48C4 002C3CC4 080B0F46 */  j          .L002C3D18
    /* C48C8 002C3CC8 ACE0001C */   sw        $zero, 0x1C($a3)
  .L002C3CCC:
    /* C48CC 002C3CCC 8CE20028 */  lw         $v0, 0x28($a3)
    /* C48D0 002C3CD0 24040001 */  addiu      $a0, $zero, 0x1
    /* C48D4 002C3CD4 ACE0003C */  sw         $zero, 0x3C($a3)
    /* C48D8 002C3CD8 ACE40040 */  sw         $a0, 0x40($a3)
    /* C48DC 002C3CDC 1040000E */  beqz       $v0, .L002C3D18
    /* C48E0 002C3CE0 ACE00038 */   sw        $zero, 0x38($a3)
    /* C48E4 002C3CE4 8C420000 */  lw         $v0, 0x0($v0)
    /* C48E8 002C3CE8 8CE30028 */  lw         $v1, 0x28($a3)
    /* C48EC 002C3CEC ACE20044 */  sw         $v0, 0x44($a3)
    /* C48F0 002C3CF0 90620008 */  lbu        $v0, 0x8($v1)
    /* C48F4 002C3CF4 10400003 */  beqz       $v0, .L002C3D04
    /* C48F8 002C3CF8 00000000 */   nop
    /* C48FC 002C3CFC 14440006 */  bne        $v0, $a0, .L002C3D18
    /* C4900 002C3D00 00000000 */   nop
  .L002C3D04:
    /* C4904 002C3D04 8C62000C */  lw         $v0, 0xC($v1)
    /* C4908 002C3D08 10400003 */  beqz       $v0, .L002C3D18
    /* C490C 002C3D0C 00000000 */   nop
  .L002C3D10:
    /* C4910 002C3D10 8C420008 */  lw         $v0, 0x8($v0)
    /* C4914 002C3D14 ACE20024 */  sw         $v0, 0x24($a3)
  .L002C3D18:
    /* C4918 002C3D18 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C491C 002C3D1C 03E00008 */  jr         $ra
    /* C4920 002C3D20 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002C3B94
