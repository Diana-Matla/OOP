#include <iostream>
#include <string>
#include"character.h"
#include"Mage.h"
using namespace std;


Mage::Mage(string n, int l, int h, int ap, int m): Character(n, l, h, ap)
{
    mana = m;
    cout << "Mage constructor\n";
}

Mage::~Mage()
{
    cout << "Mage destructor\n";
}

void Mage::performAttack() {
    cout << "Mage casts a magic spell" << endl;
}

void Mage::MakeDamage(){
    cout << "Magic damage: "<< attackPower + mana<< endl;
}

void Mage::performAttack(int bonusDamage) {
    cout << "Mage attacks with bonus damage: "
         << attackPower + bonusDamage << endl;
}

void Mage::displayInfo(){
    Character::displayInfo();
    cout << "Mana: "<< mana<< endl;
}