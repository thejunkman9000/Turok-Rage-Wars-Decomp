.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B5BB0-0x1B5D80 (VRAM 0x00447BB0) */
glabel osPfsInitPak
    /* 1B5BB0 00447BB0 27BDFF90 */  addiu      $sp, $sp, -0x70
    /* 1B5BB4 00447BB4 AFB1005C */  sw         $s1, 0x5C($sp)
    /* 1B5BB8 00447BB8 00808821 */  addu       $s1, $a0, $zero
    /* 1B5BBC 00447BBC AFB20060 */  sw         $s2, 0x60($sp)
    /* 1B5BC0 00447BC0 00A09021 */  addu       $s2, $a1, $zero
    /* 1B5BC4 00447BC4 AFB30064 */  sw         $s3, 0x64($sp)
    /* 1B5BC8 00447BC8 00C09821 */  addu       $s3, $a2, $zero
    /* 1B5BCC 00447BCC AFBF0068 */  sw         $ra, 0x68($sp)
    /* 1B5BD0 00447BD0 0C0AFB41 */  jal        __osSiGetAccess
    /* 1B5BD4 00447BD4 AFB00058 */   sw        $s0, 0x58($sp)
    /* 1B5BD8 00447BD8 02202021 */  addu       $a0, $s1, $zero
    /* 1B5BDC 00447BDC 0C111E74 */  jal        __osPfsGetStatus
    /* 1B5BE0 00447BE0 02602821 */   addu      $a1, $s3, $zero
    /* 1B5BE4 00447BE4 0C0AFB5C */  jal        __osSiRelAccess
    /* 1B5BE8 00447BE8 00408021 */   addu      $s0, $v0, $zero
    /* 1B5BEC 00447BEC 1600005D */  bnez       $s0, .L00447D64
    /* 1B5BF0 00447BF0 02001021 */   addu      $v0, $s0, $zero
    /* 1B5BF4 00447BF4 02402021 */  addu       $a0, $s2, $zero
    /* 1B5BF8 00447BF8 AE510004 */  sw         $s1, 0x4($s2)
    /* 1B5BFC 00447BFC AE530008 */  sw         $s3, 0x8($s2)
    /* 1B5C00 00447C00 AE400000 */  sw         $zero, 0x0($s2)
    /* 1B5C04 00447C04 0C112645 */  jal        __osPfsSelectBank
    /* 1B5C08 00447C08 A2400065 */   sb        $zero, 0x65($s2)
    /* 1B5C0C 00447C0C 00408021 */  addu       $s0, $v0, $zero
    /* 1B5C10 00447C10 16000054 */  bnez       $s0, .L00447D64
    /* 1B5C14 00447C14 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B5C18 00447C18 8E440004 */  lw         $a0, 0x4($s2)
    /* 1B5C1C 00447C1C 8E450008 */  lw         $a1, 0x8($s2)
    /* 1B5C20 00447C20 0C0AF564 */  jal        __osContRamRead
    /* 1B5C24 00447C24 27A70010 */   addiu     $a3, $sp, 0x10
    /* 1B5C28 00447C28 00408021 */  addu       $s0, $v0, $zero
    /* 1B5C2C 00447C2C 1600004D */  bnez       $s0, .L00447D64
    /* 1B5C30 00447C30 27A40010 */   addiu     $a0, $sp, 0x10
    /* 1B5C34 00447C34 27A50050 */  addiu      $a1, $sp, 0x50
    /* 1B5C38 00447C38 0C112601 */  jal        __osIdCheckSum
    /* 1B5C3C 00447C3C 27A60052 */   addiu     $a2, $sp, 0x52
    /* 1B5C40 00447C40 97A3002C */  lhu        $v1, 0x2C($sp)
    /* 1B5C44 00447C44 97A20050 */  lhu        $v0, 0x50($sp)
    /* 1B5C48 00447C48 14620005 */  bne        $v1, $v0, .L00447C60
    /* 1B5C4C 00447C4C 27B10010 */   addiu     $s1, $sp, 0x10
    /* 1B5C50 00447C50 97A3002E */  lhu        $v1, 0x2E($sp)
    /* 1B5C54 00447C54 97A20052 */  lhu        $v0, 0x52($sp)
    /* 1B5C58 00447C58 10620007 */  beq        $v1, $v0, .L00447C78
    /* 1B5C5C 00447C5C 00000000 */   nop
  .L00447C60:
    /* 1B5C60 00447C60 02402021 */  addu       $a0, $s2, $zero
    /* 1B5C64 00447C64 0C112466 */  jal        __osCheckPackId
    /* 1B5C68 00447C68 02202821 */   addu      $a1, $s1, $zero
    /* 1B5C6C 00447C6C 00408021 */  addu       $s0, $v0, $zero
    /* 1B5C70 00447C70 1600003C */  bnez       $s0, .L00447D64
    /* 1B5C74 00447C74 00000000 */   nop
  .L00447C78:
    /* 1B5C78 00447C78 96220018 */  lhu        $v0, 0x18($s1)
    /* 1B5C7C 00447C7C 30420001 */  andi       $v0, $v0, 0x1
    /* 1B5C80 00447C80 1440000F */  bnez       $v0, .L00447CC0
    /* 1B5C84 00447C84 00002021 */   addu      $a0, $zero, $zero
    /* 1B5C88 00447C88 02402021 */  addu       $a0, $s2, $zero
    /* 1B5C8C 00447C8C 02202821 */  addu       $a1, $s1, $zero
    /* 1B5C90 00447C90 27B10030 */  addiu      $s1, $sp, 0x30
    /* 1B5C94 00447C94 0C1123AC */  jal        __osRepairPackId
    /* 1B5C98 00447C98 02203021 */   addu      $a2, $s1, $zero
    /* 1B5C9C 00447C9C 00408021 */  addu       $s0, $v0, $zero
    /* 1B5CA0 00447CA0 16000030 */  bnez       $s0, .L00447D64
    /* 1B5CA4 00447CA4 00000000 */   nop
    /* 1B5CA8 00447CA8 97A20048 */  lhu        $v0, 0x48($sp)
    /* 1B5CAC 00447CAC 30420001 */  andi       $v0, $v0, 0x1
    /* 1B5CB0 00447CB0 14400003 */  bnez       $v0, .L00447CC0
    /* 1B5CB4 00447CB4 00002021 */   addu      $a0, $zero, $zero
    /* 1B5CB8 00447CB8 08111F59 */  j          .L00447D64
    /* 1B5CBC 00447CBC 2402000B */   addiu     $v0, $zero, 0xB
  .L00447CC0:
    /* 1B5CC0 00447CC0 02441821 */  addu       $v1, $s2, $a0
  .L00447CC4:
    /* 1B5CC4 00447CC4 02241021 */  addu       $v0, $s1, $a0
    /* 1B5CC8 00447CC8 90420000 */  lbu        $v0, 0x0($v0)
    /* 1B5CCC 00447CCC 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B5CD0 00447CD0 A062000C */  sb         $v0, 0xC($v1)
    /* 1B5CD4 00447CD4 28820020 */  slti       $v0, $a0, 0x20
    /* 1B5CD8 00447CD8 1440FFFA */  bnez       $v0, .L00447CC4
    /* 1B5CDC 00447CDC 02441821 */   addu      $v1, $s2, $a0
    /* 1B5CE0 00447CE0 24060007 */  addiu      $a2, $zero, 0x7
    /* 1B5CE4 00447CE4 8E440004 */  lw         $a0, 0x4($s2)
    /* 1B5CE8 00447CE8 8E450008 */  lw         $a1, 0x8($s2)
    /* 1B5CEC 00447CEC 9222001B */  lbu        $v0, 0x1B($s1)
    /* 1B5CF0 00447CF0 2647002C */  addiu      $a3, $s2, 0x2C
    /* 1B5CF4 00447CF4 AE42004C */  sw         $v0, 0x4C($s2)
    /* 1B5CF8 00447CF8 9223001A */  lbu        $v1, 0x1A($s1)
    /* 1B5CFC 00447CFC 24020010 */  addiu      $v0, $zero, 0x10
    /* 1B5D00 00447D00 AE420050 */  sw         $v0, 0x50($s2)
    /* 1B5D04 00447D04 24020008 */  addiu      $v0, $zero, 0x8
    /* 1B5D08 00447D08 AE420054 */  sw         $v0, 0x54($s2)
    /* 1B5D0C 00447D0C A2430064 */  sb         $v1, 0x64($s2)
    /* 1B5D10 00447D10 306300FF */  andi       $v1, $v1, 0xFF
    /* 1B5D14 00447D14 00031840 */  sll        $v1, $v1, 1
    /* 1B5D18 00447D18 92420064 */  lbu        $v0, 0x64($s2)
    /* 1B5D1C 00447D1C 24630003 */  addiu      $v1, $v1, 0x3
    /* 1B5D20 00447D20 AE430060 */  sw         $v1, 0x60($s2)
    /* 1B5D24 00447D24 92430064 */  lbu        $v1, 0x64($s2)
    /* 1B5D28 00447D28 24420001 */  addiu      $v0, $v0, 0x1
    /* 1B5D2C 00447D2C 000210C0 */  sll        $v0, $v0, 3
    /* 1B5D30 00447D30 000318C0 */  sll        $v1, $v1, 3
    /* 1B5D34 00447D34 AE420058 */  sw         $v0, 0x58($s2)
    /* 1B5D38 00447D38 00431021 */  addu       $v0, $v0, $v1
    /* 1B5D3C 00447D3C 0C0AF564 */  jal        __osContRamRead
    /* 1B5D40 00447D40 AE42005C */   sw        $v0, 0x5C($s2)
    /* 1B5D44 00447D44 00408021 */  addu       $s0, $v0, $zero
    /* 1B5D48 00447D48 16000006 */  bnez       $s0, .L00447D64
    /* 1B5D4C 00447D4C 02001021 */   addu      $v0, $s0, $zero
    /* 1B5D50 00447D50 0C111F60 */  jal        osPfsChecker
    /* 1B5D54 00447D54 02402021 */   addu      $a0, $s2, $zero
    /* 1B5D58 00447D58 8E430000 */  lw         $v1, 0x0($s2)
    /* 1B5D5C 00447D5C 34630001 */  ori        $v1, $v1, 0x1
    /* 1B5D60 00447D60 AE430000 */  sw         $v1, 0x0($s2)
  .L00447D64:
    /* 1B5D64 00447D64 8FBF0068 */  lw         $ra, 0x68($sp)
    /* 1B5D68 00447D68 8FB30064 */  lw         $s3, 0x64($sp)
    /* 1B5D6C 00447D6C 8FB20060 */  lw         $s2, 0x60($sp)
    /* 1B5D70 00447D70 8FB1005C */  lw         $s1, 0x5C($sp)
    /* 1B5D74 00447D74 8FB00058 */  lw         $s0, 0x58($sp)
    /* 1B5D78 00447D78 03E00008 */  jr         $ra
    /* 1B5D7C 00447D7C 27BD0070 */   addiu     $sp, $sp, 0x70
endlabel osPfsInitPak
