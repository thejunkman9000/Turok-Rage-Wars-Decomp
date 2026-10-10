#include "span_1000/code_8029BBA0.h"
#include "types.h"


extern const f64 D_800C5B48_de;
extern const f64 D_800C5B50_de;
extern const f64 D_800C5B58_de;

f64 func_8029DAA0_de(f64 arg0, f64 *arg2) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B48_de;
    if (limit <= arg0) {
        integral = arg0;
    } else {
        if (arg0 < D_800C5B50_de) {
            integral = -func_8029D9DC_de(-arg0);
        } else {
            temp = arg0;
            temp += limit;
            temp -= limit;
            if (arg0 < temp) {
                integral = temp - D_800C5B58_de;
            } else {
                integral = temp;
            }
        }
    }
    *arg2 = integral;
    return arg0 - integral;
}
