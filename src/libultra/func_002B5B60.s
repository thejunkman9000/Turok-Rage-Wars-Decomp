.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6760-0xB6964 (VRAM 0x002B5B60) */
glabel func_002B5B60
    /* B6760 002B5B60 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B6764 002B5B64 AFB1003C */  sw         $s1, 0x3C($sp)
    /* B6768 002B5B68 00808821 */  addu       $s1, $a0, $zero
    /* B676C 002B5B6C AFBF0044 */  sw         $ra, 0x44($sp)
    /* B6770 002B5B70 AFB20040 */  sw         $s2, 0x40($sp)
    /* B6774 002B5B74 AFB00038 */  sw         $s0, 0x38($sp)
    /* B6778 002B5B78 8E240018 */  lw         $a0, 0x18($s1)
    /* B677C 002B5B7C 10800073 */  beqz       $a0, .L002B5D4C
    /* B6780 002B5B80 00000000 */   nop
    /* B6784 002B5B84 0C0ADBD4 */  jal        func_002B6F50
    /* B6788 002B5B88 27A50010 */   addiu     $a1, $sp, 0x10
    /* B678C 002B5B8C 87B00010 */  lh         $s0, 0x10($sp)
    /* B6790 002B5B90 24020003 */  addiu      $v0, $zero, 0x3
    /* B6794 002B5B94 12020030 */  beq        $s0, $v0, .L002B5C58
    /* B6798 002B5B98 2A020004 */   slti      $v0, $s0, 0x4
    /* B679C 002B5B9C 10400005 */  beqz       $v0, .L002B5BB4
    /* B67A0 002B5BA0 24020001 */   addiu     $v0, $zero, 0x1
    /* B67A4 002B5BA4 12020008 */  beq        $s0, $v0, .L002B5BC8
    /* B67A8 002B5BA8 02202021 */   addu      $a0, $s1, $zero
    /* B67AC 002B5BAC 080AD74D */  j          .L002B5D34
    /* B67B0 002B5BB0 00000000 */   nop
  .L002B5BB4:
    /* B67B4 002B5BB4 24020004 */  addiu      $v0, $zero, 0x4
    /* B67B8 002B5BB8 12020054 */  beq        $s0, $v0, .L002B5D0C
    /* B67BC 002B5BBC 26240048 */   addiu     $a0, $s1, 0x48
    /* B67C0 002B5BC0 080AD74D */  j          .L002B5D34
    /* B67C4 002B5BC4 00000000 */   nop
  .L002B5BC8:
    /* B67C8 002B5BC8 0C0AD759 */  jal        func_002B5D64
    /* B67CC 002B5BCC 27A50010 */   addiu     $a1, $sp, 0x10
    /* B67D0 002B5BD0 8E22002C */  lw         $v0, 0x2C($s1)
    /* B67D4 002B5BD4 8E320018 */  lw         $s2, 0x18($s1)
    /* B67D8 002B5BD8 1450005C */  bne        $v0, $s0, .L002B5D4C
    /* B67DC 002B5BDC 00000000 */   nop
    /* B67E0 002B5BE0 1240005A */  beqz       $s2, .L002B5D4C
    /* B67E4 002B5BE4 02402021 */   addu      $a0, $s2, $zero
    /* B67E8 002B5BE8 0C0ADCF1 */  jal        func_002B73C4
    /* B67EC 002B5BEC 27A50030 */   addiu     $a1, $sp, 0x30
    /* B67F0 002B5BF0 304200FF */  andi       $v0, $v0, 0xFF
    /* B67F4 002B5BF4 10400055 */  beqz       $v0, .L002B5D4C
    /* B67F8 002B5BF8 00000000 */   nop
    /* B67FC 002B5BFC 8E220084 */  lw         $v0, 0x84($s1)
    /* B6800 002B5C00 10400012 */  beqz       $v0, .L002B5C4C
    /* B6804 002B5C04 00000000 */   nop
    /* B6808 002B5C08 0C0ADC66 */  jal        func_002B7198
    /* B680C 002B5C0C 02402021 */   addu      $a0, $s2, $zero
    /* B6810 002B5C10 8E230080 */  lw         $v1, 0x80($s1)
    /* B6814 002B5C14 8FA40030 */  lw         $a0, 0x30($sp)
    /* B6818 002B5C18 8C630008 */  lw         $v1, 0x8($v1)
    /* B681C 002B5C1C 00441021 */  addu       $v0, $v0, $a0
    /* B6820 002B5C20 0043102A */  slt        $v0, $v0, $v1
    /* B6824 002B5C24 14400009 */  bnez       $v0, .L002B5C4C
    /* B6828 002B5C28 00000000 */   nop
    /* B682C 002B5C2C 8E25007C */  lw         $a1, 0x7C($s1)
    /* B6830 002B5C30 0C0ADCE3 */  jal        func_002B738C
    /* B6834 002B5C34 02402021 */   addu      $a0, $s2, $zero
    /* B6838 002B5C38 8E230084 */  lw         $v1, 0x84($s1)
    /* B683C 002B5C3C 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B6840 002B5C40 10620002 */  beq        $v1, $v0, .L002B5C4C
    /* B6844 002B5C44 00621021 */   addu      $v0, $v1, $v0
    /* B6848 002B5C48 AE220084 */  sw         $v0, 0x84($s1)
  .L002B5C4C:
    /* B684C 002B5C4C 8FA20030 */  lw         $v0, 0x30($sp)
    /* B6850 002B5C50 080AD73B */  j          .L002B5CEC
    /* B6854 002B5C54 A7A00020 */   sh        $zero, 0x20($sp)
  .L002B5C58:
    /* B6858 002B5C58 02202021 */  addu       $a0, $s1, $zero
    /* B685C 002B5C5C 0C0ADBAF */  jal        func_002B6EBC
    /* B6860 002B5C60 27A50010 */   addiu     $a1, $sp, 0x10
    /* B6864 002B5C64 24030001 */  addiu      $v1, $zero, 0x1
    /* B6868 002B5C68 8E22002C */  lw         $v0, 0x2C($s1)
    /* B686C 002B5C6C 8E300018 */  lw         $s0, 0x18($s1)
    /* B6870 002B5C70 14430036 */  bne        $v0, $v1, .L002B5D4C
    /* B6874 002B5C74 00000000 */   nop
    /* B6878 002B5C78 12000034 */  beqz       $s0, .L002B5D4C
    /* B687C 002B5C7C 02002021 */   addu      $a0, $s0, $zero
    /* B6880 002B5C80 0C0ADCF1 */  jal        func_002B73C4
    /* B6884 002B5C84 27A50034 */   addiu     $a1, $sp, 0x34
    /* B6888 002B5C88 304200FF */  andi       $v0, $v0, 0xFF
    /* B688C 002B5C8C 1040002F */  beqz       $v0, .L002B5D4C
    /* B6890 002B5C90 00000000 */   nop
    /* B6894 002B5C94 8E220084 */  lw         $v0, 0x84($s1)
    /* B6898 002B5C98 10400012 */  beqz       $v0, .L002B5CE4
    /* B689C 002B5C9C 00000000 */   nop
    /* B68A0 002B5CA0 0C0ADC66 */  jal        func_002B7198
    /* B68A4 002B5CA4 02002021 */   addu      $a0, $s0, $zero
    /* B68A8 002B5CA8 8E230080 */  lw         $v1, 0x80($s1)
    /* B68AC 002B5CAC 8FA40034 */  lw         $a0, 0x34($sp)
    /* B68B0 002B5CB0 8C630008 */  lw         $v1, 0x8($v1)
    /* B68B4 002B5CB4 00441021 */  addu       $v0, $v0, $a0
    /* B68B8 002B5CB8 0043102A */  slt        $v0, $v0, $v1
    /* B68BC 002B5CBC 14400009 */  bnez       $v0, .L002B5CE4
    /* B68C0 002B5CC0 00000000 */   nop
    /* B68C4 002B5CC4 8E25007C */  lw         $a1, 0x7C($s1)
    /* B68C8 002B5CC8 0C0ADCE3 */  jal        func_002B738C
    /* B68CC 002B5CCC 02002021 */   addu      $a0, $s0, $zero
    /* B68D0 002B5CD0 8E230084 */  lw         $v1, 0x84($s1)
    /* B68D4 002B5CD4 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B68D8 002B5CD8 10620002 */  beq        $v1, $v0, .L002B5CE4
    /* B68DC 002B5CDC 00621021 */   addu      $v0, $v1, $v0
    /* B68E0 002B5CE0 AE220084 */  sw         $v0, 0x84($s1)
  .L002B5CE4:
    /* B68E4 002B5CE4 8FA20034 */  lw         $v0, 0x34($sp)
    /* B68E8 002B5CE8 A7A00020 */  sh         $zero, 0x20($sp)
  .L002B5CEC:
    /* B68EC 002B5CEC 8E260024 */  lw         $a2, 0x24($s1)
    /* B68F0 002B5CF0 00460018 */  mult       $v0, $a2
    /* B68F4 002B5CF4 26240048 */  addiu      $a0, $s1, 0x48
    /* B68F8 002B5CF8 00003012 */  mflo       $a2
    /* B68FC 002B5CFC 0C0AD469 */  jal        func_002B51A4
    /* B6900 002B5D00 27A50020 */   addiu     $a1, $sp, 0x20
    /* B6904 002B5D04 080AD753 */  j          .L002B5D4C
    /* B6908 002B5D08 00000000 */   nop
  .L002B5D0C:
    /* B690C 002B5D0C 27A50010 */  addiu      $a1, $sp, 0x10
    /* B6910 002B5D10 3C067FFF */  lui        $a2, (0x7FFFFFFF >> 16)
    /* B6914 002B5D14 34C6FFFF */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
    /* B6918 002B5D18 24020002 */  addiu      $v0, $zero, 0x2
    /* B691C 002B5D1C AE22002C */  sw         $v0, 0x2C($s1)
    /* B6920 002B5D20 24020010 */  addiu      $v0, $zero, 0x10
    /* B6924 002B5D24 0C0AD469 */  jal        func_002B51A4
    /* B6928 002B5D28 A7A20010 */   sh        $v0, 0x10($sp)
    /* B692C 002B5D2C 080AD753 */  j          .L002B5D4C
    /* B6930 002B5D30 00000000 */   nop
  .L002B5D34:
    /* B6934 002B5D34 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B6938 002B5D38 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B693C 002B5D3C 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B6940 002B5D40 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B6944 002B5D44 0C0AFF50 */  jal        __assert
    /* B6948 002B5D48 2406019C */   addiu     $a2, $zero, 0x19C
  .L002B5D4C:
    /* B694C 002B5D4C 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B6950 002B5D50 8FB20040 */  lw         $s2, 0x40($sp)
    /* B6954 002B5D54 8FB1003C */  lw         $s1, 0x3C($sp)
    /* B6958 002B5D58 8FB00038 */  lw         $s0, 0x38($sp)
    /* B695C 002B5D5C 03E00008 */  jr         $ra
    /* B6960 002B5D60 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel func_002B5B60
