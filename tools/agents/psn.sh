#!/usr/bin/env bash
# psn.sh <fn> <file.c rel to ~/trw_s703 e.g. wip/c/x.c> [xflags] : set up permuter dir ~/perm/s703_<fn> for @SN
fn=$1; cf=$2; xf=${3:-}
R=$HOME/trw_s703; d=$HOME/perm/s703_$fn
rm -rf "$d"; mkdir -p "$d"; cd "$R"
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their "$cf" > "$d/pre.c"
python3 tools/perm_strip.py "$d/pre.c" "$fn" | grep -v "^__asm__" > "$d/base.c"
python3 - "$fn" > "$d/target.s" <<'PY'
import sys,glob,re
fn=sys.argv[1]
print('.include "macro.inc"\n.set noat\n.set noreorder\n.set gp=64\n.section .text, "ax"\n')
for p in sorted(glob.glob('/mnt/d/Projects/ws/s703/asm/*.s')):
    on=False
    for l in open(p,encoding='utf-8'):
        if l.startswith('glabel '+fn+' ') or l.strip()=='glabel '+fn: on=True
        if on:
            if l.startswith('endlabel'):
                print(l.rstrip()); sys.exit(0)
            print(l.rstrip())
PY
bash tools/as.sh "$d/target.s" "$d/target.o"
cat > "$d/compile.sh" <<EOF
#!/usr/bin/env bash
export PERM_XF="$xf"
exec bash $R/tools/permcc_sn.sh "\$@"
EOF
chmod +x "$d/compile.sh"
printf 'compiler_type = "gcc"\nfunc_name = "%s"\n' "$fn" > "$d/settings.toml"
"$d/compile.sh" "$d/base.c" -o "$d/base.o" && echo "base compiles: $d"
