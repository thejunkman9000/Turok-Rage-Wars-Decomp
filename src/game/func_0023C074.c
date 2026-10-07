#include "b09_types.h"

extern B09SlotA D_80103F28[];
extern u8 D_80156000[];
void osMapTLB(s32 index, s32 pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);
void osUnmapTLB(s32 index);

void func_0023C074(B09LNode *n) {
    if (n->tlb != 0xFF) {
        if (n->slot & 1) {
            D_80103F28[n->tlb].b = 0xFF;
            if (D_80103F28[n->tlb].a == 0xFF) {
                osUnmapTLB(n->tlb);
                D_80103F28[n->tlb].key = 0xFFFF;
            } else {
                osMapTLB(n->tlb, 0, (void *)(D_80103F28[n->tlb].key << 12),
                         ((u32)D_80156000 & 0x3FFFFFF) + (D_80103F28[n->tlb].a << 12), -1, 7);
            }
        } else {
            D_80103F28[n->tlb].a = 0xFF;
            if (D_80103F28[n->tlb].b == 0xFF) {
                osUnmapTLB(n->tlb);
                D_80103F28[n->tlb].key = 0xFFFF;
            } else {
                osMapTLB(n->tlb, 0, (void *)(D_80103F28[n->tlb].key << 12), -1,
                         ((u32)D_80156000 & 0x3FFFFFF) + (D_80103F28[n->tlb].b << 12), 7);
            }
        }
        n->tlb = 0xFF;
    }
}
