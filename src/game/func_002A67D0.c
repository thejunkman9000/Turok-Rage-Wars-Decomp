#include "b23_types.h"
typedef struct Slot67D0 Slot67D0;
typedef struct Shape67D0 {
    u8 padC[0xC];
    s32 unkC;
} Shape67D0;
struct Slot67D0 {
    u8 pad0[4];
    Slot67D0 *next;
    Shape67D0 *shape;
    u8 padC[0x10];
    s32 owner;
    u8 pad20[4];
    f32 unk24;
};
typedef struct Owner67D0 {
    u8 pad0[0x7528];
    Slot67D0 *slots;
} Owner67D0;
extern f32 D_800CB024;
void func_0027302C(void *m, void *src);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
void func_00272898(void *m);
void func_002A35C0(Owner67D0 *o, Slot67D0 *s, void *m);
void func_002A67D0(Owner67D0 *o, s32 key, u8 *tbl) {
    u8 m[0x40];
    Slot67D0 *s;
    f32 k, zero;
    s = o->slots;
    if (s != 0) {
        zero = 0.0f;
        k = D_800CB024;
        do {
            if (s->owner == key) {
                if (zero < s->unk24) {
                    func_0027302C(m, tbl + (s->shape->unkC << 6));
                    func_002734EC(m, k, k, k);
                    func_00272898(m);
                    func_002A35C0(o, s, m);
                }
            }
            s = s->next;
        } while (s != 0);
    }

}
