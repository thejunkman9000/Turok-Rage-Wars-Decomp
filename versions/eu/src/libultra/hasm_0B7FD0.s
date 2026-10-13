.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB7FD0-0xB814C (VRAM 0x002B73D0) */
.globl sinf
sinf:
    /* B7FD0 002B73D0 E7AC0000 */  swc1       $fa0, 0x0($sp)
    /* B7FD4 002B73D4 8FA20000 */  lw         $v0, 0x0($sp)
    /* B7FD8 002B73D8 00021D83 */  sra        $v1, $v0, 22
    /* B7FDC 002B73DC 306301FF */  andi       $v1, $v1, 0x1FF
    /* B7FE0 002B73E0 286200FF */  slti       $v0, $v1, 0xFF
    /* B7FE4 002B73E4 10400019 */  .word 0x10400019
    /* B7FE8 002B73E8 286200E6 */  slti      $v0, $v1, 0xE6
    /* B7FEC 002B73EC 14400015 */  .word 0x14400015
    /* B7FF0 002B73F0 00000000 */  nop
    /* B7FF4 002B73F4 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B7FF8 002B73F8 3C02800D */  lui        $v0, %hi(D_auto_800C84C0)
    /* B7FFC 002B73FC 244284C0 */  addiu      $v0, $v0, %lo(D_auto_800C84C0)
    /* B8000 002B7400 D4410020 */  ldc1       $fv0f, 0x20($v0)
    /* B8004 002B7404 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B8008 002B7408 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B800C 002B740C D4400018 */  ldc1       $fv0, 0x18($v0)
    /* B8010 002B7410 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B8014 002B7414 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B8018 002B7418 D4400010 */  ldc1       $fv0, 0x10($v0)
    /* B801C 002B741C 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B8020 002B7420 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B8024 002B7424 00000000 */  nop
    /* B8028 002B7428 46036002 */  mul.s      $fv0, $fa0, $fv1f
    /* B802C 002B742C D4420008 */  ldc1       $fv1, 0x8($v0)
    /* B8030 002B7430 46220840 */  add.d      $fv0f, $fv0f, $fv1
    /* B8034 002B7434 46200860 */  cvt.s.d    $fv0f, $fv0f
    /* B8038 002B7438 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B803C 002B743C 03E00008 */  jr         $ra
    /* B8040 002B7440 46006000 */  add.s     $fv0, $fa0, $fv0
.Lauto_002B7444:
    /* B8044 002B7444 03E00008 */  jr         $ra
    /* B8048 002B7448 46006006 */  mov.s     $fv0, $fa0
.Lauto_002B744C:
    /* B804C 002B744C 28620136 */  slti       $v0, $v1, 0x136
    /* B8050 002B7450 1040003A */  .word 0x1040003A
    /* B8054 002B7454 00000000 */  nop
    /* B8058 002B7458 3C01800D */  lui        $at, %hi(D_auto_800C84E8)
    /* B805C 002B745C D42084E8 */  ldc1       $fv0, %lo(D_auto_800C84E8)($at)
    /* B8060 002B7460 46006061 */  cvt.d.s    $fv0f, $fa0
    /* B8064 002B7464 46200842 */  mul.d      $fv0f, $fv0f, $fv0
    /* B8068 002B7468 44800000 */  mtc1       $zero, $fv0
    /* B806C 002B746C 462008A0 */  cvt.s.d    $fv1, $fv0f
    /* B8070 002B7470 4602003E */  c.le.s     $fv0, $fv1
    /* B8074 002B7474 00000000 */  nop
    /* B8078 002B7478 45000005 */  .word 0x45000005
    /* B807C 002B747C 00000000 */  nop
    /* B8080 002B7480 3C01800D */  lui        $at, %hi(D_auto_800C8504)
    /* B8084 002B7484 C4208504 */  lwc1       $fv0, %lo(D_auto_800C8504)($at)
    /* B8088 002B7488 080ADD27 */  .word 0x080ADD27
    /* B808C 002B748C 46001000 */  add.s     $fv0, $fv1, $fv0
.Lauto_002B7490:
    /* B8090 002B7490 3C01800D */  lui        $at, %hi(D_auto_800C8508)
    /* B8094 002B7494 C4208508 */  lwc1       $fv0, %lo(D_auto_800C8508)($at)
    /* B8098 002B7498 46001001 */  sub.s      $fv0, $fv1, $fv0
.Lauto_002B749C:
    /* B809C 002B749C 4600010D */  trunc.w.s  $ft0, $fv0
    /* B80A0 002B74A0 44032000 */  mfc1       $v1, $ft0
    /* B80A4 002B74A4 44831000 */  mtc1       $v1, $fv1
    /* B80A8 002B74A8 468010A0 */  cvt.s.w    $fv1, $fv1
    /* B80AC 002B74AC 3C01800D */  lui        $at, %hi(D_auto_800C84F0)
    /* B80B0 002B74B0 D42184F0 */  ldc1       $fv0f, %lo(D_auto_800C84F0)($at)
    /* B80B4 002B74B4 460010A1 */  cvt.d.s    $fv1, $fv1
    /* B80B8 002B74B8 46211042 */  mul.d      $fv0f, $fv1, $fv0f
    /* B80BC 002B74BC 3C01800D */  lui        $at, %hi(D_auto_800C84F8)
    /* B80C0 002B74C0 D42084F8 */  ldc1       $fv0, %lo(D_auto_800C84F8)($at)
    /* B80C4 002B74C4 46201082 */  mul.d      $fv1, $fv1, $fv0
    /* B80C8 002B74C8 46006021 */  cvt.d.s    $fv0, $fa0
    /* B80CC 002B74CC 46210001 */  sub.d      $fv0, $fv0, $fv0f
    /* B80D0 002B74D0 46200320 */  cvt.s.d    $fa0, $fv0
    /* B80D4 002B74D4 46006021 */  cvt.d.s    $fv0, $fa0
    /* B80D8 002B74D8 46220001 */  sub.d      $fv0, $fv0, $fv1
    /* B80DC 002B74DC 46200320 */  cvt.s.d    $fa0, $fv0
    /* B80E0 002B74E0 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B80E4 002B74E4 3C02800D */  lui        $v0, %hi(D_auto_800C84C0)
    /* B80E8 002B74E8 244284C0 */  addiu      $v0, $v0, %lo(D_auto_800C84C0)
    /* B80EC 002B74EC D4400020 */  ldc1       $fv0, 0x20($v0)
    /* B80F0 002B74F0 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B80F4 002B74F4 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B80F8 002B74F8 D4410018 */  ldc1       $fv0f, 0x18($v0)
    /* B80FC 002B74FC 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B8100 002B7500 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B8104 002B7504 D4410010 */  ldc1       $fv0f, 0x10($v0)
    /* B8108 002B7508 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B810C 002B750C 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B8110 002B7510 00000000 */  nop
    /* B8114 002B7514 46036082 */  mul.s      $fv1, $fa0, $fv1f
    /* B8118 002B7518 D4410008 */  ldc1       $fv0f, 0x8($v0)
    /* B811C 002B751C 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B8120 002B7520 46200060 */  cvt.s.d    $fv0f, $fv0
    /* B8124 002B7524 46011082 */  mul.s      $fv1, $fv1, $fv0f
    /* B8128 002B7528 30620001 */  andi       $v0, $v1, 0x1
    /* B812C 002B752C 10400005 */  .word 0x10400005
    /* B8130 002B7530 46026000 */  add.s     $fv0, $fa0, $fv1
    /* B8134 002B7534 03E00008 */  jr         $ra
    /* B8138 002B7538 46000007 */  neg.s     $fv0, $fv0
.Lauto_002B753C:
    /* B813C 002B753C 3C01800D */  lui        $at, %hi(D_auto_800C8500)
    /* B8140 002B7540 C4208500 */  lwc1       $fv0, %lo(D_auto_800C8500)($at)
.Lauto_002B7544:
    /* B8144 002B7544 03E00008 */  jr         $ra
    /* B8148 002B7548 00000000 */  nop
