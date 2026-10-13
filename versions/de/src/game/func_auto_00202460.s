.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x3060-0x3898 (VRAM 0x00202460) */
glabel func_auto_00202460
    /* 3060 00202460 3C1A800F */  lui        $k0, %hi(D_auto_800F3130) /* handwritten instruction */
    /* 3064 00202464 275A3130 */  addiu      $k0, $k0, %lo(D_auto_800F3130) /* handwritten instruction */
    /* 3068 00202468 FF410328 */  sd         $at, 0x328($k0) /* handwritten instruction */
    /* 306C 0020246C FF420330 */  sd         $v0, 0x330($k0) /* handwritten instruction */
    /* 3070 00202470 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 3074 00202474 8F420338 */  lw         $v0, 0x338($k0) /* handwritten instruction */
    /* 3078 00202478 00010882 */  srl        $at, $at, 2
    /* 307C 0020247C 3021001F */  andi       $at, $at, 0x1F
    /* 3080 00202480 10200008 */  .word      0x10200008 /* was: beqz       $at, .Lauto_002024A4 */
    /* 3084 00202484 00221006 */   srlv      $v0, $v0, $at
    /* 3088 00202488 30420001 */  andi       $v0, $v0, 0x1
    /* 308C 0020248C 14400054 */  .word      0x14400054 /* was: bnez       $v0, .Lauto_002025E0 */
    /* 3090 00202490 00000000 */   nop
  .Lauto_00202494:
    /* 3094 00202494 DF410328 */  ld         $at, 0x328($k0) /* handwritten instruction */
    /* 3098 00202498 DF420330 */  ld         $v0, 0x330($k0) /* handwritten instruction */
    /* 309C 0020249C 0401FF79 */  .word      0x0401FF79 /* was: bgez       $zero, .Lauto_00202284 */
    /* 30A0 002024A0 00000000 */   nop
  .Lauto_002024A4:
    /* 30A4 002024A4 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 30A8 002024A8 00000000 */  nop
    /* 30AC 002024AC 30210800 */  andi       $at, $at, 0x800
    /* 30B0 002024B0 1020FFF8 */  .word      0x1020FFF8 /* was: beqz       $at, .Lauto_00202494 */
    /* 30B4 002024B4 00000000 */   nop
  .Lauto_002024B8:
    /* 30B8 002024B8 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 30BC 002024BC 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 30C0 002024C0 8C210000 */  lw         $at, 0x0($at)
    /* 30C4 002024C4 00000000 */  nop
    /* 30C8 002024C8 30210003 */  andi       $at, $at, 0x3
    /* 30CC 002024CC 1420FFFA */  .word      0x1420FFFA /* was: bnez       $at, .Lauto_002024B8 */
    /* 30D0 002024D0 00000000 */   nop
    /* 30D4 002024D4 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFD8)
    /* 30D8 002024D8 8C21FFD8 */  lw         $at, %lo(D_auto_B1FFFFD8)($at)
    /* 30DC 002024DC 00000000 */  nop
    /* 30E0 002024E0 3021FFFF */  andi       $at, $at, 0xFFFF
    /* 30E4 002024E4 2021FDFE */  addi       $at, $at, -0x202 /* handwritten instruction */
    /* 30E8 002024E8 1420002E */  .word      0x1420002E /* was: bnez       $at, .Lauto_002025A4 */
    /* 30EC 002024EC 00000000 */   nop
  .Lauto_002024F0:
    /* 30F0 002024F0 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 30F4 002024F4 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 30F8 002024F8 8C210000 */  lw         $at, 0x0($at)
    /* 30FC 002024FC 00000000 */  nop
    /* 3100 00202500 30210003 */  andi       $at, $at, 0x3
    /* 3104 00202504 1420FFFA */  .word      0x1420FFFA /* was: bnez       $at, .Lauto_002024F0 */
    /* 3108 00202508 00000000 */   nop
    /* 310C 0020250C 3C010303 */  lui        $at, (0x3030303 >> 16)
    /* 3110 00202510 34210303 */  ori        $at, $at, (0x3030303 & 0xFFFF)
    /* 3114 00202514 3C02B200 */  lui        $v0, %hi(D_auto_B1FFFFD8)
    /* 3118 00202518 AC41FFD8 */  sw         $at, %lo(D_auto_B1FFFFD8)($v0)
  .Lauto_0020251C:
    /* 311C 0020251C 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 3120 00202520 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 3124 00202524 8C210000 */  lw         $at, 0x0($at)
    /* 3128 00202528 00000000 */  nop
    /* 312C 0020252C 30210003 */  andi       $at, $at, 0x3
    /* 3130 00202530 1420FFFA */  .word      0x1420FFFA /* was: bnez       $at, .Lauto_0020251C */
    /* 3134 00202534 00000000 */   nop
    /* 3138 00202538 3C02B200 */  lui        $v0, %hi(D_auto_B1FFFFD8)
    /* 313C 0020253C 8C41FFD8 */  lw         $at, %lo(D_auto_B1FFFFD8)($v0)
    /* 3140 00202540 3C020303 */  lui        $v0, (0x3030303 >> 16)
    /* 3144 00202544 34420303 */  ori        $v0, $v0, (0x3030303 & 0xFFFF)
    /* 3148 00202548 00220822 */  sub        $at, $at, $v0 /* handwritten instruction */
    /* 314C 0020254C 14200007 */  .word      0x14200007 /* was: bnez       $at, .Lauto_0020256C */
    /* 3150 00202550 00000000 */   nop
    /* 3154 00202554 3C010001 */  lui        $at, (0x10001 >> 16)
    /* 3158 00202558 34210001 */  ori        $at, $at, (0x10001 & 0xFFFF)
  .Lauto_0020255C:
    /* 315C 0020255C 1420FFFF */  .word      0x1420FFFF /* was: bnez       $at, .Lauto_0020255C */
    /* 3160 00202560 2021FFFF */   addi      $at, $at, -0x1 /* handwritten instruction */
    /* 3164 00202564 1020FFED */  .word      0x1020FFED /* was: beqz       $at, .Lauto_0020251C */
    /* 3168 00202568 00000000 */   nop
  .Lauto_0020256C:
    /* 316C 0020256C 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 3170 00202570 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 3174 00202574 8C210000 */  lw         $at, 0x0($at)
    /* 3178 00202578 00000000 */  nop
    /* 317C 0020257C 30210003 */  andi       $at, $at, 0x3
    /* 3180 00202580 1420FFFA */  .word      0x1420FFFA /* was: bnez       $at, .Lauto_0020256C */
    /* 3184 00202584 00000000 */   nop
    /* 3188 00202588 3C02B200 */  lui        $v0, %hi(D_auto_B1FFFFD8)
    /* 318C 0020258C AC40FFD8 */  sw         $zero, %lo(D_auto_B1FFFFD8)($v0)
    /* 3190 00202590 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 3194 00202594 00000000 */  nop
    /* 3198 00202598 34210100 */  ori        $at, $at, 0x100
    /* 319C 0020259C 08080925 */  .word      0x08080925 /* was: j          .Lauto_00202494 */
    /* 31A0 002025A0 40816800 */   mtc0      $at, $13 /* handwritten instruction */
  .Lauto_002025A4:
    /* 31A4 002025A4 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 31A8 002025A8 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 31AC 002025AC 8C210000 */  lw         $at, 0x0($at)
    /* 31B0 002025B0 00000000 */  nop
    /* 31B4 002025B4 30210003 */  andi       $at, $at, 0x3
    /* 31B8 002025B8 1420FFFA */  .word      0x1420FFFA /* was: bnez       $at, .Lauto_002025A4 */
    /* 31BC 002025BC 00000000 */   nop
    /* 31C0 002025C0 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFF0)
    /* 31C4 002025C4 8C21FFF0 */  lw         $at, %lo(D_auto_B1FFFFF0)($at)
    /* 31C8 002025C8 00000000 */  nop
    /* 31CC 002025CC 3021FFFF */  andi       $at, $at, 0xFFFF
    /* 31D0 002025D0 1020FFB0 */  .word      0x1020FFB0 /* was: beqz       $at, .Lauto_00202494 */
    /* 31D4 002025D4 00000000 */   nop
    /* 31D8 002025D8 0401000F */  .word      0x0401000F /* was: bgez       $zero, .Lauto_00202618 */
    /* 31DC 002025DC 00000000 */   nop
  .Lauto_002025E0:
    /* 31E0 002025E0 24020009 */  addiu      $v0, $zero, 0x9
    /* 31E4 002025E4 1422000A */  .word      0x1422000A /* was: bne        $at, $v0, .Lauto_00202610 */
    /* 31E8 002025E8 00000000 */   nop
    /* 31EC 002025EC 40027000 */  mfc0       $v0, $14 /* handwritten instruction */
    /* 31F0 002025F0 00000000 */  nop
    /* 31F4 002025F4 8C420000 */  lw         $v0, 0x0($v0)
    /* 31F8 002025F8 00000000 */  nop
    /* 31FC 002025FC 00021182 */  srl        $v0, $v0, 6
    /* 3200 00202600 2441FC00 */  addiu      $at, $v0, -0x400
    /* 3204 00202604 04210077 */  .word      0x04210077 /* was: bgez       $at, .Lauto_002027E4 */
    /* 3208 00202608 00000000 */   nop
  .Lauto_0020260C:
    /* 320C 0020260C 24010009 */  addiu      $at, $zero, 0x9
  .Lauto_00202610:
    /* 3210 00202610 A3410320 */  sb         $at, 0x320($k0) /* handwritten instruction */
    /* 3214 00202614 A3400322 */  sb         $zero, 0x322($k0) /* handwritten instruction */
  .Lauto_00202618:
    /* 3218 00202618 24010001 */  addiu      $at, $zero, 0x1
    /* 321C 0020261C AF41033C */  sw         $at, 0x33C($k0) /* handwritten instruction */
    /* 3220 00202620 DF410328 */  ld         $at, 0x328($k0) /* handwritten instruction */
    /* 3224 00202624 DF420330 */  ld         $v0, 0x330($k0) /* handwritten instruction */
    /* 3228 00202628 FF5F00F8 */  sd         $ra, 0xF8($k0) /* handwritten instruction */
    /* 322C 0020262C 0C080A65 */  jal        func_00202994
    /* 3230 00202630 00000000 */   nop
    /* 3234 00202634 3C1D800F */  lui        $sp, %hi(D_auto_800F3CB0)
    /* 3238 00202638 27BD3CB0 */  addiu      $sp, $sp, %lo(D_auto_800F3CB0)
    /* 323C 0020263C 0C080529 */  jal        func_002014A4
    /* 3240 00202640 00000000 */   nop
    /* 3244 00202644 0C0808E3 */  jal        func_0020238C
    /* 3248 00202648 00000000 */   nop
    /* 324C 0020264C 0C0808EA */  jal        func_002023A8
    /* 3250 00202650 00000000 */   nop
    /* 3254 00202654 3C1A800F */  lui        $k0, %hi(D_auto_800F3130) /* handwritten instruction */
    /* 3258 00202658 275A3130 */  addiu      $k0, $k0, %lo(D_auto_800F3130) /* handwritten instruction */
    /* 325C 0020265C 24010001 */  addiu      $at, $zero, 0x1
    /* 3260 00202660 A3410320 */  sb         $at, 0x320($k0) /* handwritten instruction */
    /* 3264 00202664 DF480108 */  ld         $t0, 0x108($k0) /* handwritten instruction */
    /* 3268 00202668 00000000 */  nop
    /* 326C 0020266C 01000011 */  mthi       $t0
    /* 3270 00202670 DF480100 */  ld         $t0, 0x100($k0) /* handwritten instruction */
    /* 3274 00202674 00000000 */  nop
    /* 3278 00202678 01000013 */  mtlo       $t0
    /* 327C 0020267C DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 3280 00202680 00000000 */  nop
    /* 3284 00202684 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
    /* 3288 00202688 DF480110 */  ld         $t0, 0x110($k0) /* handwritten instruction */
    /* 328C 0020268C 00000000 */  nop
    /* 3290 00202690 40887000 */  mtc0       $t0, $14 /* handwritten instruction */
    /* 3294 00202694 DF4800D0 */  ld         $t0, 0xD0($k0) /* handwritten instruction */
    /* 3298 00202698 00000000 */  nop
    /* 329C 0020269C 4088F000 */  mtc0       $t0, $30 /* handwritten instruction */
    /* 32A0 002026A0 DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 32A4 002026A4 3C092000 */  lui        $t1, (0x20000000 >> 16)
    /* 32A8 002026A8 01284824 */  and        $t1, $t1, $t0
    /* 32AC 002026AC 1120002C */  .word      0x1120002C /* was: beqz       $t1, .Lauto_00202760 */
    /* 32B0 002026B0 00000000 */   nop
    /* 32B4 002026B4 8F480318 */  lw         $t0, 0x318($k0) /* handwritten instruction */
    /* 32B8 002026B8 00000000 */  nop
    /* 32BC 002026BC 44C80000 */  ctc1       $t0, $0
    /* 32C0 002026C0 8F48031C */  lw         $t0, 0x31C($k0) /* handwritten instruction */
    /* 32C4 002026C4 00000000 */  nop
    /* 32C8 002026C8 44C8F800 */  ctc1       $t0, $31
    /* 32CC 002026CC D7400218 */  ldc1       $fv0, 0x218($k0)
    /* 32D0 002026D0 D7420228 */  ldc1       $fv1, 0x228($k0)
    /* 32D4 002026D4 D7440238 */  ldc1       $ft0, 0x238($k0)
    /* 32D8 002026D8 D7460248 */  ldc1       $ft1, 0x248($k0)
    /* 32DC 002026DC D7480258 */  ldc1       $ft2, 0x258($k0)
    /* 32E0 002026E0 D74A0268 */  ldc1       $ft3, 0x268($k0)
    /* 32E4 002026E4 D74C0278 */  ldc1       $fa0, 0x278($k0)
    /* 32E8 002026E8 D74E0288 */  ldc1       $fa1, 0x288($k0)
    /* 32EC 002026EC D7500298 */  ldc1       $ft4, 0x298($k0)
    /* 32F0 002026F0 D75202A8 */  ldc1       $ft5, 0x2A8($k0)
    /* 32F4 002026F4 D75402B8 */  ldc1       $fs0, 0x2B8($k0)
    /* 32F8 002026F8 D75602C8 */  ldc1       $fs1, 0x2C8($k0)
    /* 32FC 002026FC D75802D8 */  ldc1       $fs2, 0x2D8($k0)
    /* 3300 00202700 D75A02E8 */  ldc1       $fs3, 0x2E8($k0)
    /* 3304 00202704 D75C02F8 */  ldc1       $fs4, 0x2F8($k0)
    /* 3308 00202708 D75E0308 */  ldc1       $fs5, 0x308($k0)
    /* 330C 0020270C DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 3310 00202710 3C090400 */  lui        $t1, (0x4000000 >> 16)
    /* 3314 00202714 01284824 */  and        $t1, $t1, $t0
    /* 3318 00202718 11200011 */  .word      0x11200011 /* was: beqz       $t1, .Lauto_00202760 */
    /* 331C 0020271C 00000000 */   nop
    /* 3320 00202720 D7410220 */  ldc1       $fv0f, 0x220($k0)
    /* 3324 00202724 D7430230 */  ldc1       $fv1f, 0x230($k0)
    /* 3328 00202728 D7450240 */  ldc1       $ft0f, 0x240($k0)
    /* 332C 0020272C D7470250 */  ldc1       $ft1f, 0x250($k0)
    /* 3330 00202730 D7490260 */  ldc1       $ft2f, 0x260($k0)
    /* 3334 00202734 D74B0270 */  ldc1       $ft3f, 0x270($k0)
    /* 3338 00202738 D74D0280 */  ldc1       $fa0f, 0x280($k0)
    /* 333C 0020273C D74F0290 */  ldc1       $fa1f, 0x290($k0)
    /* 3340 00202740 D75102A0 */  ldc1       $ft4f, 0x2A0($k0)
    /* 3344 00202744 D75302B0 */  ldc1       $ft5f, 0x2B0($k0)
    /* 3348 00202748 D75502C0 */  ldc1       $fs0f, 0x2C0($k0)
    /* 334C 0020274C D75702D0 */  ldc1       $fs1f, 0x2D0($k0)
    /* 3350 00202750 D75902E0 */  ldc1       $fs2f, 0x2E0($k0)
    /* 3354 00202754 D75B02F0 */  ldc1       $fs3f, 0x2F0($k0)
    /* 3358 00202758 D75D0300 */  ldc1       $fs4f, 0x300($k0)
    /* 335C 0020275C D75F0310 */  ldc1       $fs5f, 0x310($k0)
  .Lauto_00202760:
    /* 3360 00202760 DF410008 */  ld         $at, 0x8($k0) /* handwritten instruction */
    /* 3364 00202764 DF420010 */  ld         $v0, 0x10($k0) /* handwritten instruction */
    /* 3368 00202768 DF430018 */  ld         $v1, 0x18($k0) /* handwritten instruction */
    /* 336C 0020276C DF440020 */  ld         $a0, 0x20($k0) /* handwritten instruction */
    /* 3370 00202770 DF450028 */  ld         $a1, 0x28($k0) /* handwritten instruction */
    /* 3374 00202774 DF460030 */  ld         $a2, 0x30($k0) /* handwritten instruction */
    /* 3378 00202778 DF470038 */  ld         $a3, 0x38($k0) /* handwritten instruction */
    /* 337C 0020277C DF480040 */  ld         $t0, 0x40($k0) /* handwritten instruction */
    /* 3380 00202780 DF490048 */  ld         $t1, 0x48($k0) /* handwritten instruction */
    /* 3384 00202784 DF4A0050 */  ld         $t2, 0x50($k0) /* handwritten instruction */
    /* 3388 00202788 DF4B0058 */  ld         $t3, 0x58($k0) /* handwritten instruction */
    /* 338C 0020278C DF4C0060 */  ld         $t4, 0x60($k0) /* handwritten instruction */
    /* 3390 00202790 DF4D0068 */  ld         $t5, 0x68($k0) /* handwritten instruction */
    /* 3394 00202794 DF4E0070 */  ld         $t6, 0x70($k0) /* handwritten instruction */
    /* 3398 00202798 DF4F0078 */  ld         $t7, 0x78($k0) /* handwritten instruction */
    /* 339C 0020279C DF500080 */  ld         $s0, 0x80($k0) /* handwritten instruction */
    /* 33A0 002027A0 DF510088 */  ld         $s1, 0x88($k0) /* handwritten instruction */
    /* 33A4 002027A4 DF520090 */  ld         $s2, 0x90($k0) /* handwritten instruction */
    /* 33A8 002027A8 DF530098 */  ld         $s3, 0x98($k0) /* handwritten instruction */
    /* 33AC 002027AC DF5400A0 */  ld         $s4, 0xA0($k0) /* handwritten instruction */
    /* 33B0 002027B0 DF5500A8 */  ld         $s5, 0xA8($k0) /* handwritten instruction */
    /* 33B4 002027B4 DF5600B0 */  ld         $s6, 0xB0($k0) /* handwritten instruction */
    /* 33B8 002027B8 DF5700B8 */  ld         $s7, 0xB8($k0) /* handwritten instruction */
    /* 33BC 002027BC DF5800C0 */  ld         $t8, 0xC0($k0) /* handwritten instruction */
    /* 33C0 002027C0 DF5900C8 */  ld         $t9, 0xC8($k0) /* handwritten instruction */
    /* 33C4 002027C4 DF5B00D8 */  ld         $k1, 0xD8($k0) /* handwritten instruction */
    /* 33C8 002027C8 DF5C00E0 */  ld         $gp, 0xE0($k0) /* handwritten instruction */
    /* 33CC 002027CC DF5D00E8 */  ld         $sp, 0xE8($k0) /* handwritten instruction */
    /* 33D0 002027D0 DF5E00F0 */  ld         $fp, 0xF0($k0) /* handwritten instruction */
    /* 33D4 002027D4 DF5F00F8 */  ld         $ra, 0xF8($k0) /* handwritten instruction */
    /* 33D8 002027D8 AF40033C */  sw         $zero, 0x33C($k0) /* handwritten instruction */
    /* 33DC 002027DC 401AF000 */  mfc0       $k0, $30 /* handwritten instruction */
    /* 33E0 002027E0 42000018 */  eret /* handwritten instruction */
  .Lauto_002027E4:
    /* 33E4 002027E4 2441FBF7 */  addiu      $at, $v0, -0x409
    /* 33E8 002027E8 0421FF88 */  .word      0x0421FF88 /* was: bgez       $at, .Lauto_0020260C */
    /* 33EC 002027EC 00000000 */   nop
    /* 33F0 002027F0 3C010020 */  lui        $at, %hi(jtbl_auto_00202814)
    /* 33F4 002027F4 24212814 */  addiu      $at, $at, %lo(jtbl_auto_00202814)
    /* 33F8 002027F8 2442FC00 */  addiu      $v0, $v0, -0x400
    /* 33FC 002027FC 00021080 */  sll        $v0, $v0, 2
    /* 3400 00202800 00411021 */  addu       $v0, $v0, $at
    /* 3404 00202804 8C420000 */  lw         $v0, 0x0($v0)
    /* 3408 00202808 00000000 */  nop
    /* 340C 0020280C 00400008 */  jr         $v0
    /* 3410 00202810 00000000 */   nop
  jtbl_auto_00202814:
    /* 3414 00202814 00202838 */  .word      0x00202838                    # dsll       $a1, $zero, 0 # 00200000 <InstrIdType: CPU_SPECIAL>
    /* 3418 00202818 0020288C */  .word      0x0020288C                    # syscall    162 # 00200000 <InstrIdType: CPU_SPECIAL> /* handwritten instruction */
    /* 341C 0020281C 00202898 */  .word      0x00202898                    # mult       $at, $zero # 00002880 <InstrIdType: CPU_SPECIAL>
    /* 3420 00202820 0020260C */  .word      0x0020260C                    # syscall    152 # 00200000 <InstrIdType: CPU_SPECIAL> /* handwritten instruction */
    /* 3424 00202824 002028A4 */  .word      0x002028A4                    # and        $a1, $at, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    /* 3428 00202828 002028AC */  .word      0x002028AC                    # dadd       $a1, $at, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    /* 342C 0020282C 0020293C */  .word      0x0020293C                    # dsll32     $a1, $zero, 4 # 00200000 <InstrIdType: CPU_SPECIAL>
    /* 3430 00202830 00202948 */  .word      0x00202948                    # jr         $at # 00002940 <InstrIdType: CPU_SPECIAL>
    /* 3434 00202834 00202964 */   .word     0x00202964                     # and       $a1, $at, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    /* 3438 00202838 8F41033C */  lw         $at, 0x33C($k0) /* handwritten instruction */
    /* 343C 0020283C 00000000 */  nop
    /* 3440 00202840 1420004C */  .word      0x1420004C /* was: bnez       $at, .Lauto_00202974 */
    /* 3444 00202844 00000000 */   nop
    /* 3448 00202848 24010064 */  addiu      $at, $zero, 0x64
  .Lauto_0020284C:
    /* 344C 0020284C 1420FFFF */  .word      0x1420FFFF /* was: bnez       $at, .Lauto_0020284C */
    /* 3450 00202850 2021FFFF */   addi      $at, $at, -0x1 /* handwritten instruction */
    /* 3454 00202854 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 3458 00202858 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
  .Lauto_0020285C:
    /* 345C 0020285C 8C220000 */  lw         $v0, 0x0($at)
    /* 3460 00202860 00000000 */  nop
    /* 3464 00202864 30420003 */  andi       $v0, $v0, 0x3
    /* 3468 00202868 1440FFFC */  .word      0x1440FFFC /* was: bnez       $v0, .Lauto_0020285C */
    /* 346C 0020286C 00000000 */   nop
    /* 3470 00202870 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFF0)
    /* 3474 00202874 8C21FFF0 */  lw         $at, %lo(D_auto_B1FFFFF0)($at)
    /* 3478 00202878 00000000 */  nop
    /* 347C 0020287C 1020003D */  .word      0x1020003D /* was: beqz       $at, .Lauto_00202974 */
    /* 3480 00202880 00000000 */   nop
    /* 3484 00202884 0401FF64 */  .word      0x0401FF64 /* was: bgez       $zero, .Lauto_00202618 */
    /* 3488 00202888 00000000 */   nop
    /* 348C 0020288C 2401FFFF */  addiu      $at, $zero, -0x1
    /* 3490 00202890 08080984 */  .word      0x08080984 /* was: j          .Lauto_00202610 */
    /* 3494 00202894 00000000 */   nop
    /* 3498 00202898 2401FFFF */  addiu      $at, $zero, -0x1
    /* 349C 0020289C 08080984 */  .word      0x08080984 /* was: j          .Lauto_00202610 */
    /* 34A0 002028A0 00000000 */   nop
    /* 34A4 002028A4 08080983 */  .word      0x08080983 /* was: j          .Lauto_0020260C */
    /* 34A8 002028A8 00000000 */   nop
    /* 34AC 002028AC FF430018 */  sd         $v1, 0x18($k0) /* handwritten instruction */
    /* 34B0 002028B0 FF440020 */  sd         $a0, 0x20($k0) /* handwritten instruction */
    /* 34B4 002028B4 FF5F00F8 */  sd         $ra, 0xF8($k0) /* handwritten instruction */
    /* 34B8 002028B8 04110005 */  bal        func_002028D0 /* handwritten instruction */
    /* 34BC 002028BC 00000000 */   nop
    /* 34C0 002028C0 DF5F00F8 */  ld         $ra, 0xF8($k0) /* handwritten instruction */
    /* 34C4 002028C4 DF440020 */  ld         $a0, 0x20($k0) /* handwritten instruction */
    /* 34C8 002028C8 0401002A */  .word      0x0401002A /* was: bgez       $zero, .Lauto_00202974 */
    /* 34CC 002028CC DF430018 */   ld        $v1, 0x18($k0) /* handwritten instruction */
  alabel func_002028D0
    /* 34D0 002028D0 3C038000 */  lui        $v1, (0x80000180 >> 16)
    /* 34D4 002028D4 34630180 */  ori        $v1, $v1, (0x80000180 & 0xFFFF)
    /* 34D8 002028D8 3C020020 */  .word      0x3C020020 /* was: lui        $v0, %hi(.Lauto_00202284) */
    /* 34DC 002028DC 24422284 */  .word      0x24422284 /* was: addiu      $v0, $v0, %lo(.Lauto_00202284) */
    /* 34E0 002028E0 20440014 */  addi       $a0, $v0, 0x14 /* handwritten instruction */
  .Lauto_002028E4:
    /* 34E4 002028E4 8C410000 */  lw         $at, 0x0($v0)
    /* 34E8 002028E8 20420004 */  addi       $v0, $v0, 0x4 /* handwritten instruction */
    /* 34EC 002028EC AC610000 */  sw         $at, 0x0($v1)
    /* 34F0 002028F0 20630004 */  addi       $v1, $v1, 0x4 /* handwritten instruction */
    /* 34F4 002028F4 1444FFFB */  .word      0x1444FFFB /* was: bne        $v0, $a0, .Lauto_002028E4 */
    /* 34F8 002028F8 00000000 */   nop
    /* 34FC 002028FC 3C038000 */  lui        $v1, %hi(D_auto_80000000)
    /* 3500 00202900 3C020020 */  lui        $v0, %hi(D_auto_002022BC)
    /* 3504 00202904 244222BC */  addiu      $v0, $v0, %lo(D_auto_002022BC)
    /* 3508 00202908 20440014 */  addi       $a0, $v0, 0x14 /* handwritten instruction */
  .Lauto_0020290C:
    /* 350C 0020290C 8C410000 */  lw         $at, 0x0($v0)
    /* 3510 00202910 20420004 */  addi       $v0, $v0, 0x4 /* handwritten instruction */
    /* 3514 00202914 AC610000 */  sw         $at, %lo(D_auto_80000000)($v1)
    /* 3518 00202918 20630004 */  addi       $v1, $v1, %lo(D_auto_80000004) /* handwritten instruction */
    /* 351C 0020291C 1444FFFB */  .word      0x1444FFFB /* was: bne        $v0, $a0, .Lauto_0020290C */
    /* 3520 00202920 00000000 */   nop
    /* 3524 00202924 0C0808E3 */  jal        func_0020238C
    /* 3528 00202928 00000000 */   nop
    /* 352C 0020292C 0C0808EA */  jal        func_002023A8
    /* 3530 00202930 00000000 */   nop
    /* 3534 00202934 03E00008 */  jr         $ra
    /* 3538 00202938 00000000 */   nop
    /* 353C 0020293C AF440338 */  sw         $a0, 0x338($k0) /* handwritten instruction */
    /* 3540 00202940 08080A5D */  .word      0x08080A5D /* was: j          .Lauto_00202974 */
    /* 3544 00202944 00000000 */   nop
    /* 3548 00202948 40017000 */  mfc0       $at, $14 /* handwritten instruction */
    /* 354C 0020294C 00000000 */  nop
    /* 3550 00202950 24210004 */  addiu      $at, $at, 0x4
    /* 3554 00202954 40817000 */  mtc0       $at, $14 /* handwritten instruction */
    /* 3558 00202958 24010000 */  addiu      $at, $zero, 0x0
    /* 355C 0020295C 08080984 */  .word      0x08080984 /* was: j          .Lauto_00202610 */
    /* 3560 00202960 00000000 */   nop
    /* 3564 00202964 3C020020 */  lui        $v0, %hi(func_002013D8)
    /* 3568 00202968 244213D8 */  addiu      $v0, $v0, %lo(func_002013D8)
    /* 356C 0020296C 08080A5E */  .word      0x08080A5E /* was: j          .Lauto_00202978 */
    /* 3570 00202970 00000000 */   nop
  .Lauto_00202974:
    /* 3574 00202974 DF420330 */  ld         $v0, 0x330($k0) /* handwritten instruction */
  .Lauto_00202978:
    /* 3578 00202978 40017000 */  mfc0       $at, $14 /* handwritten instruction */
    /* 357C 0020297C 00000000 */  nop
    /* 3580 00202980 24210004 */  addiu      $at, $at, 0x4
    /* 3584 00202984 40817000 */  mtc0       $at, $14 /* handwritten instruction */
    /* 3588 00202988 DF410328 */  ld         $at, 0x328($k0) /* handwritten instruction */
    /* 358C 0020298C 401AF000 */  mfc0       $k0, $30 /* handwritten instruction */
    /* 3590 00202990 42000018 */  eret /* handwritten instruction */
  alabel func_00202994
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
    /* 37B0 00202BB0 1120002C */  .word      0x1120002C /* was: beqz       $t1, .Lauto_00202C64 */
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
    /* 381C 00202C1C 11200011 */  .word      0x11200011 /* was: beqz       $t1, .Lauto_00202C64 */
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
  .Lauto_00202C64:
    /* 3864 00202C64 DF480178 */  ld         $t0, 0x178($k0) /* handwritten instruction */
    /* 3868 00202C68 00000000 */  nop
    /* 386C 00202C6C 31080004 */  andi       $t0, $t0, 0x4
    /* 3870 00202C70 15000004 */  .word      0x15000004 /* was: bnez       $t0, .Lauto_00202C84 */
    /* 3874 00202C74 00000000 */   nop
    /* 3878 00202C78 DF480188 */  ld         $t0, 0x188($k0) /* handwritten instruction */
    /* 387C 00202C7C 08080B23 */  .word      0x08080B23 /* was: j          .Lauto_00202C8C */
    /* 3880 00202C80 00000000 */   nop
  .Lauto_00202C84:
    /* 3884 00202C84 DF480208 */  ld         $t0, 0x208($k0) /* handwritten instruction */
    /* 3888 00202C88 00000000 */  nop
  .Lauto_00202C8C:
    /* 388C 00202C8C FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* 3890 00202C90 03E00008 */  jr         $ra
    /* 3894 00202C94 00000000 */   nop
endlabel func_auto_00202460
