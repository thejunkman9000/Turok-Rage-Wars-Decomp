/* their2 */
/* Port of func_8044A790_de.c of the other decompilation (CC0): func_0044B3E0, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
/* Moves a node between two lists of an object: removes it from the list at offset 0x20 through
   func_00255E78 and adds it to the list at offset 0xC through func_00255C58.  (The other
   decompilation declares func_00255E78 with one parameter and leaves the node in $a1; the
   argument is passed explicitly here, the code is identical.) */
extern void func_00255E78(void *, void *);
extern void func_00255C58(void *, void *);

void func_0044B3E0(char *object, void *value) {
    func_00255E78(object + 0x20, value);
    func_00255C58(object + 0xC, value);
}
