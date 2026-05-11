#include <iostream>
#include <string>
#include"character.h"
#include"FireMage.h"
using namespace std;

FireMage::FireMage(string n, int l, int h, int ap, int m)
    : Mage(n, l, h, ap, m){}

void FireMage::performAttack() {
    cout << "FireMage casts FIRE spell" << endl;
}

void FireMage::MakeDamage(){
    cout << "Fire damage: "<< attackPower + ((mana/10)*7)<< endl;
}

void FireMage::displayInfo(){
    Mage::displayInfo();
    cout << "Magic type: Fire"<< endl;
}