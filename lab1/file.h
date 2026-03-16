#ifndef PRICE_H
#define PRICE_H

struct Prices {
    int grn;
    short int kop;
};




void add (Prices &x, Prices y);

void mult (Prices &x, int k);

void round (Prices &x);

void readfile (std::string filename);

#endif