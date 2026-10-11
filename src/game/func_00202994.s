.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x3594-0x3898 (VRAM 0x00202994) */
glabel func_00202994
    /* 3594 00202994 FF400000 */  sd         $zero, 0x0($k0) /* handwritten instruction */
    /* 3598 00202998 FF410008 */  sd         $at, 0x8($k0) /* handwritten instruction */
    /* 359C 0020299C FF420010 */  sd         $v0, 0x10($k0) /* handwritten instruction */
    /* 35A0 002029A0 FF430018 */  sd         $v1, 0x18($k0) /* handwritten instruction */
    /* 35A4 002029A4 FF440020 */  sd         $a0, 0x20($k0) /* handwritten instruction */
    /* 35A8 002029A8 FF450028 */  sd         $a1, 0x28($k0) /* handwritten instruction */
    /* 35AC 002029AC FF460030 */  sd         $a2, 0x30($k0) /* handwritten instruction */
    /* 35B0 002029B0 FF470038 */  sd         $a3, 0x38($k0) /* handwritten instruction */
    /* 35B4 002029B4 FF480040 */  sd         $t0, 0x40($k0) /* handwritten instruction */
    /* 35B8 002029B8 FF490048 */  sd         $t1, 0x48($k0) /* handwritten instruction */
    /* 35BC 002029BC FF4A0050 */  sd         $t2, 0x50($k0) /* handwritten instruction */
    /* 35C0 002029C0 FF4B0058 */  sd         $t3, 0x58($k0) /* handwritten instruction */
    /* 35C4 002029C4 FF4C0060 */  sd         $t4, 0x60($k0) /* handwritten instruction */
    /* 35C8 002029C8 FF4D0068 */  sd         $t5, 0x68($k0) /* handwritten instruction */
    /* 35CC 002029CC FF4E0070 */  sd         $t6, 0x70($k0) /* handwritten instruction */
    /* 35D0 002029D0 FF4F0078 */  sd         $t7, 0x78($k0) /* handwritten instruction */
    /* 35D4 002029D4 FF500080 */  sd         $s0, 0x80($k0) /* handwritten instruction */
    /* 35D8 002029D8 FF510088 */  sd         $s1, 0x88($k0) /* handwritten instruction */
    /* 35DC 002029DC FF520090 */  sd         $s2, 0x90($k0) /* handwritten instruction */
    /* 35E0 002029E0 FF530098 */  sd         $s3, 0x98($k0) /* handwritten instruction */
    /* 35E4 002029E4 FF5400A0 */  sd         $s4, 0xA0($k0) /* handwritten instruction */
    /* 35E8 002029E8 FF5500A8 */  sd         $s5, 0xA8($k0) /* handwritten instruction */
    /* 35EC 002029EC FF5600B0 */  sd         $s6, 0xB0($k0) /* handwritten instruction */
    /* 35F0 002029F0 FF5700B8 */  sd         $s7, 0xB8($k0) /* handwritten instruction */
    /* 35F4 002029F4 FF5800C0 */  sd         $t8, 0xC0($k0) /* handwritten instruction */
    /* 35F8 002029F8 FF5900C8 */  sd         $t9, 0xC8($k0) /* handwritten instruction */
    /* 35FC 002029FC FF5B00D8 */  sd         $k1, 0xD8($k0) /* handwritten instruction */
    /* 3600 00202A00 FF5C00E0 */  sd         $gp, 0xE0($k0) /* handwritten instruction */
    /* 3604 00202A04 FF5D00E8 */  sd         $sp, 0xE8($k0) /* handwritten instruction */
    /* 3608 00202A08 FF5E00F0 */  sd         $fp, 0xF0($k0) /* handwritten instruction */
    /* 360C 00202A0C 4008F000 */  mfc0       $t0, $30 /* handwritten instruction */
    /* 3610 00202A10 FF4800D0 */  sd         $t0, 0xD0($k0) /* handwritten instruction */
    /* 3614 00202A14 00004012 */  mflo       $t0
    /* 3618 00202A18 FF480100 */  sd         $t0, 0x100($k0) /* handwritten instruction */
    /* 361C 00202A1C 00004010 */  mfhi       $t0
    /* 3620 00202A20 FF480108 */  sd         $t0, 0x108($k0) /* handwritten instruction */
    /* 3624 00202A24 40080000 */  mfc0       $t0, $0 /* handwritten instruction */
    /* 3628 00202A28 00000000 */  nop
    /* 362C 00202A2C FF480118 */  sd         $t0, 0x118($k0) /* handwritten instruction */
    /* 3630 00202A30 40080800 */  mfc0       $t0, $1 /* handwritten instruction */
    /* 3634 00202A34 00000000 */  nop
    /* 3638 00202A38 FF480120 */  sd         $t0, 0x120($k0) /* handwritten instruction */
    /* 363C 00202A3C 40081000 */  mfc0       $t0, $2 /* handwritten instruction */
    /* 3640 00202A40 00000000 */  nop
    /* 3644 00202A44 FF480128 */  sd         $t0, 0x128($k0) /* handwritten instruction */
    /* 3648 00202A48 40081800 */  mfc0       $t0, $3 /* handwritten instruction */
    /* 364C 00202A4C 00000000 */  nop
    /* 3650 00202A50 FF480130 */  sd         $t0, 0x130($k0) /* handwritten instruction */
    /* 3654 00202A54 40082000 */  mfc0       $t0, $4 /* handwritten instruction */
    /* 3658 00202A58 00000000 */  nop
    /* 365C 00202A5C FF480138 */  sd         $t0, 0x138($k0) /* handwritten instruction */
    /* 3660 00202A60 40082800 */  mfc0       $t0, $5 /* handwritten instruction */
    /* 3664 00202A64 00000000 */  nop
    /* 3668 00202A68 FF480140 */  sd         $t0, 0x140($k0) /* handwritten instruction */
    /* 366C 00202A6C 40083000 */  mfc0       $t0, $6 /* handwritten instruction */
    /* 3670 00202A70 00000000 */  nop
    /* 3674 00202A74 FF480148 */  sd         $t0, 0x148($k0) /* handwritten instruction */
    /* 3678 00202A78 40083800 */  mfc0       $t0, $7 /* handwritten instruction */
    /* 367C 00202A7C 00000000 */  nop
    /* 3680 00202A80 FF480150 */  sd         $t0, 0x150($k0) /* handwritten instruction */
    /* 3684 00202A84 40084000 */  mfc0       $t0, $8 /* handwritten instruction */
    /* 3688 00202A88 00000000 */  nop
    /* 368C 00202A8C FF480158 */  sd         $t0, 0x158($k0) /* handwritten instruction */
    /* 3690 00202A90 40084800 */  mfc0       $t0, $9 /* handwritten instruction */
    /* 3694 00202A94 00000000 */  nop
    /* 3698 00202A98 FF480160 */  sd         $t0, 0x160($k0) /* handwritten instruction */
    /* 369C 00202A9C 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* 36A0 00202AA0 00000000 */  nop
    /* 36A4 00202AA4 FF480168 */  sd         $t0, 0x168($k0) /* handwritten instruction */
    /* 36A8 00202AA8 40085800 */  mfc0       $t0, $11 /* handwritten instruction */
    /* 36AC 00202AAC 00000000 */  nop
    /* 36B0 00202AB0 FF480170 */  sd         $t0, 0x170($k0) /* handwritten instruction */
    /* 36B4 00202AB4 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* 36B8 00202AB8 00000000 */  nop
    /* 36BC 00202ABC FF480178 */  sd         $t0, 0x178($k0) /* handwritten instruction */
    /* 36C0 00202AC0 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* 36C4 00202AC4 00000000 */  nop
    /* 36C8 00202AC8 FF480180 */  sd         $t0, 0x180($k0) /* handwritten instruction */
    /* 36CC 00202ACC 40087000 */  mfc0       $t0, $14 /* handwritten instruction */
    /* 36D0 00202AD0 00000000 */  nop
    /* 36D4 00202AD4 FF480188 */  sd         $t0, 0x188($k0) /* handwritten instruction */
    /* 36D8 00202AD8 40087800 */  mfc0       $t0, $15 /* handwritten instruction */
    /* 36DC 00202ADC 00000000 */  nop
    /* 36E0 00202AE0 FF480190 */  sd         $t0, 0x190($k0) /* handwritten instruction */
    /* 36E4 00202AE4 40088000 */  mfc0       $t0, $16 /* handwritten instruction */
    /* 36E8 00202AE8 00000000 */  nop
    /* 36EC 00202AEC FF480198 */  sd         $t0, 0x198($k0) /* handwritten instruction */
    /* 36F0 00202AF0 40088800 */  mfc0       $t0, $17 /* handwritten instruction */
    /* 36F4 00202AF4 00000000 */  nop
    /* 36F8 00202AF8 FF4801A0 */  sd         $t0, 0x1A0($k0) /* handwritten instruction */
    /* 36FC 00202AFC 40089000 */  mfc0       $t0, $18 /* handwritten instruction */
    /* 3700 00202B00 00000000 */  nop
    /* 3704 00202B04 FF4801A8 */  sd         $t0, 0x1A8($k0) /* handwritten instruction */
    /* 3708 00202B08 40089800 */  mfc0       $t0, $19 /* handwritten instruction */
    /* 370C 00202B0C 00000000 */  nop
    /* 3710 00202B10 FF4801B0 */  sd         $t0, 0x1B0($k0) /* handwritten instruction */
    /* 3714 00202B14 4008A000 */  mfc0       $t0, $20 /* handwritten instruction */
    /* 3718 00202B18 00000000 */  nop
    /* 371C 00202B1C FF4801B8 */  sd         $t0, 0x1B8($k0) /* handwritten instruction */
    /* 3720 00202B20 4008A800 */  mfc0       $t0, $21 /* handwritten instruction */
    /* 3724 00202B24 00000000 */  nop
    /* 3728 00202B28 FF4801C0 */  sd         $t0, 0x1C0($k0) /* handwritten instruction */
    /* 372C 00202B2C 4008B000 */  mfc0       $t0, $22 /* handwritten instruction */
    /* 3730 00202B30 00000000 */  nop
    /* 3734 00202B34 FF4801C8 */  sd         $t0, 0x1C8($k0) /* handwritten instruction */
    /* 3738 00202B38 4008B800 */  mfc0       $t0, $23 /* handwritten instruction */
    /* 373C 00202B3C 00000000 */  nop
    /* 3740 00202B40 FF4801D0 */  sd         $t0, 0x1D0($k0) /* handwritten instruction */
    /* 3744 00202B44 4008C000 */  mfc0       $t0, $24 /* handwritten instruction */
    /* 3748 00202B48 00000000 */  nop
    /* 374C 00202B4C FF4801D8 */  sd         $t0, 0x1D8($k0) /* handwritten instruction */
    /* 3750 00202B50 4008C800 */  mfc0       $t0, $25 /* handwritten instruction */
    /* 3754 00202B54 00000000 */  nop
    /* 3758 00202B58 FF4801E0 */  sd         $t0, 0x1E0($k0) /* handwritten instruction */
    /* 375C 00202B5C 4008D000 */  mfc0       $t0, $26 /* handwritten instruction */
    /* 3760 00202B60 00000000 */  nop
    /* 3764 00202B64 FF4801E8 */  sd         $t0, 0x1E8($k0) /* handwritten instruction */
    /* 3768 00202B68 4008D800 */  mfc0       $t0, $27 /* handwritten instruction */
    /* 376C 00202B6C 00000000 */  nop
    /* 3770 00202B70 FF4801F0 */  sd         $t0, 0x1F0($k0) /* handwritten instruction */
    /* 3774 00202B74 4008E000 */  mfc0       $t0, $28 /* handwritten instruction */
    /* 3778 00202B78 00000000 */  nop
    /* 377C 00202B7C FF4801F8 */  sd         $t0, 0x1F8($k0) /* handwritten instruction */
    /* 3780 00202B80 4008E800 */  mfc0       $t0, $29 /* handwritten instruction */
    /* 3784 00202B84 00000000 */  nop
    /* 3788 00202B88 FF480200 */  sd         $t0, 0x200($k0) /* handwritten instruction */
    /* 378C 00202B8C 4008F000 */  mfc0       $t0, $30 /* handwritten instruction */
    /* 3790 00202B90 00000000 */  nop
    /* 3794 00202B94 FF480208 */  sd         $t0, 0x208($k0) /* handwritten instruction */
    /* 3798 00202B98 4008F800 */  mfc0       $t0, $31 /* handwritten instruction */
    /* 379C 00202B9C 00000000 */  nop
    /* 37A0 00202BA0 FF480210 */  sd         $t0, 0x210($k0) /* handwritten instruction */
    /* 37A4 00202BA4 DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 37A8 00202BA8 3C092000 */  lui        $t1, (0x20000000 >> 16)
    /* 37AC 00202BAC 01284824 */  and        $t1, $t1, $t0
    /* 37B0 00202BB0 1120002C */  beqz       $t1, .L00202C64
    /* 37B4 00202BB4 00000000 */   nop
    /* 37B8 00202BB8 44480000 */  cfc1       $t0, $0
    /* 37BC 00202BBC 00000000 */  nop
    /* 37C0 00202BC0 AF480318 */  sw         $t0, 0x318($k0) /* handwritten instruction */
    /* 37C4 00202BC4 4448F800 */  cfc1       $t0, $31
    /* 37C8 00202BC8 00000000 */  nop
    /* 37CC 00202BCC AF48031C */  sw         $t0, 0x31C($k0) /* handwritten instruction */
    /* 37D0 00202BD0 F7400218 */  sdc1       $fv0, 0x218($k0)
    /* 37D4 00202BD4 F7420228 */  sdc1       $fv1, 0x228($k0)
    /* 37D8 00202BD8 F7440238 */  sdc1       $ft0, 0x238($k0)
    /* 37DC 00202BDC F7460248 */  sdc1       $ft1, 0x248($k0)
    /* 37E0 00202BE0 F7480258 */  sdc1       $ft2, 0x258($k0)
    /* 37E4 00202BE4 F74A0268 */  sdc1       $ft3, 0x268($k0)
    /* 37E8 00202BE8 F74C0278 */  sdc1       $fa0, 0x278($k0)
    /* 37EC 00202BEC F74E0288 */  sdc1       $fa1, 0x288($k0)
    /* 37F0 00202BF0 F7500298 */  sdc1       $ft4, 0x298($k0)
    /* 37F4 00202BF4 F75202A8 */  sdc1       $ft5, 0x2A8($k0)
    /* 37F8 00202BF8 F75402B8 */  sdc1       $fs0, 0x2B8($k0)
    /* 37FC 00202BFC F75602C8 */  sdc1       $fs1, 0x2C8($k0)
    /* 3800 00202C00 F75802D8 */  sdc1       $fs2, 0x2D8($k0)
    /* 3804 00202C04 F75A02E8 */  sdc1       $fs3, 0x2E8($k0)
    /* 3808 00202C08 F75C02F8 */  sdc1       $fs4, 0x2F8($k0)
    /* 380C 00202C0C F75E0308 */  sdc1       $fs5, 0x308($k0)
    /* 3810 00202C10 DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 3814 00202C14 3C090400 */  lui        $t1, (0x4000000 >> 16)
    /* 3818 00202C18 01284824 */  and        $t1, $t1, $t0
    /* 381C 00202C1C 11200011 */  beqz       $t1, .L00202C64
    /* 3820 00202C20 00000000 */   nop
    /* 3824 00202C24 F7410220 */  sdc1       $fv0f, 0x220($k0)
    /* 3828 00202C28 F7430230 */  sdc1       $fv1f, 0x230($k0)
    /* 382C 00202C2C F7450240 */  sdc1       $ft0f, 0x240($k0)
    /* 3830 00202C30 F7470250 */  sdc1       $ft1f, 0x250($k0)
    /* 3834 00202C34 F7490260 */  sdc1       $ft2f, 0x260($k0)
    /* 3838 00202C38 F74B0270 */  sdc1       $ft3f, 0x270($k0)
    /* 383C 00202C3C F74D0280 */  sdc1       $fa0f, 0x280($k0)
    /* 3840 00202C40 F74F0290 */  sdc1       $fa1f, 0x290($k0)
    /* 3844 00202C44 F75102A0 */  sdc1       $ft4f, 0x2A0($k0)
    /* 3848 00202C48 F75302B0 */  sdc1       $ft5f, 0x2B0($k0)
    /* 384C 00202C4C F75502C0 */  sdc1       $fs0f, 0x2C0($k0)
    /* 3850 00202C50 F75702D0 */  sdc1       $fs1f, 0x2D0($k0)
    /* 3854 00202C54 F75902E0 */  sdc1       $fs2f, 0x2E0($k0)
    /* 3858 00202C58 F75B02F0 */  sdc1       $fs3f, 0x2F0($k0)
    /* 385C 00202C5C F75D0300 */  sdc1       $fs4f, 0x300($k0)
    /* 3860 00202C60 F75F0310 */  sdc1       $fs5f, 0x310($k0)
  .L00202C64:
    /* 3864 00202C64 DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 3868 00202C68 00000000 */  nop
    /* 386C 00202C6C 31080004 */  andi       $t0, $t0, 0x4
    /* 3870 00202C70 15000004 */  bnez       $t0, .L00202C84
    /* 3874 00202C74 00000000 */   nop
    /* 3878 00202C78 DF480188 */  ld         $t0, 0x188($k0) /* handwritten instruction */
    /* 387C 00202C7C 08080B23 */  j          .L00202C8C
    /* 3880 00202C80 00000000 */   nop
  .L00202C84:
    /* 3884 00202C84 DF480208 */  ld         $t0, 0x208($k0) /* handwritten instruction */
    /* 3888 00202C88 00000000 */  nop
  .L00202C8C:
    /* 388C 00202C8C FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* 3890 00202C90 03E00008 */  jr         $ra
    /* 3894 00202C94 00000000 */   nop
endlabel func_00202994
