.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8450-0xB888C (VRAM 0x002B7850) */
glabel _handleEvent
    /* B8450 002B7850 27BDFFB0 */  addiu      $sp, $sp, -0x50
    /* B8454 002B7854 AFB40038 */  sw         $s4, 0x38($sp)
    /* B8458 002B7858 AFBF0040 */  sw         $ra, 0x40($sp)
    /* B845C 002B785C AFB5003C */  sw         $s5, 0x3C($sp)
    /* B8460 002B7860 AFB30034 */  sw         $s3, 0x34($sp)
    /* B8464 002B7864 AFB20030 */  sw         $s2, 0x30($sp)
    /* B8468 002B7868 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B846C 002B786C AFB00028 */  sw         $s0, 0x28($sp)
    /* B8470 002B7870 F7B40048 */  sdc1       $fs0, 0x48($sp)
    /* B8474 002B7874 84A30000 */  lh         $v1, 0x0($a1)
    /* B8478 002B7878 8CB00004 */  lw         $s0, 0x4($a1)
    /* B847C 002B787C 2C620009 */  sltiu      $v0, $v1, 0x9
    /* B8480 002B7880 8E13001C */  lw         $s3, 0x1C($s0)
    /* B8484 002B7884 104000F7 */  beqz       $v0, .L002B7C64
    /* B8488 002B7888 0080A021 */   addu      $s4, $a0, $zero
    /* B848C 002B788C 00031080 */  sll        $v0, $v1, 2
    /* B8490 002B7890 3C01800D */  lui        $at, %hi(jtbl_800CC770)
    /* B8494 002B7894 00220821 */  addu       $at, $at, $v0
    /* B8498 002B7898 8C22C770 */  lw         $v0, %lo(jtbl_800CC770)($at)
    /* B849C 002B789C 00400008 */  jr         $v0
    /* B84A0 002B78A0 00000000 */   nop
    /* B84A4 002B78A4 8E020028 */  lw         $v0, 0x28($s0)
    /* B84A8 002B78A8 144000EE */  bnez       $v0, .L002B7C64
    /* B84AC 002B78AC 00000000 */   nop
    /* B84B0 002B78B0 126000EC */  beqz       $s3, .L002B7C64
    /* B84B4 002B78B4 00000000 */   nop
    /* B84B8 002B78B8 A7A00012 */  sh         $zero, 0x12($sp)
    /* B84BC 002B78BC 96020020 */  lhu        $v0, 0x20($s0)
    /* B84C0 002B78C0 02002821 */  addu       $a1, $s0, $zero
    /* B84C4 002B78C4 A3A00014 */  sb         $zero, 0x14($sp)
    /* B84C8 002B78C8 A7A20010 */  sh         $v0, 0x10($sp)
    /* B84CC 002B78CC 8E840038 */  lw         $a0, 0x38($s4)
    /* B84D0 002B78D0 0C0AE034 */  jal        alSynAllocVoice
    /* B84D4 002B78D4 27A60010 */   addiu     $a2, $sp, 0x10
    /* B84D8 002B78D8 8E660000 */  lw         $a2, 0x0($s3)
    /* B84DC 002B78DC 8602002C */  lh         $v0, 0x2C($s0)
    /* B84E0 002B78E0 90C3000C */  lbu        $v1, 0xC($a2)
    /* B84E4 002B78E4 00620018 */  mult       $v1, $v0
    /* B84E8 002B78E8 3405FFC0 */  ori        $a1, $zero, 0xFFC0
    /* B84EC 002B78EC 00001812 */  mflo       $v1
    /* B84F0 002B78F0 3C028102 */  lui        $v0, (0x81020409 >> 16)
    /* B84F4 002B78F4 34420409 */  ori        $v0, $v0, (0x81020409 & 0xFFFF)
    /* B84F8 002B78F8 00620018 */  mult       $v1, $v0
    /* B84FC 002B78FC 9202002E */  lbu        $v0, 0x2E($s0)
    /* B8500 002B7900 9264000C */  lbu        $a0, 0xC($s3)
    /* B8504 002B7904 00451021 */  addu       $v0, $v0, $a1
    /* B8508 002B7908 00822021 */  addu       $a0, $a0, $v0
    /* B850C 002B790C 00802821 */  addu       $a1, $a0, $zero
    /* B8510 002B7910 00042400 */  sll        $a0, $a0, 16
    /* B8514 002B7914 00004810 */  mfhi       $t1
    /* B8518 002B7918 01231021 */  addu       $v0, $t1, $v1
    /* B851C 002B791C 00021183 */  sra        $v0, $v0, 6
    /* B8520 002B7920 00031FC3 */  sra        $v1, $v1, 31
    /* B8524 002B7924 04810002 */  bgez       $a0, .L002B7930
    /* B8528 002B7928 0043A823 */   subu      $s5, $v0, $v1
    /* B852C 002B792C 00002821 */  addu       $a1, $zero, $zero
  .L002B7930:
    /* B8530 002B7930 00051400 */  sll        $v0, $a1, 16
    /* B8534 002B7934 00021403 */  sra        $v0, $v0, 16
    /* B8538 002B7938 2842007F */  slti       $v0, $v0, 0x7F
    /* B853C 002B793C 10400002 */  beqz       $v0, .L002B7948
    /* B8540 002B7940 2411007F */   addiu     $s1, $zero, 0x7F
    /* B8544 002B7944 00A08821 */  addu       $s1, $a1, $zero
  .L002B7948:
    /* B8548 002B7948 8CD20000 */  lw         $s2, 0x0($a2)
    /* B854C 002B794C 8E840038 */  lw         $a0, 0x38($s4)
    /* B8550 002B7950 8E660008 */  lw         $a2, 0x8($s3)
    /* B8554 002B7954 C6140024 */  lwc1       $fs0, 0x24($s0)
    /* B8558 002B7958 0C0AE184 */  jal        alSynStartVoice
    /* B855C 002B795C 02002821 */   addu      $a1, $s0, $zero
    /* B8560 002B7960 02002821 */  addu       $a1, $s0, $zero
    /* B8564 002B7964 24020001 */  addiu      $v0, $zero, 0x1
    /* B8568 002B7968 AE020028 */  sw         $v0, 0x28($s0)
    /* B856C 002B796C 8E840038 */  lw         $a0, 0x38($s4)
    /* B8570 002B7970 0C0AE108 */  jal        alSynSetPan
    /* B8574 002B7974 322600FF */   andi      $a2, $s1, 0xFF
    /* B8578 002B7978 02002821 */  addu       $a1, $s0, $zero
    /* B857C 002B797C 00153400 */  sll        $a2, $s5, 16
    /* B8580 002B7980 00063403 */  sra        $a2, $a2, 16
    /* B8584 002B7984 8E840038 */  lw         $a0, 0x38($s4)
    /* B8588 002B7988 0C0AE154 */  jal        alSynSetVol
    /* B858C 002B798C 02403821 */   addu      $a3, $s2, $zero
    /* B8590 002B7990 8E840038 */  lw         $a0, 0x38($s4)
    /* B8594 002B7994 4406A000 */  mfc1       $a2, $fs0
    /* B8598 002B7998 0C0AE12C */  jal        alSynSetPitch
    /* B859C 002B799C 02002821 */   addu      $a1, $s0, $zero
    /* B85A0 002B79A0 8E840038 */  lw         $a0, 0x38($s4)
    /* B85A4 002B79A4 9206002F */  lbu        $a2, 0x2F($s0)
    /* B85A8 002B79A8 0C0AE0DC */  jal        alSynSetFXMix
    /* B85AC 002B79AC 02002821 */   addu      $a1, $s0, $zero
    /* B85B0 002B79B0 24020006 */  addiu      $v0, $zero, 0x6
    /* B85B4 002B79B4 A7A20018 */  sh         $v0, 0x18($sp)
    /* B85B8 002B79B8 AFB0001C */  sw         $s0, 0x1C($sp)
    /* B85BC 002B79BC 8E620000 */  lw         $v0, 0x0($s3)
    /* B85C0 002B79C0 8E050024 */  lw         $a1, 0x24($s0)
    /* B85C4 002B79C4 8C440000 */  lw         $a0, 0x0($v0)
    /* B85C8 002B79C8 0C0ADF70 */  jal        __sndpTimeAtPitch
    /* B85CC 002B79CC 00000000 */   nop
    /* B85D0 002B79D0 26840014 */  addiu      $a0, $s4, 0x14
    /* B85D4 002B79D4 27A50018 */  addiu      $a1, $sp, 0x18
    /* B85D8 002B79D8 0C0AD469 */  jal        alEvtqPostEvent
    /* B85DC 002B79DC 00403021 */   addu      $a2, $v0, $zero
    /* B85E0 002B79E0 080ADF19 */  j          .L002B7C64
    /* B85E4 002B79E4 00000000 */   nop
    /* B85E8 002B79E8 8E030028 */  lw         $v1, 0x28($s0)
    /* B85EC 002B79EC 24020001 */  addiu      $v0, $zero, 0x1
    /* B85F0 002B79F0 1462009C */  bne        $v1, $v0, .L002B7C64
    /* B85F4 002B79F4 00000000 */   nop
    /* B85F8 002B79F8 1260009A */  beqz       $s3, .L002B7C64
    /* B85FC 002B79FC 00000000 */   nop
    /* B8600 002B7A00 8E620000 */  lw         $v0, 0x0($s3)
    /* B8604 002B7A04 8E050024 */  lw         $a1, 0x24($s0)
    /* B8608 002B7A08 8C440008 */  lw         $a0, 0x8($v0)
    /* B860C 002B7A0C 0C0ADF70 */  jal        __sndpTimeAtPitch
    /* B8610 002B7A10 00000000 */   nop
    /* B8614 002B7A14 00409021 */  addu       $s2, $v0, $zero
    /* B8618 002B7A18 02002821 */  addu       $a1, $s0, $zero
    /* B861C 002B7A1C 00003021 */  addu       $a2, $zero, $zero
    /* B8620 002B7A20 8E840038 */  lw         $a0, 0x38($s4)
    /* B8624 002B7A24 0C0AE154 */  jal        alSynSetVol
    /* B8628 002B7A28 02403821 */   addu      $a3, $s2, $zero
    /* B862C 002B7A2C 12400083 */  beqz       $s2, .L002B7C3C
    /* B8630 002B7A30 26840014 */   addiu     $a0, $s4, 0x14
    /* B8634 002B7A34 27A50018 */  addiu      $a1, $sp, 0x18
    /* B8638 002B7A38 02403021 */  addu       $a2, $s2, $zero
    /* B863C 002B7A3C 24020007 */  addiu      $v0, $zero, 0x7
    /* B8640 002B7A40 A7A20018 */  sh         $v0, 0x18($sp)
    /* B8644 002B7A44 0C0AD469 */  jal        alEvtqPostEvent
    /* B8648 002B7A48 AFB0001C */   sw        $s0, 0x1C($sp)
    /* B864C 002B7A4C 24020002 */  addiu      $v0, $zero, 0x2
    /* B8650 002B7A50 080ADF19 */  j          .L002B7C64
    /* B8654 002B7A54 AE020028 */   sw        $v0, 0x28($s0)
    /* B8658 002B7A58 90A20008 */  lbu        $v0, 0x8($a1)
    /* B865C 002B7A5C 8E030028 */  lw         $v1, 0x28($s0)
    /* B8660 002B7A60 A202002E */  sb         $v0, 0x2E($s0)
    /* B8664 002B7A64 24020001 */  addiu      $v0, $zero, 0x1
    /* B8668 002B7A68 1462007E */  bne        $v1, $v0, .L002B7C64
    /* B866C 002B7A6C 00000000 */   nop
    /* B8670 002B7A70 1260007C */  beqz       $s3, .L002B7C64
    /* B8674 002B7A74 3404FFC0 */   ori       $a0, $zero, 0xFFC0
    /* B8678 002B7A78 9203002E */  lbu        $v1, 0x2E($s0)
    /* B867C 002B7A7C 9262000C */  lbu        $v0, 0xC($s3)
    /* B8680 002B7A80 00641821 */  addu       $v1, $v1, $a0
    /* B8684 002B7A84 00431021 */  addu       $v0, $v0, $v1
    /* B8688 002B7A88 00402821 */  addu       $a1, $v0, $zero
    /* B868C 002B7A8C 00021400 */  sll        $v0, $v0, 16
    /* B8690 002B7A90 04420001 */  bltzl      $v0, .L002B7A98
    /* B8694 002B7A94 00002821 */   addu      $a1, $zero, $zero
  .L002B7A98:
    /* B8698 002B7A98 00051400 */  sll        $v0, $a1, 16
    /* B869C 002B7A9C 00021403 */  sra        $v0, $v0, 16
    /* B86A0 002B7AA0 2842007F */  slti       $v0, $v0, 0x7F
    /* B86A4 002B7AA4 10400002 */  beqz       $v0, .L002B7AB0
    /* B86A8 002B7AA8 2411007F */   addiu     $s1, $zero, 0x7F
    /* B86AC 002B7AAC 00A08821 */  addu       $s1, $a1, $zero
  .L002B7AB0:
    /* B86B0 002B7AB0 8E840038 */  lw         $a0, 0x38($s4)
    /* B86B4 002B7AB4 02002821 */  addu       $a1, $s0, $zero
    /* B86B8 002B7AB8 0C0AE108 */  jal        alSynSetPan
    /* B86BC 002B7ABC 322600FF */   andi      $a2, $s1, 0xFF
    /* B86C0 002B7AC0 080ADF19 */  j          .L002B7C64
    /* B86C4 002B7AC4 00000000 */   nop
    /* B86C8 002B7AC8 C4A00008 */  lwc1       $fv0, 0x8($a1)
    /* B86CC 002B7ACC 3C01800D */  lui        $at, %hi(D_800CC790 + 0x4)
    /* B86D0 002B7AD0 C421C794 */  lwc1       $fv0f, %lo(D_800CC790 + 0x4)($at)
    /* B86D4 002B7AD4 4601003C */  c.lt.s     $fv0, $fv0f
    /* B86D8 002B7AD8 00000000 */  nop
    /* B86DC 002B7ADC 45000002 */  bc1f       .L002B7AE8
    /* B86E0 002B7AE0 E6000024 */   swc1      $fv0, 0x24($s0)
    /* B86E4 002B7AE4 E6010024 */  swc1       $fv0f, 0x24($s0)
  .L002B7AE8:
    /* B86E8 002B7AE8 8E030028 */  lw         $v1, 0x28($s0)
    /* B86EC 002B7AEC 24020001 */  addiu      $v0, $zero, 0x1
    /* B86F0 002B7AF0 1462005C */  bne        $v1, $v0, .L002B7C64
    /* B86F4 002B7AF4 00000000 */   nop
    /* B86F8 002B7AF8 8E840038 */  lw         $a0, 0x38($s4)
    /* B86FC 002B7AFC 8E060024 */  lw         $a2, 0x24($s0)
    /* B8700 002B7B00 0C0AE12C */  jal        alSynSetPitch
    /* B8704 002B7B04 02002821 */   addu      $a1, $s0, $zero
    /* B8708 002B7B08 080ADF19 */  j          .L002B7C64
    /* B870C 002B7B0C 00000000 */   nop
    /* B8710 002B7B10 90A20008 */  lbu        $v0, 0x8($a1)
    /* B8714 002B7B14 8E030028 */  lw         $v1, 0x28($s0)
    /* B8718 002B7B18 A202002F */  sb         $v0, 0x2F($s0)
    /* B871C 002B7B1C 24020001 */  addiu      $v0, $zero, 0x1
    /* B8720 002B7B20 14620050 */  bne        $v1, $v0, .L002B7C64
    /* B8724 002B7B24 00000000 */   nop
    /* B8728 002B7B28 8E840038 */  lw         $a0, 0x38($s4)
    /* B872C 002B7B2C 9206002F */  lbu        $a2, 0x2F($s0)
    /* B8730 002B7B30 0C0AE0DC */  jal        alSynSetFXMix
    /* B8734 002B7B34 02002821 */   addu      $a1, $s0, $zero
    /* B8738 002B7B38 080ADF19 */  j          .L002B7C64
    /* B873C 002B7B3C 00000000 */   nop
    /* B8740 002B7B40 94A50008 */  lhu        $a1, 0x8($a1)
    /* B8744 002B7B44 8E030028 */  lw         $v1, 0x28($s0)
    /* B8748 002B7B48 24020001 */  addiu      $v0, $zero, 0x1
    /* B874C 002B7B4C 14620045 */  bne        $v1, $v0, .L002B7C64
    /* B8750 002B7B50 A605002C */   sh        $a1, 0x2C($s0)
    /* B8754 002B7B54 12600043 */  beqz       $s3, .L002B7C64
    /* B8758 002B7B58 00051400 */   sll       $v0, $a1, 16
    /* B875C 002B7B5C 8E630000 */  lw         $v1, 0x0($s3)
    /* B8760 002B7B60 9063000D */  lbu        $v1, 0xD($v1)
    /* B8764 002B7B64 00021403 */  sra        $v0, $v0, 16
    /* B8768 002B7B68 00620018 */  mult       $v1, $v0
    /* B876C 002B7B6C 00001812 */  mflo       $v1
    /* B8770 002B7B70 3C028102 */  lui        $v0, (0x81020409 >> 16)
    /* B8774 002B7B74 34420409 */  ori        $v0, $v0, (0x81020409 & 0xFFFF)
    /* B8778 002B7B78 00620018 */  mult       $v1, $v0
    /* B877C 002B7B7C 02002821 */  addu       $a1, $s0, $zero
    /* B8780 002B7B80 240703E8 */  addiu      $a3, $zero, 0x3E8
    /* B8784 002B7B84 8E840038 */  lw         $a0, 0x38($s4)
    /* B8788 002B7B88 00004810 */  mfhi       $t1
    /* B878C 002B7B8C 01231021 */  addu       $v0, $t1, $v1
    /* B8790 002B7B90 00021183 */  sra        $v0, $v0, 6
    /* B8794 002B7B94 00031FC3 */  sra        $v1, $v1, 31
    /* B8798 002B7B98 00438823 */  subu       $s1, $v0, $v1
    /* B879C 002B7B9C 00113400 */  sll        $a2, $s1, 16
    /* B87A0 002B7BA0 0C0AE154 */  jal        alSynSetVol
    /* B87A4 002B7BA4 00063403 */   sra       $a2, $a2, 16
    /* B87A8 002B7BA8 080ADF19 */  j          .L002B7C64
    /* B87AC 002B7BAC 00000000 */   nop
    /* B87B0 002B7BB0 8E630000 */  lw         $v1, 0x0($s3)
    /* B87B4 002B7BB4 8C640004 */  lw         $a0, 0x4($v1)
    /* B87B8 002B7BB8 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B87BC 002B7BBC 10820029 */  beq        $a0, $v0, .L002B7C64
    /* B87C0 002B7BC0 00000000 */   nop
    /* B87C4 002B7BC4 9063000D */  lbu        $v1, 0xD($v1)
    /* B87C8 002B7BC8 8602002C */  lh         $v0, 0x2C($s0)
    /* B87CC 002B7BCC 00620018 */  mult       $v1, $v0
    /* B87D0 002B7BD0 00001812 */  mflo       $v1
    /* B87D4 002B7BD4 3C028102 */  lui        $v0, (0x81020409 >> 16)
    /* B87D8 002B7BD8 34420409 */  ori        $v0, $v0, (0x81020409 & 0xFFFF)
    /* B87DC 002B7BDC 00620018 */  mult       $v1, $v0
    /* B87E0 002B7BE0 8E050024 */  lw         $a1, 0x24($s0)
    /* B87E4 002B7BE4 00004810 */  mfhi       $t1
    /* B87E8 002B7BE8 01231021 */  addu       $v0, $t1, $v1
    /* B87EC 002B7BEC 00021183 */  sra        $v0, $v0, 6
    /* B87F0 002B7BF0 00031FC3 */  sra        $v1, $v1, 31
    /* B87F4 002B7BF4 0C0ADF70 */  jal        __sndpTimeAtPitch
    /* B87F8 002B7BF8 00438823 */   subu      $s1, $v0, $v1
    /* B87FC 002B7BFC 00409021 */  addu       $s2, $v0, $zero
    /* B8800 002B7C00 02002821 */  addu       $a1, $s0, $zero
    /* B8804 002B7C04 00113400 */  sll        $a2, $s1, 16
    /* B8808 002B7C08 00063403 */  sra        $a2, $a2, 16
    /* B880C 002B7C0C 8E840038 */  lw         $a0, 0x38($s4)
    /* B8810 002B7C10 0C0AE154 */  jal        alSynSetVol
    /* B8814 002B7C14 02403821 */   addu      $a3, $s2, $zero
    /* B8818 002B7C18 26840014 */  addiu      $a0, $s4, 0x14
    /* B881C 002B7C1C 27A50018 */  addiu      $a1, $sp, 0x18
    /* B8820 002B7C20 02403021 */  addu       $a2, $s2, $zero
    /* B8824 002B7C24 24020001 */  addiu      $v0, $zero, 0x1
    /* B8828 002B7C28 A7A20018 */  sh         $v0, 0x18($sp)
    /* B882C 002B7C2C 0C0AD469 */  jal        alEvtqPostEvent
    /* B8830 002B7C30 AFB0001C */   sw        $s0, 0x1C($sp)
    /* B8834 002B7C34 080ADF19 */  j          .L002B7C64
    /* B8838 002B7C38 00000000 */   nop
  .L002B7C3C:
    /* B883C 002B7C3C 8E840038 */  lw         $a0, 0x38($s4)
    /* B8840 002B7C40 0C0AE1F0 */  jal        alSynStopVoice
    /* B8844 002B7C44 02002821 */   addu      $a1, $s0, $zero
    /* B8848 002B7C48 8E840038 */  lw         $a0, 0x38($s4)
    /* B884C 002B7C4C 0C0AE0B4 */  jal        alSynFreeVoice
    /* B8850 002B7C50 02002821 */   addu      $a1, $s0, $zero
    /* B8854 002B7C54 26840014 */  addiu      $a0, $s4, 0x14
    /* B8858 002B7C58 0C0ADF46 */  jal        _removeEvents
    /* B885C 002B7C5C 02002821 */   addu      $a1, $s0, $zero
    /* B8860 002B7C60 AE000028 */  sw         $zero, 0x28($s0)
  .L002B7C64:
    /* B8864 002B7C64 8FBF0040 */  lw         $ra, 0x40($sp)
    /* B8868 002B7C68 8FB5003C */  lw         $s5, 0x3C($sp)
    /* B886C 002B7C6C 8FB40038 */  lw         $s4, 0x38($sp)
    /* B8870 002B7C70 8FB30034 */  lw         $s3, 0x34($sp)
    /* B8874 002B7C74 8FB20030 */  lw         $s2, 0x30($sp)
    /* B8878 002B7C78 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B887C 002B7C7C 8FB00028 */  lw         $s0, 0x28($sp)
    /* B8880 002B7C80 D7B40048 */  ldc1       $fs0, 0x48($sp)
    /* B8884 002B7C84 03E00008 */  jr         $ra
    /* B8888 002B7C88 27BD0050 */   addiu     $sp, $sp, 0x50
endlabel _handleEvent
