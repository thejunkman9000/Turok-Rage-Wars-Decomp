/* Force-included (/FI) in every game translation unit of the Windows port: hides GCC-only syntax. */
#ifndef PORT_COMPAT_H
#define PORT_COMPAT_H
#ifdef _MSC_VER
#define M2CTX 1               /* skips the INCLUDE_ASM macros */
#define __asm__(...)          /* asm labels / pins used by the matching build */
#define asm(...)
#define __inline__ inline
#define __attribute__(x)
#define __volatile__ volatile
#define __builtin_next_arg(x) ((char *)&(x) + sizeof(x))   /* o32 varargs helper used by the game's printf wrappers */
#endif
#endif
