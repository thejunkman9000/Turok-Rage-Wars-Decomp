.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7B50-0xB7CB8 (VRAM 0x002B6F50) */
glabel alSeqNextEvent
    /* B7B50 002B6F50 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B7B54 002B6F54 AFB20018 */  sw         $s2, 0x18($sp)
    /* B7B58 002B6F58 00809021 */  addu       $s2, $a0, $zero
    /* B7B5C 002B6F5C AFB10014 */  sw         $s1, 0x14($sp)
    /* B7B60 002B6F60 00A08821 */  addu       $s1, $a1, $zero
    /* B7B64 002B6F64 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B7B68 002B6F68 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B7B6C 002B6F6C 0C0ADD0B */  jal        __alSeqReadVarLen
    /* B7B70 002B6F70 AFB00010 */   sw        $s0, 0x10($sp)
    /* B7B74 002B6F74 02402021 */  addu       $a0, $s2, $zero
    /* B7B78 002B6F78 8E43000C */  lw         $v1, 0xC($s2)
    /* B7B7C 002B6F7C 00409821 */  addu       $s3, $v0, $zero
    /* B7B80 002B6F80 00731821 */  addu       $v1, $v1, $s3
    /* B7B84 002B6F84 0C0ADD20 */  jal        __alSeqReadByte
    /* B7B88 002B6F88 AE43000C */   sw        $v1, 0xC($s2)
    /* B7B8C 002B6F8C 00408021 */  addu       $s0, $v0, $zero
    /* B7B90 002B6F90 320300FF */  andi       $v1, $s0, 0xFF
    /* B7B94 002B6F94 240200FF */  addiu      $v0, $zero, 0xFF
    /* B7B98 002B6F98 14620026 */  bne        $v1, $v0, .L002B7034
    /* B7B9C 002B6F9C 24020001 */   addiu     $v0, $zero, 0x1
    /* B7BA0 002B6FA0 0C0ADD20 */  jal        __alSeqReadByte
    /* B7BA4 002B6FA4 02402021 */   addu      $a0, $s2, $zero
    /* B7BA8 002B6FA8 00402821 */  addu       $a1, $v0, $zero
    /* B7BAC 002B6FAC 30A300FF */  andi       $v1, $a1, 0xFF
    /* B7BB0 002B6FB0 24020051 */  addiu      $v0, $zero, 0x51
    /* B7BB4 002B6FB4 14620013 */  bne        $v1, $v0, .L002B7004
    /* B7BB8 002B6FB8 2402002F */   addiu     $v0, $zero, 0x2F
    /* B7BBC 002B6FBC 02402021 */  addu       $a0, $s2, $zero
    /* B7BC0 002B6FC0 24020003 */  addiu      $v0, $zero, 0x3
    /* B7BC4 002B6FC4 A6220000 */  sh         $v0, 0x0($s1)
    /* B7BC8 002B6FC8 AE330004 */  sw         $s3, 0x4($s1)
    /* B7BCC 002B6FCC A2300008 */  sb         $s0, 0x8($s1)
    /* B7BD0 002B6FD0 0C0ADD20 */  jal        __alSeqReadByte
    /* B7BD4 002B6FD4 A2250009 */   sb        $a1, 0x9($s1)
    /* B7BD8 002B6FD8 02402021 */  addu       $a0, $s2, $zero
    /* B7BDC 002B6FDC 0C0ADD20 */  jal        __alSeqReadByte
    /* B7BE0 002B6FE0 A222000A */   sb        $v0, 0xA($s1)
    /* B7BE4 002B6FE4 02402021 */  addu       $a0, $s2, $zero
    /* B7BE8 002B6FE8 0C0ADD20 */  jal        __alSeqReadByte
    /* B7BEC 002B6FEC A222000B */   sb        $v0, 0xB($s1)
    /* B7BF0 002B6FF0 02402021 */  addu       $a0, $s2, $zero
    /* B7BF4 002B6FF4 0C0ADD20 */  jal        __alSeqReadByte
    /* B7BF8 002B6FF8 A222000C */   sb        $v0, 0xC($s1)
    /* B7BFC 002B6FFC 080ADC0B */  j          .L002B702C
    /* B7C00 002B7000 A222000D */   sb        $v0, 0xD($s1)
  .L002B7004:
    /* B7C04 002B7004 54620025 */  bnel       $v1, $v0, .L002B709C
    /* B7C08 002B7008 A640001A */   sh        $zero, 0x1A($s2)
    /* B7C0C 002B700C 02402021 */  addu       $a0, $s2, $zero
    /* B7C10 002B7010 24020004 */  addiu      $v0, $zero, 0x4
    /* B7C14 002B7014 A6220000 */  sh         $v0, 0x0($s1)
    /* B7C18 002B7018 AE330004 */  sw         $s3, 0x4($s1)
    /* B7C1C 002B701C A2300008 */  sb         $s0, 0x8($s1)
    /* B7C20 002B7020 0C0ADD20 */  jal        __alSeqReadByte
    /* B7C24 002B7024 A2250009 */   sb        $a1, 0x9($s1)
    /* B7C28 002B7028 A222000A */  sb         $v0, 0xA($s1)
  .L002B702C:
    /* B7C2C 002B702C 080ADC27 */  j          .L002B709C
    /* B7C30 002B7030 A640001A */   sh        $zero, 0x1A($s2)
  .L002B7034:
    /* B7C34 002B7034 A6220000 */  sh         $v0, 0x0($s1)
    /* B7C38 002B7038 32020080 */  andi       $v0, $s0, 0x80
    /* B7C3C 002B703C 10400008 */  beqz       $v0, .L002B7060
    /* B7C40 002B7040 AE330004 */   sw        $s3, 0x4($s1)
    /* B7C44 002B7044 02402021 */  addu       $a0, $s2, $zero
    /* B7C48 002B7048 0C0ADD20 */  jal        __alSeqReadByte
    /* B7C4C 002B704C A2300008 */   sb        $s0, 0x8($s1)
    /* B7C50 002B7050 A2220009 */  sb         $v0, 0x9($s1)
    /* B7C54 002B7054 320200FF */  andi       $v0, $s0, 0xFF
    /* B7C58 002B7058 080ADC1B */  j          .L002B706C
    /* B7C5C 002B705C A642001A */   sh        $v0, 0x1A($s2)
  .L002B7060:
    /* B7C60 002B7060 9242001B */  lbu        $v0, 0x1B($s2)
    /* B7C64 002B7064 A2300009 */  sb         $s0, 0x9($s1)
    /* B7C68 002B7068 A2220008 */  sb         $v0, 0x8($s1)
  .L002B706C:
    /* B7C6C 002B706C 92220008 */  lbu        $v0, 0x8($s1)
    /* B7C70 002B7070 304300F0 */  andi       $v1, $v0, 0xF0
    /* B7C74 002B7074 240200C0 */  addiu      $v0, $zero, 0xC0
    /* B7C78 002B7078 10620007 */  beq        $v1, $v0, .L002B7098
    /* B7C7C 002B707C 240200D0 */   addiu     $v0, $zero, 0xD0
    /* B7C80 002B7080 50620006 */  beql       $v1, $v0, .L002B709C
    /* B7C84 002B7084 A220000A */   sb        $zero, 0xA($s1)
    /* B7C88 002B7088 0C0ADD20 */  jal        __alSeqReadByte
    /* B7C8C 002B708C 02402021 */   addu      $a0, $s2, $zero
    /* B7C90 002B7090 080ADC27 */  j          .L002B709C
    /* B7C94 002B7094 A222000A */   sb        $v0, 0xA($s1)
  .L002B7098:
    /* B7C98 002B7098 A220000A */  sb         $zero, 0xA($s1)
  .L002B709C:
    /* B7C9C 002B709C 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B7CA0 002B70A0 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B7CA4 002B70A4 8FB20018 */  lw         $s2, 0x18($sp)
    /* B7CA8 002B70A8 8FB10014 */  lw         $s1, 0x14($sp)
    /* B7CAC 002B70AC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B7CB0 002B70B0 03E00008 */  jr         $ra
    /* B7CB4 002B70B4 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alSeqNextEvent
