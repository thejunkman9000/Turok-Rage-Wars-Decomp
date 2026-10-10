/* Open reconstruction of the standard 16-command Nintendo 64 audio ABI.
 * Encoding reference (decoder, not SDK header):
 * https://github.com/mupen64plus/mupen64plus-rsp-hle/blob/8a7a472a7172eb2c8725b305eae26818ed7b51a2/src/alist_audio.c
 * Independently written C89 builders; no Nintendo SDK macro text is vendored.
 * The flag field of aSetVolume intentionally masks 16 bits before shifting,
 * matching the legacy builder contract, including bits that overlap the opcode.
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 AbuCakeUnbake64 contributors
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to inclusion of this notice. THE SOFTWARE IS PROVIDED "AS IS",
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL THE AUTHORS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY ARISING FROM THE SOFTWARE.
 * Include the project's canonical Acmd type before expanding these builders.
 */
#ifndef UNBAKE_ABI_H
#define UNBAKE_ABI_H
#ifndef _SHIFTL
#define _SHIFTL(v, s, w) (((unsigned int)(v) & (0xFFFFFFFFU >> (32 - (w)))) << (s))
#endif

#define aADPCMdec(pkt, f, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(1,24,8) | _SHIFTL(f,16,8); _a->words.w1 = (unsigned int)(s); }
#define aClearBuffer(pkt, d, c) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(2,24,8) | _SHIFTL(d,0,24); _a->words.w1 = (unsigned int)(c); }
#define aEnvMixer(pkt, f, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(3,24,8) | _SHIFTL(f,16,8); _a->words.w1 = (unsigned int)(s); }
#define aLoadBuffer(pkt, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(4,24,8); _a->words.w1 = (unsigned int)(s); }
#define aResample(pkt, f, p, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(5,24,8) | _SHIFTL(f,16,8) | _SHIFTL(p,0,16); _a->words.w1 = (unsigned int)(s); }
#define aSaveBuffer(pkt, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(6,24,8); _a->words.w1 = (unsigned int)(s); }
#define aSegment(pkt, seg, base) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(7,24,8); _a->words.w1 = _SHIFTL(seg,24,8) | _SHIFTL(base,0,24); }
#define aSetBuffer(pkt, f, i, o, c) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(8,24,8) | _SHIFTL(f,16,8) | _SHIFTL(i,0,16); \
    _a->words.w1 = _SHIFTL(o,16,16) | _SHIFTL(c,0,16); }
#define aSetVolume(pkt, f, v, t, r) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(9,24,8) | _SHIFTL(f,16,16) | _SHIFTL(v,0,16); \
    _a->words.w1 = _SHIFTL(t,16,16) | _SHIFTL(r,0,16); }
#define aDMEMMove(pkt, i, o, c) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(10,24,8) | _SHIFTL(i,0,24); \
    _a->words.w1 = _SHIFTL(o,16,16) | _SHIFTL(c,0,16); }
#define aLoadADPCM(pkt, c, d) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(11,24,8) | _SHIFTL(c,0,24); _a->words.w1 = (unsigned int)(d); }
#define aMix(pkt, f, g, i, o) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(12,24,8) | _SHIFTL(f,16,8) | _SHIFTL(g,0,16); \
    _a->words.w1 = _SHIFTL(i,16,16) | _SHIFTL(o,0,16); }
#define aInterleave(pkt, l, r) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(13,24,8); _a->words.w1 = _SHIFTL(l,16,16) | _SHIFTL(r,0,16); }
#define aPoleFilter(pkt, f, g, s) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(14,24,8) | _SHIFTL(f,16,8) | _SHIFTL(g,0,16); _a->words.w1 = (unsigned int)(s); }
#define aSetLoop(pkt, a) { Acmd *_a = (Acmd *)(pkt); \
    _a->words.w0 = _SHIFTL(15,24,8); _a->words.w1 = (unsigned int)(a); }
#endif
