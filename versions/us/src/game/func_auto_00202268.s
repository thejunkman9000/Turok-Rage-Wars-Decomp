.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (exception vector stubs), US v1.0 ROM 0x2E68-0x2EE0 (VRAM 0x00202268), same words as v1.1 func_00202268 except the data address (lui/addiu k0 = 0x00202460) */
glabel func_auto_00202268
    /* 2E68 00202268 05000008 */  .word      0x05000008 /* was: bltz       $t0, .Lauto_0020228C */
    /* 2E6C 0020226C 00040000 */   sll       $zero, $a0, 0
    /* 2E70 00202270 409AF000 */  mtc0       $k0, $30 /* handwritten instruction */
    /* 2E74 00202274 3C1A0020 */  lui        $k0, %hi(D_auto_00202460) /* handwritten instruction */
    /* 2E78 00202278 275A2460 */  addiu      $k0, $k0, %lo(D_auto_00202460) /* handwritten instruction */
    /* 2E7C 0020227C 03400008 */  jr         $k0
    /* 2E80 00202280 00000000 */   nop
    /* 2E84 00202284 00000000 */  nop
    /* 2E88 00202288 00000000 */  nop
  .Lauto_0020228C:
    /* 2E8C 0020228C 00000000 */  nop
    /* 2E90 00202290 00000000 */  nop
    /* 2E94 00202294 00000000 */  nop
    /* 2E98 00202298 3C1A8000 */  lui        $k0, (0x80000194 >> 16) /* handwritten instruction */
    /* 2E9C 0020229C 375A0194 */  ori        $k0, $k0, (0x80000194 & 0xFFFF) /* handwritten instruction */
    /* 2EA0 002022A0 03400008 */  jr         $k0
    /* 2EA4 002022A4 00000000 */   nop
  alabel D_auto_002022A8
    /* 2EA8 002022A8 409AF000 */  mtc0       $k0, $30 /* handwritten instruction */
    /* 2EAC 002022AC 3C1A0020 */  lui        $k0, %hi(D_auto_00202460) /* handwritten instruction */
    /* 2EB0 002022B0 275A2460 */  addiu      $k0, $k0, %lo(D_auto_00202460) /* handwritten instruction */
    /* 2EB4 002022B4 03400008 */  jr         $k0
    /* 2EB8 002022B8 00000000 */   nop
  alabel D_auto_002022BC
    /* 2EBC 002022BC 00000000 */  nop
    /* 2EC0 002022C0 00000000 */  nop
    /* 2EC4 002022C4 00000000 */  nop
    /* 2EC8 002022C8 00000000 */  nop
    /* 2ECC 002022CC 00000000 */  nop
    /* 2ED0 002022D0 3C1A8000 */  lui        $k0, (0x80000014 >> 16) /* handwritten instruction */
    /* 2ED4 002022D4 375A0014 */  ori        $k0, $k0, (0x80000014 & 0xFFFF) /* handwritten instruction */
    /* 2ED8 002022D8 03400008 */  jr         $k0
    /* 2EDC 002022DC 00000000 */   nop
endlabel func_auto_00202268
