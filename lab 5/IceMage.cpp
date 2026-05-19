#include <iostream>
#include <string>
#include"character.h"
#include"IceMage.h"
using namespace std;

IceMage::IceMage(string n, int l, int h, int ap, int m)
    : Character(n, l, h, ap),
      Mage(n, l, h, ap, m)
{
    cout << "IceMage constructor\n";
}

void IceMage::performAttack() {
    cout << "IceMage casts ICE spell" << endl;
}

void IceMage::MakeDamage(){
    cout << "Ice damage: "<< attackPower + ((mana/10)*5)<< endl;
}

void IceMage::performAttack(int bonusDamage) {
    cout << "IceMage attacks with bonus damage: "
         << attackPower + bonusDamage << endl;
}

void IceMage::displayInfo(){
    Mage::displayInfo();
    cout << "Magic type: Ice"<< endl;
}