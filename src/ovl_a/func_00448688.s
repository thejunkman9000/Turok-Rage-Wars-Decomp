.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B6688-0x1B673C (VRAM 0x00448688) */
glabel func_00448688
    /* 1B6688 00448688 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* 1B668C 0044868C 00A04021 */  addu       $t0, $a1, $zero
    /* 1B6690 00448690 00004821 */  addu       $t1, $zero, $zero
    /* 1B6694 00448694 3C078015 */  lui        $a3, %hi(__osPfsPifRam)
    /* 1B6698 00448698 24E74110 */  addiu      $a3, $a3, %lo(__osPfsPifRam)
    /* 1B669C 0044869C 3C038015 */  lui        $v1, %hi(__osContNumControllers)
    /* 1B66A0 004486A0 2463D46C */  addiu      $v1, $v1, %lo(__osContNumControllers)
    /* 1B66A4 004486A4 90620000 */  lbu        $v0, 0x0($v1)
    /* 1B66A8 004486A8 10400021 */  beqz       $v0, .L00448730
    /* 1B66AC 004486AC 00003021 */   addu      $a2, $zero, $zero
    /* 1B66B0 004486B0 240B0001 */  addiu      $t3, $zero, 0x1
    /* 1B66B4 004486B4 00605021 */  addu       $t2, $v1, $zero
    /* 1B66B8 004486B8 24A50002 */  addiu      $a1, $a1, 0x2
  .L004486BC:
    /* 1B66BC 004486BC 88EC0000 */  lwl        $t4, 0x0($a3)
    /* 1B66C0 004486C0 98EC0003 */  lwr        $t4, 0x3($a3)
    /* 1B66C4 004486C4 88ED0004 */  lwl        $t5, 0x4($a3)
    /* 1B66C8 004486C8 98ED0007 */  lwr        $t5, 0x7($a3)
    /* 1B66CC 004486CC ABAC0000 */  swl        $t4, 0x0($sp)
    /* 1B66D0 004486D0 BBAC0003 */  swr        $t4, 0x3($sp)
    /* 1B66D4 004486D4 ABAD0004 */  swl        $t5, 0x4($sp)
    /* 1B66D8 004486D8 BBAD0007 */  swr        $t5, 0x7($sp)
    /* 1B66DC 004486DC 93A20002 */  lbu        $v0, 0x2($sp)
    /* 1B66E0 004486E0 304200C0 */  andi       $v0, $v0, 0xC0
    /* 1B66E4 004486E4 00021102 */  srl        $v0, $v0, 4
    /* 1B66E8 004486E8 1440000A */  bnez       $v0, .L00448714
    /* 1B66EC 004486EC A0A20001 */   sb        $v0, 0x1($a1)
    /* 1B66F0 004486F0 93A20005 */  lbu        $v0, 0x5($sp)
    /* 1B66F4 004486F4 93A30004 */  lbu        $v1, 0x4($sp)
    /* 1B66F8 004486F8 00021200 */  sll        $v0, $v0, 8
    /* 1B66FC 004486FC 00621825 */  or         $v1, $v1, $v0
    /* 1B6700 00448700 00CB1004 */  sllv       $v0, $t3, $a2
    /* 1B6704 00448704 A5030000 */  sh         $v1, 0x0($t0)
    /* 1B6708 00448708 93A30006 */  lbu        $v1, 0x6($sp)
    /* 1B670C 0044870C 01224825 */  or         $t1, $t1, $v0
    /* 1B6710 00448710 A0A30000 */  sb         $v1, 0x0($a1)
  .L00448714:
    /* 1B6714 00448714 24C60001 */  addiu      $a2, $a2, 0x1
    /* 1B6718 00448718 24E70008 */  addiu      $a3, $a3, 0x8
    /* 1B671C 0044871C 24A50004 */  addiu      $a1, $a1, 0x4
    /* 1B6720 00448720 91420000 */  lbu        $v0, 0x0($t2)
    /* 1B6724 00448724 00C2102A */  slt        $v0, $a2, $v0
    /* 1B6728 00448728 1440FFE4 */  bnez       $v0, .L004486BC
    /* 1B672C 0044872C 25080004 */   addiu     $t0, $t0, 0x4
  .L00448730:
    /* 1B6730 00448730 A0890000 */  sb         $t1, 0x0($a0)
    /* 1B6734 00448734 03E00008 */  jr         $ra
    /* 1B6738 00448738 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel func_00448688
