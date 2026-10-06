.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB0144-0xB02A0 (VRAM 0x002AF544) */
glabel dbgLinkCmdWriteBlock
    /* B0144 002AF544 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B0148 002AF548 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B014C 002AF54C 27B10014 */  addiu      $s1, $sp, 0x14
    /* B0150 002AF550 02202021 */  addu       $a0, $s1, $zero
    /* B0154 002AF554 AFBF0034 */  sw         $ra, 0x34($sp)
    /* B0158 002AF558 AFB20030 */  sw         $s2, 0x30($sp)
    /* B015C 002AF55C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0160 002AF560 AFB00028 */   sw        $s0, 0x28($sp)
    /* B0164 002AF564 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0168 002AF568 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B016C 002AF56C 14400045 */  bnez       $v0, .L002AF684
    /* B0170 002AF570 00009021 */   addu      $s2, $zero, $zero
    /* B0174 002AF574 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0178 002AF578 02202021 */  addu       $a0, $s1, $zero
    /* B017C 002AF57C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0180 002AF580 00028200 */   sll       $s0, $v0, 8
    /* B0184 002AF584 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0188 002AF588 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B018C 002AF58C 1440003E */  bnez       $v0, .L002AF688
    /* B0190 002AF590 02401021 */   addu      $v0, $s2, $zero
    /* B0194 002AF594 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0198 002AF598 02202021 */  addu       $a0, $s1, $zero
    /* B019C 002AF59C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B01A0 002AF5A0 02028025 */   or        $s0, $s0, $v0
    /* B01A4 002AF5A4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B01A8 002AF5A8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B01AC 002AF5AC 14400035 */  bnez       $v0, .L002AF684
    /* B01B0 002AF5B0 00108200 */   sll       $s0, $s0, 8
    /* B01B4 002AF5B4 93A20014 */  lbu        $v0, 0x14($sp)
    /* B01B8 002AF5B8 02202021 */  addu       $a0, $s1, $zero
    /* B01BC 002AF5BC 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B01C0 002AF5C0 02028025 */   or        $s0, $s0, $v0
    /* B01C4 002AF5C4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B01C8 002AF5C8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B01CC 002AF5CC 1440002D */  bnez       $v0, .L002AF684
    /* B01D0 002AF5D0 00108200 */   sll       $s0, $s0, 8
    /* B01D4 002AF5D4 27B1001C */  addiu      $s1, $sp, 0x1C
    /* B01D8 002AF5D8 93A20014 */  lbu        $v0, 0x14($sp)
    /* B01DC 002AF5DC 02202021 */  addu       $a0, $s1, $zero
    /* B01E0 002AF5E0 02028025 */  or         $s0, $s0, $v0
    /* B01E4 002AF5E4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B01E8 002AF5E8 AFB00010 */   sw        $s0, 0x10($sp)
    /* B01EC 002AF5EC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B01F0 002AF5F0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B01F4 002AF5F4 14400024 */  bnez       $v0, .L002AF688
    /* B01F8 002AF5F8 02401021 */   addu      $v0, $s2, $zero
    /* B01FC 002AF5FC 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B0200 002AF600 02202021 */  addu       $a0, $s1, $zero
    /* B0204 002AF604 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0208 002AF608 00028200 */   sll       $s0, $v0, 8
    /* B020C 002AF60C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0210 002AF610 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0214 002AF614 1440001C */  bnez       $v0, .L002AF688
    /* B0218 002AF618 02401021 */   addu      $v0, $s2, $zero
    /* B021C 002AF61C 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B0220 002AF620 02202021 */  addu       $a0, $s1, $zero
    /* B0224 002AF624 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0228 002AF628 02028025 */   or        $s0, $s0, $v0
    /* B022C 002AF62C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0230 002AF630 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0234 002AF634 14400013 */  bnez       $v0, .L002AF684
    /* B0238 002AF638 00108200 */   sll       $s0, $s0, 8
    /* B023C 002AF63C 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B0240 002AF640 02202021 */  addu       $a0, $s1, $zero
    /* B0244 002AF644 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0248 002AF648 02028025 */   or        $s0, $s0, $v0
    /* B024C 002AF64C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0250 002AF650 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0254 002AF654 1440000B */  bnez       $v0, .L002AF684
    /* B0258 002AF658 00108200 */   sll       $s0, $s0, 8
    /* B025C 002AF65C 27A60020 */  addiu      $a2, $sp, 0x20
    /* B0260 002AF660 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B0264 002AF664 8FA40010 */  lw         $a0, 0x10($sp)
    /* B0268 002AF668 02028025 */  or         $s0, $s0, $v0
    /* B026C 002AF66C 02002821 */  addu       $a1, $s0, $zero
    /* B0270 002AF670 0C0ABA0D */  jal        dbgLinkRecvBlock
    /* B0274 002AF674 AFB00018 */   sw        $s0, 0x18($sp)
    /* B0278 002AF678 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B027C 002AF67C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0280 002AF680 2C520001 */  sltiu      $s2, $v0, 0x1
  .L002AF684:
    /* B0284 002AF684 02401021 */  addu       $v0, $s2, $zero
  .L002AF688:
    /* B0288 002AF688 8FBF0034 */  lw         $ra, 0x34($sp)
    /* B028C 002AF68C 8FB20030 */  lw         $s2, 0x30($sp)
    /* B0290 002AF690 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B0294 002AF694 8FB00028 */  lw         $s0, 0x28($sp)
    /* B0298 002AF698 03E00008 */  jr         $ra
    /* B029C 002AF69C 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgLinkCmdWriteBlock
