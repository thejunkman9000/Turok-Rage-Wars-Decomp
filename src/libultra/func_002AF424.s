.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB0024-0xB0144 (VRAM 0x002AF424) */
glabel func_002AF424
    /* B0024 002AF424 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B0028 002AF428 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B002C 002AF42C 27B10014 */  addiu      $s1, $sp, 0x14
    /* B0030 002AF430 02202021 */  addu       $a0, $s1, $zero
    /* B0034 002AF434 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B0038 002AF438 AFB20020 */  sw         $s2, 0x20($sp)
    /* B003C 002AF43C 0C0AB8E0 */  jal        func_002AE380
    /* B0040 002AF440 AFB00018 */   sw        $s0, 0x18($sp)
    /* B0044 002AF444 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0048 002AF448 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B004C 002AF44C 14400036 */  bnez       $v0, .L002AF528
    /* B0050 002AF450 00009021 */   addu      $s2, $zero, $zero
    /* B0054 002AF454 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0058 002AF458 02202021 */  addu       $a0, $s1, $zero
    /* B005C 002AF45C 0C0AB8E0 */  jal        func_002AE380
    /* B0060 002AF460 00028200 */   sll       $s0, $v0, 8
    /* B0064 002AF464 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0068 002AF468 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B006C 002AF46C 1440002F */  bnez       $v0, .L002AF52C
    /* B0070 002AF470 02401021 */   addu      $v0, $s2, $zero
    /* B0074 002AF474 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0078 002AF478 02202021 */  addu       $a0, $s1, $zero
    /* B007C 002AF47C 0C0AB8E0 */  jal        func_002AE380
    /* B0080 002AF480 02028025 */   or        $s0, $s0, $v0
    /* B0084 002AF484 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0088 002AF488 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B008C 002AF48C 14400026 */  bnez       $v0, .L002AF528
    /* B0090 002AF490 00108200 */   sll       $s0, $s0, 8
    /* B0094 002AF494 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0098 002AF498 02202021 */  addu       $a0, $s1, $zero
    /* B009C 002AF49C 0C0AB8E0 */  jal        func_002AE380
    /* B00A0 002AF4A0 02028025 */   or        $s0, $s0, $v0
    /* B00A4 002AF4A4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B00A8 002AF4A8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B00AC 002AF4AC 1440001E */  bnez       $v0, .L002AF528
    /* B00B0 002AF4B0 00108200 */   sll       $s0, $s0, 8
    /* B00B4 002AF4B4 93A20014 */  lbu        $v0, 0x14($sp)
    /* B00B8 002AF4B8 02028025 */  or         $s0, $s0, $v0
    /* B00BC 002AF4BC AFB00010 */  sw         $s0, 0x10($sp)
    /* B00C0 002AF4C0 8E100000 */  lw         $s0, 0x0($s0)
    /* B00C4 002AF4C4 0C0AB96B */  jal        func_002AE5AC
    /* B00C8 002AF4C8 00102602 */   srl       $a0, $s0, 24
    /* B00CC 002AF4CC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B00D0 002AF4D0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B00D4 002AF4D4 14400015 */  bnez       $v0, .L002AF52C
    /* B00D8 002AF4D8 02401021 */   addu      $v0, $s2, $zero
    /* B00DC 002AF4DC 00102402 */  srl        $a0, $s0, 16
    /* B00E0 002AF4E0 0C0AB96B */  jal        func_002AE5AC
    /* B00E4 002AF4E4 308400FF */   andi      $a0, $a0, 0xFF
    /* B00E8 002AF4E8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B00EC 002AF4EC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B00F0 002AF4F0 1440000E */  bnez       $v0, .L002AF52C
    /* B00F4 002AF4F4 02401021 */   addu      $v0, $s2, $zero
    /* B00F8 002AF4F8 00102202 */  srl        $a0, $s0, 8
    /* B00FC 002AF4FC 0C0AB96B */  jal        func_002AE5AC
    /* B0100 002AF500 308400FF */   andi      $a0, $a0, 0xFF
    /* B0104 002AF504 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0108 002AF508 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B010C 002AF50C 14400007 */  bnez       $v0, .L002AF52C
    /* B0110 002AF510 02401021 */   addu      $v0, $s2, $zero
    /* B0114 002AF514 0C0AB96B */  jal        func_002AE5AC
    /* B0118 002AF518 320400FF */   andi      $a0, $s0, 0xFF
    /* B011C 002AF51C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0120 002AF520 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0124 002AF524 2C520001 */  sltiu      $s2, $v0, 0x1
  .L002AF528:
    /* B0128 002AF528 02401021 */  addu       $v0, $s2, $zero
  .L002AF52C:
    /* B012C 002AF52C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B0130 002AF530 8FB20020 */  lw         $s2, 0x20($sp)
    /* B0134 002AF534 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B0138 002AF538 8FB00018 */  lw         $s0, 0x18($sp)
    /* B013C 002AF53C 03E00008 */  jr         $ra
    /* B0140 002AF540 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002AF424
