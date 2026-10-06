.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7CB8-0xB7D98 (VRAM 0x002B70B8) */
glabel alSeqNew
    /* B7CB8 002B70B8 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B7CBC 002B70BC AFB00010 */  sw         $s0, 0x10($sp)
    /* B7CC0 002B70C0 00808021 */  addu       $s0, $a0, $zero
    /* B7CC4 002B70C4 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B7CC8 002B70C8 AE050000 */  sw         $a1, 0x0($s0)
    /* B7CCC 002B70CC AE060010 */  sw         $a2, 0x10($s0)
    /* B7CD0 002B70D0 A600001A */  sh         $zero, 0x1A($s0)
    /* B7CD4 002B70D4 AE00000C */  sw         $zero, 0xC($s0)
    /* B7CD8 002B70D8 0C0ADD31 */  jal        __alSeqReadWord
    /* B7CDC 002B70DC AE050008 */   sw        $a1, 0x8($s0)
    /* B7CE0 002B70E0 3C034D54 */  lui        $v1, (0x4D546864 >> 16)
    /* B7CE4 002B70E4 34636864 */  ori        $v1, $v1, (0x4D546864 & 0xFFFF)
    /* B7CE8 002B70E8 14430027 */  bne        $v0, $v1, .L002B7188
    /* B7CEC 002B70EC 00000000 */   nop
    /* B7CF0 002B70F0 0C0ADD31 */  jal        __alSeqReadWord
    /* B7CF4 002B70F4 02002021 */   addu      $a0, $s0, $zero
    /* B7CF8 002B70F8 0C0ADD25 */  jal        __alSeqReadShort
    /* B7CFC 002B70FC 02002021 */   addu      $a0, $s0, $zero
    /* B7D00 002B7100 00021400 */  sll        $v0, $v0, 16
    /* B7D04 002B7104 14400020 */  bnez       $v0, .L002B7188
    /* B7D08 002B7108 00000000 */   nop
    /* B7D0C 002B710C 0C0ADD25 */  jal        __alSeqReadShort
    /* B7D10 002B7110 02002021 */   addu      $a0, $s0, $zero
    /* B7D14 002B7114 00021400 */  sll        $v0, $v0, 16
    /* B7D18 002B7118 00021403 */  sra        $v0, $v0, 16
    /* B7D1C 002B711C 24030001 */  addiu      $v1, $zero, 0x1
    /* B7D20 002B7120 14430019 */  bne        $v0, $v1, .L002B7188
    /* B7D24 002B7124 00000000 */   nop
    /* B7D28 002B7128 0C0ADD25 */  jal        __alSeqReadShort
    /* B7D2C 002B712C 02002021 */   addu      $a0, $s0, $zero
    /* B7D30 002B7130 A6020018 */  sh         $v0, 0x18($s0)
    /* B7D34 002B7134 00021400 */  sll        $v0, $v0, 16
    /* B7D38 002B7138 00021C03 */  sra        $v1, $v0, 16
    /* B7D3C 002B713C 30628000 */  andi       $v0, $v1, 0x8000
    /* B7D40 002B7140 14400011 */  bnez       $v0, .L002B7188
    /* B7D44 002B7144 00000000 */   nop
    /* B7D48 002B7148 02002021 */  addu       $a0, $s0, $zero
    /* B7D4C 002B714C 3C01800D */  lui        $at, %hi(D_800CC730)
    /* B7D50 002B7150 C420C730 */  lwc1       $fv0, %lo(D_800CC730)($at)
    /* B7D54 002B7154 44830800 */  mtc1       $v1, $fv0f
    /* B7D58 002B7158 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* B7D5C 002B715C 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* B7D60 002B7160 0C0ADD31 */  jal        __alSeqReadWord
    /* B7D64 002B7164 E6000014 */   swc1      $fv0, 0x14($s0)
    /* B7D68 002B7168 3C034D54 */  lui        $v1, (0x4D54726B >> 16)
    /* B7D6C 002B716C 3463726B */  ori        $v1, $v1, (0x4D54726B & 0xFFFF)
    /* B7D70 002B7170 14430005 */  bne        $v0, $v1, .L002B7188
    /* B7D74 002B7174 00000000 */   nop
    /* B7D78 002B7178 0C0ADD31 */  jal        __alSeqReadWord
    /* B7D7C 002B717C 02002021 */   addu      $a0, $s0, $zero
    /* B7D80 002B7180 8E020008 */  lw         $v0, 0x8($s0)
    /* B7D84 002B7184 AE020004 */  sw         $v0, 0x4($s0)
  .L002B7188:
    /* B7D88 002B7188 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B7D8C 002B718C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B7D90 002B7190 03E00008 */  jr         $ra
    /* B7D94 002B7194 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel alSeqNew
