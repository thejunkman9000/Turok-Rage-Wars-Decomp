.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB41D0-0xB4288 (VRAM 0x002B35D0) */
glabel __getTrackByte
    /* B41D0 002B35D0 00854021 */  addu       $t0, $a0, $a1
    /* B41D4 002B35D4 91020098 */  lbu        $v0, 0x98($t0)
    /* B41D8 002B35D8 10400007 */  beqz       $v0, .L002B35F8
    /* B41DC 002B35DC 00051880 */   sll       $v1, $a1, 2
    /* B41E0 002B35E0 00831821 */  addu       $v1, $a0, $v1
    /* B41E4 002B35E4 8C620058 */  lw         $v0, 0x58($v1)
    /* B41E8 002B35E8 90440000 */  lbu        $a0, 0x0($v0)
    /* B41EC 002B35EC 24420001 */  addiu      $v0, $v0, 0x1
    /* B41F0 002B35F0 080ACD9D */  j          .L002B3674
    /* B41F4 002B35F4 AC620058 */   sw        $v0, 0x58($v1)
  .L002B35F8:
    /* B41F8 002B35F8 00051080 */  sll        $v0, $a1, 2
    /* B41FC 002B35FC 00823821 */  addu       $a3, $a0, $v0
    /* B4200 002B3600 8CE60018 */  lw         $a2, 0x18($a3)
    /* B4204 002B3604 90C40000 */  lbu        $a0, 0x0($a2)
    /* B4208 002B3608 24C20001 */  addiu      $v0, $a2, 0x1
    /* B420C 002B360C ACE20018 */  sw         $v0, 0x18($a3)
    /* B4210 002B3610 240200FE */  addiu      $v0, $zero, 0xFE
    /* B4214 002B3614 308500FF */  andi       $a1, $a0, 0xFF
    /* B4218 002B3618 14A20019 */  bne        $a1, $v0, .L002B3680
    /* B421C 002B361C 24C20002 */   addiu     $v0, $a2, 0x2
    /* B4220 002B3620 90C30001 */  lbu        $v1, 0x1($a2)
    /* B4224 002B3624 306300FF */  andi       $v1, $v1, 0xFF
    /* B4228 002B3628 10650015 */  beq        $v1, $a1, .L002B3680
    /* B422C 002B362C ACE20018 */   sw        $v0, 0x18($a3)
    /* B4230 002B3630 00031A00 */  sll        $v1, $v1, 8
    /* B4234 002B3634 90C40002 */  lbu        $a0, 0x2($a2)
    /* B4238 002B3638 24C20003 */  addiu      $v0, $a2, 0x3
    /* B423C 002B363C ACE20018 */  sw         $v0, 0x18($a3)
    /* B4240 002B3640 90C50003 */  lbu        $a1, 0x3($a2)
    /* B4244 002B3644 24C20004 */  addiu      $v0, $a2, 0x4
    /* B4248 002B3648 ACE20018 */  sw         $v0, 0x18($a3)
    /* B424C 002B364C 308400FF */  andi       $a0, $a0, 0xFF
    /* B4250 002B3650 00641821 */  addu       $v1, $v1, $a0
    /* B4254 002B3654 24630004 */  addiu      $v1, $v1, 0x4
    /* B4258 002B3658 00431023 */  subu       $v0, $v0, $v1
    /* B425C 002B365C ACE20058 */  sw         $v0, 0x58($a3)
    /* B4260 002B3660 A1050098 */  sb         $a1, 0x98($t0)
    /* B4264 002B3664 8CE20058 */  lw         $v0, 0x58($a3)
    /* B4268 002B3668 90440000 */  lbu        $a0, 0x0($v0)
    /* B426C 002B366C 24420001 */  addiu      $v0, $v0, 0x1
    /* B4270 002B3670 ACE20058 */  sw         $v0, 0x58($a3)
  .L002B3674:
    /* B4274 002B3674 91020098 */  lbu        $v0, 0x98($t0)
    /* B4278 002B3678 2442FFFF */  addiu      $v0, $v0, -0x1
    /* B427C 002B367C A1020098 */  sb         $v0, 0x98($t0)
  .L002B3680:
    /* B4280 002B3680 03E00008 */  jr         $ra
    /* B4284 002B3684 00801021 */   addu      $v0, $a0, $zero
endlabel __getTrackByte
