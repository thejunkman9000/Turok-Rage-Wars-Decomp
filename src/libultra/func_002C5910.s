.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC6510-0xC6A90 (VRAM 0x002C5910) */
glabel func_002C5910
    /* C6510 002C5910 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C6514 002C5914 AFB20010 */  sw         $s2, 0x10($sp)
    /* C6518 002C5918 00009021 */  addu       $s2, $zero, $zero
    /* C651C 002C591C AFB1000C */  sw         $s1, 0xC($sp)
    /* C6520 002C5920 04810008 */  bgez       $a0, .L002C5944
    /* C6524 002C5924 AFB00008 */   sw        $s0, 0x8($sp)
    /* C6528 002C5928 2412FFFF */  addiu      $s2, $zero, -0x1
    /* C652C 002C592C 00054823 */  negu       $t1, $a1
    /* C6530 002C5930 00041823 */  negu       $v1, $a0
    /* C6534 002C5934 0009102B */  sltu       $v0, $zero, $t1
    /* C6538 002C5938 00624023 */  subu       $t0, $v1, $v0
    /* C653C 002C593C 01002021 */  addu       $a0, $t0, $zero
    /* C6540 002C5940 01202821 */  addu       $a1, $t1, $zero
  .L002C5944:
    /* C6544 002C5944 04C10008 */  bgez       $a2, .L002C5968
    /* C6548 002C5948 00E04021 */   addu      $t0, $a3, $zero
    /* C654C 002C594C 00075823 */  negu       $t3, $a3
    /* C6550 002C5950 00061823 */  negu       $v1, $a2
    /* C6554 002C5954 000B102B */  sltu       $v0, $zero, $t3
    /* C6558 002C5958 00625023 */  subu       $t2, $v1, $v0
    /* C655C 002C595C 01403021 */  addu       $a2, $t2, $zero
    /* C6560 002C5960 01603821 */  addu       $a3, $t3, $zero
    /* C6564 002C5964 00E04021 */  addu       $t0, $a3, $zero
  .L002C5968:
    /* C6568 002C5968 00C04821 */  addu       $t1, $a2, $zero
    /* C656C 002C596C 00A05821 */  addu       $t3, $a1, $zero
    /* C6570 002C5970 00805021 */  addu       $t2, $a0, $zero
    /* C6574 002C5974 152000AD */  bnez       $t1, .L002C5C2C
    /* C6578 002C5978 03A0C821 */   addu      $t9, $sp, $zero
    /* C657C 002C597C 0148102B */  sltu       $v0, $t2, $t0
    /* C6580 002C5980 1040001E */  beqz       $v0, .L002C59FC
    /* C6584 002C5984 3402FFFF */   ori       $v0, $zero, 0xFFFF
    /* C6588 002C5988 0048102B */  sltu       $v0, $v0, $t0
    /* C658C 002C598C 14400005 */  bnez       $v0, .L002C59A4
    /* C6590 002C5990 00E01821 */   addu      $v1, $a3, $zero
    /* C6594 002C5994 2D020100 */  sltiu      $v0, $t0, 0x100
    /* C6598 002C5998 38420001 */  xori       $v0, $v0, 0x1
    /* C659C 002C599C 080B166F */  j          .L002C59BC
    /* C65A0 002C59A0 000220C0 */   sll       $a0, $v0, 3
  .L002C59A4:
    /* C65A4 002C59A4 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C65A8 002C59A8 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C65AC 002C59AC 0048102B */  sltu       $v0, $v0, $t0
    /* C65B0 002C59B0 14400002 */  bnez       $v0, .L002C59BC
    /* C65B4 002C59B4 24040018 */   addiu     $a0, $zero, 0x18
    /* C65B8 002C59B8 24040010 */  addiu      $a0, $zero, 0x10
  .L002C59BC:
    /* C65BC 002C59BC 3C02800D */  lui        $v0, %hi(D_800CD050)
    /* C65C0 002C59C0 2442D050 */  addiu      $v0, $v0, %lo(D_800CD050)
    /* C65C4 002C59C4 00831806 */  srlv       $v1, $v1, $a0
    /* C65C8 002C59C8 00621821 */  addu       $v1, $v1, $v0
    /* C65CC 002C59CC 90620000 */  lbu        $v0, 0x0($v1)
    /* C65D0 002C59D0 00441021 */  addu       $v0, $v0, $a0
    /* C65D4 002C59D4 24040020 */  addiu      $a0, $zero, 0x20
    /* C65D8 002C59D8 00826823 */  subu       $t5, $a0, $v0
    /* C65DC 002C59DC 11A0005F */  beqz       $t5, .L002C5B5C
    /* C65E0 002C59E0 01AA1804 */   sllv      $v1, $t2, $t5
    /* C65E4 002C59E4 01A84004 */  sllv       $t0, $t0, $t5
    /* C65E8 002C59E8 008D1023 */  subu       $v0, $a0, $t5
    /* C65EC 002C59EC 004B1006 */  srlv       $v0, $t3, $v0
    /* C65F0 002C59F0 00625025 */  or         $t2, $v1, $v0
    /* C65F4 002C59F4 080B16D7 */  j          .L002C5B5C
    /* C65F8 002C59F8 01AB5804 */   sllv      $t3, $t3, $t5
  .L002C59FC:
    /* C65FC 002C59FC 15000009 */  bnez       $t0, .L002C5A24
    /* C6600 002C5A00 0048102B */   sltu      $v0, $v0, $t0
    /* C6604 002C5A04 24020001 */  addiu      $v0, $zero, 0x1
    /* C6608 002C5A08 0049001B */  divu       $zero, $v0, $t1
    /* C660C 002C5A0C 15200002 */  bnez       $t1, .L002C5A18
    /* C6610 002C5A10 00000000 */   nop
    /* C6614 002C5A14 0007000D */  break      7
  .L002C5A18:
    /* C6618 002C5A18 00004012 */  mflo       $t0
    /* C661C 002C5A1C 3402FFFF */  ori        $v0, $zero, 0xFFFF
    /* C6620 002C5A20 0048102B */  sltu       $v0, $v0, $t0
  .L002C5A24:
    /* C6624 002C5A24 14400005 */  bnez       $v0, .L002C5A3C
    /* C6628 002C5A28 01001821 */   addu      $v1, $t0, $zero
    /* C662C 002C5A2C 2D020100 */  sltiu      $v0, $t0, 0x100
    /* C6630 002C5A30 38420001 */  xori       $v0, $v0, 0x1
    /* C6634 002C5A34 080B1695 */  j          .L002C5A54
    /* C6638 002C5A38 000220C0 */   sll       $a0, $v0, 3
  .L002C5A3C:
    /* C663C 002C5A3C 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C6640 002C5A40 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C6644 002C5A44 0048102B */  sltu       $v0, $v0, $t0
    /* C6648 002C5A48 14400002 */  bnez       $v0, .L002C5A54
    /* C664C 002C5A4C 24040018 */   addiu     $a0, $zero, 0x18
    /* C6650 002C5A50 24040010 */  addiu      $a0, $zero, 0x10
  .L002C5A54:
    /* C6654 002C5A54 3C02800D */  lui        $v0, %hi(D_800CD050)
    /* C6658 002C5A58 2442D050 */  addiu      $v0, $v0, %lo(D_800CD050)
    /* C665C 002C5A5C 00831806 */  srlv       $v1, $v1, $a0
    /* C6660 002C5A60 00621821 */  addu       $v1, $v1, $v0
    /* C6664 002C5A64 90620000 */  lbu        $v0, 0x0($v1)
    /* C6668 002C5A68 24030020 */  addiu      $v1, $zero, 0x20
    /* C666C 002C5A6C 00441021 */  addu       $v0, $v0, $a0
    /* C6670 002C5A70 00626823 */  subu       $t5, $v1, $v0
    /* C6674 002C5A74 15A00003 */  bnez       $t5, .L002C5A84
    /* C6678 002C5A78 006DC023 */   subu      $t8, $v1, $t5
    /* C667C 002C5A7C 080B16D7 */  j          .L002C5B5C
    /* C6680 002C5A80 01485023 */   subu      $t2, $t2, $t0
  .L002C5A84:
    /* C6684 002C5A84 01A84004 */  sllv       $t0, $t0, $t5
    /* C6688 002C5A88 030A2006 */  srlv       $a0, $t2, $t8
    /* C668C 002C5A8C 01AA1804 */  sllv       $v1, $t2, $t5
    /* C6690 002C5A90 030B1006 */  srlv       $v0, $t3, $t8
    /* C6694 002C5A94 00625025 */  or         $t2, $v1, $v0
    /* C6698 002C5A98 00082C02 */  srl        $a1, $t0, 16
    /* C669C 002C5A9C 0085001B */  divu       $zero, $a0, $a1
    /* C66A0 002C5AA0 14A00002 */  bnez       $a1, .L002C5AAC
    /* C66A4 002C5AA4 00000000 */   nop
    /* C66A8 002C5AA8 0007000D */  break      7
  .L002C5AAC:
    /* C66AC 002C5AAC 00001012 */  mflo       $v0
    /* C66B0 002C5AB0 00001810 */  mfhi       $v1
    /* C66B4 002C5AB4 3106FFFF */  andi       $a2, $t0, 0xFFFF
    /* C66B8 002C5AB8 00000000 */  nop
    /* C66BC 002C5ABC 00460018 */  mult       $v0, $a2
    /* C66C0 002C5AC0 00031C00 */  sll        $v1, $v1, 16
    /* C66C4 002C5AC4 000A1402 */  srl        $v0, $t2, 16
    /* C66C8 002C5AC8 00621825 */  or         $v1, $v1, $v0
    /* C66CC 002C5ACC 00002012 */  mflo       $a0
    /* C66D0 002C5AD0 0064102B */  sltu       $v0, $v1, $a0
    /* C66D4 002C5AD4 10400008 */  beqz       $v0, .L002C5AF8
    /* C66D8 002C5AD8 01AB5804 */   sllv      $t3, $t3, $t5
    /* C66DC 002C5ADC 00681821 */  addu       $v1, $v1, $t0
    /* C66E0 002C5AE0 0068102B */  sltu       $v0, $v1, $t0
    /* C66E4 002C5AE4 54400005 */  bnel       $v0, $zero, .L002C5AFC
    /* C66E8 002C5AE8 00641823 */   subu      $v1, $v1, $a0
    /* C66EC 002C5AEC 0064102B */  sltu       $v0, $v1, $a0
    /* C66F0 002C5AF0 54400001 */  bnel       $v0, $zero, .L002C5AF8
    /* C66F4 002C5AF4 00681821 */   addu      $v1, $v1, $t0
  .L002C5AF8:
    /* C66F8 002C5AF8 00641823 */  subu       $v1, $v1, $a0
  .L002C5AFC:
    /* C66FC 002C5AFC 0065001B */  divu       $zero, $v1, $a1
    /* C6700 002C5B00 14A00002 */  bnez       $a1, .L002C5B0C
    /* C6704 002C5B04 00000000 */   nop
    /* C6708 002C5B08 0007000D */  break      7
  .L002C5B0C:
    /* C670C 002C5B0C 00001012 */  mflo       $v0
    /* C6710 002C5B10 00001810 */  mfhi       $v1
    /* C6714 002C5B14 00000000 */  nop
    /* C6718 002C5B18 00000000 */  nop
    /* C671C 002C5B1C 00460018 */  mult       $v0, $a2
    /* C6720 002C5B20 00031C00 */  sll        $v1, $v1, 16
    /* C6724 002C5B24 3142FFFF */  andi       $v0, $t2, 0xFFFF
    /* C6728 002C5B28 00621825 */  or         $v1, $v1, $v0
    /* C672C 002C5B2C 00002012 */  mflo       $a0
    /* C6730 002C5B30 0064102B */  sltu       $v0, $v1, $a0
    /* C6734 002C5B34 50400009 */  beql       $v0, $zero, .L002C5B5C
    /* C6738 002C5B38 00645023 */   subu      $t2, $v1, $a0
    /* C673C 002C5B3C 00681821 */  addu       $v1, $v1, $t0
    /* C6740 002C5B40 0068102B */  sltu       $v0, $v1, $t0
    /* C6744 002C5B44 14400005 */  bnez       $v0, .L002C5B5C
    /* C6748 002C5B48 00645023 */   subu      $t2, $v1, $a0
    /* C674C 002C5B4C 0064102B */  sltu       $v0, $v1, $a0
    /* C6750 002C5B50 54400001 */  bnel       $v0, $zero, .L002C5B58
    /* C6754 002C5B54 00681821 */   addu      $v1, $v1, $t0
  .L002C5B58:
    /* C6758 002C5B58 00645023 */  subu       $t2, $v1, $a0
  .L002C5B5C:
    /* C675C 002C5B5C 00082C02 */  srl        $a1, $t0, 16
    /* C6760 002C5B60 0145001B */  divu       $zero, $t2, $a1
    /* C6764 002C5B64 14A00002 */  bnez       $a1, .L002C5B70
    /* C6768 002C5B68 00000000 */   nop
    /* C676C 002C5B6C 0007000D */  break      7
  .L002C5B70:
    /* C6770 002C5B70 00001012 */  mflo       $v0
    /* C6774 002C5B74 00001810 */  mfhi       $v1
    /* C6778 002C5B78 3106FFFF */  andi       $a2, $t0, 0xFFFF
    /* C677C 002C5B7C 00000000 */  nop
    /* C6780 002C5B80 00460018 */  mult       $v0, $a2
    /* C6784 002C5B84 00031C00 */  sll        $v1, $v1, 16
    /* C6788 002C5B88 000B1402 */  srl        $v0, $t3, 16
    /* C678C 002C5B8C 00621825 */  or         $v1, $v1, $v0
    /* C6790 002C5B90 00002012 */  mflo       $a0
    /* C6794 002C5B94 0064102B */  sltu       $v0, $v1, $a0
    /* C6798 002C5B98 50400009 */  beql       $v0, $zero, .L002C5BC0
    /* C679C 002C5B9C 00641823 */   subu      $v1, $v1, $a0
    /* C67A0 002C5BA0 00681821 */  addu       $v1, $v1, $t0
    /* C67A4 002C5BA4 0068102B */  sltu       $v0, $v1, $t0
    /* C67A8 002C5BA8 54400005 */  bnel       $v0, $zero, .L002C5BC0
    /* C67AC 002C5BAC 00641823 */   subu      $v1, $v1, $a0
    /* C67B0 002C5BB0 0064102B */  sltu       $v0, $v1, $a0
    /* C67B4 002C5BB4 54400001 */  bnel       $v0, $zero, .L002C5BBC
    /* C67B8 002C5BB8 00681821 */   addu      $v1, $v1, $t0
  .L002C5BBC:
    /* C67BC 002C5BBC 00641823 */  subu       $v1, $v1, $a0
  .L002C5BC0:
    /* C67C0 002C5BC0 0065001B */  divu       $zero, $v1, $a1
    /* C67C4 002C5BC4 14A00002 */  bnez       $a1, .L002C5BD0
    /* C67C8 002C5BC8 00000000 */   nop
    /* C67CC 002C5BCC 0007000D */  break      7
  .L002C5BD0:
    /* C67D0 002C5BD0 00001012 */  mflo       $v0
    /* C67D4 002C5BD4 00001810 */  mfhi       $v1
    /* C67D8 002C5BD8 00000000 */  nop
    /* C67DC 002C5BDC 00000000 */  nop
    /* C67E0 002C5BE0 00460018 */  mult       $v0, $a2
    /* C67E4 002C5BE4 00031C00 */  sll        $v1, $v1, 16
    /* C67E8 002C5BE8 3162FFFF */  andi       $v0, $t3, 0xFFFF
    /* C67EC 002C5BEC 00621825 */  or         $v1, $v1, $v0
    /* C67F0 002C5BF0 00002012 */  mflo       $a0
    /* C67F4 002C5BF4 0064102B */  sltu       $v0, $v1, $a0
    /* C67F8 002C5BF8 10400007 */  beqz       $v0, .L002C5C18
    /* C67FC 002C5BFC 00000000 */   nop
    /* C6800 002C5C00 00681821 */  addu       $v1, $v1, $t0
    /* C6804 002C5C04 0068102B */  sltu       $v0, $v1, $t0
    /* C6808 002C5C08 14400003 */  bnez       $v0, .L002C5C18
    /* C680C 002C5C0C 0064102B */   sltu      $v0, $v1, $a0
    /* C6810 002C5C10 54400001 */  bnel       $v0, $zero, .L002C5C18
    /* C6814 002C5C14 00681821 */   addu      $v1, $v1, $t0
  .L002C5C18:
    /* C6818 002C5C18 1320008A */  beqz       $t9, .L002C5E44
    /* C681C 002C5C1C 00645823 */   subu      $t3, $v1, $a0
    /* C6820 002C5C20 01AB7806 */  srlv       $t7, $t3, $t5
    /* C6824 002C5C24 080B178F */  j          .L002C5E3C
    /* C6828 002C5C28 00007021 */   addu      $t6, $zero, $zero
  .L002C5C2C:
    /* C682C 002C5C2C 0149102B */  sltu       $v0, $t2, $t1
    /* C6830 002C5C30 10400007 */  beqz       $v0, .L002C5C50
    /* C6834 002C5C34 3402FFFF */   ori       $v0, $zero, 0xFFFF
    /* C6838 002C5C38 00A07821 */  addu       $t7, $a1, $zero
    /* C683C 002C5C3C 01407021 */  addu       $t6, $t2, $zero
    /* C6840 002C5C40 AFAE0000 */  sw         $t6, 0x0($sp)
    /* C6844 002C5C44 AFAF0004 */  sw         $t7, 0x4($sp)
    /* C6848 002C5C48 080B1791 */  j          .L002C5E44
    /* C684C 002C5C4C 00000000 */   nop
  .L002C5C50:
    /* C6850 002C5C50 0049102B */  sltu       $v0, $v0, $t1
    /* C6854 002C5C54 14400005 */  bnez       $v0, .L002C5C6C
    /* C6858 002C5C58 01201821 */   addu      $v1, $t1, $zero
    /* C685C 002C5C5C 2D220100 */  sltiu      $v0, $t1, 0x100
    /* C6860 002C5C60 38420001 */  xori       $v0, $v0, 0x1
    /* C6864 002C5C64 080B1721 */  j          .L002C5C84
    /* C6868 002C5C68 000220C0 */   sll       $a0, $v0, 3
  .L002C5C6C:
    /* C686C 002C5C6C 3C0200FF */  lui        $v0, (0xFFFFFF >> 16)
    /* C6870 002C5C70 3442FFFF */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* C6874 002C5C74 0049102B */  sltu       $v0, $v0, $t1
    /* C6878 002C5C78 14400002 */  bnez       $v0, .L002C5C84
    /* C687C 002C5C7C 24040018 */   addiu     $a0, $zero, 0x18
    /* C6880 002C5C80 24040010 */  addiu      $a0, $zero, 0x10
  .L002C5C84:
    /* C6884 002C5C84 3C02800D */  lui        $v0, %hi(D_800CD050)
    /* C6888 002C5C88 2442D050 */  addiu      $v0, $v0, %lo(D_800CD050)
    /* C688C 002C5C8C 00831806 */  srlv       $v1, $v1, $a0
    /* C6890 002C5C90 00621821 */  addu       $v1, $v1, $v0
    /* C6894 002C5C94 90620000 */  lbu        $v0, 0x0($v1)
    /* C6898 002C5C98 24030020 */  addiu      $v1, $zero, 0x20
    /* C689C 002C5C9C 00441021 */  addu       $v0, $v0, $a0
    /* C68A0 002C5CA0 00626823 */  subu       $t5, $v1, $v0
    /* C68A4 002C5CA4 15A0000F */  bnez       $t5, .L002C5CE4
    /* C68A8 002C5CA8 006DC023 */   subu      $t8, $v1, $t5
    /* C68AC 002C5CAC 012A102B */  sltu       $v0, $t1, $t2
    /* C68B0 002C5CB0 14400004 */  bnez       $v0, .L002C5CC4
    /* C68B4 002C5CB4 01682023 */   subu      $a0, $t3, $t0
    /* C68B8 002C5CB8 0168102B */  sltu       $v0, $t3, $t0
    /* C68BC 002C5CBC 14400005 */  bnez       $v0, .L002C5CD4
    /* C68C0 002C5CC0 00000000 */   nop
  .L002C5CC4:
    /* C68C4 002C5CC4 01491823 */  subu       $v1, $t2, $t1
    /* C68C8 002C5CC8 0164102B */  sltu       $v0, $t3, $a0
    /* C68CC 002C5CCC 00625023 */  subu       $t2, $v1, $v0
    /* C68D0 002C5CD0 00805821 */  addu       $t3, $a0, $zero
  .L002C5CD4:
    /* C68D4 002C5CD4 1320005B */  beqz       $t9, .L002C5E44
    /* C68D8 002C5CD8 01607821 */   addu      $t7, $t3, $zero
    /* C68DC 002C5CDC 080B178F */  j          .L002C5E3C
    /* C68E0 002C5CE0 01407021 */   addu      $t6, $t2, $zero
  .L002C5CE4:
    /* C68E4 002C5CE4 01A91804 */  sllv       $v1, $t1, $t5
    /* C68E8 002C5CE8 03081006 */  srlv       $v0, $t0, $t8
    /* C68EC 002C5CEC 00624825 */  or         $t1, $v1, $v0
    /* C68F0 002C5CF0 01A84004 */  sllv       $t0, $t0, $t5
    /* C68F4 002C5CF4 030A2006 */  srlv       $a0, $t2, $t8
    /* C68F8 002C5CF8 01AA1804 */  sllv       $v1, $t2, $t5
    /* C68FC 002C5CFC 030B1006 */  srlv       $v0, $t3, $t8
    /* C6900 002C5D00 00625025 */  or         $t2, $v1, $v0
    /* C6904 002C5D04 00093402 */  srl        $a2, $t1, 16
    /* C6908 002C5D08 0086001B */  divu       $zero, $a0, $a2
    /* C690C 002C5D0C 14C00002 */  bnez       $a2, .L002C5D18
    /* C6910 002C5D10 00000000 */   nop
    /* C6914 002C5D14 0007000D */  break      7
  .L002C5D18:
    /* C6918 002C5D18 00003812 */  mflo       $a3
    /* C691C 002C5D1C 00001810 */  mfhi       $v1
    /* C6920 002C5D20 312CFFFF */  andi       $t4, $t1, 0xFFFF
    /* C6924 002C5D24 00000000 */  nop
    /* C6928 002C5D28 00EC0018 */  mult       $a3, $t4
    /* C692C 002C5D2C 000A1402 */  srl        $v0, $t2, 16
    /* C6930 002C5D30 00031C00 */  sll        $v1, $v1, 16
    /* C6934 002C5D34 00621825 */  or         $v1, $v1, $v0
    /* C6938 002C5D38 00002812 */  mflo       $a1
    /* C693C 002C5D3C 0065102B */  sltu       $v0, $v1, $a1
    /* C6940 002C5D40 1040000A */  beqz       $v0, .L002C5D6C
    /* C6944 002C5D44 01AB5804 */   sllv      $t3, $t3, $t5
    /* C6948 002C5D48 00691821 */  addu       $v1, $v1, $t1
    /* C694C 002C5D4C 0069102B */  sltu       $v0, $v1, $t1
    /* C6950 002C5D50 14400006 */  bnez       $v0, .L002C5D6C
    /* C6954 002C5D54 24E7FFFF */   addiu     $a3, $a3, -0x1
    /* C6958 002C5D58 0065102B */  sltu       $v0, $v1, $a1
    /* C695C 002C5D5C 50400004 */  beql       $v0, $zero, .L002C5D70
    /* C6960 002C5D60 00651823 */   subu      $v1, $v1, $a1
    /* C6964 002C5D64 24E7FFFF */  addiu      $a3, $a3, -0x1
    /* C6968 002C5D68 00691821 */  addu       $v1, $v1, $t1
  .L002C5D6C:
    /* C696C 002C5D6C 00651823 */  subu       $v1, $v1, $a1
  .L002C5D70:
    /* C6970 002C5D70 0066001B */  divu       $zero, $v1, $a2
    /* C6974 002C5D74 14C00002 */  bnez       $a2, .L002C5D80
    /* C6978 002C5D78 00000000 */   nop
    /* C697C 002C5D7C 0007000D */  break      7
  .L002C5D80:
    /* C6980 002C5D80 00002012 */  mflo       $a0
    /* C6984 002C5D84 00001810 */  mfhi       $v1
    /* C6988 002C5D88 00000000 */  nop
    /* C698C 002C5D8C 00000000 */  nop
    /* C6990 002C5D90 008C0018 */  mult       $a0, $t4
    /* C6994 002C5D94 3142FFFF */  andi       $v0, $t2, 0xFFFF
    /* C6998 002C5D98 00031C00 */  sll        $v1, $v1, 16
    /* C699C 002C5D9C 00621825 */  or         $v1, $v1, $v0
    /* C69A0 002C5DA0 00002812 */  mflo       $a1
    /* C69A4 002C5DA4 0065102B */  sltu       $v0, $v1, $a1
    /* C69A8 002C5DA8 5040000B */  beql       $v0, $zero, .L002C5DD8
    /* C69AC 002C5DAC 00655023 */   subu      $t2, $v1, $a1
    /* C69B0 002C5DB0 00691821 */  addu       $v1, $v1, $t1
    /* C69B4 002C5DB4 0069102B */  sltu       $v0, $v1, $t1
    /* C69B8 002C5DB8 14400006 */  bnez       $v0, .L002C5DD4
    /* C69BC 002C5DBC 2484FFFF */   addiu     $a0, $a0, -0x1
    /* C69C0 002C5DC0 0065102B */  sltu       $v0, $v1, $a1
    /* C69C4 002C5DC4 10400004 */  beqz       $v0, .L002C5DD8
    /* C69C8 002C5DC8 00655023 */   subu      $t2, $v1, $a1
    /* C69CC 002C5DCC 2484FFFF */  addiu      $a0, $a0, -0x1
    /* C69D0 002C5DD0 00691821 */  addu       $v1, $v1, $t1
  .L002C5DD4:
    /* C69D4 002C5DD4 00655023 */  subu       $t2, $v1, $a1
  .L002C5DD8:
    /* C69D8 002C5DD8 00071400 */  sll        $v0, $a3, 16
    /* C69DC 002C5DDC 00441025 */  or         $v0, $v0, $a0
    /* C69E0 002C5DE0 00480019 */  multu      $v0, $t0
    /* C69E4 002C5DE4 00003010 */  mfhi       $a2
    /* C69E8 002C5DE8 0146102B */  sltu       $v0, $t2, $a2
    /* C69EC 002C5DEC 00002812 */  mflo       $a1
    /* C69F0 002C5DF0 54400005 */  bnel       $v0, $zero, .L002C5E08
    /* C69F4 002C5DF4 00A82023 */   subu      $a0, $a1, $t0
    /* C69F8 002C5DF8 14CA0007 */  bne        $a2, $t2, .L002C5E18
    /* C69FC 002C5DFC 0165102B */   sltu      $v0, $t3, $a1
    /* C6A00 002C5E00 10400005 */  beqz       $v0, .L002C5E18
    /* C6A04 002C5E04 00A82023 */   subu      $a0, $a1, $t0
  .L002C5E08:
    /* C6A08 002C5E08 00C91823 */  subu       $v1, $a2, $t1
    /* C6A0C 002C5E0C 00A4102B */  sltu       $v0, $a1, $a0
    /* C6A10 002C5E10 00623023 */  subu       $a2, $v1, $v0
    /* C6A14 002C5E14 00802821 */  addu       $a1, $a0, $zero
  .L002C5E18:
    /* C6A18 002C5E18 1320000A */  beqz       $t9, .L002C5E44
    /* C6A1C 002C5E1C 01651823 */   subu      $v1, $t3, $a1
    /* C6A20 002C5E20 01462023 */  subu       $a0, $t2, $a2
    /* C6A24 002C5E24 0163102B */  sltu       $v0, $t3, $v1
    /* C6A28 002C5E28 00825023 */  subu       $t2, $a0, $v0
    /* C6A2C 002C5E2C 030A1004 */  sllv       $v0, $t2, $t8
    /* C6A30 002C5E30 01A31806 */  srlv       $v1, $v1, $t5
    /* C6A34 002C5E34 00437825 */  or         $t7, $v0, $v1
    /* C6A38 002C5E38 01AA7006 */  srlv       $t6, $t2, $t5
  .L002C5E3C:
    /* C6A3C 002C5E3C AF2E0000 */  sw         $t6, 0x0($t9)
    /* C6A40 002C5E40 AF2F0004 */  sw         $t7, 0x4($t9)
  .L002C5E44:
    /* C6A44 002C5E44 12400009 */  beqz       $s2, .L002C5E6C
    /* C6A48 002C5E48 00000000 */   nop
    /* C6A4C 002C5E4C 8FA20000 */  lw         $v0, 0x0($sp)
    /* C6A50 002C5E50 8FA30004 */  lw         $v1, 0x4($sp)
    /* C6A54 002C5E54 00038823 */  negu       $s1, $v1
    /* C6A58 002C5E58 00021023 */  negu       $v0, $v0
    /* C6A5C 002C5E5C 0011202B */  sltu       $a0, $zero, $s1
    /* C6A60 002C5E60 00448023 */  subu       $s0, $v0, $a0
    /* C6A64 002C5E64 AFB00000 */  sw         $s0, 0x0($sp)
    /* C6A68 002C5E68 AFB10004 */  sw         $s1, 0x4($sp)
  .L002C5E6C:
    /* C6A6C 002C5E6C 8FA20000 */  lw         $v0, 0x0($sp)
    /* C6A70 002C5E70 8FA30004 */  lw         $v1, 0x4($sp)
    /* C6A74 002C5E74 8FB20010 */  lw         $s2, 0x10($sp)
    /* C6A78 002C5E78 8FB1000C */  lw         $s1, 0xC($sp)
    /* C6A7C 002C5E7C 8FB00008 */  lw         $s0, 0x8($sp)
    /* C6A80 002C5E80 03E00008 */  jr         $ra
    /* C6A84 002C5E84 27BD0018 */   addiu     $sp, $sp, 0x18


    /* C6A88 002C5E88 BF800000 */  .word      0xBF800000 /* linker padding */
    /* C6A8C 002C5E8C BF800000 */  .word      0xBF800000 /* linker padding */
endlabel func_002C5910
