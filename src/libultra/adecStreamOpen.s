.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5DA0-0xC5E5C (VRAM 0x002C51A0) */
glabel adecStreamOpen
    /* C5DA0 002C51A0 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C5DA4 002C51A4 00A04021 */  addu       $t0, $a1, $zero
    /* C5DA8 002C51A8 3C038015 */  lui        $v1, %hi(D_80151CC8)
    /* C5DAC 002C51AC 24631CC8 */  addiu      $v1, $v1, %lo(D_80151CC8)
    /* C5DB0 002C51B0 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C5DB4 002C51B4 AC640008 */  sw         $a0, 0x8($v1)
    /* C5DB8 002C51B8 AC640014 */  sw         $a0, 0x14($v1)
    /* C5DBC 002C51BC 8C870000 */  lw         $a3, 0x0($a0)
    /* C5DC0 002C51C0 24820004 */  addiu      $v0, $a0, 0x4
    /* C5DC4 002C51C4 AC620014 */  sw         $v0, 0x14($v1)
    /* C5DC8 002C51C8 AC670000 */  sw         $a3, 0x0($v1)
    /* C5DCC 002C51CC 8C820004 */  lw         $v0, 0x4($a0)
    /* C5DD0 002C51D0 3C0A0F42 */  lui        $t2, (0xF424000 >> 16)
    /* C5DD4 002C51D4 AC620010 */  sw         $v0, 0x10($v1)
    /* C5DD8 002C51D8 8C850004 */  lw         $a1, 0x4($a0)
    /* C5DDC 002C51DC 24820008 */  addiu      $v0, $a0, 0x8
    /* C5DE0 002C51E0 AC620014 */  sw         $v0, 0x14($v1)
    /* C5DE4 002C51E4 AC65000C */  sw         $a1, 0xC($v1)
    /* C5DE8 002C51E8 8C820008 */  lw         $v0, 0x8($a0)
    /* C5DEC 002C51EC 2484000C */  addiu      $a0, $a0, 0xC
    /* C5DF0 002C51F0 AC640014 */  sw         $a0, 0x14($v1)
    /* C5DF4 002C51F4 3C01800E */  lui        $at, %hi(D_800D94EE)
    /* C5DF8 002C51F8 A42094EE */  sh         $zero, %lo(D_800D94EE)($at)
    /* C5DFC 002C51FC 3C01800E */  lui        $at, %hi(D_800D94F0)
    /* C5E00 002C5200 A42094F0 */  sh         $zero, %lo(D_800D94F0)($at)
    /* C5E04 002C5204 3C01800E */  lui        $at, %hi(D_800D94E8)
    /* C5E08 002C5208 A42094E8 */  sh         $zero, %lo(D_800D94E8)($at)
    /* C5E0C 002C520C 3C01800E */  lui        $at, %hi(D_800D94EA)
    /* C5E10 002C5210 A42094EA */  sh         $zero, %lo(D_800D94EA)($at)
    /* C5E14 002C5214 3C01800E */  lui        $at, %hi(D_800D94EC)
    /* C5E18 002C5218 A42094EC */  sh         $zero, %lo(D_800D94EC)($at)
    /* C5E1C 002C521C AC620004 */  sw         $v0, 0x4($v1)
    /* C5E20 002C5220 ACC70000 */  sw         $a3, 0x0($a2)
    /* C5E24 002C5224 8C620010 */  lw         $v0, 0x10($v1)
    /* C5E28 002C5228 354A4000 */  ori        $t2, $t2, (0xF424000 & 0xFFFF)
    /* C5E2C 002C522C 004A0018 */  mult       $v0, $t2
    /* C5E30 002C5230 01004821 */  addu       $t1, $t0, $zero
    /* C5E34 002C5234 00004021 */  addu       $t0, $zero, $zero
    /* C5E38 002C5238 01003021 */  addu       $a2, $t0, $zero
    /* C5E3C 002C523C 00002010 */  mfhi       $a0
    /* C5E40 002C5240 00002812 */  mflo       $a1
    /* C5E44 002C5244 0C0B17A4 */  jal        __udivdi3
    /* C5E48 002C5248 01203821 */   addu      $a3, $t1, $zero
    /* C5E4C 002C524C 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C5E50 002C5250 00601021 */  addu       $v0, $v1, $zero
    /* C5E54 002C5254 03E00008 */  jr         $ra
    /* C5E58 002C5258 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel adecStreamOpen
