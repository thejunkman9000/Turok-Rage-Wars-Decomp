.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB36BC-0xB3D00 (VRAM 0x002B2ABC) */
glabel rncUnpackMethod2Body
    /* B36BC 002B2ABC 00A08821 */  addu       $s1, $a1, $zero
    /* B36C0 002B2AC0 240D0000 */  addiu      $t5, $zero, 0x0
    /* B36C4 002B2AC4 3C0B8015 */  lui        $t3, %hi(D_8014D420)
    /* B36C8 002B2AC8 256BD420 */  addiu      $t3, $t3, %lo(D_8014D420)
    /* B36CC 002B2ACC 25CE0004 */  addiu      $t6, $t6, 0x4
    /* B36D0 002B2AD0 91CD0000 */  lbu        $t5, 0x0($t6)
    /* B36D4 002B2AD4 91CC0001 */  lbu        $t4, 0x1($t6)
    /* B36D8 002B2AD8 91D20002 */  lbu        $s2, 0x2($t6)
    /* B36DC 002B2ADC 91CF0003 */  lbu        $t7, 0x3($t6)
    /* B36E0 002B2AE0 000D6E00 */  sll        $t5, $t5, 24
    /* B36E4 002B2AE4 000C6400 */  sll        $t4, $t4, 16
    /* B36E8 002B2AE8 00129200 */  sll        $s2, $s2, 8
    /* B36EC 002B2AEC 01AC6825 */  or         $t5, $t5, $t4
    /* B36F0 002B2AF0 01B26825 */  or         $t5, $t5, $s2
    /* B36F4 002B2AF4 01AF6825 */  or         $t5, $t5, $t7
    /* B36F8 002B2AF8 25CE0004 */  addiu      $t6, $t6, 0x4
    /* B36FC 002B2AFC AD6D0000 */  sw         $t5, 0x0($t3)
    /* B3700 002B2B00 01C01821 */  addu       $v1, $t6, $zero
    /* B3704 002B2B04 2063000A */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* B3708 002B2B08 02202821 */  addu       $a1, $s1, $zero
    /* B370C 002B2B0C 00A03021 */  addu       $a2, $a1, $zero
    /* B3710 002B2B10 00CD3021 */  addu       $a2, $a2, $t5
    /* B3714 002B2B14 91CD0000 */  lbu        $t5, 0x0($t6)
    /* B3718 002B2B18 91CC0001 */  lbu        $t4, 0x1($t6)
    /* B371C 002B2B1C 91D20002 */  lbu        $s2, 0x2($t6)
    /* B3720 002B2B20 91CF0003 */  lbu        $t7, 0x3($t6)
    /* B3724 002B2B24 000D6E00 */  sll        $t5, $t5, 24
    /* B3728 002B2B28 000C6400 */  sll        $t4, $t4, 16
    /* B372C 002B2B2C 00129200 */  sll        $s2, $s2, 8
    /* B3730 002B2B30 01AC6825 */  or         $t5, $t5, $t4
    /* B3734 002B2B34 01B26825 */  or         $t5, $t5, $s2
    /* B3738 002B2B38 01AF6825 */  or         $t5, $t5, $t7
    /* B373C 002B2B3C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* B3740 002B2B40 00602021 */  addu       $a0, $v1, $zero
    /* B3744 002B2B44 008D2020 */  add        $a0, $a0, $t5 /* handwritten instruction */
    /* B3748 002B2B48 216BFFFE */  addi       $t3, $t3, -0x2 /* handwritten instruction */
    /* B374C 002B2B4C A5600000 */  sh         $zero, 0x0($t3)
    /* B3750 002B2B50 3C0AFFFF */  lui        $t2, (0xFFFFFF00 >> 16)
    /* B3754 002B2B54 354AFF00 */  ori        $t2, $t2, (0xFFFFFF00 & 0xFFFF)
    /* B3758 002B2B58 240F0001 */  addiu      $t7, $zero, 0x1
    /* B375C 002B2B5C 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3760 002B2B60 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3764 002B2B64 014A5021 */  addu       $t2, $t2, $t2
    /* B3768 002B2B68 014F5021 */  addu       $t2, $t2, $t7
    /* B376C 002B2B6C 014A5021 */  addu       $t2, $t2, $t2
    /* B3770 002B2B70 000A7A02 */  srl        $t7, $t2, 8
    /* B3774 002B2B74 080ACBB4 */  j          .L002B2ED0
    /* B3778 002B2B78 31EF0001 */   andi      $t7, $t7, 0x1
    /* B377C 002B2B7C 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B3780 002B2B80 03E00008 */  jr         $ra
    /* B3784 002B2B84 00000000 */   nop
    /* B3788 002B2B88 2402FFFE */  addiu      $v0, $zero, -0x2
    /* B378C 002B2B8C 03E00008 */  jr         $ra
    /* B3790 002B2B90 00000000 */   nop
  .L002B2B94:
    /* B3794 002B2B94 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3798 002B2B98 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B379C 002B2B9C 014A5021 */  addu       $t2, $t2, $t2
    /* B37A0 002B2BA0 014F5021 */  addu       $t2, $t2, $t7
    /* B37A4 002B2BA4 000A7A02 */  srl        $t7, $t2, 8
    /* B37A8 002B2BA8 080ACB24 */  j          .L002B2C90
    /* B37AC 002B2BAC 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2BB0:
    /* B37B0 002B2BB0 906A0000 */  lbu        $t2, 0x0($v1)
    /* B37B4 002B2BB4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B37B8 002B2BB8 014A5021 */  addu       $t2, $t2, $t2
    /* B37BC 002B2BBC 014F5021 */  addu       $t2, $t2, $t7
    /* B37C0 002B2BC0 000A7A02 */  srl        $t7, $t2, 8
    /* B37C4 002B2BC4 080ACB40 */  j          .L002B2D00
    /* B37C8 002B2BC8 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2BCC:
    /* B37CC 002B2BCC 906A0000 */  lbu        $t2, 0x0($v1)
    /* B37D0 002B2BD0 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B37D4 002B2BD4 014A5021 */  addu       $t2, $t2, $t2
    /* B37D8 002B2BD8 014F5021 */  addu       $t2, $t2, $t7
    /* B37DC 002B2BDC 000A7A02 */  srl        $t7, $t2, 8
    /* B37E0 002B2BE0 080ACB48 */  j          .L002B2D20
    /* B37E4 002B2BE4 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2BE8:
    /* B37E8 002B2BE8 906A0000 */  lbu        $t2, 0x0($v1)
    /* B37EC 002B2BEC 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B37F0 002B2BF0 014A5021 */  addu       $t2, $t2, $t2
    /* B37F4 002B2BF4 014F5021 */  addu       $t2, $t2, $t7
    /* B37F8 002B2BF8 000A7A02 */  srl        $t7, $t2, 8
    /* B37FC 002B2BFC 080ACB51 */  j          .L002B2D44
    /* B3800 002B2C00 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2C04:
    /* B3804 002B2C04 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3808 002B2C08 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B380C 002B2C0C 014A5021 */  addu       $t2, $t2, $t2
    /* B3810 002B2C10 014F5021 */  addu       $t2, $t2, $t7
    /* B3814 002B2C14 000A7A02 */  srl        $t7, $t2, 8
    /* B3818 002B2C18 080ACB5E */  j          .L002B2D78
    /* B381C 002B2C1C 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2C20:
    /* B3820 002B2C20 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3824 002B2C24 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3828 002B2C28 014A5021 */  addu       $t2, $t2, $t2
    /* B382C 002B2C2C 014F5021 */  addu       $t2, $t2, $t7
    /* B3830 002B2C30 000A7A02 */  srl        $t7, $t2, 8
    /* B3834 002B2C34 080ACB66 */  j          .L002B2D98
    /* B3838 002B2C38 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2C3C:
    /* B383C 002B2C3C 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3840 002B2C40 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3844 002B2C44 014A5021 */  addu       $t2, $t2, $t2
    /* B3848 002B2C48 014F5021 */  addu       $t2, $t2, $t7
    /* B384C 002B2C4C 000A7A02 */  srl        $t7, $t2, 8
    /* B3850 002B2C50 080ACB6E */  j          .L002B2DB8
    /* B3854 002B2C54 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2C58:
    /* B3858 002B2C58 906A0000 */  lbu        $t2, 0x0($v1)
    /* B385C 002B2C5C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3860 002B2C60 014A5021 */  addu       $t2, $t2, $t2
    /* B3864 002B2C64 014F5021 */  addu       $t2, $t2, $t7
    /* B3868 002B2C68 000A7A02 */  srl        $t7, $t2, 8
    /* B386C 002B2C6C 080ACB79 */  j          .L002B2DE4
    /* B3870 002B2C70 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B2C74:
    /* B3874 002B2C74 24080003 */  addiu      $t0, $zero, 0x3
  .L002B2C78:
    /* B3878 002B2C78 014A5021 */  addu       $t2, $t2, $t2
    /* B387C 002B2C7C 000A7A02 */  srl        $t7, $t2, 8
    /* B3880 002B2C80 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3884 002B2C84 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3888 002B2C88 100AFFC2 */  beq        $zero, $t2, .L002B2B94
    /* B388C 002B2C8C 00000000 */   nop
  .L002B2C90:
    /* B3890 002B2C90 01294821 */  addu       $t1, $t1, $t1
    /* B3894 002B2C94 012F4821 */  addu       $t1, $t1, $t7
    /* B3898 002B2C98 00097C02 */  srl        $t7, $t1, 16
    /* B389C 002B2C9C 31EF0001 */  andi       $t7, $t7, 0x1
    /* B38A0 002B2CA0 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B38A4 002B2CA4 0501FFF4 */  bgez       $t0, .L002B2C78
    /* B38A8 002B2CA8 00000000 */   nop
    /* B38AC 002B2CAC 21290002 */  addi       $t1, $t1, 0x2 /* handwritten instruction */
  .L002B2CB0:
    /* B38B0 002B2CB0 906C0000 */  lbu        $t4, 0x0($v1)
    /* B38B4 002B2CB4 90720001 */  lbu        $s2, 0x1($v1)
    /* B38B8 002B2CB8 A0AC0000 */  sb         $t4, 0x0($a1)
    /* B38BC 002B2CBC A0B20001 */  sb         $s2, 0x1($a1)
    /* B38C0 002B2CC0 906C0002 */  lbu        $t4, 0x2($v1)
    /* B38C4 002B2CC4 90720003 */  lbu        $s2, 0x3($v1)
    /* B38C8 002B2CC8 A0AC0002 */  sb         $t4, 0x2($a1)
    /* B38CC 002B2CCC A0B20003 */  sb         $s2, 0x3($a1)
    /* B38D0 002B2CD0 24630004 */  addiu      $v1, $v1, 0x4
    /* B38D4 002B2CD4 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* B38D8 002B2CD8 0521FFF5 */  bgez       $t1, .L002B2CB0
    /* B38DC 002B2CDC 20A50004 */   addi      $a1, $a1, 0x4 /* handwritten instruction */
    /* B38E0 002B2CE0 080ACBB4 */  j          .L002B2ED0
    /* B38E4 002B2CE4 00000000 */   nop
  .L002B2CE8:
    /* B38E8 002B2CE8 014A5021 */  addu       $t2, $t2, $t2
    /* B38EC 002B2CEC 000A7A02 */  srl        $t7, $t2, 8
    /* B38F0 002B2CF0 31EF0001 */  andi       $t7, $t7, 0x1
    /* B38F4 002B2CF4 314A00FF */  andi       $t2, $t2, 0xFF
    /* B38F8 002B2CF8 100AFFAD */  beq        $zero, $t2, .L002B2BB0
    /* B38FC 002B2CFC 00000000 */   nop
  .L002B2D00:
    /* B3900 002B2D00 01084021 */  addu       $t0, $t0, $t0
    /* B3904 002B2D04 010F4021 */  addu       $t0, $t0, $t7
    /* B3908 002B2D08 014A5021 */  addu       $t2, $t2, $t2
    /* B390C 002B2D0C 000A7A02 */  srl        $t7, $t2, 8
    /* B3910 002B2D10 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3914 002B2D14 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3918 002B2D18 100AFFAC */  beq        $zero, $t2, .L002B2BCC
    /* B391C 002B2D1C 00000000 */   nop
  .L002B2D20:
    /* B3920 002B2D20 100F000F */  beq        $zero, $t7, .L002B2D60
    /* B3924 002B2D24 00000000 */   nop
    /* B3928 002B2D28 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B392C 002B2D2C 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* B3930 002B2D30 000A7A02 */  srl        $t7, $t2, 8
    /* B3934 002B2D34 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3938 002B2D38 314A00FF */  andi       $t2, $t2, 0xFF
    /* B393C 002B2D3C 100AFFAA */  beq        $zero, $t2, .L002B2BE8
    /* B3940 002B2D40 00000000 */   nop
  .L002B2D44:
    /* B3944 002B2D44 01084021 */  addu       $t0, $t0, $t0
    /* B3948 002B2D48 010F4021 */  addu       $t0, $t0, $t7
    /* B394C 002B2D4C 00087C02 */  srl        $t7, $t0, 16
    /* B3950 002B2D50 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3954 002B2D54 210CFFF7 */  addi       $t4, $t0, -0x9 /* handwritten instruction */
    /* B3958 002B2D58 100CFFC6 */  beq        $zero, $t4, .L002B2C74
    /* B395C 002B2D5C 00000000 */   nop
  .L002B2D60:
    /* B3960 002B2D60 014A5021 */  addu       $t2, $t2, $t2
    /* B3964 002B2D64 000A7A02 */  srl        $t7, $t2, 8
    /* B3968 002B2D68 31EF0001 */  andi       $t7, $t7, 0x1
    /* B396C 002B2D6C 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3970 002B2D70 100AFFA4 */  beq        $zero, $t2, .L002B2C04
    /* B3974 002B2D74 00000000 */   nop
  .L002B2D78:
    /* B3978 002B2D78 100F0022 */  beq        $zero, $t7, .L002B2E04
    /* B397C 002B2D7C 00000000 */   nop
    /* B3980 002B2D80 014A5021 */  addu       $t2, $t2, $t2
    /* B3984 002B2D84 000A7A02 */  srl        $t7, $t2, 8
    /* B3988 002B2D88 31EF0001 */  andi       $t7, $t7, 0x1
    /* B398C 002B2D8C 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3990 002B2D90 100AFFA3 */  beq        $zero, $t2, .L002B2C20
    /* B3994 002B2D94 00000000 */   nop
  .L002B2D98:
    /* B3998 002B2D98 01294821 */  addu       $t1, $t1, $t1
    /* B399C 002B2D9C 012F4821 */  addu       $t1, $t1, $t7
    /* B39A0 002B2DA0 014A5021 */  addu       $t2, $t2, $t2
    /* B39A4 002B2DA4 000A7A02 */  srl        $t7, $t2, 8
    /* B39A8 002B2DA8 31EF0001 */  andi       $t7, $t7, 0x1
    /* B39AC 002B2DAC 314A00FF */  andi       $t2, $t2, 0xFF
    /* B39B0 002B2DB0 100AFFA2 */  beq        $zero, $t2, .L002B2C3C
    /* B39B4 002B2DB4 00000000 */   nop
  .L002B2DB8:
    /* B39B8 002B2DB8 140F0078 */  bne        $zero, $t7, .L002B2F9C
    /* B39BC 002B2DBC 00000000 */   nop
    /* B39C0 002B2DC0 1409000C */  bne        $zero, $t1, .L002B2DF4
    /* B39C4 002B2DC4 00000000 */   nop
    /* B39C8 002B2DC8 21290001 */  addi       $t1, $t1, 0x1 /* handwritten instruction */
  .L002B2DCC:
    /* B39CC 002B2DCC 014A5021 */  addu       $t2, $t2, $t2
    /* B39D0 002B2DD0 000A7A02 */  srl        $t7, $t2, 8
    /* B39D4 002B2DD4 31EF0001 */  andi       $t7, $t7, 0x1
    /* B39D8 002B2DD8 314A00FF */  andi       $t2, $t2, 0xFF
    /* B39DC 002B2DDC 100AFF9E */  beq        $zero, $t2, .L002B2C58
    /* B39E0 002B2DE0 00000000 */   nop
  .L002B2DE4:
    /* B39E4 002B2DE4 01294821 */  addu       $t1, $t1, $t1
    /* B39E8 002B2DE8 012F4821 */  addu       $t1, $t1, $t7
    /* B39EC 002B2DEC 00097C02 */  srl        $t7, $t1, 16
    /* B39F0 002B2DF0 31EF0001 */  andi       $t7, $t7, 0x1
  .L002B2DF4:
    /* B39F4 002B2DF4 00096200 */  sll        $t4, $t1, 8
    /* B39F8 002B2DF8 318CFF00 */  andi       $t4, $t4, 0xFF00
    /* B39FC 002B2DFC 00094A02 */  srl        $t1, $t1, 8
    /* B3A00 002B2E00 012C4825 */  or         $t1, $t1, $t4
  .L002B2E04:
    /* B3A04 002B2E04 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* B3A08 002B2E08 90690000 */  lbu        $t1, 0x0($v1)
    /* B3A0C 002B2E0C 24630001 */  addiu      $v1, $v1, 0x1
    /* B3A10 002B2E10 01334825 */  or         $t1, $t1, $s3
    /* B3A14 002B2E14 00A07021 */  addu       $t6, $a1, $zero
    /* B3A18 002B2E18 01C97022 */  sub        $t6, $t6, $t1 /* handwritten instruction */
    /* B3A1C 002B2E1C 21CEFFFF */  addi       $t6, $t6, -0x1 /* handwritten instruction */
    /* B3A20 002B2E20 310F0001 */  andi       $t7, $t0, 0x1
    /* B3A24 002B2E24 00084042 */  srl        $t0, $t0, 1
    /* B3A28 002B2E28 100F0005 */  beq        $zero, $t7, .L002B2E40
    /* B3A2C 002B2E2C 00000000 */   nop
    /* B3A30 002B2E30 91CC0000 */  lbu        $t4, 0x0($t6)
    /* B3A34 002B2E34 21CE0001 */  addi       $t6, $t6, 0x1 /* handwritten instruction */
    /* B3A38 002B2E38 A0AC0000 */  sb         $t4, 0x0($a1)
    /* B3A3C 002B2E3C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
  .L002B2E40:
    /* B3A40 002B2E40 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B3A44 002B2E44 1409000C */  bne        $zero, $t1, .L002B2E78
    /* B3A48 002B2E48 00000000 */   nop
    /* B3A4C 002B2E4C 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* B3A50 002B2E50 91C90000 */  lbu        $t1, 0x0($t6)
    /* B3A54 002B2E54 00000000 */  nop
    /* B3A58 002B2E58 01334825 */  or         $t1, $t1, $s3
  .L002B2E5C:
    /* B3A5C 002B2E5C A0A90000 */  sb         $t1, 0x0($a1)
    /* B3A60 002B2E60 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B3A64 002B2E64 A0A90001 */  sb         $t1, 0x1($a1)
    /* B3A68 002B2E68 0501FFFC */  bgez       $t0, .L002B2E5C
    /* B3A6C 002B2E6C 20A50002 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* B3A70 002B2E70 080ACBB4 */  j          .L002B2ED0
    /* B3A74 002B2E74 00000000 */   nop
  .L002B2E78:
    /* B3A78 002B2E78 91D20001 */  lbu        $s2, 0x1($t6)
    /* B3A7C 002B2E7C 91CC0000 */  lbu        $t4, 0x0($t6)
    /* B3A80 002B2E80 A0B20001 */  sb         $s2, 0x1($a1)
    /* B3A84 002B2E84 A0AC0000 */  sb         $t4, 0x0($a1)
    /* B3A88 002B2E88 21CE0002 */  addi       $t6, $t6, 0x2 /* handwritten instruction */
    /* B3A8C 002B2E8C 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B3A90 002B2E90 0501FFF9 */  bgez       $t0, .L002B2E78
    /* B3A94 002B2E94 20A50002 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* B3A98 002B2E98 080ACBB4 */  j          .L002B2ED0
    /* B3A9C 002B2E9C 00000000 */   nop
  .L002B2EA0:
    /* B3AA0 002B2EA0 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3AA4 002B2EA4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3AA8 002B2EA8 014A5021 */  addu       $t2, $t2, $t2
    /* B3AAC 002B2EAC 014F5021 */  addu       $t2, $t2, $t7
    /* B3AB0 002B2EB0 000A7A02 */  srl        $t7, $t2, 8
    /* B3AB4 002B2EB4 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3AB8 002B2EB8 140F0016 */  bne        $zero, $t7, .L002B2F14
    /* B3ABC 002B2EBC 00000000 */   nop
  .L002B2EC0:
    /* B3AC0 002B2EC0 906C0000 */  lbu        $t4, 0x0($v1)
    /* B3AC4 002B2EC4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3AC8 002B2EC8 A0AC0000 */  sb         $t4, 0x0($a1)
    /* B3ACC 002B2ECC 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
  .L002B2ED0:
    /* B3AD0 002B2ED0 014A5021 */  addu       $t2, $t2, $t2
    /* B3AD4 002B2ED4 000A7A02 */  srl        $t7, $t2, 8
    /* B3AD8 002B2ED8 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3ADC 002B2EDC 140F000A */  bne        $zero, $t7, .L002B2F08
    /* B3AE0 002B2EE0 00000000 */   nop
    /* B3AE4 002B2EE4 906C0000 */  lbu        $t4, 0x0($v1)
    /* B3AE8 002B2EE8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3AEC 002B2EEC A0AC0000 */  sb         $t4, 0x0($a1)
    /* B3AF0 002B2EF0 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* B3AF4 002B2EF4 014A5021 */  addu       $t2, $t2, $t2
    /* B3AF8 002B2EF8 000A7A02 */  srl        $t7, $t2, 8
    /* B3AFC 002B2EFC 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3B00 002B2F00 100FFFEF */  beq        $zero, $t7, .L002B2EC0
    /* B3B04 002B2F04 00000000 */   nop
  .L002B2F08:
    /* B3B08 002B2F08 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3B0C 002B2F0C 100AFFE4 */  beq        $zero, $t2, .L002B2EA0
    /* B3B10 002B2F10 00000000 */   nop
  .L002B2F14:
    /* B3B14 002B2F14 24080002 */  addiu      $t0, $zero, 0x2
    /* B3B18 002B2F18 24090000 */  addiu      $t1, $zero, 0x0
    /* B3B1C 002B2F1C 014A5021 */  addu       $t2, $t2, $t2
    /* B3B20 002B2F20 000A7A02 */  srl        $t7, $t2, 8
    /* B3B24 002B2F24 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3B28 002B2F28 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3B2C 002B2F2C 100A0030 */  beq        $zero, $t2, .L002B2FF0
    /* B3B30 002B2F30 00000000 */   nop
  .L002B2F34:
    /* B3B34 002B2F34 100FFF6C */  beq        $zero, $t7, .L002B2CE8
    /* B3B38 002B2F38 00000000 */   nop
    /* B3B3C 002B2F3C 014A5021 */  addu       $t2, $t2, $t2
    /* B3B40 002B2F40 000A7A02 */  srl        $t7, $t2, 8
    /* B3B44 002B2F44 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3B48 002B2F48 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3B4C 002B2F4C 100A002F */  beq        $zero, $t2, .L002B300C
    /* B3B50 002B2F50 00000000 */   nop
  .L002B2F54:
    /* B3B54 002B2F54 100FFFAB */  beq        $zero, $t7, .L002B2E04
    /* B3B58 002B2F58 00000000 */   nop
    /* B3B5C 002B2F5C 21080001 */  addi       $t0, $t0, 0x1 /* handwritten instruction */
    /* B3B60 002B2F60 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* B3B64 002B2F64 000A7A02 */  srl        $t7, $t2, 8
    /* B3B68 002B2F68 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3B6C 002B2F6C 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3B70 002B2F70 100A002D */  beq        $zero, $t2, .L002B3028
    /* B3B74 002B2F74 00000000 */   nop
  .L002B2F78:
    /* B3B78 002B2F78 100FFF79 */  beq        $zero, $t7, .L002B2D60
    /* B3B7C 002B2F7C 00000000 */   nop
    /* B3B80 002B2F80 90680000 */  lbu        $t0, 0x0($v1)
    /* B3B84 002B2F84 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3B88 002B2F88 00000000 */  nop
    /* B3B8C 002B2F8C 1008003B */  beq        $zero, $t0, .L002B307C
    /* B3B90 002B2F90 21080008 */   addi      $t0, $t0, 0x8 /* handwritten instruction */
    /* B3B94 002B2F94 080ACB58 */  j          .L002B2D60
    /* B3B98 002B2F98 00000000 */   nop
  .L002B2F9C:
    /* B3B9C 002B2F9C 014A5021 */  addu       $t2, $t2, $t2
    /* B3BA0 002B2FA0 000A7A02 */  srl        $t7, $t2, 8
    /* B3BA4 002B2FA4 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3BA8 002B2FA8 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3BAC 002B2FAC 100A0025 */  beq        $zero, $t2, .L002B3044
    /* B3BB0 002B2FB0 00000000 */   nop
  .L002B2FB4:
    /* B3BB4 002B2FB4 01294821 */  addu       $t1, $t1, $t1
    /* B3BB8 002B2FB8 012F4821 */  addu       $t1, $t1, $t7
    /* B3BBC 002B2FBC 00097C02 */  srl        $t7, $t1, 16
    /* B3BC0 002B2FC0 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3BC4 002B2FC4 35290004 */  ori        $t1, $t1, 0x4
    /* B3BC8 002B2FC8 014A5021 */  addu       $t2, $t2, $t2
    /* B3BCC 002B2FCC 000A7A02 */  srl        $t7, $t2, 8
    /* B3BD0 002B2FD0 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3BD4 002B2FD4 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3BD8 002B2FD8 100A0021 */  beq        $zero, $t2, .L002B3060
    /* B3BDC 002B2FDC 00000000 */   nop
  .L002B2FE0:
    /* B3BE0 002B2FE0 140FFF84 */  bne        $zero, $t7, .L002B2DF4
    /* B3BE4 002B2FE4 00000000 */   nop
    /* B3BE8 002B2FE8 080ACB73 */  j          .L002B2DCC
    /* B3BEC 002B2FEC 00000000 */   nop
  .L002B2FF0:
    /* B3BF0 002B2FF0 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3BF4 002B2FF4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3BF8 002B2FF8 014A5021 */  addu       $t2, $t2, $t2
    /* B3BFC 002B2FFC 014F5021 */  addu       $t2, $t2, $t7
    /* B3C00 002B3000 000A7A02 */  srl        $t7, $t2, 8
    /* B3C04 002B3004 080ACBCD */  j          .L002B2F34
    /* B3C08 002B3008 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B300C:
    /* B3C0C 002B300C 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3C10 002B3010 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3C14 002B3014 014A5021 */  addu       $t2, $t2, $t2
    /* B3C18 002B3018 014F5021 */  addu       $t2, $t2, $t7
    /* B3C1C 002B301C 000A7A02 */  srl        $t7, $t2, 8
    /* B3C20 002B3020 080ACBD5 */  j          .L002B2F54
    /* B3C24 002B3024 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B3028:
    /* B3C28 002B3028 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3C2C 002B302C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3C30 002B3030 014A5021 */  addu       $t2, $t2, $t2
    /* B3C34 002B3034 014F5021 */  addu       $t2, $t2, $t7
    /* B3C38 002B3038 000A7A02 */  srl        $t7, $t2, 8
    /* B3C3C 002B303C 080ACBDE */  j          .L002B2F78
    /* B3C40 002B3040 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B3044:
    /* B3C44 002B3044 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3C48 002B3048 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3C4C 002B304C 014A5021 */  addu       $t2, $t2, $t2
    /* B3C50 002B3050 014F5021 */  addu       $t2, $t2, $t7
    /* B3C54 002B3054 000A7A02 */  srl        $t7, $t2, 8
    /* B3C58 002B3058 080ACBED */  j          .L002B2FB4
    /* B3C5C 002B305C 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B3060:
    /* B3C60 002B3060 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3C64 002B3064 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3C68 002B3068 014A5021 */  addu       $t2, $t2, $t2
    /* B3C6C 002B306C 014F5021 */  addu       $t2, $t2, $t7
    /* B3C70 002B3070 000A7A02 */  srl        $t7, $t2, 8
    /* B3C74 002B3074 080ACBF8 */  j          .L002B2FE0
    /* B3C78 002B3078 31EF0001 */   andi      $t7, $t7, 0x1
  .L002B307C:
    /* B3C7C 002B307C 014A5021 */  addu       $t2, $t2, $t2
    /* B3C80 002B3080 000A7A02 */  srl        $t7, $t2, 8
    /* B3C84 002B3084 31EF0001 */  andi       $t7, $t7, 0x1
    /* B3C88 002B3088 314A00FF */  andi       $t2, $t2, 0xFF
    /* B3C8C 002B308C 140A0007 */  bne        $zero, $t2, .L002B30AC
    /* B3C90 002B3090 00000000 */   nop
    /* B3C94 002B3094 906A0000 */  lbu        $t2, 0x0($v1)
    /* B3C98 002B3098 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* B3C9C 002B309C 014A5021 */  addu       $t2, $t2, $t2
    /* B3CA0 002B30A0 014F5021 */  addu       $t2, $t2, $t7
    /* B3CA4 002B30A4 000A7A02 */  srl        $t7, $t2, 8
    /* B3CA8 002B30A8 31EF0001 */  andi       $t7, $t7, 0x1
  .L002B30AC:
    /* B3CAC 002B30AC 140FFF88 */  bne        $zero, $t7, .L002B2ED0
    /* B3CB0 002B30B0 00000000 */   nop
    /* B3CB4 002B30B4 956D0000 */  lhu        $t5, 0x0($t3)
    /* B3CB8 002B30B8 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* B3CBC 002B30BC 100D0008 */  beq        $zero, $t5, .L002B30E0
    /* B3CC0 002B30C0 00000000 */   nop
  .L002B30C4:
    /* B3CC4 002B30C4 85700000 */  lh         $s0, 0x0($t3)
    /* B3CC8 002B30C8 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* B3CCC 002B30CC A0B00000 */  sb         $s0, 0x0($a1)
    /* B3CD0 002B30D0 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* B3CD4 002B30D4 21ADFFFF */  addi       $t5, $t5, -0x1 /* handwritten instruction */
    /* B3CD8 002B30D8 140DFFFA */  bne        $zero, $t5, .L002B30C4
    /* B3CDC 002B30DC 00000000 */   nop
  .L002B30E0:
    /* B3CE0 002B30E0 080ACC3B */  j          .L002B30EC
    /* B3CE4 002B30E4 00000000 */   nop
    /* B3CE8 002B30E8 AD700000 */  sw         $s0, 0x0($t3)
  .L002B30EC:
    /* B3CEC 002B30EC 24020000 */  addiu      $v0, $zero, 0x0
    /* B3CF0 002B30F0 03E00008 */  jr         $ra
    /* B3CF4 002B30F4 00000000 */   nop


    /* B3CF8 002B30F8 0C0AD469 */  .word      0x0C0AD469 /* linker padding */
    /* B3CFC 002B30FC A7A20010 */  .word      0xA7A20010 /* linker padding */
endlabel rncUnpackMethod2Body
