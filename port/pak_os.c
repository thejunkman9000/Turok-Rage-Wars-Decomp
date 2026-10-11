/* libultra controller-pak functions that have no usable code in the port, written against the virtual SI/PIF of port/pak.c.
 *
 * The game's ROM contains the complete libultra Controller Pak stack.  Almost all of it runs unmodified in the port (the statically recompiled
 * or ported-C versions of osPfsInitPak, osPfsChecker, osPfsAllocateFile, __osCheckPackId, __osPfsRWInode, ...).  These pieces could not:
 *   __osContRamRead / __osContRamWrite / __osContGetInitData : the MIPS code copies 40-byte structures with lwl/lwr/swl/swr, which the
 *                  recompiler does not translate (they were UNIMPLEMENTED stubs in port/gen/stubs.c);
 *   osMotorInit / osMotorStart / osMotorStop : only host shims existed (they reported "no rumble pak" for every port);
 *   osPfsInitPak / osPfsIsPlug : "always absent" overrides.  osPfsInitPak now simply runs the game's own recompiled osPfsInitPak (func_00447BB0);
 *                  osPfsIsPlug is not referenced by the game, it is the standard libultra routine for completeness.
 * Each function below is a line-by-line transliteration of the ROM code (disassembled from the cartridge: VA 0x2BD590, 0x2BD950, 0x2BCBA8,
 * 0x2BD0A8, 0x2BCEE4, 0x2BCD20), using the same buffers (__osPfsPifRam, __osMotorStartData, ...) at their original addresses, so the
 * game's other code (which reads those buffers) sees exactly what it would on a console.  Multi-byte guest fields are big-endian. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <intrin.h>
#include "os_types.h"

extern void pak_si_dma(int dir, void *ram);
extern unsigned char pak_crc5(unsigned blk);
extern unsigned char pak_crc8(const unsigned char *d);
extern s32 osRecvMesg(OSMesgQueue *mq, OSMesg *m, s32 flags);          /* os_shim.c */
extern s32 __osSiRawStartDma(s32 dir, void *pif_ram);                  /* os_shim.c -> pak_si_dma */
extern void __osSiGetAccess(void);                                     /* game code (lu_siacs) */
extern void __osSiRelAccess(void);
extern s32 __osPfsGetStatus(OSMesgQueue *queue, int channel);          /* game code (ov___osPfsGetStatus) */
extern u32 func_00447BB0(u32 queue, u32 pfs, u32 channel, u32 a3);     /* the game's own osPfsInitPak (recompiled from the ROM) */

#ifdef PAK_STANDALONE_TEST
#define XLP(p) ((unsigned char *)(size_t)(p))             /* the self test has no translated low guest space (its stack lives there) */
#else
#define XLP(p) ((unsigned char *)(size_t)((((unsigned)(size_t)(p)) - 0x200000u) < 0x1E00000u ? (unsigned)(size_t)(p) + 0x30000000u : (unsigned)(size_t)(p)))
#endif
static u32 be32(const volatile void *p) { return _byteswap_ulong(*(const volatile unsigned long *)p); }
static void st32(volatile void *p, u32 v) { *(volatile unsigned long *)p = _byteswap_ulong(v); }

/* original addresses of the libultra data this code works on (guest address == host address) */
#define G_PFS_PIF       ((volatile unsigned char *)0x80154110u)       /* __osPfsPifRam: 15 words + pif status word */
#define G_CONT_NUM      (*(volatile unsigned char *)0x8014D46Cu)      /* __osContNumControllers */
#define G_CONT_PIF      ((volatile unsigned char *)0x8014D470u)       /* __osContPifRam */
#define G_LAST_CMD      (*(volatile unsigned char *)0x8014D4B0u)      /* __osContLastCmd */
#define G_MSTART_DATA(c) ((volatile unsigned char *)(0x8014D4C0u + (unsigned)(c) * 64u))   /* __osMotorStartData[4] */
#define G_MSTART_BUF    ((volatile unsigned char *)0x8014D5C0u)       /* __osMotorStartBuf[32] */
#define G_MSTOP_DATA(c) ((volatile unsigned char *)(0x8014D5E0u + (unsigned)(c) * 64u))   /* __osMotorStopData[4] */
#define G_MSTOP_BUF     ((volatile unsigned char *)0x8014D6E0u)       /* __osMotorStopBuf[32] */
#define G_MOTOR_INIT(c) ((volatile unsigned char *)(0x800D8380u + (unsigned)(c) * 4u))    /* __osMotorinitialized[4] (big-endian words) */

/* __osPackRamReadData / __osPackRamWriteData / the body of _MakeMotorData: the channel's skip bytes, the 40-byte read/write format
 * {0xFF, txsize, rxsize, cmd, address(2), data[32], crc 0xFF, pad} and the 0xFE terminator.  `clear`: zero the 15 words first (motor blocks). */
static void pack_ram(volatile unsigned char *pif, int clear, int write, int channel, unsigned address, const volatile unsigned char *data) {
    unsigned char pkt[40]; volatile unsigned char *ptr; unsigned a16, i;
    if (clear) for (i = 0; i < 60; i++) pif[i] = 0;
    st32(pif + 60, 1);                                               /* pif status = run the command list */
    address &= 0xFFFF; a16 = ((address << 5) | pak_crc5(address)) & 0xFFFF;
    pkt[0] = 0xFF; pkt[1] = write ? 0x23 : 0x03; pkt[2] = write ? 0x01 : 0x21; pkt[3] = write ? 3 : 2;
    pkt[4] = (unsigned char)(a16 >> 8); pkt[5] = (unsigned char)a16;
    for (i = 0; i < 32; i++) pkt[6 + i] = write ? data[i] : 0xFF;
    pkt[38] = 0xFF; pkt[39] = 0;
    ptr = pif; for (i = 0; i < (unsigned)channel; i++) *ptr++ = 0;
    for (i = 0; i < 40; i++) ptr[i] = pkt[i];
    ptr[40] = 0xFE;
}

s32 __osContRamRead(OSMesgQueue *mq, int channel, unsigned address, u8 *buffer) {
    s32 ret; int retry = 2; unsigned char pkt[40]; unsigned i;
    buffer = XLP(buffer);
    if (channel < 0 || channel > 3) return 5;
    __osSiGetAccess();
    G_LAST_CMD = 2;
    pack_ram(G_PFS_PIF, 0, 0, channel, address, NULL);
    __osSiRawStartDma(1, (void *)G_PFS_PIF); osRecvMesg(mq, NULL, 1);
    do {
        __osSiRawStartDma(0, (void *)G_PFS_PIF); osRecvMesg(mq, NULL, 1);
        for (i = 0; i < 40; i++) pkt[i] = G_PFS_PIF[(unsigned)channel + i];
        ret = (pkt[2] & 0xC0) >> 4;                                  /* rx byte error flags: 8 = no device, 4 = timeout */
        if (ret == 0) {
            if (pak_crc8(pkt + 6) != pkt[0x26]) {                    /* data CRC mismatch: ask the controller what happened */
                ret = __osPfsGetStatus(mq, channel);
                if (ret == 0) ret = 4;                               /* nothing wrong with the pak itself: retry */
            } else {
                for (i = 0; i < 32; i++) buffer[i] = pkt[6 + i];
            }
        } else ret = 1;                                              /* PFS_ERR_NOPACK */
    } while (ret == 4 && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}

s32 __osContRamWrite(OSMesgQueue *mq, int channel, unsigned address, u8 *buffer, int force) {
    s32 ret; int retry = 2; unsigned char pkt[40]; unsigned i;
    buffer = XLP(buffer); address &= 0xFFFF;
    if (force != 1 && address < 7 && address != 0) return 0;         /* the id area (blocks 1-6) is protected unless forced */
    if (channel < 0 || channel > 3) return 5;
    __osSiGetAccess();
    G_LAST_CMD = 3;
    pack_ram(G_PFS_PIF, 0, 1, channel, address, buffer);
    __osSiRawStartDma(1, (void *)G_PFS_PIF); osRecvMesg(mq, NULL, 1);
    do {
        __osSiRawStartDma(0, (void *)G_PFS_PIF); osRecvMesg(mq, NULL, 1);
        for (i = 0; i < 40; i++) pkt[i] = G_PFS_PIF[(unsigned)channel + i];
        ret = (pkt[2] & 0xC0) >> 4;
        if (ret == 0) {
            if (pak_crc8(buffer) != pkt[0x26]) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret == 0) ret = 4;
            }
        } else ret = 1;
    } while (ret == 4 && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}

/* decodes the four request-status blocks the last transfer left in __osContPifRam into pattern[bit per answering controller] / data[4] */
void __osContGetInitData(u8 *pattern, OSContStatus *data) {
    unsigned char *d = XLP(data), bits = 0; int i;
    pattern = XLP(pattern);
    for (i = 0; i < (int)G_CONT_NUM && i < 4; i++) {
        unsigned char b[8]; int k;
        for (k = 0; k < 8; k++) b[k] = G_CONT_PIF[i * 8 + k];
        d[i * 4 + 3] = (unsigned char)((b[2] & 0xC0) >> 4);                      /* errno */
        if (d[i * 4 + 3] == 0) {
            d[i * 4 + 0] = b[5]; d[i * 4 + 1] = b[4];                             /* type = typel << 8 | typeh, stored big-endian */
            d[i * 4 + 2] = b[6];                                                 /* status */
            bits |= (unsigned char)(1u << i);
        }
    }
    *pattern = bits;
}

/* rumble pak -------------------------------------------------------------------------------------------------------------------------- */
static void make_motor_data(int channel, unsigned address, volatile unsigned char *buf, volatile unsigned char *mdata) { pack_ram(mdata, 1, 1, channel, address, buf); }

s32 pak_motor_init(OSMesgQueue *mq, void *pfs_, int channel) {
    unsigned char *pfs = XLP(pfs_); unsigned char temp[32]; s32 ret; int i;
    st32(pfs + 0x04, (u32)(size_t)mq); st32(pfs + 0x08, (u32)channel); st32(pfs + 0x00, 0); pfs[0x65] = 0x80;       /* pfs->queue, channel, status = 0, activebank = 0x80 */
    if (channel < 0 || channel > 3) return 5;
    memset(temp, 0xFE, 32);                                         /* 0xFE into the detection register: a rumble pak locks, a memory pak ignores it */
    ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret == 2) ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret != 0) return ret;
    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == 2) ret = 4;
    if (ret != 0) return ret;
    if (temp[31] == 0xFE) return 11;                                 /* echoes: some other device */
    memset(temp, 0x80, 32);                                         /* 0x80 unlocks a rumble pak */
    ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret == 2) ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret != 0) return ret;
    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == 2) ret = 4;
    if (ret != 0) return ret;
    if (temp[31] != 0x80) return 11;                                 /* PFS_ERR_DEVICE: not a rumble pak */
    if (!be32(G_MOTOR_INIT(channel))) {
        for (i = 0; i < 32; i++) { G_MSTART_BUF[i] = 1; G_MSTOP_BUF[i] = 0; }
        make_motor_data(channel, 0x600, G_MSTART_BUF, G_MSTART_DATA(channel));
        make_motor_data(channel, 0x600, G_MSTOP_BUF, G_MSTOP_DATA(channel));
        st32(G_MOTOR_INIT(channel), 1);
    }
    return 0;
}
static s32 motor_cmd(void *pfs_, int start) {
    unsigned char *pfs = XLP(pfs_); int channel = (int)be32(pfs + 0x08); OSMesgQueue *mq = (OSMesgQueue *)(size_t)be32(pfs + 0x04);
    unsigned char pkt[40]; s32 ret; unsigned i;
    if (channel < 0 || channel > 3 || !be32(G_MOTOR_INIT(channel))) return 5;                   /* PFS_ERR_INVALID: osMotorInit has not succeeded */
    __osSiGetAccess();
    G_LAST_CMD = 3;
    __osSiRawStartDma(1, (void *)(start ? G_MSTART_DATA(channel) : G_MSTOP_DATA(channel))); osRecvMesg(mq, NULL, 1);
    __osSiRawStartDma(0, (void *)G_PFS_PIF); osRecvMesg(mq, NULL, 1);
    for (i = 0; i < 40; i++) pkt[i] = G_PFS_PIF[(unsigned)channel + i];
    ret = (pkt[2] & 0xC0) >> 4;
    if (ret == 0) {
        unsigned char buf[32]; for (i = 0; i < 32; i++) buf[i] = (start ? G_MSTART_BUF : G_MSTOP_BUF)[i];
        if (pak_crc8(buf) != pkt[0x26]) ret = 4;                     /* the controller returns the CRC of what it received */
    }
    __osSiRelAccess();
    return ret;
}
s32 pak_motor_start(void *pfs) { return motor_cmd(pfs, 1); }
s32 pak_motor_stop(void *pfs) { return motor_cmd(pfs, 0); }

/* osPfsInitPak: the game's own code (ROM 0x447BB0, recompiled) runs against the virtual device.
 * Guard: when a later regeneration replaces the recompiled twin by matched C, func_00447BB0 becomes an alias of the C function named osPfsInitPak - which this
 * definition shadows - and the call below would recurse forever.  pak_os_init() detects that (g_initpak_alias) and the pak then reports "no pak" instead; the fix
 * is to delete this function (and port/overrides/osPfsInitPak.c) so that the real one is linked. */
static int g_initpak_alias;
s32 osPfsInitPak(OSMesgQueue *queue, void *pfs, int channel) { if (g_initpak_alias) return 1; return (s32)func_00447BB0((u32)(size_t)queue, (u32)(size_t)pfs, (u32)channel, 0); }

/* osPfsIsPlug: which ports have a pak (the standard libultra routine; the game does not call it) */
s32 pak_pfs_isplug(OSMesgQueue *queue, u8 *pattern) {
    unsigned char bits = 0; int tries, ch; s32 ret = 0;
    pattern = XLP(pattern);
    __osSiGetAccess();
    for (tries = 0; tries < 3; tries++) {
        int crc_err = 0; unsigned i;
        G_LAST_CMD = 0;
        for (i = 0; i < 60; i++) G_PFS_PIF[i] = 0;
        st32((volatile void *)(G_PFS_PIF + 60), 1);
        for (ch = 0; ch < 4; ch++) { volatile unsigned char *b = G_PFS_PIF + ch * 8; b[0] = 0xFF; b[1] = 1; b[2] = 3; b[3] = 0; b[4] = 0xFF; b[5] = 0xFF; b[6] = 0xFF; b[7] = 0xFF; }
        G_PFS_PIF[32] = 0xFE;
        __osSiRawStartDma(1, (void *)G_PFS_PIF); osRecvMesg(queue, NULL, 1);
        __osSiRawStartDma(0, (void *)G_PFS_PIF); osRecvMesg(queue, NULL, 1);
        bits = 0;
        for (ch = 0; ch < 4; ch++) {
            volatile unsigned char *b = G_PFS_PIF + ch * 8;
            if (((b[2] & 0xC0) >> 4) == 0) { if (b[6] & 1) bits |= (unsigned char)(1u << ch); if (b[6] & 4) crc_err = 1; }
        }
        if (!crc_err) break;
    }
    *pattern = bits;
    __osSiRelAccess();
    return ret;
}


/* osPfsChecker's helper corrupted(pfs, fpage, cache) takes the page link `fpage` (__OSInodeUnit, a 2-byte union) BY VALUE, so caller and callee must use the
 * same convention.  Until 2026-10-11 the checker was the recompiled twin (MIPS o32: the halfword in the high 16 bits of a register image) and this file served
 * `corrupted` from the recompiled twin too.  osPfsChecker is matched C now and the recompiled osPfsInitPak calls it, so the matched C corrupted()
 * (src/ovl_a/corrupted.c, x86 struct image) is the right partner: a wrapper here made the C checker read page 0 / bank 0 for every link and delete
 * every note (the player the game had just created, foreign notes).  Do not define corrupted here again. */

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern) { return pak_pfs_isplug(queue, pattern); }

/* the ROM's own names for the same code, for code pointers / tables that refer to the entries by address */
u32 func_002BCBA8(u32 a0, u32 a1) { __osContGetInitData((u8 *)(size_t)a0, (OSContStatus *)(size_t)a1); return 0; }
u32 func_002BD590(u32 a0, u32 a1, u32 a2, u32 a3) { return (u32)__osContRamRead((OSMesgQueue *)(size_t)a0, (int)a1, a2, (u8 *)(size_t)a3); }
u32 func_002BD950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) { return (u32)__osContRamWrite((OSMesgQueue *)(size_t)a0, (int)a1, a2, (u8 *)(size_t)a3, (int)a4); }

#ifndef PAK_STANDALONE_TEST
/* ---------------------------------------------------------------------------------------------------------------------------------------
 * Diagnostic: TUROK_PAKTWIN=all | name,name,...  redirects ported-C pak library functions to the statically recompiled MIPS twin of the same ROM function
 * (patches a JMP over the C function's first bytes at start-up).  Used to find out which of the C versions misbehave on x86. */
extern int corrupted_init(); extern int osPfsDeleteFile(); extern int osPfsFindFile(); extern int __osPfsDeclearPage(); extern int __osClearPage();
extern int __osPfsReleasePages(); extern int __osBlockSum(); extern int __osPfsGetStatus(); extern int __osPfsSelectBank(); extern int __osCheckId(); extern int __osGetId();
extern int func_004481BC(); extern int func_004471D0(); extern int func_00448D30(); extern int func_00446F74(); extern int func_00447140();
extern int func_004473FC(); extern int func_0044759C(); extern int func_004479D0(); extern int func_00449914(); extern int func_0044984C(); extern int func_00449308();
static void patch_jmp(void *from, void *to) {
    DWORD old; unsigned char *p = (unsigned char *)from;
    if (!VirtualProtect(p, 8, PAGE_EXECUTE_READWRITE, &old)) return;
    p[0] = 0xE9; *(int *)(p + 1) = (int)((unsigned char *)to - (p + 5));
    VirtualProtect(p, 8, old, &old); FlushInstructionCache(GetCurrentProcess(), p, 8);
}
void pak_os_init(void) {
    static const struct { const char *name; void *c, *twin; } t[] = {
        { "corrupted_init", (void *)corrupted_init, (void *)func_004481BC },
        { "osPfsDeleteFile", (void *)osPfsDeleteFile, (void *)func_004471D0 }, { "osPfsFindFile", (void *)osPfsFindFile, (void *)func_00448D30 },
        { "__osPfsDeclearPage", (void *)__osPfsDeclearPage, (void *)func_00446F74 }, { "__osClearPage", (void *)__osClearPage, (void *)func_00447140 },
        { "__osPfsReleasePages", (void *)__osPfsReleasePages, (void *)func_004473FC }, { "__osBlockSum", (void *)__osBlockSum, (void *)func_0044759C },
        { "__osPfsGetStatus", (void *)__osPfsGetStatus, (void *)func_004479D0 }, { "__osPfsSelectBank", (void *)__osPfsSelectBank, (void *)func_00449914 },
    };
    char e[512]; unsigned i;
    if ((void *)func_00447BB0 == (void *)osPfsInitPak) { g_initpak_alias = 1; fprintf(stderr, "pak: WARNING: func_00447BB0 is an alias of pak_os.c's osPfsInitPak (the recompiled twin is gone): no pak until osPfsInitPak is removed from port/pak_os.c\n"); }
    if (!GetEnvironmentVariableA("TUROK_PAKTWIN", e, sizeof e)) return;
    for (i = 0; i < sizeof t / sizeof t[0]; i++) {
        char key[80]; _snprintf(key, sizeof key, ",%s,", t[i].name);
        { char list[520]; _snprintf(list, sizeof list, ",%s,", e);
          if (!strcmp(e, "all") || strstr(list, key)) { patch_jmp(t[i].c, t[i].twin); fprintf(stderr, "pak: %s -> recompiled ROM twin\n", t[i].name); } }
    }
}
#endif
