#include <iostream> 
#include "file.cpp"

int main() {
    int k = 3; // кількість товару під х
    int w = 1; //кількість товару під y
    Prices a{19, 89};
    Prices b{13, 29};
    Prices ra = a * k; // сума всього товару по х
    Prices rb = b * w; // сума всього товару по y
    Prices z = ra + rb; //загальна сума 
    Prices s = z.round() ; // заокруглення

    mult(a,k);
    
    std::cout << "Сума товару1 = " << ra.grn << " грн " << ra.kop << " коп" << std::endl;
    std::cout << "Сума товару2 = " << rb.grn << " грн " << rb.kop << " коп" << std::endl;

    std::cout << "Загальна сума = " << z.grn << " грн " << z.kop << " коп" << std::endl;

    std::cout << "Заокруглена сума = " << s.grn << " грн " << s.kop << " коп" << std::endl;

    std::cout << "функція= " << a.grn << " грн " << a.kop << " коп" << std::endl;
    return 0;

}