/* Original SDK mbi.h shift builders, adapted for the project GBI interface.
 * Source: https://ultra64.ca/files/documentation/online-manuals/man/header/mbi.htm
 * These builders mask the input before shifting. Include after gbi.h when
 * reproducing its original SDK expression types under the SN64 compiler.
 * The SDK explicitly excludes a width of 32 for these builders.
 */
#ifndef RAGEWARS_SDK_MBI_H
#define RAGEWARS_SDK_MBI_H
#undef _SHIFTL
#define _SHIFTL(v, s, w) \
    ((unsigned int) (((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#endif
