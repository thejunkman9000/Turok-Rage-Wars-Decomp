.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBC190-0xBC224 (VRAM 0x002BB590) */
glabel func_002BB590
    /* BC190 002BB590 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BC194 002BB594 AFB10014 */  sw         $s1, 0x14($sp)
    /* BC198 002BB598 00808821 */  addu       $s1, $a0, $zero
    /* BC19C 002BB59C 00051400 */  sll        $v0, $a1, 16
    /* BC1A0 002BB5A0 00C02821 */  addu       $a1, $a2, $zero
    /* BC1A4 002BB5A4 00E03021 */  addu       $a2, $a3, $zero
    /* BC1A8 002BB5A8 00021403 */  sra        $v0, $v0, 16
    /* BC1AC 002BB5AC AFB00010 */  sw         $s0, 0x10($sp)
    /* BC1B0 002BB5B0 00028080 */  sll        $s0, $v0, 2
    /* BC1B4 002BB5B4 02028021 */  addu       $s0, $s0, $v0
    /* BC1B8 002BB5B8 00108080 */  sll        $s0, $s0, 2
    /* BC1BC 002BB5BC 02028023 */  subu       $s0, $s0, $v0
    /* BC1C0 002BB5C0 AFBF0018 */  sw         $ra, 0x18($sp)
    /* BC1C4 002BB5C4 8E240034 */  lw         $a0, 0x34($s1)
    /* BC1C8 002BB5C8 00108080 */  sll        $s0, $s0, 2
    /* BC1CC 002BB5CC 00902021 */  addu       $a0, $a0, $s0
    /* BC1D0 002BB5D0 0C0AE3F8 */  jal        func_002B8FE0
    /* BC1D4 002BB5D4 24840020 */   addiu     $a0, $a0, 0x20
    /* BC1D8 002BB5D8 8E260034 */  lw         $a2, 0x34($s1)
    /* BC1DC 002BB5DC 24050001 */  addiu      $a1, $zero, 0x1
    /* BC1E0 002BB5E0 00D03021 */  addu       $a2, $a2, $s0
    /* BC1E4 002BB5E4 0C0AEC6A */  jal        func_002BB1A8
    /* BC1E8 002BB5E8 24C40020 */   addiu     $a0, $a2, 0x20
    /* BC1EC 002BB5EC 24050002 */  addiu      $a1, $zero, 0x2
    /* BC1F0 002BB5F0 8E260034 */  lw         $a2, 0x34($s1)
    /* BC1F4 002BB5F4 8E240030 */  lw         $a0, 0x30($s1)
    /* BC1F8 002BB5F8 00D03021 */  addu       $a2, $a2, $s0
    /* BC1FC 002BB5FC 0C0AE984 */  jal        func_002BA610
    /* BC200 002BB600 24C60020 */   addiu     $a2, $a2, 0x20
    /* BC204 002BB604 8E220034 */  lw         $v0, 0x34($s1)
    /* BC208 002BB608 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BC20C 002BB60C 8FB10014 */  lw         $s1, 0x14($sp)
    /* BC210 002BB610 00501021 */  addu       $v0, $v0, $s0
    /* BC214 002BB614 8FB00010 */  lw         $s0, 0x10($sp)
    /* BC218 002BB618 24420020 */  addiu      $v0, $v0, 0x20
    /* BC21C 002BB61C 03E00008 */  jr         $ra
    /* BC220 002BB620 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002BB590
