.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA400-0xBA94C (VRAM 0x002B9800) */
glabel alEnvmixerPull
    /* BA400 002B9800 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* BA404 002B9804 AFB3002C */  sw         $s3, 0x2C($sp)
    /* BA408 002B9808 8FB30058 */  lw         $s3, 0x58($sp)
    /* BA40C 002B980C AFB60038 */  sw         $s6, 0x38($sp)
    /* BA410 002B9810 00C0B021 */  addu       $s6, $a2, $zero
    /* BA414 002B9814 AFB00020 */  sw         $s0, 0x20($sp)
    /* BA418 002B9818 00808021 */  addu       $s0, $a0, $zero
    /* BA41C 002B981C AFBF0044 */  sw         $ra, 0x44($sp)
    /* BA420 002B9820 AFBE0040 */  sw         $fp, 0x40($sp)
    /* BA424 002B9824 AFB7003C */  sw         $s7, 0x3C($sp)
    /* BA428 002B9828 AFB50034 */  sw         $s5, 0x34($sp)
    /* BA42C 002B982C AFB40030 */  sw         $s4, 0x30($sp)
    /* BA430 002B9830 AFB20028 */  sw         $s2, 0x28($sp)
    /* BA434 002B9834 AFB10024 */  sw         $s1, 0x24($sp)
    /* BA438 002B9838 AFA70054 */  sw         $a3, 0x54($sp)
    /* BA43C 002B983C 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA440 002B9840 00E0F021 */  addu       $fp, $a3, $zero
    /* BA444 002B9844 A7A0001A */  sh         $zero, 0x1A($sp)
    /* BA448 002B9848 10400125 */  beqz       $v0, .L002B9CE0
    /* BA44C 002B984C A7A00018 */   sh        $zero, 0x18($sp)
    /* BA450 002B9850 24170001 */  addiu      $s7, $zero, 0x1
    /* BA454 002B9854 3C15800E */  lui        $s5, %hi(D_800D8240)
    /* BA458 002B9858 26B58240 */  addiu      $s5, $s5, %lo(D_800D8240)
    /* BA45C 002B985C 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA460 002B9860 03C01821 */  addu       $v1, $fp, $zero
  .L002B9864:
    /* BA464 002B9864 8C5E0004 */  lw         $fp, 0x4($v0)
    /* BA468 002B9868 03C39023 */  subu       $s2, $fp, $v1
    /* BA46C 002B986C 02D2102A */  slt        $v0, $s6, $s2
    /* BA470 002B9870 1440011C */  bnez       $v0, .L002B9CE4
    /* BA474 002B9874 02002021 */   addu      $a0, $s0, $zero
    /* BA478 002B9878 06410008 */  bgez       $s2, .L002B989C
    /* BA47C 002B987C 2A4200A1 */   slti      $v0, $s2, 0xA1
    /* BA480 002B9880 3C04800D */  lui        $a0, %hi(D_800CC850)
    /* BA484 002B9884 2484C850 */  addiu      $a0, $a0, %lo(D_800CC850)
    /* BA488 002B9888 3C05800D */  lui        $a1, %hi(D_800CC854)
    /* BA48C 002B988C 24A5C854 */  addiu      $a1, $a1, %lo(D_800CC854)
    /* BA490 002B9890 0C0AFF50 */  jal        __assert
    /* BA494 002B9894 24060067 */   addiu     $a2, $zero, 0x67
    /* BA498 002B9898 2A4200A1 */  slti       $v0, $s2, 0xA1
  .L002B989C:
    /* BA49C 002B989C 14400007 */  bnez       $v0, .L002B98BC
    /* BA4A0 002B98A0 00000000 */   nop
    /* BA4A4 002B98A4 3C04800D */  lui        $a0, %hi(D_800CC850)
    /* BA4A8 002B98A8 2484C850 */  addiu      $a0, $a0, %lo(D_800CC850)
    /* BA4AC 002B98AC 3C05800D */  lui        $a1, %hi(D_800CC854)
    /* BA4B0 002B98B0 24A5C854 */  addiu      $a1, $a1, %lo(D_800CC854)
    /* BA4B4 002B98B4 0C0AFF50 */  jal        __assert
    /* BA4B8 002B98B8 24060068 */   addiu     $a2, $zero, 0x68
  .L002B98BC:
    /* BA4BC 002B98BC 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA4C0 002B98C0 84430008 */  lh         $v1, 0x8($v0)
    /* BA4C4 002B98C4 2C620011 */  sltiu      $v0, $v1, 0x11
    /* BA4C8 002B98C8 104000E6 */  beqz       $v0, .L002B9C64
    /* BA4CC 002B98CC 00031080 */   sll       $v0, $v1, 2
    /* BA4D0 002B98D0 3C01800D */  lui        $at, %hi(jtbl_800CC860)
    /* BA4D4 002B98D4 00220821 */  addu       $at, $at, $v0
    /* BA4D8 002B98D8 8C22C860 */  lw         $v0, %lo(jtbl_800CC860)($at)
    /* BA4DC 002B98DC 00400008 */  jr         $v0
    /* BA4E0 002B98E0 00000000 */   nop
    /* BA4E4 002B98E4 8E11003C */  lw         $s1, 0x3C($s0)
    /* BA4E8 002B98E8 8622000A */  lh         $v0, 0xA($s1)
    /* BA4EC 002B98EC 10400006 */  beqz       $v0, .L002B9908
    /* BA4F0 002B98F0 0200A021 */   addu      $s4, $s0, $zero
    /* BA4F4 002B98F4 02002021 */  addu       $a0, $s0, $zero
    /* BA4F8 002B98F8 24050008 */  addiu      $a1, $zero, 0x8
    /* BA4FC 002B98FC 8E020008 */  lw         $v0, 0x8($s0)
    /* BA500 002B9900 0040F809 */  jalr       $v0
    /* BA504 002B9904 00003021 */   addu      $a2, $zero, $zero
  .L002B9908:
    /* BA508 002B9908 02002021 */  addu       $a0, $s0, $zero
    /* BA50C 002B990C 8E260018 */  lw         $a2, 0x18($s1)
    /* BA510 002B9910 8E020008 */  lw         $v0, 0x8($s0)
    /* BA514 002B9914 0040F809 */  jalr       $v0
    /* BA518 002B9918 24050005 */   addiu     $a1, $zero, 0x5
    /* BA51C 002B991C 02002021 */  addu       $a0, $s0, $zero
    /* BA520 002B9920 24050009 */  addiu      $a1, $zero, 0x9
    /* BA524 002B9924 8E020008 */  lw         $v0, 0x8($s0)
    /* BA528 002B9928 0040F809 */  jalr       $v0
    /* BA52C 002B992C 00003021 */   addu      $a2, $zero, $zero
    /* BA530 002B9930 AE170038 */  sw         $s7, 0x38($s0)
    /* BA534 002B9934 AE000030 */  sw         $zero, 0x30($s0)
    /* BA538 002B9938 8E220014 */  lw         $v0, 0x14($s1)
    /* BA53C 002B993C AE020034 */  sw         $v0, 0x34($s0)
    /* BA540 002B9940 86220010 */  lh         $v0, 0x10($s1)
    /* BA544 002B9944 00420018 */  mult       $v0, $v0
    /* BA548 002B9948 00004012 */  mflo       $t0
    /* BA54C 002B994C 000813C3 */  sra        $v0, $t0, 15
    /* BA550 002B9950 A602001A */  sh         $v0, 0x1A($s0)
    /* BA554 002B9954 92220012 */  lbu        $v0, 0x12($s1)
    /* BA558 002B9958 A6020018 */  sh         $v0, 0x18($s0)
    /* BA55C 002B995C 92220013 */  lbu        $v0, 0x13($s1)
    /* BA560 002B9960 00021040 */  sll        $v0, $v0, 1
    /* BA564 002B9964 00551021 */  addu       $v0, $v0, $s5
    /* BA568 002B9968 94420000 */  lhu        $v0, 0x0($v0)
    /* BA56C 002B996C A6020020 */  sh         $v0, 0x20($s0)
    /* BA570 002B9970 92220013 */  lbu        $v0, 0x13($s1)
    /* BA574 002B9974 2408007F */  addiu      $t0, $zero, 0x7F
    /* BA578 002B9978 01021023 */  subu       $v0, $t0, $v0
    /* BA57C 002B997C 00021040 */  sll        $v0, $v0, 1
    /* BA580 002B9980 00551021 */  addu       $v0, $v0, $s5
    /* BA584 002B9984 94420000 */  lhu        $v0, 0x0($v0)
    /* BA588 002B9988 A6020022 */  sh         $v0, 0x22($s0)
    /* BA58C 002B998C 8E220014 */  lw         $v0, 0x14($s1)
    /* BA590 002B9990 10400004 */  beqz       $v0, .L002B99A4
    /* BA594 002B9994 00000000 */   nop
    /* BA598 002B9998 A617001C */  sh         $s7, 0x1C($s0)
    /* BA59C 002B999C 080AE67D */  j          .L002B99F4
    /* BA5A0 002B99A0 A617001E */   sh        $s7, 0x1E($s0)
  .L002B99A4:
    /* BA5A4 002B99A4 86020018 */  lh         $v0, 0x18($s0)
    /* BA5A8 002B99A8 8603001A */  lh         $v1, 0x1A($s0)
    /* BA5AC 002B99AC 00021040 */  sll        $v0, $v0, 1
    /* BA5B0 002B99B0 00551021 */  addu       $v0, $v0, $s5
    /* BA5B4 002B99B4 84420000 */  lh         $v0, 0x0($v0)
    /* BA5B8 002B99B8 00620018 */  mult       $v1, $v0
    /* BA5BC 002B99BC 86020018 */  lh         $v0, 0x18($s0)
    /* BA5C0 002B99C0 00004012 */  mflo       $t0
    /* BA5C4 002B99C4 00081BC3 */  sra        $v1, $t0, 15
    /* BA5C8 002B99C8 2408007F */  addiu      $t0, $zero, 0x7F
    /* BA5CC 002B99CC 01021023 */  subu       $v0, $t0, $v0
    /* BA5D0 002B99D0 00021040 */  sll        $v0, $v0, 1
    /* BA5D4 002B99D4 00551021 */  addu       $v0, $v0, $s5
    /* BA5D8 002B99D8 A603001C */  sh         $v1, 0x1C($s0)
    /* BA5DC 002B99DC 8603001A */  lh         $v1, 0x1A($s0)
    /* BA5E0 002B99E0 84420000 */  lh         $v0, 0x0($v0)
    /* BA5E4 002B99E4 00620018 */  mult       $v1, $v0
    /* BA5E8 002B99E8 00004012 */  mflo       $t0
    /* BA5EC 002B99EC 000813C3 */  sra        $v0, $t0, 15
    /* BA5F0 002B99F0 A602001E */  sh         $v0, 0x1E($s0)
  .L002B99F4:
    /* BA5F4 002B99F4 8E840000 */  lw         $a0, 0x0($s4)
    /* BA5F8 002B99F8 108000AA */  beqz       $a0, .L002B9CA4
    /* BA5FC 002B99FC 24050007 */   addiu     $a1, $zero, 0x7
    /* BA600 002B9A00 8E26000C */  lw         $a2, 0xC($s1)
    /* BA604 002B9A04 8C820008 */  lw         $v0, 0x8($a0)
    /* BA608 002B9A08 080AE727 */  j          .L002B9C9C
    /* BA60C 002B9A0C 00000000 */   nop
    /* BA610 002B9A10 02002021 */  addu       $a0, $s0, $zero
    /* BA614 002B9A14 27A50018 */  addiu      $a1, $sp, 0x18
    /* BA618 002B9A18 27A6001A */  addiu      $a2, $sp, 0x1A
    /* BA61C 002B9A1C 8FA80054 */  lw         $t0, 0x54($sp)
    /* BA620 002B9A20 02403821 */  addu       $a3, $s2, $zero
    /* BA624 002B9A24 AFB30014 */  sw         $s3, 0x14($sp)
    /* BA628 002B9A28 0C0AE753 */  jal        _pullSubFrame
    /* BA62C 002B9A2C AFA80010 */   sw        $t0, 0x10($sp)
    /* BA630 002B9A30 8E050030 */  lw         $a1, 0x30($s0)
    /* BA634 002B9A34 8E030034 */  lw         $v1, 0x34($s0)
    /* BA638 002B9A38 00A3182A */  slt        $v1, $a1, $v1
    /* BA63C 002B9A3C 1460001C */  bnez       $v1, .L002B9AB0
    /* BA640 002B9A40 00409821 */   addu      $s3, $v0, $zero
    /* BA644 002B9A44 86020018 */  lh         $v0, 0x18($s0)
    /* BA648 002B9A48 8603001A */  lh         $v1, 0x1A($s0)
    /* BA64C 002B9A4C 00021040 */  sll        $v0, $v0, 1
    /* BA650 002B9A50 00551021 */  addu       $v0, $v0, $s5
    /* BA654 002B9A54 84420000 */  lh         $v0, 0x0($v0)
    /* BA658 002B9A58 00620018 */  mult       $v1, $v0
    /* BA65C 002B9A5C 86020018 */  lh         $v0, 0x18($s0)
    /* BA660 002B9A60 00004012 */  mflo       $t0
    /* BA664 002B9A64 00081BC3 */  sra        $v1, $t0, 15
    /* BA668 002B9A68 2408007F */  addiu      $t0, $zero, 0x7F
    /* BA66C 002B9A6C 01021023 */  subu       $v0, $t0, $v0
    /* BA670 002B9A70 00021040 */  sll        $v0, $v0, 1
    /* BA674 002B9A74 00551021 */  addu       $v0, $v0, $s5
    /* BA678 002B9A78 A6030028 */  sh         $v1, 0x28($s0)
    /* BA67C 002B9A7C 8603001A */  lh         $v1, 0x1A($s0)
    /* BA680 002B9A80 84420000 */  lh         $v0, 0x0($v0)
    /* BA684 002B9A84 00620018 */  mult       $v1, $v0
    /* BA688 002B9A88 96030028 */  lhu        $v1, 0x28($s0)
    /* BA68C 002B9A8C 00004012 */  mflo       $t0
    /* BA690 002B9A90 000813C3 */  sra        $v0, $t0, 15
    /* BA694 002B9A94 A602002E */  sh         $v0, 0x2E($s0)
    /* BA698 002B9A98 8E020034 */  lw         $v0, 0x34($s0)
    /* BA69C 002B9A9C 9604002E */  lhu        $a0, 0x2E($s0)
    /* BA6A0 002B9AA0 A603001C */  sh         $v1, 0x1C($s0)
    /* BA6A4 002B9AA4 AE020030 */  sw         $v0, 0x30($s0)
    /* BA6A8 002B9AA8 080AE6C0 */  j          .L002B9B00
    /* BA6AC 002B9AAC A604001E */   sh        $a0, 0x1E($s0)
  .L002B9AB0:
    /* BA6B0 002B9AB0 86060026 */  lh         $a2, 0x26($s0)
    /* BA6B4 002B9AB4 8602001C */  lh         $v0, 0x1C($s0)
    /* BA6B8 002B9AB8 96070024 */  lhu        $a3, 0x24($s0)
    /* BA6BC 002B9ABC 44826000 */  mtc1       $v0, $fa0
    /* BA6C0 002B9AC0 46806320 */  cvt.s.w    $fa0, $fa0
    /* BA6C4 002B9AC4 0C0AE8D6 */  jal        _getVol
    /* BA6C8 002B9AC8 00000000 */   nop
    /* BA6CC 002B9ACC 8E050030 */  lw         $a1, 0x30($s0)
    /* BA6D0 002B9AD0 8606002C */  lh         $a2, 0x2C($s0)
    /* BA6D4 002B9AD4 9607002A */  lhu        $a3, 0x2A($s0)
    /* BA6D8 002B9AD8 8603001E */  lh         $v1, 0x1E($s0)
    /* BA6DC 002B9ADC 4600004D */  trunc.w.s  $fv0f, $fv0
    /* BA6E0 002B9AE0 44020800 */  mfc1       $v0, $fv0f
    /* BA6E4 002B9AE4 44836000 */  mtc1       $v1, $fa0
    /* BA6E8 002B9AE8 46806320 */  cvt.s.w    $fa0, $fa0
    /* BA6EC 002B9AEC 0C0AE8D6 */  jal        _getVol
    /* BA6F0 002B9AF0 A602001C */   sh        $v0, 0x1C($s0)
    /* BA6F4 002B9AF4 4600004D */  trunc.w.s  $fv0f, $fv0
    /* BA6F8 002B9AF8 44020800 */  mfc1       $v0, $fv0f
    /* BA6FC 002B9AFC A602001E */  sh         $v0, 0x1E($s0)
  .L002B9B00:
    /* BA700 002B9B00 8602001C */  lh         $v0, 0x1C($s0)
    /* BA704 002B9B04 50400001 */  beql       $v0, $zero, .L002B9B0C
    /* BA708 002B9B08 A617001C */   sh        $s7, 0x1C($s0)
  .L002B9B0C:
    /* BA70C 002B9B0C 8602001E */  lh         $v0, 0x1E($s0)
    /* BA710 002B9B10 50400001 */  beql       $v0, $zero, .L002B9B18
    /* BA714 002B9B14 A617001E */   sh        $s7, 0x1E($s0)
  .L002B9B18:
    /* BA718 002B9B18 8E04003C */  lw         $a0, 0x3C($s0)
    /* BA71C 002B9B1C 84830008 */  lh         $v1, 0x8($a0)
    /* BA720 002B9B20 2402000C */  addiu      $v0, $zero, 0xC
    /* BA724 002B9B24 14620003 */  bne        $v1, $v0, .L002B9B34
    /* BA728 002B9B28 00000000 */   nop
    /* BA72C 002B9B2C 9482000E */  lhu        $v0, 0xE($a0)
    /* BA730 002B9B30 A6020018 */  sh         $v0, 0x18($s0)
  .L002B9B34:
    /* BA734 002B9B34 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA738 002B9B38 84430008 */  lh         $v1, 0x8($v0)
    /* BA73C 002B9B3C 2402000B */  addiu      $v0, $zero, 0xB
    /* BA740 002B9B40 1462000A */  bne        $v1, $v0, .L002B9B6C
    /* BA744 002B9B44 00000000 */   nop
    /* BA748 002B9B48 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA74C 002B9B4C AE000030 */  sw         $zero, 0x30($s0)
    /* BA750 002B9B50 8C43000C */  lw         $v1, 0xC($v0)
    /* BA754 002B9B54 00630018 */  mult       $v1, $v1
    /* BA758 002B9B58 00004012 */  mflo       $t0
    /* BA75C 002B9B5C 00081BC3 */  sra        $v1, $t0, 15
    /* BA760 002B9B60 A603001A */  sh         $v1, 0x1A($s0)
    /* BA764 002B9B64 8C420010 */  lw         $v0, 0x10($v0)
    /* BA768 002B9B68 AE020034 */  sw         $v0, 0x34($s0)
  .L002B9B6C:
    /* BA76C 002B9B6C 8E04003C */  lw         $a0, 0x3C($s0)
    /* BA770 002B9B70 84830008 */  lh         $v1, 0x8($a0)
    /* BA774 002B9B74 24020010 */  addiu      $v0, $zero, 0x10
    /* BA778 002B9B78 5462004A */  bnel       $v1, $v0, .L002B9CA4
    /* BA77C 002B9B7C AE170038 */   sw        $s7, 0x38($s0)
    /* BA780 002B9B80 8C82000C */  lw         $v0, 0xC($a0)
    /* BA784 002B9B84 00021040 */  sll        $v0, $v0, 1
    /* BA788 002B9B88 00551021 */  addu       $v0, $v0, $s5
    /* BA78C 002B9B8C 94420000 */  lhu        $v0, 0x0($v0)
    /* BA790 002B9B90 00801821 */  addu       $v1, $a0, $zero
    /* BA794 002B9B94 A6020020 */  sh         $v0, 0x20($s0)
    /* BA798 002B9B98 8C62000C */  lw         $v0, 0xC($v1)
    /* BA79C 002B9B9C 2408007F */  addiu      $t0, $zero, 0x7F
    /* BA7A0 002B9BA0 01021023 */  subu       $v0, $t0, $v0
    /* BA7A4 002B9BA4 00021040 */  sll        $v0, $v0, 1
    /* BA7A8 002B9BA8 00551021 */  addu       $v0, $v0, $s5
    /* BA7AC 002B9BAC 94420000 */  lhu        $v0, 0x0($v0)
    /* BA7B0 002B9BB0 A6020022 */  sh         $v0, 0x22($s0)
    /* BA7B4 002B9BB4 080AE729 */  j          .L002B9CA4
    /* BA7B8 002B9BB8 AE170038 */   sw        $s7, 0x38($s0)
    /* BA7BC 002B9BBC 8E11003C */  lw         $s1, 0x3C($s0)
    /* BA7C0 002B9BC0 8622000A */  lh         $v0, 0xA($s1)
    /* BA7C4 002B9BC4 10400005 */  beqz       $v0, .L002B9BDC
    /* BA7C8 002B9BC8 02002021 */   addu      $a0, $s0, $zero
    /* BA7CC 002B9BCC 24050008 */  addiu      $a1, $zero, 0x8
    /* BA7D0 002B9BD0 8E020008 */  lw         $v0, 0x8($s0)
    /* BA7D4 002B9BD4 0040F809 */  jalr       $v0
    /* BA7D8 002B9BD8 00003021 */   addu      $a2, $zero, $zero
  .L002B9BDC:
    /* BA7DC 002B9BDC 02002021 */  addu       $a0, $s0, $zero
    /* BA7E0 002B9BE0 8E26000C */  lw         $a2, 0xC($s1)
    /* BA7E4 002B9BE4 8E020008 */  lw         $v0, 0x8($s0)
    /* BA7E8 002B9BE8 0040F809 */  jalr       $v0
    /* BA7EC 002B9BEC 24050005 */   addiu     $a1, $zero, 0x5
    /* BA7F0 002B9BF0 02002021 */  addu       $a0, $s0, $zero
    /* BA7F4 002B9BF4 24050009 */  addiu      $a1, $zero, 0x9
    /* BA7F8 002B9BF8 8E020008 */  lw         $v0, 0x8($s0)
    /* BA7FC 002B9BFC 080AE727 */  j          .L002B9C9C
    /* BA800 002B9C00 00003021 */   addu      $a2, $zero, $zero
    /* BA804 002B9C04 02002021 */  addu       $a0, $s0, $zero
    /* BA808 002B9C08 27A50018 */  addiu      $a1, $sp, 0x18
    /* BA80C 002B9C0C 27A6001A */  addiu      $a2, $sp, 0x1A
    /* BA810 002B9C10 8FA80054 */  lw         $t0, 0x54($sp)
    /* BA814 002B9C14 02403821 */  addu       $a3, $s2, $zero
    /* BA818 002B9C18 AFB30014 */  sw         $s3, 0x14($sp)
    /* BA81C 002B9C1C 0C0AE753 */  jal        _pullSubFrame
    /* BA820 002B9C20 AFA80010 */   sw        $t0, 0x10($sp)
    /* BA824 002B9C24 00409821 */  addu       $s3, $v0, $zero
    /* BA828 002B9C28 02002021 */  addu       $a0, $s0, $zero
    /* BA82C 002B9C2C 24050004 */  addiu      $a1, $zero, 0x4
    /* BA830 002B9C30 8E020008 */  lw         $v0, 0x8($s0)
    /* BA834 002B9C34 080AE727 */  j          .L002B9C9C
    /* BA838 002B9C38 00003021 */   addu      $a2, $zero, $zero
    /* BA83C 002B9C3C 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA840 002B9C40 3C04800E */  lui        $a0, %hi(alGlobalsp)
    /* BA844 002B9C44 8C8480A0 */  lw         $a0, %lo(alGlobalsp)($a0)
    /* BA848 002B9C48 8C43000C */  lw         $v1, 0xC($v0)
    /* BA84C 002B9C4C AC6000D8 */  sw         $zero, 0xD8($v1)
    /* BA850 002B9C50 8C45000C */  lw         $a1, 0xC($v0)
    /* BA854 002B9C54 0C0AE343 */  jal        _freePVoice
    /* BA858 002B9C58 02D2B023 */   subu      $s6, $s6, $s2
    /* BA85C 002B9C5C 080AE72B */  j          .L002B9CAC
    /* BA860 002B9C60 00121040 */   sll       $v0, $s2, 1
  .L002B9C64:
    /* BA864 002B9C64 02002021 */  addu       $a0, $s0, $zero
    /* BA868 002B9C68 27A50018 */  addiu      $a1, $sp, 0x18
    /* BA86C 002B9C6C 27A6001A */  addiu      $a2, $sp, 0x1A
    /* BA870 002B9C70 8FA80054 */  lw         $t0, 0x54($sp)
    /* BA874 002B9C74 02403821 */  addu       $a3, $s2, $zero
    /* BA878 002B9C78 AFB30014 */  sw         $s3, 0x14($sp)
    /* BA87C 002B9C7C 0C0AE753 */  jal        _pullSubFrame
    /* BA880 002B9C80 AFA80010 */   sw        $t0, 0x10($sp)
    /* BA884 002B9C84 00409821 */  addu       $s3, $v0, $zero
    /* BA888 002B9C88 8E03003C */  lw         $v1, 0x3C($s0)
    /* BA88C 002B9C8C 8E020008 */  lw         $v0, 0x8($s0)
    /* BA890 002B9C90 84650008 */  lh         $a1, 0x8($v1)
    /* BA894 002B9C94 8C66000C */  lw         $a2, 0xC($v1)
    /* BA898 002B9C98 02002021 */  addu       $a0, $s0, $zero
  .L002B9C9C:
    /* BA89C 002B9C9C 0040F809 */  jalr       $v0
    /* BA8A0 002B9CA0 00000000 */   nop
  .L002B9CA4:
    /* BA8A4 002B9CA4 02D2B023 */  subu       $s6, $s6, $s2
    /* BA8A8 002B9CA8 00121040 */  sll        $v0, $s2, 1
  .L002B9CAC:
    /* BA8AC 002B9CAC 8E05003C */  lw         $a1, 0x3C($s0)
    /* BA8B0 002B9CB0 97A3001A */  lhu        $v1, 0x1A($sp)
    /* BA8B4 002B9CB4 8CA40000 */  lw         $a0, 0x0($a1)
    /* BA8B8 002B9CB8 00621821 */  addu       $v1, $v1, $v0
    /* BA8BC 002B9CBC A7A3001A */  sh         $v1, 0x1A($sp)
    /* BA8C0 002B9CC0 14800002 */  bnez       $a0, .L002B9CCC
    /* BA8C4 002B9CC4 AE04003C */   sw        $a0, 0x3C($s0)
    /* BA8C8 002B9CC8 AE000040 */  sw         $zero, 0x40($s0)
  .L002B9CCC:
    /* BA8CC 002B9CCC 0C0AE33D */  jal        __freeParam
    /* BA8D0 002B9CD0 00A02021 */   addu      $a0, $a1, $zero
    /* BA8D4 002B9CD4 8E02003C */  lw         $v0, 0x3C($s0)
    /* BA8D8 002B9CD8 1440FEE2 */  bnez       $v0, .L002B9864
    /* BA8DC 002B9CDC 03C01821 */   addu      $v1, $fp, $zero
  .L002B9CE0:
    /* BA8E0 002B9CE0 02002021 */  addu       $a0, $s0, $zero
  .L002B9CE4:
    /* BA8E4 002B9CE4 27A50018 */  addiu      $a1, $sp, 0x18
    /* BA8E8 002B9CE8 27A6001A */  addiu      $a2, $sp, 0x1A
    /* BA8EC 002B9CEC 8FA80054 */  lw         $t0, 0x54($sp)
    /* BA8F0 002B9CF0 02C03821 */  addu       $a3, $s6, $zero
    /* BA8F4 002B9CF4 AFB30014 */  sw         $s3, 0x14($sp)
    /* BA8F8 002B9CF8 0C0AE753 */  jal        _pullSubFrame
    /* BA8FC 002B9CFC AFA80010 */   sw        $t0, 0x10($sp)
    /* BA900 002B9D00 8E030030 */  lw         $v1, 0x30($s0)
    /* BA904 002B9D04 8E040034 */  lw         $a0, 0x34($s0)
    /* BA908 002B9D08 0083182A */  slt        $v1, $a0, $v1
    /* BA90C 002B9D0C 10600002 */  beqz       $v1, .L002B9D18
    /* BA910 002B9D10 00409821 */   addu      $s3, $v0, $zero
    /* BA914 002B9D14 AE040030 */  sw         $a0, 0x30($s0)
  .L002B9D18:
    /* BA918 002B9D18 02601021 */  addu       $v0, $s3, $zero
    /* BA91C 002B9D1C 8FBF0044 */  lw         $ra, 0x44($sp)
    /* BA920 002B9D20 8FBE0040 */  lw         $fp, 0x40($sp)
    /* BA924 002B9D24 8FB7003C */  lw         $s7, 0x3C($sp)
    /* BA928 002B9D28 8FB60038 */  lw         $s6, 0x38($sp)
    /* BA92C 002B9D2C 8FB50034 */  lw         $s5, 0x34($sp)
    /* BA930 002B9D30 8FB40030 */  lw         $s4, 0x30($sp)
    /* BA934 002B9D34 8FB3002C */  lw         $s3, 0x2C($sp)
    /* BA938 002B9D38 8FB20028 */  lw         $s2, 0x28($sp)
    /* BA93C 002B9D3C 8FB10024 */  lw         $s1, 0x24($sp)
    /* BA940 002B9D40 8FB00020 */  lw         $s0, 0x20($sp)
    /* BA944 002B9D44 03E00008 */  jr         $ra
    /* BA948 002B9D48 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel alEnvmixerPull
