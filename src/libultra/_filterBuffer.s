.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBF2C-0xBBFD0 (VRAM 0x002BB32C) */
glabel _filterBuffer
    /* BBF2C 002BB32C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BBF30 002BB330 AFB20018 */  sw         $s2, 0x18($sp)
    /* BBF34 002BB334 00809021 */  addu       $s2, $a0, $zero
    /* BBF38 002BB338 3C030B00 */  lui        $v1, (0xB000020 >> 16)
    /* BBF3C 002BB33C 34630020 */  ori        $v1, $v1, (0xB000020 & 0xFFFF)
    /* BBF40 002BB340 26440008 */  addiu      $a0, $s2, 0x8
    /* BBF44 002BB344 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBF48 002BB348 00E08021 */  addu       $s0, $a3, $zero
    /* BBF4C 002BB34C 30A5FFFF */  andi       $a1, $a1, 0xFFFF
    /* BBF50 002BB350 3C020800 */  lui        $v0, (0x8000000 >> 16)
    /* BBF54 002BB354 00A21025 */  or         $v0, $a1, $v0
    /* BBF58 002BB358 00052C00 */  sll        $a1, $a1, 16
    /* BBF5C 002BB35C 00063040 */  sll        $a2, $a2, 1
    /* BBF60 002BB360 30C6FFFF */  andi       $a2, $a2, 0xFFFF
    /* BBF64 002BB364 00A62825 */  or         $a1, $a1, $a2
    /* BBF68 002BB368 AFBF001C */  sw         $ra, 0x1C($sp)
    /* BBF6C 002BB36C AFB10014 */  sw         $s1, 0x14($sp)
    /* BBF70 002BB370 AE020000 */  sw         $v0, 0x0($s0)
    /* BBF74 002BB374 AE050004 */  sw         $a1, 0x4($s0)
    /* BBF78 002BB378 0C0B032C */  jal        osVirtualToPhysical
    /* BBF7C 002BB37C AE030008 */   sw        $v1, 0x8($s0)
    /* BBF80 002BB380 3C040E00 */  lui        $a0, (0xE000000 >> 16)
    /* BBF84 002BB384 AE02000C */  sw         $v0, 0xC($s0)
    /* BBF88 002BB388 9243002F */  lbu        $v1, 0x2F($s2)
    /* BBF8C 002BB38C 96420002 */  lhu        $v0, 0x2($s2)
    /* BBF90 002BB390 00031C00 */  sll        $v1, $v1, 16
    /* BBF94 002BB394 00441025 */  or         $v0, $v0, $a0
    /* BBF98 002BB398 00621825 */  or         $v1, $v1, $v0
    /* BBF9C 002BB39C AE030010 */  sw         $v1, 0x10($s0)
    /* BBFA0 002BB3A0 8E440028 */  lw         $a0, 0x28($s2)
    /* BBFA4 002BB3A4 0C0B032C */  jal        osVirtualToPhysical
    /* BBFA8 002BB3A8 26110018 */   addiu     $s1, $s0, 0x18
    /* BBFAC 002BB3AC AE020014 */  sw         $v0, 0x14($s0)
    /* BBFB0 002BB3B0 02201021 */  addu       $v0, $s1, $zero
    /* BBFB4 002BB3B4 AE40002C */  sw         $zero, 0x2C($s2)
    /* BBFB8 002BB3B8 8FBF001C */  lw         $ra, 0x1C($sp)
    /* BBFBC 002BB3BC 8FB20018 */  lw         $s2, 0x18($sp)
    /* BBFC0 002BB3C0 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBFC4 002BB3C4 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBFC8 002BB3C8 03E00008 */  jr         $ra
    /* BBFCC 002BB3CC 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel _filterBuffer
