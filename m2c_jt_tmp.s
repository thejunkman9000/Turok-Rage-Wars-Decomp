.include "macro.inc"
.set noat
.set noreorder
.section .text
glabel func_002C2A64
    /* C3664 002C2A64 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C3668 002C2A68 AFB00010 */  sw         $s0, 0x10($sp)
    /* C366C 002C2A6C 00808021 */  addu       $s0, $a0, $zero
    /* C3670 002C2A70 00A04021 */  addu       $t0, $a1, $zero
    /* C3674 002C2A74 30C200FF */  andi       $v0, $a2, 0xFF
    /* C3678 002C2A78 2443FFDB */  addiu      $v1, $v0, -0x25
    /* C367C 002C2A7C 2C620054 */  sltiu      $v0, $v1, 0x54
    /* C3680 002C2A80 AFBF0014 */  sw         $ra, 0x14($sp)
    /* C3684 002C2A84 AE000020 */  sw         $zero, 0x20($s0)
    /* C3688 002C2A88 AE00001C */  sw         $zero, 0x1C($s0)
    /* C368C 002C2A8C AE000018 */  sw         $zero, 0x18($s0)
    /* C3690 002C2A90 AE000014 */  sw         $zero, 0x14($s0)
    /* C3694 002C2A94 AE000010 */  sw         $zero, 0x10($s0)
    /* C3698 002C2A98 10400104 */  beqz       $v0, .L002C2EAC
    /* C369C 002C2A9C AE00000C */   sw        $zero, 0xC($s0)
    /* C36A0 002C2AA0 00031080 */  sll        $v0, $v1, 2
    /* C36A4 002C2AA4 3C01800D */  lui        $at, %hi(jtbl_800CCD68)
    /* C36A8 002C2AA8 00220821 */  addu       $at, $at, $v0
    /* C36AC 002C2AAC 8C22CD68 */  lw         $v0, %lo(jtbl_800CCD68)($at)
    /* C36B0 002C2AB0 00400008 */  jr         $v0
    /* C36B4 002C2AB4 00000000 */   nop
.L002C2AB8:
    /* C36B8 002C2AB8 2402FFFC */  addiu      $v0, $zero, -0x4
    /* C36BC 002C2ABC 8D030000 */  lw         $v1, 0x0($t0)
    /* C36C0 002C2AC0 8E04000C */  lw         $a0, 0xC($s0)
    /* C36C4 002C2AC4 24630003 */  addiu      $v1, $v1, 0x3
    /* C36C8 002C2AC8 00621824 */  and        $v1, $v1, $v0
    /* C36CC 002C2ACC 24620004 */  addiu      $v0, $v1, 0x4
    /* C36D0 002C2AD0 00E42821 */  addu       $a1, $a3, $a0
    /* C36D4 002C2AD4 AD020000 */  sw         $v0, 0x0($t0)
    /* C36D8 002C2AD8 90620003 */  lbu        $v0, 0x3($v1)
    /* C36DC 002C2ADC 24840001 */  addiu      $a0, $a0, 0x1
    /* C36E0 002C2AE0 A0A20000 */  sb         $v0, 0x0($a1)
    /* C36E4 002C2AE4 080B0BB0 */  j          .L002C2EC0
    /* C36E8 002C2AE8 AE04000C */   sw        $a0, 0xC($s0)
.L002C2AEC:
    /* C36EC 002C2AEC 92030034 */  lbu        $v1, 0x34($s0)
    /* C36F0 002C2AF0 2402006C */  addiu      $v0, $zero, 0x6C
    /* C36F4 002C2AF4 1062000C */  beq        $v1, $v0, .L002C2B28
    /* C36F8 002C2AF8 2402004C */   addiu     $v0, $zero, 0x4C
    /* C36FC 002C2AFC 1462000A */  bne        $v1, $v0, .L002C2B28
    /* C3700 002C2B00 2403FFF8 */   addiu     $v1, $zero, -0x8
    /* C3704 002C2B04 8D020000 */  lw         $v0, 0x0($t0)
    /* C3708 002C2B08 24420007 */  addiu      $v0, $v0, 0x7
    /* C370C 002C2B0C 00431024 */  and        $v0, $v0, $v1
    /* C3710 002C2B10 24430008 */  addiu      $v1, $v0, 0x8
    /* C3714 002C2B14 AD030000 */  sw         $v1, 0x0($t0)
    /* C3718 002C2B18 8C430004 */  lw         $v1, 0x4($v0)
    /* C371C 002C2B1C 8C420000 */  lw         $v0, 0x0($v0)
    /* C3720 002C2B20 080B0AD3 */  j          .L002C2B4C
    /* C3724 002C2B24 00000000 */   nop
  .L002C2B28:
    /* C3728 002C2B28 8D020000 */  lw         $v0, 0x0($t0)
    /* C372C 002C2B2C 2403FFFC */  addiu      $v1, $zero, -0x4
    /* C3730 002C2B30 24420003 */  addiu      $v0, $v0, 0x3
    /* C3734 002C2B34 00431024 */  and        $v0, $v0, $v1
    /* C3738 002C2B38 24430004 */  addiu      $v1, $v0, 0x4
    /* C373C 002C2B3C AD030000 */  sw         $v1, 0x0($t0)
    /* C3740 002C2B40 8C440000 */  lw         $a0, 0x0($v0)
    /* C3744 002C2B44 00801821 */  addu       $v1, $a0, $zero
    /* C3748 002C2B48 000417C3 */  sra        $v0, $a0, 31
  .L002C2B4C:
    /* C374C 002C2B4C AE020000 */  sw         $v0, 0x0($s0)
    /* C3750 002C2B50 AE030004 */  sw         $v1, 0x4($s0)
    /* C3754 002C2B54 92030034 */  lbu        $v1, 0x34($s0)
    /* C3758 002C2B58 24020068 */  addiu      $v0, $zero, 0x68
    /* C375C 002C2B5C 14620007 */  bne        $v1, $v0, .L002C2B7C
    /* C3760 002C2B60 00000000 */   nop
    /* C3764 002C2B64 96040006 */  lhu        $a0, 0x6($s0)
    /* C3768 002C2B68 00042400 */  sll        $a0, $a0, 16
    /* C376C 002C2B6C 00041C03 */  sra        $v1, $a0, 16
    /* C3770 002C2B70 000417C3 */  sra        $v0, $a0, 31
    /* C3774 002C2B74 AE020000 */  sw         $v0, 0x0($s0)
    /* C3778 002C2B78 AE030004 */  sw         $v1, 0x4($s0)
  .L002C2B7C:
    /* C377C 002C2B7C 8E020000 */  lw         $v0, 0x0($s0)
    /* C3780 002C2B80 04410004 */  bgez       $v0, .L002C2B94
    /* C3784 002C2B84 2403002D */   addiu     $v1, $zero, 0x2D
    /* C3788 002C2B88 8E02000C */  lw         $v0, 0xC($s0)
    /* C378C 002C2B8C 080B0AF0 */  j          .L002C2BC0
    /* C3790 002C2B90 00E22021 */   addu      $a0, $a3, $v0
  .L002C2B94:
    /* C3794 002C2B94 8E030030 */  lw         $v1, 0x30($s0)
    /* C3798 002C2B98 30620002 */  andi       $v0, $v1, 0x2
    /* C379C 002C2B9C 10400004 */  beqz       $v0, .L002C2BB0
    /* C37A0 002C2BA0 30620001 */   andi      $v0, $v1, 0x1
    /* C37A4 002C2BA4 8E02000C */  lw         $v0, 0xC($s0)
    /* C37A8 002C2BA8 080B0AEF */  j          .L002C2BBC
    /* C37AC 002C2BAC 2403002B */   addiu     $v1, $zero, 0x2B
  .L002C2BB0:
    /* C37B0 002C2BB0 1040003F */  beqz       $v0, .L002C2CB0
    /* C37B4 002C2BB4 24030020 */   addiu     $v1, $zero, 0x20
    /* C37B8 002C2BB8 8E02000C */  lw         $v0, 0xC($s0)
  .L002C2BBC:
    /* C37BC 002C2BBC 00E22021 */  addu       $a0, $a3, $v0
  .L002C2BC0:
    /* C37C0 002C2BC0 24420001 */  addiu      $v0, $v0, 0x1
    /* C37C4 002C2BC4 080B0B2B */  j          .L002C2CAC
    /* C37C8 002C2BC8 A0830000 */   sb        $v1, 0x0($a0)
.L002C2BCC:
    /* C37CC 002C2BCC 92030034 */  lbu        $v1, 0x34($s0)
    /* C37D0 002C2BD0 2402006C */  addiu      $v0, $zero, 0x6C
    /* C37D4 002C2BD4 1062000C */  beq        $v1, $v0, .L002C2C08
    /* C37D8 002C2BD8 2402004C */   addiu     $v0, $zero, 0x4C
    /* C37DC 002C2BDC 1462000A */  bne        $v1, $v0, .L002C2C08
    /* C37E0 002C2BE0 2403FFF8 */   addiu     $v1, $zero, -0x8
    /* C37E4 002C2BE4 8D020000 */  lw         $v0, 0x0($t0)
    /* C37E8 002C2BE8 24420007 */  addiu      $v0, $v0, 0x7
    /* C37EC 002C2BEC 00431024 */  and        $v0, $v0, $v1
    /* C37F0 002C2BF0 24430008 */  addiu      $v1, $v0, 0x8
    /* C37F4 002C2BF4 AD030000 */  sw         $v1, 0x0($t0)
    /* C37F8 002C2BF8 8C430004 */  lw         $v1, 0x4($v0)
    /* C37FC 002C2BFC 8C420000 */  lw         $v0, 0x0($v0)
    /* C3800 002C2C00 080B0B0B */  j          .L002C2C2C
    /* C3804 002C2C04 00000000 */   nop
  .L002C2C08:
    /* C3808 002C2C08 8D020000 */  lw         $v0, 0x0($t0)
    /* C380C 002C2C0C 2403FFFC */  addiu      $v1, $zero, -0x4
    /* C3810 002C2C10 24420003 */  addiu      $v0, $v0, 0x3
    /* C3814 002C2C14 00431024 */  and        $v0, $v0, $v1
    /* C3818 002C2C18 24430004 */  addiu      $v1, $v0, 0x4
    /* C381C 002C2C1C AD030000 */  sw         $v1, 0x0($t0)
    /* C3820 002C2C20 8C440000 */  lw         $a0, 0x0($v0)
    /* C3824 002C2C24 00801821 */  addu       $v1, $a0, $zero
    /* C3828 002C2C28 000417C3 */  sra        $v0, $a0, 31
  .L002C2C2C:
    /* C382C 002C2C2C AE020000 */  sw         $v0, 0x0($s0)
    /* C3830 002C2C30 AE030004 */  sw         $v1, 0x4($s0)
    /* C3834 002C2C34 92030034 */  lbu        $v1, 0x34($s0)
    /* C3838 002C2C38 24020068 */  addiu      $v0, $zero, 0x68
    /* C383C 002C2C3C 14620004 */  bne        $v1, $v0, .L002C2C50
    /* C3840 002C2C40 00001021 */   addu      $v0, $zero, $zero
    /* C3844 002C2C44 96030006 */  lhu        $v1, 0x6($s0)
    /* C3848 002C2C48 080B0B17 */  j          .L002C2C5C
    /* C384C 002C2C4C 00000000 */   nop
  .L002C2C50:
    /* C3850 002C2C50 14600004 */  bnez       $v1, .L002C2C64
    /* C3854 002C2C54 00000000 */   nop
    /* C3858 002C2C58 8E030004 */  lw         $v1, 0x4($s0)
  .L002C2C5C:
    /* C385C 002C2C5C AE020000 */  sw         $v0, 0x0($s0)
    /* C3860 002C2C60 AE030004 */  sw         $v1, 0x4($s0)
  .L002C2C64:
    /* C3864 002C2C64 8E020030 */  lw         $v0, 0x30($s0)
    /* C3868 002C2C68 30420008 */  andi       $v0, $v0, 0x8
    /* C386C 002C2C6C 10400010 */  beqz       $v0, .L002C2CB0
    /* C3870 002C2C70 24030030 */   addiu     $v1, $zero, 0x30
    /* C3874 002C2C74 8E04000C */  lw         $a0, 0xC($s0)
    /* C3878 002C2C78 00E41021 */  addu       $v0, $a3, $a0
    /* C387C 002C2C7C 24840001 */  addiu      $a0, $a0, 0x1
    /* C3880 002C2C80 A0430000 */  sb         $v1, 0x0($v0)
    /* C3884 002C2C84 30C300FF */  andi       $v1, $a2, 0xFF
    /* C3888 002C2C88 24020078 */  addiu      $v0, $zero, 0x78
    /* C388C 002C2C8C 10620004 */  beq        $v1, $v0, .L002C2CA0
    /* C3890 002C2C90 AE04000C */   sw        $a0, 0xC($s0)
    /* C3894 002C2C94 24020058 */  addiu      $v0, $zero, 0x58
    /* C3898 002C2C98 54620006 */  bnel       $v1, $v0, .L002C2CB4
    /* C389C 002C2C9C 02002021 */   addu      $a0, $s0, $zero
  .L002C2CA0:
    /* C38A0 002C2CA0 00E41021 */  addu       $v0, $a3, $a0
    /* C38A4 002C2CA4 A0460000 */  sb         $a2, 0x0($v0)
    /* C38A8 002C2CA8 24820001 */  addiu      $v0, $a0, 0x1
  .L002C2CAC:
    /* C38AC 002C2CAC AE02000C */  sw         $v0, 0xC($s0)
  .L002C2CB0:
    /* C38B0 002C2CB0 02002021 */  addu       $a0, $s0, $zero
  .L002C2CB4:
    /* C38B4 002C2CB4 8C82000C */  lw         $v0, 0xC($a0)
    /* C38B8 002C2CB8 30C500FF */  andi       $a1, $a2, 0xFF
    /* C38BC 002C2CBC 00E21021 */  addu       $v0, $a3, $v0
    /* C38C0 002C2CC0 0C0B0BB4 */  jal        func_002C2ED0
    /* C38C4 002C2CC4 AC820008 */   sw        $v0, 0x8($a0)
    /* C38C8 002C2CC8 080B0BB0 */  j          .L002C2EC0
    /* C38CC 002C2CCC 00000000 */   nop
.L002C2CD0:
    /* C38D0 002C2CD0 8D020000 */  lw         $v0, 0x0($t0)
    /* C38D4 002C2CD4 2403FFF8 */  addiu      $v1, $zero, -0x8
    /* C38D8 002C2CD8 24420007 */  addiu      $v0, $v0, 0x7
    /* C38DC 002C2CDC 00431024 */  and        $v0, $v0, $v1
    /* C38E0 002C2CE0 24430008 */  addiu      $v1, $v0, 0x8
    /* C38E4 002C2CE4 AD030000 */  sw         $v1, 0x0($t0)
    /* C38E8 002C2CE8 D4400000 */  ldc1       $fv0, 0x0($v0)
    /* C38EC 002C2CEC F6000000 */  sdc1       $fv0, 0x0($s0)
    /* C38F0 002C2CF0 96020000 */  lhu        $v0, 0x0($s0)
    /* C38F4 002C2CF4 30428000 */  andi       $v0, $v0, 0x8000
    /* C38F8 002C2CF8 10400004 */  beqz       $v0, .L002C2D0C
    /* C38FC 002C2CFC 2403002D */   addiu     $v1, $zero, 0x2D
    /* C3900 002C2D00 8E02000C */  lw         $v0, 0xC($s0)
    /* C3904 002C2D04 080B0B4E */  j          .L002C2D38
    /* C3908 002C2D08 00E22021 */   addu      $a0, $a3, $v0
  .L002C2D0C:
    /* C390C 002C2D0C 8E030030 */  lw         $v1, 0x30($s0)
    /* C3910 002C2D10 30620002 */  andi       $v0, $v1, 0x2
    /* C3914 002C2D14 10400004 */  beqz       $v0, .L002C2D28
    /* C3918 002C2D18 30620001 */   andi      $v0, $v1, 0x1
    /* C391C 002C2D1C 8E02000C */  lw         $v0, 0xC($s0)
    /* C3920 002C2D20 080B0B4D */  j          .L002C2D34
    /* C3924 002C2D24 2403002B */   addiu     $v1, $zero, 0x2B
  .L002C2D28:
    /* C3928 002C2D28 10400006 */  beqz       $v0, .L002C2D44
    /* C392C 002C2D2C 24030020 */   addiu     $v1, $zero, 0x20
    /* C3930 002C2D30 8E02000C */  lw         $v0, 0xC($s0)
  .L002C2D34:
    /* C3934 002C2D34 00E22021 */  addu       $a0, $a3, $v0
  .L002C2D38:
    /* C3938 002C2D38 24420001 */  addiu      $v0, $v0, 0x1
    /* C393C 002C2D3C A0830000 */  sb         $v1, 0x0($a0)
    /* C3940 002C2D40 AE02000C */  sw         $v0, 0xC($s0)
  .L002C2D44:
    /* C3944 002C2D44 02002021 */  addu       $a0, $s0, $zero
    /* C3948 002C2D48 8C82000C */  lw         $v0, 0xC($a0)
    /* C394C 002C2D4C 30C500FF */  andi       $a1, $a2, 0xFF
    /* C3950 002C2D50 00E21021 */  addu       $v0, $a3, $v0
    /* C3954 002C2D54 0C0B0C6C */  jal        func_002C31B0
    /* C3958 002C2D58 AC820008 */   sw        $v0, 0x8($a0)
    /* C395C 002C2D5C 080B0BB0 */  j          .L002C2EC0
    /* C3960 002C2D60 00000000 */   nop
.L002C2D64:
    /* C3964 002C2D64 92030034 */  lbu        $v1, 0x34($s0)
    /* C3968 002C2D68 24020068 */  addiu      $v0, $zero, 0x68
    /* C396C 002C2D6C 1462000B */  bne        $v1, $v0, .L002C2D9C
    /* C3970 002C2D70 2402006C */   addiu     $v0, $zero, 0x6C
    /* C3974 002C2D74 8D020000 */  lw         $v0, 0x0($t0)
    /* C3978 002C2D78 2403FFFC */  addiu      $v1, $zero, -0x4
    /* C397C 002C2D7C 24420003 */  addiu      $v0, $v0, 0x3
    /* C3980 002C2D80 00431024 */  and        $v0, $v0, $v1
    /* C3984 002C2D84 24430004 */  addiu      $v1, $v0, 0x4
    /* C3988 002C2D88 AD030000 */  sw         $v1, 0x0($t0)
    /* C398C 002C2D8C 8C430000 */  lw         $v1, 0x0($v0)
    /* C3990 002C2D90 9602002E */  lhu        $v0, 0x2E($s0)
    /* C3994 002C2D94 080B0BB0 */  j          .L002C2EC0
    /* C3998 002C2D98 A4620000 */   sh        $v0, 0x0($v1)
  .L002C2D9C:
    /* C399C 002C2D9C 1062000F */  beq        $v1, $v0, .L002C2DDC
    /* C39A0 002C2DA0 2402004C */   addiu     $v0, $zero, 0x4C
    /* C39A4 002C2DA4 1462000D */  bne        $v1, $v0, .L002C2DDC
    /* C39A8 002C2DA8 2404FFFC */   addiu     $a0, $zero, -0x4
    /* C39AC 002C2DAC 8D050000 */  lw         $a1, 0x0($t0)
    /* C39B0 002C2DB0 24A50003 */  addiu      $a1, $a1, 0x3
    /* C39B4 002C2DB4 00A42824 */  and        $a1, $a1, $a0
    /* C39B8 002C2DB8 24A40004 */  addiu      $a0, $a1, 0x4
    /* C39BC 002C2DBC AD040000 */  sw         $a0, 0x0($t0)
    /* C39C0 002C2DC0 8E03002C */  lw         $v1, 0x2C($s0)
    /* C39C4 002C2DC4 8CA40000 */  lw         $a0, 0x0($a1)
    /* C39C8 002C2DC8 00001021 */  addu       $v0, $zero, $zero
    /* C39CC 002C2DCC AC820000 */  sw         $v0, 0x0($a0)
    /* C39D0 002C2DD0 AC830004 */  sw         $v1, 0x4($a0)
    /* C39D4 002C2DD4 080B0BB0 */  j          .L002C2EC0
    /* C39D8 002C2DD8 00000000 */   nop
  .L002C2DDC:
    /* C39DC 002C2DDC 8D020000 */  lw         $v0, 0x0($t0)
    /* C39E0 002C2DE0 2403FFFC */  addiu      $v1, $zero, -0x4
    /* C39E4 002C2DE4 24420003 */  addiu      $v0, $v0, 0x3
    /* C39E8 002C2DE8 00431024 */  and        $v0, $v0, $v1
    /* C39EC 002C2DEC 24430004 */  addiu      $v1, $v0, 0x4
    /* C39F0 002C2DF0 AD030000 */  sw         $v1, 0x0($t0)
    /* C39F4 002C2DF4 8C430000 */  lw         $v1, 0x0($v0)
    /* C39F8 002C2DF8 8E02002C */  lw         $v0, 0x2C($s0)
    /* C39FC 002C2DFC 080B0BB0 */  j          .L002C2EC0
    /* C3A00 002C2E00 AC620000 */   sw        $v0, 0x0($v1)
.L002C2E04:
    /* C3A04 002C2E04 8D050000 */  lw         $a1, 0x0($t0)
    /* C3A08 002C2E08 2406FFFC */  addiu      $a2, $zero, -0x4
    /* C3A0C 002C2E0C 24A50003 */  addiu      $a1, $a1, 0x3
    /* C3A10 002C2E10 00A62824 */  and        $a1, $a1, $a2
    /* C3A14 002C2E14 24A60004 */  addiu      $a2, $a1, 0x4
    /* C3A18 002C2E18 AD060000 */  sw         $a2, 0x0($t0)
    /* C3A1C 002C2E1C 8CA60000 */  lw         $a2, 0x0($a1)
    /* C3A20 002C2E20 02002021 */  addu       $a0, $s0, $zero
    /* C3A24 002C2E24 00C01821 */  addu       $v1, $a2, $zero
    /* C3A28 002C2E28 000617C3 */  sra        $v0, $a2, 31
    /* C3A2C 002C2E2C 8C86000C */  lw         $a2, 0xC($a0)
    /* C3A30 002C2E30 24050078 */  addiu      $a1, $zero, 0x78
    /* C3A34 002C2E34 AC820000 */  sw         $v0, 0x0($a0)
    /* C3A38 002C2E38 AC830004 */  sw         $v1, 0x4($a0)
    /* C3A3C 002C2E3C 00E63021 */  addu       $a2, $a3, $a2
    /* C3A40 002C2E40 0C0B0BB4 */  jal        func_002C2ED0
    /* C3A44 002C2E44 AC860008 */   sw        $a2, 0x8($a0)
    /* C3A48 002C2E48 080B0BB0 */  j          .L002C2EC0
    /* C3A4C 002C2E4C 00000000 */   nop
.L002C2E50:
    /* C3A50 002C2E50 8D020000 */  lw         $v0, 0x0($t0)
    /* C3A54 002C2E54 2403FFFC */  addiu      $v1, $zero, -0x4
    /* C3A58 002C2E58 24420003 */  addiu      $v0, $v0, 0x3
    /* C3A5C 002C2E5C 00431024 */  and        $v0, $v0, $v1
    /* C3A60 002C2E60 24430004 */  addiu      $v1, $v0, 0x4
    /* C3A64 002C2E64 AD030000 */  sw         $v1, 0x0($t0)
    /* C3A68 002C2E68 8C440000 */  lw         $a0, 0x0($v0)
    /* C3A6C 002C2E6C 0C0B093C */  jal        strlen
    /* C3A70 002C2E70 AE040008 */   sw        $a0, 0x8($s0)
    /* C3A74 002C2E74 8E030024 */  lw         $v1, 0x24($s0)
    /* C3A78 002C2E78 04600011 */  bltz       $v1, .L002C2EC0
    /* C3A7C 002C2E7C AE020014 */   sw        $v0, 0x14($s0)
    /* C3A80 002C2E80 0062102A */  slt        $v0, $v1, $v0
    /* C3A84 002C2E84 5440000E */  bnel       $v0, $zero, .L002C2EC0
    /* C3A88 002C2E88 AE030014 */   sw        $v1, 0x14($s0)
    /* C3A8C 002C2E8C 080B0BB0 */  j          .L002C2EC0
    /* C3A90 002C2E90 00000000 */   nop
.L002C2E94:
    /* C3A94 002C2E94 8E02000C */  lw         $v0, 0xC($s0)
    /* C3A98 002C2E98 24030025 */  addiu      $v1, $zero, 0x25
    /* C3A9C 002C2E9C 00E22021 */  addu       $a0, $a3, $v0
    /* C3AA0 002C2EA0 24420001 */  addiu      $v0, $v0, 0x1
    /* C3AA4 002C2EA4 080B0BAF */  j          .L002C2EBC
    /* C3AA8 002C2EA8 A0830000 */   sb        $v1, 0x0($a0)
  .L002C2EAC:
.L002C2EAC:
    /* C3AAC 002C2EAC 8E02000C */  lw         $v0, 0xC($s0)
    /* C3AB0 002C2EB0 00E21821 */  addu       $v1, $a3, $v0
    /* C3AB4 002C2EB4 24420001 */  addiu      $v0, $v0, 0x1
    /* C3AB8 002C2EB8 A0660000 */  sb         $a2, 0x0($v1)
  .L002C2EBC:
    /* C3ABC 002C2EBC AE02000C */  sw         $v0, 0xC($s0)
  .L002C2EC0:
    /* C3AC0 002C2EC0 8FBF0014 */  lw         $ra, 0x14($sp)
    /* C3AC4 002C2EC4 8FB00010 */  lw         $s0, 0x10($sp)
    /* C3AC8 002C2EC8 03E00008 */  jr         $ra
    /* C3ACC 002C2ECC 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002C2A64

.section .rodata
glabel jtbl_800CCD68
    .word .L002C2E94
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2CD0
    .word .L002C2EAC
    .word .L002C2CD0
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2BCC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2AB8
    .word .L002C2AEC
    .word .L002C2CD0
    .word .L002C2CD0
    .word .L002C2CD0
    .word .L002C2EAC
    .word .L002C2AEC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2D64
    .word .L002C2BCC
    .word .L002C2E04
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2E50
    .word .L002C2EAC
    .word .L002C2BCC
    .word .L002C2EAC
    .word .L002C2EAC
    .word .L002C2BCC
