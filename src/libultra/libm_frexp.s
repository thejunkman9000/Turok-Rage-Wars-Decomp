.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBAFD0-0xBB084 (VRAM 0x002BA3D0) */
glabel libm_frexp
    /* BAFD0 002BA3D0 3C01800D */  lui        $at, %hi(D_800CC960)
    /* BAFD4 002BA3D4 D420C960 */  ldc1       $fv0, %lo(D_800CC960)($at)
    /* BAFD8 002BA3D8 46206032 */  c.eq.d     $fa0, $fv0
    /* BAFDC 002BA3DC 00000000 */  nop
    /* BAFE0 002BA3E0 45000003 */  bc1f       .L002BA3F0
    /* BAFE4 002BA3E4 ACC00000 */   sw        $zero, 0x0($a2)
    /* BAFE8 002BA3E8 03E00008 */  jr         $ra
    /* BAFEC 002BA3EC 46206006 */   mov.d     $fv0, $fa0
  .L002BA3F0:
    /* BAFF0 002BA3F0 3C01800D */  lui        $at, %hi(D_800CC968)
    /* BAFF4 002BA3F4 D420C968 */  ldc1       $fv0, %lo(D_800CC968)($at)
    /* BAFF8 002BA3F8 46206045 */  abs.d      $fv0f, $fa0
    /* BAFFC 002BA3FC 4621003E */  c.le.d     $fv0, $fv0f
    /* BB000 002BA400 00000000 */  nop
    /* BB004 002BA404 4500000A */  bc1f       .L002BA430
    /* BB008 002BA408 00000000 */   nop
    /* BB00C 002BA40C 3C01800D */  lui        $at, %hi(D_800CC970)
    /* BB010 002BA410 D422C970 */  ldc1       $fv1, %lo(D_800CC970)($at)
  .L002BA414:
    /* BB014 002BA414 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* BB018 002BA418 8CC20000 */  lw         $v0, 0x0($a2)
    /* BB01C 002BA41C 24420001 */  addiu      $v0, $v0, 0x1
    /* BB020 002BA420 4621003E */  c.le.d     $fv0, $fv0f
    /* BB024 002BA424 00000000 */  nop
    /* BB028 002BA428 4501FFFA */  bc1t       .L002BA414
    /* BB02C 002BA42C ACC20000 */   sw        $v0, 0x0($a2)
  .L002BA430:
    /* BB030 002BA430 3C01800D */  lui        $at, %hi(D_800CC978)
    /* BB034 002BA434 D420C978 */  ldc1       $fv0, %lo(D_800CC978)($at)
    /* BB038 002BA438 4620083C */  c.lt.d     $fv0f, $fv0
    /* BB03C 002BA43C 00000000 */  nop
    /* BB040 002BA440 45000008 */  bc1f       .L002BA464
    /* BB044 002BA444 00000000 */   nop
  .L002BA448:
    /* BB048 002BA448 8CC20000 */  lw         $v0, 0x0($a2)
    /* BB04C 002BA44C 46210840 */  add.d      $fv0f, $fv0f, $fv0f
    /* BB050 002BA450 2442FFFF */  addiu      $v0, $v0, -0x1
    /* BB054 002BA454 4620083C */  c.lt.d     $fv0f, $fv0
    /* BB058 002BA458 00000000 */  nop
    /* BB05C 002BA45C 4501FFFA */  bc1t       .L002BA448
    /* BB060 002BA460 ACC20000 */   sw        $v0, 0x0($a2)
  .L002BA464:
    /* BB064 002BA464 3C01800D */  lui        $at, %hi(D_800CC980)
    /* BB068 002BA468 D420C980 */  ldc1       $fv0, %lo(D_800CC980)($at)
    /* BB06C 002BA46C 462C003C */  c.lt.d     $fv0, $fa0
    /* BB070 002BA470 00000000 */  nop
    /* BB074 002BA474 45020001 */  bc1fl      .L002BA47C
    /* BB078 002BA478 46200847 */   neg.d     $fv0f, $fv0f
  .L002BA47C:
    /* BB07C 002BA47C 03E00008 */  jr         $ra
    /* BB080 002BA480 46200806 */   mov.d     $fv0, $fv0f
endlabel libm_frexp
