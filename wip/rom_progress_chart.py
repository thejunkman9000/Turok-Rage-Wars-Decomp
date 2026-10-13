import json, matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
d = json.load(open('wip/rom_progress.json'))
SURF, INK, INK2, GRID = '#fcfcfb', '#0b0b0b', '#52514e', '#e4e3de'
cats = [('shared', 'Matched C shared with US v1.1', '#2a78d6'),
        ('spec', 'Release-specific matched C', '#eb6834'),
        ('hand', 'Hand-written asm + linker padding', '#1baf7a'),
        ('asm', 'Hand-written / library asm, as in v1.1 (not C)', '#e0b13a'),
        ('rest', 'Still assembly (to match)', '#d9d8d2')]
plt.rcParams.update({'font.family': 'Segoe UI', 'font.size': 11})
fig, ax = plt.subplots(figsize=(11, 4.6), dpi=150)
fig.patch.set_facecolor(SURF); ax.set_facecolor(SURF)
rows = d[::-1]
for i, r in enumerate(rows):
    left = 0
    for key, _, col in cats:
        w = 100 * r.get(key, 0) / r['total']
        if w > 0:
            ax.barh(i, w, left=left, height=0.56, color=col, edgecolor=SURF, linewidth=2)
        left += w
    done = 100 * (r['shared'] + r['spec'] + r['hand'] + r.get('asm', 0)) / r['total']
    ax.text(101.2, i, f"{done:.1f}%", va='center', ha='left', fontsize=12, fontweight='bold', color=INK)
    ax.text(101.2, i - 0.33, f"{(r['rest']):,} insns left", va='center', ha='left', fontsize=9, color=INK2)
ax.set_yticks(range(len(rows))); ax.set_yticklabels([r['rom'] for r in rows], fontsize=12, color=INK)
ax.set_xlim(0, 100); ax.set_xticks([0, 25, 50, 75, 100]); ax.set_xticklabels(['0%', '25%', '50%', '75%', '100%'], color=INK2)
ax.xaxis.grid(True, color=GRID, linewidth=0.8); ax.set_axisbelow(True)
for s in ax.spines.values(): s.set_visible(False)
ax.tick_params(length=0)
handles = [plt.Rectangle((0, 0), 1, 1, color=c) for _, _, c in cats]
ax.legend(handles, [l for _, l, _ in cats], loc='upper center', bbox_to_anchor=(0.5, 1.2), ncol=3, frameon=False, fontsize=10, labelcolor=INK)
fig.suptitle('Turok: Rage Wars decompilation: game code built from matched C, per ROM', x=0.02, ha='left', y=1.02, fontsize=14, fontweight='bold', color=INK)
fig.text(0.02, -0.04, 'Share of each ROM\'s code (main image + overlay A, by instructions). All four ROMs rebuild byte-identical; code not yet matched is built from assembly.\n'
         'In the other releases the v1.1 hand-written .s units are not reused yet, so that code still counts as "to match".', fontsize=9, color=INK2, ha='left')
plt.subplots_adjust(left=0.1, right=0.87, top=0.8, bottom=0.12)
plt.savefig('wip/rom_progress.png', bbox_inches='tight', facecolor=SURF)
