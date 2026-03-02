#include <cmath>
#include <iostream>
#include <fstream>
#include "file.h"

// вивід ціни x в консоль, пееред нею додається текст title
void printPrice(std::string title, Prices x){
    std::cout << title << " \t" << x.grn << " грн " << x.kop << " коп " << std::endl;
};

// нормалізуємо ціну якщо кількість копійок більша 99
Prices normalize (Prices x) {
    Prices result;
    result.grn = x.grn;
    result.kop = x.kop;
    if (result.kop >= 100) {
        result.grn += result.kop / 100;
        result.kop = result.kop % 100;
    }
    return result;
}

// аналог normalize, без повернення значення
void normalize_ (Prices &x) {
    if (x.kop >= 100) {
        x.grn += x.kop / 100;
        x.kop = x.kop % 100;
    }
}

// додавання двох цін 
Prices add (Prices x, Prices y){
    Prices result;
    result.grn = x.grn + y.grn;
    result.kop = x.kop + y.kop;
    return normalize(result);
};

// аналог add, без повернення значення
void add_ (Prices &x, Prices y){
    x.grn += y.grn;
    x.kop += y.kop;
    normalize_(x);
};

// множення ціни на ціле число
Prices mult (Prices x, int k){
    Prices result;
    result.grn = x.grn * k;
    result.kop = x.kop * k;
    return normalize(result);
};

// аналог mult, без повернення значення
void mult_ (Prices &x, int k){
    x.grn *= k;
    x.kop *= k;
    normalize_(x);
};

// заокруглення цін по правилах НБУ
Prices round (Prices x) {
    Prices result;
    result = normalize(x);

    if (result.kop < 25) {
        result.kop = 0;
    }
    else if ((result.kop >= 25) && (result.kop < 75)) {
        result.kop = 50;
    }
    else {
        result.grn += 1;
        result.kop = 0;
    }
    return result;
}

// аналог round, без повернення значення
void round_ (Prices &x) {
    normalize_(x);

    if (x.kop < 25) {
        x.kop = 0;
    }
    else if ((x.kop >= 25) && (x.kop < 75)) {
        x.kop = 50;
    }
    else {
        x.grn += 1;
        x.kop = 0;
    }
}

// читання значень з текстового файлу
int readfile (std::string filename, Prices &x, int &kx, Prices &y, int &ky){
    std::ifstream file(filename);

    if (file.is_open()){

        file>>x.grn>>x.kop>>kx>>y.grn>>y.kop>>ky;

        file.close();
        return 0;
    }   
    else {
        return 1;
    }
}