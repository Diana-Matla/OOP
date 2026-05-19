#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include <string>
using namespace std;

class Warrior : public Character
{
protected:
    int strength;
    string weaponType;
public:
    Warrior(string n, int l, int h, int ap, int str);
    void performAttack() override;
    void MakeDamage()override;
    void performAttack(int bonusDamage);
    void displayInfo();
};

#endif