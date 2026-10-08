/* Force-included when the game C is compiled with clang (LLVM IR path with big-endian memory access). */
#ifndef PORT_COMPAT_CLANG_H
#define PORT_COMPAT_CLANG_H
#define M2CTX 1               /* skips INCLUDE_ASM macros */

/* GCC's __builtin_next_arg(last): address just after the last named parameter (x86 cdecl varargs live on the host stack) */
#define __builtin_next_arg(x) ((char *)&(x) + sizeof(x))

/* Every 16/32/64-bit load in the game is byte-swapped by port/be_ir.py, but variadic arguments are pushed by native code,
   so they are read byte-reversed into the temporary: the swapped load then restores the native value.  No alignment padding
   on x86. */
#define va_arg(ap, type) \
    ({ volatile type __va_v; unsigned __va_i; \
       for (__va_i = 0; __va_i < sizeof(type); __va_i++) ((volatile char *)&__va_v)[__va_i] = ((char *)(ap))[sizeof(type) - 1 - __va_i]; \
       (ap) = (void *)((char *)(ap) + sizeof(type)); __va_v; })
#endif

/* printf-style functions (matching C) read their variadic arguments through __builtin_next_arg: hand the recompiled vsprintf a block of big-endian-memory-format words instead of the raw x86 argument slots */
extern char *port_vararg_block(void *pva);
#define __builtin_next_arg(x) ({ __builtin_va_list va_blk_; __builtin_va_start(va_blk_, x); port_vararg_block((void *)&va_blk_); })
