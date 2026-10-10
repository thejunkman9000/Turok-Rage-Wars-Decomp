#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804196C0.h"
/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern Object_func_80419E54_de *func_8025305C_de(int);
extern int func_80299958_de(void);
extern void func_802A0748_de(void *, int, int);
extern Resource_func_80419E54_de *func_8040EC30_de(int, int);
extern void func_8040EDE4_de(Resource_func_80419E54_de *, Object_func_80419E54_de *);
extern int func_80411DCC_de(int);
extern void func_80419C84_de(Object_func_80419E54_de *, int);
extern void func_80419F18_de(Object_func_80419E54_de *);
Object_func_80419E54_de *func_80419E54_de(int arg0, int arg1)
{
  Resource_func_80419E54_de *r;
  Object_func_80419E54_de *p;
  int kind;
  r = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 65535);
  func_80411DCC_de(func_80299958_de());
  p = func_8025305C_de(0x88);
  func_802A0748_de(p, 0, 0x88);
  p->b = (kind = 0xB62);
  p->resource = r;
  p->owner.value = arg1;
  p->c = 8;
  p->a = kind;
  p->resource->value = p->owner.bytes[3];
  func_80419C84_de(p, -1);
  func_80419F18_de(p);
  func_8040EDE4_de(r, p);
  return p;
}
