/* Generated public compiler provider. */
#ifndef UNBAKE_PUBLIC_STDARG_H
#define UNBAKE_PUBLIC_STDARG_H
#include <common/unused.h>
#if defined(__UNBAKE_STDARG_GCC)
typedef char __unbake_stdarg_target[
    sizeof(int) == 4 && sizeof(long) == 4 && sizeof(long long) == 8 &&
    sizeof(double) == 8 && sizeof(void *) == 4 && sizeof(va_list) == 4 ? 1 : -1];
extern void *__builtin_next_arg();
#define va_start(ap, last) ((ap) = (va_list)__builtin_next_arg(last))
#define __unbake_va_alignment(type) (sizeof(struct { char pad; type item; }) - sizeof(type))
#ifdef __STRICT_ANSI__
#define __unbake_stdarg_inline
#else
#define __unbake_stdarg_inline inline
#endif
static __unbake_stdarg_inline char *__unbake_stdarg_take(va_list *ap, unsigned int size,
                                                     unsigned int alignment)
{
    char *slot = (char *)(((unsigned int)*ap + alignment - 1) & -alignment);
    *ap = slot + ((size + 3) & -4);
    return slot;
}
/* Keep the expression sequencing boundary of historical GNU va_arg expansion.
 * Inlining a C helper is ABI-equivalent but can reorder an enclosing assignment. */
#ifdef __STRICT_ANSI__
#define va_arg(ap, type) (*(type *)__unbake_stdarg_take(&(ap), sizeof(type), \
                         __unbake_va_alignment(type) > 4 ? 8 : 4))
#else
#define va_arg(ap, type) ({ \
    va_list *__unbake_cursor = &(ap); \
    char *__unbake_slot = (char *)(((unsigned int)*__unbake_cursor + \
        (__unbake_va_alignment(type) > 4 ? 8 : 4) - 1) & \
        -(__unbake_va_alignment(type) > 4 ? 8 : 4)); \
    *__unbake_cursor = __unbake_slot + ((sizeof(type) + 3) & -4); \
    *(type *)__unbake_slot; })
#endif
#define va_end(ap) ((void)(ap))
#define va_copy(dst, src) ((dst) = (src))

#elif defined(__UNBAKE_STDARG_IDO)
typedef char __unbake_stdarg_target[
    sizeof(int) == 4 && sizeof(long) == 4 && sizeof(long long) == 8 &&
    sizeof(double) == 8 && sizeof(void *) == 4 && sizeof(va_list) == 4 ? 1 : -1];
#define va_start(ap, last) ((ap) = (va_list)((char *)&(last) + sizeof(last)))
/* The native compiler tags saved FP argument cursors. The host token provider
 * parses equivalent type expressions without sending its builtins to cfe. */
#ifdef __UNBAKE_HEADER_ANALYSIS
#define __unbake_va_align(type) (sizeof(type) > 4 ? 8 : 4)
#define __unbake_va_fp(type) (__builtin_classify_type(*(type *)0) == 8)
#else
#define __unbake_va_align(type) __builtin_alignof(*(type *)0)
#define __unbake_va_fp(type) (__builtin_classof(*(type *)0) == 1)
#endif
static char *__unbake_stdarg_take(va_list *ap, unsigned int size,
                                 unsigned int alignment, int floating)
{
    unsigned int cursor = (unsigned int)*ap;
    unsigned int next;
    char *slot;
    if (floating && alignment == 8 && (cursor & 1)) {
        next = cursor + 7;
        slot = (char *)(next - 6 - 16 - size);
    } else if (floating && alignment == 8 && (cursor & 2)) {
        next = cursor + 10;
        slot = (char *)(next - 24 - 16 - size);
    } else {
        if (alignment < 4) alignment = 4;
        slot = (char *)((cursor + alignment - 1) & -alignment);
        next = (unsigned int)slot + ((size + 3) & -4);
    }
    *ap = (char *)next;
    return slot;
}
#define va_arg(ap, type) (*(type *)__unbake_stdarg_take(&(ap), sizeof(type), \
                         __unbake_va_align(type), __unbake_va_fp(type)))
#define va_end(ap) ((void)(ap))
#define va_copy(dst, src) ((dst) = (src))

#else
#error "compiler public-header selector is missing"
#endif
#endif
