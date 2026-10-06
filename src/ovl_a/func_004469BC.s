.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B49BC-0x1B4A54 (VRAM 0x004469BC) */
glabel func_004469BC
    /* 1B49BC 004469BC 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* 1B49C0 004469C0 AFBF0010 */  sw         $ra, 0x10($sp)
    /* 1B49C4 004469C4 8CA5001C */  lw         $a1, 0x1C($a1)
    /* 1B49C8 004469C8 3C048014 */  lui        $a0, %hi(D_80145040)
    /* 1B49CC 004469CC 24845040 */  addiu      $a0, $a0, %lo(D_80145040)
    /* 1B49D0 004469D0 0C08A964 */  jal        func_0022A590
    /* 1B49D4 004469D4 00000000 */   nop
    /* 1B49D8 004469D8 00021840 */  sll        $v1, $v0, 1
    /* 1B49DC 004469DC 00621821 */  addu       $v1, $v1, $v0
    /* 1B49E0 004469E0 000328C0 */  sll        $a1, $v1, 3
    /* 1B49E4 004469E4 3C01800E */  lui        $at, %hi(D_800E63C8)
    /* 1B49E8 004469E8 00250821 */  addu       $at, $at, $a1
    /* 1B49EC 004469EC 8C2463C8 */  lw         $a0, %lo(D_800E63C8)($at)
    /* 1B49F0 004469F0 3C01800E */  lui        $at, %hi(D_800E63C4)
    /* 1B49F4 004469F4 00250821 */  addu       $at, $at, $a1
    /* 1B49F8 004469F8 AC2063C4 */  sw         $zero, %lo(D_800E63C4)($at)
    /* 1B49FC 004469FC 10800011 */  beqz       $a0, .L00446A44
    /* 1B4A00 00446A00 2484FFFF */   addiu     $a0, $a0, -0x1
    /* 1B4A04 00446A04 3C01800E */  lui        $at, %hi(D_800E63C0)
    /* 1B4A08 00446A08 00250821 */  addu       $at, $at, $a1
    /* 1B4A0C 00446A0C 8C2363C0 */  lw         $v1, %lo(D_800E63C0)($at)
    /* 1B4A10 00446A10 3C01800E */  lui        $at, %hi(D_800E63C8)
    /* 1B4A14 00446A14 00250821 */  addu       $at, $at, $a1
    /* 1B4A18 00446A18 AC2463C8 */  sw         $a0, %lo(D_800E63C8)($at)
    /* 1B4A1C 00446A1C 2463FFFF */  addiu      $v1, $v1, -0x1
    /* 1B4A20 00446A20 3C01800E */  lui        $at, %hi(D_800E63C0)
    /* 1B4A24 00446A24 00250821 */  addu       $at, $at, $a1
    /* 1B4A28 00446A28 AC2363C0 */  sw         $v1, %lo(D_800E63C0)($at)
    /* 1B4A2C 00446A2C 00651821 */  addu       $v1, $v1, $a1
    /* 1B4A30 00446A30 3C01800E */  lui        $at, %hi(D_800E63CC)
    /* 1B4A34 00446A34 00230821 */  addu       $at, $at, $v1
    /* 1B4A38 00446A38 A02063CC */  sb         $zero, %lo(D_800E63CC)($at)
    /* 1B4A3C 00446A3C 08111A92 */  j          .L00446A48
    /* 1B4A40 00446A40 00001021 */   addu      $v0, $zero, $zero
  .L00446A44:
    /* 1B4A44 00446A44 00001021 */  addu       $v0, $zero, $zero
  .L00446A48:
    /* 1B4A48 00446A48 8FBF0010 */  lw         $ra, 0x10($sp)
    /* 1B4A4C 00446A4C 03E00008 */  jr         $ra
    /* 1B4A50 00446A50 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_004469BC
