.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5204-0xC536C (VRAM 0x002C4604) */
glabel func_002C4604
    /* C5204 002C4604 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* C5208 002C4608 F7B70040 */  sdc1       $fs1f, 0x40($sp)
    /* C520C 002C460C 3C01800D */  lui        $at, %hi(D_800CCF10)
    /* C5210 002C4610 C437CF10 */  lwc1       $fs1f, %lo(D_800CCF10)($at)
    /* C5214 002C4614 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C5218 002C4618 3C01800D */  lui        $at, %hi(D_800CCF10 + 0x4)
    /* C521C 002C461C C436CF14 */  lwc1       $fs1, %lo(D_800CCF10 + 0x4)($at)
    /* C5220 002C4620 F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C5224 002C4624 3C01800D */  lui        $at, %hi(D_800CCF18)
    /* C5228 002C4628 C435CF18 */  lwc1       $fs0f, %lo(D_800CCF18)($at)
    /* C522C 002C462C AFB10014 */  sw         $s1, 0x14($sp)
    /* C5230 002C4630 00008821 */  addu       $s1, $zero, $zero
    /* C5234 002C4634 AFB40020 */  sw         $s4, 0x20($sp)
    /* C5238 002C4638 3C148015 */  lui        $s4, %hi(D_801510C0)
    /* C523C 002C463C 269410C0 */  addiu      $s4, $s4, %lo(D_801510C0)
    /* C5240 002C4640 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C5244 002C4644 3C138015 */  lui        $s3, %hi(D_801512C0)
    /* C5248 002C4648 267312C0 */  addiu      $s3, $s3, %lo(D_801512C0)
    /* C524C 002C464C AFB20018 */  sw         $s2, 0x18($sp)
    /* C5250 002C4650 3C128015 */  lui        $s2, %hi(D_801518C0)
    /* C5254 002C4654 265218C0 */  addiu      $s2, $s2, %lo(D_801518C0)
    /* C5258 002C4658 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C525C 002C465C AFB00010 */  sw         $s0, 0x10($sp)
    /* C5260 002C4660 F7B40028 */  sdc1       $fs0, 0x28($sp)
  .L002C4664:
    /* C5264 002C4664 00118400 */  sll        $s0, $s1, 16
    /* C5268 002C4668 00108403 */  sra        $s0, $s0, 16
    /* C526C 002C466C 44900000 */  mtc1       $s0, $fv0
    /* C5270 002C4670 46800020 */  cvt.s.w    $fv0, $fv0
    /* C5274 002C4674 46170002 */  mul.s      $fv0, $fv0, $fs1f
    /* C5278 002C4678 46160000 */  add.s      $fv0, $fv0, $fs1
    /* C527C 002C467C 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C5280 002C4680 0C0AED8C */  jal        cosf
    /* C5284 002C4684 4600A306 */   mov.s     $fa0, $fs0
    /* C5288 002C4688 4600A306 */  mov.s      $fa0, $fs0
    /* C528C 002C468C 00108080 */  sll        $s0, $s0, 2
    /* C5290 002C4690 02141021 */  addu       $v0, $s0, $s4
    /* C5294 002C4694 0C0AF080 */  jal        sinf
    /* C5298 002C4698 E4400000 */   swc1      $fv0, 0x0($v0)
    /* C529C 002C469C 26220001 */  addiu      $v0, $s1, 0x1
    /* C52A0 002C46A0 00408821 */  addu       $s1, $v0, $zero
    /* C52A4 002C46A4 02131821 */  addu       $v1, $s0, $s3
    /* C52A8 002C46A8 02128021 */  addu       $s0, $s0, $s2
    /* C52AC 002C46AC 00021400 */  sll        $v0, $v0, 16
    /* C52B0 002C46B0 00021403 */  sra        $v0, $v0, 16
    /* C52B4 002C46B4 28420080 */  slti       $v0, $v0, 0x80
    /* C52B8 002C46B8 E4600000 */  swc1       $fv0, 0x0($v1)
    /* C52BC 002C46BC 1440FFE9 */  bnez       $v0, .L002C4664
    /* C52C0 002C46C0 AE000000 */   sw        $zero, 0x0($s0)
    /* C52C4 002C46C4 00008821 */  addu       $s1, $zero, $zero
    /* C52C8 002C46C8 3C01800D */  lui        $at, %hi(D_800CCF18 + 0x4)
    /* C52CC 002C46CC C435CF1C */  lwc1       $fs0f, %lo(D_800CCF18 + 0x4)($at)
    /* C52D0 002C46D0 3C138015 */  lui        $s3, %hi(D_801514C0)
    /* C52D4 002C46D4 267314C0 */  addiu      $s3, $s3, %lo(D_801514C0)
    /* C52D8 002C46D8 3C128015 */  lui        $s2, %hi(D_801516C0)
    /* C52DC 002C46DC 265216C0 */  addiu      $s2, $s2, %lo(D_801516C0)
  .L002C46E0:
    /* C52E0 002C46E0 00118400 */  sll        $s0, $s1, 16
    /* C52E4 002C46E4 00108403 */  sra        $s0, $s0, 16
    /* C52E8 002C46E8 44900000 */  mtc1       $s0, $fv0
    /* C52EC 002C46EC 46800020 */  cvt.s.w    $fv0, $fv0
    /* C52F0 002C46F0 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C52F4 002C46F4 0C0AED8C */  jal        cosf
    /* C52F8 002C46F8 4600A306 */   mov.s     $fa0, $fs0
    /* C52FC 002C46FC 4600A306 */  mov.s      $fa0, $fs0
    /* C5300 002C4700 0C0AF080 */  jal        sinf
    /* C5304 002C4704 46000506 */   mov.s     $fs0, $fv0
    /* C5308 002C4708 26220001 */  addiu      $v0, $s1, 0x1
    /* C530C 002C470C 00408821 */  addu       $s1, $v0, $zero
    /* C5310 002C4710 00108080 */  sll        $s0, $s0, 2
    /* C5314 002C4714 02131821 */  addu       $v1, $s0, $s3
    /* C5318 002C4718 02128021 */  addu       $s0, $s0, $s2
    /* C531C 002C471C 4600A040 */  add.s      $fv0f, $fs0, $fv0
    /* C5320 002C4720 00021400 */  sll        $v0, $v0, 16
    /* C5324 002C4724 00021403 */  sra        $v0, $v0, 16
    /* C5328 002C4728 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* C532C 002C472C 28420080 */  slti       $v0, $v0, 0x80
    /* C5330 002C4730 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C5334 002C4734 1440FFEA */  bnez       $v0, .L002C46E0
    /* C5338 002C4738 E6000000 */   swc1      $fv0, 0x0($s0)
    /* C533C 002C473C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C5340 002C4740 8FB40020 */  lw         $s4, 0x20($sp)
    /* C5344 002C4744 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C5348 002C4748 8FB20018 */  lw         $s2, 0x18($sp)
    /* C534C 002C474C 8FB10014 */  lw         $s1, 0x14($sp)
    /* C5350 002C4750 8FB00010 */  lw         $s0, 0x10($sp)
    /* C5354 002C4754 D7B70040 */  ldc1       $fs1f, 0x40($sp)
    /* C5358 002C4758 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C535C 002C475C D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C5360 002C4760 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C5364 002C4764 03E00008 */  jr         $ra
    /* C5368 002C4768 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel func_002C4604
