#include "BattleMage.h"
#include <iostream>

using namespace std;

BattleMage::BattleMage(string n, int l, int h, int ap,
                       int str, int m)
    : Character(n, l, h, ap),
      Warrior(n, l, h, ap, str),
      Mage(n, l, h, ap, m)
{
    cout << "BattleMage constructor\n";
}

BattleMage::~BattleMage()
{
    cout << "BattleMage destructor\n";
}

void BattleMage::performAttack()
{
    cout << "BattleMage attacks with magic sword\n";
}

void BattleMage::MakeDamage()
{
    cout << "BattleMage damage: "
         << attackPower + strength + mana
         << endl;
}

void BattleMage::displayInfo()
{
    Character::displayInfo();

    cout << "Strength: " << strength << endl;
    cout << "Mana: " << mana << endl;
}