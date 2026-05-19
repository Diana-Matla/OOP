#ifndef MAGE_H
#define MAGE_H

#include "character.h"
#include <string>
using namespace std;

class Mage : public Character
{
protected:
    int mana;
public:
    Mage(string n, int l, int h, int ap, int m);
    void performAttack() override;
    void MakeDamage()override;
    void performAttack(int bonusDamage);
    void displayInfo();
};

#endif