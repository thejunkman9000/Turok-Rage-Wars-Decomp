.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6224-0xB6760 (VRAM 0x002B5624) */
glabel __voiceHandler
    /* B6224 002B5624 27BDFFB0 */  addiu      $sp, $sp, -0x50
    /* B6228 002B5628 F7B40048 */  sdc1       $fs0, 0x48($sp)
    /* B622C 002B562C 3C01800D */  lui        $at, %hi(D_800CC6A8)
    /* B6230 002B5630 C434C6A8 */  lwc1       $fs0, %lo(D_800CC6A8)($at)
    /* B6234 002B5634 AFB20030 */  sw         $s2, 0x30($sp)
    /* B6238 002B5638 00809021 */  addu       $s2, $a0, $zero
    /* B623C 002B563C AFB5003C */  sw         $s5, 0x3C($sp)
    /* B6240 002B5640 24150001 */  addiu      $s5, $zero, 0x1
    /* B6244 002B5644 AFBF0040 */  sw         $ra, 0x40($sp)
    /* B6248 002B5648 AFB40038 */  sw         $s4, 0x38($sp)
    /* B624C 002B564C AFB30034 */  sw         $s3, 0x34($sp)
    /* B6250 002B5650 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B6254 002B5654 AFB00028 */  sw         $s0, 0x28($sp)
  .L002B5658:
    /* B6258 002B5658 86430038 */  lh         $v1, 0x38($s2)
    /* B625C 002B565C 2C620018 */  sltiu      $v0, $v1, 0x18
    /* B6260 002B5660 1040012C */  beqz       $v0, .L002B5B14
    /* B6264 002B5664 00031080 */   sll       $v0, $v1, 2
    /* B6268 002B5668 3C01800D */  lui        $at, %hi(jtbl_800CC6B0)
    /* B626C 002B566C 00220821 */  addu       $at, $at, $v0
    /* B6270 002B5670 8C22C6B0 */  lw         $v0, %lo(jtbl_800CC6B0)($at)
    /* B6274 002B5674 00400008 */  jr         $v0
    /* B6278 002B5678 00000000 */   nop
    /* B627C 002B567C 0C0AD6D8 */  jal        __handleNextSeqEvent
    /* B6280 002B5680 02402021 */   addu      $a0, $s2, $zero
    /* B6284 002B5684 080AD6C6 */  j          .L002B5B18
    /* B6288 002B5688 26440048 */   addiu     $a0, $s2, 0x48
    /* B628C 002B568C 26440048 */  addiu      $a0, $s2, 0x48
    /* B6290 002B5690 24020009 */  addiu      $v0, $zero, 0x9
    /* B6294 002B5694 A7A20010 */  sh         $v0, 0x10($sp)
    /* B6298 002B5698 8E46005C */  lw         $a2, 0x5C($s2)
    /* B629C 002B569C 0C0AD469 */  jal        alEvtqPostEvent
    /* B62A0 002B56A0 27A50010 */   addiu     $a1, $sp, 0x10
    /* B62A4 002B56A4 080AD6C6 */  j          .L002B5B18
    /* B62A8 002B56A8 26440048 */   addiu     $a0, $s2, 0x48
    /* B62AC 002B56AC 8E50003C */  lw         $s0, 0x3C($s2)
    /* B62B0 002B56B0 8E440014 */  lw         $a0, 0x14($s2)
    /* B62B4 002B56B4 0C0AE1F0 */  jal        alSynStopVoice
    /* B62B8 002B56B8 02002821 */   addu      $a1, $s0, $zero
    /* B62BC 002B56BC 8E440014 */  lw         $a0, 0x14($s2)
    /* B62C0 002B56C0 0C0AE0B4 */  jal        alSynFreeVoice
    /* B62C4 002B56C4 02002821 */   addu      $a1, $s0, $zero
    /* B62C8 002B56C8 8E110010 */  lw         $s1, 0x10($s0)
    /* B62CC 002B56CC 92220037 */  lbu        $v0, 0x37($s1)
    /* B62D0 002B56D0 10400003 */  beqz       $v0, .L002B56E0
    /* B62D4 002B56D4 02402021 */   addu      $a0, $s2, $zero
    /* B62D8 002B56D8 0C0ADB41 */  jal        __seqpStopOsc
    /* B62DC 002B56DC 02202821 */   addu      $a1, $s1, $zero
  .L002B56E0:
    /* B62E0 002B56E0 02402021 */  addu       $a0, $s2, $zero
    /* B62E4 002B56E4 0C0AD98F */  jal        __unmapVoice
    /* B62E8 002B56E8 02002821 */   addu      $a1, $s0, $zero
    /* B62EC 002B56EC 080AD6C6 */  j          .L002B5B18
    /* B62F0 002B56F0 26440048 */   addiu     $a0, $s2, 0x48
    /* B62F4 002B56F4 8E50003C */  lw         $s0, 0x3C($s2)
    /* B62F8 002B56F8 8E110010 */  lw         $s1, 0x10($s0)
    /* B62FC 002B56FC 92220034 */  lbu        $v0, 0x34($s1)
    /* B6300 002B5700 14400002 */  bnez       $v0, .L002B570C
    /* B6304 002B5704 24020001 */   addiu     $v0, $zero, 0x1
    /* B6308 002B5708 A2220034 */  sb         $v0, 0x34($s1)
  .L002B570C:
    /* B630C 002B570C 8E530040 */  lw         $s3, 0x40($s2)
    /* B6310 002B5710 92420044 */  lbu        $v0, 0x44($s2)
    /* B6314 002B5714 02202021 */  addu       $a0, $s1, $zero
    /* B6318 002B5718 A0820030 */  sb         $v0, 0x30($a0)
    /* B631C 002B571C 8E42001C */  lw         $v0, 0x1C($s2)
    /* B6320 002B5720 02402821 */  addu       $a1, $s2, $zero
    /* B6324 002B5724 00531021 */  addu       $v0, $v0, $s3
    /* B6328 002B5728 0C0ADA39 */  jal        __vsVol
    /* B632C 002B572C AC820024 */   sw        $v0, 0x24($a0)
    /* B6330 002B5730 02002821 */  addu       $a1, $s0, $zero
    /* B6334 002B5734 00021400 */  sll        $v0, $v0, 16
    /* B6338 002B5738 00023403 */  sra        $a2, $v0, 16
    /* B633C 002B573C 8E440014 */  lw         $a0, 0x14($s2)
    /* B6340 002B5740 0C0AE154 */  jal        alSynSetVol
    /* B6344 002B5744 02603821 */   addu      $a3, $s3, $zero
    /* B6348 002B5748 080AD6C6 */  j          .L002B5B18
    /* B634C 002B574C 26440048 */   addiu     $a0, $s2, 0x48
    /* B6350 002B5750 27A50020 */  addiu      $a1, $sp, 0x20
    /* B6354 002B5754 8E51003C */  lw         $s1, 0x3C($s2)
    /* B6358 002B5758 8E540040 */  lw         $s4, 0x40($s2)
    /* B635C 002B575C 8E420074 */  lw         $v0, 0x74($s2)
    /* B6360 002B5760 0040F809 */  jalr       $v0
    /* B6364 002B5764 02802021 */   addu      $a0, $s4, $zero
    /* B6368 002B5768 00409821 */  addu       $s3, $v0, $zero
    /* B636C 002B576C C7A00020 */  lwc1       $fv0, 0x20($sp)
    /* B6370 002B5770 4600A03E */  c.le.s     $fs0, $fv0
    /* B6374 002B5774 00000000 */  nop
    /* B6378 002B5778 45010005 */  bc1t       .L002B5790
    /* B637C 002B577C 26260036 */   addiu     $a2, $s1, 0x36
    /* B6380 002B5780 4600008D */  trunc.w.s  $fv1, $fv0
    /* B6384 002B5784 44031000 */  mfc1       $v1, $fv1
    /* B6388 002B5788 080AD5EA */  j          .L002B57A8
    /* B638C 002B578C 02202021 */   addu      $a0, $s1, $zero
  .L002B5790:
    /* B6390 002B5790 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* B6394 002B5794 3C028000 */  lui        $v0, (0x80000000 >> 16)
    /* B6398 002B5798 4600008D */  trunc.w.s  $fv1, $fv0
    /* B639C 002B579C 44031000 */  mfc1       $v1, $fv1
    /* B63A0 002B57A0 00621825 */  or         $v1, $v1, $v0
    /* B63A4 002B57A4 02202021 */  addu       $a0, $s1, $zero
  .L002B57A8:
    /* B63A8 002B57A8 02402821 */  addu       $a1, $s2, $zero
    /* B63AC 002B57AC 0C0ADA39 */  jal        __vsVol
    /* B63B0 002B57B0 A0C30000 */   sb        $v1, 0x0($a2)
    /* B63B4 002B57B4 02202021 */  addu       $a0, $s1, $zero
    /* B63B8 002B57B8 00028400 */  sll        $s0, $v0, 16
    /* B63BC 002B57BC 8E45001C */  lw         $a1, 0x1C($s2)
    /* B63C0 002B57C0 0C0ADA56 */  jal        __vsDelta
    /* B63C4 002B57C4 00108403 */   sra       $s0, $s0, 16
    /* B63C8 002B57C8 26250004 */  addiu      $a1, $s1, 0x4
    /* B63CC 002B57CC 02003021 */  addu       $a2, $s0, $zero
    /* B63D0 002B57D0 8E440014 */  lw         $a0, 0x14($s2)
    /* B63D4 002B57D4 0C0AE154 */  jal        alSynSetVol
    /* B63D8 002B57D8 00403821 */   addu      $a3, $v0, $zero
    /* B63DC 002B57DC 26440048 */  addiu      $a0, $s2, 0x48
    /* B63E0 002B57E0 27A50010 */  addiu      $a1, $sp, 0x10
    /* B63E4 002B57E4 02603021 */  addu       $a2, $s3, $zero
    /* B63E8 002B57E8 24020016 */  addiu      $v0, $zero, 0x16
    /* B63EC 002B57EC A7A20010 */  sh         $v0, 0x10($sp)
    /* B63F0 002B57F0 AFB10014 */  sw         $s1, 0x14($sp)
    /* B63F4 002B57F4 0C0AD469 */  jal        alEvtqPostEvent
    /* B63F8 002B57F8 AFB40018 */   sw        $s4, 0x18($sp)
    /* B63FC 002B57FC 080AD6C6 */  j          .L002B5B18
    /* B6400 002B5800 26440048 */   addiu     $a0, $s2, 0x48
    /* B6404 002B5804 27A50020 */  addiu      $a1, $sp, 0x20
    /* B6408 002B5808 8E540040 */  lw         $s4, 0x40($s2)
    /* B640C 002B580C 8E51003C */  lw         $s1, 0x3C($s2)
    /* B6410 002B5810 8E420074 */  lw         $v0, 0x74($s2)
    /* B6414 002B5814 92500044 */  lbu        $s0, 0x44($s2)
    /* B6418 002B5818 0040F809 */  jalr       $v0
    /* B641C 002B581C 02802021 */   addu      $a0, $s4, $zero
    /* B6420 002B5820 C7A00020 */  lwc1       $fv0, 0x20($sp)
    /* B6424 002B5824 C6210028 */  lwc1       $fv0f, 0x28($s1)
    /* B6428 002B5828 320300FF */  andi       $v1, $s0, 0xFF
    /* B642C 002B582C 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B6430 002B5830 E620002C */  swc1       $fv0, 0x2C($s1)
    /* B6434 002B5834 8E440060 */  lw         $a0, 0x60($s2)
    /* B6438 002B5838 00031900 */  sll        $v1, $v1, 4
    /* B643C 002B583C 00641821 */  addu       $v1, $v1, $a0
    /* B6440 002B5840 C460000C */  lwc1       $fv0, 0xC($v1)
    /* B6444 002B5844 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B6448 002B5848 00409821 */  addu       $s3, $v0, $zero
    /* B644C 002B584C 8E440014 */  lw         $a0, 0x14($s2)
    /* B6450 002B5850 44060800 */  mfc1       $a2, $fv0f
    /* B6454 002B5854 0C0AE12C */  jal        alSynSetPitch
    /* B6458 002B5858 26250004 */   addiu     $a1, $s1, 0x4
    /* B645C 002B585C 26440048 */  addiu      $a0, $s2, 0x48
    /* B6460 002B5860 27A50010 */  addiu      $a1, $sp, 0x10
    /* B6464 002B5864 02603021 */  addu       $a2, $s3, $zero
    /* B6468 002B5868 24020017 */  addiu      $v0, $zero, 0x17
    /* B646C 002B586C A7A20010 */  sh         $v0, 0x10($sp)
    /* B6470 002B5870 AFB10014 */  sw         $s1, 0x14($sp)
    /* B6474 002B5874 AFB40018 */  sw         $s4, 0x18($sp)
    /* B6478 002B5878 0C0AD469 */  jal        alEvtqPostEvent
    /* B647C 002B587C A3B0001C */   sb        $s0, 0x1C($sp)
    /* B6480 002B5880 080AD6C6 */  j          .L002B5B18
    /* B6484 002B5884 26440048 */   addiu     $a0, $s2, 0x48
    /* B6488 002B5888 02402021 */  addu       $a0, $s2, $zero
    /* B648C 002B588C 0C0AD759 */  jal        __handleMIDIMsg
    /* B6490 002B5890 26450038 */   addiu     $a1, $s2, 0x38
    /* B6494 002B5894 080AD6C6 */  j          .L002B5B18
    /* B6498 002B5898 26440048 */   addiu     $a0, $s2, 0x48
    /* B649C 002B589C 02402021 */  addu       $a0, $s2, $zero
    /* B64A0 002B58A0 0C0ADBAF */  jal        __handleMetaMsg
    /* B64A4 002B58A4 26450038 */   addiu     $a1, $s2, 0x38
    /* B64A8 002B58A8 080AD6C6 */  j          .L002B5B18
    /* B64AC 002B58AC 26440048 */   addiu     $a0, $s2, 0x48
    /* B64B0 002B58B0 8E42002C */  lw         $v0, 0x2C($s2)
    /* B64B4 002B58B4 10550098 */  beq        $v0, $s5, .L002B5B18
    /* B64B8 002B58B8 26440048 */   addiu     $a0, $s2, 0x48
    /* B64BC 002B58BC AE55002C */  sw         $s5, 0x2C($s2)
    /* B64C0 002B58C0 0C0ADB7D */  jal        __postNextSeqEvent
    /* B64C4 002B58C4 02402021 */   addu      $a0, $s2, $zero
    /* B64C8 002B58C8 080AD6C6 */  j          .L002B5B18
    /* B64CC 002B58CC 26440048 */   addiu     $a0, $s2, 0x48
    /* B64D0 002B58D0 8E43002C */  lw         $v1, 0x2C($s2)
    /* B64D4 002B58D4 24020002 */  addiu      $v0, $zero, 0x2
    /* B64D8 002B58D8 1462008F */  bne        $v1, $v0, .L002B5B18
    /* B64DC 002B58DC 26440048 */   addiu     $a0, $s2, 0x48
    /* B64E0 002B58E0 8E510064 */  lw         $s1, 0x64($s2)
    /* B64E4 002B58E4 52200014 */  beql       $s1, $zero, .L002B5938
    /* B64E8 002B58E8 AE40001C */   sw        $zero, 0x1C($s2)
    /* B64EC 002B58EC 26300004 */  addiu      $s0, $s1, 0x4
  .L002B58F0:
    /* B64F0 002B58F0 8E440014 */  lw         $a0, 0x14($s2)
    /* B64F4 002B58F4 0C0AE1F0 */  jal        alSynStopVoice
    /* B64F8 002B58F8 02002821 */   addu      $a1, $s0, $zero
    /* B64FC 002B58FC 8E440014 */  lw         $a0, 0x14($s2)
    /* B6500 002B5900 0C0AE0B4 */  jal        alSynFreeVoice
    /* B6504 002B5904 02002821 */   addu      $a1, $s0, $zero
    /* B6508 002B5908 92220037 */  lbu        $v0, 0x37($s1)
    /* B650C 002B590C 10400003 */  beqz       $v0, .L002B591C
    /* B6510 002B5910 02402021 */   addu      $a0, $s2, $zero
    /* B6514 002B5914 0C0ADB41 */  jal        __seqpStopOsc
    /* B6518 002B5918 02202821 */   addu      $a1, $s1, $zero
  .L002B591C:
    /* B651C 002B591C 02402021 */  addu       $a0, $s2, $zero
    /* B6520 002B5920 0C0AD98F */  jal        __unmapVoice
    /* B6524 002B5924 02002821 */   addu      $a1, $s0, $zero
    /* B6528 002B5928 8E510064 */  lw         $s1, 0x64($s2)
    /* B652C 002B592C 1620FFF0 */  bnez       $s1, .L002B58F0
    /* B6530 002B5930 26300004 */   addiu     $s0, $s1, 0x4
    /* B6534 002B5934 AE40001C */  sw         $zero, 0x1C($s2)
  .L002B5938:
    /* B6538 002B5938 080AD6C5 */  j          .L002B5B14
    /* B653C 002B593C AE40002C */   sw        $zero, 0x2C($s2)
    /* B6540 002B5940 8E42002C */  lw         $v0, 0x2C($s2)
    /* B6544 002B5944 14550074 */  bne        $v0, $s5, .L002B5B18
    /* B6548 002B5948 26440048 */   addiu     $a0, $s2, 0x48
    /* B654C 002B594C 26500048 */  addiu      $s0, $s2, 0x48
    /* B6550 002B5950 02002021 */  addu       $a0, $s0, $zero
    /* B6554 002B5954 0C0AD4CA */  jal        alEvtqFlushType
    /* B6558 002B5958 00002821 */   addu      $a1, $zero, $zero
    /* B655C 002B595C 02002021 */  addu       $a0, $s0, $zero
    /* B6560 002B5960 0C0AD4CA */  jal        alEvtqFlushType
    /* B6564 002B5964 24050002 */   addiu     $a1, $zero, 0x2
    /* B6568 002B5968 8E510064 */  lw         $s1, 0x64($s2)
    /* B656C 002B596C 12200010 */  beqz       $s1, .L002B59B0
    /* B6570 002B5970 26440048 */   addiu     $a0, $s2, 0x48
    /* B6574 002B5974 02402021 */  addu       $a0, $s2, $zero
  .L002B5978:
    /* B6578 002B5978 26300004 */  addiu      $s0, $s1, 0x4
    /* B657C 002B597C 02002821 */  addu       $a1, $s0, $zero
    /* B6580 002B5980 0C0AD9A8 */  jal        __voiceNeedsNoteKillOff
    /* B6584 002B5984 3406C350 */   ori       $a2, $zero, 0xC350
    /* B6588 002B5988 304200FF */  andi       $v0, $v0, 0xFF
    /* B658C 002B598C 10400004 */  beqz       $v0, .L002B59A0
    /* B6590 002B5990 02402021 */   addu      $a0, $s2, $zero
    /* B6594 002B5994 02002821 */  addu       $a1, $s0, $zero
    /* B6598 002B5998 0C0ADAF9 */  jal        __seqpReleaseVoice
    /* B659C 002B599C 3406C350 */   ori       $a2, $zero, 0xC350
  .L002B59A0:
    /* B65A0 002B59A0 8E310000 */  lw         $s1, 0x0($s1)
    /* B65A4 002B59A4 1620FFF4 */  bnez       $s1, .L002B5978
    /* B65A8 002B59A8 02402021 */   addu      $a0, $s2, $zero
    /* B65AC 002B59AC 26440048 */  addiu      $a0, $s2, 0x48
  .L002B59B0:
    /* B65B0 002B59B0 27A50010 */  addiu      $a1, $sp, 0x10
    /* B65B4 002B59B4 3C067FFF */  lui        $a2, (0x7FFFFFFF >> 16)
    /* B65B8 002B59B8 34C6FFFF */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
    /* B65BC 002B59BC 24020002 */  addiu      $v0, $zero, 0x2
    /* B65C0 002B59C0 AE42002C */  sw         $v0, 0x2C($s2)
    /* B65C4 002B59C4 24020010 */  addiu      $v0, $zero, 0x10
    /* B65C8 002B59C8 0C0AD469 */  jal        alEvtqPostEvent
    /* B65CC 002B59CC A7A20010 */   sh        $v0, 0x10($sp)
    /* B65D0 002B59D0 080AD6C6 */  j          .L002B5B18
    /* B65D4 002B59D4 26440048 */   addiu     $a0, $s2, 0x48
    /* B65D8 002B59D8 9642003C */  lhu        $v0, 0x3C($s2)
    /* B65DC 002B59DC 8E510064 */  lw         $s1, 0x64($s2)
    /* B65E0 002B59E0 1220004C */  beqz       $s1, .L002B5B14
    /* B65E4 002B59E4 A6420032 */   sh        $v0, 0x32($s2)
    /* B65E8 002B59E8 02202021 */  addu       $a0, $s1, $zero
  .L002B59EC:
    /* B65EC 002B59EC 0C0ADA39 */  jal        __vsVol
    /* B65F0 002B59F0 02402821 */   addu      $a1, $s2, $zero
    /* B65F4 002B59F4 02202021 */  addu       $a0, $s1, $zero
    /* B65F8 002B59F8 00028400 */  sll        $s0, $v0, 16
    /* B65FC 002B59FC 8E45001C */  lw         $a1, 0x1C($s2)
    /* B6600 002B5A00 0C0ADA56 */  jal        __vsDelta
    /* B6604 002B5A04 00108403 */   sra       $s0, $s0, 16
    /* B6608 002B5A08 26250004 */  addiu      $a1, $s1, 0x4
    /* B660C 002B5A0C 02003021 */  addu       $a2, $s0, $zero
    /* B6610 002B5A10 8E440014 */  lw         $a0, 0x14($s2)
    /* B6614 002B5A14 0C0AE154 */  jal        alSynSetVol
    /* B6618 002B5A18 00403821 */   addu      $a3, $v0, $zero
    /* B661C 002B5A1C 8E310000 */  lw         $s1, 0x0($s1)
    /* B6620 002B5A20 1620FFF2 */  bnez       $s1, .L002B59EC
    /* B6624 002B5A24 02202021 */   addu      $a0, $s1, $zero
    /* B6628 002B5A28 080AD6C6 */  j          .L002B5B18
    /* B662C 002B5A2C 26440048 */   addiu     $a0, $s2, 0x48
    /* B6630 002B5A30 8E42003C */  lw         $v0, 0x3C($s2)
    /* B6634 002B5A34 8E430040 */  lw         $v1, 0x40($s2)
    /* B6638 002B5A38 8E440044 */  lw         $a0, 0x44($s2)
    /* B663C 002B5A3C AE42007C */  sw         $v0, 0x7C($s2)
    /* B6640 002B5A40 AE430080 */  sw         $v1, 0x80($s2)
    /* B6644 002B5A44 080AD6C5 */  j          .L002B5B14
    /* B6648 002B5A48 AE440084 */   sw        $a0, 0x84($s2)
    /* B664C 002B5A4C 9242003C */  lbu        $v0, 0x3C($s2)
    /* B6650 002B5A50 8E430060 */  lw         $v1, 0x60($s2)
    /* B6654 002B5A54 9244003D */  lbu        $a0, 0x3D($s2)
    /* B6658 002B5A58 00021100 */  sll        $v0, $v0, 4
    /* B665C 002B5A5C 00431021 */  addu       $v0, $v0, $v1
    /* B6660 002B5A60 080AD6C5 */  j          .L002B5B14
    /* B6664 002B5A64 A0440008 */   sb        $a0, 0x8($v0)
    /* B6668 002B5A68 8E42002C */  lw         $v0, 0x2C($s2)
    /* B666C 002B5A6C 14550007 */  bne        $v0, $s5, .L002B5A8C
    /* B6670 002B5A70 00000000 */   nop
    /* B6674 002B5A74 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B6678 002B5A78 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B667C 002B5A7C 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B6680 002B5A80 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B6684 002B5A84 0C0AFF50 */  jal        __assert
    /* B6688 002B5A88 24060128 */   addiu     $a2, $zero, 0x128
  .L002B5A8C:
    /* B668C 002B5A8C 3C0548F4 */  lui        $a1, (0x48F42400 >> 16)
    /* B6690 002B5A90 34A52400 */  ori        $a1, $a1, (0x48F42400 & 0xFFFF)
    /* B6694 002B5A94 8E42003C */  lw         $v0, 0x3C($s2)
    /* B6698 002B5A98 02402021 */  addu       $a0, $s2, $zero
    /* B669C 002B5A9C 0C0ADBC8 */  jal        __setUsptFromTempo
    /* B66A0 002B5AA0 AE420018 */   sw        $v0, 0x18($s2)
    /* B66A4 002B5AA4 8E450020 */  lw         $a1, 0x20($s2)
    /* B66A8 002B5AA8 10A0001B */  beqz       $a1, .L002B5B18
    /* B66AC 002B5AAC 26440048 */   addiu     $a0, $s2, 0x48
    /* B66B0 002B5AB0 0C0ADA6D */  jal        __initFromBank
    /* B66B4 002B5AB4 02402021 */   addu      $a0, $s2, $zero
    /* B66B8 002B5AB8 080AD6C6 */  j          .L002B5B18
    /* B66BC 002B5ABC 26440048 */   addiu     $a0, $s2, 0x48
    /* B66C0 002B5AC0 8E42002C */  lw         $v0, 0x2C($s2)
    /* B66C4 002B5AC4 10400007 */  beqz       $v0, .L002B5AE4
    /* B66C8 002B5AC8 00000000 */   nop
    /* B66CC 002B5ACC 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B66D0 002B5AD0 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B66D4 002B5AD4 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B66D8 002B5AD8 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B66DC 002B5ADC 0C0AFF50 */  jal        __assert
    /* B66E0 002B5AE0 24060131 */   addiu     $a2, $zero, 0x131
  .L002B5AE4:
    /* B66E4 002B5AE4 8E45003C */  lw         $a1, 0x3C($s2)
    /* B66E8 002B5AE8 02402021 */  addu       $a0, $s2, $zero
    /* B66EC 002B5AEC 0C0ADA6D */  jal        __initFromBank
    /* B66F0 002B5AF0 AE450020 */   sw        $a1, 0x20($s2)
    /* B66F4 002B5AF4 080AD6C6 */  j          .L002B5B18
    /* B66F8 002B5AF8 26440048 */   addiu     $a0, $s2, 0x48
    /* B66FC 002B5AFC 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B6700 002B5B00 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B6704 002B5B04 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B6708 002B5B08 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B670C 002B5B0C 0C0AFF50 */  jal        __assert
    /* B6710 002B5B10 2406013B */   addiu     $a2, $zero, 0x13B
  .L002B5B14:
    /* B6714 002B5B14 26440048 */  addiu      $a0, $s2, 0x48
  .L002B5B18:
    /* B6718 002B5B18 0C0AD443 */  jal        alEvtqNextEvent
    /* B671C 002B5B1C 26450038 */   addiu     $a1, $s2, 0x38
    /* B6720 002B5B20 00402021 */  addu       $a0, $v0, $zero
    /* B6724 002B5B24 1080FECC */  beqz       $a0, .L002B5658
    /* B6728 002B5B28 AE440028 */   sw        $a0, 0x28($s2)
    /* B672C 002B5B2C 8E43001C */  lw         $v1, 0x1C($s2)
    /* B6730 002B5B30 00641821 */  addu       $v1, $v1, $a0
    /* B6734 002B5B34 AE43001C */  sw         $v1, 0x1C($s2)
    /* B6738 002B5B38 8FBF0040 */  lw         $ra, 0x40($sp)
    /* B673C 002B5B3C 8FB5003C */  lw         $s5, 0x3C($sp)
    /* B6740 002B5B40 8FB40038 */  lw         $s4, 0x38($sp)
    /* B6744 002B5B44 8FB30034 */  lw         $s3, 0x34($sp)
    /* B6748 002B5B48 8FB20030 */  lw         $s2, 0x30($sp)
    /* B674C 002B5B4C 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B6750 002B5B50 8FB00028 */  lw         $s0, 0x28($sp)
    /* B6754 002B5B54 D7B40048 */  ldc1       $fs0, 0x48($sp)
    /* B6758 002B5B58 03E00008 */  jr         $ra
    /* B675C 002B5B5C 27BD0050 */   addiu     $sp, $sp, 0x50
endlabel __voiceHandler
