.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9210-0xB92A4 (VRAM 0x002B8610) */
glabel alSynStartVoice
    /* B9210 002B8610 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B9214 002B8614 AFB10014 */  sw         $s1, 0x14($sp)
    /* B9218 002B8618 00808821 */  addu       $s1, $a0, $zero
    /* B921C 002B861C AFB00010 */  sw         $s0, 0x10($sp)
    /* B9220 002B8620 00A08021 */  addu       $s0, $a1, $zero
    /* B9224 002B8624 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B9228 002B8628 AFB20018 */  sw         $s2, 0x18($sp)
    /* B922C 002B862C 8E020008 */  lw         $v0, 0x8($s0)
    /* B9230 002B8630 10400016 */  beqz       $v0, .L002B868C
    /* B9234 002B8634 00C09021 */   addu      $s2, $a2, $zero
    /* B9238 002B8638 0C0AE332 */  jal        __allocParam
    /* B923C 002B863C 00000000 */   nop
    /* B9240 002B8640 00403021 */  addu       $a2, $v0, $zero
    /* B9244 002B8644 10C00011 */  beqz       $a2, .L002B868C
    /* B9248 002B8648 00000000 */   nop
    /* B924C 002B864C 8E020008 */  lw         $v0, 0x8($s0)
    /* B9250 002B8650 8E23001C */  lw         $v1, 0x1C($s1)
    /* B9254 002B8654 8C4400D8 */  lw         $a0, 0xD8($v0)
    /* B9258 002B8658 2402000E */  addiu      $v0, $zero, 0xE
    /* B925C 002B865C A4C20008 */  sh         $v0, 0x8($a2)
    /* B9260 002B8660 ACD2000C */  sw         $s2, 0xC($a2)
    /* B9264 002B8664 ACC00000 */  sw         $zero, 0x0($a2)
    /* B9268 002B8668 00641821 */  addu       $v1, $v1, $a0
    /* B926C 002B866C ACC30004 */  sw         $v1, 0x4($a2)
    /* B9270 002B8670 9602001A */  lhu        $v0, 0x1A($s0)
    /* B9274 002B8674 A4C2000A */  sh         $v0, 0xA($a2)
    /* B9278 002B8678 8E020008 */  lw         $v0, 0x8($s0)
    /* B927C 002B867C 8C44000C */  lw         $a0, 0xC($v0)
    /* B9280 002B8680 8C820008 */  lw         $v0, 0x8($a0)
    /* B9284 002B8684 0040F809 */  jalr       $v0
    /* B9288 002B8688 24050003 */   addiu     $a1, $zero, 0x3
  .L002B868C:
    /* B928C 002B868C 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B9290 002B8690 8FB20018 */  lw         $s2, 0x18($sp)
    /* B9294 002B8694 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9298 002B8698 8FB00010 */  lw         $s0, 0x10($sp)
    /* B929C 002B869C 03E00008 */  jr         $ra
    /* B92A0 002B86A0 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel alSynStartVoice
