.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBAC38-0xBAE88 (VRAM 0x002BA038) */
glabel _getRate
    /* BAC38 002BA038 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* BAC3C 002BA03C 8FA20058 */  lw         $v0, 0x58($sp)
    /* BAC40 002BA040 3C01800D */  lui        $at, %hi(D_800CC8E8)
    /* BAC44 002BA044 C420C8E8 */  lwc1       $fv0, %lo(D_800CC8E8)($at)
    /* BAC48 002BA048 8FA5005C */  lw         $a1, 0x5C($sp)
    /* BAC4C 002BA04C 44820800 */  mtc1       $v0, $fv0f
    /* BAC50 002BA050 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BAC54 002BA054 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* BAC58 002BA058 1440000B */  bnez       $v0, .L002BA088
    /* BAC5C 002BA05C 460000A1 */   cvt.d.s   $fv1, $fv0
    /* BAC60 002BA060 462E603E */  c.le.d     $fa0, $fa1
    /* BAC64 002BA064 00000000 */  nop
    /* BAC68 002BA068 45000004 */  bc1f       .L002BA07C
    /* BAC6C 002BA06C 3402FFFF */   ori       $v0, $zero, 0xFFFF
    /* BAC70 002BA070 A4A20000 */  sh         $v0, 0x0($a1)
    /* BAC74 002BA074 080AE8A0 */  j          .L002BA280
    /* BAC78 002BA078 24027FFF */   addiu     $v0, $zero, 0x7FFF
  .L002BA07C:
    /* BAC7C 002BA07C A4A00000 */  sh         $zero, 0x0($a1)
    /* BAC80 002BA080 080AE8A0 */  j          .L002BA280
    /* BAC84 002BA084 00001021 */   addu      $v0, $zero, $zero
  .L002BA088:
    /* BAC88 002BA088 3C01800D */  lui        $at, %hi(D_800CC8F0)
    /* BAC8C 002BA08C D421C8F0 */  ldc1       $fv0f, %lo(D_800CC8F0)($at)
    /* BAC90 002BA090 4621703C */  c.lt.d     $fa1, $fv0f
    /* BAC94 002BA094 00000000 */  nop
    /* BAC98 002BA098 45030001 */  bc1tl      .L002BA0A0
    /* BAC9C 002BA09C 46200B86 */   mov.d     $fa1, $fv0f
  .L002BA0A0:
    /* BACA0 002BA0A0 3C01800D */  lui        $at, %hi(D_800CC8F8)
    /* BACA4 002BA0A4 D420C8F8 */  ldc1       $fv0, %lo(D_800CC8F8)($at)
    /* BACA8 002BA0A8 4620603E */  c.le.d     $fa0, $fv0
    /* BACAC 002BA0AC 00000000 */  nop
    /* BACB0 002BA0B0 45030001 */  bc1tl      .L002BA0B8
    /* BACB4 002BA0B4 46200B06 */   mov.d     $fa0, $fv0f
  .L002BA0B8:
    /* BACB8 002BA0B8 03A01821 */  addu       $v1, $sp, $zero
    /* BACBC 002BA0BC 3C02800D */  lui        $v0, %hi(D_800CC8A8)
    /* BACC0 002BA0C0 2442C8A8 */  addiu      $v0, $v0, %lo(D_800CC8A8)
    /* BACC4 002BA0C4 24440040 */  addiu      $a0, $v0, 0x40
  .L002BA0C8:
    /* BACC8 002BA0C8 8C460000 */  lw         $a2, 0x0($v0)
    /* BACCC 002BA0CC 8C470004 */  lw         $a3, 0x4($v0)
    /* BACD0 002BA0D0 8C480008 */  lw         $t0, 0x8($v0)
    /* BACD4 002BA0D4 8C49000C */  lw         $t1, 0xC($v0)
    /* BACD8 002BA0D8 AC660000 */  sw         $a2, 0x0($v1)
    /* BACDC 002BA0DC AC670004 */  sw         $a3, 0x4($v1)
    /* BACE0 002BA0E0 AC680008 */  sw         $t0, 0x8($v1)
    /* BACE4 002BA0E4 AC69000C */  sw         $t1, 0xC($v1)
    /* BACE8 002BA0E8 24420010 */  addiu      $v0, $v0, 0x10
    /* BACEC 002BA0EC 1444FFF6 */  bne        $v0, $a0, .L002BA0C8
    /* BACF0 002BA0F0 24630010 */   addiu     $v1, $v1, 0x10
    /* BACF4 002BA0F4 3C01800D */  lui        $at, %hi(D_800CC900)
    /* BACF8 002BA0F8 D420C900 */  ldc1       $fv0, %lo(D_800CC900)($at)
    /* BACFC 002BA0FC 46201002 */  mul.d      $fv0, $fv1, $fv0
    /* BAD00 002BA100 462C7383 */  div.d      $fa1, $fa1, $fa0
    /* BAD04 002BA104 3C01800D */  lui        $at, %hi(D_800CC908)
    /* BAD08 002BA108 D421C908 */  ldc1       $fv0f, %lo(D_800CC908)($at)
    /* BAD0C 002BA10C 27A30040 */  addiu      $v1, $sp, 0x40
    /* BAD10 002BA110 46217032 */  c.eq.d     $fa1, $fv0f
    /* BAD14 002BA114 462000CD */  trunc.w.d  $fv1f, $fv0
    /* BAD18 002BA118 44041800 */  mfc1       $a0, $fv1f
    /* BAD1C 002BA11C 45000003 */  bc1f       .L002BA12C
    /* BAD20 002BA120 AFA00040 */   sw        $zero, 0x40($sp)
    /* BAD24 002BA124 080AE86F */  j          .L002BA1BC
    /* BAD28 002BA128 46207306 */   mov.d     $fa0, $fa1
  .L002BA12C:
    /* BAD2C 002BA12C 3C01800D */  lui        $at, %hi(D_800CC910)
    /* BAD30 002BA130 D420C910 */  ldc1       $fv0, %lo(D_800CC910)($at)
    /* BAD34 002BA134 46207045 */  abs.d      $fv0f, $fa1
    /* BAD38 002BA138 4621003E */  c.le.d     $fv0, $fv0f
    /* BAD3C 002BA13C 00000000 */  nop
    /* BAD40 002BA140 4500000A */  bc1f       .L002BA16C
    /* BAD44 002BA144 00000000 */   nop
    /* BAD48 002BA148 3C01800D */  lui        $at, %hi(D_800CC918)
    /* BAD4C 002BA14C D422C918 */  ldc1       $fv1, %lo(D_800CC918)($at)
  .L002BA150:
    /* BAD50 002BA150 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* BAD54 002BA154 8C620000 */  lw         $v0, 0x0($v1)
    /* BAD58 002BA158 24420001 */  addiu      $v0, $v0, 0x1
    /* BAD5C 002BA15C 4621003E */  c.le.d     $fv0, $fv0f
    /* BAD60 002BA160 00000000 */  nop
    /* BAD64 002BA164 4501FFFA */  bc1t       .L002BA150
    /* BAD68 002BA168 AC620000 */   sw        $v0, 0x0($v1)
  .L002BA16C:
    /* BAD6C 002BA16C 3C01800D */  lui        $at, %hi(D_800CC920)
    /* BAD70 002BA170 D420C920 */  ldc1       $fv0, %lo(D_800CC920)($at)
    /* BAD74 002BA174 4620083C */  c.lt.d     $fv0f, $fv0
    /* BAD78 002BA178 00000000 */  nop
    /* BAD7C 002BA17C 45000008 */  bc1f       .L002BA1A0
    /* BAD80 002BA180 00000000 */   nop
  .L002BA184:
    /* BAD84 002BA184 8C620000 */  lw         $v0, 0x0($v1)
    /* BAD88 002BA188 46210840 */  add.d      $fv0f, $fv0f, $fv0f
    /* BAD8C 002BA18C 2442FFFF */  addiu      $v0, $v0, -0x1
    /* BAD90 002BA190 4620083C */  c.lt.d     $fv0f, $fv0
    /* BAD94 002BA194 00000000 */  nop
    /* BAD98 002BA198 4501FFFA */  bc1t       .L002BA184
    /* BAD9C 002BA19C AC620000 */   sw        $v0, 0x0($v1)
  .L002BA1A0:
    /* BADA0 002BA1A0 3C01800D */  lui        $at, %hi(D_800CC928)
    /* BADA4 002BA1A4 D420C928 */  ldc1       $fv0, %lo(D_800CC928)($at)
    /* BADA8 002BA1A8 462E003C */  c.lt.d     $fv0, $fa1
    /* BADAC 002BA1AC 00000000 */  nop
    /* BADB0 002BA1B0 45010002 */  bc1t       .L002BA1BC
    /* BADB4 002BA1B4 46200B06 */   mov.d     $fa0, $fv0f
    /* BADB8 002BA1B8 46206307 */  neg.d      $fa0, $fa0
  .L002BA1BC:
    /* BADBC 002BA1BC 3C01800D */  lui        $at, %hi(D_800CC930)
    /* BADC0 002BA1C0 D420C930 */  ldc1       $fv0, %lo(D_800CC930)($at)
    /* BADC4 002BA1C4 46206002 */  mul.d      $fv0, $fa0, $fv0
    /* BADC8 002BA1C8 462000CD */  trunc.w.d  $fv1f, $fv0
    /* BADCC 002BA1CC 44021800 */  mfc1       $v0, $fv1f
    /* BADD0 002BA1D0 2442FFF8 */  addiu      $v0, $v0, -0x8
    /* BADD4 002BA1D4 000210C0 */  sll        $v0, $v0, 3
    /* BADD8 002BA1D8 03A21021 */  addu       $v0, $sp, $v0
    /* BADDC 002BA1DC D4400000 */  ldc1       $fv0, 0x0($v0)
    /* BADE0 002BA1E0 C7A10040 */  lwc1       $fv0f, 0x40($sp)
    /* BADE4 002BA1E4 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* BADE8 002BA1E8 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* BADEC 002BA1EC 3C01800D */  lui        $at, %hi(D_800CC938)
    /* BADF0 002BA1F0 D421C938 */  ldc1       $fv0f, %lo(D_800CC938)($at)
    /* BADF4 002BA1F4 46210002 */  mul.d      $fv0, $fv0, $fv0f
    /* BADF8 002BA1F8 3C01800D */  lui        $at, %hi(D_800CC940)
    /* BADFC 002BA1FC D422C940 */  ldc1       $fv1, %lo(D_800CC940)($at)
    /* BAE00 002BA200 3C01800D */  lui        $at, %hi(D_800CC948)
    /* BAE04 002BA204 D421C948 */  ldc1       $fv0f, %lo(D_800CC948)($at)
    /* BAE08 002BA208 46220003 */  div.d      $fv0, $fv0, $fv1
    /* BAE0C 002BA20C 10800009 */  beqz       $a0, .L002BA234
    /* BAE10 002BA210 46210000 */   add.d     $fv0, $fv0, $fv0f
    /* BAE14 002BA214 30820001 */  andi       $v0, $a0, 0x1
  .L002BA218:
    /* BAE18 002BA218 10400002 */  beqz       $v0, .L002BA224
    /* BAE1C 002BA21C 00042043 */   sra       $a0, $a0, 1
    /* BAE20 002BA220 46200842 */  mul.d      $fv0f, $fv0f, $fv0
  .L002BA224:
    /* BAE24 002BA224 00000000 */  nop
    /* BAE28 002BA228 46200002 */  mul.d      $fv0, $fv0, $fv0
    /* BAE2C 002BA22C 1480FFFA */  bnez       $a0, .L002BA218
    /* BAE30 002BA230 30820001 */   andi      $v0, $a0, 0x1
  .L002BA234:
    /* BAE34 002BA234 46210842 */  mul.d      $fv0f, $fv0f, $fv0f
    /* BAE38 002BA238 00000000 */  nop
    /* BAE3C 002BA23C 46210842 */  mul.d      $fv0f, $fv0f, $fv0f
    /* BAE40 002BA240 00000000 */  nop
    /* BAE44 002BA244 46210842 */  mul.d      $fv0f, $fv0f, $fv0f
    /* BAE48 002BA248 462008CD */  trunc.w.d  $fv1f, $fv0f
    /* BAE4C 002BA24C 44021800 */  mfc1       $v0, $fv1f
    /* BAE50 002BA250 00021400 */  sll        $v0, $v0, 16
    /* BAE54 002BA254 00021403 */  sra        $v0, $v0, 16
    /* BAE58 002BA258 44820000 */  mtc1       $v0, $fv0
    /* BAE5C 002BA25C 46800020 */  cvt.s.w    $fv0, $fv0
    /* BAE60 002BA260 46000021 */  cvt.d.s    $fv0, $fv0
    /* BAE64 002BA264 46200801 */  sub.d      $fv0, $fv0f, $fv0
    /* BAE68 002BA268 3C01800D */  lui        $at, %hi(D_800CC950)
    /* BAE6C 002BA26C D421C950 */  ldc1       $fv0f, %lo(D_800CC950)($at)
    /* BAE70 002BA270 46210002 */  mul.d      $fv0, $fv0, $fv0f
    /* BAE74 002BA274 462000CD */  trunc.w.d  $fv1f, $fv0
    /* BAE78 002BA278 44031800 */  mfc1       $v1, $fv1f
    /* BAE7C 002BA27C A4A30000 */  sh         $v1, 0x0($a1)
  .L002BA280:
    /* BAE80 002BA280 03E00008 */  jr         $ra
    /* BAE84 002BA284 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel _getRate
