.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5078-0xC5204 (VRAM 0x002C4478) */
glabel adecDecodeFrame
    /* C5078 002C4478 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* C507C 002C447C AFB10024 */  sw         $s1, 0x24($sp)
    /* C5080 002C4480 3C03800E */  lui        $v1, %hi(D_800D94EE)
    /* C5084 002C4484 246394EE */  addiu      $v1, $v1, %lo(D_800D94EE)
    /* C5088 002C4488 AFBF0028 */  sw         $ra, 0x28($sp)
    /* C508C 002C448C AFB00020 */  sw         $s0, 0x20($sp)
    /* C5090 002C4490 84620000 */  lh         $v0, 0x0($v1)
    /* C5094 002C4494 3C10800E */  lui        $s0, %hi(D_800D9594)
    /* C5098 002C4498 26109594 */  addiu      $s0, $s0, %lo(D_800D9594)
    /* C509C 002C449C 14400026 */  bnez       $v0, .L002C4538
    /* C50A0 002C44A0 00808821 */   addu      $s1, $a0, $zero
    /* C50A4 002C44A4 26240018 */  addiu      $a0, $s1, 0x18
    /* C50A8 002C44A8 24050006 */  addiu      $a1, $zero, 0x6
    /* C50AC 002C44AC 24060010 */  addiu      $a2, $zero, 0x10
    /* C50B0 002C44B0 00003821 */  addu       $a3, $zero, $zero
    /* C50B4 002C44B4 24020001 */  addiu      $v0, $zero, 0x1
    /* C50B8 002C44B8 A4620000 */  sh         $v0, 0x0($v1)
    /* C50BC 002C44BC 0C0B0FA8 */  jal        adecReadBits
    /* C50C0 002C44C0 AFB10010 */   sw        $s1, 0x10($sp)
    /* C50C4 002C44C4 00021400 */  sll        $v0, $v0, 16
    /* C50C8 002C44C8 18400048 */  blez       $v0, .L002C45EC
    /* C50CC 002C44CC 00003821 */   addu      $a3, $zero, $zero
    /* C50D0 002C44D0 8E02000C */  lw         $v0, 0xC($s0)
    /* C50D4 002C44D4 3C058015 */  lui        $a1, %hi(D_801510A0)
    /* C50D8 002C44D8 24A510A0 */  addiu      $a1, $a1, %lo(D_801510A0)
    /* C50DC 002C44DC 24420060 */  addiu      $v0, $v0, 0x60
    /* C50E0 002C44E0 AE02000C */  sw         $v0, 0xC($s0)
  .L002C44E4:
    /* C50E4 002C44E4 00072400 */  sll        $a0, $a3, 16
    /* C50E8 002C44E8 24E30001 */  addiu      $v1, $a3, 0x1
    /* C50EC 002C44EC 00603821 */  addu       $a3, $v1, $zero
    /* C50F0 002C44F0 000423C3 */  sra        $a0, $a0, 15
    /* C50F4 002C44F4 02241021 */  addu       $v0, $s1, $a0
    /* C50F8 002C44F8 00852021 */  addu       $a0, $a0, $a1
    /* C50FC 002C44FC 00031C00 */  sll        $v1, $v1, 16
    /* C5100 002C4500 00031C03 */  sra        $v1, $v1, 16
    /* C5104 002C4504 94420018 */  lhu        $v0, 0x18($v0)
    /* C5108 002C4508 28630010 */  slti       $v1, $v1, 0x10
    /* C510C 002C450C 1460FFF5 */  bnez       $v1, .L002C44E4
    /* C5110 002C4510 A4820000 */   sh        $v0, 0x0($a0)
    /* C5114 002C4514 8E020000 */  lw         $v0, 0x0($s0)
    /* C5118 002C4518 5040002A */  beql       $v0, $zero, .L002C45C4
    /* C511C 002C451C AFB10010 */   sw        $s1, 0x10($sp)
    /* C5120 002C4520 26100014 */  addiu      $s0, $s0, 0x14
  .L002C4524:
    /* C5124 002C4524 8E020000 */  lw         $v0, 0x0($s0)
    /* C5128 002C4528 5440FFFE */  bnel       $v0, $zero, .L002C4524
    /* C512C 002C452C 26100014 */   addiu     $s0, $s0, 0x14
    /* C5130 002C4530 080B1171 */  j          .L002C45C4
    /* C5134 002C4534 AFB10010 */   sw        $s1, 0x10($sp)
  .L002C4538:
    /* C5138 002C4538 AFB10010 */  sw         $s1, 0x10($sp)
    /* C513C 002C453C 02002021 */  addu       $a0, $s0, $zero
    /* C5140 002C4540 26250018 */  addiu      $a1, $s1, 0x18
    /* C5144 002C4544 24060010 */  addiu      $a2, $zero, 0x10
    /* C5148 002C4548 0C0B101D */  jal        adecHuffDecode
    /* C514C 002C454C 27A70018 */   addiu     $a3, $sp, 0x18
    /* C5150 002C4550 00021400 */  sll        $v0, $v0, 16
    /* C5154 002C4554 00021C03 */  sra        $v1, $v0, 16
    /* C5158 002C4558 24020010 */  addiu      $v0, $zero, 0x10
    /* C515C 002C455C 14620024 */  bne        $v1, $v0, .L002C45F0
    /* C5160 002C4560 2402FFFF */   addiu     $v0, $zero, -0x1
    /* C5164 002C4564 00003821 */  addu       $a3, $zero, $zero
    /* C5168 002C4568 87A30018 */  lh         $v1, 0x18($sp)
    /* C516C 002C456C 3C088015 */  lui        $t0, %hi(D_801510A0)
    /* C5170 002C4570 250810A0 */  addiu      $t0, $t0, %lo(D_801510A0)
    /* C5174 002C4574 00031080 */  sll        $v0, $v1, 2
    /* C5178 002C4578 00431021 */  addu       $v0, $v0, $v1
    /* C517C 002C457C 00021080 */  sll        $v0, $v0, 2
    /* C5180 002C4580 00508021 */  addu       $s0, $v0, $s0
  .L002C4584:
    /* C5184 002C4584 00072400 */  sll        $a0, $a3, 16
    /* C5188 002C4588 000423C3 */  sra        $a0, $a0, 15
    /* C518C 002C458C 00882821 */  addu       $a1, $a0, $t0
    /* C5190 002C4590 02242021 */  addu       $a0, $s1, $a0
    /* C5194 002C4594 24E30001 */  addiu      $v1, $a3, 0x1
    /* C5198 002C4598 00603821 */  addu       $a3, $v1, $zero
    /* C519C 002C459C 00031C00 */  sll        $v1, $v1, 16
    /* C51A0 002C45A0 00031C03 */  sra        $v1, $v1, 16
    /* C51A4 002C45A4 94A60000 */  lhu        $a2, 0x0($a1)
    /* C51A8 002C45A8 94820018 */  lhu        $v0, 0x18($a0)
    /* C51AC 002C45AC 28630010 */  slti       $v1, $v1, 0x10
    /* C51B0 002C45B0 00461021 */  addu       $v0, $v0, $a2
    /* C51B4 002C45B4 A4820018 */  sh         $v0, 0x18($a0)
    /* C51B8 002C45B8 1460FFF2 */  bnez       $v1, .L002C4584
    /* C51BC 002C45BC A4A20000 */   sh        $v0, 0x0($a1)
    /* C51C0 002C45C0 AFB10010 */  sw         $s1, 0x10($sp)
  .L002C45C4:
    /* C51C4 002C45C4 02002021 */  addu       $a0, $s0, $zero
    /* C51C8 002C45C8 262500B8 */  addiu      $a1, $s1, 0xB8
    /* C51CC 002C45CC 24060100 */  addiu      $a2, $zero, 0x100
    /* C51D0 002C45D0 0C0B101D */  jal        adecHuffDecode
    /* C51D4 002C45D4 27A70018 */   addiu     $a3, $sp, 0x18
    /* C51D8 002C45D8 00021400 */  sll        $v0, $v0, 16
    /* C51DC 002C45DC 00021C03 */  sra        $v1, $v0, 16
    /* C51E0 002C45E0 24020100 */  addiu      $v0, $zero, 0x100
    /* C51E4 002C45E4 10620002 */  beq        $v1, $v0, .L002C45F0
    /* C51E8 002C45E8 24020001 */   addiu     $v0, $zero, 0x1
  .L002C45EC:
    /* C51EC 002C45EC 2402FFFF */  addiu      $v0, $zero, -0x1
  .L002C45F0:
    /* C51F0 002C45F0 8FBF0028 */  lw         $ra, 0x28($sp)
    /* C51F4 002C45F4 8FB10024 */  lw         $s1, 0x24($sp)
    /* C51F8 002C45F8 8FB00020 */  lw         $s0, 0x20($sp)
    /* C51FC 002C45FC 03E00008 */  jr         $ra
    /* C5200 002C4600 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel adecDecodeFrame
