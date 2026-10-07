#include "o05_types.h"


typedef struct { u8 pad[0x10]; u8 b10; } O05Wb;
extern O05L2 *D_800E59E0;
typedef struct { u16 w[38]; } O05Row;
extern O05Row D_800E5A1A[];
extern O05Row D_800E5A06[];
O05Wb *func_0040ECB0(void *p, s32 id);
void func_0040E9A8(void *w, s32 a);
void func_0040E958(void *w, s32 a);
void func_0043BC3C(s32 k, s32 c);

void func_0043AED0(s32 k, s32 dir) {
    s32 s1;
    O05Wb *w;
    s1 = D_800E59E0->row[k].f4AC;
    w = func_0040ECB0(D_800E59E0->f0, D_800E5A1A[k].w[s1 * 2]);
    func_0040E9A8(w, 0);
    w->b10 = 0x23;
    if (s1 != 5) {
        func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E5A06[k].w[s1 * 2]), 0);
    }
    if (dir == 1) {
        if (s1 == 0) {
            s1 = 5;
        } else {
            s1--;
            if (D_800E59E0->row[k].f4CC == 1) {
                if (s1 >= 3) {
                    s1 = 2;
                }
            }
        }
    } else {
        if (s1 == 5) {
            s1 = 0;
        } else {
            s1++;
            if (D_800E59E0->row[k].f4CC == 1) {
                if (s1 >= 3) {
                    s1 = 5;
                }
            }
        }
    }
    func_0043BC3C(k, s1);
}
