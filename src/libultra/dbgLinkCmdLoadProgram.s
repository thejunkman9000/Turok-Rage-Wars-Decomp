.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB03F8-0xB0590 (VRAM 0x002AF7F8) */
glabel dbgLinkCmdLoadProgram
    /* B03F8 002AF7F8 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B03FC 002AF7FC AFB1002C */  sw         $s1, 0x2C($sp)
    /* B0400 002AF800 27B10014 */  addiu      $s1, $sp, 0x14
    /* B0404 002AF804 02202021 */  addu       $a0, $s1, $zero
    /* B0408 002AF808 AFBF0034 */  sw         $ra, 0x34($sp)
    /* B040C 002AF80C AFB20030 */  sw         $s2, 0x30($sp)
    /* B0410 002AF810 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0414 002AF814 AFB00028 */   sw        $s0, 0x28($sp)
    /* B0418 002AF818 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B041C 002AF81C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0420 002AF820 14400054 */  bnez       $v0, .L002AF974
    /* B0424 002AF824 00009021 */   addu      $s2, $zero, $zero
    /* B0428 002AF828 93A20014 */  lbu        $v0, 0x14($sp)
    /* B042C 002AF82C 02202021 */  addu       $a0, $s1, $zero
    /* B0430 002AF830 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0434 002AF834 00028200 */   sll       $s0, $v0, 8
    /* B0438 002AF838 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B043C 002AF83C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0440 002AF840 1440004D */  bnez       $v0, .L002AF978
    /* B0444 002AF844 02401021 */   addu      $v0, $s2, $zero
    /* B0448 002AF848 93A20014 */  lbu        $v0, 0x14($sp)
    /* B044C 002AF84C 02202021 */  addu       $a0, $s1, $zero
    /* B0450 002AF850 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0454 002AF854 02028025 */   or        $s0, $s0, $v0
    /* B0458 002AF858 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B045C 002AF85C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0460 002AF860 14400044 */  bnez       $v0, .L002AF974
    /* B0464 002AF864 00108200 */   sll       $s0, $s0, 8
    /* B0468 002AF868 93A20014 */  lbu        $v0, 0x14($sp)
    /* B046C 002AF86C 02202021 */  addu       $a0, $s1, $zero
    /* B0470 002AF870 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0474 002AF874 02028025 */   or        $s0, $s0, $v0
    /* B0478 002AF878 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B047C 002AF87C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0480 002AF880 1440003C */  bnez       $v0, .L002AF974
    /* B0484 002AF884 00108200 */   sll       $s0, $s0, 8
    /* B0488 002AF888 27B1001C */  addiu      $s1, $sp, 0x1C
    /* B048C 002AF88C 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0490 002AF890 02202021 */  addu       $a0, $s1, $zero
    /* B0494 002AF894 02028025 */  or         $s0, $s0, $v0
    /* B0498 002AF898 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B049C 002AF89C AFB00010 */   sw        $s0, 0x10($sp)
    /* B04A0 002AF8A0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B04A4 002AF8A4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B04A8 002AF8A8 14400033 */  bnez       $v0, .L002AF978
    /* B04AC 002AF8AC 02401021 */   addu      $v0, $s2, $zero
    /* B04B0 002AF8B0 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B04B4 002AF8B4 02202021 */  addu       $a0, $s1, $zero
    /* B04B8 002AF8B8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B04BC 002AF8BC 00028200 */   sll       $s0, $v0, 8
    /* B04C0 002AF8C0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B04C4 002AF8C4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B04C8 002AF8C8 1440002B */  bnez       $v0, .L002AF978
    /* B04CC 002AF8CC 02401021 */   addu      $v0, $s2, $zero
    /* B04D0 002AF8D0 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B04D4 002AF8D4 02202021 */  addu       $a0, $s1, $zero
    /* B04D8 002AF8D8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B04DC 002AF8DC 02028025 */   or        $s0, $s0, $v0
    /* B04E0 002AF8E0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B04E4 002AF8E4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B04E8 002AF8E8 14400022 */  bnez       $v0, .L002AF974
    /* B04EC 002AF8EC 00108200 */   sll       $s0, $s0, 8
    /* B04F0 002AF8F0 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B04F4 002AF8F4 02202021 */  addu       $a0, $s1, $zero
    /* B04F8 002AF8F8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B04FC 002AF8FC 02028025 */   or        $s0, $s0, $v0
    /* B0500 002AF900 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0504 002AF904 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0508 002AF908 1440001A */  bnez       $v0, .L002AF974
    /* B050C 002AF90C 00108200 */   sll       $s0, $s0, 8
    /* B0510 002AF910 3C048010 */  lui        $a0, (0x80100000 >> 16)
    /* B0514 002AF914 27A60020 */  addiu      $a2, $sp, 0x20
    /* B0518 002AF918 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B051C 002AF91C 8FA50010 */  lw         $a1, 0x10($sp)
    /* B0520 002AF920 02028025 */  or         $s0, $s0, $v0
    /* B0524 002AF924 0C0ABA0D */  jal        dbgLinkRecvBlock
    /* B0528 002AF928 AFB00018 */   sw        $s0, 0x18($sp)
    /* B052C 002AF92C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0530 002AF930 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0534 002AF934 14400010 */  bnez       $v0, .L002AF978
    /* B0538 002AF938 02401021 */   addu      $v0, $s2, $zero
    /* B053C 002AF93C 8FA30018 */  lw         $v1, 0x18($sp)
    /* B0540 002AF940 8FA20020 */  lw         $v0, 0x20($sp)
    /* B0544 002AF944 1462000C */  bne        $v1, $v0, .L002AF978
    /* B0548 002AF948 02401021 */   addu      $v0, $s2, $zero
    /* B054C 002AF94C 24120001 */  addiu      $s2, $zero, 0x1
    /* B0550 002AF950 8FA20010 */  lw         $v0, 0x10($sp)
    /* B0554 002AF954 02401821 */  addu       $v1, $s2, $zero
    /* B0558 002AF958 3C01800D */  lui        $at, %hi(D_800D3640)
    /* B055C 002AF95C AC233640 */  sw         $v1, %lo(D_800D3640)($at)
    /* B0560 002AF960 3C038010 */  lui        $v1, (0x80100000 >> 16)
    /* B0564 002AF964 3C01800D */  lui        $at, %hi(D_800D3644)
    /* B0568 002AF968 AC233644 */  sw         $v1, %lo(D_800D3644)($at)
    /* B056C 002AF96C 3C01800D */  lui        $at, %hi(D_800D3648)
    /* B0570 002AF970 AC223648 */  sw         $v0, %lo(D_800D3648)($at)
  .L002AF974:
    /* B0574 002AF974 02401021 */  addu       $v0, $s2, $zero
  .L002AF978:
    /* B0578 002AF978 8FBF0034 */  lw         $ra, 0x34($sp)
    /* B057C 002AF97C 8FB20030 */  lw         $s2, 0x30($sp)
    /* B0580 002AF980 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B0584 002AF984 8FB00028 */  lw         $s0, 0x28($sp)
    /* B0588 002AF988 03E00008 */  jr         $ra
    /* B058C 002AF98C 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgLinkCmdLoadProgram
