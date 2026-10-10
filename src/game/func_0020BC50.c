#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"










extern void func_8020D1FC_de(s32);
extern void func_8020EC14_de(void *);
extern void func_8020D220_de(void *, s32);
extern s32 func_8020C5A0_de(Obj8020BC50 *, Node8020BC50 *);





s32 func_8020BC50_de(Obj8020BC50 *obj, s32 key, s32 requested, void *owner) {
    Node8020BC50 *node;
    s32 found;

    {
        Node8020BC50 *reset;

        reset = obj->nodes;
        while (reset != 0) {
            reset->value = D_800C1D68_de;
            reset->state = -1;
            reset->field18 = 0;
            reset->field1C = 0;
            reset->field20 = 0;
            reset->field24 = 0;
            reset->field28 = 0;
            reset->field2C = 0;
            reset->field30 = 0;
            reset = reset->next;
        }
    }

    obj->selected = -1;
    obj->value = D_800C1D6C_de;
    func_8020D1FC_de(obj);
    found = 0;
    func_8020EC14_de(owner);
    func_8020D220_de(obj, requested);

    {
        s32 i;
        s32 count;
        u32 mask;

        i = found;
        count = obj->count;
        if (count > 0) {
            mask = 0x04300000;
            do {
            char *record;
            s32 product;

            product = i * count;
            if (i != requested) {
                if (((struct func_8020C9CC_S1 *) (obj->links->data + ((product + requested) * obj->links->stride)))->unk4 != 0) {
                    record = (char *)obj->records +
                             (i * obj->records->stride + 8);
                    if (record != 0 && (((ObjectState10 *)(record))->unk_C.v0 & mask) == 0) {
                        func_8020D220_de(obj, i);
                        found++;
                    }
                }
            }
                i++;
                count = obj->count;
            } while (i < count);
        }

        if (found == 0) {
            for (i = 0; i < obj->count; i++) {
                char *record;
                s32 product;

                product = i * obj->count;
                if (i != requested) {
                    if (((struct func_8020C9CC_S1 *) (obj->links->data + ((product + requested) * obj->links->stride)))->unk4 != 0) {
                        record = (char *)obj->records +
                                 (i * obj->records->stride + 8);
                        if (record != 0 && (((ObjectState10 *)(record))->unk_C.v1 & 0x400) == 0) {
                            func_8020D220_de(obj, i);
                        }
                    }
                }
            }
        }
    }

    node = obj->nodes;
    if (node == 0) {
        goto not_found;
    }
    do {
        if (node->key == key) {
            goto search_done;
        }
        node = node->next;
    } while (node != 0);
not_found:
    node = 0;
search_done:
    func_8020C5A0_de(obj, node);
    obj->selected = obj->result;
}
