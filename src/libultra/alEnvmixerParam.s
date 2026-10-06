.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBAE88-0xBAF58 (VRAM 0x002BA288) */
glabel alEnvmixerParam
    /* BAE88 002BA288 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* BAE8C 002BA28C AFBF0010 */  sw         $ra, 0x10($sp)
    /* BAE90 002BA290 24020003 */  addiu      $v0, $zero, 0x3
    /* BAE94 002BA294 10A2000F */  beq        $a1, $v0, .L002BA2D4
    /* BAE98 002BA298 00801821 */   addu      $v1, $a0, $zero
    /* BAE9C 002BA29C 28A20004 */  slti       $v0, $a1, 0x4
    /* BAEA0 002BA2A0 10400005 */  beqz       $v0, .L002BA2B8
    /* BAEA4 002BA2A4 24020001 */   addiu     $v0, $zero, 0x1
    /* BAEA8 002BA2A8 50A20027 */  beql       $a1, $v0, .L002BA348
    /* BAEAC 002BA2AC AC860000 */   sw        $a2, 0x0($a0)
    /* BAEB0 002BA2B0 080AE8CC */  j          .L002BA330
    /* BAEB4 002BA2B4 00000000 */   nop
  .L002BA2B8:
    /* BAEB8 002BA2B8 24020004 */  addiu      $v0, $zero, 0x4
    /* BAEBC 002BA2BC 10A2000B */  beq        $a1, $v0, .L002BA2EC
    /* BAEC0 002BA2C0 24020009 */   addiu     $v0, $zero, 0x9
    /* BAEC4 002BA2C4 10A20013 */  beq        $a1, $v0, .L002BA314
    /* BAEC8 002BA2C8 24020001 */   addiu     $v0, $zero, 0x1
    /* BAECC 002BA2CC 080AE8CC */  j          .L002BA330
    /* BAED0 002BA2D0 00000000 */   nop
  .L002BA2D4:
    /* BAED4 002BA2D4 8C820040 */  lw         $v0, 0x40($a0)
    /* BAED8 002BA2D8 50400002 */  beql       $v0, $zero, .L002BA2E4
    /* BAEDC 002BA2DC AC86003C */   sw        $a2, 0x3C($a0)
    /* BAEE0 002BA2E0 AC460000 */  sw         $a2, 0x0($v0)
  .L002BA2E4:
    /* BAEE4 002BA2E4 080AE8D2 */  j          .L002BA348
    /* BAEE8 002BA2E8 AC660040 */   sw        $a2, 0x40($v1)
  .L002BA2EC:
    /* BAEEC 002BA2EC 8C830000 */  lw         $v1, 0x0($a0)
    /* BAEF0 002BA2F0 24020001 */  addiu      $v0, $zero, 0x1
    /* BAEF4 002BA2F4 AC820038 */  sw         $v0, 0x38($a0)
    /* BAEF8 002BA2F8 AC800048 */  sw         $zero, 0x48($a0)
    /* BAEFC 002BA2FC 10600012 */  beqz       $v1, .L002BA348
    /* BAF00 002BA300 A482001A */   sh        $v0, 0x1A($a0)
    /* BAF04 002BA304 00602021 */  addu       $a0, $v1, $zero
    /* BAF08 002BA308 8C820008 */  lw         $v0, 0x8($a0)
    /* BAF0C 002BA30C 080AE8D0 */  j          .L002BA340
    /* BAF10 002BA310 24050004 */   addiu     $a1, $zero, 0x4
  .L002BA314:
    /* BAF14 002BA314 8C830000 */  lw         $v1, 0x0($a0)
    /* BAF18 002BA318 1060000B */  beqz       $v1, .L002BA348
    /* BAF1C 002BA31C AC820048 */   sw        $v0, 0x48($a0)
    /* BAF20 002BA320 00602021 */  addu       $a0, $v1, $zero
    /* BAF24 002BA324 8C820008 */  lw         $v0, 0x8($a0)
    /* BAF28 002BA328 080AE8D0 */  j          .L002BA340
    /* BAF2C 002BA32C 24050009 */   addiu     $a1, $zero, 0x9
  .L002BA330:
    /* BAF30 002BA330 8C840000 */  lw         $a0, 0x0($a0)
    /* BAF34 002BA334 10800004 */  beqz       $a0, .L002BA348
    /* BAF38 002BA338 00000000 */   nop
    /* BAF3C 002BA33C 8C820008 */  lw         $v0, 0x8($a0)
  .L002BA340:
    /* BAF40 002BA340 0040F809 */  jalr       $v0
    /* BAF44 002BA344 00000000 */   nop
  .L002BA348:
    /* BAF48 002BA348 8FBF0010 */  lw         $ra, 0x10($sp)
    /* BAF4C 002BA34C 00001021 */  addu       $v0, $zero, $zero
    /* BAF50 002BA350 03E00008 */  jr         $ra
    /* BAF54 002BA354 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel alEnvmixerParam
