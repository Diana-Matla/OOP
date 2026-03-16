#include <cmath>
#include <iostream>
#include <fstream>
#include "file.h"

void add (Prices &x, Prices y){
    x.grn += y.grn;
    x.kop += y.kop;
};

void mult (Prices &x, int k){
    x.kop *= k;
    x.grn = x.grn * k + x.kop / 100;
    x.kop = x.kop % 100;
};

void round (Prices &x) {
    if (x.kop >= 100){
        x.grn += x.kop / 100;
        x.kop %= 100 ; 
    }

    int ost = x.kop % 10;
    if (ost < 5)
        x.kop -= ost;
    else 
        x.kop += 10 - ost;
}

void readfile (std::string filename){
    std::string goodname = "";
    int goodcount = 0;
    Prices goodprice = {0, 0};
    Prices totalsum = {0, 0};

    std::ifstream file(filename);
    
    if (file.is_open()){
        while (file>>goodname>>goodprice.grn>>goodprice.kop>>goodcount){
            if (goodprice.grn >= 0 && goodprice.kop >= 0 && goodcount >=0) {
                mult(goodprice, goodcount);
                add(totalsum, goodprice);
            }
            else
                std::cout << "Помилка в товарі <" << goodname << std::endl;
        }    
        file.close();
        
    }   
    else 
        std::cout << "Файл <" << filename << "> не відкрився" << std::endl;
    
    if (totalsum.kop >= 100){
        totalsum.grn += totalsum.kop / 100;
        totalsum.kop %= 100 ; 
    }
    
    std::cout << "Загальна сума чеку: " << totalsum.grn << " грн " << totalsum.kop << " коп" << std::endl;
    round(totalsum);
    std::cout << "Сума до оплати: " << totalsum.grn << " грн " << totalsum.kop << " коп" << std::endl;
}