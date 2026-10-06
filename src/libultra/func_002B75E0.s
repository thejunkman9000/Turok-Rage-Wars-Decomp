.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB81E0-0xB82A0 (VRAM 0x002B75E0) */
glabel func_002B75E0
    /* B81E0 002B75E0 8C820044 */  lw         $v0, 0x44($a0)
    /* B81E4 002B75E4 8C890040 */  lw         $t1, 0x40($a0)
    /* B81E8 002B75E8 18400029 */  blez       $v0, .L002B7690
    /* B81EC 002B75EC 00004021 */   addu      $t0, $zero, $zero
    /* B81F0 002B75F0 240B0005 */  addiu      $t3, $zero, 0x5
    /* B81F4 002B75F4 3C01800D */  lui        $at, %hi(D_800CC760)
    /* B81F8 002B75F8 C420C760 */  lwc1       $fv0, %lo(D_800CC760)($at)
    /* B81FC 002B75FC 240C0040 */  addiu      $t4, $zero, 0x40
    /* B8200 002B7600 3C0A8102 */  lui        $t2, (0x81020409 >> 16)
    /* B8204 002B7604 354A0409 */  ori        $t2, $t2, (0x81020409 & 0xFFFF)
    /* B8208 002B7608 00081400 */  sll        $v0, $t0, 16
  .L002B760C:
    /* B820C 002B760C 00023C03 */  sra        $a3, $v0, 16
    /* B8210 002B7610 00071040 */  sll        $v0, $a3, 1
    /* B8214 002B7614 00471021 */  addu       $v0, $v0, $a3
    /* B8218 002B7618 00021100 */  sll        $v0, $v0, 4
    /* B821C 002B761C 00493021 */  addu       $a2, $v0, $t1
    /* B8220 002B7620 8CC2001C */  lw         $v0, 0x1C($a2)
    /* B8224 002B7624 14400013 */  bnez       $v0, .L002B7674
    /* B8228 002B7628 25020001 */   addiu     $v0, $t0, 0x1
    /* B822C 002B762C ACC5001C */  sw         $a1, 0x1C($a2)
    /* B8230 002B7630 A4CB0020 */  sh         $t3, 0x20($a2)
    /* B8234 002B7634 ACC00028 */  sw         $zero, 0x28($a2)
    /* B8238 002B7638 E4C00024 */  swc1       $fv0, 0x24($a2)
    /* B823C 002B763C A0CC002E */  sb         $t4, 0x2E($a2)
    /* B8240 002B7640 A0C0002F */  sb         $zero, 0x2F($a2)
    /* B8244 002B7644 90A2000D */  lbu        $v0, 0xD($a1)
    /* B8248 002B7648 00021BC0 */  sll        $v1, $v0, 15
    /* B824C 002B764C 00621823 */  subu       $v1, $v1, $v0
    /* B8250 002B7650 006A0018 */  mult       $v1, $t2
    /* B8254 002B7654 00E01021 */  addu       $v0, $a3, $zero
    /* B8258 002B7658 00006810 */  mfhi       $t5
    /* B825C 002B765C 01A32021 */  addu       $a0, $t5, $v1
    /* B8260 002B7660 00042183 */  sra        $a0, $a0, 6
    /* B8264 002B7664 00031FC3 */  sra        $v1, $v1, 31
    /* B8268 002B7668 00832023 */  subu       $a0, $a0, $v1
    /* B826C 002B766C 03E00008 */  jr         $ra
    /* B8270 002B7670 A4C4002C */   sh        $a0, 0x2C($a2)
  .L002B7674:
    /* B8274 002B7674 00404021 */  addu       $t0, $v0, $zero
    /* B8278 002B7678 00021400 */  sll        $v0, $v0, 16
    /* B827C 002B767C 8C830044 */  lw         $v1, 0x44($a0)
    /* B8280 002B7680 00021403 */  sra        $v0, $v0, 16
    /* B8284 002B7684 0043102A */  slt        $v0, $v0, $v1
    /* B8288 002B7688 1440FFE0 */  bnez       $v0, .L002B760C
    /* B828C 002B768C 00081400 */   sll       $v0, $t0, 16
  .L002B7690:
    /* B8290 002B7690 03E00008 */  jr         $ra
    /* B8294 002B7694 2402FFFF */   addiu     $v0, $zero, -0x1


glabel func_002B7698
    /* B8298 002B7698 8FB00010 */  lw         $s0, 0x10($sp)
    /* B829C 002B769C 03E00008 */  jr         $ra
endlabel func_002B75E0
