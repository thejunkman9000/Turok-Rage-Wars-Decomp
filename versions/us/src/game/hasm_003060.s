.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0x3060-0x34D0 (VRAM 0x00202460) */
.globl func_auto_00202460
func_auto_00202460:
    /* 3060 00202460 3C1A800F */  lui        $k0, %hi(D_auto_800F1130) /* handwritten instruction */
    /* 3064 00202464 275A1130 */  addiu      $k0, $k0, %lo(D_auto_800F1130) /* handwritten instruction */
    /* 3068 00202468 FF410328 */  sd         $at, 0x328($k0) /* handwritten instruction */
    /* 306C 0020246C FF420330 */  sd         $v0, 0x330($k0) /* handwritten instruction */
    /* 3070 00202470 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 3074 00202474 8F420338 */  lw         $v0, 0x338($k0) /* handwritten instruction */
    /* 3078 00202478 00010882 */  srl        $at, $at, 2
    /* 307C 0020247C 3021001F */  andi       $at, $at, 0x1F
    /* 3080 00202480 10200008 */  .word 0x10200008
    /* 3084 00202484 00221006 */  srlv      $v0, $v0, $at
    /* 3088 00202488 30420001 */  andi       $v0, $v0, 0x1
    /* 308C 0020248C 14400054 */  .word 0x14400054
    /* 3090 00202490 00000000 */  nop
.Lauto_00202494:
    /* 3094 00202494 DF410328 */  ld         $at, 0x328($k0) /* handwritten instruction */
    /* 3098 00202498 DF420330 */  ld         $v0, 0x330($k0) /* handwritten instruction */
    /* 309C 0020249C 0401FF79 */  .word 0x0401FF79
    /* 30A0 002024A0 00000000 */  nop
.Lauto_002024A4:
    /* 30A4 002024A4 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 30A8 002024A8 00000000 */  nop
    /* 30AC 002024AC 30210800 */  andi       $at, $at, 0x800
    /* 30B0 002024B0 1020FFF8 */  .word 0x1020FFF8
    /* 30B4 002024B4 00000000 */  nop
.Lauto_002024B8:
    /* 30B8 002024B8 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 30BC 002024BC 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 30C0 002024C0 8C210000 */  lw         $at, 0x0($at)
    /* 30C4 002024C4 00000000 */  nop
    /* 30C8 002024C8 30210003 */  andi       $at, $at, 0x3
    /* 30CC 002024CC 1420FFFA */  .word 0x1420FFFA
    /* 30D0 002024D0 00000000 */  nop
    /* 30D4 002024D4 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFD8)
    /* 30D8 002024D8 8C21FFD8 */  lw         $at, %lo(D_auto_B1FFFFD8)($at)
    /* 30DC 002024DC 00000000 */  nop
    /* 30E0 002024E0 3021FFFF */  andi       $at, $at, 0xFFFF
    /* 30E4 002024E4 2021FDFE */  addi       $at, $at, -0x202 /* handwritten instruction */
    /* 30E8 002024E8 1420002E */  .word 0x1420002E
    /* 30EC 002024EC 00000000 */  nop
.Lauto_002024F0:
    /* 30F0 002024F0 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 30F4 002024F4 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 30F8 002024F8 8C210000 */  lw         $at, 0x0($at)
    /* 30FC 002024FC 00000000 */  nop
    /* 3100 00202500 30210003 */  andi       $at, $at, 0x3
    /* 3104 00202504 1420FFFA */  .word 0x1420FFFA
    /* 3108 00202508 00000000 */  nop
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
    /* 3130 00202530 1420FFFA */  .word 0x1420FFFA
    /* 3134 00202534 00000000 */  nop
    /* 3138 00202538 3C02B200 */  lui        $v0, %hi(D_auto_B1FFFFD8)
    /* 313C 0020253C 8C41FFD8 */  lw         $at, %lo(D_auto_B1FFFFD8)($v0)
    /* 3140 00202540 3C020303 */  lui        $v0, (0x3030303 >> 16)
    /* 3144 00202544 34420303 */  ori        $v0, $v0, (0x3030303 & 0xFFFF)
    /* 3148 00202548 00220822 */  sub        $at, $at, $v0 /* handwritten instruction */
    /* 314C 0020254C 14200007 */  .word 0x14200007
    /* 3150 00202550 00000000 */  nop
    /* 3154 00202554 3C010001 */  lui        $at, (0x10001 >> 16)
    /* 3158 00202558 34210001 */  ori        $at, $at, (0x10001 & 0xFFFF)
.Lauto_0020255C:
    /* 315C 0020255C 1420FFFF */  .word 0x1420FFFF
    /* 3160 00202560 2021FFFF */  addi      $at, $at, -0x1 /* handwritten instruction */
    /* 3164 00202564 1020FFED */  .word 0x1020FFED
    /* 3168 00202568 00000000 */  nop
.Lauto_0020256C:
    /* 316C 0020256C 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 3170 00202570 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 3174 00202574 8C210000 */  lw         $at, 0x0($at)
    /* 3178 00202578 00000000 */  nop
    /* 317C 0020257C 30210003 */  andi       $at, $at, 0x3
    /* 3180 00202580 1420FFFA */  .word 0x1420FFFA
    /* 3184 00202584 00000000 */  nop
    /* 3188 00202588 3C02B200 */  lui        $v0, %hi(D_auto_B1FFFFD8)
    /* 318C 0020258C AC40FFD8 */  sw         $zero, %lo(D_auto_B1FFFFD8)($v0)
    /* 3190 00202590 40016800 */  mfc0       $at, $13 /* handwritten instruction */
    /* 3194 00202594 00000000 */  nop
    /* 3198 00202598 34210100 */  ori        $at, $at, 0x100
    /* 319C 0020259C 08080925 */  .word 0x08080925
    /* 31A0 002025A0 40816800 */  mtc0      $at, $13 /* handwritten instruction */
.Lauto_002025A4:
    /* 31A4 002025A4 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 31A8 002025A8 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
    /* 31AC 002025AC 8C210000 */  lw         $at, 0x0($at)
    /* 31B0 002025B0 00000000 */  nop
    /* 31B4 002025B4 30210003 */  andi       $at, $at, 0x3
    /* 31B8 002025B8 1420FFFA */  .word 0x1420FFFA
    /* 31BC 002025BC 00000000 */  nop
    /* 31C0 002025C0 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFF0)
    /* 31C4 002025C4 8C21FFF0 */  lw         $at, %lo(D_auto_B1FFFFF0)($at)
    /* 31C8 002025C8 00000000 */  nop
    /* 31CC 002025CC 3021FFFF */  andi       $at, $at, 0xFFFF
    /* 31D0 002025D0 1020FFB0 */  .word 0x1020FFB0
    /* 31D4 002025D4 00000000 */  nop
    /* 31D8 002025D8 0401000F */  .word 0x0401000F
    /* 31DC 002025DC 00000000 */  nop
.Lauto_002025E0:
    /* 31E0 002025E0 24020009 */  addiu      $v0, $zero, 0x9
    /* 31E4 002025E4 1422000A */  .word 0x1422000A
    /* 31E8 002025E8 00000000 */  nop
    /* 31EC 002025EC 40027000 */  mfc0       $v0, $14 /* handwritten instruction */
    /* 31F0 002025F0 00000000 */  nop
    /* 31F4 002025F4 8C420000 */  lw         $v0, 0x0($v0)
    /* 31F8 002025F8 00000000 */  nop
    /* 31FC 002025FC 00021182 */  srl        $v0, $v0, 6
    /* 3200 00202600 2441FC00 */  addiu      $at, $v0, -0x400
    /* 3204 00202604 04210077 */  .word 0x04210077
    /* 3208 00202608 00000000 */  nop
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
    /* 3230 00202630 00000000 */  nop
    /* 3234 00202634 3C1D800F */  lui        $sp, %hi(D_auto_800F1CB0)
    /* 3238 00202638 27BD1CB0 */  addiu      $sp, $sp, %lo(D_auto_800F1CB0)
    /* 323C 0020263C 0C080529 */  jal        func_002014A4
    /* 3240 00202640 00000000 */  nop
    /* 3244 00202644 0C0808E3 */  jal        func_0020238C
    /* 3248 00202648 00000000 */  nop
    /* 324C 0020264C 0C0808EA */  jal        func_002023A8
    /* 3250 00202650 00000000 */  nop
    /* 3254 00202654 3C1A800F */  lui        $k0, %hi(D_auto_800F1130) /* handwritten instruction */
    /* 3258 00202658 275A1130 */  addiu      $k0, $k0, %lo(D_auto_800F1130) /* handwritten instruction */
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
    /* 32AC 002026AC 1120002C */  .word 0x1120002C
    /* 32B0 002026B0 00000000 */  nop
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
    /* 3318 00202718 11200011 */  .word 0x11200011
    /* 331C 0020271C 00000000 */  nop
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
    /* 33E8 002027E8 0421FF88 */  .word 0x0421FF88
    /* 33EC 002027EC 00000000 */  nop
    /* 33F0 002027F0 3C010020 */  lui        $at, %hi(jtbl_auto_00202814)
    /* 33F4 002027F4 24212814 */  addiu      $at, $at, %lo(jtbl_auto_00202814)
    /* 33F8 002027F8 2442FC00 */  addiu      $v0, $v0, -0x400
    /* 33FC 002027FC 00021080 */  sll        $v0, $v0, 2
    /* 3400 00202800 00411021 */  addu       $v0, $v0, $at
    /* 3404 00202804 8C420000 */  lw         $v0, 0x0($v0)
    /* 3408 00202808 00000000 */  nop
    /* 340C 0020280C 00400008 */  jr         $v0
    /* 3410 00202810 00000000 */  nop
    /* 3414 00202814 00202838 */  .word 0x00202838
    /* 3418 00202818 0020288C */  .word 0x0020288C
    /* 341C 0020281C 00202898 */  .word 0x00202898
    /* 3420 00202820 0020260C */  .word 0x0020260C
    /* 3424 00202824 002028A4 */  .word 0x002028A4
    /* 3428 00202828 002028AC */  .word 0x002028AC
    /* 342C 0020282C 0020293C */  .word 0x0020293C
    /* 3430 00202830 00202948 */  .word 0x00202948
    /* 3434 00202834 00202964 */  .word 0x00202964
    /* 3438 00202838 8F41033C */  lw         $at, 0x33C($k0) /* handwritten instruction */
    /* 343C 0020283C 00000000 */  nop
    /* 3440 00202840 1420004C */  .word 0x1420004C
    /* 3444 00202844 00000000 */  nop
    /* 3448 00202848 24010064 */  addiu      $at, $zero, 0x64
.Lauto_0020284C:
    /* 344C 0020284C 1420FFFF */  .word 0x1420FFFF
    /* 3450 00202850 2021FFFF */  addi      $at, $at, -0x1 /* handwritten instruction */
    /* 3454 00202854 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* 3458 00202858 34210010 */  ori        $at, $at, %lo(PI_STATUS_REG)
.Lauto_0020285C:
    /* 345C 0020285C 8C220000 */  lw         $v0, 0x0($at)
    /* 3460 00202860 00000000 */  nop
    /* 3464 00202864 30420003 */  andi       $v0, $v0, 0x3
    /* 3468 00202868 1440FFFC */  .word 0x1440FFFC
    /* 346C 0020286C 00000000 */  nop
    /* 3470 00202870 3C01B200 */  lui        $at, %hi(D_auto_B1FFFFF0)
    /* 3474 00202874 8C21FFF0 */  lw         $at, %lo(D_auto_B1FFFFF0)($at)
    /* 3478 00202878 00000000 */  nop
    /* 347C 0020287C 1020003D */  .word 0x1020003D
    /* 3480 00202880 00000000 */  nop
    /* 3484 00202884 0401FF64 */  .word 0x0401FF64
    /* 3488 00202888 00000000 */  nop
    /* 348C 0020288C 2401FFFF */  addiu      $at, $zero, -0x1
    /* 3490 00202890 08080984 */  .word 0x08080984
    /* 3494 00202894 00000000 */  nop
    /* 3498 00202898 2401FFFF */  addiu      $at, $zero, -0x1
    /* 349C 0020289C 08080984 */  .word 0x08080984
    /* 34A0 002028A0 00000000 */  nop
    /* 34A4 002028A4 08080983 */  .word 0x08080983
    /* 34A8 002028A8 00000000 */  nop
    /* 34AC 002028AC FF430018 */  sd         $v1, 0x18($k0) /* handwritten instruction */
    /* 34B0 002028B0 FF440020 */  sd         $a0, 0x20($k0) /* handwritten instruction */
    /* 34B4 002028B4 FF5F00F8 */  sd         $ra, 0xF8($k0) /* handwritten instruction */
    /* 34B8 002028B8 04110005 */  bal        func_002028D0 /* handwritten instruction */
    /* 34BC 002028BC 00000000 */  nop
    /* 34C0 002028C0 DF5F00F8 */  ld         $ra, 0xF8($k0) /* handwritten instruction */
    /* 34C4 002028C4 DF440020 */  ld         $a0, 0x20($k0) /* handwritten instruction */
    /* 34C8 002028C8 0401002A */  .word 0x0401002A
    /* 34CC 002028CC DF430018 */  ld        $v1, 0x18($k0) /* handwritten instruction */
