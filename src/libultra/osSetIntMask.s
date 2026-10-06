.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2E60-0xC2F10 (VRAM 0x002C2260) */
glabel osSetIntMask
    /* C2E60 002C2260 400C6000 */  mfc0       $t4, $12 /* handwritten instruction */
    /* C2E64 002C2264 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C2E68 002C2268 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C2E6C 002C226C 3182FF01 */  andi       $v0, $t4, 0xFF01
    /* C2E70 002C2270 8D0B0000 */  lw         $t3, 0x0($t0)
    /* C2E74 002C2274 00000000 */  nop
    /* C2E78 002C2278 2401FFFF */  addiu      $at, $zero, -0x1
    /* C2E7C 002C227C 01614026 */  xor        $t0, $t3, $at
    /* C2E80 002C2280 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* C2E84 002C2284 00481025 */  or         $v0, $v0, $t0
    /* C2E88 002C2288 3C0AA430 */  lui        $t2, %hi(MI_INTR_MASK_REG)
    /* C2E8C 002C228C 8D4A000C */  lw         $t2, %lo(MI_INTR_MASK_REG)($t2)
    /* C2E90 002C2290 00000000 */  nop
    /* C2E94 002C2294 11400005 */  beqz       $t2, .L002C22AC
    /* C2E98 002C2298 000B4C02 */   srl       $t1, $t3, 16
    /* C2E9C 002C229C 2401FFFF */  addiu      $at, $zero, -0x1
    /* C2EA0 002C22A0 01214826 */  xor        $t1, $t1, $at
    /* C2EA4 002C22A4 3129003F */  andi       $t1, $t1, 0x3F
    /* C2EA8 002C22A8 01495025 */  or         $t2, $t2, $t1
  .L002C22AC:
    /* C2EAC 002C22AC 000A5400 */  sll        $t2, $t2, 16
    /* C2EB0 002C22B0 004A1025 */  or         $v0, $v0, $t2
    /* C2EB4 002C22B4 3C01003F */  lui        $at, (0x3F0000 >> 16)
    /* C2EB8 002C22B8 00814024 */  and        $t0, $a0, $at
    /* C2EBC 002C22BC 010B4024 */  and        $t0, $t0, $t3
    /* C2EC0 002C22C0 000843C2 */  srl        $t0, $t0, 15
    /* C2EC4 002C22C4 3C01800D */  lui        $at, %hi(__osRcpImTable)
    /* C2EC8 002C22C8 00280821 */  addu       $at, $at, $t0
    /* C2ECC 002C22CC 942ACCC0 */  lhu        $t2, %lo(__osRcpImTable)($at)
    /* C2ED0 002C22D0 3C01A430 */  lui        $at, %hi(MI_INTR_MASK_REG)
    /* C2ED4 002C22D4 AC2A000C */  sw         $t2, %lo(MI_INTR_MASK_REG)($at)
    /* C2ED8 002C22D8 3088FF01 */  andi       $t0, $a0, 0xFF01
    /* C2EDC 002C22DC 3169FF00 */  andi       $t1, $t3, 0xFF00
    /* C2EE0 002C22E0 01094024 */  and        $t0, $t0, $t1
    /* C2EE4 002C22E4 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* C2EE8 002C22E8 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* C2EEC 002C22EC 01816024 */  and        $t4, $t4, $at
    /* C2EF0 002C22F0 01886025 */  or         $t4, $t4, $t0
    /* C2EF4 002C22F4 408C6000 */  mtc0       $t4, $12 /* handwritten instruction */
    /* C2EF8 002C22F8 00000000 */  nop
    /* C2EFC 002C22FC 00000000 */  nop
    /* C2F00 002C2300 03E00008 */  jr         $ra
    /* C2F04 002C2304 00000000 */   nop


    /* C2F08 002C2308 00031902 */  .word      0x00031902 /* linker padding */
    /* C2F0C 002C230C AE02003C */  .word      0xAE02003C /* linker padding */
endlabel osSetIntMask
