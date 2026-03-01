#include <cmath> 
#include "file.h"

void round (Prices &x) {
        if (x.kop < 25) {
            x.kop = 0;
        }
        else if ((x.kop >= 25) && (x.kop < 75)) {
            x.kop = 50;
        }
        else if ((x.kop >= 75) && (x.kop < 100)) {
            x.grn = 1 + x.grn;
            x.kop = 0;
        }
        
    }


void mult(Prices &x, int k){
    x.grn *= k;
    x.kop *= k;
    round(x);
}
