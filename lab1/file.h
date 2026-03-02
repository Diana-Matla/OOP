#ifndef PRICE_H
#define PRICE_H

struct Prices {
    int grn;
    short int kop;
};

void printPrice(std::string title, Prices x);

Prices add (Prices x, Prices y);
void add_ (Prices &x, Prices y);
Prices mult (Prices x, int k);
void mult_ (Prices &x, int k);
Prices normalize (Prices x);
void normalize_ (Prices &x);
Prices round (Prices x);
void round_ (Prices &x);

int readfile (std::string filename, Prices &x, int &kx, Prices &y, int &ky);

#endif