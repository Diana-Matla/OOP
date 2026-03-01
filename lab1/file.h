#ifndef PRICE_H
#define PRICE_H

#include<iostream>


struct Prices {
    int grn;
    short int kop;

    void normalize() {
        while (this->kop >= 100) {
            this->grn += 1;
            this->kop -= 100;
        }
    }

    Prices operator+(const Prices& x) const {
        Prices result;
        result.grn = grn + x.grn;
        result.kop = kop + x.kop;
        result.normalize();
        return result;
    }
        
    Prices operator*(int k) const {
        Prices result;
        result.grn = grn * k;
        result.kop = kop * k;
        result.normalize();    
        return result;
    }

    Prices round () const {
        Prices result;
        
        result.grn = grn;

        if (kop < 25) {
            result.kop = 0;
        }
        else if ((kop >= 25) && (kop < 75)) {
            result.kop = 50;
        }
        else if ((kop >= 75) && (kop < 100)) {
            result.grn = 1 + grn;
            result.kop = 0;
        }
        return result;
    }
    
};

void mult(Prices& x, int k);
void round (Prices &x);

#endif