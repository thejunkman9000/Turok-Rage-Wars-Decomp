/* Undefined-behaviour reports of the unoptimised game C.
 *
 * zig cc instruments -O0 code with UBSan (build_clang.py compiles the mode=sn sources, which carry MIPS-code-generator hacks, at -O0).
 * Every check calls __ubsan_handle_<kind>(data, ...); data starts with the source location of the check.  Matching C is full of constructs
 * that are only defined on the MIPS target (shifts by >= 32, float -> int conversions out of range - cvttss2si returns INT_MIN where
 * trunc.w.s saturates -, loads through NULL or misaligned pointers); each distinct location is logged once in port/build/run.log as
 *   UBSAN <kind> <file>:<line>:<col>
 * (the file is the preprocessed copy in port/build/ll/ - same line numbers as the source).  They are leads for port bugs, not errors. */
#include <stdio.h>
#include <string.h>

typedef struct { const char *file; unsigned line, col; } ub_loc;
static void ub_report(const char *kind, const void *data, unsigned a, unsigned b) {
    static struct { const char *file; unsigned line, col; const char *kind; } seen[1024]; static int n, total;
    const ub_loc *l = (const ub_loc *)data; int i;
    if (!l || !l->file) return;
    for (i = 0; i < n; i++) if (seen[i].line == l->line && seen[i].col == l->col && !strcmp(seen[i].file, l->file) && seen[i].kind == kind) return;
    if (n < 1024) { seen[n].file = l->file; seen[n].line = l->line; seen[n].col = l->col; seen[n].kind = kind; n++; }
    if (++total <= 400) { fprintf(stderr, "UBSAN %s %s:%u:%u (%08X %08X)\n", kind, l->file, l->line, l->col, a, b); fflush(stderr); }
}
#define UBH(name) void __ubsan_handle_##name(void *d, unsigned a, unsigned b) { ub_report(#name, d, a, b); }
UBH(add_overflow) UBH(sub_overflow) UBH(mul_overflow) UBH(negate_overflow) UBH(divrem_overflow) UBH(shift_out_of_bounds)
UBH(out_of_bounds) UBH(type_mismatch_v1) UBH(float_cast_overflow) UBH(load_invalid_value) UBH(nonnull_arg) UBH(nullability_arg)
UBH(nonnull_return_v1) UBH(nullability_return_v1) UBH(pointer_overflow) UBH(invalid_builtin) UBH(missing_return)
UBH(vla_bound_not_positive) UBH(builtin_unreachable) UBH(alignment_assumption) UBH(implicit_conversion) UBH(function_type_mismatch)
UBH(function_type_mismatch_v1)
