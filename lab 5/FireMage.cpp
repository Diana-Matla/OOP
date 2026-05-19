#include <iostream>
#include <string>
#include"character.h"
#include"FireMage.h"
using namespace std;

FireMage::FireMage(string n, int l, int h, int ap, int m)
    : Character(n, l, h, ap),  
      Mage(n, l, h, ap, m)
{
    cout << "FireMage constructor\n";
}

void FireMage::performAttack() {
    cout << "FireMage casts FIRE spell" << endl;
}

void FireMage::MakeDamage(){
    cout << "Fire damage: "<< attackPower + ((mana/10)*7)<< endl;
}

void FireMage::performAttack(int bonusDamage) {
    cout << "FireMage attacks with bonus damage: "
         << attackPower + bonusDamage << endl;
}

void FireMage::displayInfo(){
    Mage::displayInfo();
    cout << "Magic type: Fire"<< endl;
}