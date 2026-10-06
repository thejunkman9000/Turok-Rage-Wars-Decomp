.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB240-0xBB400 (VRAM 0x002BA640) */
glabel func_002BA640
    /* BB240 002BA640 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* BB244 002BA644 AFB20028 */  sw         $s2, 0x28($sp)
    /* BB248 002BA648 00809021 */  addu       $s2, $a0, $zero
    /* BB24C 002BA64C AFB3002C */  sw         $s3, 0x2C($sp)
    /* BB250 002BA650 AFB00020 */  sw         $s0, 0x20($sp)
    /* BB254 002BA654 00C08021 */  addu       $s0, $a2, $zero
    /* BB258 002BA658 AFB10024 */  sw         $s1, 0x24($sp)
    /* BB25C 002BA65C 8FB10050 */  lw         $s1, 0x50($sp)
    /* BB260 002BA660 24020140 */  addiu      $v0, $zero, 0x140
    /* BB264 002BA664 AFBF0030 */  sw         $ra, 0x30($sp)
    /* BB268 002BA668 F7B40038 */  sdc1       $fs0, 0x38($sp)
    /* BB26C 002BA66C A7A20018 */  sh         $v0, 0x18($sp)
    /* BB270 002BA670 8E440000 */  lw         $a0, 0x0($s2)
    /* BB274 002BA674 12000059 */  beqz       $s0, .L002BA7DC
    /* BB278 002BA678 00A09821 */   addu      $s3, $a1, $zero
    /* BB27C 002BA67C 8E42001C */  lw         $v0, 0x1C($s2)
    /* BB280 002BA680 10400016 */  beqz       $v0, .L002BA6DC
    /* BB284 002BA684 27A50018 */   addiu     $a1, $sp, 0x18
    /* BB288 002BA688 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB28C 002BA68C 8C820004 */  lw         $v0, 0x4($a0)
    /* BB290 002BA690 0040F809 */  jalr       $v0
    /* BB294 002BA694 02003021 */   addu      $a2, $s0, $zero
    /* BB298 002BA698 00408821 */  addu       $s1, $v0, $zero
    /* BB29C 002BA69C 3C0300FF */  lui        $v1, (0xFFFFFF >> 16)
    /* BB2A0 002BA6A0 3463FFFF */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* BB2A4 002BA6A4 02202021 */  addu       $a0, $s1, $zero
    /* BB2A8 002BA6A8 87A20018 */  lh         $v0, 0x18($sp)
    /* BB2AC 002BA6AC 26310008 */  addiu      $s1, $s1, 0x8
    /* BB2B0 002BA6B0 00431024 */  and        $v0, $v0, $v1
    /* BB2B4 002BA6B4 3C030A00 */  lui        $v1, (0xA000000 >> 16)
    /* BB2B8 002BA6B8 00431025 */  or         $v0, $v0, $v1
    /* BB2BC 002BA6BC AC820000 */  sw         $v0, 0x0($a0)
    /* BB2C0 002BA6C0 00101040 */  sll        $v0, $s0, 1
    /* BB2C4 002BA6C4 96630000 */  lhu        $v1, 0x0($s3)
    /* BB2C8 002BA6C8 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BB2CC 002BA6CC 00031C00 */  sll        $v1, $v1, 16
    /* BB2D0 002BA6D0 00621825 */  or         $v1, $v1, $v0
    /* BB2D4 002BA6D4 080AE9F7 */  j          .L002BA7DC
    /* BB2D8 002BA6D8 AC830004 */   sw        $v1, 0x4($a0)
  .L002BA6DC:
    /* BB2DC 002BA6DC C6400018 */  lwc1       $fv0, 0x18($s2)
    /* BB2E0 002BA6E0 3C01800D */  lui        $at, %hi(D_800CC990)
    /* BB2E4 002BA6E4 C421C990 */  lwc1       $fv0f, %lo(D_800CC990)($at)
    /* BB2E8 002BA6E8 4600083C */  c.lt.s     $fv0f, $fv0
    /* BB2EC 002BA6EC 00000000 */  nop
    /* BB2F0 002BA6F0 45030001 */  bc1tl      .L002BA6F8
    /* BB2F4 002BA6F4 E6410018 */   swc1      $fv0f, 0x18($s2)
  .L002BA6F8:
    /* BB2F8 002BA6F8 C6400018 */  lwc1       $fv0, 0x18($s2)
    /* BB2FC 002BA6FC 3C01800D */  lui        $at, %hi(D_800CC990 + 0x4)
    /* BB300 002BA700 C434C994 */  lwc1       $fs0, %lo(D_800CC990 + 0x4)($at)
    /* BB304 002BA704 46140002 */  mul.s      $fv0, $fv0, $fs0
    /* BB308 002BA708 460000CD */  trunc.w.s  $fv1f, $fv0
    /* BB30C 002BA70C 44021800 */  mfc1       $v0, $fv1f
    /* BB310 002BA710 3C01800D */  lui        $at, %hi(D_800CC998)
    /* BB314 002BA714 C420C998 */  lwc1       $fv0, %lo(D_800CC998)($at)
    /* BB318 002BA718 44821000 */  mtc1       $v0, $fv1
    /* BB31C 002BA71C 468010A0 */  cvt.s.w    $fv1, $fv1
    /* BB320 002BA720 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* BB324 002BA724 44900000 */  mtc1       $s0, $fv0
    /* BB328 002BA728 46800020 */  cvt.s.w    $fv0, $fv0
    /* BB32C 002BA72C 46001002 */  mul.s      $fv0, $fv1, $fv0
    /* BB330 002BA730 C6410020 */  lwc1       $fv0f, 0x20($s2)
    /* BB334 002BA734 46000840 */  add.s      $fv0f, $fv0f, $fv0
    /* BB338 002BA738 460008CD */  trunc.w.s  $fv1f, $fv0f
    /* BB33C 002BA73C 44061800 */  mfc1       $a2, $fv1f
    /* BB340 002BA740 44860000 */  mtc1       $a2, $fv0
    /* BB344 002BA744 46800020 */  cvt.s.w    $fv0, $fv0
    /* BB348 002BA748 46000841 */  sub.s      $fv0f, $fv0f, $fv0
    /* BB34C 002BA74C E6420018 */  swc1       $fv1, 0x18($s2)
    /* BB350 002BA750 E6410020 */  swc1       $fv0f, 0x20($s2)
    /* BB354 002BA754 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB358 002BA758 8C820004 */  lw         $v0, 0x4($a0)
    /* BB35C 002BA75C 0040F809 */  jalr       $v0
    /* BB360 002BA760 27A50018 */   addiu     $a1, $sp, 0x18
    /* BB364 002BA764 00408821 */  addu       $s1, $v0, $zero
    /* BB368 002BA768 02202021 */  addu       $a0, $s1, $zero
    /* BB36C 002BA76C 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* BB370 002BA770 26310008 */  addiu      $s1, $s1, 0x8
    /* BB374 002BA774 97A20018 */  lhu        $v0, 0x18($sp)
    /* BB378 002BA778 C6400018 */  lwc1       $fv0, 0x18($s2)
    /* BB37C 002BA77C 00431025 */  or         $v0, $v0, $v1
    /* BB380 002BA780 AC820000 */  sw         $v0, 0x0($a0)
    /* BB384 002BA784 00101040 */  sll        $v0, $s0, 1
    /* BB388 002BA788 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BB38C 002BA78C 02208021 */  addu       $s0, $s1, $zero
    /* BB390 002BA790 96630000 */  lhu        $v1, 0x0($s3)
    /* BB394 002BA794 46140002 */  mul.s      $fv0, $fv0, $fs0
    /* BB398 002BA798 00031C00 */  sll        $v1, $v1, 16
    /* BB39C 002BA79C 00621825 */  or         $v1, $v1, $v0
    /* BB3A0 002BA7A0 AC830004 */  sw         $v1, 0x4($a0)
    /* BB3A4 002BA7A4 92440027 */  lbu        $a0, 0x27($s2)
    /* BB3A8 002BA7A8 3C020500 */  lui        $v0, (0x5000000 >> 16)
    /* BB3AC 002BA7AC 00042400 */  sll        $a0, $a0, 16
    /* BB3B0 002BA7B0 460000CD */  trunc.w.s  $fv1f, $fv0
    /* BB3B4 002BA7B4 44031800 */  mfc1       $v1, $fv1f
    /* BB3B8 002BA7B8 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BB3BC 002BA7BC 00621825 */  or         $v1, $v1, $v0
    /* BB3C0 002BA7C0 00832025 */  or         $a0, $a0, $v1
    /* BB3C4 002BA7C4 AE040000 */  sw         $a0, 0x0($s0)
    /* BB3C8 002BA7C8 8E440014 */  lw         $a0, 0x14($s2)
    /* BB3CC 002BA7CC 0C0B032C */  jal        osVirtualToPhysical
    /* BB3D0 002BA7D0 26310008 */   addiu     $s1, $s1, 0x8
    /* BB3D4 002BA7D4 AE020004 */  sw         $v0, 0x4($s0)
    /* BB3D8 002BA7D8 AE400024 */  sw         $zero, 0x24($s2)
  .L002BA7DC:
    /* BB3DC 002BA7DC 02201021 */  addu       $v0, $s1, $zero
    /* BB3E0 002BA7E0 8FBF0030 */  lw         $ra, 0x30($sp)
    /* BB3E4 002BA7E4 8FB3002C */  lw         $s3, 0x2C($sp)
    /* BB3E8 002BA7E8 8FB20028 */  lw         $s2, 0x28($sp)
    /* BB3EC 002BA7EC 8FB10024 */  lw         $s1, 0x24($sp)
    /* BB3F0 002BA7F0 8FB00020 */  lw         $s0, 0x20($sp)
    /* BB3F4 002BA7F4 D7B40038 */  ldc1       $fs0, 0x38($sp)
    /* BB3F8 002BA7F8 03E00008 */  jr         $ra
    /* BB3FC 002BA7FC 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel func_002BA640
