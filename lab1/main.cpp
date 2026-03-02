#include <iostream>
#include "file.cpp"

int main() {
    Prices a, b;
    int ka, kb;
    std::string filename = "file.txt";

    if (readfile(filename, a, ka, b, kb) == 0) {
        
        /*
        Prices ra = mult(a, ka); // вартість всього товару a
        Prices rb = mult(b, kb); // вартість всього товару b
        Prices r = add(ra, rb); // загальна вартість товарів 

        printPrice("Вартість товару 1:", ra);
        printPrice("Вартість товару 2:", rb);
        printPrice("Загальна вартість:", r);
        printPrice("Сума до оплати:", round(r));
        */

        
        mult_(a, ka);
        printPrice("Вартість товару 1:", a);

        mult_(b, kb);
        printPrice("Вартість товару 2:", b);

        add_(a, b);
        printPrice("Загальна вартість:", a);

        round_(a);
        printPrice("Сума до оплати:", a);
        
    }
    else {
        std::cout << "Файл <" << filename << "> не відкрився" << std::endl;
    }

    return 0;
}